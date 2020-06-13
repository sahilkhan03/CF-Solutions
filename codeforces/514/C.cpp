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
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define loop(i, n) for(ll i = 0; i < n; i++)
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

uniform_int_distribution<int> dist(7, mod - 2);
random_device rd;
const ll p1 = dist(rd), p2 = dist(rd);

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vl pw1(1e6), pw2(1e6);
    pw1[0] = 1, pw2[0] = 1;
    for (int i = 1; i < 1e6; i++) {
        pw1[i] = (pw1[i - 1] * p1) % mod;
        pw2[i] = (pw2[i - 1] * p2) % mod;
    }
    map<ll, bool> mp1, mp2;
    int n, m;
    cin >> n >> m;
    while (n--) {
        string s;
        cin >> s;
        ll hash1 = 0, hash2 = 0;
        for (int i = 0; i < s.size(); i++) {
            hash1 = (hash1 * p1 + s[i]) % mod;
            hash2 = (hash2 * p2 + s[i]) % mod;
        }
        debug(s, hash1, hash2);
        mp1[hash1] = 1;
        mp2[hash2] = 1;
    }
    while (m--) {
        string s;
        cin >> s;
        ll hash1 = 0, hash2 = 0;
        for (int i = 0; i < s.size(); i++) {
            hash1 = (hash1 * p1 + s[i]) % mod;
            hash2 = (hash2 * p2 + s[i]) % mod;
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = 'a'; j <= 'c'; j++) {
                if (j == s[i]) continue;
                ll nhash1 = (mod * mod + hash1 + (j - s[i]) * pw1[s.size() - i - 1]) % mod;
                ll nhash2 = (mod * mod + hash2 + (j - s[i]) * pw2[s.size() - i - 1]) % mod;
                if (mp1[nhash1] and mp2[nhash2]) {
                    cout << "YES" << endl;
                    goto skip;
                }
            }
        }
        cout << "NO" << endl;
skip:;
    }



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}