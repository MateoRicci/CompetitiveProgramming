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
    ll n; cin >> n;
    vector<ii> td(n);

    fore(i,0,n){
        ll a,b; cin >> a >> b;
        td[i].fst = a; td[i].snd = b;
    }

    ll time = 0;
    for(auto [T, D] : td) {
        time += T;
    }

    vector<bool> used(n, false);
    vector<ll> ans(n, -1);

    dfore(i,n-1,0){
        dfore(j,n-1,0){
            if (!used[j]) {
                auto [tj, dj] = td[j];

                if (dj >= time) {
                    used[j] = true;
                    ans[i] = j;
                    time -= tj;
                    break;
                }
            }
        }

        // si no encuentra no es posible
        if(ans[i] == -1){
            show('*');
            return 0;
        }
    }

    // imprimimos
    fore(i,0,n){
        cout << ans[i] + 1 << " ";
    }
    cout << "\n" ;
    return 0;
}