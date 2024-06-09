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
        string a,b;
        cin >> a >> b;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        if(a[0] == b[0] && a[0] == 'S'){
            if(a.length()>b.length()){
                cout << '<' << endl;
            }
            else if(a.length()<b.length()){
                cout << '>' << endl;
            }
            else{
                cout << '=' << endl;
            }
        }
        else if(a[0] == b[0]){
            if(a.length()>b.length()){
                cout << '>' << endl;
            }
            else if(a.length()<b.length()){
                cout << '<' << endl;
            }
            else{
                cout << '=' << endl;
            }
        }
        else if(a[0] == 'S'){
            cout << '<' << endl;
        }
        else if(b[0] == 'S'){
            cout << '>' << endl;
        }
        else if(a[0] == 'M'){
            cout << '<' << endl;
        }
        else if(b[0] == 'M'){
            cout << '>' << endl;
        }
        else if(a[0] == 'L'){
            cout << '<' << endl;
        }
        else if(b[0] == 'L'){
            cout << '>' << endl;
        }

    }

}