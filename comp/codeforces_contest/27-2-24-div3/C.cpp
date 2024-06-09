#include <bits/stdc++.h> 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
using namespace std; 
typedef long long ll; 
#define fr(i,n) for (ll i=0;i<n;i++)

using namespace std;

bool existeEnVector(const vector<int> vec, int numero) {
    // Verificar si el número existe en el vector
    for (int elemento : vec) {
        if (elemento == numero) {
            return true;  // El número ya existe en el vector
        }
    }
    return false;  // El número no existe en el vector
}


int main(){
    FIN;
    int t = 0;
    cin >> t;
    while(t--){
        int a,b,l;
        cin >> a >> b >> l;
        int res = 0;
        double logaux;
        int maxi, maxj;
        logaux = log(l) / log(a);
        maxi = ceil(logaux) + 2;
        logaux = log(l) / log(b);
        maxj = ceil(logaux) + 2;
        int k;
        vector<int> vec;

        for(int i = 0; i < maxi ; i++){
            for(int j = 0; j < maxj; j++){
                int aux = pow(a,i)*pow(b,j);
                if(l%aux==0){
                    k = l/aux;
                    if(!existeEnVector(vec,k)){
                    vec.push_back(k);
                    res += 1;
                    }
                }
            }
        }

        cout << res << endl;     
    }
}