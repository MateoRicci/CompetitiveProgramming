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

const ll MAXN = 100005;

int main(){
    FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        set<ll> a0,a1;

        fore(i,0,n){
            ll x,y;
            cin >> x >> y;
            if (y==0) a0.insert(x);
            else a1.insert(x);
        }

        ll res = 0;
        for(auto x : a0){
            if(a1.find(x) != a1.end()){
                res += SZ(a0)-1;
            }
            if((a1.find(x+1) != a1.end()) && (a0.find(x+2) != a0.end())) res++;
        }
        for(auto x : a1){
            if(a0.find(x) != a0.end()){
                res += SZ(a1)-1;
            }
            if((a0.find(x+1) != a0.end()) && (a1.find(x+2) != a1.end())) res++;
        }
        show(res);
    }
}