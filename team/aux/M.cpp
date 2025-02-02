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
        ll n; cin >> n;
        vector<pair<ll,pair<ll,ll>>> p(n);
        fore(i,0,n){
            cin >> p[i].snd.snd;
            p[i].snd.fst = i;
        }
        fore(i,0,n){
            cin >> p[i].fst;
        }
        sort(all(p));
        fore(i,0,n){
            cout << p[i].snd.snd << " ";
        }
        cout << "\n";
    }

    return 0;
}

// muchas gracias penazzi