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
ll n1, n2, n3, sum1, sum2, sum3;
vl v1, v2, v3;
ll calc(vl a, vl b, vl c) {
	ll p1 = a[0], p2 = b[0];
	for (int i = 0; i < c.size() - 1; i++) p1 -= c[i];
	for (int i = 1; i < b.size(); i++) p1 -= b[i];
	for (int i = 1; i < a.size(); i++) p2 -= a[i];
	ll ans1 = c.back() - p1 - p2;
	p1 -= b[0];
	ll ans2 = c.back() - p1;
	for (int i = 1; i < a.size(); i++) ans2 -= a[i];
	return max(ans1, ans2);
}

void solve() {
	cin >> n1 >> n2 >> n3;
	v1 = vl(n1), v2 = vl(n2), v3 = vl(n3);
	cin >> v1 >> v2 >> v3;
	sort(all(v1)); sort(all(v2));
	sort(all(v3));
	cout << max({calc(v1, v2, v3), calc(v1, v3, v2), calc(v2, v1, v3), calc(v2, v3, v1), calc(v3, v1, v2), calc(v3, v2, v1)}) << endl;
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
