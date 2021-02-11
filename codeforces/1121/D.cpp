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
map<ll, ll> req;
map<ll, ll> cur;
vl v;
ll len, c, m, k, n, s;
void calc(int l, int r) {
	int use = 0;
	vl ans;
	for (int i = l; i < r; i++) {
		if (use < len - k) {
			if (req.find(v[i]) == req.end()) {
				ans.pb(i + 1); use++;
			}
			else if (req[v[i]] < cur[v[i]]) {
				cur[v[i]]--;
				ans.pb(i + 1); use++;
			}
		}
	}
	cout << use << endl << ans << endl;
}

void solve() {
	cin >> m >> k >> n >> s;
	v = vl(m); cin >> v;
	for (int i = 0; i < s; i++) {
		int x; cin >> x;
		req[x]++;
	}
	c = 0, len = k + m - n  * k;
	for (int i = 0; i < len; i++) {
		if (req.find(v[i]) != req.end()) {
			cur[v[i]]++;
			if (cur[v[i]] == req[v[i]]) c++;
		}
	}
	if (c >= req.size()) {
		calc(0, len);
		return;
	}
	for (int i = len; i < m; i++) {
		if (req.find(v[i]) != req.end()) {
			cur[v[i]]++;
			if (cur[v[i]] == req[v[i]]) c++;
		}
		if (req.find(v[i - len]) != req.end()) {
			cur[v[i - len]]--;
			if (cur[v[i - len]] == req[v[i - len]] - 1) c--;
		}
		if ((i + 1 - len) % k == 0 and c >= req.size()) {
			calc(i - len + 1, i + 1);
			return;
		}
	}
	cout << -1 << endl;
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
