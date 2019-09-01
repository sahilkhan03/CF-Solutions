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
    ll n,last=0,flag=0,flag2=0;
    in(n);
    while(n--) {
        ll a,b;
        in2(a,b);
        if(!last) last=b;
        if(a!=b) {
            flag=1;
            break;
        }
        else {
            if(last<a) {
                flag2=max((ll)1,flag2);
            }
        }
        last=b;
    }
    if(flag2)
    cout<<((flag) ? "rated" : "unrated")<<endl;
    else {
        cout<<((flag) ? "rated" : "maybe")<<endl;
    }
    return 0;
}