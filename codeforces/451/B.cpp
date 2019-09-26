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
    ll a[n],b[n];
    for(ll i=0;i<n;i++) {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    unordered_map<ll,ll> m;
    for(ll i=0;i<n;i++) m[b[i]] = i;
    for(ll i=0;i<n;i++) a[i] = m[a[i]];
    ll l=-1,r=-1;
    for(ll i=0;i<n;i++) 
        if(a[i]!=i) {
            l=i;break;
        }
    for(ll i=n-1;i>=0;i--) {
        if(a[i]!=i) {
            r=i;
            break;
        }
    }
    if(l==-1 or r==-1) {
        cout<<"yes"<<endl<<1<<" "<<1<<endl;
        return 0;
    }
    reverse(a+l,a+r+1);
    bool ok = true;
    for(ll i=0;i<n;i++) if(a[i]!=i) {ok=false;break;}
    if(ok) {
    cout<<"yes"<<endl<<l+1<<" "<<r+1<<endl;
    }
    else cout<<"no"<<endl;
    return 0;
}