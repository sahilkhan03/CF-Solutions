
// Problem : G. Candy Box (hard version)
// Contest : Codeforces - Codeforces Round #570 (Div. 3)
// URL : https://codeforces.com/contest/1183/problem/G
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

struct cmp {
	bool operator()(pl a, pl b) {
		if(a.F + a.S == b.F + b.S) 
			return a.F < b.F;
		return a.F + a.S < b.F + b.S;
	}
};

int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--) {
    	ll n;
    	cin >> n;
    	vector<pl> v(n + 1, {0, 0});
    	for(int i = 0; i < n; i++) {
    		ll a, f;
    		cin >> a >> f;
    		if(f) v[a].F++;
    		else v[a].S++;
    	}
    	priority_queue<pl, vector<pl>,  cmp> pq(all(v));
    	pl ans = {0, 0};
    	ll req = n + 1;
    	while(!pq.empty() and req > 0) {
    		auto tp = pq.top(); pq.pop();
    		if(tp.F + tp.S > req) {
    			ll len = tp.F + tp.S - req;
    			tp.F -= max(0ll, len - tp.S);
    			tp.S -= min(tp.S, len);
    			pq.push(tp);
    			continue;
    		}
    		req = min(req, tp.F + tp.S);
    		debug(tp, req);
    		ans.F += req, ans.S += min(req, tp.F);
    		req--;
    	}
    	cout << ans << endl;
    }

    return 0;
}
