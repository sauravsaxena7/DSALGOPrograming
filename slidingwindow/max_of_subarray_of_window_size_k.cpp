#include<bits/stdc++.h>

using namespace std;

vector<int> max_window_subarray_of_size_k(vector<int> &arr,int k){
	deque<int> dq;
	
	int i=0;
	int j=0;
	int count=0;
	

	
	vector<int> res;
	
	while(j<arr.size()){
		
		
		if(dq.size()>0 && arr[dq.back()]<arr[j]){
			
			
			while(dq.size()>0 && arr[dq.back()]<arr[j]){
				dq.pop_back();
			}
			dq.push_back(j);
			
		}else{
			dq.push_back(j);
		}
		
		//cout<<j<<endl;
		
		count++;
		
		if(count==k){
				cout<<dq.size()<<endl;

			res.push_back(arr[dq.front()]);
			
			if(i==dq.front()){
				dq.pop_front();
			}
			i++;
			count=count-1;
		}
		
		j++;
		
	
	}
	
	return res;
}

int main(){
	
	int n ;
	cin>>n;
	
	vector<int> v(n);
	
	for(int i=0;i<n;i++){
		int it;
		cin>>it;
		v[i]=it;
	}
	
	int k;
	cin>>k;
	
	vector<int> res = max_window_subarray_of_size_k(v,k);
	cout<<res.size()<<endl;
	
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	
	
	
	
}


