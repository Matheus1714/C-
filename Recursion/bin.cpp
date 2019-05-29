#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;

string alfabet = "abcdefghaiklmnopqrstuvwxyz";

int decimal(string bin){
    int num, i;
    for(i=bin.size()-1, num =0; i>=0;i--){
        num = num + (bin[i] == '1') *pow(2,bin.size()-1-i);
    }
    return num;
}

char letra(int num){
    return alfabet[num-1];
}

int main(){
    ifstream input;
    string bin;

    input.open("text.txt");

    while(!input.eof()){
        bin = input.get();
        
        letra(decimal(bin));
    }

    cout<<endl;

    input.close();
    return 0;
}