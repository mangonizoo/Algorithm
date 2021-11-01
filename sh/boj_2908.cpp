#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int num1, num2;
	int max_num=0;
	cin>>num1>>num2;
	string ber1,ber2;
	//int to string
	ber1=to_string(num1);
	ber2=to_string(num2);
	//reverse string
	reverse(ber1.begin(),ber1.end());
	reverse(ber2.begin(),ber2.end());
	//string to int
	num1=stoi(ber1);
	num2=stoi(ber2);
	//compare
	max_num=max(num1,num2);
	
	cout<<max_num;
	return 0;
}
