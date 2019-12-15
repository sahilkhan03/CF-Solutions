/*                    ___          |\    /|           ____   ____   ____  ____
   |     |    /\    /    \ |     | | \  / |    /\    |    \ |    \ |     |    \
   |_____|   /__\   \____  |_____| |  \/  |   /__\   |____/ |____/ |__   |____/
   |     |  /    \       \ |     | |      |  /    \  |      |      |     |   \
   |     | /      \ \____/ |     | |      | /      \ |      |      |____ |    \
*/
#include<bits/stdc++.h>
using namespace std;
#define isko_lga_dala_to_life_jhinga_la_la ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lb lower_bound
#define ub upper_bound
#define pf push_front
#define pb push_back
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define pld pair<long double,long double>
#define endl '\n'
#define loop(i,n) for(ll i=0;i<n;i++)
#define mod ((ll)(1e9+7))
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define in3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define inv(v) for(auto&i:v) in(i)
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpl vector<pair<ll,ll>>
#define INF 0x3f3f3f3f

template<typename T, typename TT>
ostream& operator<<(ostream &os, const pair<T, TT> &t) { return os<<t.first<<" "<<t.second; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &t) { for(auto& i: t) os<<i<<" "; return os; }

int main() {
    ll n;in(n);
    string s;
    cin>>s;
    vl ans;
    if(s.size()%2==0) {
        char m = s[0];
        ll i=1;
         while(i<n-1){
                if(s[i]!=m) {
                    // cout<<s[i]<<endl;
                    ans.push_back(i+1);
                    s[i]= (s[i]=='W' ? 'B' : 'W');
                    s[i+1]= (s[i+1]=='W' ? 'B' : 'W');
                }
            i++;
        }
        ll cw=0,cb=0;
        loop(i,n) if(s[i]=='W') cw++; else cb++;
        if(cw==1 or cb==1) {
            cout<<-1<<endl;
            return 0;
        }
        if(s[n-1]!=m) {
            m = s[n-1];
            ll i=n-2;
            while(i>0) {
                if(s[i]!=m) {
                        ans.push_back(i);
                        s[i]= (s[i]=='W' ? 'B' : 'W');
                        s[i-1]= (s[i-1]=='W' ? 'B' : 'W');
                    }
                i--;
            }
        }
    }
    else {
        char m = s[0];
        ll i=1;
        while(i<n-1){
                if(s[i]!=m) {
                    // cout<<s[i]<<endl;
                    ans.push_back(i+1);
                    s[i]= (s[i]=='W' ? 'B' : 'W');
                    s[i+1]= (s[i+1]=='W' ? 'B' : 'W');
                }
            i++;
        }
        if(s[n-1]!=m) {
            m = s[n-1];
            ll i=n-2;
            while(i>0) {
                if(s[i]!=m) {
                        ans.push_back(i);
                        s[i]= (s[i]=='W' ? 'B' : 'W');
                        s[i-1]= (s[i-1]=='W' ? 'B' : 'W');
                    }
                i--;
            }
        }
    }
    cout<<ans.size()<<endl<<ans<<endl;
    return 0;
}