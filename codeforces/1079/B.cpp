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
	ll n = s.size();
	for (ll i = 1; i <= 5; i++) {
		if ((n + i - 1) / i > 20) continue;
		ll j = (n + i - 1) / i;
		cout << i << " " << j << endl;
		vector<string> ans(i, string(j, '.'));
		ll c = i * j - n;
		for (int k = 0, r = 0; k < j and c > 0; k++, (r += 1) %= i, c--)
			ans[r][k] = '*';
		for (int k = 0, r = 0, c = 0; k < n; k++) {
			if (ans[r][c] == '*') k--;
			else ans[r][c] = s[k];
			r += (c == j - 1);
			(c += 1) %= j;
		}
		for (auto x : ans) cout << x << endl;
		return;
	}

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
