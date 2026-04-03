#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cout<<"Enter number of elements: ";
  cin >> n;
  int arr[n];

  cout <<"Enter elements: ";
  for(int i=0; i<n; i++){
     cin >> arr[i];
  }
    int start = 0;
    int last = n - 1;

    while(start < last) {
        int temp = arr[start];
        arr[start] = arr[last];
        arr[last] = temp;

        start++;
        last--;
    }
    cout << "Reversed array: ";
    for(int i=0; i<n; i++){
         cout << arr[i] << " ";
    }
return 0;
}
