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

ll n, k;
string s;

void solve() {
	cin >> n >> k >> s;
	ll mx = 0, cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'L') cnt++;
		else mx += cnt;
	}
	if (k > mx) {
		cout << -1 << endl;
		return;
	}
	vector<vl> tans;
	while (k > 0 and mx - k + 1 > 1) {
		vl ans;
		for (int i = 0; i < n - 1 and ans.size() < mx - k + 1; i++) {
			if (s[i] == 'R' and s[i + 1] == 'L') ans.pb(i + 1), swap(s[i], s[i + 1]), i++;
		}
		tans.pb(ans);
		mx -= ans.size();
		k--;
	}
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] == 'R') {
			ll j = i;
			while (j + 1 < n and s[j + 1] == 'L' and mx > 0 and k > 0) {
				tans.pb({j + 1});
				swap(s[j], s[j + 1]);
				j++; k--; mx--;
			}
		}
	}
	if (k or mx) cout << -1 << endl;
	else {
		for (auto& x : tans) cout << x.size() << " " << x << endl;
	}
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
