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

ll n, m, k, s;
vector<pl> d, p, cd, cp;
vl pred = {0};
vl prep = {0};

bool calc(ll days) {
	for (ll i = 0; i < pred.size(); i++) {
		ll rem = s - pred[i] * d[days].F;
		if (rem < 0) break;
		ll cnt = 0;
		for (ll st = 3e5; st; st /= 2) {
			while (cnt + st < prep.size() and prep[cnt + st] * p[days].F <= rem) cnt += st;
		}
		if (cnt + i >= k) return 1;
	}
	return 0;
}

void solve() {
	cin >> n >> m >> k >> s;
	d = p = vector<pl>(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i].F;
		d[i].S = i + 1;
		if (i) d[i] = min(d[i], d[i - 1]);
	}
	for (int i = 0; i < n; i++) {
		cin >> p[i].F;
		p[i].S = i + 1;
		if (i) p[i] = min(p[i], p[i - 1]);
	}
	for (int i = 0; i < m; i++) {
		ll tp, x;
		cin >> tp >> x;
		if (tp == 1) cd.pb({x, i + 1});
		else cp.pb({x, i + 1});
	}
	sort(all(cd));
	sort(all(cp));
	for (int i = 0; i < cd.size(); i++) pred.pb(pred.back() + cd[i].F);
	for (int i = 0; i < cp.size(); i++) prep.pb(prep.back() + cp[i].F);
	ll ans = n + 1;
	for (ll st = 3e5; st; st /= 2) {
		while (ans - st > 0 and calc(ans - st - 1)) ans -= st;
	}
	if (ans > n) {
		cout << -1 << endl;
		return;
	}
	cout << ans << endl;
	for (ll i = 0; i < pred.size(); i++) {
		ll rem = s - pred[i] * d[ans - 1].F;
		if (rem < 0) break;
		ll cnt = 0;
		for (ll st = 3e5; st; st /= 2) {
			while (cnt + st < prep.size() and prep[cnt + st] * p[ans - 1].F <= rem) cnt += st;
		}
		if (cnt + i >= k) {
			for (int l = 0; l < i and k; l++, k--) cout << cd[l].S << " " << d[ans - 1].S << endl;
			for (int l = 0; l < cnt and k; l++, k--) cout << cp[l].S << " " << p[ans - 1].S << endl;
		}
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
