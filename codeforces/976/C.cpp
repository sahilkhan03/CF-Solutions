/* “Whether you think you can or you think you can’t, you’re right” - Henry Ford */

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

void solve() {
    ll n; scanf("%lld", &n);
    vector<vl> v(n, vl(3));
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &v[i][0], &v[i][1]);
        v[i][2] = i + 1;
    }
    sort(all(v),[](const vl& a, const vl& b)-> bool{
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    multiset<pl, greater<pl>> s;
    for(int i = 0; i < n; i++) {
        ll l = v[i][0], r = v[i][1];  
        while(!s.empty() and s.rbegin()->F < l) s.erase(prev(s.end()));
        if(!s.empty() and s.begin()->F >= r) {
            printf("%lld %lld\n",v[i][2], s.begin()->S);
            return;
        }
        s.insert({r, v[i][2]});
    }
    printf("-1 -1\n");
}

int main()
{
    // fast;
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
