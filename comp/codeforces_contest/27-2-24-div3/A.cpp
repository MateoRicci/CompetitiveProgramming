#include <bits/stdc++.h> 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
using namespace std; 
typedef long long ll; 
#define fr(i,n) for (ll i=0;i<n;i++)

using namespace std;

int main(){
    FIN;

    int t = 0;

    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int sum = 0;
        int a[n];
        fr(i,n){
            int aux;
            cin >> aux;
            a[i] = aux;

            if(aux<0){
                sum += (-aux);
            }
            else{
                sum += aux;
            }
        }
        cout << sum << endl;

    }
}