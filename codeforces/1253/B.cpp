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
#define mod ((ll)(1e9+7))
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpll vector<pair<ll,ll>>
#define INF 0x3f3f3f3f
#define mp make_pair
 
int main() {
    ll n;
    in(n);
    vl v(n);
    for(auto& i:v) in(i);
    vl ans;
    ll sum=0;
    set<ll> s;ll last=0;
    loop(i,n) {
        sum+=v[i];
    }
    if(sum) {
        cout<<-1<<endl;
        return 0;
    }
    ml m;
    bool check = 1;
    loop(i,n) {
        if(v[i]>0) {m[v[i]]++;
        if(m[v[i]]!=1) {
            check = 0;
            break;
        }}
        if(v[i]<0) {
            m[abs(v[i])]--;
            if(m[v[i]]) {
                check = 0;
                break;
            }
        }
    }
    if(!check) {
        cout<<-1<<endl;
        return 0;
    }
    
    ll count=0;
    m.clear();
    ml mp;
    loop(i,n) {
        count++;
        mp[v[i]]++;
        if(mp[v[i]]>1) {
            cout<<-1<<endl;
            return 0;
        }
        if(v[i]>0) {
            m[v[i]]++;
            last++;
            
        }
        if(v[i]<0) {
            m[abs(v[i])]--;
            if(!m[abs(v[i])]) last--;
        }
        if(!last) {
            ans.push_back(count);
            count = 0;
            mp.clear();
        }
    }
    if(!ans.size()) {
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x<<" ";
    return 0;
}