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

const ll MAXN = 20000005;

int cr[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
    memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0)for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=i;
}
map<int,int> fact(int n){  // must call init_cribe before
	map<int,int> r;
	while(cr[n]>=0)r[cr[n]]++,n/=cr[n];
	if(n>1)r[n]++;
	return r;
}

int main(){
    FIN;

    init_sieve();
    
    ll t; cin >> t;
    while(t--){
        ll c,d,x;
        cin >> c >> d >> x;
        ll res = 0;
        for(ll i = 1; i*i <= x ; i++){ // i = possible g
            if(x%i!=0) continue; //si g no es divisor paso
            ll k = x / i + d;
            if(k%c==0){ // c divide a k, entonces buscamos la cantidad de (a,b)

            }
            
        }
    }
}