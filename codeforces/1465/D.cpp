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

void solve() {
	string s; cin >> s;
	ll a, b, n = s.size();
	cin >> a >> b;
	ll ans = 0, c0 = 0, c1 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') ans += c0 * a, c1++;
		else ans += c1 * b, c0++;
	}
	ll nc0 = 0, nc1 = 0, cur = ans;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			nc1++, c1--;
		}
		else if (s[i] == '0') {
			nc0++, c0--;
		}
		else {
			cur -= nc1 * b + c1 * a;
			nc1++, c0--;
			cur += nc0 * a + c0 * b;
		}
		ans = min(ans, cur);
	}
	c0 = nc0, c1 = nc1;
	nc0 = 0, nc1 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			nc1++, c1--;
		}
		else if (s[i] == '0') {
			nc0++, c0--;
		}
		else {
			cur -= nc0 * a + c0 * b;
			nc0++, c1--;
			cur += nc1 * b + c1 * a;
		}
		ans = min(ans, cur);
	}
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
