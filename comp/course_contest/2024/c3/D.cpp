
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
ll a[200005];
ll dp[200005];

ll f(ll x){
    if(x>n) return 1e9; // chequeo de bordes, si un salto se pasa de n es pq ese bloque no es valido
    if(x==n) return 0; // caso final
	if(dp[x]>=0)return dp[x]; // ya revisamos esta posicion
    
    dp[x] = min(1 + f(x+1), f(x+a[x]+1));

    return dp[x];
}

int main(){
    FIN;
    ll t;
    cin >> t;
    while(t--){

        cin>>n;
        fore(i,0,n){
            cin >> a[i];
        }
        memset(dp,-1,sizeof(dp));
        cout<<f(0)<<"\n";

    }
}

/*
que puedo hacer:
1- elegir no quitar el numero k y saltar k veces en el arreglo
2- quitar ese numero sumar 1 y volver a lo mismo
*/