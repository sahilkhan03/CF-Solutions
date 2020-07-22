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

string calc(string &s, ll mid) {
    string f1 = s.substr(0, mid), f2 = s.substr(mid);
    reverse(all(f1)); reverse(all(f2));
    ll c = 0;
    string ans = "";
    for (int j = 0; j < max(f1.size(), f2.size()); j++) {
        ll cur = (j < f1.size() ? f1[j] : '0') + (j < f2.size() ? f2[j] : '0') - '0' - '0';
        cur += c;
        c = cur / 10;
        ans += char((cur % 10) + '0');
    }
    if (c) ans += char(c + '0');
    reverse(all(ans));
    return ans;
}
string check(string a, string b) {
    if (a.size() < b.size()) return a;
    if (b.size() < a.size()) return b;
    for (int i = 0; i < a.size(); i++)
        if (a[i] < b[i]) return a;
        else if (a[i] > b[i]) return b;
    return a;
}

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fast;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll mid = n / 2;
    string ans1 = "-1", ans2 = "-1";
    for (int i = mid; i < n; i++) {
        if (s[i] != '0') {
            ans1 = calc(s, i);
            break;
        }
    }
    for (int i = mid - 1; i > 0; i--) {
        if (s[i] != '0') {
            ans2 = calc(s, i);
            break;
        }
    }
    if (n & 1) {
        for (int i = mid + 1; i < n; i++) {
            if (s[i] != '0') {
                if (ans1 != "-1")
                    ans1 = check(ans1, calc(s, i));
                else ans1 = calc(s, i);
                break;
            }
        }
        for (int i = mid; i > 0; i--) {
            if (s[i] != '0') {
                if (ans2 != "-1")
                    ans2 = check(ans2, calc(s, i));
                else ans2 = calc(s, i);
                break;
            }
        }
    }
    string ans = s;
    if (ans1 != "-1") ans = ans1;
    if (ans2 != "-1") ans = check(ans, ans2);
    reverse(all(ans));
    while (ans.size() > 1 and ans.back() == '0') ans.pop_back();
    reverse(all(ans));
    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}
