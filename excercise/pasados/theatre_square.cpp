#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m,a;
    cin  >> n;
    cin >> m;
    cin >> a;

    long long x = (n+a-1)/a; // manera de redondear para arriba

    long long y = (m+a-1)/a;

    cout << x*y << endl;
}