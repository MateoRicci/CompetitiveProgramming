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
        ll x,y;
        cin >> x >> y;

        ll res = 0;

        if (y%2==0 || y==0){
            ll temp = y/2; //pantallas para la y
            res = temp;
            ll temp_x = x - temp*7; // veo si me alcanza para las x

            if(temp_x>0){
                res += temp_x/15;
                if(temp_x%15!= 0){
                    res++;
                }
            }
        }else{
            ll temp = (y-1)/2; //pantallas para la y
            res = temp + 1;
            ll temp_x = x - temp*7 - 11;
            if(temp_x>0){
                res += temp_x/15;
                if(temp_x%15!= 0){
                    res++;
                }
            }
        }   
        cout << res << "\n";
    }

}