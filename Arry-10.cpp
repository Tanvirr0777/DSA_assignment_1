#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int index = 0;
     for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < index; j++) {
            if(arr[i] == arr[j]) {
                found = 1;
                break;
            }}
        if(!found) {
            arr[index++] = arr[i];
        }}
   cout <<"Array after removing duplicates: ";
    for(int i=0; i<index; i++){
         cout << arr[i]<<" ";
    }
return 0;
}
