#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
//using namespace __gnu_pbds;
#define rep(i,a,b) for(i=(a);i<=(b);i++)
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define maxn 100005
#define inf 1e18
#define boost ios::sync_with_stdio(false);cin.tie(0)
#define fr freopen("source.txt","r",stdin),freopen("output.txt","w",stdout)
#define SET(a,b) memset(a,b,sizeof(a))
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
//template<typename T>
//using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
int main()
{
    boost;
    ll n,i,j,x,t,m;
    cin>>n>>m;
    ll a[n];
    map<ll,ll>mp;
    set<ll>s;
    for(i=0;i<n;i++) {
        cin>>a[i];
        mp[a[i]]++;
        s.insert(a[i]);
    }
    vector<ll>v;
    x=1;
    ll ans=0;
    while(1){
        vector<ll>e;
        for(auto p:s){
            ll flag=0;
            if(mp[p-x]==0){
                ans+=x;
                mp[p-x]++;
                v.pb(p-x);
                if(v.size()==m) break;
                flag++;
            }
            if(mp[p+x]==0){
                ans+=x;
                mp[p+x]++;
                v.pb(p+x);
                if(v.size()==m) break;
                flag++;
            }
            if(flag==0) e.pb(p);
        }
        if(v.size()==m) break;
        x++;
        for(auto p:e) s.erase(p);
    }
    cout<<ans<<"\n";
    for(auto p:v) cout<<p<<" ";
}