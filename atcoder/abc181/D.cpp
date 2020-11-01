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
	string s; cin >> s;
	map<ll, ll> m;
	if (s.size() == 1) {
		if ((s[0] - '0') % 8 == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
		return;
	}
	if (s.size() == 2) {
		ll n1 = (s[0] - '0') * 10 + s[1] - '0';
		ll n2 = (s[1] - '0') * 10 + s[0] - '0';
		if (n1 % 8 == 0 or n2 % 8 == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
		return;
	}
	for (auto x : s) m[x - '0']++;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				if ((i * 100 + j * 10 + k) % 8 == 0) {
					debug(i, j, k);
					if (m[i]) m[i]--;
					else continue;
					if (m[j]) m[j]--;
					else {
						m[i]++;
						continue;
					}
					if (m[k]) {
						cout << "Yes" << endl;
						return;
					}
					else m[j]++, m[i]++;
				}
			}
		}
	}
	cout << "No" << endl;
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
