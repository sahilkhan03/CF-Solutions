/*                    ___          |\    /|           ____   ____   ____  ____
   |     |    /\    /    \ |     | | \  / |    /\    |    \ |    \ |     |    \
   |_____|   /__\   \____  |_____| |  \/  |   /__\   |____/ |____/ |__   |____/
   |     |  /    \       \ |     | |      |  /    \  |      |      |     |   \
   |     | /      \ \____/ |     | |      | /      \ |      |      |____ |    \
*/
#include<bits/stdc++.h>
using namespace std;
#define lb lower_bound
#define ub upper_bound
#define pf push_front
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pi pair<int,int>
#define pl pair<long,long>
#define pll pair<long long,long long>
#define pld pair<long double,long double>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define endl '\n'
#define loop(i,n) for(ll i=0;i<n;i++)
#define mod 1e9+7
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define vl vector<ll>
#define vpll vector<pair<ll,ll>>
#define INF 0x3f3f3f3f
#define mp make_pair

vl v[105];

bool bfs(vl &color, ll start) {
    queue<pll> q;
    color[start]=1;
    q.push({start,1});
    while(!q.empty()) {
        auto s = q.front();q.pop();
        for(auto u:v[s.first]) {
            if(color[u]==-1) {
                color[u] = 1 - s.second;
                q.push({u,color[u]});
            }
            else if(color[u]==s.second) {
                // cout<<ans<<"--"<<s.first<<"--"<<u<<"----"<<color[u]<<endl;
                return true;
            }
        }
    }
    // cout<<"-----"<<ans<<endl;
    return false;
}

int main()
{
    ll n,m;
    in2(n,m);
    vl color(n,-1);
    while (m--)
    {
        ll a,b;
        in2(a,b);
        v[a-1].pb(b-1);
        v[b-1].pb(a-1);
    }
    ll ans = 0;
    auto cur_pos = find(color.begin(),color.end(),-1);
    while(cur_pos != color.end()) {
        // cout<<cur_pos-color.begin()<<" "<<ans<<endl;
        ans += bfs(color, cur_pos - color.begin());
        cur_pos = find(color.begin(),color.end(),-1);
    }
    cout<<(((n-ans)%2 == 0) ? ans : ans+1)<<endl;
    return 0;
}