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
const ll MAXN = 3005;
string s,t;

ll dp[MAXN][MAXN];

ll f(ll m, ll n){
	if(m >= SZ(s) || n >= SZ(t)) return 0;
	if(dp[m][n] != -1) return dp[m][n];

	// si matchea la letra
	if(s[m] == t[n]){
		dp[m][n] = 1 + f(m+1,n+1);
	}
	else{
		dp[m][n] = max(f(m+1,n), f(m,n+1));
	}

	return dp[m][n];
}


int main(){
    FIN;
    memset(dp,-1,sizeof(dp));
    cin >> s >> t;
    ll res = f(0,0);
    string ans;
    ll l=0,r=0;
    while(res){
    	if(f(l,r+1) == res) r++;
    	else if(f(l+1, r) == res) l++;
    	else if(f(l+1, r+1) == res-1){
    		ans.pb(s[l]); res--,l++,r++;
    	}
    }
    show(ans);
}
