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

#define oper(a,b) min(a,b)
#define NEUT LONG_LONG_MAX
struct STree { // segment tree for oper over lls
	vector<ll> st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void init(ll k, ll s, ll e, vector<ll> &a){
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]=v;return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(vector<ll> &a){init(1,0,n,a);}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

ll sd(ll numero) {
    string numeroStr = to_string(numero);
    ll suma = 0;
    for(char digito : numeroStr) {
        suma += digito - '0';
    }
    return suma;
}


int main(){
    FIN;
    ll t; cin >> t;
    while(t--){
        ll n,q; cin >> n >> q;
        vector<ll> a(n),b(n);
        fore(i,0,n){
            cin >> a[i];
            b[i] = i;
        }
        STree rmq(n);
        rmq.init(b);
        // fore(i,0,n) cout << rmq.query(i,i+1);

        while(q--){
            ll k; cin >> k;
            if(k==1){
                ll x,y; cin >> x >> y;
                x--;
                ll aux = x;
                while(aux < y){
                    aux = rmq.query(aux,y);
                    if(aux < n){
                        a[aux] = sd(a[aux]);
                        if(a[aux] < 10) rmq.upd(aux,LONG_LONG_MAX);
                        aux++;
                    }
                }

            } else{
                ll x; cin >> x;
                x--;
                cout << a[x] << "\n";

            }
        }
        
    }
}