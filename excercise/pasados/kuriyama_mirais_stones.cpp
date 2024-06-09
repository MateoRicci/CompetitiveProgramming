#include <bits/stdc++.h>
#define ll long long
#define fr(i,n) for (ll i=0;i<n;i++)
using namespace std;
/*
3 lineas de input
primera linea n
segunda linea n numeros, son los vi costos de las piedras
tercera linea m numero de preguntas

ahora tendremos type l r, donde type=1 -> usa los vi y type=2 -> usa los vi ordenados
l y r son los indices de las piedras que se usaran

6 4 2 7 2 7
0 6 10 12 19 21 28
1 3 6 10 15

*/
int main(){
    ll n = 0;
    cin >> n;
    vector<ll> stn;
    vector<ll> stns;
    vector<ll> v;
    vector<ll> u;
    v.push_back(0);
    u.push_back(0);

    fr(i,n){
        ll val;
        cin >> val;
        stn.push_back(val);
        stns.push_back(val);
        v.push_back(val + v[i]);
        
    }
    sort(stns.begin(), stns.end());
    fr(i,n){
       u.push_back(u[i] + stns[i]);
    }
    ll m;
    cin >> m;
    while(m--){
        ll type, l, r;
        cin >> type >> l >> r;
        if(type == 1){
            cout << v[r] - v[l-1] << endl;
        } 
        else if(type == 2){
            cout << u[r] - u[l-1] << endl;
        }
    }

}

//solucion antigua, esta paso de pedo
/*
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m, l, r, q, answer;
    cin >> n;
 
    long long v[n + 1];
    long long u[n + 1];
 
    v[0]=0;
    u[0]=0;
 
    for (int i = 1; i<n+1;i++){
        cin >> v[i];
        u[i] = v[i];
        v[i] += v[i-1];
    }
 
    cin >> m;
    std::sort(u, u + (n+1));
 
    for(long long i =1; i<n+1; i++){
        u[i] = u[i] + u[i-1]; 
    }
 
    while(m--){
        cin >> q;
        cin >> l;
        cin >> r;
 
        if (q==1){
            answer = v[r] - v[l-1];
        }
        else{
            answer = u[r] - u[l-1];
        }
        cout << answer << "\n";
    }
}
*/