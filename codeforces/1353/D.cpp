/*                    ___          |\    /|           ____   ____   ____  ____
   |     |    /\    /    \ |     | | \  / |    /\    |    \ |    \ |     |    \
   |_____|   /__\   \____  |_____| |  \/  |   /__\   |____/ |____/ |__   |____/
   |     |  /    \       \ |     | |      |  /    \  |      |      |     |   \
   |     | /      \ \____/ |     | |      | /      \ |      |      |____ |    \
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define pi pair<int, int>
#define pl pair<long long, long long>
#define pld pair<long double, long double>
#define endl '\n'
#define loop(i, n) for (ll i = 0; i < n; i++)
#define rep(i, begin, end) for (__typeof(begin) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod ((ll)(1e9 + 7))
#define all(x) x.begin(), x.end()
#define vl vector<ll>
#define vi vector<int>
#define ml map<ll, ll>
#define vpl vector<pair<ll, ll>>

template <typename T, typename TT>
ostream &operator<<(ostream &os, const pair<T, TT> &t)
{
    return os << t.first << " " << t.second;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &t)
{
    for (auto &i : t)
        os << i << " ";
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &t : v)
        is >> t;
    return is;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, vector<pair<T1, T2>> &v)
{
    for (pair<T1, T2> &t : v)
        is >> t.first >> t.second;
    return is;
}

// int sieve[int(1e6) + 5];
struct cmp
{
    bool operator()(vl a, vl b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a < b;
    }
};
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, i = 1;
        cin >> n;
        vl v(n + 1, 0);
        priority_queue<vector<ll>, vector<vl>, cmp> pq;
        pq.push({n, 1, n});
        while (!pq.empty())
        {
            auto tp = pq.top();
            // cout << tp << endl;
            pq.pop();
            if (tp[1] == tp[2])
                v[tp[1]] = i++;
            else
            {
                ll med = tp[1] + tp[0] / 2;
                if (tp[0] % 2 == 0)
                    med--;
                v[med] = i++;
                if (med - tp[1])
                    pq.push({med - tp[1], tp[1], med - 1});
                if (tp[2] - med)
                    pq.push({tp[2] - med, med + 1, tp[2]});
            }
        }
        // cout << v << endl;
        rep(i, 1, n + 1) cout << v[i] << " ";
        cout << endl;
    }

#ifdef LOCAL
    cerr
        << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;
}