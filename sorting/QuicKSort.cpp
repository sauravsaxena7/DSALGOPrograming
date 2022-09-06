#include<bits/stdc++.h>

using namespace std;

int partition(vector<int> &a,int lb,int ub){
	int start = lb;
	int end=ub;
	
	int pivot = a[lb];
	
	while(start<end){
		
		while(a[start]<=pivot){
			start++;
		}
		
		while(a[end]>pivot){
			end--;
		}
		
		if(start<end){
			swap(a[start],a[end]);
		}
	}
	
	swap(a[lb],a[end]);
	
	return end;
}

void Quicksort(vector<int> &a,int lb,int ub){
	if(lb<ub){
		int loc=partition(a,lb,ub);
		
		Quicksort(a,lb,loc-1);
		Quicksort(a,loc+1,ub);
	}
}

int main(){
	int n;
	cin>>n;
	
	vector<int> a(n);
	
	for(int i=0;i<n;i++){
		int it;
		cin>>it;
		
		a[i]=it;
	}
	
	
	Quicksort(a,0,n-1);
	
	for(int i=0;i<n;i++){
		
		cout<<a[i]<<" ";
	}
}
