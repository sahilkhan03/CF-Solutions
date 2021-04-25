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

vi sieve(1e5 + 5);
void solve() {
	int n, q;
	cin >> n >> q;
	vi v(n); cin >> v;
	for (int i = 2; i < 1e5 + 5; i++) {
		if (!sieve[i]) {
			for (int j = i; j < 1e5 + 5; j += i)
				sieve[j] = i;
		}
	}
	set<int> s;
	int j = n - 1, i = n - 1;
	auto fact = [&](int num) {
		set<int> cur;
		while (num != 1) {
			cur.insert(sieve[num]);
			num /= sieve[num];
		}
		return cur;
	};
	vector<vi> lca(20, vi(n, n));
	while (i >= 0) {
		auto cur = fact(v[i]);
		for (auto x : cur) {
			while (s.find(x) != s.end()) {
				auto ret = fact(v[j--]);
				for (auto y : ret) s.erase(y);
			}
		}
		for (auto x : cur) s.insert(x);
		lca[0][i] = j;
		for (int p = 1; p < 20 and lca[p - 1][i] + 1 < n; p++) {
			lca[p][i] = lca[p - 1][lca[p - 1][i] + 1];
		}
		i--;
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int ans = 0;
		for (int st = 19; st >= 0 and l <= r; st--) {
			if (lca[st][l] <= r) {
				l = lca[st][l] + 1, ans += (1 << st);
				debug(st, l, ans);
			}
		}
		ans += (l <= r);
		cout << ans << endl;
	}
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
