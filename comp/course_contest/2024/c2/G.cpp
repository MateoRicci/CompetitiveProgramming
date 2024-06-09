#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
    FIN;
    ll n, res= 0;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll> > pq; // pq de tipo long long, funciona como vector, greater => menor a mayor
    ll s = 0;

    fore(i,0,n){
        ll x; cin >> x;
        s+=x;
        pq.push(x);

        while(s<0){ // si estoy sin vida voy a quitar cosas negativas hasta volver a tener vida(primero quitando las mas grandes)
            s-= pq.top();
            pq.pop();
        }
    }

    res = SZ(pq);
    cout << res << endl;

}