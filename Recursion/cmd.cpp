#include <iostream>
using namespace std;
int cmd(int m, int n){
    if(m==0&&n==0) return -1;
    else if(m>0&&n==0) return m;
    else if(m==0&&n>0) return n;
    else return cmd(n,m%n);
}
int main(){
    int m,n;
    cout<<"Enter a two numbers"<<endl;
    cin>>m>>n;
    cout<<"cmd("<<m<<","<<n<<") = "<<cmd(m,n)<<endl;
    return 0;
}