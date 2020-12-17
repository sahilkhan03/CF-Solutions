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
ll n, q;
vl v, pre;

set<ll> s;
void calc(ll l, ll r) {
	s.insert(pre[r] - pre[l - 1]);
	debug(l, r, v[l - 1], v[r - 1]);
	if (v[l - 1] == v[r - 1]) return;
	ll mid = upper_bound(v.begin() + l - 1, v.begin() + r, (v[l - 1] + v[r - 1]) / 2) - v.begin();
	calc(l, mid);
	calc(mid + 1, r);
}

void solve() {
	cin >> n >> q;
	v = vl(n), pre = vl(n + 1);
	cin >> v;
	s.clear(); sort(all(v));
	for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + v[i];
	calc(1, n);
	while (q--) {
		ll x; cin >> x;
		if (s.find(x) != s.end()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
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
