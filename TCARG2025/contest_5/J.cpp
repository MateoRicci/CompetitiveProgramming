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
typedef pair<ll,ll> ii;

ll mod;

const ll MAXN = 505;
ll dp[MAXN][MAXN];

ll f(ll unos, ll doses){
    if(unos == 0 && doses == 0) return 1;
    if(dp[unos][doses] != -1) return dp[unos][doses];
    dp[unos][doses] = 0;
    if(unos >= 1 && doses >= 1){
        // show("NO ENTRAR");
        dp[unos][doses] += (unos*doses) * f(unos,doses-1) % mod;
    }
    if(unos >= 2){
        dp[unos][doses] += (unos*(unos-1)/2) * f(unos-2,doses) % mod;
    }
    if(doses >= 2){
        dp[unos][doses] += (doses*(doses-1)/2) * f(unos+2,doses-2) % mod;
    }
    dp[unos][doses] %= mod;
    return dp[unos][doses];
}

int main(){
    FIN;
    memset(dp,-1,sizeof(dp));
    ll t = 1;
    // cin >> t;
    while(t--){ 
        ll n,m; cin >> n >> m >> mod;
        ll unos = 0, dos = 0;
        vector<ll> columnas(n,0);
        fore(i,0,m){
            string s; cin >> s;
            fore(j,0,n){
                if(s[j]=='1') columnas[j]++;
            }
        }
        fore(i,0,n) {if(columnas[i] == 1) unos++; else if(columnas[i]==0) dos++;}
        // DGB(unos);
        // DGB(dos);
        ll res = f(unos,dos);
        // fore(i,0,n) fore(j,0,n) cout << dp[i][j] << "\n";
        //  = dp[unos][dos];
        cout << res % mod << "\n";
    }
}
