/*
    "Whether you think you can or you think you can't, you're right"
        - Henry Ford
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

template <typename T, typename TT>
inline ostream &operator<<(ostream &os, const pair<T, TT> &t) {
    return os << t.first << " " << t.second;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &t) {
    for (auto i : t) os << i << " ";
    return os;
}
template <typename T>
inline ostream &operator<<(ostream &os, const set<T> &t) {
    for (auto i : t) os << i << " ";
    return os;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &t) {
    for (auto i : t) os << i.first << " : " << i.second << endl;
    return os;
}
template <typename T>
inline istream &operator>>(istream &is, vector<T> &v) {
    for (T &t : v) is >> t;
    return is;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &is, vector<pair<T1, T2>> &v) {
    for (pair<T1, T2> &t : v) is >> t.first >> t.second;
    return is;
}

#ifdef LOCAL
#define debug(args...) (Debugger()), args
class Debugger {
public:
    bool first;
    string separator;
    Debugger(const string &_separator = ", ") : first(true), separator(_separator) {}
    template <typename ObjectType>
    Debugger &operator, (const ObjectType &v) {
        if (!first) cerr << separator;
        cerr << v;
        first = false;
        return *this;
    }
    ~Debugger() { cerr << endl; }
};
#else
#define debug(args...)
#endif

const ll mod = 1e9 + 7;

void solve() {
    int n; scanf("%d", &n);
    vector<vi> v(n, vi(n));
    vector<vector<pair<int, char>>> dp2(n + 1, vector<pair<int, char>>(n + 1, {0, '.'})), dp5(n + 1, vector<pair<int, char>>(n + 1, {0, '.'}));
    bool f = 0;
    pl loc = { -1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &v[i][j]);
            int c2 = 0, c5 = 0;
            if (!v[i][j]) loc = {i, j}, f = 1, c2++, c5++;
            else {
                while (v[i][j] > 1 and v[i][j] % 2 == 0) c2++, v[i][j] /= 2;
                while (v[i][j] > 1 and v[i][j] % 5 == 0) c5++, v[i][j] /= 5;
            }
            if (!i) {
                dp2[i + 1][j + 1] = {dp2[i + 1][j].F + c2, 'R'};
                dp5[i + 1][j + 1] = {dp5[i + 1][j].F + c5, 'R'};
                continue;
            }
            if (!j) {
                dp2[i + 1][j + 1] = {dp2[i][j + 1].F + c2, 'D'};
                dp5[i + 1][j + 1] = {dp5[i][j + 1].F + c5, 'D'};
                continue;
            }
            if (dp2[i][j + 1].F > dp2[i + 1][j].F)
                dp2[i + 1][j + 1] = {dp2[i + 1][j].F + c2, 'R'};
            else
                dp2[i + 1][j + 1] = {dp2[i][j + 1].F + c2, 'D'};
            if (dp5[i][j + 1].F > dp5[i + 1][j].F)
                dp5[i + 1][j + 1] = {dp5[i + 1][j].F + c5, 'R'};
            else
                dp5[i + 1][j + 1] = {dp5[i][j + 1].F + c5, 'D'};
        }
    }
    if (f and min(dp2[n][n].F, dp5[n][n].F) > 1) {
        printf("1\n");
        debug(loc);
        for (int i = 0; i < loc.F; i++) printf("D");
        for (int j = 0; j < loc.S; j++) printf("R");
        for (int i = loc.F; i < n - 1; i++) printf("D");
        for (int i = loc.S; i < n - 1; i++) printf("R");
        return;
    }
    string ans = "";
    printf("%d\n", min(dp2[n][n].F, dp5[n][n].F));
    if (dp2[n][n].F < dp5[n][n].F) {
        ll i = n, j = n;
        while (!(i == 1 and j == 1)) {
            char c = dp2[i][j].S;
            ans += c;
            if (c == 'R') j--;
            else i--;
        }
    }
    else {
        ll i = n, j = n;
        while (!(i == 1 and j == 1)) {
            char c = dp5[i][j].S;
            ans += c;
            if (c == 'R') j--;
            else i--;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) printf("%c", ans[i]);
}

int main()
{
    solve();
    return 0;
}
