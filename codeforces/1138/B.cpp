/*
    Author : DemonStar
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
void __print(bool x) {cerr << x;}

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

const ll mod = 998244353;

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fast;
    ll n;
    cin >> n;
    string a;
    string b;
    cin >> a >> b;
    vector<vl> cnt(4, vl());
    vl ans;
    for (int i = 0; i < n; i++) {
        if (a[i] == '0' and b[i] == '0') cnt[0].push_back(i);
        else if (a[i] == '0' and b[i] == '1') cnt[1].push_back(i);
        else if (a[i] == '1' and b[i] == '0') cnt[2].push_back(i);
        else cnt[3].push_back(i);
    }
    for (int i = 0; i <= n / 2; i++) {
        if (cnt[0].size() + cnt[1].size() < n / 2 - i or cnt[2].size() + cnt[3].size() < i) continue;
        ll req0 = n / 2 - i, req1 = i;
        debug(i, req0, req1);
        ll r01 = cnt[1].size() - min(ll(cnt[1].size()), req0),
           r00 = cnt[0].size() - (req0 - min(ll(cnt[1].size()), req0)),
           r10 = cnt[2].size() - min(ll(cnt[2].size()), req1),
           r11 = cnt[3].size() - (req1 - min(ll(cnt[2].size()), req1));
        debug(r00, r01, r10, r11);
        if (r00 + r10 == req0 and r11 + r01 == req1) {
            for (int j = 0; j < cnt[1].size() - r01; j++)
                cout << cnt[1][j] + 1 << " ";
            for (int j = 0; j < cnt[0].size() - r00; j++)
                cout << cnt[0][j] + 1 << " ";
            for (int j = 0; j < cnt[2].size() - r10; j++)
                cout << cnt[2][j]  + 1 << " ";
            for (int j = 0; j < cnt[3].size() - r11; j++)
                cout << cnt[3][j] + 1 << " ";
            return 0;
        }
    }
    cout << -1 << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}
