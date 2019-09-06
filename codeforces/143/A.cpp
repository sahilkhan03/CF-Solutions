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
    ll i,j,k,l,r1,r2,c1,c2,d1,d2;
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    ll flag=0;
    for( i=1;i<10;i++) {
    for( j=1;j<10;j++){
    for( k=1;k<10;k++) {
        for(l=1;l<10;l++) 
        if(i+j==r1 and k+l==r2 and i+k==c1 and j+l==c2 and i+l==d1 and j+k==d2 and i!=j and i!=k and i!=l and j!=k and j!=l and k!=l) {flag=1;break;}
        if(flag ) break;
    }
    if(flag) break;
    }
    if(flag) break;
    }
    if(!flag) cout<<-1<<endl;
    else {
        cout<<i<<" "<<j<<endl<<k<<" "<<l<<endl;
    }
    return 0;
}