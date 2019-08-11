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
    ll n;
    in(n);
    string s,ans="0000000000";
    cin>>s;
    for(ll i=0;i<s.size();i++) {
        if(s[i]=='L') ans[ans.find('0')]='1';
        else if(s[i]=='R') {
            reverse(ans.begin(),ans.end());
            ll pos = ans.find('0');
            reverse(ans.begin(),ans.end());
            ans[9-pos] = '1';
        }
        else ans[s[i]-48]='0';
    }
    cout<<ans<<endl;
}