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
#define vpll vector<pair<ll,ll>>
#define INF 0x3f3f3f3f
#define mp make_pair

int main()
{
    ll n;
    in(n);
    vl v(n),a(n+1),b(n+1);
    for(auto &i:v) in(i);
    ll m;in(m);
    a[0]=b[0]=0;a[1] = v[0];
    for(ll i=1;i<=n;i++) {
        a[i] = a[i-1] + v[i-1]; 
    }
    sort(v.begin(),v.end());
    b[1] = v[0];
    for(ll i=1;i<=n;i++) {
        b[i] = b[i-1] + v[i-1]; 
    }
    while(m--) {
        ll  p,q,r;
        cin>>r>>p>>q;
        if(r==1) cout<<a[q]-a[p-1]<<endl;
        else cout<<b[q]-b[p-1]<<endl;
    }
    return 0;
}