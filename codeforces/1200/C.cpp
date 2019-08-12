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
#define ll int64_t
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
    long long  n,m,q;
    cin>>m>>n>>q;
    long double g = __gcd(n,m);
    m/=g;n/=g;
    // cout<<lcm;
    while(q--) {
        long double a,b,c,d;
        cin>>a>>b>>c>>d;
        long long area1,area2;
        area1 = ((a==1) ? (b-1+m)/m : (b-1+n)/n );
        area2 = ((c==1) ? (d-1+m)/m : (d-1+n)/n );
        // cout<<area1<<" "<<area2<<endl;
        // long double endPoint = max(area1,area2);
        // long double lower = min(area1,area2);
        // ll multiple = endPoint/lcm;
        cout<<((area2 == area1) ? "YES\n" : "NO\n");
    }
    return 0;
}