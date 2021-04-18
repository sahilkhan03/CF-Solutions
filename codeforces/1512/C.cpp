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
	ll a, b;
	cin >> a >> b;
	ll n = a + b;
	string s; cin >> s;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] == '?' and s[n - i - 1] == '?') continue;
		if (s[i] == '?') {
			if (s[n - i - 1] == '0') a -= 2, s[i] = '0';
			else s[i] = '1', b -= 2;
		} else if (s[n - i - 1] == '?') {
			if (s[i] == '0') a -= 2, s[n - i - 1] = '0';
			else s[n - i - 1] = '1', b -= 2;
		}
		else if (s[i] != s[n - i - 1]) {
			cout << -1 << endl;
			return;
		}
		else if (s[i] == '0') a -= 2;
		else b -= 2;
		if (a < 0 or b < 0) {
			cout << -1 << endl;
			return;
		}
	}
	if (n & 1) {
		if (s[n / 2] == '0') {
			if (a) a--;
			else {
				cout << -1 << endl;
				return;
			}
		}
		else if (s[n / 2] == '1') {
			if (b)
				b--;
			else {
				cout << -1 << endl;
				return;
			}
		}
		else if (a & 1) a--, s[n / 2] = '0';
		else if (b & 1) b--, s[n / 2] = '1';
		else {
			cout << -1 << endl;
			return;
		}
	}
	for (int i = 0; i < n / 2; i++) {
		if (s[i] == '?') {
			if (a > 1) s[i] = s[n - i - 1] = '0', a -= 2;
			else if (b > 1) s[i] = s[n - i - 1] = '1', b -= 2;
			else {
				cout << -1 << endl;
				return;
			}
		}
	}
	cout << s << endl;
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
