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
#define mp make_pair

int main()
{
    ll n;
    in(n); vl v(n);
    ll a=0,b=0,c=0;
    vl av,bv,cv;
    ll j=0;
    for(auto& i:v ) {
        in(i);
        if(i==1) {a++;av.push_back(j+1);}
        else if(i==2) {b++;bv.push_back(j+1);}
        else
        {
             {c++;cv.push_back(j+1);}
        }
        j++;
    }
    ll w=min(a,min(b,c));
    cout<<w<<endl;
    ll  it=0;
    while(it<av.size() and it<bv.size() and it<cv.size()) {
        cout<<av[it]<<" "<<bv[it]<<" "<<cv[it]<<endl;
        it++;
    }

    return 0;
}