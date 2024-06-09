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
typedef pair<ll,ll> ii;


int main(){
    FIN;
    ll t; cin >> t;

    while(t--){
        ll p1,p2,p3;
        cin >> p1 >>p2 >> p3;
        ll sum = p1+p2+p3;
        ll res = 0;

        if(sum%2==1){
            cout << -1 << "\n"; // resultado no valido, siempre se reparten 2 puntos
        }
        else{
            if((p1+p2)>p3){
                while(p1>0){
                    res++;
                    if(p3>p2){
                        p1--;
                        p3--;
                    }else{
                        p1--;
                        p2--;
                    }
                }
                while(p2>0 && p3>0){
                    res++;
                    p2--;
                    p3--;
                }

            }else{
                res = p1+p2;
            }
            cout << res << "\n";
        }

    }


}