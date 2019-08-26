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
    // fast
    ll n,ans;
    in(n);
    ans=n-1;
    vl v(n);
    unordered_map<ll,ll> m;
    for(auto& x:v) in(x);
    for(ll i=0; i<n; i++) {
        ll flag = 1;
        for(ll j=0;j<i;j++) {
            m[v[j]]++;
            if(m[v[j]] == 2) {
                flag = 0;
                break;
            }
        }
        ll last=n;
        for(ll j=n-1;j>=i;j--) {
            m[v[j]]++;
            if(m[v[j]]==1)  last = j;
            else break;
        }
        if(flag)
            ans = min(ans,last-i);
        m.clear();
    }
    cout<<ans<<endl;
    return 0;
}