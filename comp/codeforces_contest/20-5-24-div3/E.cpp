
#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll m,pl;
ll h[51][2];
vector<vector<ll>> dp(100000000, vector<ll>(51));

ll f(ll x, ll d){
    if(d>m) return 0; // chequeo de bordes
	if(dp[x][d]>=0)return dp[x][d]; // ya revisamos esta posicion

    if(x<h[d][0]){
        f(x+pl,d+1);
    }
    else{
        dp[x][d] = max(f(x+pl,d+1),h[d][1] + f(x+pl-h[d][0],d+1));
    }
    
	return dp[x][d]; 
}

int main(){
    FIN;
    ll t; cin >> t;
    while(t--){
        cin >> m >> pl;
        fore(i,1,m+1){
            cin >> h[i][0] >> h[i][1]; // costo y felicidad
        }
        cout<< f(0,0)<<"\n";
    }
}