#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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


struct dsu {
public:
	dsu() : _n(0) {}
	dsu(int n) : _n(n), parent_or_size(n, -1) {}

	int merge(int a, int b) {
		assert(0 <= a && a < _n);
		assert(0 <= b && b < _n);
		int x = leader(a), y = leader(b);
		if (x == y) return x;
		if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
		parent_or_size[x] += parent_or_size[y];
		parent_or_size[y] = x;
		return x;
	}

	bool same(int a, int b) {
		assert(0 <= a && a < _n);
		assert(0 <= b && b < _n);
		return leader(a) == leader(b);
	}

	int leader(int a) {
		assert(0 <= a && a < _n);
		if (parent_or_size[a] < 0) return a;
		return parent_or_size[a] = leader(parent_or_size[a]);
	}

	int size(int a) {
		assert(0 <= a && a < _n);
		return -parent_or_size[leader(a)];
	}

	std::vector<std::vector<int>> groups() {
		std::vector<int> leader_buf(_n), group_size(_n);
		for (int i = 0; i < _n; i++) {
			leader_buf[i] = leader(i);
			group_size[leader_buf[i]]++;
		}
		std::vector<std::vector<int>> result(_n);
		for (int i = 0; i < _n; i++) {
			result[i].reserve(group_size[i]);
		}
		for (int i = 0; i < _n; i++) {
			result[leader_buf[i]].push_back(i);
		}
		result.erase(
		    std::remove_if(result.begin(), result.end(),
		[&](const std::vector<int>& v) { return v.empty(); }),
		result.end());
		return result;
	}

private:
	int _n;
	std::vector<int> parent_or_size;
};



const ll mod = 1e9 + 7;

void solve() {
	ll n; cin >> n;
	vl v(n); cin >> v;
	dsu d(n);
	vector<pl> ans;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ans.size() >= n - 1) break;
			if (v[i] != v[j]) {
				if (d.same(i, j)) continue;
				d.merge(i, j);
				ans.pb({i + 1, j + 1});
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!d.same(0, i) or ans.size() != n - 1) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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
