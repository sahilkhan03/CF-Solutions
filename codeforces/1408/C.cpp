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
vl v;
ll n, l;

long double calcx(long double mid) {
	long double cur = 0, sp = 1, i = 1, dis = 0;
	while (i < v.size() and cur + (v[i] - v[i - 1]) / sp < mid) {
		dis = v[i];
		cur += (v[i] - v[i - 1]) / sp;
		sp++; i++;
	}
	dis += (mid - cur) * sp;
	return dis;
}

long double calcy(long double mid) {
	long double sp = 1, i = v.size() - 2, dis = l, cur = 0;
	while (i >= 0 and cur + (v[i + 1] - v[i]) / sp < mid) {
		dis = v[i];
		cur += (v[i + 1] - v[i]) / sp;
		sp++; i--;
	}
	dis -= (mid - cur) * sp;
	return dis;
}

void solve() {
	cin >> n >> l;
	v = vl(n + 1);
	v[0] = 0;
	for (int i = 1; i < n + 1; i++) cin >> v[i];
	v.pb(l);
	long double ans = 0, lo = 0, hi = l, mid;
	while (true) {
		mid = lo + (hi - lo) / 2;
		long double x = calcx(mid), y = calcy(mid);
		if (abs(x - y) < 1e-8) {
			ans = mid;
			break;
		}
		if (x > y) hi = mid;
		else lo = mid;
	}
	printf("%.10Lf\n", ans);
}

int main()
{
	ll T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
