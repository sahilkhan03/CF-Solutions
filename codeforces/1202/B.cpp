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

string s;
int solve(ll x,ll y) {
    int ds[10];
    memset(ds,int(INF),sizeof ds);
                loop(i,11){
                    loop(j,11) {
                        if(!i and !j) continue;
                        int k = ((i*x) + (j*y))%10;
                        ds[k] = min(int(i+j),ds[k]);
                    }
                }
    int ans=0;
    for(int i=1;i<s.size();i++) {
        int val = ds[(10-s[i-1]+s[i])%10];
        if(val == int(INF)) return -1;
        ans+=val-1;
    }
    return ans;
}

int main() {
    cin>>s;
    loop(x,10) {
        loop(y,10) {
            cout<<solve(x,y)<<" ";
        }
        cout<<endl;
    }
    return 0;
}