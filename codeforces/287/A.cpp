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
    string s[4];
    cin>>s[0]>>s[1]>>s[2]>>s[3];
    bool flag=false;
    for(ll i=0;i<3;i++) {
        for(ll j=0;j<3;j++) {
            ll a=0,b=0;
            if(s[i][j]=='.') a++; else b++;
            if(s[i][j+1]=='.') a++; else b++;
            if(s[i+1][j+1]=='.') a++; else b++;
            if(s[i+1][j]=='.') a++; else b++;
            if(abs(a-b) >= 2) {
                // cout<<i<<" "<<j<<endl;
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}