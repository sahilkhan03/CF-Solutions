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

struct pair_hash {
	size_t operator()(const pair<int, int>&x)const {
		return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
	}
};

int dp[101][10001];

vl fact(105), inv(105);

ll mpow(ll n, ll p) {
	ll ans = 1;
	while (p) {
		if (p & 1) (ans *= n) %= mod;
		(n *= n) %= mod, p /= 2;
	}
	return ans;
}

ll ncr(ll n, ll r) {
	return ((fact[n] * inv[r]) % mod) * inv[n - r] % mod;
}

void solve() {
	int n, sum = 0; cin >> n;
	vi v(n); cin >> v;
	vi cnt(101);
	dp[0][0] = 1;
	int dist = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		cnt[v[i]]++;
		if (cnt[v[i]] == 1) dist++;
		for (int k = i; k >= 0; k--) {
			for (int j = sum - v[i]; j >= 0; j--) {
				(dp[k + 1][j + v[i]] += dp[k][j]) %= mod;
			}
		}
	}
	if (dist < 3) {
		cout << n << endl;
		return;
	}
	int ans = 1;
	for (int i = 1; i <= 100; i++) {
		for (int j = cnt[i]; j > ans; j--) {
			if (ncr(cnt[i], j) == dp[j][j * i]) ans = j;
		}
	}
	cout << ans << endl;
}

int main()
{
	fast;
	fact[0] = 1; inv[0] = 1;
	for (int i = 1; i < 105; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
		inv[i] = mpow(fact[i], mod - 2);
	}
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
