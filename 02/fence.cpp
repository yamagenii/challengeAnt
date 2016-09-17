#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> a;
int cost = 0;

void fence(){
    for(int i = 0;i < n-1;i++){
        sort(a.begin(),a.end(), greater<int>());
        int tmp = a[n-i-1] + a[n-i-2];
        cost += tmp;
        a.pop_back();
        a[n-i-2] = tmp;
    }
}

void mainmain(){
    cin >> n;
    for (int i = 0;i < n; i++){
        int m;
        cin >> m;
        a.push_back(m);
    }
    fence();
    cout << cost << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    mainmain();
    return 0;
}
