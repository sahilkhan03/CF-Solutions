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
    ll n,a=0,b=0;
    in(n);
    vl v(n);
    for(auto&i : v) in(i);
    ll i=0,j=n-1;
    while(j>i) {
        if(v[i]>v[j]) 
            {
                a+=v[i];
                // cout<<v[i]<<endl;
                i++;
            }
        else {
            a+=v[j];
            // cout<<v[j]<<endl;
            j--;
        }

        if(v[i]>v[j]) 
            {
                b+=v[i];
                i++;
            }
        else {
            b+=v[j];
            j--;
        }
    }
    if(n%2==1) a+=v[i];
    cout<<a<<" "<<b<<endl;
    return 0;
}