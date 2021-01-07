#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
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

void solve() {
	ll n; cin >> n;
	vector<pl> con, v(n);
	cin >> v;
	vl c(n); cin >> c;
	vl k(n); cin >> k;
	ll ans = 0;
	priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
	for (int i = 0; i < n; i++) pq.push({c[i], -1, i});
	vl pw, vis(n, 0);
	while (!pq.empty()) {
		auto [cost, p, j] = pq.top();
		pq.pop();
		if (vis[j]) continue;
		ans += cost; vis[j] = 1;
		if (p == -1) pw.pb(j + 1);
		else con.pb({p + 1, j + 1});
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				pq.push({(k[i] + k[j]) * (abs(v[i].F - v[j].F) + abs(v[i].S - v[j].S)), j, i});
			}
		}
	}
	cout << ans << endl;
	cout << pw.size() << endl << pw << endl;
	cout << con.size() << endl;
	for (auto x : con) cout << x << endl;
}

int main()
{
	fast;
	ll T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
