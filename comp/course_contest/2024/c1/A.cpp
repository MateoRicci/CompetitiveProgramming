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
        ll rating;
        cin >> rating;
        if(rating >= 1900){
            cout << "Division 1" << endl;
        }
        else if(rating >= 1600){
            cout << "Division 2" << endl;
        }
        else if(rating >= 1400){
            cout << "Division 3" << endl;
        }
        else{
            cout << "Division 4" << endl;
        }

    }

}