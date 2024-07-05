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

bool can(ll m, vector<ll> a){
    ll ptr = 0;
    ll workers = 1;
    fore(i,0,SZ(a)){
        if(abs(a[i] - a[ptr]) > 2*m){ // 2m porque algun valor en el medio va a ser el patron, no importa cual
            // recorro el arreglo, viendo si me alcanza con 3 trabajadores para hacer los juguetes en tiempo m
            ptr = i;
            workers++;
        }
    }

    return workers<=3;
}


int main(){
    FIN;

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n);
        fore(i,0,n) cin >> a[i];
        sort(ALL(a));

        ll l = 0, r = 10e15;
        while(l<=r){
            ll m = (l + r) / 2;
            if(can(m,a)) r = m-1;
            else l = m + 1;
        }

        cout << l << "\n";
    }

}

