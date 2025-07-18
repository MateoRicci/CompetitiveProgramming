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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF = 1e9;
ll dp[105][20005];


int main(){
    FIN;
    ll n;
    cin >> n;
    vector<ll> a(n),b(n);
    fore(i,0,n){
        fore(A,0,20005){
            dp[i][A] = -INF;
        }
    }
    dp[0][0] = 0;
    ll sum_total = 0;
    // dp[cantidad de elementos][cantidad de suma acomulada] = cantidad de suma restante
    fore(i,0,n){
        cin >> a[i] >> b[i], a[i]*=2, b[i]*=2;
        sum_total += b[i];
        
        dfore(k,i,0){
            fore(A,0,k*200 + 2){
                ll x = dp[k][A];
                if(x<0) continue; // evito los que no calcule
                // cada elemento es el maximo entre lo que tenia siguiente y agregarme ami mas lo anterior
                dp[k+1][A+a[i]] = max(dp[k+1][A+a[i]], x + b[i]);
            }
        }
    }

    vector<ll> res(n+1);
    fore(k,1,n+1){
        fore(A,0,k*200 + 2){
            ll B = dp[k][A];
            if(B < 0) continue;
            res[k] = max(res[k], min(A, (sum_total + B)/2));
        }
    }

    // if(n==1){
    //     cout << res[1] << "\n";
    //     return 0;
    // }
    fore(k,1,n+1){
        if(res[k]%2){
            cout << res[k]/2 << ".5000000000\n";
        } else{
            cout << res[k]/2 << ".0000000000\n";
        }
        // cout << res[k]/2 << (res[k]%2) ? ".5\n":".0\n";
    }
    return 0;
};