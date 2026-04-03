#include<bits/stdc++.h>

using namespace std;

int main(){
 int n, target, newValue;
 cout<<"Enter number of elements: ";
 cin >> n;

 int arr[n];
 cout << "Enter elements: ";
 for(int i=0; i<n; i++){
    cin >> arr[i];
 }
 cout <<"Enter target value: ";
 cin >> target;

 cout << "Enter value to insert after each occurrence: ";
 cin >> newValue;

 int i = 0;
    while(i < n) {
        if(arr[i] == target) {
            for(int j = n; j > i+1; j--) {
                arr[j] = arr[j-1];
            }
            arr[i+1] = newValue;
            n++;
            i++;
        }
        i++;
    }
  cout << "Resulting array: ";
   for(int i=0; i<n; i++){
     cout << arr[i] << " ";
   }
 return 0;
}
