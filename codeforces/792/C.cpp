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
	string s; cin >> s;
	ll sum = accumulate(all(s), 0ll) - s.size() * ('0');
	if (sum % 3 == 0) {
		cout << s << endl;
		return;
	}
	vector<vl> v(3);
	for (int i = 0; i < s.size(); i++) {
		char x = s[i];
		v[(x - '0') % 3].pb(i);
	}
	vector<string> ans;
	if (sum % 3 == 1) {
		if (v[1].size()) {
			string tmp = s;
			tmp.erase(tmp.begin() + v[1].back());
			if (!tmp.empty()) ans.pb(tmp);
		}
		if (v[2].size() >= 2) {
			string tmp = s;
			tmp.erase(tmp.begin() + v[2].back());
			v[2].pop_back();
			tmp.erase(tmp.begin() + v[2].back());
			if (!tmp.empty()) ans.pb(tmp);
		}
	}
	else {
		if (v[2].size()) {
			string tmp = s;
			tmp.erase(tmp.begin() + v[2].back());
			if (!tmp.empty()) ans.pb(tmp);
		}
		if (v[1].size() >= 2) {
			string tmp = s;
			tmp.erase(tmp.begin() + v[1].back());
			v[1].pop_back();
			tmp.erase(tmp.begin() + v[1].back());
			if (!tmp.empty()) ans.pb(tmp);
		}
	}
	for (auto& x : ans) {
		ll i = 0;
		while (i < x.size() and x[i] == '0') i++;
		if (i < x.size()) x = x.substr(i);
		else x = "0";
	}
	sort(all(ans), [](const string & a, string & b) -> bool {
		return a.size() > b.size();
	});
	if (ans.empty() or !ans[0].size()) cout << -1 << endl;
	else cout << ans[0] << endl;
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
