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


int main(){
    FIN;
    ll t; cin >> t;

    while(t--){
        ll h, n; cin >> h >> n;
        vector<ii> a(n);
        fore(i,0,n){
            cin >> a[i].fst;
            a[i].fst = a[i].fst * (-1);
        }
        fore(i,0,n){
            cin >> a[i].snd;
        }
        sort(ALL(a));

        priority_queue<ii> at;
        priority_queue<pair<ll,ii>> cold_down;
        fore(i,0,n){
            at.push(a[i]);
        }
        ll res = 0;
        ll damage = 0;
        while(damage < h){
            while(!cold_down.empty() && (cold_down.top().fst >= res)){
                pair<ll,ii> prim = cold_down.top();
                cold_down.pop();
                at.push(prim.snd);
            }

            pair<ll,ll> usage;
            if(!at.empty()){
                usage = at.top();
                at.pop();
                damage += (-usage.fst);
                ll cd = usage.snd + res + 1;
                pair<ll,ii> aux = {cd,{usage}};
                cold_down.push(aux);
            }


            if(damage < h) res++;
        }

        cout << res << "\n";
    }
}
