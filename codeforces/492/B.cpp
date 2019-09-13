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


bool compare(pll a, pll b) {
    return b.second<a.second;
}



int main()
{
    double n,l;
    // in2(n,l);
    cin>>n>>l;
    double ans=0;
    vector<double> v(n);
    for(auto& i:v) cin>>(i);
    sort(v.begin(),v.end());
    ans = max(ans,(v[0]-0));
    ans = max(ans,(l-v[n-1]));
    for(ll i=0;i<n;i++) v[i] = v[i+1]-v[i];
    v.erase(--v.end());
    // for(auto x:v) cout<<x<<endl;
    for(auto i:v) {
        ans = max(ans,i/2);
        // cout<<i<<endl;
    }
    printf("%.10f\n",ans);
    return 0;
}