#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
inline ostream &operator<<(ostream &os, const set<T> &t) {
	for (auto i : t) os << i << " ";
	return os;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &t) {
	for (auto i : t) os << i.first << " : " << i.second << endl;
	return os;
}
template <typename T>
inline istream &operator>>(istream &is, vector<T> &v) {
	for (T &t : v) is >> t;
	return is;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &is, vector<pair<T1, T2>> &v) {
	for (pair<T1, T2> &t : v) is >> t.first >> t.second;
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
	vl v(n); cin >> v;
	vl c1, c2, c3;
	vector<pl> ans;
	for (int i = n; i > 0; i--) {
		if (!v[i - 1]) continue;
		if (v[i - 1] == 1) {
			c1.pb(i);
			ans.pb({i, i});
		}
		else if (v[i - 1] == 2) {
			if (c1.empty()) {
				cout << -1 << endl;
				return;
			}
			ans.pb({c1.back(), i});
			c2.pb(i);
			c1.pop_back();
		}
		else {
			if (c3.empty()) {
				if (c2.empty()) {
					if (c1.empty()) {
						cout << -1 << endl;
						return;
					}
					else {
						ans.pb({i, i});
						ans.pb({i, c1.back()});
						c1.pop_back();
					}
				}
				else {
					ans.pb({i, i});
					ans.pb({i, c2.back()});
					c2.pop_back();
				}
			}
			else {
				ans.pb({i, i});
				ans.pb({i, c3.back()});
				c3.pop_back();
			}
			c3.pb(i);
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans) cout << x << endl;
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
