#include<iostream>
using namespace std;
int main(){
    int sang_h,sang_m;
    int chang_h,chang_m;

    cin>>sang_h>>sang_m;

    if(sang_m<45){
        if(sang_h==0){
            chang_h=23;
        }
        else{
            chang_h=sang_h-1;
        }
        chang_m=60-(45-sang_m);
    }
    else if(sang_m>=45){
        chang_h=sang_h;
        chang_m=sang_m-45;
    }

    cout<<chang_h<<" "<<chang_m;
    return 0;
}