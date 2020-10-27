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

vl scnt(string &s) {
	vl cnt(26, 0);
	for (int i = 0; i < s.size(); i++)
		cnt[s[i] - 'a']++;
	return cnt;
}

void solve() {
	string s, a, b;
	cin >> s >> a >> b;
	vl cnt1 = scnt(s), cnt2 = scnt(a), cnt3 = scnt(b);
	ll mx = 1e18;
	for (int i = 0; i < 26; i++) {
		if (cnt2[i]) mx = min(mx, cnt1[i] / cnt2[i]);
	}
	pl req = {0, 0};
	for (int i = 0; i <= mx; i++) {
		ll c = 1e18;
		for (int j = 0; j < 26; j++) {
			if (cnt3[j]) c = min(c, (cnt1[j] - i * cnt2[j]) / cnt3[j]);
		}
		if (i + c > req.F + req.S)
			req = {i, c};
	}
	debug(req);
	string ans = "";
	for (int i = 0; i < 26; i++)
		cnt1[i] -= req.F * cnt2[i] + req.S * cnt3[i];
	while (req.F--) ans += a;
	while (req.S--) ans += b;
	for (int i = 0; i < 26; i++)
		while (cnt1[i]--) ans += char('a' + i);
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
