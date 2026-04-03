#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout <<"Enter elements: ";
    for(int i=0; i<n; i++){
         cin >> arr[i];
    }
    int start = 0, last = n - 1;
    int isPalindrome = 1;

    while(start < last) {
        if(arr[start] != arr[last]) {
            isPalindrome = 0;
            break;
        }
        start++;
        last--;
    }
    if(isPalindrome){
        cout <<"The array is a palindrome."<<endl;
    }
    else{
        cout << "The array is not a palindrome."<<endl;
    }
return 0;
}
