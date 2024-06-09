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

ll n;
ll h[100005];
ll dp[100005];

ll f(ll x){
	if(dp[x]>=0)return dp[x]; // ya revisamos esta posicion
	if(x==n-1)return 0; // final
	if(x==n-2)return abs(h[n-1]-h[n-2]); // ultimo salto
	dp[x]=min(f(x+1)+abs(h[x+1]-h[x]),f(x+2)+abs(h[x+2]-h[x])); // caso recursivo
	return dp[x];
}

int main(){
    FIN;
	cin>>n;
	fore(i,0,n)cin>>h[i];
	memset(dp,-1,sizeof(dp));
	cout<<f(0)<<"\n";
}