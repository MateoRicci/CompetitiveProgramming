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
typedef pair<ll,ll> pll;

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        ll n,s; cin >> n >> s;
        vector<ll> a(n);
        ll sum = 0;
        vector<ll> cant(3,0);
        fore(i,0,n) cin >> a[i], sum += a[i], cant[a[i]]++;
        // DGB(sum);
        ll falta = s - sum;
        if(falta < 0 || falta == 1){
            vector<ll> res;
            fore(i,0,cant[0]) res.pb(0);
            fore(i,0,cant[2]) res.pb(2);
            fore(i,0,cant[1]) res.pb(1);
            assert(SZ(res) == n);
            showAll(res);
        } else{
            show(-1);
        }
    }
}
