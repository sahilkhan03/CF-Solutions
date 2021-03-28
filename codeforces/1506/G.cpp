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
	string s;
	cin >> s;
	int n = s.size();
	vector<vi> v(26);
	int use = 0;
	vi vis(26);
	for (int i = 0; i < n; i++) {
		v[s[i] - 'a'].pb(i);
	}
	for (int i = 0; i < 26; i++) {
		if (v[i].empty()) vis[i] = 1, use++;
	}
	string ans;
	int ls = -1;
	auto check = [&](int c, int l) {
		for (int i = 0; i < 26; i++) {
			if (vis[i] or i == c) continue;
			if (upper_bound(all(v[i]), l) == v[i].end())
				return 0;
		}
		return 1;
	};
	while (use < 26) {
		for (int i = 25; i >= 0; i--) {
			if (vis[i]) continue;
			auto it = upper_bound(all(v[i]), ls) - v[i].begin();
			debug(char(i + 'a'), it, check(i, v[i][it]));
			if (check(i, v[i][it])) {
				ls = v[i][it];
				vis[i] = 1;
				ans += char(i + 'a');
				break;
			}
		}
		use++;
	}
	cout << ans << endl;
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
