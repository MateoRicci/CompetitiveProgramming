#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

ll n,k;
ll h[100005];
ll dp[100005];

ll f(ll x){
	if(dp[x]>=0)return dp[x]; // ya revisamos esta posicion
	if(x==n-1)return 0; // final
	if(x==n-2)return abs(h[n-1]-h[n-2]); // ultimo salto
    if(x>=n) return 1e10;
    dp[x] = 1e10;
    fore(i,1,k+1){
	    dp[x]=min(dp[x],f(x+i)+abs(h[x+i] - h[x])); // caso recursivo
    }
	return dp[x];
}

int main(){
    FIN;
	cin>>n>>k;
	fore(i,0,n)cin>>h[i];
	memset(dp,-1,sizeof(dp));
	cout<<f(0)<<"\n";
}