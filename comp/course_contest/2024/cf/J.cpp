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
 
 
const ll inf = 1LL << 62;
void floydWarshall(vector<vector<ll>>& m) {
	ll n = SZ(m);
	fore(i,0,n) m[i][i] = min(m[i][i], 0LL);
	fore(k,0,n) fore(i,0,n) fore(j,0,n)
		if (m[i][k] != inf && m[k][j] != inf) {
			auto newDist = max(m[i][k] + m[k][j], -inf);
			m[i][j] = min(m[i][j], newDist);
		}
	fore(k,0,n) if (m[k][k] < 0) fore(i,0,n) fore(j,0,n)
		if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}
     
     
int main(){
    FIN;
 
    string a,b;
    cin >> a >> b;
    ll n; cin >> n;
    vector<vector<ll>> g(26, vector<ll>(26, inf));
    fore(i,0,n){
        char aux1, aux2;
        ll cost;
        cin >> aux1 >> aux2 >> cost;
 
        ll primc = aux1 - 97;
        ll segc = aux2 - 97;
        // cout << primc << " " << segc << "\n";
 
        g[primc][segc] = min(g[primc][segc], cost);
    }
 
    if(SZ(a) != SZ(b)){
        cout << -1 << "\n";
    }else{
        floydWarshall(g);
        bool flag = false;
        ll res = 0;
        vector<char> res2;
        fore(i,0,SZ(a)){
            ll val = inf;
            if(a[i]!=b[i]){
                ll c1 = a[i] - 97;
                ll c2 = b[i] - 97;
 
                char caux;
                fore(j,0,26){
                    if(g[c1][j] < 50005 && g[c2][j] < 50005){
                        if(g[c1][j] + g[c2][j] < val) caux = 'a' + j;
                        val = min(val,(g[c1][j] + g[c2][j]));
                    }
                }
                if(val< 50005){
                    res+=val;
                    res2.pb(caux);
                } else flag = true;
            }
            else{
                res2.pb(a[i]);
            }
        } 
        if(flag){
            cout << -1 << "\n";
        } else{
            cout << res << "\n";
            fore(i,0,SZ(res2))cout << res2[i];
            cout << "\n";
        }
    }
 
    // cout << "vamos bien\n";
}