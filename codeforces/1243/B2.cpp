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
	ll n; cin >> n;
	string s, t;
	cin >> s >> t;
	set<ll> st;
	vector<pl> ans;
	for (int i = 0; i < n; i++)
		st.insert(i);
	for (char c = 'a'; c <= 'z'; c++) {
		vector<vl> pos(2, vl());
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == c) pos[0].pb(i);
			if (t[i] == c) pos[1].pb(i);
		}
		if ((pos[0].size() + pos[1].size()) % 2 == 1) {
			cout << "No" << endl;
			return;
		}
		while (!pos[0].empty() and !pos[1].empty()) {
			ll idx = *st.begin();
			if (t[idx] == c) {
				ans.pb({idx + 1, pos[1].back() + 1});
				swap(s[idx], t[pos[1].back()]);
				ans.pb({pos[0].back() + 1, idx + 1});
				swap(s[pos[0].back()], t[idx]);
			}
			else {
				ans.pb({pos[0].back() + 1, idx + 1});
				swap(s[pos[0].back()], t[idx]);
				ans.pb({idx + 1, pos[1].back() + 1});
				swap(s[idx], t[pos[1].back()]);
			}
			pos[0].pop_back();
			pos[1].pop_back();
			st.erase(st.begin());
		}
		int id = pos[0].empty();
		int i = 0, j = (pos[id].empty() ? 0 : pos[id].size()) - 1;
		while (i < j) {
			if (id) swap(s[pos[id][j]], t[pos[id][i]]), ans.pb({pos[id][j] + 1, pos[id][i] + 1});
			else swap(s[pos[id][i]], t[pos[id][j]]), ans.pb({pos[id][i] + 1, pos[id][j] + 1});
			st.erase(st.find(pos[id][j]));
			i++, j--;
		}
	}
	cout << "Yes" << endl;
	cout << ans.size() << endl;
	for (auto x : ans) cout << x << endl;
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
