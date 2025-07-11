#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(ll a=b; a>=c; --a)
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
const ll MAXN = 101;
const ll MAXM = 64;

vector<vector<ll>> g(MAXN,vector<ll>(MAXM)); // [0,n)->[0,m)
ll n,m = 62;
ll mat[MAXM];bool vis[MAXN];
ll match(ll x){
	if(vis[x])return 0;
	vis[x]=true;
	for(ll y:g[x])if(mat[y]<0||match(mat[y])){mat[y]=x;return 1;}
	return 0;
}
vector<pair<ll,ll> > max_matching(){
	vector<pair<ll,ll> > r;
	memset(mat,-1,sizeof(mat));
	fore(i,0,n)memset(vis,false,sizeof(vis)),match(i);
	fore(i,0,m)if(mat[i]>=0)r.pb({mat[i],i});
	return r;
}

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        cin >> n;
        ll c0 = 0;
        fore(i,0,n) g[i].clear();
        set<ll> bits;
        fore(i,0,n){
            ll a; cin >> a;
            if(a==0) c0++;
            else{
                fore(j,0,m){   
                    // show((1LL << j));
                    if(a&(1LL << j)){
                        bits.insert(j);
                        g[i].pb(j);
                        // g[j].pb(i);
                    }
                }
            }
        }
        vector<ii> cut = max_matching();
        // for(auto [a,b] : cut) cout << a << " " << b << "\n";
        show(n - SZ(cut));
    }
    return 0;
}