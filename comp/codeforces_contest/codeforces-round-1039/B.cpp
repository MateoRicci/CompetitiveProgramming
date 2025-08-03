#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n);
        input(a);
        ll i = 1, j = n-1;
        string res;
        ll last_used = 0;
        bool greater = false;
        if(a[0] < a[i] && a[0] < a[j]) greater = true;
        res.pb('L');
        while(i<=j){
            if(greater){
                // pongo uno mas grande
                if(a[i] > a[last_used]){
                    // puedo poner i, pero quiero ver cual me conviene poner, si izq o derecha
                    if(a[i] > a[j]){
                        res.pb('L');
                        last_used = i;
                        i++;
                        greater = false;
                    } else{
                        res.pb('R');
                        last_used = j;
                        j--;
                        greater = false;
                    }
                } else if(a[j] > a[last_used]){
                    // tengo q poner este pq a[i] no es mayor
                    res.pb('R');
                    last_used = j;
                    j--;
                    greater = false;
                } else{
                    // tenia que poner mayor, pero no hay, entonces pongo el menor de los 2 y despues corrijo
                    if(a[i] < a[j]){
                        res.pb('L');
                        last_used = i;
                        i++;
                    } else{
                        res.pb('R');
                        last_used = j;
                        j--;
                    }
                }
            } else{
                // pongo uno mas chico
                if(a[i] < a[last_used]){
                    // puedo poner i, pero quiero ver cual me conviene poner, si izq o derecha
                    if(a[i] < a[j]){
                        res.pb('L');
                        last_used = i;
                        i++;
                        greater = true;
                    } else{
                        res.pb('R');
                        last_used = j;
                        j--;
                        greater = true;
                    }
                } else if(a[j] < a[last_used]){
                    // tengo q poner este pq a[i] no es menor
                    res.pb('R');
                    last_used = j;
                    j--;
                    greater = true;
                } else{
                    // tenia que poner menor, pero no hay, entonces pongo el mayor de los 2 y despues corrijo
                    if(a[i] > a[j]){
                        res.pb('L');
                        last_used = i;
                        i++;
                    } else{
                        res.pb('R');
                        last_used = j;
                        j--;
                    }
                }
            }
        }
        // DGB(SZ(res));
        cout << res << "\n";
    }
}
