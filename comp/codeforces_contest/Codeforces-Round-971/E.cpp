#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
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
        ll n,k; cin >> n >> k;
        ll last = n+k-1;
        ll l = k, r = last;
        while(l+1<r){
            ll m = (l+r)/2;
            ll s1 = (m*(m+1))/2 - (k*(k-1))/2;
            ll s2 = (last*(last+1))/2 - (m*(m+1))/2;
            if(s1-s2 > 0) r = m;
            else l = m;
                
        }
        // RAYA;
        // DGB(l);
        // DGB(k);
        ll s1 = (l*(l+1))/2 - (k*(k-1))/2;
        ll s2 = (last*(last+1))/2 - (l*(l+1))/2;
        ll res = abs(s1-s2);
        l++;
        ll s3 = (l*(l+1))/2 - (k*(k-1))/2;
        ll s4 = (last*(last+1))/2 - (l*(l+1))/2;
        res = min(res,abs(s3-s4));
        // DGB(s1);
        // DGB(s2);
        // DGB(s3);
        // DGB(s4);
        show(res);
    }
}