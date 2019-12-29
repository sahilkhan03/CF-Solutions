#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define endl "\n"
const int MOD=1e9+7;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef HOME
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define me(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n+5];
    map<int,int>m;
    set<int>v;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]){
            m[a[i]] = i;
        }else{
            v.insert(i);
        }
    }
    set<int>k;
    for(int i=1;i<=n;i++){
        if(m[i] == 0){
            k.insert(i);
        }
    }
    map<int,int>vis;
    for(auto x:k){
        vis[x]++;
    }
    for(auto y:v){
        vis[y]++;
    }
    // debug()<<me(vis);
    // debug()<<me(k) me(v);
    for(auto z:vis){
        if(z.second >= 2){
            // debug()<<me(v);
            for(auto y = v.rbegin();y != v.rend();y++){
                if(*y !=  z.first){
                    a[*y] = z.first;
                    v.erase(*y);
                    k.erase(z.first);
                    break;
                }
            }
            // for(auto y:v){
            //     if(y !=  z.first){
            //         a[y] = z.first;
            //         v.erase(y);
            //         // k.erase(z.first);
            //         break;
            //     }
            // }
        }
    }
    for(auto x:k){
        bool flag = false;
        for(auto y:v){
            if(y != x){
                a[y] = x;
                v.erase(y);
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
        // cerr<<i<<" ";
    }
    return 0;
    
}