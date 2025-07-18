#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
#define DGB(a) cout<<#a<<" = "<<a<<'\n'
using namespace std;
typedef long long ll;
#define pll pair<ll,ll>

class Compare {
public:
	bool operator()(pll &a, pll &b) {
		if(a.fst > b.fst) {
			return true;
		}
		return false;
	}
};

int main(){
    FIN;
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<ll> bat(n),tengo(n);
        fore(i,0,n) {cin >> bat[i];tengo[i] = bat[i];}
        vector<pll> charg(m);
        fore(i,0,m) {cin >> charg[i].fst >> charg[i].snd; charg[i].snd--;} // <DISTANCIA, CARGADOR>
        priority_queue<pll, vector<pll>, Compare> pq;
        //prox carga de cada una
        vector<ll> cargas[n];
        fore(i,0,m)cargas[charg[i].snd].pb(charg[i].fst);
        fore(i,0,n)cargas[i].pb(charg[m-1].snd + 1000000000000);
        fore(i,0,m){
            pq.push(charg[i]);
        }
        fore(i,0,n)pq.push({charg[m-1].snd + 1000000000000,i});
        ll nxt = 0, estoy = 0;
        while(nxt<m && !pq.empty()){
            ll b = pq.top().second;
            ll pos_aux = pq.top().fst;
            ll tb = tengo[b];
            pq.pop();
            if(tb == 0)continue;if(pos_aux <= estoy)continue;
            tengo[b] -= min(charg[nxt].first - estoy, tb);
            estoy += min(charg[nxt].first - estoy, tb);
            if(estoy == charg[nxt].first){
                tengo[charg[nxt].snd] = bat[charg[nxt].snd];
                auto it = lower_bound(all(cargas[charg[nxt].snd]),estoy + 1);
                if(*it<=estoy)++it;
                pq.push({*it,charg[nxt].snd});
                ++nxt;
                if(nxt<m){
                    pq.push(charg[nxt]);
                }
            }
            auto it = lower_bound(all(cargas[b]),estoy + 1);
            if(*it<=estoy)++it;
            pq.push({*it,b});
        }
        fore(i,0,n)estoy += tengo[i];
        cout<<estoy<<'\n';
    }
}
/*
1
3 3
2 2 1
2 1
4 1
5 3
*/