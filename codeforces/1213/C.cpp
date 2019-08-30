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
    ll t; 
    in(t);
    while(t--) {
        ll a,b,ans=0;
        in2(a,b);
        ll sum10=0;
        for(ll i=0;i<=b*10;i+=b) sum10+=i%10;
        if(a<=b*10) {
            ll i=0;
            while(i<=a) {
                 ans+=i%10;
                 i+=b;
            }
        }
        else {
            ll c = a/(b*10);
            ans+=c*sum10;
            a-=c*b*10;
            ll i=0;
            while(i<=a) {
                 ans+=i%10;
                 i+=b;
            }
        }
        cout<<ans<<endl; 
    }
    return 0;
}