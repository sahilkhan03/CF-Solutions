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
	vector<string> s(10);
	cin >> s;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ll c = 0;

			if (j + 4 < 10)
				for (int k = j; k < 10 and k - j < 5; k++) {
					c += (s[i][k] == 'X');
					c += (s[i][k] == 'O') * (-1e9);
				}
			if (c == 4) {
				cout << "YES" << endl;
				return;
			}
		}
	}
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 10; i++) {
			ll c = 0;

			if (i + 4 < 10)
				for (int k = i; k < 10 and k - i < 5; k++) {
					c += (s[k][j] == 'X');

					c += (s[k][j] == 'O') * (-1e9);
				}
			if (c == 4) {
				cout << "YES" << endl;
				return;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ll c = 0;

			if (i + 4 < 10 and j + 4 < 10)
				for (int k = 0; k < 5 and i + k < 10 and j + k < 10; k++) {
					c += (s[i + k][j + k] == 'X');

					c += (s[i + k][j + k] == 'O') * (-1e9);
				}
			if (c == 4) {
				cout << "YES" << endl;
				return;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ll c = 0;
			if (i + 4 < 10 and j  - 4 >= 0)
				for (int k = 0; k < 5 and i + k < 10 and j - k >= 0; k++) {
					c += (s[i + k][j - k] == 'X');
					c += (s[i + k][j - k] == 'O') * (-1e9);
				}
			if (c == 4) {
				cout << "YES" << endl;
				return;
			}
		}
	}
	cout << "NO" << endl;
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
