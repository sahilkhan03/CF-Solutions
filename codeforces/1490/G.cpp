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
	ll n, m, sum = 0;
	cin >> n >> m;
	vl v(n); cin >> v;
	vl pre(n); pre[0] = v[0];
	sum = v[0];
	for (int i = 1; i < n; i++) {
		pre[i] = max(pre[i - 1], sum + v[i]);
		sum += v[i];
	}
	auto calc = [&](ll s) {
		ll ans = n - 1;
		for (ll st = 1e6; st; st /= 2) {
			while (ans - st >= 0 and pre[ans - st] >= s) ans -= st;
		}
		return ans;
	};
	while (m--) {
		ll x; cin >> x;
		if (pre.back() >= x) {
			cout << lower_bound(all(pre), x) - pre.begin() << " ";
			continue;
		}
		if (sum <= 0) {
			cout << -1 << " ";
			continue;
		}
		ll tm = (x - pre.back() + sum - 1) / sum;
		cout << tm * n + calc(x - sum * tm)  << " ";
	}
	cout << endl;
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
