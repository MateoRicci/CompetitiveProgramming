#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define show(a) cout<<a<<"\n"
#define showall(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define MAXN 200005
#define ALPH 26
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;

int main(){
    FIN;
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pll> b(n);
        vector<bool> done(n);
        ll tot_sum = 0;
        fore(i,0,n){
            cin >> b[i].fst >> b[i].snd;
            tot_sum += b[i].snd;
        }
        vector<ll> res(n);
        fore(j,0,n){
            ll p_min = LONG_LONG_MAX;
            ll i_min = 0;
            fore(i,0,n){
                if(!done[i]){
                    ll calc = tot_sum*b[i].fst - b[i].snd;
                    if(calc < p_min){
                        i_min = i;
                        p_min = calc;
                    }
                }
                DGB(j);
                DGB(i);
                DGB(i_min);
                DGB(p_min);
            }
            tot_sum -= b[i_min].snd;
            done[i_min] = true;
            res[j] = i_min+1;
        }
        showall(res);
    }
    return 0;
}

// sometimes I feel like I don't have a partner