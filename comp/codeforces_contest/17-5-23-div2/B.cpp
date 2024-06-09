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

#define oper(a,b) ((a)|(b))
const ll K=18;
ll st[K][1<<K];  // K such that 2^K>n
void st_init(vector<ll> &a){
	fore(i,0,SZ(a))st[0][i]=a[i];
	fore(k,1,K)fore(i,0,SZ(a)-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
ll st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}

// ll BOR(const vector<ll>& a, ll i, ll j) {
//     ll result = 0;
//     for (ll k = i; k <= j; ++k) {
//         result |= a[k];
//     }
//     return result;
// }

// bool can(vector<ll> &a,ll k,ll n){
//     bool res = true;
//     ll i = 0, j = k-1;
//     ll prev = BOR(a,i,j);
//     i++,j++;
//     while(j<n && res){
//         ll aux = BOR(a,i,j);
//         if(!(prev == aux)){
//             res = false;
//         }
//         else{
//             i++;
//             j++;
//             prev = aux;
//         }
//     }
//     return res;
// }

int main(){
    FIN;

    ll t;cin >> t;
    while(t--){

        ll n; cin >> n;
        vector<ll> a;

        fore(i,0,n){
            ll aux;
            cin >> aux;
            a.pb(aux);
        }

        st_init(a); // inicio mi segment tree
        ll x = 0;
        for(auto i:a)x=(x|i); // x es el mayo numero posible de or

        ll res;
        ll l = 1, r = n, m;
        while(l <= r) {
            m = (l+r)/2;
            ll can = 1;
            fore(i,0,n-m+1){ // recorro mi arreglo de posibilidades
				if(st_query(i,i+m)!=x)can=0; // si se cumple el query de i hasta j(j= i+m)
			}
            if (can){
                res = m;;
                r = m-1;
            }
            else l = m+1;
        }
        cout << res << "\n";
    }
}
