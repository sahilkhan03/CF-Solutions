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

pl calc(vl v) {
	pl ans = {0, 0};
	ll c1 = (v[3] - v[1] + 2) / 2, c2 = v[3] - v[1] + 1 - c1;
	ans.F = (c1 + c2) * ((v[2] - v[0] + 1) / 2) + c1 * ((v[2] - v[0] + 1) & 1);
	ans.S = (v[2] - v[0] + 1) * (v[3] - v[1] + 1) - ans.F;
	if ((v[0] + v[1]) % 2) swap(ans.F, ans.S);
	return ans;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vl rec1(4), rec2(4);
	cin >> rec1 >> rec2;
	pl ans = calc(vl({1, 1, n, m}));
	pl c1 = calc(rec2);
	ans.F -= c1.F; ans.S -= c1.S;
	c1 = calc(rec1);
	ans.F -= c1.F; ans.S -= c1.S;
	ans.F += (rec1[2] - rec1[0] + 1) * (rec1[3] - rec1[1] + 1);
	ans.S += (rec2[2] - rec2[0] + 1) * (rec2[3] - rec2[1] + 1);
	// debug(ans);
	if (!(rec1[0] > rec2[2] or rec1[2] < rec2[0] or rec1[1] > rec2[3] or rec1[3] < rec2[1])) {
		ans.F -= (min(rec1[2], rec2[2]) - max(rec1[0], rec2[0]) + 1) *
		         (min(rec1[3], rec2[3]) - max(rec2[1], rec1[1]) + 1);
		c1 = calc(vl({max(rec1[0], rec2[0]), max(rec2[1], rec1[1]),
		              min(rec1[2], rec2[2]), min(rec1[3], rec2[3])
		             }));
		ans.F += c1.F; ans.S += c1.S;
	}
	cout << ans << endl;
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
