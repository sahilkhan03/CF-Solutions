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
	if (n == 1) {
		cout << v[0] - 1 << endl;
		return;
	}
	vl nxt(n + 1);
	nxt[n] = n;
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] == 1) nxt[i] = nxt[i + 1];
		else nxt[i] = i;
	}
	for (int i = 0; i < n; i++) {
		if (i == n - 1) ans += v[i] - 1, v[i] = 1;
		else if (v[i] > n - i - 1) ans += v[i] - (n - i - 1), v[i] = n - i - 1;
		debug(i, ans);
		while (v[i] > 1) {
			ans++;
			ll des = nxt[i + v[i]];
			while (des != n) {
				ll ndes = n;
				if (des + v[des] < n) ndes = nxt[des + v[des]];
				debug(des);
				v[des]--;
				if (v[des] == 1) {
					for (int j = des; j >= 0 and nxt[j] == des; j--)
						nxt[j] = nxt[des + 1];
				}
				des = ndes;
			}
			v[i]--;
			debug('\n');
		}
	}
	cout << ans << endl;
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
