#include <iostream>
using namespace std;
bool BS(int x,int inf,int sup,int *vet){
    if(inf>sup) return false;
    else{
        int med=(inf+sup)/2;
        if(x==vet[med]) return true;
        else if(x<vet[med]) return BS(x,inf,med-1,vet);
        else if(x>vet[med]) return BS(x,med+1,sup,vet);
    }
    
}
int main(){
    int element;
    int n;
    int *vet;
    cout<<"What is a length of the vector?"<<endl;
    cin>>n;
    vet = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        cout<<i+1<<" : ";
        cin>>vet[i];
    }
    cout<<endl;
    cout<<"Enter with the element serached:";
    cin >> element;
    cout<<(BS(element,0,n-1,vet) ? "The element is in vector" : "The element isn't in vector")<<endl; 
    return 0;
}