
// Problem : F. Elongated Matrix
// Contest : Codeforces - Codeforces Round #531 (Div. 3)
// URL : https://codeforces.com/contest/1102/problem/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	“Whether you think you can, or you think you can’t – you’re right” - Henry Ford 
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

vector<vi> cons, dif;

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vi> v(n, vi(m));
	cin >> v;
	cons.resize(n, vi(n)); 
	dif.resize(n, vi(n));
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			dif[i][j] = dif[j][i] = cons[i][j] = cons[j][i] = 1e9;
			if(j != i) {
				for(int l = 0; l < m; l++) 
					cons[i][j] = min(cons[i][j], abs(v[i][l] - v[j][l]));
			}
			cons[j][i] = cons[i][j];
			for(int l = 0; l < m - 1; l++) 
				dif[i][j] = min(dif[i][j], abs(v[j][l] - v[i][l + 1])),
				dif[j][i] = min(dif[j][i], abs(v[i][l] - v[j][l + 1]));
		}
	}
	if(n == 1) {
		cout << dif[0][0] << endl;
		return; 
	}
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(1<<n, -1)));
	for(int i = 0; i < n; i++) dp[i][i][1 << i] = mod;
	for(int mask = 1; mask < (1 << n) - 1; mask++) {
		for(int l = 0; l < n; l++) {
			if(!(mask & (1<<l))) {
				int state = (mask | (1 << l));
				for(int st = 0; st < n; st++) {
					if((mask & (1 << st))) {
						for(int pre = 0; pre < n; pre++) {
							if((mask & (1 << pre)) and !(__builtin_popcount(mask) > 1 and (st==pre))) {
								int cur = min(cons[l][pre], dp[st][pre][mask]);
								if(state == (1 << n) - 1) {
									cur = min(cur, dif[st][l]); 
								}
								dp[st][l][state] = max(dp[st][l][state], cur); 
								// debug(st,l,pre,mask,state,cur);
							}
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i != j) ans = max(ans, dp[i][j][(1<<n) - 1]);
		}
	}
	cout << ans << endl;
}

int main()
{
	fast;
   ll t = 1;
   // cin >> t;
   while(t--) {
   	solve();
   }
	return 0;
}
