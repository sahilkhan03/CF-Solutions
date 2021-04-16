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

vector<vl> v(10, vl(2e5 + 5));

void solve() {
	ll n, m;
	cin >> n >> m;
	vl cnt(10);
	while (n) {
		cnt[n % 10]++;
		n /= 10;
	}
	ll ans = 0;
	for (int i = 0; i < 10; i++) (ans += cnt[i] * v[i][m]) %= mod;
	cout << ans << endl;
}

int main()
{
	fast;
	int T = 1;
	for (int n = 0; n < 10; n++) {
		vl cur(10);
		cur[n] = 1;
		for (int i = 1; i < 2e5 + 5; i++) {
			vl tmp(10);
			for (int i = 1; i < 10; i++)
				tmp[i] = cur[i - 1];
			tmp[0] = cur[9];
			(tmp[1] += cur[9]) %= mod;
			cur = tmp;
			v[n][i] = accumulate(all(cur), 0ll) % mod;
		}
	}
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
