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
typedef pair<int,int> ii;

int main(){
    FIN;
    ll n;
    cin >> n;
    vector<ii> p;
    fore(i,0,n){
        ii p_aux;
        cin >> p_aux.snd >> p_aux.fst;
        p.push_back(p_aux);
    }

    sort(p.begin(), p.end());

    ll t = 0;
    ll res = 0;
    fore(i,0,n){
        if(p[i].snd >= t){ // si la puedo arrancar la veo, pq es la q primero va
            t = p[i].fst;
            res+=1;
        }
    }
    cout << res << endl;

}