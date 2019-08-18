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
#define ll long
#define pi pair<int,int>
#define pl pair<long,long>
#define pll pair<long long,long long>
#define pld pair<long double,long double>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define endl '\n'
#define it(i,a,b) for(i=a;i<b;i++)
#define mod 1e9+7
#define in(x) scanf("%ld",&x)
#define in2(x,y) scanf("%ld %ld",&x,&y)
#define vl vector<ll>
#define mp make_pair

int main()
{
    ll n,m;
    in(n);
    vector<ll> a(n);
    for(ll i=0;i<n;i++) in(a[i]);
    in(m);
    vector<ll> b(m);
    for(ll i=0;i<m;i++) in(b[i]); 
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    cout<<a[0]<<" "<<b[0]<<endl;
    return 0;
}