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
const ll MOD = 1e9 + 7;

ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll a, ll b){
	if(b<0)return 0;
	ll r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

int main(){
    FIN;
    ll n,k; cin >> n >> k;
    vector<pll> a(n);
    fore(i,0,n) cin >> a[i].fst;
    fore(i,0,n) cin >> a[i].snd;
    sort(ALL(a));
    reverse(ALL(a));

    ll qmod = fpow(1000LL,k);
    
    ll pmod = 1;
    fore(i,0,k) pmod = mul(pmod,a[i].snd);
    fore(i,k,n){
        if(a[i].fst == a[k-1].fst){
            pmod = mul(pmod,a[i].snd);
            qmod = mul(qmod,1000L);
        }
    }

    ll qinv = fpow(qmod,MOD-2LL);
    ll x = mul(pmod,qinv);
    cout << x << "\n";
}
