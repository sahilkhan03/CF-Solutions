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
        ll n, m;
        cin >> n >> m;
        vector<string> s(n);
        cin >> s;
        vector<pl> b, g;
        loop(i, n) {
            loop(j, m) {
                if (s[i][j] == 'B') b.push_back({i, j});
                else if (s[i][j] == 'G') g.push_back({i, j});
            }
        }
        ll i, j;
        queue<pl> q;
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        for (auto x : b) {
            tie(i, j) = x;
            if (i > 0 and s[i - 1][j] == '.') s[i - 1][j] = '#';
            if (i < n - 1 and s[i + 1][j] == '.') s[i + 1][j]  = '#';
            if (j > 0 and s[i][j - 1] == '.') s[i][j - 1] = '#';
            if (j < m - 1 and s[i][j + 1] == '.') s[i][j + 1]  = '#';
            q.push(x);
        }
        bool reach = 0;
        while (!q.empty()) {
            auto tp = q.front(); q.pop();
            tie(i, j) = tp;
            if (vis[i][j] or s[i][j] == '#')
                continue;
            if (i == n - 1 and j == m - 1) reach = 1;
            vis[i][j] = 1;
            if (i > 0)
                q.push({i - 1, j});
            if (i < n - 1)
                q.push({i + 1, j});
            if (j < m - 1)
                q.push({i, j  + 1});
            if (j > 0)
                q.push({i, j - 1});
        }
        debug(s, reach);
        vector<pl> tmp;
        vector<vector<int>> v(n, vector<int>(m, -1));
        if (reach) {
            cout << "No" << endl;
            goto skip;
        }
        for (auto x : g) {
            queue<pl> q1;
            q1.push(x);
            while (!q1.empty()) {
                tie(i, j) = q1.front();
                q1.pop();
                debug(i, j);
                if (v[i][j] == 1) goto skip1;
                if (v[i][j] == 2 or s[i][j] == '#') continue;
                v[i][j] = 2;
                tmp.push_back({i, j});
                debug(tmp);
                if (i == n - 1 and j == m - 1) goto skip1;
                if (i > 0)
                    q1.push({i - 1, j});
                if (i < n - 1)
                    q1.push({i + 1, j});
                if (j < m - 1)
                    q1.push({i, j  + 1});
                if (j > 0)
                    q1.push({i, j - 1});
            }
            cout << "No" << endl;
            goto skip;
skip1:;
            for (auto x : tmp)
                v[x.first][x.second] = 1;
            tmp.clear();
        }
        cout << "Yes" << endl;
        debug(v);
skip:;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}