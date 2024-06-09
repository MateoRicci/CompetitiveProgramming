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

bool can(ll t,ll n, ll sum){
    bool res = false;
    ll aux = sum;

    fore(i,0,t){
        aux -= (n-1);
    }

    if(aux <= 0){
        res = true;
    }

    return res;
}

int main(){
    FIN;

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        set<ll> s;
        vector<ll> a;
        fore(i,0,n){
            ll aux;
            cin >> aux;
            s.insert(aux);
        }
        for(set<ll>::iterator it = s.begin(); it != s.end(); ++it){
            // Aquí puedes usar *it para acceder al elemento actual del conjunto
            a.pb(*it);
        }

        ll l=0,r=0,res=1;
        ll size = a.size();
        while(r < size && l < size){
            if(r+1 < size && a[r+1] - a[l] < n){
                r = r + 1;
                res = max(res,(r-l+1));
            }
            else{
                l++;
            }
        }
        cout << res << "\n";
    }
}