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

ll calc(vl a, vl b) {
	if (b.empty() or a.empty()) return 0;
	vl suf(b.size() + 2);
	int j = a.size() - 1;
	for (int i = b.size() - 1; i >= 0; i--) {
		suf[i] = suf[i + 1];
		while (j >= 0 and a[j] > b[i]) j--;
		if (j >= 0) suf[i] += (a[j] == b[i]);
	}
	ll ans = suf[0];
	debug(a, b);
	j = 0;
	auto check = [&](ll e, ll i) {
		ll ex = upper_bound(all(a), e) - lower_bound(all(a), b[i]);
		ll len = e - b[i] + 1;
		return len - ex > j;
	};
	for (int i = 0; i < b.size(); i++) {
		while (j < a.size() and a[j] < b[i]) j++;
		ll ed = 1e18;
		for (ll st = 1e18; st; st /= 2) {
			while (ed - st >= b[i] and check(ed - st, i)) ed -= st;
		}
		auto it = lower_bound(all(b), ed) - b.begin();
		auto ext = lower_bound(all(b), ed) - b.begin() - i;
		debug(j, b[i], ed, suf[it], ext);
		ans = max(ans, suf[it] + ext);
	}
	return ans;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vl apos, aneg, bpos, bneg;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		if (x > 0) apos.pb(x);
		else aneg.pb(-x);
	}
	for (int i = 0; i < m; i++) {
		ll x; cin >> x;
		if (x > 0) bpos.pb(x);
		else bneg.pb(-x);
	}
	reverse(all(aneg));
	reverse(all(bneg));
	cout << calc(apos, bpos) + calc(aneg, bneg) << endl;
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
