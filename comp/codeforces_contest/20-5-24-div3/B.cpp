#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;


int main(){
    FIN;
   
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<char> b(n);
        set<char> r;
        fore(i,0,n){
            cin >> b[i];
            r.insert(b[i]);
        }
        map<char,char> mp;
        vector<char> aux;
        for(auto e : r){
            aux.pb(e);
        }

        ll j=SZ(aux)-1;
        fore(i,0,SZ(aux)){
            mp[aux[i]] = aux[j];
            j--;
        }

        vector<char> res(n);
        fore(i,0,n){
            res[i] = mp[b[i]];
            cout << res[i];
        }
        cout << "\n";


        

        

    }

}