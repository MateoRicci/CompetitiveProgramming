#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

//PRECALCULAR LA CANTIDAD DE NODOS HASTA N

int main(){
    FIN;
    ll n,k; cin >> n >> k;

    vector<ll> lu(k);
    ll max_pos = 0;
    fore(i,0,k){
        ll aux; cin >> aux;
        lu[i] = aux;
        if(lu[i] > lu[max_pos]) max_pos = i;
    }

    vector<ll> fibo(n);
    fibo[0] = 1;
    fibo[1] = 1;
    fore(i,2,n){
        fibo[i] = fibo[i-1] + fibo[i-2] + 1;
    }

    if(fibo[n-1] < k){
        cout << "N\n";
        return 0;
    }

    if(max_pos < k-1 && max_pos > 0){
        //me fijo la izquierda
        if(lu[max_pos] - lu[max_pos-1] > 2 || lu[max_pos] - lu[max_pos-1] < 1){
            cout << "N\n";
            return 0;
        }

        //me fijo la derecha
        if(lu[max_pos] - lu[max_pos+1] > 2 || lu[max_pos] - lu[max_pos+1] < 1){
            cout << "N\n";
            return 0;
        }

        if(lu[max_pos-1] == lu[max_pos+1]){
            cout << "N\n";
            return 0;     
        }

    } else if(max_pos==0){
        if(lu[max_pos] - lu[max_pos+1] > 2 || lu[max_pos] - lu[max_pos+1] < 1){
            cout << "N\n";
            return 0;
        }
    } else if(max_pos==k-1){
        if(lu[max_pos] - lu[max_pos-1] > 2 || lu[max_pos] - lu[max_pos-1] < 1){
            cout << "N\n";
            return 0;
        }
    } else{

        fore(i,max_pos+1,k-1){
            if(lu[i] - lu[i+1] > 2 || lu[i] - lu[i+1] < 1){
                cout << "N\n";
                return 0;
            }
        }
        dfore(i,max_pos-1,1){
            if(lu[i] - lu[i-1] > 2 || lu[i] - lu[i-1] < 2 ){
                cout << "N\n";
                return 0;
            }
        }



    }

    
    cout<< "S\n";
    return 0;
}

// Cueste lo que cueste el sabado tenemos que ganar