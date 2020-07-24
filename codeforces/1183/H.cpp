
// Problem : H. Subsequences (hard version)
// Contest : Codeforces - Codeforces Round #570 (Div. 3)
// URL : https://codeforces.com/contest/1183/problem/H
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

int main()
{
    fast;
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vl> last(26, vl(n, -1));
    last[s[0] - 'a'][0] = 0;
    for(int i = 1; i < n; i++) {
    	for(int j = 0; j < 26; j++) {
    		last[j][i] = last[j][i - 1];
    		if(j == s[i] - 'a') last[j][i] = i;
    	}
    }
    vector<vl> dp(n, vl(n + 1, 0));
    for(int i = 0; i < n; i++) dp[i][1] = 1;
    for(int i = 1; i < n; i++) {
    	for(int j = 1; j <= i + 1; j++) {
    		for(int k = 0; k < 26; k++) {
    			if(last[k][i - 1] != -1) {
    				dp[i][j] += dp[last[k][i - 1]][j - 1];
    				dp[i][j] = min(dp[i][j], ll(1e12));
    			}
    		}
    	}
    }
    debug(dp);
    ll ans = 0, cnt = 0;
    for(int i = n; i > 0; i--) {
    	for(int j = 0; j < 26; j++) {
    		if(last[j][n - 1] != -1) {
	    		if(cnt + dp[last[j][n - 1]][i] > k) {
	    			ans += (k - cnt)* (n - i);
	    			cnt = k;
	    			goto skip;
	    		}
	    		else {
	    			cnt += dp[last[j][n - 1]][i];
	    			ans += dp[last[j][n - 1]][i]*(n - i);
	    		}
    		}
    	}
    }
    skip:;
    if(cnt < k) cnt++, ans+= n;
    if(cnt < k) cout << -1 << endl;
    else cout << ans << endl;


    return 0;
}
