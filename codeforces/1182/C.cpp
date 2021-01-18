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
	int n; cin >> n;
	vector<string> s(n);
	vector<vi> cnt(5, vi(1e5 + 5, -1));
	map<char, int> m;
	m['a'] = 0, m['e'] = 1, m['o'] = 2, m['i'] = 3, m['u'] = 4;
	vector<pl> sec;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		int c = 0, ls = 0;
		for (int j = 0; j < s[i].size(); j++) {
			if (m.find(s[i][j]) != m.end()) {
				ls = m[s[i][j]];
				c++;
			}
		}
		if (cnt[ls][c] == -1) cnt[ls][c] = i;
		else {
			sec.pb({cnt[ls][c], i});
			cnt[ls][c] = -1;
		}
	}
	vector<pl> use;
	for (int i = 0; i < 1e5 + 5; i++) {
		int ls = -1;
		for (int j = 0; j < 5; j++) {
			if (cnt[j][i] != -1) {
				if (ls == -1) ls = cnt[j][i];
				else {
					use.pb({cnt[j][i], ls});
					ls = -1;
				}
			}
		}
	}
	debug(sec);
	vector<vl> ans;
	while (!use.empty() and !sec.empty()) {
		ans.pb({use.back().F, sec.back().F, use.back().S, sec.back().S});
		use.pop_back();
		sec.pop_back();
	}
	while (!sec.empty() and sec.size() > 1) {
		debug(')');
		auto p1 = sec.back();
		sec.pop_back();
		ans.pb({p1.F, sec.back().F, p1.S, sec.back().S});
		sec.pop_back();
	}
	cout << ans.size() << endl;
	for (auto& x : ans) {
		cout << s[x[0]] << " " << s[x[1]] << endl;
		cout << s[x[2]] << " " << s[x[3]] << endl;
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
