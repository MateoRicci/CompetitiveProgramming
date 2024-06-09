
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

#define MOD 1000000007

ll n,l,r, c0,c1,c2;
ll dp[200005][3];

ll f(ll x, ll r){
    if(x<0) return 0; // chequeo de bordes
    if(x==0 && r == 0) return 1; // caso final
    else if(x==0) return 0;
	if(dp[x][r]>=0)return dp[x][r]; // ya revisamos esta posicion
    
    dp[x][r] = (c0*f(x-1,r) + c1*f(x-1,(r+1)%3) + c2*f(x-1,(r+2)%3)) % MOD;

    return dp[x][r];
}

ll d(ll x, ll r){
    return (x+((3-r)%3))/3;
}

int main(){
    FIN;

    cin >> n >> l >> r;

    c0 = d(r,0) - d(l-1,0);
    c1 = d(r,1) - d(l-1,1);
    c2 = d(r,2) - d(l-1,2);


    memset(dp,-1,sizeof(dp));
    cout<<f(n,0)<<"\n";

}