#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T, i, j, N, x, y;
    vector< pair<int,int> > M;
    cin >> T;
    
    for( i = 0; i < T; i++){
        cin >> N;
        for( j = 0; j < N; j++){
            cin >> y, x;
            M.push_back(make_pair(x, y));
        }
        for( j = 0; j < N; j++){
            cout<<M[j].first<<"      "<<M[j].second<<endl;
        }
        for( j = 0; j < N; j++,  M.pop_back());
    }

    return 0;
}