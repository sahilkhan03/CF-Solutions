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

const ll mod = 1e9 + 7;

struct Node
{
	Node *child[2];
	int cnt;
	Node() {
		cnt = 0;
		child[0] = child[1] = NULL;
	}
};

Node *root = new Node();

void insert(int num) {
	auto cur = root;
	for (int i = 30; i >= 0; i--) {
		int cbit = !!((1 << i) & num);
		if (cur->child[cbit] == NULL)
			cur->child[cbit] = new Node();
		cur = cur->child[cbit];
		cur->cnt++;
	}
}

void remove(int num) {
	auto cur = root;
	for (int i = 30; i >= 0; i--) {
		int cbit = !!((1 << i) & num);
		cur = cur->child[cbit];
		cur->cnt--;
	}
}

int query(Node *cur, int i, int p, int l) {
	if (i < 0 or cur == NULL) return 0;
	int pbit = !!((1 << i) & p), lbit = !!((1 << i) & l);
	int ans = 0;
	if (!lbit) ans += query(cur->child[pbit], i - 1, p, l);
	else {
		if (!pbit) {
			if (cur->child[0]) ans += cur->child[0]->cnt;
			ans += query(cur -> child[1], i - 1, p, l);
		}
		else {
			if (cur->child[1]) ans += cur->child[1]->cnt;
			ans += query(cur -> child[0], i - 1, p, l);
		}
	}
	return ans;
}

void solve() {
	ll q; cin >> q;
	while (q--) {
		ll op; cin >> op;
		if (op == 1) {
			ll x; cin >> x;
			insert(x);
		}
		else if (op == 2) {
			ll x; cin >> x;
			remove(x);
		}
		else {
			ll p, l;
			cin >> p >> l;
			cout << query(root, 30, p, l) << endl;
		}
	}
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
