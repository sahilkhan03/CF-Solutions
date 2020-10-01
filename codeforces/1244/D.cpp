/*
	"Work until your Idols become your Rivals"
*/

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

ll calc(vector<vl> &cost, vl &lst, vl &pos) {
	ll res = 0;
	for (int i = 0; i < lst.size(); i++) {
		res += cost[pos[i % 3]][lst[i]];
	}
	return res;
}

void solve() {
	ll n; cin >> n;
	vector<vl> v(n), cost(3, vl(n));
	cin >> cost;
	for (int i = 0; i < n - 1; i++) {
		ll a, b;
		cin >> a >> b;
		v[a - 1].pb(b - 1);
		v[b - 1].pb(a - 1);
	}
	ll root = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].size() > 2) {
			cout << -1 << endl;
			return;
		}
		if (v[i].size() == 1) root = i;
	}
	ll p = -1, cur = root;
	vl lst;
	while (true) {
		lst.pb(cur);
		if (v[cur][0] != p) {
			p = cur;
			cur = v[cur][0];
		}
		else if (v[cur].size() == 2) {
			p = cur;
			cur = v[cur][1];
		}
		else break;
	}
	vl pos = {0, 1, 2};
	vector<vl> ps;
	do {
		ps.pb(pos);
	} while (next_permutation(all(pos)));
	ll mn = 1e18, id = -1;
	for (int i = 0; i < ps.size(); i++) {
		ll x = calc(cost, lst, ps[i]);
		if (x < mn) mn = x, id = i;
	}
	cout << mn << endl;
	vl ans(n);
	for (int i = 0; i < n; i++) {
		ans[lst[i]] = ps[id][i % 3] + 1;
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
