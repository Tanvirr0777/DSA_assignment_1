#include<bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n];
  cout << "Enter elements: ";
  for(int i=0; i<n; i++){
     cin >> arr[i];
  }
   int index = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            arr[index++] = arr[i];
        }
    }

    cout << "Compressed array (zeros removed) : ";
    for(int i=0; i<index; i++){
        cout << arr[i] <<" ";
    }

return 0;
}
