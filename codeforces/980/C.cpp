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
	ll n, k;
	cin >> n >> k;
	vl v(n); cin >> v;
	vl col(256, -1), cnt(256);
	for (int i = 0; i < n; i++) {
		if (col[v[i]] == -1) {
			int j = v[i];
			while (j >=  max(0ll, v[i] - k + 1) and col[j] == -1) j--;
			if (j <  max(0ll, v[i] - k + 1)) {
				for (int l = j + 1; l <= v[i]; l++)
					cnt[j + 1]++, col[l] = j + 1;
			} else {
				if (cnt[col[j]] + v[i] - j <= k) {
					for (int l = j + 1; l <= v[i]; l++)
						cnt[col[j]]++, col[l] = col[j];
				} else {
					for (int l = j + 1; l <= v[i]; l++)
						cnt[j + 1]++, col[l] = j + 1;
				}
			}
		}
		v[i] = col[v[i]];
	}
	cout << v << endl;
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
