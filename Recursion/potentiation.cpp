#include <iostream>
using namespace std;
int potentiation(float a,int n){
    if(n==0) return 1;
    else return a*potentiation(a,n-1);
}
int main(){
    float n;
    int p;
    cout<<"Enter a number and a potentiation"<<endl;
    cin>>n>>p;
    cout<<n<<"^("<<p<<"): "<<potentiation(n,p)<<endl;
    return 0;
}