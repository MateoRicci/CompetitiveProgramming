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

const ll MAXN = 1000005;

ll cr[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0)for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=i;
}
map<ll,ll> fact(ll n){  // must call init_cribe before
	map<ll,ll> r;
	while(cr[n]>=0)r[cr[n]]++,n/=cr[n];
	if(n>1)r[n]++;
	return r;
}

int main(){
    FIN;

    init_sieve();
    ll t; cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> nums(n);
        vector<map<ll,ll>> prims(n);
        map<ll,ll> sums;
        fore(i,0,n){
            cin >> nums[i];
        }
        fore(i,0,n){
            prims[i] = fact(nums[i]);
        }

        for(auto mp : prims){ // O(n)
            for(auto i : mp){ // O(sqr N)?
                ll pr = i.fst, sn = i.snd;
                // cout << pr << " " << sn << "\n";
                sums[pr] += sn;
            }
        }
        bool res = true;
        for(auto i : sums){
            if(i.snd%n != 0){
                res = false;
            }
        }

        if(res) cout << "YES\n";
        else cout << "NO\n";

    }
    
    return 0;

}


