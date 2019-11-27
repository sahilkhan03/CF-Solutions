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
#define pl pair<long long,long long>
#define pld pair<long double,long double>
#define endl '\n'
#define loop(i,n) for(ll i=0;i<n;i++)
#define mod ((ll)(1e9+7))
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define inv(v) for(auto&i:v) in(i)
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpl vector<pair<ll,ll>>
#define INF 0x3f3f3f3f

bool used[1005][1005];
map<pl,ll> mp;
ll n,m;

ll dfs(vector<string> &s,set<pl> &imp, ll i, ll j) {
    vpl dir = {{-1,0},{1,0}, {0,1},{0,-1}};
    if(used[i][j]) return 0;
    used[i][j]=1;
    ll c=0;
    for(auto x:dir) {
        if(i+x.first>=0 and i+x.first<n and j+x.second>=0 and j+x.second<m){
            if(s[i+x.first][j+x.second]=='*') imp.insert({i+x.first,j+x.second});
            else c+=dfs(s,imp,i+x.first,j+x.second);
        }
    }
    return c+1;
}

int main() {
    in2(n,m);
    vector<string> s(n);
    for(auto& i:s) cin>>i;
    
    loop(i,n) {
        loop(j,m) {
            if(s[i][j]=='.' and !used[i][j]) {
                set<pl> imp;
                ll c = dfs(s,imp,i,j);
                // cout<<i<<" "<<j<<" "<<c<<endl;
                for(auto x:imp) mp[{x.first,x.second}]+=c;
            }
        }
    }

    loop(i,n){
        loop(j,m) {
            if(s[i][j]=='*') cout<<(mp[{i,j}]+1)%10;
            else cout<<'.';
        }
        cout<<endl;
    }
    
    return 0;
}