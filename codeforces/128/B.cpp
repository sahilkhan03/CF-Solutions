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

void solve() {
	string s;
	cin >> s;
	ll k, n = s.size(); cin >> k;
	if (k > n * (n + 1) / 2) {
		cout << "No such line." << endl;
		return;
	}
	vl list;
	for (int i = 0; i < n; i++) list.pb(i);
	string ans;
	auto calc = [&]() {
		vl cnt(26), occ(26);
		vector<vl> nxt(26);
		for (auto x : list) {
			nxt[s[x] - 'a'].pb(x);
			cnt[s[x] - 'a'] += n - x - 1;
			occ[s[x] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (occ[i] >= k) {
				ans += char(i + 'a');
				k = 0;
				cout << ans << endl;
				return;
			}
			else k -= occ[i];
			if (cnt[i] >= k) {
				ans += char(i + 'a');
				list.clear();
				for (auto x : nxt[i]) if (x + 1 < n)
						list.pb(x + 1);
				return;
			}
			k -= cnt[i];
		}
	};
	while (k > 0) calc();
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
