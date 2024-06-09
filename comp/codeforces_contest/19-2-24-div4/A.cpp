#include <bits/stdc++.h> 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
using namespace std; 
typedef long long ll; 
#define fr(i,n) for (ll i=0;i<n;i++)

using namespace std;

int main(){
    FIN;

    int cant = 0;

    cin >> cant;

    while(cant--){
        int canta = 0;
        int cantb = 0;

        char letras[5];
        fr(i,5){
            cin >> letras[i];
            if (letras[i] == 'A'){
                canta++;
            }
            else if (letras[i] == 'B'){
                cantb++;
            }
        }
        if(canta > cantb){
            cout << 'A' << endl;
        }
        else{
            cout << 'B' << endl;
        }
    }
}