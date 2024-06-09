#include <bits/stdc++.h> 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
using namespace std; 
typedef long long ll; 
#define fr(i,n) for (ll i=0;i<n;i++)

using namespace std;

const int MAXN=2e5+10;
int a[MAXN];

int main(){
    FIN;

    for(int i=1; i < MAXN;i++){
        int x=i;
		a[i]=a[i-1];
		while(x) a[i]+=x%10,x/=10;
    }
    

    ll t;
    cin >> t;
    

    while(t--){
        int n;
        cin >> n;
        cout << a[n] << endl;
    }

}
