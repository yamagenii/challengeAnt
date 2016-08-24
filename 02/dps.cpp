#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,k;
vector<int> a;

bool dps(int i, int sum){//深さ優先アルゴリズム 全ての和を列挙して、任意の和を持つか判定するアルゴリズム
    if(sum == k) return true;
    else if(i == a.size()) return false;
    if(dps(i+1,sum + a[i])) return true;
    if(dps(i+1, sum)) return true;
    return false;
}

void mainmain(){
    cin >> n;
    for (int i = 0;i < n; i++){
        int m;
        cin >> m;
        a.push_back(m);
    }
    cin >> k;
    bool ans = dps(0,0);
    cout << ans <<endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    mainmain();
    return 0;
}
