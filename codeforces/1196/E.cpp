/*
    Author : DemonStar
*/
#pragma GCC optimize("Ofast")
// #pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define loop(i, n) for(ll i = 0; i < n; i++)
#define mset(v, a) memset(v, a, sizeof v);
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

const ll mod = 998244353;

ll calc(string s, string can) {
    ll ans = 1e18, n = s.size(), k = can.size();
    for (int i = 0; i <= n - k; i++) {
        ll cur = 0;
        for (int j = 0; j < k; j++) cur += (s[i + j] != can[j]);
        ans = min(ans, cur);
    }
    return ans;
}

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fast;
    ll t;
    cin >> t;
    while (t--) {
        ll b, w;
        cin >> b >> w;
        if (max(b, w) > 3 * min(b, w) + 1) {
            cout << "NO" << endl;
            continue;
        }
        vector<pl> vb, vw;
        if (b < w) {
            pl s = {2, 3};
            while (b--) {
                vb.push_back(s);
                s.second += 2;
                if (w) {
                    vw.push_back({s.first, s.second - 1});
                    w--;
                }
            }
            if (w) vw.push_back({2, 2}), w--;
            for (auto x : vb) {
                if (!w) break;
                vw.push_back({x.first - 1, x.second});
                w--;
                if (w) {
                    vw.push_back({x.first + 1, x.second});
                    w--;
                }
            }
        }
        else {
            pl s = {2, 2};
            while (w--) {
                vw.push_back(s);
                s.second += 2;
                if (b) {
                    vb.push_back({s.first, s.second - 1});
                    b--;
                }
            }
            if (b) vb.push_back({2, 1}), b--;
            for (auto x : vw) {
                if (!b) break;
                vb.push_back({x.first - 1, x.second});
                b--;
                if (b) {
                    vb.push_back({x.first + 1, x.second});
                    b--;
                }
            }
        }
        cout << "YES" << endl;
        for (auto x : vb) cout << x << endl;
        for (auto x : vw) cout << x << endl;
    }
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}