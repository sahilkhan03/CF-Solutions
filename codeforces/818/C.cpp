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

void solve() {
	ll d; cin >> d;
	ll n, m; cin >> n >> m;
	vector<vl> v(d, vl(4));
	cin >> v;
	vl req(4); cin >> req;
	vl lf, rt, tp, bt;
	for (int i = 0; i < d; i++) {
		if (v[i][0] > v[i][2]) swap(v[i][0], v[i][2]);
		if (v[i][1] > v[i][3]) swap(v[i][1], v[i][3]);
		lf.pb(v[i][0]);
		rt.pb(v[i][2]);
		tp.pb(v[i][1]);
		bt.pb(v[i][3]);
	}
	debug(lf, tp, rt, bt);
	sort(all(lf));
	sort(all(tp));
	sort(all(rt));
	sort(all(bt));
	for (int i = 0; i < d; i++) {
		auto lc = lower_bound(all(lf), v[i][2]) - lf.begin() - (v[i][2] > v[i][0]);
		auto rc = rt.end() - upper_bound(all(rt), v[i][0]) - (v[i][0] < v[i][2]);
		auto tc = lower_bound(all(tp), v[i][3]) - tp.begin() - (v[i][1] < v[i][3]);
		auto bc = bt.end() - upper_bound(all(bt), v[i][1]) - (v[i][1] < v[i][3]);
		if (vl({lc, rc, tc, bc}) == req) {
			cout << i + 1 << endl;
			return;
		}
	}
	cout << -1 << endl;
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
