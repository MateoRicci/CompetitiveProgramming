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
        int h,m;

        cin >> h >> m;

        int hour = 24 * 60;
        int time_left = hour - (h*60) - m;

        cout << time_left << "\n";

    }

}