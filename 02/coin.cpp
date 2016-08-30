#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;

int ans(int num){
    int a;
    a = n/num;
    n %= num;
    return a;
}

void mainmain(){
    cin >> n;
    cout << "500 :" << ans(500) << endl;
    cout << "100 :" << ans(100) << endl;
    cout << "50  :" << ans(50)  << endl;
    cout << "10  :" << ans(10)  << endl;
    cout << "5   :" << ans(5)   << endl;
    cout << "1   :" << ans(1)  << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    mainmain();
    return 0;
}
