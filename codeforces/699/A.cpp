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
    ll n;
    cin>>n>>s;
    vl v(n);
    for(auto& i:v) cin>>i;
    auto pos = s.find("RL");
    if(pos == string::npos) 
    cout<<-1<<endl;
    else {
        ll mean = (v[pos] + v[pos+1])/2;
        ll ans = mean-v[pos];
        // cout<<ans<<endl;
        while(s.find("RL",pos+1) != string::npos) {
            pos = s.find("RL",pos+1);
            mean = (v[pos] + v[pos+1])/2;
            ans = min(ans,mean - v[pos]);
        }
        cout<<ans<<endl;
    }
    return 0;
}