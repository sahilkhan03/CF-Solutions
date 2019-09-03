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
    vector<string> v(n);
    for(auto& i:v) cin>>i; 
    char d = v[0][0];
    char l = v[0][1];
    bool flag = true;
    if(l == d) flag = false;
    if(flag)
    for(ll i=0;i<n;i++) if(v[i][i]!=d or v[i][n-i-1]!=d) {
        flag = false;
        break;
    } 
    if(flag) {
        for(ll i=0;i<n;i++)
            for(ll j=0;j<n;j++) {
                if(i!=j and j!=n-i-1)
                if(v[i][j] !=l) {
                    flag = false;
                    break;
                }
            }
    }

    cout<<((flag) ? "YES" : "NO" )<<endl;

    return 0;
}