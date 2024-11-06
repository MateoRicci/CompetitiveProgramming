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

const ll MOD = 1000000007;

int main(){
    FIN;

    ll n,m; cin >> n >> m;
    vector<vector<char>> mtr(n, vector<char>(m));
    vector<vector<ll>> d(n, vector<ll>(m));
    vector<vector<ll>> r(n, vector<ll>(m));
    fore(i,0,n){
        fore(j,0,m){
            cin >> mtr[i][j];
        }
    }
    if(mtr[n][m]=='R'){
        cout << "0\n";
        return 0;
    }

    d[n][m] = 1;
    r[n][m] = 1;




    return 0;
}

// Gallardo vuelve a river