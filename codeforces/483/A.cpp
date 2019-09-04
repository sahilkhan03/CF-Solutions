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
    ll l,r;
    in2(l,r);
    ll i,j,k,flag=0;
    for( i=l;i<=r;i++) {
        for( j=i+1;j<=r;j++) { 
            for( k=j+1;k<=r;k++) {
                if(__gcd(i,j)==1 and __gcd(j,k)==1 and __gcd(i,k)!=1) {
                    flag = 1;
                    break;
                }
            }
        if(flag) break;
        }
        if(flag) break;
    }
    if(flag) 
        cout<<i<<" "<<j<<" "<<k<<endl;
    else
    cout<<-1<<endl;
    return 0;
}