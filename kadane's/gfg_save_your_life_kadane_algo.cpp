#include<bits/stdc++.h>
using namespace std;


string maxSum(string w,char x[], int b[],int n){


	int map[1000];
	for(int i=0;i<1000;i++){
		map[i]=-100000;
	}

	for(int i=0;i<n;i++){
		map[(int)x[i]]=b[i];
	}

	long long int currSum=0,maxSumm=INT_MIN;
	int start=0,end=0,maxStart=0;

	for(int i=0;i<w.size();i++){
		int op;

		if(map[(int)w[i]]!=-100000){
			op=map[(int)w[i]];
		}else{

			op=(int)w[i];
		}
		currSum+=op;

		if(currSum<0){
			currSum=0;
			  start=i+1;
		}
		else if(currSum==0){

			end=i;
		}
		else if(currSum>maxSumm){
			maxSumm=currSum;
			maxStart=start;
			end=i;

		} 
	    cout<<currSum<<" "<<maxSumm<<" "<<op<<" "<<maxStart<<" "<<start<<" "<<end<<endl;



	}

	string result="";
	cout<<endl;
	cout<<maxStart<<" "<<end<<endl;
	for(int i=maxStart;i<=end;i++){
		result+=w[i];
	}

	return result;
}
int main(){
	string str;
	cin>>str;
	int n;
	cin>>n;

	char x[n];
	int b[n];

	for(int i=0;i<str.size();i++){
		cout<<str[i]<<" -> "<<(int)str[i]<<endl;
	}


	for(int i=0;i<n;i++){
		cin>>x[i];
	}

	for(int i=0;i<n;i++){
		cin>>b[i];
	}

	cout<<maxSum(str,x,b,n);	
}