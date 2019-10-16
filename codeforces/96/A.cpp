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
#define mod (ll)(1e9+7)
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define vl vector<ll>
#define vpll vector<pair<ll,ll>>
#define INF 0x3f3f3f3f
#define mp make_pair

ll dp[1005][1005];

int main()
{
    string s;
    cin>>s;
    ll ans1=0,ans0=0,last1=0,last0=0;
    for(ll i=0;i<s.size();i++) {
        if(s[i]=='1') {
            last0=0;
            last1++;
            ans1 = max(ans1,last1);
        }
        else {
            last1 = 0;
            last0++;
            ans0=max(ans0,last0);
        }
    }
    if(ans0 >6 or ans1>6 ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}