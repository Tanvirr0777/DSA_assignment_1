#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, oldValue, newValue;
    cout<<"Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0; i<n; i++){
         cin >> arr[i];
    }
    cout << "Enter value to replace: ";
    cin >> oldValue;
    cout << "Enter new value:  ";
    cin >> newValue;

    for(int i = 0; i < n; i++) {
        if(arr[i] == oldValue) {
            arr[i] = newValue;
        }}
    cout << "Updated array: ";
    for(int i=0; i<n; i++){
         cout << arr[i] << " ";
    }
return 0;
}
