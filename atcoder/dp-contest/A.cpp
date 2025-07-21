#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN = 100005;

ll n;
ll dp[MAXN];
ll a[MAXN];

ll f(ll i){
    if(i >= n-1) return 0;
    if(dp[i]!=-1) return dp[i];

    if(i < n-2){
        dp[i] = min(abs(a[i]-a[i+1]) + f(i+1), abs(a[i]-a[i+2]) + f(i+2));
    } else{
        dp[i] = abs(a[i]-a[i+1]);
    }

    return dp[i];
}


int main(){
    FIN;
    memset(dp,-1,sizeof(dp));
    cin >> n;
    fore(i,0,n) cin >> a[i];
    cout << f(0) << "\n";
}