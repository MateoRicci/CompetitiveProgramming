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

bool can(vector<ll> &p, ll x, ll a, ll y, ll b, ll m, ll k){

    ll cXY = 0, cX = 0, cY = 0, res = 0;

    set<ll> entradas;

    fore(i,1,m+1){
        if(i%a == 0 && i%b == 0) cXY++;
        else if(i%a == 0) cX++;
        else if(i%b == 0) cY++;  
    }

    fore(i,0,cXY) res += (p[i] * (x+y))/100; // nunca se va a pasar de rango aca
    fore(i,0,cX){
        if((i + cXY)<m){; // cehqueamos que no se pase
            res += (p[i + cXY] * x)/100; 
        }
    }
    fore(i,0,cY){ 
        if((i + cXY + cX)<m){ // chequeamos que no se pase
            res += (p[i + cXY + cX] * y)/100;
        }
    }

    if(res >= k){
        return true;
    } else{
        return false;
    }

    // cehqueamos primero las posiciones q comparten x e y
    // chequeamos primero las posiciones del max(x,y)
    // chequeamos primero las posiciones del min(x,y)

}

int main(){
    FIN;

    ll q;
    cin >> q;
    while(q--){
        ll n,x,y,a,b, k;
        cin >> n;
        vector<ll> p(n);
        fore(i,0,n){
            ll aux;
            cin >> aux;
            p.push_back(aux);
        }
        cin >> x >> a;
        cin >> y >> b;
        cin >> k;
        sort(p.begin(),p.end());
        reverse(p.begin(),p.end());

        ll x_max, a_max, y_min, b_min;
        if(x<y){
            x_max = y; a_max = b; y_min = x; b_min = a;
        }
        else{
            x_max = x; a_max = a; y_min = y; b_min = b;
        }


        ll l = 1, r = n, m, res=-1;
        while(l <= r) {
            m = (l+r)/2;
            if (can(p,x_max,a_max,y_min,b_min,m,k)){
                res = m;;
                r = m-1;
            }
            else l = m+1;
        }
        cout << res << "\n";

    }

}