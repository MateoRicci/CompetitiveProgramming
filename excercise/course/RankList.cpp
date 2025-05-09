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

bool comp(ii a, ii b){
    if(a.fst == b.fst) return a.snd<b.snd;
    return a>b;
}

int main(){
    FIN;
    ll n,k; cin >> n >> k; k--;
    vector<ii> a(n);
    multiset<ii> ms;
    fore(i,0,n){
        cin >> a[i].fst >> a[i].snd;
        ms.insert(a[i]);
    }
    sort(ALL(a), comp);
    // fore(i,0,n) cout << i+1 << ": " << a[i].fst << " " << a[i].snd << "\n";
    cout << ms.count(a[k]) << "\n";
}