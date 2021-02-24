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
	vector<string> s(n), fans;
	cin >> s;
	function<pair<ll, vector<string>>(string, string)> calc = [&](string f1, string f2) {
		vector<pl> v1, v2;
		ll tot1 = 0, tot2 = 0;
		for (int i = 0; i < n; i++) {
			ll c1 = 0, c2 = 0;
			for (int j = 0; j < m; j++) {
				if (i & 1) {
					c1 += (s[i][j] != f1[j & 1]);
					c2 += (s[i][j] != f1[!(j & 1)]);
				}
				else {
					c1 += (s[i][j] != f2[j & 1]);
					c2 += (s[i][j] != f2[!(j & 1)]);
				}
			}
			if (c1 > c2) v1.pb({c2, 1}), tot1 += c2;
			else v1.pb({c1, 0}), tot1 += c1;
		}
		for (int j = 0; j < m; j++) {
			ll c1 = 0, c2 = 0;
			for (int i = 0; i < n; i++) {
				if (j & 1) {
					c1 += (s[i][j] != f1[i & 1]);
					c2 += (s[i][j] != f1[!(i & 1)]);
				}
				else {
					c1 += (s[i][j] != f2[i & 1]);
					c2 += (s[i][j] != f2[!(i & 1)]);
				}
			}
			if (c1 > c2) v2.pb({c2, 1}), tot2 += c2;
			else v2.pb({c1, 0}), tot2 += c1;
		}
		vector<string> ans(n, string(m, 'A'));
		if (tot1 > tot2) {
			for (int j = 0; j < m; j++) {
				for (int i = 0; i < n; i++) {
					if (j & 1) {
						ans[i][j] = (v2[j].S ? f1[!(i & 1)] : f1[i & 1]);
					}
					else {
						ans[i][j] = (v2[j].S ? f2[!(i & 1)] : f2[i & 1]);
					}
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (i & 1) {
						ans[i][j] = (v1[i].S ? f1[!(j & 1)] : f1[j & 1]);
					}
					else {
						ans[i][j] = (v1[i].S ? f2[!(j & 1)] : f2[j & 1]);
					}
				}
			}
		}
		return pair<ll, vector<string>>({min(tot1, tot2), ans});
	};
	string tmp = "ATGC";
	ll mn = 1e18;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			string f1, f2;
			f1 += tmp[i];
			f1 += tmp[j];
			for (int k = 0; k < 4; k++)
				if (k != i and k != j) f2 += tmp[k];
			auto cur = calc(f1, f2);
			if (cur.F < mn) mn = cur.F, fans = cur.S;
		}
	}
	for (auto& x : fans) cout << x << endl;
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
