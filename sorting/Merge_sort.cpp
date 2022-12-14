#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &a,int lb,int mid,int ub){
	vector<int> b(100000,0);
	
	int k=lb;
	int i=lb;
	int j=mid+1;
	
	while(i<=mid && j<=ub){
		
		if(a[i]>a[j]){
			b[k]=a[j];
			j++;
			
		}else{
			b[k]=a[i];
			i++;
		}
		
		k++;
	}
	
	if(i>mid){
		while(j<=ub){
			b[k]=a[j];
			j++;
			k++;
		}
	}else{
		
		while(i<=mid+1){
			b[k]=a[i];
			i++;
			k++;
		}
	}
	
	for(int p=lb;p<=ub;p++){
		a[p]=b[p];
	}
	
	
}

void mergeSort(vector<int> &arr,int lb,int ub){
	
	if(lb<ub){
		
		int mid=lb+(ub-lb)/2;
		
		mergeSort(arr,lb,mid);
		mergeSort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
		
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
	
	
	mergeSort(a,0,a.size()-1);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
