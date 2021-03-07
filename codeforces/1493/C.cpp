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
	ll n, k;
	cin >> n >> k;
	string s; cin >> s;
	vl cnt(26);
	for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
	bool f = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % k) f = 1;
	}
	if (!f) {
		cout << s << endl;
		return;
	}
	for (ll i = n - 1, sp = 1; i >= 0; i--, sp++) {
		ll req = 0;
		cnt[s[i] - 'a']--;
		for (int j = 0; j <= s[i] - 'a'; j++) req += (k - (cnt[j] % k)) % k;
		if (req >= sp) continue;
		ll req1 = 0;
		for (int j = s[i] - 'a' + 1; j < 26; j++) {
			req1 += (k - (cnt[j] % k)) % k;
		}
		if (req + req1 > sp or (sp - (req + req1)) % k) continue;
		if (s[i] == 'z') continue;
		cout << s.substr(0, i);
		ll len = i;
		string ans = "";
		for (int j = 0; j <= s[i] - 'a'; j++) {
			ll x = (k - (cnt[j] % k)) % k;
			while (x--) ans += char('a' + j), len++;
		}
		bool ff = 0;
		for (int j = s[i] - 'a' + 1; j < 26; j++) {
			ll x = (k - (cnt[j] % k)) % k;
			if (!ff) {
				if (!x and (sp - req - req1) > 0) {
					cout << char('a' + j);
					ff = 1; len++;
					x = k - 1;
				}
				else if (x > 0) {
					cout << char('a' + j);
					ff = 1; len++;
					x--;
				}
			}
			while (x--) ans += char('a' + j), len++;
		}
		while (len < n) {
			cout << 'a';
			len++;
		}
		cout << ans << endl;
		return;
	}
	cout << -1 << endl;
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
