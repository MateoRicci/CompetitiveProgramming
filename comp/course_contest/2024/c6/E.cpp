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

#define oper min
int st[K][1<<K];int n;  // K such that 2^K>n
void st_init(vector<ll> &a){
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}


int main(){
    FIN;
    ll t; cin >> t;
    while(t--){
        ll n,q; cin >> n >> q;
        vector<ll> a(n);
        fore(i,0,n){
            char aux; cin >> aux;
            if(aux=='+') a[i] = 1;
            else a[i] = -1;
        }
        Tree rmq(a);
        Tree rmq2(a);

        while(q--){
            ll res = 1;

            
            
            cout << res << "\n";
        }

    }

}