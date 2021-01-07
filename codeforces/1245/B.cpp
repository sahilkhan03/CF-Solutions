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

void solve() {
	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	string s, t;
	cin >> s;
	vector<vl> cnt(3);
	for (int i = 0; i < n; i++) {
		t += '.';
		if (s[i] == 'R') cnt[0].pb(i);
		else if (s[i] == 'P') cnt[1].pb(i);
		else cnt[2].pb(i);
	}
	ll ans = 0;
	for (int i = 0; i < cnt[0].size() and b > 0; i++, b--, ans++) {
		t[cnt[0][i]] = 'P';
	}
	for (int i = 0; i < cnt[1].size() and c > 0; i++, c--, ans++) {
		t[cnt[1][i]] = 'S';
	}
	for (int i = 0; i < cnt[2].size() and a > 0; i++, a--, ans++) {
		t[cnt[2][i]] = 'R';
	}
	if (ans < (n + 1) / 2) {
		cout << "NO" << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (t[i] == '.') {
			if (s[i] == 'R') {
				if (b) b-- , t[i] = 'P';
				else if (a) a--, t[i] = 'R';
				else c--, t[i] = 'S';
			}
			else if (s[i] == 'P') {
				if (c) c-- , t[i] = 'S';
				else if (b) b--, t[i] = 'P';
				else a--, t[i] = 'R';
			}
			else {
				if (a) a-- , t[i] = 'R';
				else if (c) c--, t[i] = 'S';
				else b--, t[i] = 'P';
			}
		}
	}
	cout << "YES" << endl << t << endl;
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
