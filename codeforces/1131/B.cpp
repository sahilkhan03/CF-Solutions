
// Problem : B. Draw!
// Contest : Codeforces - Codeforces Round #541 (Div. 2)
// URL : https://codeforces.com/contest/1131/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define F first
#define S second
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

int main()
{
    fast;
    ll n;
    cin >> n;
    vector<pl> v(n + 1);
    v[0] = {0, 0};
    for(int i = 1; i <= n; i++) {
    	cin >> v[i].F >> v[i].S;
    }
    ll ans = 1;
    for(int i = 1; i <= n; i++) {
    	if(v[i].F == v[i - 1].F and v[i].S == v[i - 1].S)
    		continue;
    	// if(v[i - 1].F <= v[i - 1].S) {
    		// if(v[i].F >= v[i - 1].S) ans++;
    		// ans += min(v[i].F, v[i].S) - v[i - 1].S;
    	// }
    	if(v[i - 1].F < v[i - 1].S and v[i].F >= v[i - 1].S) ans++;
    	if(v[i - 1].S < v[i - 1].F and v[i].S >= v[i - 1].F) ans++;
    	ans += max(0ll, min(v[i].F, v[i].S) - max(v[i - 1].F, v[i - 1].S));
    }
    cout << ans << endl;


    return 0;
}
