#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

struct UF {
	vector<ll> e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

struct edges
{
    ll a;
    ll b;
    ll w;
    ll index;
};

bool compare(edges a, edges b){
    return(a.w < b.w);
}


int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<edges> a(n);
        fore(i,0,n){
            cin >> a[i].a >> a[i].b;
            a[i].w = a[i].b - a[i].a; // los de mayor distancia son los que voy a querer sacar
            a[i].index = i;
        }
        sort(ALL(a),compare);
        UF uf(2*(n+1));
        vector<ll> res;
        for(auto e : a){
            if(uf.join(e.a,e.b)){ // si cuando lo agrego no me genera un ciclo
                ll in = e.index + 1;
                res.pb(in);
            }
        }
        // ahora la f(S) es el size de la cantidad de aristas que use g(S) es 0
        cout << SZ(res) << "\n";
        showAll(res);
    }
}
