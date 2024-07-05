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


struct Tree { // example: range sum with range addition
	typedef ii T; typedef ll L; // T: data type, L: lazy type
	// neutrals
	constexpr static T tneut = {LONG_LONG_MAX,0}; constexpr static L lneut = 0;
	T f(T a, T b) { return min(a,b); } // operation
	// new st according to lazy
	T apply(T v, L l, ll s, ll e){
        return {v.fst+l,v.snd};
    }
	// cumulative effect of lazy
	L comb(L a, L b){
        return a + b;
    }
	ll n;
	vector<T> st;
	vector<L> lazy;
	Tree(ll n) : n(n), st(4*n, tneut), lazy(4*n, lneut) {}
	Tree(vector<T> &a) : n(SZ(a)), st(4*n), lazy(4*n, lneut) {
		init(1, 0, n, a);
	}
	void init(ll k, ll s, ll e, vector<T> &a) {
		lazy[k] = lneut;
		if (s + 1 == e) { st[k] = a[s]; return; }
		ll m = (s + e) / 2;
		init(2*k, s, m, a), init(2*k+1, m, e, a);
		st[k] = f(st[2*k], st[2*k+1]);
	}
	void push(ll k, ll s, ll e) {
		if (lazy[k] == lneut) return; // if neutral, nothing to do
		st[k] = apply(st[k], lazy[k], s, e);
		if (s + 1 < e) { // propagate to children
			lazy[2*k] = comb(lazy[2*k], lazy[k]);
			lazy[2*k+1] = comb(lazy[2*k+1], lazy[k]);
		}
		lazy[k] = lneut; // clear node lazy
	}
	void upd(ll k, ll s, ll e, ll a, ll b, L v) {
		push(k, s, e);
		if (s >= b || e <= a) return;
		if (s >= a && e <= b) {
			lazy[k] = comb(lazy[k], v); // accumulate lazy
			push(k, s, e);
			return;
		}
		ll m = (s + e) / 2;
		upd(2*k, s, m, a, b, v), upd(2*k+1, m, e, a, b, v);
		st[k] = f(st[2*k], st[2*k+1]);
	}
	T query(ll k, ll s, ll e, ll a, ll b) {
		if (s >= b || e <= a) return tneut;
		push(k, s, e);
		if (s >= a && e <= b) return st[k];
		ll m = (s + e) / 2;
		return f(query(2*k, s, m, a, b),query(2*k+1, m, e, a, b));
	}
	void upd(ll a, ll b, L v) { upd(1, 0, n, a, b, v); }
	T query(ll a, ll b) { return query(1, 0, n, a, b); }
};

int main(){
    FIN;

    ll n,m,w;
    cin >> n >> m >> w;
    vector<ii> a(n);

    fore(i,0,n){
        cin >> a[i].fst;
        a[i].snd = i;
    }

    Tree st(a);
    
    fore(i,0,m){
        // cout << "dia: " << i << "\n";
        // cout << "plantas: ";
        // fore(j,0,n) cout << st.query(j,j+1) << " ";
        // cout << "\n";


        //ahora en mid tengo la posicion de la primera minima planta.
        // entonces tengo que regar desde la planta hacia la derecha
        // primero chequear que no me vaya de rango
        ii aux = st.query(0,n);
        ll fmin = aux.snd;
        if(fmin+w > n) fmin = n-w;

        st.upd(fmin, fmin + w, 1);
    }
    ii aux = st.query(0,n);
    ll res = aux.fst;
    cout << res << "\n";
}