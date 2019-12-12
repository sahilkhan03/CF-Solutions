/*                    ___          |\    /|           ____   ____   ____  ____
   |     |    /\    /    \ |     | | \  / |    /\    |    \ |    \ |     |    \
   |_____|   /__\   \____  |_____| |  \/  |   /__\   |____/ |____/ |__   |____/
   |     |  /    \       \ |     | |      |  /    \  |      |      |     |   \
   |     | /      \ \____/ |     | |      | /      \ |      |      |____ |    \
*/
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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

int main() {
    ll t;
    in(t);
    while(t--) {
        string s;
        cin>>s;
        ll l=0,r=0,u=0,d=0;
        loop(i,s.size()) if(s[i]=='L') l++;
        else if(s[i]=='R') r++;
        else if(s[i]=='D') d++;
        else if(s[i]=='U') u++;
        ll h,v;
        h = min(l,r);
        v=min(u,d);
        if(!h) {
            if(v>=1) cout<<2<<endl<<"UD"<<endl;
            else cout<<0<<endl;
        }
        else if(!v) {
            if(h>=1) cout<<2<<endl<<"RL"<<endl;
            else cout<<0<<endl;
        }
        else {
            cout<<(h+v)*2<<endl;
            loop(i,h) cout<<'R';
            loop(i,v) cout<<"D";
            loop(i,h) cout<<'L';
            loop(i,v) cout<<"U";
            cout<<endl;
        }
    }
    return 0;
}