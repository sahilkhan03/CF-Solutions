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
	ll n, m, k;
	cin >> n >> m >> k;
	vector<string> s(n);
	cin >> s;
	vl ans;
	ll id = 0;
	vector<vl> v(n, vl(m, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '*' or v[i][j] != -1) continue;
			ll cur = 0;
			queue<pl> q;
			q.push({i, j});
			while (!q.empty()) {
				pl tp = q.front(); q.pop();
				if (v[tp.F][tp.S] != -1 or s[tp.F][tp.S] == '*') continue;
				v[tp.F][tp.S] = id;
				if (tp.F < n - 1) {
					if (s[tp.F + 1][tp.S] == '*') cur++;
					else q.push({tp.F + 1, tp.S});
				}
				if (tp.S < m - 1) {
					if (s[tp.F][tp.S + 1] == '*') cur++;
					else q.push({tp.F, tp.S + 1});
				}

				if (tp.F > 0) {
					if (s[tp.F - 1][tp.S] == '*') cur++;
					else q.push({tp.F - 1, tp.S});
				}
				if (tp.S > 0) {
					if (s[tp.F][tp.S - 1] == '*') cur++;
					else q.push({tp.F, tp.S - 1});
				}
			}
			ans.pb(cur);
			id++;
		}
	}
	while (k--) {
		ll a, b;
		cin >> a >> b;
		cout << ans[v[a - 1][b - 1]] << endl;
	}
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
