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

const ll MAXN = 1005;
const ll MAXM = 5005;

int n,m;
int mat[MAXM];bool vis[MAXN];
int match(int x, vector<vector<int>> &g){
	if(vis[x])return 0;
	vis[x]=true;
	for(int y:g[x])if(mat[y]<0||match(mat[y],g)){mat[y]=x;return 1;}
	return 0;
}
vector<pair<int,int>> max_matching(vector<vector<int>> &g){
    vector<pair<int,int> > r;
	memset(mat,-1,sizeof(mat));
	fore(i,0,n)memset(vis,false,sizeof(vis)),match(i,g);
	fore(i,0,m)if(mat[i]>=0)r.pb({mat[i],i});
	return r;
}

int main(){
    FIN;
    ll t; cin >> t;
    while (t--){
        cin >> n >> m;
        vector<vector<int>> g(MAXN); // [0,n)->[0,m)
        fore(i,0,m){
            ii aux; cin >> aux.fst >> aux.snd;
            aux.fst--;aux.snd--;
            g[aux.fst].pb(aux.snd);
            g[aux.snd].pb(aux.fst);
        }
        vector<pair<int,int>> mm = max_matching(g);
        ll res = (SZ(mm)/2) + max(0LL,(n-SZ(mm)));
        show(res);
        // cout << n - (SZ(mm)/2) << "\n";
    }
    
    
}