#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
    FIN;

    ll t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        string a;
        cin >> a;
        int res = 0;
        fore(l,0,n){
            int a_n[10] = {0,0,0,0,0,0,0,0,0,0};
            int dif = 0;
            fore(r,l,(min(n,l+100))){
                int index = a[r] - 48;
                a_n[index] += 1;
                if(a_n[index] == 1){
                    dif += 1;
                }
                bool res_aux = true;
                fore(k,0,10){
                    if(a_n[k]>dif){
                        res_aux = false;
                    }
                }
                if(res_aux){
                    res += 1;
                }
                //cout << index << " " << dif << " " << res << endl;
            }
        }
        // 399996
        cout << res << endl;
    }
}


// numeros diversos
// #num dist >= ocurrencias cualquier num
// max #num dist = 10 
// 10 >= ocurrencias cualquier num
// for  l n
//     for r l min n l+100
//         voy chequeando
// 1010
// l
// r
//  r
//   r
//    r
