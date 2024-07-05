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

int main(){
    FIN;
    ll t; cin >> t;



    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        fore(i,0,n){
            cin >> a[i];
        }
        fore(i,0,n){
            cin >> b[i];
        }

        ll m1 = 0, m2 = 0;
        ll pos = 0; ll neg = 0;

        fore(i,0,n){
            if(a[i]!=b[i]){
                if(a[i]>b[i]) m1 += a[i];
                else m2 += b[i];   
            }
            else{
                if(a[i]==1) pos++;
                else if(a[i]==-1) neg++;
            }
        }
        while(pos--){
            if(m1>m2) m2++;
            else m1++;
        }
        while(neg--){
            if(m1<m2) m2--;
            else m1--;
        }
        ll res = min(m1,m2);
        cout << res << "\n";

    }
}

