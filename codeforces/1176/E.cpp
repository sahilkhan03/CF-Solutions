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
#define inv(v) for(auto&i:v) in(i)
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpl vector<pair<ll,ll>>
#define INF 0x3f3f3f3f

int main() {
    ll t;
    in(t);
    while (t--)
    {
        ll n,m;
        in2(n,m);
        vector<ml> v(n,ml());
        bool done[n];
        memset(done,0,sizeof done);
        while(m--) {
            ll a,b;
            in2(a,b);
            a--;b--;
            v[a][b]=1;
            v[b][a]=1;
        }
        ll distance[n];
        queue<ll> q;    
        q.push(0);
        distance[0]=0;
        done[0]=1;
        while (!q.empty())
        {
            ll c = q.front();q.pop();   
            // cout<<c<<endl;
            for(auto x:v[c]) {
                if(!done[x.first]) {
                    done[x.first]=1;
                    distance[x.first] = distance[c]+1;
                    q.push(x.first);
                }
            }
        }
        // cout<<endl;
        // loop(i,n) {
        //     cout<<i+1<<"-"<<distance[i]<<endl;
        // }
        vl e,o;
        loop(i,n) {
            if(distance[i]%2 == 0) e.push_back(i);
            else o.push_back(i);
        }
        if(e.size()<o.size()) {
            cout<<e.size()<<endl;
            for(auto x:e) cout<<x+1<<" ";
        }
        else {
            cout<<o.size()<<endl;
            for(auto x:o) cout<<x+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}