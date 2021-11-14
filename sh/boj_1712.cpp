#include<iostream>
using namespace std;
int main() {

    long fixed, variable, price;//고정비용, 가변비용, 판매가격
    long total = 0, save = 0;
    cin >> fixed >> variable >> price;
    if(variable>=price){
        cout<<"-1";
        return 0;
    }
    cout<<fixed/(price-variable) + 1;
    return 0;
}