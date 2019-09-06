
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
    ll n,s,i,e;
    in(n);
    while(n--) {
        ll ans=0;
        cin>>s>>i>>e;
        ll x = (i+e-s)/2;
        if(x>0) {
            ans = e - x;
            if(ans<0) ans=0;
            cout<<ans<<endl;
        }
        else if(x==0) {
            float a = ((float)i+(float)e-(float)s)/(float)2;
            // cout<<<<endl;
            if(a>=0) cout<<e<<endl;
            else if(!e) {
                if(s>i) cout<<1<<endl;
                else cout<<0<<endl;
            } else  {
                cout<<e+1<<endl;
            }
        }
        else {
            if(!e) {
                if(s>i) cout<<1<<endl;
                else cout<<0<<endl;
            }
            else  {
                cout<<e+1<<endl;
            }
        }
    }
    return 0;
}