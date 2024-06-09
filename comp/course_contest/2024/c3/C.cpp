
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
ll h[100005][2];
ll dp[100005][2];

ll f(ll x, ll r){
    if(x>=n) return 0; // chequeo de bordes
	if(dp[x][r]>=0)return dp[x][r]; // ya revisamos esta posicion

    ll alt = h[x][r];

    dp[x][r] = max(alt + f(x+1,1-r), f(x+1,r));
    
	return dp[x][r]; 
}

int main(){
    FIN;
	cin>>n;
	fore(i,0,n){
        cin >> h[i][0];
    }
    fore(i,0,n){
        cin >> h[i][1];
    }
	memset(dp,-1,sizeof(dp));

	cout<<max(f(0,0),f(0,1))<<"\n";
}