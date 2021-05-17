#include<iostream>
#include<vector>
#include<string>
#include "debug.h"
using namespace std;
void create(vector<string> a,int i){
    if(i<9){
        a[i/3][i%3] = 'X';
        create(a,i+1);
        a[i/3][i%3] = 'O';
        create(a,i+1);
        a[i/3][i%3] = '_';
        create(a,i+1);
    }else{
    print(a);
    }
}
int main(){
    vector<string> a(3,"   ");
    create(a,0);

}