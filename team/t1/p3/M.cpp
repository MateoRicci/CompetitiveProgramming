#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

#define MAXN 200005
int uf[MAXN];
void uf_init(){memset(uf,-1,int(sizeof(uf)));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

vector<ii> kruskal(vector<ii> &es){  // assumes graph is connected
	sort(es.begin(),es.end());uf_init();
    vector<ii> r;
	fore(i,0,es.size()){ // without 1
		int x=es[i].fst,y=es[i].snd;
		if(uf_join(x,y))r.pb(es[i]); // (x,y,c) belongs to mst
	}
	return r; // vertexs
}


int main(){
    FIN;
    
    uf_init();
    ll n,m,d; cin >> n >> m >> d;
    vector<ii> es; // edges (cost,(u,v))
    vector<ii> to_use;
    fore(i,0,m){
        ll a,b;
        cin >> a >> b; a--;b--;
        if(a==0) es.pb({a,b});
        else if(b==0) es.pb({b,a});
        else{
            to_use.pb({a,b});
            to_use.pb({b,a});
            uf_join(a,b);
        }
        // es.pb({a,b});
    }



    set<ll> st;
    set<ii> fr;
    set<ll> used;
    for(auto k : es){
        if(uf_find(k.snd)==-1){
            to_use.pb(k);
            to_use.pb({k.snd,k.fst});
            used.insert(k.snd);
            d--;
            continue;
        }

        if(st.count(uf_find(k.snd)==0)){
            to_use.pb(k);
            to_use.pb({k.snd,k.fst});
            d--;
            st.insert(uf_find(k.snd));
            used.insert(k.snd);
            continue;
        }
    
        fr.insert(k);

    }
    
    if(d<0){
        cout << "NO\n";
        return 0;
    }

    for(auto k : fr){
        d--;
        to_use.pb(k);
        to_use.pb({k.snd,k.fst});
        if(d==0) break;
    }

    if(d!=0){
        cout << "NO\n";
        
    }else{
        vector<ii> res = kruskal(to_use);
        cout << "YES\n";
        for(auto k : res) cout << ++k.fst  << " " << ++k.snd << "\n";
    }


}