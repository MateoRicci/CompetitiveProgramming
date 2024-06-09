
#include <bits/stdc++.h> 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
using namespace std; 
typedef long long ll; 
#define fr(i,n) for (ll i=0;i<n;i++)

using namespace std;

const int MAXN=2e5+10;
int a[MAXN];

int main(){
    FIN;
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int* a = new int[n];

        int p1bool = 0;
        int sum = 0;

        fr(i,n){
            int aux;
            cin >> aux;
            a[i] = aux;

            if(a[i]%3==1){
                p1bool=1;
            }
            sum+=a[i];
        }
        int resto = sum%3;
        if(resto == 0){
            cout << 0 << endl;
        }
        else if(resto == 1){
            if(p1bool){
                cout << 1 << endl;
            }
            else{
                cout << 2 << endl;
            }
        }
        else{
            cout << 1 << endl;
        }

    }
}