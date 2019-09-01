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
    string a,b,c;
    a="qwertyuiop";
    b="asdfghjkl;";
    c="zxcvbnm,./";
    ll n;in(n);
    char ch;
    cin>>ch;
    string s,ans;
    cin>>s;
    if(ch=='R') {
        for(ll i=0;i<s.size();i++) {
            if(a.find(s[i])!=string::npos) s[i]=a[a.find(s[i])-1];
            if(b.find(s[i])!=string::npos) s[i]=b[b.find(s[i])-1];
            if(c.find(s[i])!=string::npos) s[i]=c[c.find(s[i])-1];
        }
    } else {
        for(ll i=0;i<s.size();i++) {
            if(a.find(s[i])!=string::npos) s[i]=a[a.find(s[i])+1];
            if(b.find(s[i])!=string::npos) s[i]=b[b.find(s[i])+1];
            if(c.find(s[i])!=string::npos) s[i]=c[c.find(s[i])+1];
        }
    }
    cout<<s<<endl;
    return 0;
}