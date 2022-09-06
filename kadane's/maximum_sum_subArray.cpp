#include<bits/stdc++.h>

using namespace std;

int maxSumSubArray(vector<int> &a){
	int max_ending_here=0;
	int max_so_far=a[0];
	int s=0,end=0,start=0;
	
	for(int i=0;i<a.size();i++){
		max_ending_here=max_ending_here+a[i];
		
		if(max_ending_here>max_so_far){
			max_so_far=max_ending_here;
			start=s;
			end=i;
			
		}
		
		if(max_ending_here<0){
			
			max_ending_here=0;
			s=i+1;
		}
	}
	
	return max_so_far;
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
	
	int result=maxSumSubArray(a);
	
	cout<<result;
}
