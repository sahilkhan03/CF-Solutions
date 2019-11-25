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
bool visited[300005];
int main() {
    ll n,x;in2(n,x);
    vector<ml> v(n, ml());
    loop(i,n-1) {
        ll a,b,c;
        cin>>a>>b;
        a--;b--;
        v[a][b]=1;
        v[b][a] =1;
    }
    vl leaf;
    queue<pll> q;
    q.push({0,0});
    ll dis[n],dis1[n];
    while (!q.empty())
    { 
        pll cur = q.front();q.pop();
        dis[cur.first]=cur.second;
        visited[cur.first] = true;
        // cout<<v[cur.first].size()<<" "<<cur.first<<endl;
        if(v[cur.first].size()==1) leaf.push_back(cur.first);
        for(auto c:v[cur.first]) {
            if(!visited[c.first]) {
                q.push({c.first,c.second+cur.second});
            }
        }
    }
    queue<pll> q1;
    memset(visited,0,sizeof visited);
    q1.push({x-1,0});
    leaf.push_back(0);
    while (!q1.empty())
    { 
        pll  cur = q1.front();q1.pop();
        dis1[cur.first] = cur.second;
        visited[cur.first] = true;
        for(auto c:v[cur.first]) {
            if(!visited[c.first]) {
                q1.push({c.first,c.second+cur.second});
            }
        }
    }
    ll ans = 2*dis[x-1];
    for(auto l:leaf) {
        if(dis1[l]<dis[l])
            {ans = max(ans,2*dis[l]);}
    }
    cout<<ans<<endl;
    return 0;
}