#include <iostream>
#include <string>
using namespace std;

int main() {
	int alpha[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
	int num[26]={0,};
	int index=0,sum=0;
	string input;
	cin >> input;
	for(int i=0;i<input.length();i++){
		index=int(input[i])-65;
		num[i]=alpha[index];
	}
	for(int j=0;num[j]!=0;j++){
		sum=sum+(num[j]+1);
	}
	cout <<sum;
	return 0;
}
