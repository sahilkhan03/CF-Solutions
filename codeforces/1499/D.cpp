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

vi sieve(2e7 + 2);

void solve() {
	int c, d, x, ans = 0;
	scanf("%d %d %d", &c, &d, &x);
	auto calc = [&](int g) {
		int val = x / g + d;
		if (val % c) return 0;
		val /= c;
		return (1 << sieve[val]);
	};
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			ans += calc(i);
			if (i * i != x) ans += calc(x / i);
		}
	}
	printf("%d\n", ans);
}

int main()
{
	for (int i = 2; i < 2e7 + 2; i++) {
		if (!sieve[i]) {
			for (int j = i; j < 2e7 + 2; j += i)
				sieve[j]++;
		}
	}
	int T = 1;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
