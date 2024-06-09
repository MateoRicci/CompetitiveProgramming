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
        ll n,q;
        cin >> n >> q;
        vector<ll> arr;
        arr.push_back(0);
        fore(i,0,n){
           ll aux;
           cin >> aux;
           arr.push_back(aux + arr[i]);
        }

        while(q--){
            ll l,r,k, num, res;
            cin >> l >> r >> k;
            num = k*(r-l-1) + arr[l-1];
            res = arr[n] - arr[r] + num;
            if((res%2)==0){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
        }
    }
    // 0 2 2 1 3 2
    // 0 1 2 3 4 5
    // 1 5 5
    // n 
    // 2 3
    // 0 2 5
    // 
}