
// Problem : F1. Microtransactions (easy version)
// Contest : Codeforces - Codeforces Round #560 (Div. 3)
// URL : https://codeforces.com/contest/1165/problem/F1
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	“Whether you think you can, or you think you can’t – you’re right” - Henry Ford 
*/

#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")
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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

template <typename T, typename TT>
ostream &operator<<(ostream &os, const pair<T, TT> &t) {
    return os << t.first << " " << t.second;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &t) {
    for (auto &i : t) os << i << " ";
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &t : v) is >> t;
    return is;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, vector<pair<T1, T2>> &v) {
    for (pair<T1, T2> &t : v) is >> t.first >> t.second;
    return is;
}


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

const ll mod = 1e9 + 7;
vector<pl> item;
ll n, m;
vl v;
bool check(ll mid) {
	vl cnt = v; ll rem = 0;
	vl c(n, -1);
	for(auto x: item) {
		if(x.F > mid) continue;
		c[x.S - 1] = max(c[x.S - 1], x.F);
	}
	vector<vl> last(2e5 + 5);
	for(int i = 0; i < n; i++) 
		if(c[i] != -1) last[c[i]].pb(i);
	for(ll i = 1; i <= mid; i++) {
		rem++;
		if(i > 2e5) continue;
		for(auto x: last[i]) {
			if(!rem) break;
			if(cnt[x] >= rem) {
				cnt[x] -= rem;
				rem = 0;	
				break;
			}
			else {
				rem -= cnt[x];
				cnt[x] = 0;	
			}
		}
	}
	return accumulate(all(cnt), 0) * 2 <= rem;
}

int main()
{
	fast;
   cin >> n >> m;
	v.resize(n); item.resize(m);
	cin >> v >> item;
	ll lo = 0, hi = 4e5, ans = hi, mid;
	while(lo <= hi) {
		mid = lo + (hi - lo) /2;
		if(check(mid)) ans = mid, hi = mid - 1;
		else lo = mid + 1; 
	}
	cout << ans << endl;
	return 0;
}
