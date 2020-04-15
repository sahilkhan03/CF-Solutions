/*                    ___          |\    /|           ____   ____   ____  ____
   |     |    /\    /    \ |     | | \  / |    /\    |    \ |    \ |     |    \
   |_____|   /__\   \____  |_____| |  \/  |   /__\   |____/ |____/ |__   |____/
   |     |  /    \       \ |     | |      |  /    \  |      |      |     |   \
   |     | /      \ \____/ |     | |      | /      \ |      |      |____ |    \
*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lb lower_bound
#define ub upper_bound
#define pf push_front
#define pb push_back
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define pld pair<long double,long double>
#define endl '\n'
#define loop(i,n) for(ll i=0;i<n;i++)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define mod ((ll)(1e9+7))
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define in3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define inv(v) for(auto&i:v) in(i)
#define all(x) x.begin(), x.end()
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpl vector<pair<ll,ll>>
#define INF 0x3f3f3f3f

template<typename T, typename TT>
ostream& operator<<(ostream &os, const pair<T, TT> &t) { return os<<t.first<<" "<<t.second; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &t) { for(auto& i: t) os<<i<<" "; return os; }

int main() {
    fast;
    int t;scanf("%d",&t);
    while (t--) {
        int n;scanf("%d",&n);
        vector<int> v(n); 
        loop(i,n) scanf("%d",&v[i]);
        vector<vector<int>> freq(200, vector<int>(n+1)), pos(200,vector<int>());
        loop(i,200) {
            freq[i][0]=0;
            loop(j,n) {
                freq[i][j+1] = freq[i][j];
                if(v[j]==i+1) freq[i][j+1]++, pos[i].push_back(j+1);
            }
        }
        int ans=0;
        loop(i,200) {
            ans = max(ans,(int)pos[i].size());
            loop(j,pos[i].size()/2) {
                loop(k,200)
                    // cout<<k<<" "<<i<<" "<<freq[k][pos[i][j]]<<" "<<freq[k][pos[i][pos[i].size()-j-2]];
                    ans=max(ans*1LL, 2*(j+1) + freq[k][pos[i][pos[i].size()-j-1]-1] - freq[k][pos[i][j]]);
                    // cout<<ans<<endl;
            }
        }
        printf("%d\n",ans);
    }
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}