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

void solve() {
	vector<pl> ans;
	ll n, d, k;
	cin >> n >> d >> k;
	if (d > 1 and k < 2) {
		cout << "NO" << endl;
		return;
	}
	n--;
	for (int i = 1; i <= d; i++) {
		ans.pb({i, i + 1});
		n--;
		if (n < 0) {
			cout << "NO" << endl;
			return;
		}
	}
	ll st = d + 2;
	for (ll i = 2; i < d + 1; i++) {
		queue<array<ll, 3>> q;
		q.push({i, 1, 2});
		ll lim = min(i - 1, d + 1 - i) + 1;
		debug(i, lim);
		while (!q.empty() and n) {
			auto [node, lvl, used] = q.front(); q.pop();
			if (lvl < lim) {
				while (used < k and n) {
					ans.pb({node, st});
					q.push({st, lvl + 1, 1});
					used++; st++; n--;
				}
			}
		}
	}
	if (n) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (auto x : ans) cout << x << endl;
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
