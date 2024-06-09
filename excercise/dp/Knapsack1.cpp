
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

ll n,W;
ll w[105], v[105];
ll dp[105][100005];

ll f(ll x, ll wg){
    if(x>=n) return 0; // chequeo de bordes
    if(wg<=0) return 0; // no me queda espacio en la mochila
	if(dp[x][wg]>=0)return dp[x][wg]; // ya revisamos esta posicion

    if(w[x] <= wg){
        dp[x][wg] = max(f(x+1,wg), v[x] + f(x+1,wg-w[x]));
    } else{
        dp[x][wg] = f(x+1,wg);
    }


	return dp[x][wg];
}

int main(){
    FIN;
	cin>>n>>W;
	fore(i,0,n){
        cin >> w[i] >> v[i];
    }
	memset(dp,-1,sizeof(dp));
	cout<<f(0,W)<<"\n";
}