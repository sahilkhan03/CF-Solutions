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

ll a, b, x, y;

ll calc(vector<pl> &pre, ll k) {
    ll n = pre.size(); n--;
    pl ans = {a + (k / n)*pre[n].first + pre[k % n].first, b + (k / n)*pre[n].second + pre[k % n].second};
    ll dis = abs(x - ans.first) + abs(y - ans.second);
    debug(ans);
    debug(dis);
    dis -= k;
    return max(0ll, dis);
}

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fast;
    cin >> a >> b >> x >> y;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<pl> pre(n + 1);
    pre[0] = {0, 0};
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') pre[i + 1] = {pre[i].first - 1, pre[i].second};
        else if (s[i] == 'R') pre[i + 1] = {pre[i].first + 1, pre[i].second};
        else if (s[i] == 'U') pre[i + 1] = {pre[i].first, pre[i].second + 1};
        else if (s[i] == 'D') pre[i + 1] = {pre[i].first, pre[i].second - 1};
    }
    ll lo = 1, hi = 1e18, mid;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        ll f1 = calc(pre, mid - 1), f2 = calc(pre, mid), f3 = calc(pre, mid + 1);
        if (f1 >= f2 and f2 <= f3) {
            debug(mid, f1, f2, f3);
            break;
        }
        else if (f1 <= f2 and f2 <= f3) hi = mid - 1;
        else lo = mid + 1;
    }
    debug(mid);
    lo = 1, hi = mid;
    ll ans = -1;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (!calc(pre, mid)) hi = mid -  1, ans = mid;
        else lo = mid + 1;
        debug(mid, calc(pre, mid));
    }
    cout << ans << endl;
    debug(calc(pre, 13));

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}
