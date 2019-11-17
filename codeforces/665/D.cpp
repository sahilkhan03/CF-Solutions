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

bool sieve[2000005];

int main() {
    ll n;
    in(n);
    vl v(n);
    for(auto& I:v) in(I);
    for(ll i=2;i<2000005;i++) {
        if(!sieve[i]) {
            for(ll j=2*i;j<2000005;j+=i) sieve[j] = true;
        }
    }
    ll c1=0, cp = -1, c=0;
    loop(i,n)  if(v[i]==1) c1++;
    if(c1) {
        loop(i,n) if(!sieve[v[i]+1] and v[i]!=1) {
            cp = v[i];
            break;
        } 
    } 
    c = c1+((cp!=-1) ? 1 : 0);
    ll ans1=-1,ans2=-1;
    loop(i,n) {
        for(ll j=i+1;j<n;j++) {
            if(!sieve[v[j]+v[i]]) {
                ans1=v[j];
                ans2=v[i];
                break;
            }
        }
    }
    if(c>2) {
        cout<<c<<endl;
        if(cp==-1)
        loop(i,c) cout<<1<<" ";
        else {
            loop(i,c-1) cout<<1<<" ";
            cout<<cp<<endl;
        }
        return 0;
    }
    else if(ans1!=-1 and ans2!=-1) {
        cout<<2<<endl;
        cout<<ans1<<" "<<ans2<<endl;
        return 0;
    }
    else {
        cout<<1<<endl;
        cout<<v[0]<<endl;
    }
    return 0;
}