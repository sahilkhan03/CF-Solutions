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

void tog(char &c) {
	if (c == '1') c = '0';
	else c = '1';
}

vector<vector<pl>> ans;

void solve() {
	ans.clear();
	ll n, m;
	cin >> n >> m;
	vector<string> v(n);
	cin >> v;
	for (int i = 0; i < n - 2; i++) {
		int j = 0;
		while (j < m) {
			if (j + 1 < m and v[i][j] == '1' and v[i][j + 1] == '1')  {
				ans.pb({{i + 1, j + 1}, {i + 1, j + 2}, {i + 2, j + 1}});
				v[i][j] = v[i][j + 1] = '0';
				tog(v[i + 1][j]);
				j += 2;
				continue;
			}
			if (v[i][j] == '1') {
				if (j + 1 < m) ans.pb({{i + 1, j + 1}, {i + 2, j + 2}, {i + 2, j + 1}}), tog(v[i][j]), tog(v[i + 1][j + 1]), tog(v[i + 1][j]);
				else ans.pb({{i + 1, j + 1}, {i + 2, j}, {i + 2, j + 1}}), tog(v[i][j]),  tog(v[i + 1][j - 1]), tog(v[i + 1][j]);
			}
			j++;
		}
	}
	int i = n - 2;
	for (int j = 0; j < m - 2; j++) {
		if (v[i][j] == '1') {
			ans.pb({{i + 1, j + 1}, {i + 2, j + 2}, {i + 2, j + 1}}), tog(v[i][j]), tog(v[i + 1][j + 1]), tog(v[i + 1][j]);
		}
		if (v[i + 1][j] == '1') {
			ans.pb({{i + 2, j + 1}, {i + 2, j + 2}, {i + 1, j + 2}}), tog(v[i + 1][j + 1]), tog(v[i][j + 1]), tog(v[i + 1][j]);
		}
	}
	debug(v);
	int j = m - 2;
	vector<pl> cur, c1, c2, id = {{i, j}, {i + 1, j}, {i, j + 1}, {i + 1, j + 1}};
	for (auto x : id) {
		if (v[x.F][x.S] == '1') c1.pb(x);
		else c2.pb(x);
	}
	if (c1.size() > 1) {
		for (auto x : c1) {
			if (cur.size() >= 3) break;
			cur.pb({x.F + 1, x.S + 1});
			tog(v[x.F][x.S]);
		}
		while (cur.size() < 3) {
			pl x = c2.back(); c2.pop_back();
			cur.pb({x.F + 1, x.S + 1});
			tog(v[x.F][x.S]);
		}
		ans.pb(cur);
	}
	if (v[i][j] == '1') {
		ans.pb({{i + 1, j + 1}, {i + 1, j + 2}, {i + 2, j + 1}});
		ans.pb({{i + 1, j + 1}, {i + 1, j + 2}, {i + 2, j + 2}});
		ans.pb({{i + 1, j + 1}, {i + 2, j + 1}, {i + 2, j + 2}});
		tog(v[i][j]);
	}
	else if (v[i + 1][j] == '1') {
		ans.pb({{i + 2, j + 1}, {i + 1, j + 1}, {i + 2, j + 2}});
		ans.pb({{i + 2, j + 1}, {i + 1, j + 2}, {i + 2, j + 2}});
		ans.pb({{i + 2, j + 1}, {i + 1, j + 2}, {i + 1, j + 1}});
		tog(v[i + 1][j]);
	}
	else if (v[i][j + 1] == '1') {
		ans.pb({{i + 1, j + 2}, {i + 1, j + 1}, {i + 2, j + 2}});
		ans.pb({{i + 1, j + 2}, {i + 1, j + 1}, {i + 2, j + 1}});
		ans.pb({{i + 1, j + 2}, {i + 2, j + 1}, {i + 2, j + 2}});
		tog(v[i][j + 1]);
	}
	else if (v[i + 1][j + 1] == '1') {
		ans.pb({{i + 2, j + 2}, {i + 1, j + 2}, {i + 2, j + 1}});
		ans.pb({{i + 2, j + 2}, {i + 1, j + 2}, {i + 1, j + 1}});
		ans.pb({{i + 2, j + 2}, {i + 2, j + 1}, {i + 1, j + 1}});
		tog(v[i + 1][j + 1]);
	}
	debug(v);
	cout << ans.size() << endl;
	for (auto x : ans) {
		for (auto y : x) cout << y << " ";
		cout << endl;
	}

}

int main()
{
	fast;
	ll T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
