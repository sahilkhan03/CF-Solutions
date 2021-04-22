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
	int n; cin >> n;
	vector<string> v(3);
	cin >> v;
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			ll a = count(all(v[i]), '0'), b = count(all(v[j]), '0');
			if (a >= n and b >= n) {
				debug(1, i, j);
				string p, q;
				if (a > b) p = v[i], q = v[j];
				else p = v[j], q = v[i];
				int l = 0, c1 = 0;
				for (int k = 0, c = 0; k < 2 * n; k++) {
					if (q[k] == '0') {
						c++;
						continue;
					}
					while (l < 2 * n and c1 < c) {
						cout << p[l];
						if (p[l] == '0') c1++;
						l++;
					}
					cout << q[k];
				}
				while (l < 2 * n) cout << p[l++];
				cout << endl;
				return;
			} else if (2 * n - a >= n and 2 * n - b >= n) {
				string p, q;
				if (2 * n - a > 2 * n - b) p = v[i], q = v[j];
				else p = v[j], q = v[i];
				int l = 0, c1 = 0;
				for (int k = 0, c = 0; k < 2 * n; k++) {
					if (q[k] == '1') {
						c++;
						continue;
					}
					while (l < 2 * n and c1 < c) {
						cout << p[l];
						if (p[l] == '1') c1++;
						l++;
					}
					cout << q[k];
				}
				while (l < 2 * n) cout << p[l++];
				cout << endl;
				return;
			}
		}
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
