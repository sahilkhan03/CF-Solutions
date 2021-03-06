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
	string s; cin >> s;
	ll  n = s.size();
	set<ll> ans;
	for (int i = 4; i < n; i++) {
		if (s[i - 4] == 't' and s[i - 3] == 'w' and s[i - 2] == 'o' and s[i - 1] == 'n' and s[i] == 'e') ans.insert(i - 1);
	}
	for (int i = 2; i < n; i++) {
		if (s[i - 2] == 't' and s[i - 1] == 'w' and s[i] == 'o') {
			if (ans.find(i + 1) == ans.end()) ans.insert(i);
		}
		else if (s[i - 2] == 'o' and s[i - 1] == 'n' and s[i] == 'e') {
			if (ans.find(i - 1) == ans.end()) ans.insert(i);
		}
	}
	cout << ans.size() << endl;
	cout << vl(all(ans)) << endl;
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
