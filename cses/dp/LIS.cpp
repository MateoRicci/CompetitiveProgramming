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
typedef pair<ll,ll> ii;

int main(){
    FIN;
    ll n; cin >> n;
    vector<ll> a(n);
    fore(i,0,n) cin >> a[i];
    vector<ll> res;
    res.pb(0);
    fore(i,0,n){
    	ll elem = a[i];
    	// if i can add elem to the last
    	auto pos = lower_bound(ALL(res), elem);
    	if(pos==res.end()){
    		res.pb(elem);
    	} else{
    		ll ni = pos - res.begin();
    		res[ni] = elem;
    	}
    }
    cout << SZ(res) - 1 << "\n";
}
