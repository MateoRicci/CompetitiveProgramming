#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const ll MOD = 998244353;

ll mul(ll a, ll b){
	return a*b%MOD;
}


int main(){
    FIN;
    ll t; cin >> t;
    while(t--){
        string num;
        cin >> num;
        ll sum = 0;
        ll rep = 0;
        vector<ll> reps;
        ll total_comb = 1;

        ll cant = ll(num.length());
        fore(i, 0, cant - 1) {
            if (num[i] == num[i + 1]) {
                sum++;
                rep++;
            } else {
                if (rep > 0) {
                    reps.pb(rep + 1);
                    total_comb = mul(total_comb,rep+1);
                }
                rep = 0;
            }
        }
        if (rep > 0) {
            reps.pb(rep + 1);
            total_comb = mul(total_comb,rep+1);
        }

        
    
        fore(i,1,sum+1){
            total_comb = mul(total_comb,i);
        }

        cout << sum << " " << total_comb << "\n";
    }

}




