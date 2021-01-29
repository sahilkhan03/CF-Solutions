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
	ll a, b, m;
	cin >> a >> b >> m;
	vl v = {a};
	ll sum = a;
	while (v.back() < b) {
		if (sum + 1 > b) break;
		v.pb(sum + 1);
		sum += sum + 1;
	}
	ll k = v.size(), i = 1, use = 0;
	vl cnt(k, m - 1);
	while (i < k) {
		use = 0;
		for (ll st = cnt[i]; st; st /= 2) {
			while (use + st <= cnt[i] and (use + st) * (1ll << max(0ll, k - i - 2)) + v.back() <= b and log10(use + st) + log10((1ll << max(0ll, k - i - 2))) < 18) use += st;
		}
		v[i] += use; cnt[i] -= use;
		for (ll j = i + 1, pw = 1; j < k; j++, pw *= 2) v[j] += pw * use;
		i++;
	}
	if (v.back() != b) cout << -1 << endl;
	else cout << k << " " << v << endl;
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
