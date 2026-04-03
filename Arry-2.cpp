#include<bits/stdc++.h>

using namespace std;

int main(){

  int freequency[256] = {0};

  int n;

  cout<<"Enter number of elements: ";
  cin >> n;

  int arr[n];

  cout<<"Enter elements: ";
  for(int i=0; i<n; i++){
     cin >> arr[i];
     freequency[arr[i]]++;
  }
  for(int i=0; i<256; i++){
     if(freequency[i] > 0 ){
        cout <<i << "-> Frequency: " << freequency[i] << endl;
     }
  }


return 0;
}
