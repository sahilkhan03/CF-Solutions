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
#define ll long 
#define pi pair<int,int>
#define pl pair<long,long>
#define pll pair<long long,long long>
#define pld pair<long double,long double>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define endl '\n'
#define it(i,a,b) for(i=a;i<b;i++)
#define mod 1e9+7
#define in(x) scanf("%ld",&x)
#define in2(x,y) scanf("%ld %ld",&x,&y)
#define vl vector<ll>
#define mp make_pair

int main()
{
    ll q;
    in(q);
    while (q--)
    {
        ll n;
        in(n);
        vector<ll> v(n);
        for(ll i=0;i<n;i++) in(v[i]);
        ll flag=1,flag1=1;
        ll posmin,i=1,count=1,minC=99999999;

        //Check Clockwise
        for(ll i=0;i<n;i++) {
            if(v[i]<minC) {minC=v[i];posmin=i;} 
        }
        ll f1=1;
        for(ll i=1;i<posmin;i++) {
            if((v[i]-v[(i-1+n)%n])!=1) {
                f1=0;
                break;
            }
        }
        if(f1) {
            for(ll i=posmin+1;i<n;i++) {
                if((v[i]-v[(i-1+n)%n])!=1) {
                    f1=0;
                    break;
                }
            }
        }
        ll f2=1;
        if(!f1) {
         for(ll i=1;i<posmin;i++) {
            if((v[(i-1+n)%n]-v[i])!=1) {
                f2=0;
                break;
            }
            // cout<<" --";
         }
         if(f2) {
              for(ll i=posmin+1;i<n;i++) {
                if((v[i]-v[(i+1)%n])!=1) {
                    f2=0;
                    break;
                }
            }
         }
        }
        // if(abs(v[0]-v[n-1])!=1) f1=f2=0;
        // cout<<f1<<" "<<f2<<" /"<<posmin;
        cout<<(((max(f1,f2)) ? "YES\n" : "NO\n"));
    }
    
    return 0;
}