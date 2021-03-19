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
	ll n; cin >> n;
	vl v(n); cin >> v;
	for (auto& x : v) x = __builtin_popcountll(x);
	vl odd = { -1};
	for (int i = 0; i < n; i++) if (v[i] & 1) odd.pb(i);
	odd.pb(n);
	vl suf(odd.size() + 2);
	for (int i = odd.size() - 2; i >= 0; i--) {
		suf[i] = odd[i + 1] - odd[i];
		if (i + 2 < odd.size()) suf[i] += suf[i + 2];
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll sum = 0, c = 0, mx = 0;
		for (int j = i; j < i + 200 and j < n; j++) {
			sum += v[j];
			c += (v[j] & 1);
			mx = max(mx, v[j]);
			if (mx <= sum - mx and sum % 2 == 0) ans++;
		}
		if (i + 200 < n) {
			auto it = lower_bound(all(odd), i + 200) - odd.begin();
			if (c & 1) ans += suf[it];
			else ans += n - i - 200 - suf[it];
		}
	}
	cout << ans << endl;
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
