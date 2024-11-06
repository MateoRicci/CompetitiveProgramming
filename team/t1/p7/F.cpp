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
#define MAXN 200005
#define ALPH 26
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;


struct Tree {
	typedef ll T;
	static constexpr T neut = 0;
	T f(T a, T b) {
        return a + b;
    } // (any associative fn)
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


//El Vasito is love, El Vasito is life

void solve(){
    ll n; cin >> n;
    Tree s(MAXN), e(MAXN);
    vector<pll> posid(MAXN, {-1,-1});
    ll currid = 1;
    ll tot = 0;
    fore(i,0,n){
        ll t; cin >> t;
        if(t==1){
            ll a,b,v;
            cin >> a >> b >> v;
            b--;
            s.upd(a,v);
            e.upd(b,v);
            tot += v;
            posid[currid] = {a,b};
            currid++;
        }
        if(t==2){
            ll k; cin >> k;
            tot -= s.query(posid[k].fst,posid[k].fst+1);
            s.upd(posid[k].fst,0);
            e.upd(posid[k].snd,0);
        }
        if(t==3){
            ll a,b;
            cin >> a >> b;
            // DGB(tot);
            ll res = tot - e.query(0,a) - s.query(b,MAXN);
            cout << res << "\n";
        }
    }
}

int main(){
    FIN;
    int t = 1;
    // cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo

// st de pair <val,id> 
