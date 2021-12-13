#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct item{
	int department;
	string name;
	item(){}
	item(int department, string name){
		this->department = department;
		this->name = name;
	}

	string toString(){
		return "item{'department' : " + to_string(department)
					+ ", 'name' : '" + name + "'}"; 
	}
};

void countSort(item* arr, int n, int departmentCount){
	// O(N)
	queue<item>* q = new queue<item>[departmentCount + 1];
	for(int i = 0; i < n; i++){
		q[arr[i].department].push(arr[i]);
	}

	int k = 0;
	for(int i = 0; i <= departmentCount; i++){
		while(!q[i].empty()){
			arr[k] = q[i].front();
			q[i].pop();
			k++;
		}
	}
}

void drivingCode(){
	int departmentCount, n;
	cin>>departmentCount>>n;
	item* arr = new item[n];
	for(int i = 0; i < n; i++){
		int dept; string name;
		cin>>name;
		cin>>dept;
		arr[i] = item(dept, name);
	}
	countSort(arr, n, departmentCount);
	for(int i = 0; i < n; i++){
		cout<<arr[i].toString()<<"\n";
	}
}