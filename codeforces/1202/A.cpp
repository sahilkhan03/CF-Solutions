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
    ll t;
    in(t);
    while(t--)
    {
     string x,y;
     cin>>x>>y;
     reverse(x.begin(),x.end());
     reverse(y.begin(),y.end());
     ll a,b,ans=0,flag=0;
     b = y.find('1');
     if(b==string::npos) {
         ans=0;
     }
     else {
         for(ll i = 0; i<x.size();i++) {
             if(x[i]=='1') {
                 if(i>=b) {
                    ans=i-b;
                    break;
                }
            }
        }
     }
     cout<<ans<<endl;
    }
    return 0;
}