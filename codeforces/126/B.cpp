/*
    Author : DemonStar
*/

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define loop(i, n) for(ll i = 0; i < n; i++)
#define mset(v, a) memset(v, a, sizeof v);
#define pl pair<ll, ll>
#define vl vector<ll>
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

random_device rd;
uniform_int_distribution<int> dist(7, 1e9);
const ll p1 = dist(rd), p2 = dist(rd);

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    int n = s.size();
    vl pw1(1e6 + 5), pw2(1e6 + 5), pres1(n), pres2(n);
    pw1[0] = 1, pw2[0] = 1;
    for (int i = 1; i <= 1e6; i++) {
        pw1[i] = (1LL * pw1[i - 1] * p1) % mod;
        pw2[i] = (1LL * pw2[i - 1] * p2) % mod;
    }
    loop(i, n) {
        if (!i) pres1[i] = s[i], pres2[i] = s[i] ;
        else {
            pres1[i] = (1LL * pres1[i - 1] * p1 + s[i]) % mod;
            pres2[i] = (1LL * pres2[i - 1] * p2 + s[i]) % mod;
        }
    }
    vl v;
    for (int i = 0; i < n - 2; i++) {
        if (pres1[i] == (pres1[n - 1] - pres1[n - i - 2]*pw1[i + 1] + mod * mod) % mod and pres2[i] == (pres2[n - 1] - pres2[n - i - 2]*pw2[i + 1] + mod * mod) % mod )
            v.push_back(i + 1);
    }
    debug(v);
    if (v.empty()) {
        cout << "Just a legend" << endl;
        return 0;
    }
    ll lo = 0, hi = v.size() - 1, mid;
    ll ans = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        ll len = v[mid];
        for (int i = len; i < n - 1; i++) {
            if ((pres1[i] - pres1[i - len]*pw1[len] + mod * mod) % mod == pres1[len - 1] and pres2[len - 1] == (pres2[i] - pres2[i - len]*pw2[len] + mod * mod) % mod) {
                lo = mid + 1;
                ans = v[mid];
                goto skip;
            }
        }
        hi = mid - 1;
skip:;
    }
    debug(ans);
    if (ans == -1)
        cout << "Just a legend" << endl;
    else
        cout << s.substr(0, ans) << endl;



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}
