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
ll n; vector<string> v;
string ans;
void calc(vl st, ll lvl, string pre) {
	debug(lvl, st, pre, ans);
	if (st.size() == 1 or pre.size() > 100) {
		for (auto x : st) ans += v[x];
		return;
	}
	vector<vl> tmp(26);
	for (int i = 0; i < st.size(); i++) {
		char x;
		if (lvl < v[st[i]].size()) x = v[st[i]][lvl];
		else x = pre[lvl - v[st[i]].size()];
		tmp[x - 'a'].pb(st[i]);
	}
	for (int i = 0; i < 26; i++) {
		if (tmp[i].empty()) continue;
		calc(tmp[i], lvl + 1, pre + char(i + 'a'));
	}
}

void solve() {
	cin >> n;
	v = vector<string>(n);
	cin >> v;
	vl st;
	for (int i = 0; i < n; i++) st.pb(i);
	calc(st, 0, "");
	cout << ans << endl;
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
