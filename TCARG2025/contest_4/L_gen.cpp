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

random_device rd;
mt19937 rng(rd());

int main(){
    FIN;
    ll N, M, A; cin >> N >> M >> A;
    ll n = rng()%N; // la cantidad de puntos
    n++;
    ll l = rng()%M;
    ll r = rng()%M;
    l -= r;
    cout << n << " " << l << " " << r << "\n";

    fore(i,0,n){
        ll x = rng()% (2*M);
        x-=M;
        ll y = rng()%M;
        ll a = rng()%A;
        a++;
        cout << x << " " << y << " " << a << "\n";
    }
    return 0;
}