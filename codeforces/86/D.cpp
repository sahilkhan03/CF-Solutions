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

ll s;
ll m[1000006];
bool compare(pair<pll,ll> q1, pair<pll,ll> q2) {
    if(q1.first.first/s == q2.first.first/s) 
        return ( ((q1.first.first/s)%2) ? (q1.first.second < q2.first.second) : (q1.first.second > q2.first.second) );
    return q1.first.first/s < q2.first.first/s;
}
 
int main()
{
    fast;
    ll n,q;
    in2(n,q);
    s = ceil(sqrt(n));
    ll v[n];
    loop(i,n) in(v[i]);
    pair<pll,ll> queries[q];
    ll ans[q];
    for(ll i=0;i<q;i++) {
        ll l,r;
        in2(l,r);
        l--;r--;
        queries[i] = {{l,r},i};
    }
 
    sort(queries,queries+q,compare);
    ll st=-1,en=-1,c=0;
    // for(auto x:queries) cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl; 
    for(pair<pll,ll> qr: queries) {
        ll l = qr.first.first, r = qr.first.second;
        if(st==-1) {st = l, en = l-1;}
        while(en<r) {
            en++;
            c-=m[v[en]]*m[v[en]]*v[en];
            m[v[en]]++;
            c+=m[v[en]]*m[v[en]]*v[en];
            // cout<<1<<" "<<m[v[en]]<<" "<<c<<endl;    
        }
        while (en>r)
        {   
            c-=m[v[en]]*m[v[en]]*v[en];
            m[v[en]]--;
            c+=m[v[en]]*m[v[en]]*v[en];
            en--;
            // cout<<2<<" "<<m[v[en]]<<" "<<c<<endl;
        }
        
        while(st<l) {
            c-=m[v[st]]*m[v[st]]*v[st];
            m[v[st]]--;
            c+=m[v[st]]*m[v[st]]*v[st];
            st++;
 
         //   cout<<3<<" "<<m[v[st]]<<" "<<c<<endl;
        }
        while(st>l) {
            st--;
            c-=m[v[st]]*m[v[st]]*v[st];
            m[v[st]]++;
            c+=m[v[st]]*m[v[st]]*v[st];
            // cout<<4<<" "<<m[v[st]]<<" "<<c<<endl;
        }
        ans[qr.second] = c;
        // cout<<st<<" "<<en<<endl;
    }
    loop(i,q) printf("%lld\n",ans[i]);
    return 0;
}