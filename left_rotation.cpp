#include <bits/stdc++.h>

using namespace std;

int mod(int a, int m){
  int c = a%m;
  return(c<0? c+m : c);
}
vector <int> leftRotation(vector <int> a, int d) {
    // Complete this function
    vector<int> v(a.size());
    for(int i=0 ; i < a.size() ; i++){
       v[mod((i-d),a.size())]= a[i];
    }
    return v;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector <int> result = leftRotation(a, d);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
