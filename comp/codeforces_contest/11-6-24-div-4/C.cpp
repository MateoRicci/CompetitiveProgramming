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
        ll n; cin >> n;
        vector<ll> a(n);
        vector<ll> sp(n+1);
        sp[0] = 0;
        vector<ll> maxis(n);
        fore(i,0,n){
            cin >> a[i];
            if(i!=0) maxis[i] = max(maxis[i-1],a[i]);
            else maxis[0] = a[i];
            sp[i+1] = sp[i] + a[i];
        }

        ll res = 0;
        fore(i,1,n+1){
//             cout << sp[i] << " " << sp[i-1] << " " << maxis[i-1] << "\n";
            if(i>1){
                if(sp[i]-maxis[i-1] == maxis[i-1]){
                    res ++;
                }
            } else{
                if(a[i-1] == 0) res++;
            }

        }
        cout << res << "\n";



    }
}
