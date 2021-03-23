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
	ll n;
	cin >> n;
	vl zero, pos, neg;
	vl v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] > 0) pos.pb(i + 1);
		else if (v[i] < 0) neg.pb(i + 1);
		else zero.pb(i + 1);
	}
	sort(all(neg), [&](ll a, ll b) -> bool {
		return v[a - 1] < v[b - 1];
	});
	if (!neg.empty() and neg.size() % 2) {
		zero.pb(neg.back());
		neg.pop_back();
		debug(zero);
	}
	ll c = 0;
	if (!zero.empty()) {
		ll sz = zero.size();
		while (sz > 1) {
			cout << 1 << " " << zero[sz - 1] << " " << zero[sz - 2] << endl;
			zero.pop_back();
			sz--; c++;
		}
		if (c < n - 1)
			cout << 2 << " " << zero[0] << endl;
	}
	if (!pos.empty()) {
		ll sz = pos.size();
		while (sz > 1) {
			cout << 1 << " " << pos[sz - 1] << " " << pos[sz - 2] << endl;
			pos.pop_back();
			sz--;
		}
	}
	if (!neg.empty()) {
		ll sz = neg.size();
		while (sz > 1) {
			cout << 1 << " " << neg[sz - 1] << " " << neg[sz - 2] << endl;
			neg.pop_back();
			sz--;
		}
	}
	if (!neg.empty() and !pos.empty())
		cout << 1 << " " << pos[0] << " " << neg[0] << endl;
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
