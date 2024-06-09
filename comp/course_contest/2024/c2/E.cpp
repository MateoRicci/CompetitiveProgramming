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

bool can(ll sum,ll t,ll n){
    bool res = false;
    ll acc = 0;

    acc = (n*t) - sum;

    if(acc >= t){
        res = true;
    }

    return res;
}

int main(){
    FIN;

    ll n, sum=0, mx=0;
    cin >> n;
    vector<ll> a;
    fore(i,0,n){
        ll aux;
        cin >> aux;
        a.pb(aux);
        sum += aux;
        mx=max(mx,aux);
    }

    //sort(a.begin(),a.end());

    ll l = mx, r = 1e9*2, m, res=1;
    while(l <= r) {
        m = (l+r)/2;
        if (can(sum,m,n)){
            res = m;;
            r = m-1;
        }
        else l = m+1;
    }
    cout << res << "\n";
}