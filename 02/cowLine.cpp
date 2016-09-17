#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

#define N_MAx 2000

int n;
deque<char> a;
vector<char> t;

void mainmain(){
    cin >> n;
    for (int i = 0;i < n; i++){
        int m;
        cin >> m;
        a.push_back(m);
    }
    int count = 0;

    while (!a.empty()){
        cout << a.front() << endl;
        cout << a.back() << endl;
        if (a.front() > a.back()){
            cout << a.front() << endl;
            t.push_back(a.back());
            a.pop_back();
        }else if (a.front() < a.back()){
            t.push_back(a.front());
            cout << a.front() << endl;
            a.pop_front();
        }else {
            cout << "e" <<endl;
            char c = a.front();
            char f,b;
            for(int i = 0;i < a.size() ;i++){
                if (c != a[i]) f = a[i];
                if (c != a[n-i-1]) b = a[n-i-1];
            }
            if(f > b){
                t.push_back(a.back());
                a.pop_back();
            }else {
                t.push_back(a.front());
                a.pop_front();
            }
        }
        cout << count <<endl;
        count++;
    }
    for (int i= 0;i < n; i++ ){
        cout << t[i];
    }
    cout << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    mainmain();
    return 0;
}
