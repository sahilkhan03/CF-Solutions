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
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
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

const int N = 1e6 + 1;
int fen[N];
void update(int i, int s)
{
    while (i < N)
        fen[i] += s, i += (i & (-i));
}
int sum(int i)
{
    int s = 0;
    while (i)
        s += fen[i], i -= i & (-i);
    return s;
}
int main()
{
    fast;
    int n, q, lo, hi, mid, last, t;
    scanf("%d%d", &n, &q);
    loop(i, n)
    {
        scanf("%d", &t);
        update(t, 1);
    }
    while (q--)
    {
        scanf("%d", &t);
        if (t > 0)
            update(t, 1);
        else
        {
            t = -t;
            lo = 1, hi = N, last = hi;
            while (lo <= hi)
            {
                mid = lo + (hi - lo) / 2;
                if (sum(mid) >= t)
                    last = mid, hi = mid - 1;
                else
                    lo = mid + 1;
            }
            update(last, -1);
        }
    }
    if (sum(N - 1))
    {
        lo = 1, hi = N - 1, last = N - 1;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (sum(mid) >= 1)
                hi = mid - 1, last = mid;
            else
                lo = mid + 1;
        }
        cout << last << endl;
    }
    else
        cout << 0 << endl;
#ifdef LOCAL
    cerr
        << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;
}
