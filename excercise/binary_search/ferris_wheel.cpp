#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
    FIN;

    ll n,x; // n chicos x peso
    cin >> n >> x;
    multiset<ll> c;

    fore(i,0,n){
        ll c_aux;
        cin >> c_aux;
        c.insert(c_aux);
    }

    ll res = 0;

    while(c.size() > 0){
        ll c1;
        c1 = *c.begin();
        ll mw = x - c1;
        
        auto it = c.lower_bound(mw);
        cout << c1 << " " << *it << endl;

        if(*it > mw && c.size() > 2){
            --it;
        }
        if(c.size() == 1){
            c.erase(c.begin());
            res += 1;
        }
        else{
            if(mw >= *it){
                c.erase(c.begin());
                c.erase(it);
                res += 1;
            } else{
                c.erase(c.begin());
                res += 1;
            }
        }
    }
    cout << res << endl;
}