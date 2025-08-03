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
const ll MAXN = 2505;
ll dp[MAXN][MAXN];

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll a, ll b){
	if(b<0)return 0;
	ll r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

ll kneed;
ll kcant;
ll f(ll i, ll pos, vector<pll> &a){
    if(pos > kneed) return 0;
    if(i > kcant){
        if(pos == kneed) return 1;
        return 0;
    }
    if(dp[i][pos] != -1) return dp[i][pos];

    dp[i][pos] = add(mul(a[i].snd,f(i+1,pos+1,a)), mul((1000LL-a[i].snd), f(i+1,pos,a)));

    return dp[i][pos];

}

int main(){
    FIN;
    memset(dp,-1,sizeof(dp));
    ll n,k; cin >> n >> k;
    vector<pll> a(n);
    fore(i,0,n) cin >> a[i].fst;
    fore(i,0,n) cin >> a[i].snd;
    sort(ALL(a));
    reverse(ALL(a));

    ll upos;
    ll cant = 0;
    fore(i,0,n) if(a[i].fst == a[k-1].fst) {upos = i;break;}
    fore(i,upos,n) if(a[i].fst == a[k-1].fst) cant++;

    kcant = upos+cant-1;
    kneed = k - upos;
    // DGB(kneed);
    // DGB(kcant);
    ll pmod = f(upos,0,a);
    // DGB(pmod);

    ll qmod = fpow(1000LL,n);
    fore(i,0,upos) pmod = mul(pmod,a[i].snd);
    fore(i,upos+cant,n) pmod = mul(pmod,1000LL-a[i].snd);

    ll qinv = fpow(qmod,MOD-2LL);
    ll x = mul(pmod,qinv);
    cout << x << "\n";
}
