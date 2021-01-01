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
	string s; cin >> s;
	set<ll> op, ed;
	vector<pl> ans;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') op.insert(i);
		else ed.insert(i);
	}
	int req = n / 2 - k + 1;
	for (int c = 0; c < req; c++) {
		if (s[c] != '(') {
			ans.pb({c + 1, *op.begin() + 1});
			swap(s[c], s[*op.begin()]);
			ed.erase(ed.begin());
			ed.insert(*op.begin());
		}
		op.erase(op.begin());
	}
	debug('1', ans);
	for (int c = req; c < 2 * req; c++) {
		if (s[c] != ')') {
			ans.pb({c + 1, *ed.begin() + 1});
			swap(s[c], s[*ed.begin()]);
			op.erase(op.begin());
			op.insert(*ed.begin());
		}
		ed.erase(ed.begin());
	}
	for (int c = 2 * req; c < n; c++) {
		if (c & 1) {
			if (s[c] != ')') {
				ans.pb({c + 1, *ed.begin() + 1});
				swap(s[c], s[*ed.begin()]);
				op.erase(op.begin());
				op.insert(*ed.begin());
			}
			ed.erase(ed.begin());
		}
		else {
			if (s[c] != '(') {
				ans.pb({c + 1, *op.begin() + 1});
				swap(s[c], s[*op.begin()]);
				ed.erase(ed.begin());
				ed.insert(*op.begin());
			}
			op.erase(op.begin());
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans) cout << x << endl;
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
