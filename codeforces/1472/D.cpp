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
	ll n; cin >> n;
	vl o, e;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		if (x & 1) o.pb(x);
		else e.pb(x);
	}
	sort(all(o));
	sort(all(e));
	ll a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			if (e.empty()) {
				b += o.back();
				o.pop_back();
			}
			else if (o.empty()) {
				e.pop_back();
			}
			else if (e.back() > o.back()) {
				e.pop_back();
			}
			else {
				b += o.back();
				o.pop_back();
			}
		}
		else {
			if (o.empty()) {
				a += e.back();
				e.pop_back();
			}
			else if (e.empty()) {
				o.pop_back();
			}
			else if (o.back() > e.back()) {
				o.pop_back();
			}
			else {
				a += e.back();
				e.pop_back();
			}
		}
	}
	if (a == b) cout << "Tie" << endl;
	else if (a > b) cout << "Alice" << endl;
	else cout << "Bob" << endl;
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
