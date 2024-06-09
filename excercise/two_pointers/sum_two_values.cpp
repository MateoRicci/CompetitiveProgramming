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

    ll n,x;
    cin >> n >> x;
    vector<ll> v;
    fore(i,0,n){
        ll aux;
        cin >> aux;
        v.push_back(aux);
    }
    
    ll i, j, sum, res;
    i = 0;
    j = 0;
    sum = 0;
    res = 0;

    cout << res << endl;
}