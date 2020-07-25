
// Problem : C. String Transformation 1
// Contest : Codeforces - Codeforces Round #659 (Div. 2)
// URL : https://codeforces.com/contest/1384/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
    ll t;
    cin >> t;
    while(t--) {
    	ll n;
    	cin >> n;
    	string a, b;
    	cin >> a >> b;
    	vector<vl> v(26);
    	ll ans = 0;
    	for(int i = 0; i < n; i++ ) {
    		if(a[i] > b[i]) {
    			cout << -1 << endl;
    			goto skip;
    		}
    		v[a[i] - 'a'].pb(b[i] - 'a');
    	}
    	for(int i = 0; i < 25; i++) {
    		sort(all(v[i]));
    		int j = -1, c = i + 1;
    		for(j = 0; j < v[i].size(); j++) {
    			if(v[i][j] > i) {
    				ans++;
    				c = v[i][j];
    				while(j < v[i].size() and v[i][j] == c) j++;
    				break;
    			}
    		}
    		while(j < v[i].size()) v[c].pb(v[i][j++]); 
		}
		cout << ans << endl;
    	skip:;
    }

    return 0;
}
