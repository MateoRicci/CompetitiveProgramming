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

    ll t;
    cin >> t;
    while(t--){
        ll a,b,c;
        cin >> a >> b >> c;
        ll a_aux = max(b,c);
        ll b_aux = max(a,c);
        ll c_aux = max(a,b);

        ll a_res,b_res,c_res;

        ll cer = 0;
        
        a_res = max((a_aux - a + 1), cer);
        b_res = max((b_aux - b + 1),cer);
        c_res = max((c_aux - c + 1),cer);

        cout << a_res << " " << b_res << " " << c_res << endl;
    }

}