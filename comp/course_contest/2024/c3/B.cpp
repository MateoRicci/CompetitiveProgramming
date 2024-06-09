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
    ll t;
    cin >> t;
    while(t--){
        ll n,c, orb=0;
        cin >> n >> c;
        vector<ll> a;
        ll b[105];
        memset(b,0,sizeof(b));

        fore(i,0,n){
            ll aux;
            cin >> aux;
            a.pb(aux);
            b[aux]++;
            orb=max(orb,aux);
        }

        ll res = 0;
        // cout << "orb: " << orb << "\n";
        // fore(i,1,orb+1){
        //     cout << b[i] << "\n";
        // }
        fore(i,1,orb+1){
            res = res + min(b[i],c);
        }

        cout << res << "\n";



    }   
}
