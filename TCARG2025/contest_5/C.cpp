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

const ll MAXN = 2e6+5;

// MAXN: max number of nodes or 2 * max number of variables (2SAT)
bool truth[MAXN]; // truth[cmp[i]]=value of variable i (2SAT)
int nvar;int neg(int x){return MAXN-1-x;} // (2SAT)
vector<int> g[MAXN];
int n,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(int v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x,l=-1;
		do{x=st.top();st.pop();cmp[x]=qcmp;if(min(x,neg(x))<nvar)l=x;}
		while(x!=u);
		if(l!=-1)truth[qcmp]=(cmp[neg(l)]<0); // (2SAT)
		qcmp++;
	}
}
void scc(){
    fore(i,0,n) idx[i]=0, cmp[i] = -1;
    qidx=0; qcmp=0;
	// memset(idx,0,sizeof(idx));qidx=0;
	// memset(cmp,-1,sizeof(cmp));qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
}
// Only for 2SAT:
void addor(int a, int b){g[neg(a)].pb(b);g[neg(b)].pb(a);}
bool satisf(int _nvar){
	nvar=_nvar;n=MAXN;scc();
	fore(i,0,nvar)if(cmp[i]==cmp[neg(i)])return false;
	return true;
}

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        int m;
        cin >> n >> m;
        fore(i,0,n){
            g[i].clear();
        }
        fore(i,0,m){
            int a,b;
            cin >> a >> b,a--,b--;
            if(a!=b){
                g[a].pb(b);
            }
        }
        scc();
        set<int> colors;
        fore(i,0,n) colors.insert(cmp[i]);
        if(SZ(colors)==1){
            show("No");
        } else{
            show("Yes");

            vector<vector<ll>> g2(SZ(colors));
            fore(i,0,n){
                for(auto v : g[i]){
                    if(cmp[i] != cmp[v]) g2[cmp[i]].pb(cmp[v]);
                }
            }
            // BUSCAR LA LEAFDE DEL GRAFO DE COMPONENTES CONEXAS
            ll color_elegido = 0;
            fore(i,0,SZ(colors)){
                if(SZ(g2[i])==0){
                    // encontre la leaf
                    color_elegido = i;
                    break;
                }
            }
            
            // lo que voy a hacer va a ser reservame el primero y pushbakear el resto
            vector<ll> jueces;
            vector<ll> gatos;

            fore(i,0,n){
                if(cmp[i] == color_elegido) jueces.pb(i+1);
                else gatos.pb(i+1);
            }
            cout << SZ(jueces) << " " << SZ(gatos) << "\n";
            showAll(jueces);
            showAll(gatos);

        }
    }
}

