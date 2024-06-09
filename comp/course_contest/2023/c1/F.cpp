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


    // fore(i,0,SZ(v)){
    //     if(v[i].snd<nn){
    //         return 0;
    //     }
    // }

int main(){
    FIN;

    ll n,m;
    cin >> n >> m;
    int* prb = new int[n];
    fore(i,0,n){
        prb[i] = 0;
    }
    int a;
    int q = 1;
    fore(i,0,m){
        cin >> a;
        prb[a-1] += 1;
        int res = 0;
        if(i+1>=n){
            res = 1;
            fore(j,0,n){
                if(prb[j] < q){
                    res = 0;
                    break;
                }
            }
        }
        if(res == 0){
            cout << 0;
        }
        else{
            cout << 1;
            q++;
        }
    }
    cout << "\n";

}