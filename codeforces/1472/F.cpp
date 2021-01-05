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
	ll n, m;
	cin >> n >> m;
	vector<pl> v(m);
	cin >> v;
	sort(all(v), [&](const pl & a, const pl & b) -> bool {
		if (a.S == b.S) return a.F < b.F;
		return a.S < b.S;
	});
	int i = 0;
	while (i < m) {
		if (i + 1 >= m) {
			cout << "NO" << endl;
			return;
		}
		if (v[i].F == 1) {
			if (v[i + 1].F == 1) {
				if ((v[i + 1].S - v[i].S) % 2 == 0 or (i + 2 < m and v[i + 2] == pl({2, v[i + 1].S}))) {
					cout << "NO" << endl;
					return;
				}
			}
			else {
				if ((v[i + 1].S - v[i].S) % 2) {
					cout << "NO" << endl;
					return;
				}
			}
		}
		else {
			if (v[i + 1].F == 2) {
				if ((v[i + 1].S - v[i].S) % 2 == 0 or (i + 2 < m and v[i + 2] == pl({1, v[i + 1].S}))) {
					cout << "NO" << endl;
					return;
				}
			}
			else {
				if ((v[i + 1].S - v[i].S) % 2 or ((i + 2 < m and v[i + 2] == pl({2, v[i + 1].S})))) {
					cout << "NO" << endl;
					return;
				}
			}
		}
		i += 2;
	}
	cout << "YES" << endl;
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
