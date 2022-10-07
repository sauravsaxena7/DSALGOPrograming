#include<bits/stdc++.h>
using namespace std;

bool checkForPowerOf2(int k){
	while(1){

		if(k==2){
			return true;
		}

		if(k%2==0){
			k=k/2;
		}else{
			return false;
		}
		

	}
	return true;
}

string lexicographicallySmallest(string s, int k) {
	stack<char> stk;
	string result="";

	if(checkForPowerOf2(s.size())){
		k=k/2;
	}else{
		k=k*2;
	}
	int i=0;

	while(i<s.size()){
		if(stk.size()==0){
			stk.push(s[i]);
		}else{
			while(stk.size()>0 && stk.top()>s[i] && k>0){
				k--;
				stk.pop();
			}
			stk.push(s[i]);
		}
		if(k==0){
			break;
		}
		i++;
	}

	while(stk.size()>0){
		result = result+stk.top();
		stk.pop();
	}
	reverse(result.begin(),result.end());

	while(i<s.size()){
		result=result+s[i];
		i++;
	}




	cout<<k<<endl;
	cout<<checkForPowerOf2(k)<<endl;
	return result;
}

int main(){

	string str;
	cin>>str;
	int k;
	cin>>k;
	string res = lexicographicallySmallest(str,k);
}