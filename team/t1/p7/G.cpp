#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN 10005
#define ALPH 26
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const ll MOD = 1000000007;

const ll MOD=998244353; // o 1e9+7

ll add(ll a, ll b){
	a+=b;
	if(a>=MOD)a-=MOD;
	return a;
}

ll sub(ll a, ll b){
	a-=b;
	if(a<0)a+=MOD;
	return a;
}

ll mul(ll a, ll b){
	return a*b%MOD;
}

ll fpow(ll a, ll b){ // iterativa (mas rapida)
	ll res=1;
	while(b>0){
		if(b%2==1){
			res=(res*a)%MOD;
		}
		a=(a*a)%MOD,b/=2;
	}
	return res;
}

ll binpow(ll a, ll b){ // recursiva
	if(b==0)return 1;
	ll r=binpow(a,b/2);
	if(b%2==1)return r*r%MOD*a%MOD;
	return r*r%MOD;
}

ll fc[MAXN],fci[MAXN];

void factoriales(){
	fc[0]=1;
	fore(i,1,MAXN)fc[i]=mul(fc[i-1],i);
	fci[MAXN-1]=fpow(fc[MAXN-1],MOD-2);
	for(ll i=MAXN-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
}

ll comb(ll n, ll k){
	return mul(fc[n],mul(fci[k],fci[n-k]));
}


int main(){
    FIN;

    ll n; // cant rondas
    ll m; // puntaje maximo por ronda
    ll p1,p2; // puntaje esperado de cada equipo

}
