/*                    ___          |\    /|           ____   ____   ____  ____
   |     |    /\    /    \ |     | | \  / |    /\    |    \ |    \ |     |    \
   |_____|   /__\   \____  |_____| |  \/  |   /__\   |____/ |____/ |__   |____/
   |     |  /    \       \ |     | |      |  /    \  |      |      |     |   \
   |     | /      \ \____/ |     | |      | /      \ |      |      |____ |    \
*/
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lb lower_bound
#define ub upper_bound
#define pf push_front
#define pb push_back
#define ll long long
#define pi pair<int,int>
#define pl pair<long,long>
#define pll pair<long long,long long>
#define pld pair<long double,long double>
#define endl '\n'
#define loop(i,n) for(ll i=0;i<n;i++)
#define mod ((ll)(1e9+7))
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpll vector<pair<ll,ll>>
#define adjl vector<vl>  
#define INF 0x3f3f3f3f
bool visited[100005];
int main() {
    ll n;in(n);
    ll ans=0;
    vector<ml> v(n, ml());
    loop(i,n-1) {
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        v[a][b]=c;
        v[b][a] =c;
        ans+=c*2;
    }
    queue<pll> q;
    q.push({0,0});
    ll ds = 0;
    while (!q.empty())
    { 
        pll cur = q.front();q.pop();
        ds = max(ds,cur.second);
        visited[cur.first] = true;
        for(auto x:v[cur.first]) {
            if(!visited[x.first]) {
                q.push({x.first,x.second+cur.second});
            }
        }
    }
    
    cout<<ans - ds<<endl;
    
    return 0;
}