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
        ll n,k; cin >> n >> k;
        vector<vector<bool>> used(n,vector<bool>(n, false));

        ll res = 0;
        if(k>0){
            k -= n;
            res++;
        }
        ll i = 1;
        while(k>0){
            n-=i;
            k -= n;
            res++;
            if(k<1) break;
            k -= n;
            res++;
        }

        cout << res << "\n";
    }
   


}
