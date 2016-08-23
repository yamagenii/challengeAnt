#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int m;
vector<int> a;
vector<int> aa;
bool solve();
bool solve2();


bool binary_search(int num){
    int i = 0;
    int r = n*n-1;
    int x = 0;
    while(num <= a[r] && num >= a[i]){
        int h = (r + i)/2;
        if(a[i]==num)return true;
        else if(a[r]==num) return true;
        else if(a[h]==num) return true;
        else if(num > a[h]) i = h;
        else r = h;
    }
    return false;
}

void mainmain(){
    cin >> n;
    cin >> m;
    for (int i = 0;i < n; i++){
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << solve() << endl;
    cout << solve2() << endl;
}
//遅い解き方 全探索　o(n^4)
bool solve(){
    for (int i = 0; i<n ;i++){
        for (int j = 0; j<n ;j++){
            for (int k = 0; k<n ;k++){
                for (int l = 0; l<n ;l++){
                    if(a[i]+a[j]+a[k]+a[l] == m){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

//速い解き方　バイナリサーチ（2分探索法）を使う
bool solve2(){
    for(int i=0;i<n;i++){
        for(int j = 0;j< n;j++){
            aa.push_back(a[i]+a[j]);
        }
    }
    sort(aa.begin(),aa.end());
    for (int i = 0;i< aa.size();i++){
        cout << aa[i] <<endl;
    }
    for (int i = 0;i < n ;i++){
        for (int j = 0;j<n;j++){
            if(binary_search(m-a[i]-a[j])){
                return true;
            }
        }
    }
    return false;

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    mainmain();
    return 0;
}
