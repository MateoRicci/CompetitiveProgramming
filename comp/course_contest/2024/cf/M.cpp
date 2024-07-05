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

struct Tree {
	typedef pair<ll,ii> T;
	static constexpr T neut = {0,{0,0}};
	T f(T a, T b){
        ll m = min(a.snd.fst, b.snd.snd);
        ll pval = a.fst + b.fst + m;
        ll sval = a.snd.fst + b.snd.fst - m;
        ll tval = a.snd.snd + b.snd.snd - m;
        return {pval,{sval,tval}}; 
    }
	vector<T> s; ll n;
	Tree(ll n = 0, T def = neut) : s(2*n, def), n(n) {}
	void upd(ll pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(ll b, ll e) { // query [b, e)
		T ra = neut, rb = neut;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


int main(){
    FIN;
    ll n,q;
    ll trash;
    cin >> n >> q;
    vector<ll> a(n), b(n), c(n-1);

    fore(i,0,n) cin >> a[i];
    fore(i,0,n) cin >> b[i];
    fore(i,0,n-1) cin >> trash;

    Tree st(n);
    
    fore(i,0,n){
        ll m = min(a[i],b[i]);
        ll v1 = a[i] - m;
        ll v2 = b[i] - m;
        pair<ll,ii> toupd = {m , {v1, v2}};
        st.upd(i,toupd);
    }

    // cout << "----creacion----\n";
    // fore(i,0,n){
    //     pair<ll,ii> kl = st.query(i,i+1);
    //     cout << kl.fst << " " << kl.snd.fst << " " << kl.snd.snd << "\n";
    // }
    // cout << "\n----------------\n";


    fore(i,0,q){
        ll au,bu,p;
        cin >> p >> au >> bu >> trash;
        p--;

        ll m = min(au,bu);
        pair<ll,ii> toupd = {m,{au-m, bu-m}}, res;


        // fore(i,0,n){
        //     pair<ll,ii> kl = st.query(0,i+1);
        //     cout << kl.fst << " ";
        // }
        // cout << "\n";

        st.upd(p,toupd);
        res = st.query(0,n);
        cout << res.fst << "\n";
    }


    

}


