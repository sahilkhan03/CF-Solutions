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
	ll n, k;
	cin >> n >> k;
	priority_queue<pl> pq;
	vl v(n), cur(n, -1);
	cin >> v;
	if (n == 2 and abs(v[0] - v[1]) >= k) {
		cout << "NO" << endl;
		return;
	}
	cur[0] = v[0], cur[n - 1] = v[n - 1];
	for (int i = 1; i < n - 1; i++) {
		pq.push({v[i], i});
	}
	while (!pq.empty()) {
		auto [h, i] = pq.top();
		pq.pop();
		ll mx = max(cur[i - 1], cur[i + 1]);
		if (mx == -1) cur[i] = h;
		else if (h + 2 * k - 1 <= mx) {
			cout << "NO" << endl;
			return;
		}
		else cur[i] = max(h, mx - k + 1);
		debug(h, i, cur[i], mx);
		if (i == n - 2 and abs(cur[i] - cur[i + 1]) >= k) {
			cout << "NO" << endl;
			return;
		}
		if (i == 1 and abs(cur[i] - cur[i - 1]) >= k) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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
