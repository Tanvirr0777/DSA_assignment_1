#include<bits/stdc++.h>

using namespace std;

int main(){

   int n,val;
   cout << "Enter number of elements: ";
   cin >>n;

   int arr[n];
   cout << "Enter elements: ";
   for(int i=0; i<n; i++){
        cin >> arr[i];
   }
   cout << "Enter value to delete: ";
   cin >> val;

    int index = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != val) {
            arr[index++] = arr[i];
        }
    }
    cout <<"Array after deleting all " <<val << " : ";
    for(int i=0; i<index; i++){
          cout << arr[i] <<" ";
    }

return 0;
}
