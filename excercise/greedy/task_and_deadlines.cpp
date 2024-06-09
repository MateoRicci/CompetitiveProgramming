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
    vector<pair<ll,ll>> t;
    fore(i,0,n){
        ii t_aux;
        cin >> t_aux.fst >> t_aux.snd;
        t.push_back(t_aux);
    }

    ll time = 0;
    ll res = 0;
    sort(t.begin(), t.end());  
    fore(i,0,n){
        time += t[i].fst;
        res += t[i].snd - time;
    }

    cout << res << endl;

}