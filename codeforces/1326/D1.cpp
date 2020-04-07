/*                    ___          |\    /|           ____   ____   ____  ____
   |     |    /\    /    \ |     | | \  / |    /\    |    \ |    \ |     |    \
   |_____|   /__\   \____  |_____| |  \/  |   /__\   |____/ |____/ |__   |____/
   |     |  /    \       \ |     | |      |  /    \  |      |      |     |   \
   |     | /      \ \____/ |     | |      | /      \ |      |      |____ |    \
*/
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lb lower_bound
#define ub upper_bound
#define pf push_front
#define pb push_back
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define pld pair<long double,long double>
#define endl '\n'
#define loop(i,n) for(ll i=0;i<n;i++)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define mod ((ll)(1e9+7))
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define in3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define inv(v) for(auto&i:v) in(i)
#define all(x) x.begin(), x.end()
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpl vector<pair<ll,ll>>
#define INF 0x3f3f3f3f

template<typename T, typename TT>
ostream& operator<<(ostream &os, const pair<T, TT> &t) { return os<<t.first<<" "<<t.second; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &t) { for(auto& i: t) os<<i<<" "; return os; }

bool func(string s) {
    ll i=0,j=s.size()-1;
    while(i<=j) if(s[i++]!=s[j--]) return false;
    return true;
}

int main() {
    ll t;
    in(t);
    while(t--) {
        string s,ans="";
        cin>>s;
        ll i=0,j=s.size()-1;
        while(i<=j and s[i]==s[j]) i++,j--;
        if(i>j) {
            cout<<s<<endl;
            continue;
        }
        string mid = "" , tmp = "";
        rep(k,i,j) {
            tmp+=s[k];
            if(func(tmp) and tmp.size()>mid.size()) mid=tmp;
        }
        tmp="";
        for(ll k=j;k>=i;k--) {
            tmp = s[k]+tmp;
            if(func(tmp) and tmp.size()>mid.size()) mid = tmp;
        }
        cout<<s.substr(0,i) + mid + s.substr(j+1)<<endl;
        // ll p1=i,p2=j,len=0;
        // while(p1<=p2) {
        //     if(s[p1]==s[p2]) {
        //         if(p1==p2) len++;
        //         else len+=2;
        //         p1++,p2--;
        //     }
        //     else if(p1!=i) p1=i,len=0;
        //     else p2--;
        // }
        // string tmp1 = s.substr(i,len);
        // p1=i,p2=j,len=0;
        // while(p1<=p2) {
        //     if(s[p1]==s[p2]) {
        //         if(p1==p2) len++;
        //         else len+=2;
        //         p1++,p2--;
        //     }
        //     else if(p2!=j) p2=j,len=0;
        //     else p1++;
        // }
        // string tmp2 = s.substr(j-len+1,len);
        // if(tmp1.size()>tmp2.size()) cout<<s.substr(0,i) + tmp1 + s.substr(j+1,i)<<endl;
        // else cout<<s.substr(0,i) + tmp2 + s.substr(j+1,i)<<endl;
    }
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}