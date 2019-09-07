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
    string s,s1;
    cin>>s>>s1;
    ll i,left=0,right=0;
    for( i=0;i<s.size();i++) if(s[i]=='|') break;
    left = i; right = s.size()-i-1;
    ll j=0;
    auto it = s.end();
    //it--;
    if(left<right) {
        while(left<right and j<s1.size()) {
            s.insert(s.begin(),s1[j++]);
            left++;
        }
    }
    else if(right<left) {
        while(left>right and j<s1.size()) {
            s.insert(s.end(),s1[j++]);
            right++;
        }
    }
        while(j<s1.size()) {
            s.insert(s.begin(),s1[j++]); left++;
            if(j<s1.size()) 
                {s.insert(s.end(),s1[j++]);right++;}
        }
        // s.insert(s.end(),'I');
        // cout<<s<<endl;
    // cout<<j<<endl;
    if(left == right and j==s1.size()) 
    cout<<s<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}