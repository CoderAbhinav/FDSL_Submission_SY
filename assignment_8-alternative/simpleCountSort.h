#include <iostream>
#include <queue>
using namespace std;
void countSort(int arr[], int n,const int departmentCount){
	// O(N) Linear
	int *m = new int[departmentCount + 1]; // map
	for(int i = 0; i < n; i++){
		m[arr[i]]++;
	}

	int k = 0;
	for(int i = 0; i <= departmentCount; i++){
		while(m[i]--){
			arr[k] = i;
			k++;
		}
	}

}

void drivingCode(){
	int departmentCount, n;
	cin>>departmentCount>>n;
	int arr[n];
	for(int i = 0; i < n; i++) cin>>arr[i];
	countSort(arr, n, departmentCount);
	for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
}