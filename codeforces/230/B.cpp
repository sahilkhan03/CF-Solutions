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
#define mod ((ll)(1e9+7))
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpll vector<pair<ll,ll>>
#define INF 0x3f3f3f3f
#define mp make_pair

ll power(ll a, unsigned ll n, ll p) 
{ 
    ll res = 1;      // Initialize result 
    a = a % p;  // Update 'a' if 'a' >= p 
  
    while (n > 0) 
    { 
        // If n is odd, multiply 'a' with result 
        if (n & 1) 
            res = (res*a) % p; 
  
        // n must be even now 
        n = n>>1; // n = n/2 
        a = (a*a) % p; 
    } 
    return res; 
} 

bool isPrime(ll n, ll k) 
{ 
   // Corner cases 
   if (n <= 1 || n == 4)  return false; 
   if (n <= 3) return true; 
  
   // Try k times 
   while (k>0) 
   { 
       // Pick a random number in [2..n-2]         
       // Above corner cases make sure that n > 4 
       ll a = 2 + rand()%(n-4);   
  
       // Checking if a and n are co-prime 
       if (__gcd(n, a) != 1) 
          return false; 
   
       // Fermat's little theorem 
       if (power(a, n-1, n) != 1) 
          return false; 
  
       k--; 
    } 
  
    return true; 
} 
int main() {
    ll n;
    in(n);
    while(n--) {
        ll t;
        in(t);
        if(t==1) {cout<<"NO"<<endl;continue;}
        if((ll)sqrt(t)*(ll)sqrt(t)==t and isPrime((ll)sqrt(t),9)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

