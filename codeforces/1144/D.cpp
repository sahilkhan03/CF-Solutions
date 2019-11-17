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
    ll n;
    in(n);
    vl v(n);
    ll c=0,e=0,pos=-1;
    for(auto& I:v){
         in(I);
         m[I]++;
         if(m[I] > c) {
             c = m[I];
             pos=e;
        }
        e++;
    }
    cout<<n-m[v[pos]]<<endl;
    // cout<<pos<<endl;
    for(ll i=pos+1;i<n;i++) {
        if(v[i] > v[pos]) cout<<2<<" "<<i+1<<" "<<i<<endl;
        else if(v[i]< v[pos]) cout<<1<<" "<<i+1<<" "<<i<<endl; 
    }
    for(ll i=pos;i>=0;i--) {
        if(v[i] > v[pos]) cout<<2<<" "<<i+1<<" "<<i+2<<endl;
        else if(v[i]< v[pos]) cout<<1<<" "<<i+1<<" "<<i+2<<endl; 
    }
    return 0;
}