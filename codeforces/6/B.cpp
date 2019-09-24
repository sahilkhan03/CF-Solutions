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
#define mp make_pair

int main()
{
    ll n,m;
    char c;
    cin>>n>>m>>c;
    vector<string> s(n);
    for(auto& i:s) cin>>i;
    // pl a;
    vector<pll> v;
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) 
        if(s[i][j]==c) {v.push_back({i,j});}
    }
    ll co=0;
    unordered_map<char,ll> mapper;
    for(auto a:v) {
    if(a.first+1 < n and s[a.first+1][a.second]!=c and s[a.first+1][a.second]!='.' and !mapper.count(s[a.first+1][a.second])) {
        co++; mapper[s[a.first+1][a.second]]++;
    }
    if(a.first-1 >=0 and s[a.first-1][a.second]!=c and s[a.first-1][a.second]!='.' and !mapper.count(s[a.first-1][a.second])) {
        co++;mapper[s[a.first-1][a.second]]++;
    }
    if(a.second+1 < m and s[a.first][a.second+1]!=c and s[a.first][a.second+1]!='.' and !mapper.count(s[a.first][a.second+1])) {
        co++;mapper[s[a.first][a.second+1]]++;
    }
    if(a.second-1 >=0 and s[a.first][a.second-1]!=c and s[a.first][a.second-1]!='.' and !mapper.count(s[a.first][a.second-1])) {
        co++;mapper[s[a.first][a.second-1]]++;
    }
    }
    // cout<<s[0]<<endl<<s[1]<<endl<<s[2]<<endl;
    cout<<co<<endl;
}