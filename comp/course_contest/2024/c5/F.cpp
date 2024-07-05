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

const ll MOD=998244353;

ll mult(ll n, ll t){
	ll res=1;
	fore(i,0,t) res*=n;
	return res;
}


ll sqr4(ll n){
    ll aux = sqrt(sqrt(n))-3;
    while(aux<0 || mult(aux,4)<n)aux++; // chequeo < 0 pq la resta de 3 se puede pasar a negativo
	if(mult(aux,4)==n)return aux;
	return -1;
}

ll cubert(ll n){
    ll aux = cbrt(n)-3;
    while(aux<0 || mult(aux,3)<n)aux++;
	if(mult(aux,3)==n)return aux;
	return -1;
}

ll sqr2(ll n){
    ll aux = sqrt(n)-3;
    while(aux<0 || mult(aux,2)<n)aux++;
	if(mult(aux,2)==n)return aux;
	return -1;
}

ll mul(ll a, ll b){
	return a*b%MOD;
}

int main(){
    FIN;

    ll n;
    cin >> n;

    vector<ll> a(n);
    fore(i,0,n){
        cin >> a[i];
    }

    map<ll,ll> perfect;
    map<ll,ll> to_check;

    fore(i,0,n){
        if(sqr4(a[i])!= -1){
            perfect[sqr4(a[i])]+= 4; // sumo un p^4 :)
        }
        else if(cubert(a[i])!= -1){
            perfect[cubert(a[i])] += 3; // sumo un cubo perfecto
        }
        else if(sqr2(a[i])!= -1){
            perfect[sqr2(a[i])] += 2; // sumo un cuadrado perfecto
        }
        else{ // y ahora de que nos disfrazamos
            to_check[a[i]] ++; // la mandamos al corner
        }
    }

    ll res = 1;

    for(auto i : to_check){
        ll apear = 0;
        fore(j,0,n){
            ll g = __gcd(i.fst, a[j]); 
            if(g != 1 && g != i.fst){ // chequeo q sean divisibles (!= 1) y (!= si mismo)
                perfect[g] += i.snd; // le sumo las apariciones en g
                perfect[i.fst/g] += i.snd; // le sumo las pariciones en su division
                apear++;
                break;
            }
        }
        if(apear==0){ // si no aparece multiplico la cantidad de veces q aparece
            // res = mul(i.snd+1, i.snd+1);
            res *= (i.snd+1) * (i.snd+1); //(2*2) de edu = (apariciones + 1) ^2)
            res %= MOD;
        }
    }

    for(auto p : perfect){
        // res = mul(res,p.snd);
        res *= (p.snd+1); // + 1 por (e+1)
        res %= MOD;
    }

    cout << res << "\n";

}

