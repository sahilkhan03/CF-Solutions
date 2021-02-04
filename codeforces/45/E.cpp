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

void calc(vector<string> &v, vi &ans, vi cur, int lvl) {
	vector<vi> g(26);
	for (auto x : cur) {
		if (v[x].size() <= lvl) ans.pb(x);
		else g[v[x][lvl] - "Aa"[lvl > 0]].pb(x);
	}
	for (auto& x : g) if (!x.empty()) calc(v, ans, x, lvl + 1);
}

void solve() {
	int n; cin >> n;
	vector<string> v1(n), v2(n);
	cin >> v1 >> v2;
	vi ans1, ans2, cur;
	for (int i = 0; i < n; i++) cur.pb(i);
	calc(v1, ans1, cur, 0);
	calc(v2, ans2, cur, 0);
	vector<vi> p1(26), p2(26);
	for (int i = n - 1; i >= 0; i--) p1[v1[ans1[i]][0] - 'A'].pb(ans1[i]);
	for (int i = n - 1; i >= 0; i--) p2[v2[ans2[i]][0] - 'A'].pb(ans2[i]);
	string ans;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < i; j++) {
			while (!p2[j].empty() and p1[i].size() > p2[i].size()) {
				ans += v1[p1[i].back()] + " " + v2[p2[j].back()] + ", ";
				p1[i].pop_back();
				p2[j].pop_back();
			}
		}
		while (!p1[i].empty() and !p2[i].empty()) {
			ans += v1[p1[i].back()] + " " + v2[p2[i].back()] + ", ";
			p1[i].pop_back();
			p2[i].pop_back();
		}
		for (int j = i + 1; j < 26; j++) {
			while (p1[j].size() < p2[j].size() and !p1[i].empty()) {
				ans += v1[p1[i].back()] + " " + v2[p2[j].back()] + ", ";
				p1[i].pop_back();
				p2[j].pop_back();
			}
		}
	}
	ans.pop_back();
	ans.pop_back();
	cout << ans << endl;
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
