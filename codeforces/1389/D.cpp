
// Problem : D. Segment Intersections
// Contest : Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1389/problem/D
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

const ll mod = 1e9 + 7;
ll n, k;
pl a, b;

int main()
{
	fast;
   ll t;
   cin >> t;
   while(t--) {
   	cin >> n >> k >> a.F >> a.S >> b.F >> b.S;
   	if(a.S > b.S) swap(a, b);
   	if(a == b) {
   		ll s = (a.S - a.F)*n;
   		cout << max(0ll, k - s) * 2 << endl;
   		continue;
   	}
   	if(a.F <= b.F and b.F <= a.S) {
   		ll s = (a.S - b.F) * n;
   		if(s >= k) cout << 0 << endl;
   		else {
   			ll c = b.S - a.S + b.F - a.F;
   			if((b.S - a.F)*n >= k) 
   				cout << k - s << endl;
   			else 
   				cout << c*n + (k - (b.S - a.F)*n)*2 << endl;
   		}
   		continue;
   	}
   	if(b.F <= a.F) {
   		ll s = (a.S - a.F)*n;
   		if(s >= k) cout << 0 << endl;
   		else {
   			ll c = b.S - a.S + a.F - b.F;
   			if((b.S - b.F)*n >= k) 
   				cout << k - s << endl;
   			else 
   				cout << c*n + (k - (b.S - b.F)*n)*2 << endl;
   		}
   		continue;
   	}
   	ll d = b.F - a.S, len = b.S - a.F, cur = 0, ans = 1e18;
   	debug(d, len);
   	for(int i = 0; i < n; i++) {
   		cur += d;
   		if(len >= k) {
   			ans = min(ans, cur + k);
   			break;
   		}
   		cur += len;
   		k -= len;
   		ans = min(ans, cur + 2* k);
   	}
   	cout << ans << endl;	
   }

	return 0;
}
