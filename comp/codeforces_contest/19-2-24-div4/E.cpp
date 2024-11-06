#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
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
        ll n,k; cin>>n>>k;
		ll p=1;
		k--;
		ll res=0;
		while(1){
			ll c = n/p - n/(2*p);
			if(k<c){
				res=(2*k+1)*p;
				break;
			}
			else k -= c;
			p*=2;
		}
		cout<<res<<"\n";
        
    }
    
}

// Gallardo volvio a river