#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cout << "Enter the number of elements : ";
    cin >> n;

    int arr[n];

    cout<<"Enter array elements : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int largest = arr[0], smallest = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] > largest)
            largest = arr[i];
        if(arr[i] < smallest)
            smallest = arr[i];
    }

     int secondLargest = INT_MIN;
     int secondSmallest = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(arr[i] > secondLargest && arr[i] < largest)
            secondLargest = arr[i];

        if(arr[i] < secondSmallest && arr[i] > smallest)
            secondSmallest = arr[i];
    }

    cout << "Second largest elements : "<<secondLargest<<endl;
    cout << "Second smallest elements : "<<secondSmallest<<endl;

    return 0;
}
