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
vl v(4);
vector<string> ans;
void inc(int i) {
	string res = "+";
	res += char(i + 1 + '0');
	ans.pb(res);
	v[i]++, v[(i + 1) % 4]++;
}

void div(int i) {
	string res = "/";
	res += char(i + 1 + '0');
	ans.pb(res);
	v[i] /= 2, v[(i + 1) % 4] /= 2;
}

void solve() {
	cin >> v;
	while (v[0] > 1) {
		if (v[0] & 1) inc(0);
		if (v[1] & 1) inc(1);
		div(0);
	}
	while (v[1] > 1) {
		if (v[1] & 1) inc(1);
		if (v[2] & 1) inc(2);
		div(1);
	}
	while (v[2] != 1 and v[3] != 1) {
		if ((v[3] & 1) == (v[2] & 1)) {
			if (v[3] & 1) inc(2);
			div(2);
		}
		else if (v[2] & 1) inc(1), div(1);
		else inc(3), div(3);
	}
	int i = max_element(all(v)) - v.begin();
	while (v[i] > 1 and ans.size() < 1000) {
		if ((v[i] & 1) == (v[(i + 3) % 4] & 1)) {
			if (v[i] & 1) inc((i + 3) % 4);
			div((i + 3) % 4);
		}
		else if ((v[i] & 1) == (v[(i + 1) % 4] & 1)) {
			if (v[i] & 1) inc(i);
			div(i);
		}
		else inc((i + 3) % 4), inc(i);
		i = max_element(all(v)) - v.begin();
	}
	if (ans.size() > 1000) cout << -1 << endl;
	else {
		for (auto x : ans) cout << x << endl;
	}
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
