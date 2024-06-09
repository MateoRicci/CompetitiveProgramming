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
    ll res =0;
    vector<pair<ll,ll>> v;
    fore(i,0,n){
        pair<ll, ll> aux;
        cin >> aux.fst >> aux.snd;
        v.push_back(aux);
    }
    fore(i,0,n){
        fore(j,0,n){
            if(i!=j){
                if(v[i].fst == v[j].snd){
                    res++;
                }
            }
        }
    }
    cout << res << endl;
}