#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int serialSum(const string& a){
    int k = 0;
    for(int i = 0; i < a.length(); i++){
        if(isdigit(a[i]) != 0){
            k += a[i] - '0';
        }
    }
    return k;
}

bool cmp(const string& a, const string& b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    if(serialSum(a) != serialSum(b)){
        return serialSum(a) < serialSum(b);
    }
    
    return a < b;
}

int main()
{
    int n;
    
    cin >> n;
    
    vector<string> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << "\n";
    }

    return 0;
}
