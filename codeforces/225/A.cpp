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
    ll n,x;
    in2(n,x);
    bool flag = true;
    ll c=0;
    while(n--) {
        ll a,b;
        in2(a,b);
        if(!c) { c++; continue;}
        x=7-x;
        // cout<<x<<endl;
        if(x==a or x==b or x==(7-a) or x==(7-b)) {
            flag = false;
            break;
        }
        else {
            for(ll i=1;i<7;i++) 
                if(i!=a and i!=b and i!=(7-a) and i!=(7-b) and i!=x) 
                    x=i;
        }
        c++; 
    }
    cout<<((flag) ? "YES" : "NO")<<endl;
    return 0;
}