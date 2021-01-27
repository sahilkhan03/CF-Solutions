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
	int n; cin >> n;
	vector<pl> v(n); cin >> v;
	map<pl, set<pl>> m;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int num = v[j].S - v[i].S;
			int den = v[j].F - v[i].F;
			if (den == 0) num = 1;
			else if (num == 0) den = 1;
			else {
				if (den < 0) den = -den, num = -num;
				int g = __gcd(abs(den), abs(num));
				den /= g, num /= g;
			}
			int cnm = v[i].S * den - num * v[i].F, cden = den;
			if (den == 0) cnm = v[i].F, cden = 1;
			else if (num == 0) cnm = v[i].S, cden = 1;
			else {
				int g = __gcd(cden, cnm);
				cnm /= g, cden /= g;
			}
			m[ {num, den}].insert({cnm, cden});
		}
	}
	ll ans = 0, tot = 0;
	for (auto& x : m) tot += x.S.size();
	for (auto& x : m) ans += x.S.size() * 1ll * (tot - x.S.size());
	cout << ans / 2 << endl;
}

int main()
{
	fast;
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
