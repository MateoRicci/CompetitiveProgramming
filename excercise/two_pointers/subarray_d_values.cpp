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

    ll n,k;
    cin >> n >> k;
    vector<ll> v;
    fore(i,0,n){
        ll aux;
        cin >> aux;
        v.push_back(aux);
    }

    ll res = 0;
    ll i = 0; // pos minima paraq sea valido
    ll j = 0;
    while(j < n-k+1){
        set<ll> s;
        i=j;
        bool aux = true;
        ll siz = 0;
        while(aux && i<n){
            if(siz < k){
                s.insert(v[i]);
                siz = s.size();
                i++;
            }
            else{
                res+= n - i + 1;
                aux = false;
                //cout << "--" << res << "--" << endl;
            }
        }
        j++;
    }
    cout << res << endl;
}