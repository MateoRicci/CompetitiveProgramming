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
    ll n,m,q;
    cin >> n >> m >> q;
    vector<vector<ll>> s(n+1,vector<ll>(n+1,0));
    fore(i,0,m){
        ll k,a,b;
        cin >> k >> a >> b;
        if(b<a) swap(a,b);
        ll pos = b-a;
        s[pos][a] += 1;
        s[pos][a+k] -= 1;
    }

    fore(pos,0,n+1){
        fore(i,1,n+1){
            s[pos][i] = s[pos][i] + s[pos][i-1];
        }
    }

    fore(i,0,q){
        ll a,b;
        cin >> a >> b;
        if(b<a) swap(a,b);
        ll pos = b-a;
        ll upd = s[pos][a];
        if(upd%2==1)show("SI");
        else show("NO");

    }
}