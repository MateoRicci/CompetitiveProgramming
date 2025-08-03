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
const ll MAXN = 1005;
const ll MOD = 1000000007;
ll dp[MAXN][MAXN];
char a[MAXN][MAXN];

ll h,w;

ll f(ll i, ll j){
	if(i >= h || j >= w) return 0;
	if(i == h-1 && j == w-1) return 1;
	if(dp[i][j] != -1) return dp[i][j];
	if(a[i][j] == '#') return 0;
	dp[i][j] = (f(i+1,j) + f(i,j+1)) % MOD;
	return dp[i][j] % MOD;
}

int main(){
    FIN;
	memset(dp,-1,sizeof(dp));
	cin >> h >> w;
	fore(i,0,h) fore(j,0,w) cin >> a[i][j];
	cout << f(0,0) << "\n";
}
