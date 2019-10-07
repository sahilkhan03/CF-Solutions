/*                    ___          |\    /|           ____   ____   ____  ____
   |     |    /\    /    \ |     | | \  / |    /\    |    \ |    \ |     |    \
   |_____|   /__\   \____  |_____| |  \/  |   /__\   |____/ |____/ |__   |____/
   |     |  /    \       \ |     | |      |  /    \  |      |      |     |   \
   |     | /      \ \____/ |     | |      | /      \ |      |      |____ |    \
*/
#include<bits/stdc++.h>
using namespace std;
#define lb lower_bound
#define ub upper_bound
#define pf push_front
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pi pair<int,int>
#define pl pair<long,long>
#define pll pair<long long,long long>
#define pld pair<long double,long double>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define endl '\n'
#define loop(i,n) for(ll i=0;i<n;i++)
#define mod 1e9+7
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define vl vector<ll>
#define vpll vector<pair<ll,ll>>
#define INF 0x3f3f3f3f
#define mp make_pair

int main()
{
    ll n,k;
    in2(n,k);
    ll mid, beg = 1, end = n, last_ans;
    while(beg<=end) {
        mid = (beg+end)/2;
        ll j = 0, cur=0;
        while(mid/pow(k,j) and cur<=n) {
            cur+=mid/pow(k,j);
            j++;
        }
        if(cur>=n) {
            last_ans = mid;
            end = mid-1;
        }
        else beg = mid+1;
        // cout<<mid<<" - "<<cur<< " "<<beg<< " "<<end<<endl;
    }
    cout<<last_ans<<endl;
    return 0;
}