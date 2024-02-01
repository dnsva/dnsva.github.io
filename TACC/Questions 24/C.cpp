//C

#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n, w, h, t;
    cin>>n>>w>>h;

    int max = sqrt(w*w + h*h);  //the maximum length a stick can be
                                // this is the hypotenuse
    
    for(int i = 0; i<n; ++i){
        cin>>t;
        if(t <= max){
            cout<<"DA\n";
        }else{
            cout<<"NE\n";
        }
    }
    return 0;
}