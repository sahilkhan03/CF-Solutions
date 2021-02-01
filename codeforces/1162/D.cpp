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
	int n, m;
	cin >> n >> m;
	vector<pl> v(m); cin >> v;
	map<pl, int> mp;
	for (int i = 0; i < m; i++) mp[v[i]] = i;
	function<bool(int)> check = [&](int k) {
		vi vis(m);
		int i = 0;
		while (i < m) {
			if (!vis[i]) {
				for (int j = k; j <= n; j += k) {
					int edf = v[i].F + j, eds = v[i].S + j;
					if (edf > n) edf -= n;
					if (eds > n) eds -= n;
					if (mp.find({edf, eds}) != mp.end()) {
						vis[mp[ {edf, eds}]] = 1;
						continue;
					}
					if (mp.find({eds, edf}) != mp.end()) {
						vis[mp[ {eds, edf}]] = 1;
						continue;
					}
					return 0;
				}
			}
			i++;
		}
		return 1;
	};
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			if (check(i) or check(n / i)) {
				cout << "Yes" << endl;
				return;
			}
		}
	}
	if (check(1)) cout << "Yes" << endl;
	else cout << "No" << endl;
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
