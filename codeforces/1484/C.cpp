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

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vl> v(m), frnd(n + 1);
	for (int i = 0; i < m; i++) {
		ll k; cin >> k;
		v[i] = vl(k);
		cin >> v[i];
		for (auto x : v[i])
			frnd[x].pb(i);
	}
	vl ans(m);
	for (auto& x : frnd) {
		sort(all(x), [&](ll a, ll b) -> bool{
			return v[a].size() < v[b].size();
		});
	}
	vl ord;
	for (int i = 0; i <= n; i++) ord.pb(i);
	sort(all(ord), [&](ll a, ll b) -> bool {
		return frnd[a].size() < frnd[b].size();
	});
	for (auto cur : ord) {
		int use = 0;
		for (auto& x : frnd[cur]) {
			if (ans[x]) continue;
			ans[x] = cur;
			use++;
			if (use >= (m + 1) / 2) break;
		}
	}
	if (*min_element(all(ans))) cout << "YES" << endl << ans << endl;
	else cout << "NO" << endl;
}

int main()
{
	fast;
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
