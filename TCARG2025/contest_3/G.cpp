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
    ll n,m; cin >> n >> m;
    vector<ll> a(m);
    ll L = 0;
    bool valid = true;
    fore(i,0,m){
        cin >> a[i], L+=a[i];
        if((i+1) > n - a[i] + 1){valid = false;}
    }

    if(L < n || !valid){
        // DGB(L);
        // DGB(valid);
        show(-1);return 0;
    }
    ll pt = n;
    vector<ll> res(m);
    ll j; bool unito = false;
    dfore(i,m-1,0){
        // DGB(pt);
        pt -= a[i]-1;
        // DGB(a[i]);
        // DGB(pt);
        if(pt<=i){
            j = i;
            unito = true;
            break;
        } else{
            res[i] = pt;
        }
        pt--;
    }
    if(unito){
        // DGB(j);
        dfore(i,j,0){
            res[i] = i+1;
        }
    }
    showAll(res);
    return 0;
}