#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
inline ostream &operator<<(ostream &os, const set<T> &t) {
	for (auto i : t) os << i << " ";
	return os;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &t) {
	for (auto i : t) os << i.first << " : " << i.second << endl;
	return os;
}
template <typename T>
inline istream &operator>>(istream &is, vector<T> &v) {
	for (T &t : v) is >> t;
	return is;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &is, vector<pair<T1, T2>> &v) {
	for (pair<T1, T2> &t : v) is >> t.first >> t.second;
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

inline ll calc(ll l, ll p) {
	ll b = l / p, t = l % p;
	return b * b * (p - t) + (b + 1) * (b + 1) * t;
}

struct cmp
{
	bool operator()(const pl& a, const pl& b) {
		return calc(a.F, a.S) - calc(a.F, a.S + 1) < calc(b.F, b.S) - calc(b.F, b.S + 1);
	}
};

void solve() {
	ll n, k;
	cin >> n >> k;
	vl v(n); cin >> v;
	priority_queue<pl, vector<pl>, cmp> pq;
	for (auto x : v) pq.push({x, 1});
	for (int i = 0; i < k - n; i++) {
		auto tp = pq.top(); pq.pop();
		debug(tp);
		pq.push({tp.F, tp.S + 1});
	}
	ll ans = 0;
	while (!pq.empty()) {
		auto tp = pq.top(); pq.pop();
		ans += calc(tp.F, tp.S);
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
