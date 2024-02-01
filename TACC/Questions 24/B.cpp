//Hailstone Sequences

#include <iostream>

using namespace std;

int main(){
    
    long n;
    cin>>n; //get input 

    //two variables. One to store the last number in the sequence (prev)
    //and one to store the new number to be added to the sequence (next)
    long prev = n;
    long next = 0;

    long sequence_length = 1; //answer

    while(prev != 1){ //while the end (1) not reached

        if(prev%2 == 0){ //if even
            next = prev/2;
        }else{ //if odd
            next = 3*prev + 1;
        }

        prev = next; //update
        ++sequence_length; //add
    }
    cout<<sequence_length<<"\n"; //give answer
    return 0;
}