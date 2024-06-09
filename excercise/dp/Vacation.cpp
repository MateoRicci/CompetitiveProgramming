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
ll act[100005][3];
ll dp[100005][3];

ll f(ll x, ll y){
	if(dp[x][y]>=0)return dp[x][y]; // ya revisamos esta posicion
    if(x>=n) return 0; // chequeo de bordes

    dp[x][y] = max(f(x+1,(y+1)%3),f(x+1,(y+2)%3)) + act[x][y];

	return dp[x][y];
}

int main(){
    FIN;
	cin>>n;
	fore(i,0,n){
        cin >> act[i][0] >> act[i][1] >> act[i][2];
    }
	memset(dp,-1,sizeof(dp));
	cout<<max(f(0,0),max(f(0,1),f(0,2)))<<"\n";
}