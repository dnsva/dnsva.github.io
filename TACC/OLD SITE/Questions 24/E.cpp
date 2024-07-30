//Reversibly Cyclic Strings
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
THINGS TO CONSIDER

When they say that t should be a substring of any ROTATION of s, 
you do not have to actually worry about rotating anything. A simple
way to account for all rotations is just to double s.

If s = "abc", s_doubled would be "abcabc". "abcabc" accounts for all
rotations of "abc".

PROOF:
All rotations of "abc":
"abc" -> "bca" -> "cab" -> "abc" -> etc.
OR
"abc" -> "cab" -> "bca" -> "abc" -> etc. 
Are included in "abcabc"

A systematic solution to the ENTIRE QUESTION includes:
1. Find all substrings of s
2. For each substring:
    a. flip it
    b. see if it is in s_doubled
    c. if it is not, break out of everything, s is not internally reversibly cyclic
    d. otherwise continue
3. If you pass all checks, s is internally reversibly cyclic

The code below combines everything together efficiently such that you check the
shortest substrings first (in case they already fail the checks, there is no need
to go through the other substrings). First we go through substrings of length 1, 
then length 2, and so on. For each substring t, reverse it, and check if it is
inside s_doubled.
*/

int main(){
    string s;
    cin>>s;

    string s_doubled = s+s; //concatenate s

    bool flag = true; //***

    for(int substr_len = 1; substr_len <= s.length(); ++substr_len){

        bool stop = false; //this flag is needed since this is a double for loop. break only breaks out of the nested one

        for(int i = 0; i < s.length(); ++i){

            if(i + substr_len > s.length()){ //to not go out of bounds
                break;
            }

            string t = s.substr(i,substr_len); //make the substring
            reverse(t.begin(), t.end()); //flip it
            if(s_doubled.find(t) == string::npos){ //check if it is in any rotation of s
                flag = false; //***
                stop = true;
                break;
            }

        }

        if(stop) break;
    }


    if(flag){ //output results
        cout<<"1\n";
    }else{
        cout<<"0\n";
    }

    return 0;
}

