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

ll n;
ll dp[1000000005];

ll f(ll x,ll i, vector<ii> &d){
    if(i>=n) return 0; // chequeo de bordes, si un salto se pasa de n es pq ese bloque no es valido
    if(x == 0) return 0;
	if(dp[x]>=0) return dp[x]; // ya revisamos esta posicion
    if(dp[x] > d[i].snd) dp[x] = f(x,i+1,d);
    else{    
        dp[x] = 2 + f(x-d[i].fst,i,d);
    }
    return dp[x];
}



int main(){
    FIN;
    ll m; cin >> n >> m;
    vector<ll> a(n),b(n),c(m);
    vector<ii> d(n);
    fore(i,0,n){
        cin >> a[i];
    }
    fore(i,0,n){
        cin >> b[i];
        d[i] = {a[i] - b[i], a[i]};
    }
    fore(i,0,m){
        cin >> c[i];
    }

    sort(ALL(d));

    ll exp = 0;
    memset(dp,-1,sizeof(dp));

    fore(i,0,m){
        exp += f(c[i],0,d);
    }

    cout << exp << "\n";
}
