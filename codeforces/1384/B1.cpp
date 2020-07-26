
// Problem : B1. Koa and the Beach (Easy Version)
// Contest : Codeforces - Codeforces Round #659 (Div. 2)
// URL : https://codeforces.com/contest/1384/problem/B1
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--) {
    	 ll n, k, l;
    	 cin >> n >> k >> l;
    	 vl v(n);
    	 cin >> v;
    	 for(auto& x: v) x = l - x;
    	 if(*min_element(all(v)) < 0) {
    	 	cout << "No" << endl;
    	 	continue;
    	 }
    	 bool sd = (v[0] == 0);
    	 ll c = v[0];
    	 debug(v);
    	 for(int i = 1; i < n; i++) {
    	 		if(v[i] >= k) {
    	 			sd = 0, c = k;
    	 			continue;
    	 		} 
    	 		if(sd) {
    	 			c++;
    	 			if(c > v[i]) {
    	 				cout << "No" << endl;
    	 				goto skip;
    	 			} 
    	 		}
    	 		else {
    	 			if(v[i] < c) c = v[i];
    	 			else c--;
    	 			if(!c) sd = 1;	
    	 		}
    	 		debug(v[i], c, sd);
    	 }
    	 cout << "Yes" << endl;
    	 skip:;
    }

    return 0;
}
