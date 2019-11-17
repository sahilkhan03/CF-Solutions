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
#define mod ((ll)(1e9+7))
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpll vector<pair<ll,ll>>
#define INF 0x3f3f3f3f
#define mp make_pair
int m[1000005];

int main() {
    ll n,k;
    in2(n,k);
    vl v(n);
    for(auto& I:v) in(I);
    ll ans=0;
    pll p;
    ll i=0,j=0,c=0;
    while(j<n) {
        m[v[j]]++;
        if(m[v[j]]==1) {
            c++;
            while(c>k) {
                m[v[i]]--;
                if(!m[v[i]]) c--;
                i++;
            }
        }
        if(ans < j-i+1) {
            ans= j-i+1;
            p.first = i;p.second = j;
        }
        j++;
    }
    cout<<p.first+1<<" "<<p.second+1<<endl;
    return 0;
}