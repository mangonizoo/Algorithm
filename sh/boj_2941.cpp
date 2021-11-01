#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	int index;
	int cnt=0;
	cin>>input;
	while(1){
	if(input.find("c=")!=string::npos){
		index=input.find("c=");//해당 문자의 시작 인덱스 반환
		input.replace(index,2,"00");
		cnt++;
	}
	else if(input.find("c-")!=string::npos){
		index=input.find("c-");//해당 문자의 시작 인덱스 반환
		input.replace(index,2,"00");
		cnt++;
	}
	else if(input.find("dz=")!=string::npos){
		index=input.find("dz=");//해당 문자의 시작 인덱스 반환
		input.replace(index,3,"00");
		cnt++;
	}
	else if(input.find("d-")!=string::npos){
		index=input.find("d-");//해당 문자의 시작 인덱스 반환
		input.replace(index,2,"00");
		cnt++;
	}
	else if(input.find("lj")!=string::npos){
		index=input.find("lj");//해당 문자의 시작 인덱스 반환
		input.replace(index,2,"00");
		cnt++;
	}
	else if(input.find("nj")!=string::npos){
		index=input.find("nj");//해당 문자의 시작 인덱스 반환
		input.replace(index,2,"00");
		cnt++;
	
	}
	else if(input.find("s=")!=string::npos){
		index=input.find("s=");//해당 문자의 시작 인덱스 반환
		input.replace(index,2,"00");
		cnt++;
	
	}
	else if(input.find("z=")!=string::npos){
		index=input.find("z=");//해당 문자의 시작 인덱스 반환
		input.replace(index,2,"00");
		cnt++;
		}
	else{
		break;
	}
	}
	for(int i=0;i<input.length();i++){
		if(isdigit(input[i])==false){
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}
