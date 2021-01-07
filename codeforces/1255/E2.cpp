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
ll n;
ll calc(vl v, ll g) {
	for (int i = 0; i < n; i++) v[i] %= g;
	ll i = 0, ans = 0;
	while (i < n) {
		ll j = i, cur = 0, med = n;
		while (j < n and v[j] + cur <= g) {
			cur += v[j++];
			if (cur >= (g + 1) / 2) med = min(med, j - 1);
		}
		med = min(med, j);
		for (ll k = i, s = 0; k <= j; k++) {
			ll used = min(v[k], g - s);
			s += used;
			ans += abs(k - med) * used;
			v[k] -= used;
		}
		i = j;
	}
	return ans;
}

void solve() {
	cin >> n;
	vl v(n); ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	if (sum == 1) {
		cout << -1 << endl;
		return;
	}
	v.pb(0);
	ll ans = 1e18;
	for (ll i = 2; i * i <= sum; i++) {
		if (sum % i == 0) {
			ans = min(ans, calc(v, i));
			while (sum % i == 0) sum /= i;
		}
	}
	if (sum > 1) ans = min(ans, calc(v, sum));
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
