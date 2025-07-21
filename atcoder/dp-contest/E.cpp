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
const ll MAXN = 105;
const ll MAXW = 100005;

ll dp[MAXN][MAXW];
ll a[MAXN][2];
ll n; ll w;

ll f(ll i,ll vi){
    if(dp[i][vi] > w) return -1000000000000;
    if(i>=n) return 0;
    if(dp[i][vi]!=-1) return dp[i][vi];

    dp[i][vi] = 

    return dp[i][wi];
}

int main(){
    FIN;
    memset(dp,-1,sizeof(dp));
    cin >> n >> w;
    fore(i,0,n) cin >> a[i][0] >> a[i][1];
    cout << f(0,0) << "\n";
}
