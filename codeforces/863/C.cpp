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
	ll k, a, b;
	cin >> k >> a >> b;
	vector<vl> ch1(3, vl(3)), ch2(3, vl(3)), ch3(3, vl(3, -1));
	cin >> ch1 >> ch2;
	vector<pl> sc = {{0, 0}};
	while (ch3[a - 1][b - 1] == -1) {
		pl cur = {0, 0};
		ch3[a - 1][b - 1] = sc.size();
		if (a != b) {
			if ((a == 1 and b == 3 ) or (a == 2 and b == 1) or (a == 3 and  b == 2)) cur = {1, 0};
			else cur = {0, 1};
		}
		sc.pb({sc.back().F + cur.F, sc.back().S + cur.S});
		debug(a, b);
		ll na = ch1[a - 1][b - 1], nb = ch2[a - 1][b - 1];
		a = na, b = nb;
	}
	pl ans = {0, 0};
	ll st = ch3[a - 1][b - 1];
	if (k <= st) {
		cout << sc[k] << endl;
		return;
	}
	k -= st - 1;
	ans = sc[st - 1];
	ll len = sc.size() - st , t = k / len, md = k % len;
	debug(st, k, len, t, md);
	ans.F += (sc.back().F - sc[st - 1].F) * t;
	ans.S += (sc.back().S - sc[st - 1].S) * t;
	ans.F += sc[st + md - 1].F - sc[st - 1].F;
	ans.S += sc[st + md - 1].S - sc[st - 1].S;
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
