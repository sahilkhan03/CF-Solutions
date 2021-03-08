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
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

struct pair_hash {
	size_t operator()(const pair<int, int>&x)const {
		return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
	}
};
void solve() {
	ll n, ck;
	cin >> n >> ck;
	vector<string> s(n);
	cin >> s;
	string ans;
	vector<unordered_map<pl, ll, pair_hash>> v(26);
	char c = 'a';
	if (ck > 0) {
		if (s[0][0] == 'a') v[0][ {0, 0}] = ck;
		else v[0][ {0, 0}] = ck - 1;
	} else {
		c = s[0][0];
		v[c - 'a'][ {0 , 0}] = ck;
	}
	for (int tm = 0; tm < 2 * n - 1; tm++) {
		ans += c;
		// debug(tm, c);
		auto cur = v[c - 'a'];
		for (int i = 0; i < 26; i++) v[i].clear();
		for (auto& [p, k] : cur) {
			auto& [i, j] = p;
			if (i + 1 < n) {
				if (k > 0) v[0][ {i + 1, j}] = max(v[0][ {i + 1, j}], k - (s[i + 1][j] != 'a'));
				else v[s[i + 1][j] - 'a'][ {i + 1, j}] = max(v[s[i + 1][j] - 'a'][ {i + 1, j}], 0ll);
			}
			if (j + 1 < n) {
				if (k > 0) v[0][ {i, j + 1}] = max(v[0][ {i, j + 1}], k - (s[i][j + 1] != 'a'));
				else v[s[i][j + 1] - 'a'][ {i, j + 1}] = max(v[s[i][j + 1] - 'a'][ {i, j + 1}], 0ll);
			}
		}
		for (int i = 0; i < 26; i++) {
			if (!v[i].empty()) {
				c = char(i + 'a');
				break;
			}
		}
	}
	cout << ans << endl;
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
