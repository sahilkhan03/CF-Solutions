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
	map<char, char> m;
	m['A'] = 'A';
	m['b'] = 'd';
	m['d'] = 'b';
	m['H'] = 'H';
	m['I'] = 'I';
	m['M'] = 'M';
	m['O'] = 'O';
	m['o'] = 'o';
	m['p'] = 'q';
	m['q'] = 'p';
	m['T'] = 'T';
	m['U'] = 'U';
	m['V'] = 'V';
	m['v'] = 'v';
	m['W'] = 'W';
	m['w'] = 'w';
	m['X'] = 'X';
	m['x'] = 'x';
	m['Y'] = 'Y';
	string s; cin >> s;
	for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
		if (m.find(s[i]) == m.end() or m[s[i]] != s[j]) {
			cout << "NIE" << endl;
			return;
		}
	}
	if (s.size() % 2 )  {
		char c = s[s.size() / 2];
		if (m.find(c) == m.end() or c == 'b' or c == 'd' or c == 'q' or c == 'p') {
			cout << "NIE" << endl;
			return;
		}
	}
	cout << "TAK" << endl;
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
