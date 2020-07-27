
// Problem : D. Edge Deletion
// Contest : Codeforces - Educational Codeforces Round 54 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1076/problem/D
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	“Whether you think you can, or you think you can’t – you’re right” - Henry Ford 
*/

#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define pb push_back
#define pl pair<ll, ll>
#define vl vector<ll>
#define vi vector<int>
#define endl '\n'

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

template <typename T, typename TT>
ostream &operator<<(ostream &os, const pair<T, TT> &t) {
    return os << t.first << " " << t.second;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &t) {
    for (auto &i : t) os << i << " ";
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &t : v) is >> t;
    return is;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, vector<pair<T1, T2>> &v) {
    for (pair<T1, T2> &t : v) is >> t.first >> t.second;
    return is;
}

const ll mod = 1e9 + 7;

int main()
{
    fast;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<vl>> v(n);
    vl ans;
    for(int i = 0; i < m; i++) {
    	ll a, b, w;
    	cin >> a >> b >> w;
    	a--, b--;
    	v[a].pb({b, w, i + 1});
    	v[b].pb({a, w, i + 1});
    }
    debug(v);
    priority_queue<vl, vector<vl>, greater<vl>> pq;
    pq.push({0, 0, -1});
    vector<bool> vis(n, 0);
    vl dis(n, 1e18);
    dis[0] = 0;
    while(!pq.empty() and k > 0) {
    	auto tp = pq.top(); pq.pop();
    	if(vis[tp[1]]) continue;
    	vis[tp[1]] = 1;
    	dis[tp[1]] = tp[0];
    	if(tp[2] > 0) {
    		ans.push_back(tp[2]); k--;	
    	}
    	for(auto x: v[tp[1]]) {
    		if(!vis[x[0]] and dis[x[0]] > tp[0] + x[1]) {
    			dis[x[0]] = tp[0] + x[1];
    			pq.push({dis[x[0]], x[0], x[2]});
    		}
    	}
    }
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}
