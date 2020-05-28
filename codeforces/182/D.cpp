/*
    Author : DemonStar
*/

#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define all(x) x.begin(), x.end()
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

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // fast;
    string a, b;
    cin >> a >> b;
    map<string, bool>  s;
    ll n = a.size();
    for (ll i = 1 ; i * i <= n; i++)  {
        if (n % i == 0) {
            for (ll j = 0; j < n; j++) {
                if (a[j] != a[j % i])
                    goto skip;
            }
            s[a.substr(0, i)] = 1;
skip:;
            for (ll j = 0; j < n; j++) {
                if (a[j] != a[j % (n / i)])
                    goto skip1;
            }
            s[a.substr(0, (n / i))] = 1;
skip1:;
        }
    }
    debug(s);
    n = b.size();
    ll ans = 0;
    for (ll i = 1 ; i * i <= n; i++)  {
        if (n % i == 0) {
            for (ll j = 0; j < n; j++) {
                if (b[j] != b[j % i])
                    goto skip2;
            }
            if (s[b.substr(0, i)]) ans++;
            if (i * i == n) continue;
            debug(i, ans);
skip2:;
            for (ll j = 0; j < n; j++) {
                if (b[j] != b[j % (n / i)])
                    goto skip3;
            }
            if (s[b.substr(0, (n / i))]) ans++;
            debug(n / i, ans);
skip3:;
        }
    }
    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif

    return 0;
}
