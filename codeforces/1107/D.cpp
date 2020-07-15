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

const ll mod = 1e9 + 7;


string hb(char c) {
    switch (toupper(c))
    {
    case '0': return "0000";
    case '1': return "0001";
    case '2': return "0010";
    case '3': return "0011";
    case '4': return "0100";
    case '5': return "0101";
    case '6': return "0110";
    case '7': return "0111";
    case '8': return "1000";
    case '9': return "1001";
    case 'A': return "1010";
    case 'B': return "1011";
    case 'C': return "1100";
    case 'D': return "1101";
    case 'E': return "1110";
    case 'F': return "1111";
    }
    return "0000";
}

bool calc(vector<vector<int>> &v, int n, int x) {
    for (int i = x; i <= n; i += x) {
        for (int j = x; j <= n; j += x) {
            ll s = v[i][j] - v[i - x][j] - v[i][j - x] + v[i - x][j - x];
            if (s != 0 and s != x * x) {
                debug(x, s);
                return 0;
            }
        }
    }
    return 1;
}

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fast;
    int n;
    scanf("%d", &n);
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        char c[1305]; scanf("%s[^\n]", &c);
        for (int j = 0; j < n / 4; j++) {
            string res = hb(c[j]);
            v[i + 1][j * 4 + 1] = (res[0] == '1');
            v[i + 1][j * 4 + 2] = (res[1] == '1');
            v[i + 1][j * 4 + 3] = (res[2] == '1');
            v[i + 1][j * 4 + 4] = (res[3] == '1');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
        }
    }
    // for (int i = 0; i < n; i++)
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++)
    //         cerr << v[i][j] ;
    //     cerr << endl;
    // }
    vl fn = {1, n};
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0 ) {
            fn.push_back(i);
            if (n != i * i) fn.push_back(n / i);
        }
    }
    sort(all(fn));
    ll ans = 1;
    for (int i = fn.size() - 1; ~i; i--) {
        if (calc(v, n, fn[i])) {
            ans = fn[i];
            break;
        }
    }
    cout << ans << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}
