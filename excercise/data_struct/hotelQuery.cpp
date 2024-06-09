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
	typedef ll T;
	static constexpr T neut = LONG_LONG_MIN;
	T f(T a, T b) { return max(a,b);} // (any associative fn)
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

    ll n,m;
    cin >> n >> m;
    Tree num(n);
    fore(i,0,n){
        ll h; cin >> h;
        num.upd(i,h);
    }
    vector<ll> tur(n);
    fore(i,0,m) cin >> tur[i];

    vector<ll> res;
    fore(i,0,m){
        ll aux;
        if(num.query(0,n)<tur[i]){
            aux=0;
        }else{
            ll l=0,r=n,mid;
            while(l+1<r){
                mid = (l+r)/2;
                ll aux2 = num.query(l,mid);
                if(aux2>=tur[i]){
                    r=mid;
                    aux=mid;
                }
                else{
                    l=mid;
                }
            }
            ll cant = num.query(mid-1,mid);
            num.upd(mid-1,(cant-tur[i]));
        }
        res.pb(aux);
    }
    fore(i,0,SZ(res)){
        cout << res[i] << " ";
    }
    cout << "\n";
    
}