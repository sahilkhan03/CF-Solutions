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

bitset<1000005> vis;

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int lim = log2(n);
    vector<vector<int>> v(lim + 1), gcd(lim + 1);
    for (int i = 0; i < n ; i++) {
        int tmp ;
        cin >> tmp;
        v[0].push_back(tmp);
        gcd[0].push_back(tmp);
    }
    for (int i = 1; i <= lim; i++) {
        int mx = n - (1 << i) + 1;
        v[i].resize(mx);
        gcd[i].resize(mx);
        for (int j = 0; j < mx; j++) {
            v[i][j] = min(v[i - 1][j], v[i - 1][j + (1 << (i - 1))]);
            gcd[i][j] = __gcd(gcd[i - 1][j], gcd[i - 1][j + (1 << (i - 1))]);
        }
    }
    debug(v, gcd);
    int mx = 0, i = 0, j = 0;
    set<int> ans;
    for (int i = 0; i < n; i++) {
        int lo = i, hi = n - 1, lf = -1, rg = -1;;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2, len = log2(mid - i + 1);
            if (min(v[len][i], v[len][mid - (1 << len) + 1]) == __gcd(gcd[len][i], gcd[len][mid - (1 << len) + 1]) and __gcd(gcd[len][i], gcd[len][mid - (1 << len) + 1]) == v[0][i])
                rg = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        lo = 0, hi = i;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2, len = log2(i - mid + 1);
            if (min(v[len][mid], v[len][i - (1 << len) + 1]) == __gcd(gcd[len][mid], gcd[len][i - (1 << len) + 1]) and __gcd(gcd[len][mid], gcd[len][i - (1 << len) + 1]) == v[0][i])
                lf = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        debug(i, lf, rg);
        if (mx < rg - lf + 1) {
            mx = rg - lf + 1;
            ans.clear();
            ans.insert(lf + 1);
        }
        else if (mx == rg - lf + 1) {
            ans.insert(lf + 1);
        }
    }
    cout << ans.size() << " " << mx - 1 << endl;
    for (auto x : ans)
        cout << x << " ";

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}