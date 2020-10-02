/*
	"Work until your Idols become your Rivals"
*/

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

string ans = "";
vl vis(26);
vector<vl> v(26);
bool f = 0;
void dfs(ll u) {
	if (f) return;
	vis[u] = 1;
	for (auto x : v[u]) {
		if (vis[x] == 1) {
			f = 1;
			return;
		}
		else if (!vis[x]) dfs(x);
	}
	vis[u] = 2;
	ans += char(u + 'a');
}

void solve() {
	ll n; cin >> n;
	vector<string> s(n);
	cin >> s;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = 0; k < min(s[i].size(), s[j].size()); k++) {
				if (s[i][k] == s[j][k]) continue;
				v[s[i][k] - 'a'].pb(s[j][k] - 'a');
				goto skip;
			}
			if (s[i].size() > s[j].size()) {
				cout << "Impossible" << endl;
				return;
			}
skip:;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (!vis[i]) dfs(i);
	}
	if (f) {
		cout << "Impossible" << endl;
		return;
	}
	reverse(all(ans));
	cout << ans << endl;
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
