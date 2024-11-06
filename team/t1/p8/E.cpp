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
    double n,m; cin >> n >> m;
    double x,y; cin >> x >> y;
    double a,b;
    a = (((x/n) + (y/m))/2);
    b = (((x+y) / (n+m)));

    ll aa = a*100000000000;
    ll bb = b*100000000000;

    if(aa>bb) cout << "A\n";
    else if(bb>aa) cout << "B\n";
    else cout << "C\n";

}
// euro river
