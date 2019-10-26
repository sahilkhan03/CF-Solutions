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

double dp[2005][2005];

int main()
{
    ll n,m;
    in2(n,m);
    if(!n) {
        cout<<0<<" "<<1<<endl<<0<<" "<<m<<endl;
        cout<<0<<" "<<0<<endl<<n<<" "<<m-1<<endl;
    }
    else if(!m) {
        cout<<1<<" "<<0<<endl<<n<<" "<<0<<endl;
        cout<<0<<" "<<0<<endl<<n-1<<" "<<0<<endl;
    }
    else {
        double d1 = (2*hypot((n-1),m)) + hypot(n,m);
        double d3 = (2*hypot(n,m-1)) + hypot(n,m);
        double d2 = (2*hypot(n,m)) + ((n>m) ? n: m);
        // cout<<d1<<" "<<d2<<" "<<d3<<endl;
        if(d1>d2 and d1>d3) {
            cout<<n-1<<" "<<m<<endl<<0<<" "<<0<<endl;
            cout<<n<<" "<<m<<endl<<1<<" "<<0<<endl;
        }
        else if(d3>d2) {
            cout<<n<<" "<<m-1<<endl<<0<<" "<<0<<endl;
            cout<<n<<" "<<m<<endl<<0<<" "<<1<<endl;
        }
        else {
            cout<<0<<" "<<0<<endl<<n<<" "<<m<<endl;
            ((n>m) ? (cout<<0<<" "<<m<<endl<<n<<" "<<0<<endl) : (cout<<n<<" "<<0<<endl<<0<<" "<<m<<endl) );
        }
    }
    return 0;
}