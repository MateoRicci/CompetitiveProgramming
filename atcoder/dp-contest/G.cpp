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

vector<ll> g[MAXN];
ll dp[MAXN];

ll n,m;

ll f(ll v){
	if(v >= n) return 0;
	if(dp[v] != -1) return dp[v];

	dp[v] = 0;
	for(auto u : g[v]){
		dp[v] = max(dp[v], 1 + f(u));
	}
	return dp[v];
}

int main(){
    FIN;
	memset(dp,-1,sizeof(dp));
	cin >> n >> m;
	fore(i,0,m){
		ll a,b; cin >> a >> b, a--, b--;
		g[a].pb(b);
	}
	ll res = 0;
	fore(i,0,n){
		res = max(res,f(i));
	}
	cout << res << "\n";
}
