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
    string s;
    cin>>s;
    string ans = "";
    ll j=s.find("WUB");
    if(j==string::npos)
    for(ll k=0;k<s.size();k++) ans+=s[k];
    else 
    {
    for(ll k=0;k<j;k++) ans+=s[k];
    }
    ll i=0;
    while(i<s.size()) {
        ll f=s.find("WUB",i);
        ll g=s.find("WUB",f+1);
        if(f == string::npos) break;
        else if(g==string::npos) {
            ll k=f+3;
            if(ans.size()) ans+=" ";
            while(k<s.size()) {
                ans+=s[k];
                k++;
            }
        } 
        else
        {
            if(ans.size() and f+3<g ) ans+=" "; 
            for( ll k=f+3;k<g;k++) {
                ans+=s[k];
            }
        }
        i=f+3;
    }
    cout<<ans<<endl;
    return 0;
}