//GCD

#include <iostream>

using namespace std;

int main(){
    int A, B;
    cin>>A>>B;
    for(int i = min(A,B); i > 0; --i){ //start at the max possible gcd and go down
        if(A%i==0 && B%i==0){
            cout<<i<<"\n";
            break;
        }
    }
    return 0;
}