#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n;
    
    cin >> n;
    
    vector<int> arr_a(n);
    vector<int> arr_b(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr_a[i];
    }
    
    for(int i = 0; i < n; i++){
        cin >> arr_b[i];
    }
    
    sort(arr_a.begin(), arr_a.end());
    sort(arr_b.begin(), arr_b.end(), greater<>());
    
    int sum = 0;
    
    for(int i = 0; i < n; i++){
        sum += arr_a[i] * arr_b[i];
    }
    
    cout << sum;

    return 0;
}
