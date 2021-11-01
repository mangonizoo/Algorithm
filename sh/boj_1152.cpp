#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string sentence;
	int cnt=0;
	getline(cin,sentence);
	
	if(sentence[0]==' '){
		cnt--;
		//cout<<"앞공백"<<endl;
	}
	if(sentence[sentence.length()-1]==' '){
		cnt--;
		//cout<<"뒷 공백"<<endl;
	}
	
	for(int i=0;i<sentence.length();i++){
		if(sentence[i]==' '){
			cnt++;
		}
		else;
	}
	cout << cnt+1;
	return 0;
}
