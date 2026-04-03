#include<bits/stdc++.h>

using namespace std;

int main(){

 int n,k;
 cout << "Enter number of elements : ";
 cin >> n;

 int arr[n];
 cout << "Enter elements: ";
 for(int i=0; i<n; i++){
      cin >> arr[i];
 }
 cout << "Enter k: ";
 cin >> k;

      k = k % n;
    for(int i = 0; i < k; i++) {
        int temp = arr[0];
        for(int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;
    }
    cout << "Array after left rotation by "<<k<<" : ";
    for(int i=0; i<n; i++){
         cout << arr[i] <<" ";
    }
return 0;
}
