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
    ll n;
    in(n);
    vl v(n);
    for(auto&i : v) in(i);
    ll ans=0;
    for(ll i=0;i<n;i++) {
        ll cur = 1;
        ll j=i;
        if(j+1<n)
        while(v[j]<=v[j+1]) {cur++;j++; if(j+1==n) break;}
        ll mx = v[j];
        j++;
        // printf("%lld",v[j]);
        while(j<n and v[j]<=mx) {cur++;mx=v[j];j++; }
        // printf("%lld\n",cur);
        ans=max(ans,cur);
    }
    if(v.size()==1) printf("1");
    else
    printf("%lld", ans);
    return 0;
}