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

struct compare { 
    bool operator()(const pair<int, int>& value,  
                                const int& key) 
    { 
        return (value.first < key); 
    } 
    bool operator()(const int& key,  
                    const pair<int, int>& value) 
    { 
        return (key < value.first); 
    } 
}; 

int main()
{
    ll n,m,k,t;
    cin>>n>>m>>k>>t;
    vector<pll> v(k);
    for(auto& i:v) in2(i.first,i.second);
    sort(v.begin(),v.end());
    // cout<<endl;
    // for(auto x:v) cout<<x.first<<" "<<x.second<<endl;
    while(t--) {
        ll p,q,i,flag=0;
        in2(p,q);
        for( i=0;i<v.size();i++) {
            if(v[i].first==p and v[i].second==q) {
                cout<<"Waste"<<endl;
                flag=1;
                break;
            }
            if(v[i].first>p) break;
            if(v[i].first==p) 
                if(v[i].second>=q) break;
        }
        if(flag) continue;
        ll ans = ((p-1)*m)+q-i;
        // cout<<ans<<" "<<i<<endl;
        if(ans%3==0) cout<<"Grapes"<<endl;
        else if(ans%3==1) cout<<"Carrots"<<endl;
        else cout<<"Kiwis"<<endl;
    }
}