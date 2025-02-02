#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define show(a) cout<<a<<"\n"
#define showall(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define MAXN 200005
#define ALPH 26
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;

int main(){
    FIN;
    
    ll t; cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        string s1, s2;
        cin >> s1;
        cin >> s2;

        // encontrar para el a

        float ad = 0;
        fore(i,1,a+1){
            ad += (s1[i-1] - '0')/pow(10,i);
        }
        ll ax = pow(10,a);
        ll aj = ax;
        ll pot_a = pow(10,a);
        ll ajj = stoi(s1);
        ll ga = gcd(aj,ajj);
        aj = aj / ga;
        ajj = ajj / ga;
        // cout << "RES: " << ajj << " / " << aj << "\n";

        // ecnontrar para el b

        float bd = 0;
        fore(i,1,b+1){
            bd += (s2[i-1] - '0')/pow(10,i);
        }
        ll bx = pow(10,b);
        ll bj = bx - 1;
        ll pot_aux = pow(10,b);
        ll bjj = stoi(s2);
        ll gb = gcd(bj,bjj);
        bj = bj / gb;
        bjj = bjj / gb;
        bj *= pow(10,a);
        // cout << "RES: " << bjj << " / " << bj << "\n";

        // ecnontrar la fraccion final

        ll df = bj * aj;
        ll af = ajj * bj;
        ll bf = bjj * aj;
        ll nf = af + bf;
        ll gcdf = gcd(nf,df);
        df = df / gcdf;
        nf = nf / gcdf;
        cout << nf << " " << df << "\n";

    }

    return 0;
}

// sometimes I feel like I don't have a partner