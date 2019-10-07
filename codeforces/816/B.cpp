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
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> v(200005,0);
    while(n--) {
        ll a,b;
        cin>>a>>b;
        v[a]++;
        v[b+1]--;
    }
    for(ll i=1;i<200005;i++) v[i]+=v[i-1];
    for(auto& x:v) if(x>=k) x=1; else x=0;
    for(ll i=1;i<200005;i++) v[i]+=v[i-1];
    while(q--) {
        ll a,b;
        in2(a,b);
        cout<<v[b]-v[a-1]<<endl;
    }
    return 0;
}