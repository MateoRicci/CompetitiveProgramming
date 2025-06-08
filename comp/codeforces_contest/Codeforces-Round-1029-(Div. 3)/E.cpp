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
    ll t = 1;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n),b(n);
        fore(i,0,n) cin >> a[i];
        fore(i,0,n) cin >> b[i];

        ll res = 0;
        if(a[n-1]==b[n-1]){
            res = n;
        } else{

            dfore(i,n-2,0){
                if(i < n-2){
                    if(a[i]==b[i] || a[i] == a[i+1] || b[i] == b[i+1] || a[i] == a[i+2] || b[i] == b[i+2]){
                        res = max(res,ll(i+1));
                    }
                } else{
                    if(a[i]==b[i] || a[i] == a[i+1] || b[i] == b[i+1]){
                        res = max(res,ll(i+1));
                    }
                }

            }
        }
        cout << res << "\n";
    }
}