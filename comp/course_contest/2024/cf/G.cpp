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

int main(){
    FIN;

    ll t; cin >> t;
    while(t--){

        ll n; cin >> n;
        ll a = 0,b = 0,c = 0;
        bool flag = true;
        // buscamos el primer divisor q es siempre primo
        for(ll i = 2; i*i <= n && flag; i++) { // O(sqr(n))
            if(n%i==0){
                a = i;
                flag = false;
            }
        }
        if(a==0 || a == n){
            // n es primo
            cout << "NO\n";
            // cout << a << " " << b << " " << c << "N1\n";
        }
        else{
            // buscamos el segundo divisor
            // si es primo ya esta, si no existe seran todos multiplos de a?
            
            flag = true;        
            for(ll i = a+1; i*i <= n && flag; i++) { // O(5 10e8)
                if(n%i==0 && i%a!=0){ // primo
                    b = i;
                    flag = false;
                }
            }
            if(b==0){ // no existe divisor primo
                b = a*a; // a solo es el divisor de n, pruebo con esto q deberia estar si o si
                // si solo n tiene un solo numero primo q lo divide
            }
            
            c = n / (a*b);
            if(a*b*c == n && c > 1 && a !=c && b != c){
                cout << "YES\n";
                cout << a << " " << b << " " << c << "\n";
            }
            else{
                cout << "NO\n";
            }

        }


    }

}