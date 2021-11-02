#include <iostream>
#include <string>
using namespace std;

int main() {
	int n=0;
	int cnt=0;
	bool isgroup=true;
	string input;
	int alpha[26]={0,};
	cin >> n;
	for(int j=0;j<n;j++){
	cin >> input;
	for(int i=0;i<input.length();i++){
		
		//already exist
		if(alpha[int(input[i])-97]==1){
			if(input[i-1]==input[i]){
				isgroup=true;
			}
			else{
				isgroup=false;
				break;
			}
		}
		//first time
		else{
			alpha[int(input[i])-97]=1;
			isgroup=true;
		}
	
	}
	if(isgroup==true){
		cnt++;
	}
	for(int i=0;i<26;i++){
		alpha[i]=0;
	}
	}
	cout<<cnt;
	return 0;
}
