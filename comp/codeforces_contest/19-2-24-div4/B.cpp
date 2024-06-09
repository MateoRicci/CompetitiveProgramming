#include <bits/stdc++.h> 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
using namespace std; 
typedef long long ll; 
#define fr(i,n) for (ll i=0;i<n;i++)

using namespace std;

int main(){
    FIN;

    ll t;
    cin >> t;
    while (t--){

        int n;
        cin >> n;

        int* sums = new int[n];
        fr(i,n){
            cin >> sums[i];
        }
        int res;
        int prev = 0;
        fr(i,n){
            if (sums[i] != 0 && prev == 0){
                prev = sums[i];
            }
            else if (sums[i] != 0 && prev != 0){
                if (prev == sums[i]){
                    res = 1;
                }
                else{
                    res = 2;
                }
            }
        }


        if (res == 1){
            cout << "SQUARE" << endl;
        }
        else{
            cout << "TRIANGLE" << endl;
        }
    }

}