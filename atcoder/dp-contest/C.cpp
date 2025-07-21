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
ll dp[MAXN][3];
ll a[MAXN][3];

ll f(ll i, ll j){
    if(i>=n) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = a[i][j] + max(f(i+1,(j+1)%3), f(i+1,(j+2)%3));

    return dp[i][j];
}

int main(){
    FIN;
    memset(dp,-1,sizeof(dp));
    cin >> n;
    fore(i,0,n) cin >> a[i][0]>> a[i][1]>> a[i][2];
    cout << max({f(0,0),f(0,1),f(0,2)}) << "\n";
}