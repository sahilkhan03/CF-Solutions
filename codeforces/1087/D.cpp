#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define pb push_back
#define pl pair<ll, ll>
#define vl vector<ll>
#define vi vector<int>
#define endl '\n'

template <typename T, typename TT>
inline ostream &operator<<(ostream &os, const pair<T, TT> &t) {
	return os << t.first << " " << t.second;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &t) {
	for (auto i : t) os << i << " ";
	return os;
}
template <typename T>
inline istream &operator>>(istream &is, vector<T> &v) {
	for (T &t : v) is >> t;
	return is;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &is, pair<T1, T2> &t) {
	is >> t.first >> t.second;
	return is;
}

#ifdef LOCAL
#define debug(args...) (Debugger()), args
class Debugger {
public:
	bool first;
	string separator;
	Debugger(const string &_separator = ", ") : first(true), separator(_separator) {}
	template <typename ObjectType>
	Debugger &operator, (const ObjectType &v) {
		if (!first) cerr << separator;
		cerr << v;
		first = false;
		return *this;
	}
	~Debugger() { cerr << endl; }
};
#else
#define debug(args...)
#endif

const ll mod = 1e9 + 7;
ll n, st, ed; ld s;
vector<vl> v;
vl cnt;
pl mx = {0, 0};
void dfs(ll u, ll p, ll dis) {
	// debug(u, p, dis);
	mx = max(mx, {dis, u});
	for (auto x : v[u]) {
		if (x != p) dfs(x, u, dis + 1);
	}
}
vl cur, dia;
void dfs1(ll u, ll p) {
	cur.pb(u);
	if (u == ed) {
		dia = cur;
		return;
	}
	for (auto x : v[u]) {
		if (x != p) {
			dfs1(x, u);
		}
	}
	cur.pop_back();
}
set<ll> dd;

ll calc(ll u, ll p) {
	ll ans = (v[u].size() == 1);
	for (auto x : v[u]) {
		if (x != p and dd.find(x) == dd.end()) ans += calc(x, u);
	}
	return ans;
}

bool check(ld mid) {
	ld rem = s - mid, len = mid / (dia.size() - 1);
	for (int i = 0; i < cnt.size(); i++) {
		rem -= cnt[i] * mid / 2;
	}
	debug(rem, mid);
	return rem <= 1e-8;
}

void solve() {
	cin >> n >> s;
	v.resize(n);
	cnt.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].pb(b - 1);
		v[b - 1].pb(a - 1);
	}
	if (n == 2) {
		cout << s << endl;
		return;
	}
	dfs(0, -1, 0);
	st = mx.S;
	mx = {0, st};
	dfs(st, - 1, 0);
	ed = mx.S;
	dfs1(st, -1);
	dd = set<ll>(all(dia));
	for (int i = 0; i < dia.size(); i++) {
		cnt[max(i, int(dia.size()) - i - 1)] += calc(dia[i], -1);
	}
	ll sum = accumulate(all(cnt), 0ll);
	debug(sum);
	printf("%.10Lf\n", 2 * s / sum);
}

int main()
{
	fast;
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
