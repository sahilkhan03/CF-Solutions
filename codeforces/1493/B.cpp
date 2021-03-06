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
	ll h, m;
	cin >> h >> m;
	string s;
	cin >> s;
	string t = s;
	vi inv = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
	while (true) {
		if (inv[t[0] - '0'] != -1 and inv[t[1] - '0'] != -1
		        and inv[t[4] - '0'] != -1 and inv[t[3] - '0'] != -1) {
			int ch = inv[t[4] - '0'] * 10 + inv[t[3] - '0'];
			int cm = inv[t[1] - '0'] * 10 + inv[t[0] - '0'];
			if (ch < h and cm < m) {
				cout << t << endl;
				return;
			}
		}
		int hh = 0;
		if ((t[3] - '0') * 10 + t[4] - '0'  == m - 1) {
			hh = 1;
			t[3] = t[4] = '0';
		}
		else {
			int c = 0;
			if (t[4] == '9') t[4] = '0', c = 1;
			else t[4]++;
			t[3] += c;
		}
		if (hh) {
			if ((t[0] - '0') * 10 + t[1] - '0' == h - 1) t[0] = t[1] = '0';
			else {
				int c = 0;
				if (t[1] == '9') t[1] = '0', c = 1;
				else t[1]++;
				t[0] += c;
			}
		}
		if (t == s) break;
	}
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
