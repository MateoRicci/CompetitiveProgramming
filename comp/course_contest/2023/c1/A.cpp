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

    ll n;
    cin >> n;

    fore(i,1,n){
        if(i%2==1){
            cout << "I hate that ";
        }
        else{
            cout << "I love that ";
        }
    }
    if(n%2==1){
        cout << "I hate it"<< "\n";
    }
    else{
        cout << "I love it"<< "\n";
    }

}