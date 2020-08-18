
// Problem : B. Spreadsheets
// Contest : Codeforces - Codeforces Beta Round #1
// URL : https://codeforces.com/contest/1/problem/B
// Memory Limit : 64 MB
// Time Limit : 10000 ms
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

void solve() {
	string s;
	cin >> s;
	if(s.size() >= 4 and s[0] == 'R' and s[1] >= '0' and s[1] <= '9' and s.find('C', 1) != string::npos) {
		int i = 0, rn = 0;
		while(i < s.size() and s[i] != 'C') i++;
		string cn = s.substr(1, i - 1);
		for(i = i + 1; i < s.size(); i++) rn = rn*10 + (s[i] - '0');
		string pre = "";
		while(rn > 0) {
			int rem = rn % 26;
			if(rem == 0) pre += 'Z', rn -= 26;
			else pre += char(rem - 1 + 'A');
			rn /= 26;
		}		
		debug(pre, rn, cn);
		reverse(all(pre));
		cout << pre + cn << endl;
	}
	else {
		string pre = "", suf = "R";
		int i = 0;
		while(i < s.size() and !(s[i] >= '0' and s[i] <= '9')) pre += s[i++];
		while(i < s.size()) suf += s[i++];
		int num = 0;
		for(int i = 0; i <pre.size(); i++) num += (pre[i] - 'A' + 1)*powl(26, pre.size() - i - 1);
		cout << suf << "C" << num << endl;
	}
}

int main()
{
	// fast;
   ll t = 1;
   cin >> t;
   while(t--) {
   	solve();
   }
	return 0;
}
