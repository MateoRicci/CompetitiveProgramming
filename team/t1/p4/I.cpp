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

ll f(ll i, ll n, vector<double> &a, vector<ll> &res){
    ll j = i+1;
    j = j % n;
    ll cant = 1;
    double x = a[i]/2;
    while(a[j] >= x){

        if(res[j]!=-1) return res[j] + cant;

        x = max(x,(a[j]/2));
        cant++;
        j++;
        j = j%n;
        if(cant>2*n){
            return LONG_LONG_MAX;
        }
    }
    return cant;
}


int main(){
    FIN;
    ll n; cin >> n;
    vector<double> a(n);
    vector<ii> b(n);
    vector<ll> res(n,-1), pres(n,0);
    fore(i,0,n){
        cin >> a[i];
        b[i] = {a[i],i};
    }
    bool flag = false;

    sort(b.begin(),b.end(),greater<ii>());

    fore(i,0,n){
        ll hi = b[i].snd;
        res[hi] = f(hi,n,a,res);
        if(res[i] == LONG_LONG_MAX){
            flag = true;
            break;
        }
        ll cant = res[hi]-1;
        fore(p,hi+1,hi+res[hi]){
            ll pi = p%n;
            pres[pi] = cant;
            cant--;
        }
    }


    if(flag){
        fore(i,0,n) cout << -1 << " ";    
    } else{
        fore(i,0,n) cout << res[i] << " ";
    }
    cout << "\n";
}

// Gallardo vuelve a river