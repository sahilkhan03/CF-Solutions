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
    while(t--)
    {
        ll h,c,b,p,f;
        cin>>b>>p>>f>>h>>c;
        ll ans=0;
        ll mx=b/2;
        if(h>c) {
            if(mx<=p) 
                ans=mx*h;
            else {
                ans=(p*h);
                if(mx-p > f) ans+=f*c;
                else ans+=(mx-p)*c;
            }
        }
        else {
            // cout<<'h'<<endl;
            if(mx<=f) {ans=mx*c;
            // cout<<ans<<endl;
            }
            else {
                ans=f*c;
                if(mx-f > p) ans+=p*h;
                else ans+=(mx-f)*h;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}