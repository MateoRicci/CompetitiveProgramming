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
        ll l1,l2,r1,r2;
        cin >> l1 >> r1;
        cin >> l2 >> r2;
        vector<ll> lck(101,0);
        fore(i,l1,r1+1) lck[i] += 1;
        fore(i,l2,r2+1) lck[i] += 2;

        ll res = 0;
        if(r1 < l2 || r2 < l1) res =1;
        else{
            fore(i,1,100){
                if(lck[i] == 3){
                    if(lck[i+1] != 0) res++;
                }
                else if(lck[i] == 1 || lck[i] == 2){
                    if(lck[i] != lck[i+1] && lck[i+1] != 0) res++;
                }
            }
        }

        show(res);

        
    }
}