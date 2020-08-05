
// Problem : E1. Weights Division (easy version)
// Contest : Codeforces - Codeforces Round #661 (Div. 3)
// URL : https://codeforces.com/contest/1399/problem/E1
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	“Whether you think you can, or you think you can’t – you’re right” - Henry Ford 
*/

#pragma GCC optimize("Ofast")
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
ll n, S, ans = 0, sum = 0;
vector<map<ll, pl>> v;
vl cnt;
ll dfs(ll u, ll p) {
	ll s = (v[u].size() < 2);
	for(auto x: v[u]) {
		if(x.F != p) {
			s += dfs(x.F, u);
		}
	}
	if(p != -1) cnt[v[p][u].S] = s;
	return s;
}
struct cmp {
	bool operator()(pl a, pl b) {
		return (a.F*a.S - (a.F/2)*a.S) < (b.F*b.S - (b.F/2)*b.S);
	}
};

void solve() {
	cin >> n >> S;
	ans = 0;
	sum = 0;
	v = vector<map<ll, pl>>(n);
	cnt = vl(n - 1, 0);
	vl W;
	for(int i = 0; i < n - 1; i++) {
		ll a, b, w; 
		cin >> a >> b >> w;
		a--, b--;
		W.pb(w);
		v[a][b] = {w, i};
		v[b][a] = {w, i};
	}
	dfs(0, -1);
	priority_queue<pl, vector<pl>,cmp> pq;
	for(int i = 0; i < n - 1; i++) {
		sum += W[i]*cnt[i];
		pq.push({W[i], cnt[i]});
	}
	debug(cnt);
	while(sum > S) {
		auto tp = pq.top();
		debug(tp, sum);
		pq.pop();
		sum -= tp.F * tp.S;
		tp.F/=2;
		sum += tp.F * tp.S;
		pq.push(tp);
		ans++;
		debug(sum);
	}
	cout << ans << endl;
}

int main()
{
	fast;
   ll t = 1;
   cin >> t;
   while(t--) {
   	solve();
   }
	return 0;
}
