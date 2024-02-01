//Cut in Line
//Arrays solution

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n; //the initial number of people
    cin>>n;

    string line[n+1000]; //this is the largest amount of memory possibly needed
    int number_of_people_in_line = n; //add when there is a cut, sub when a leave

    /* Get the current line input: */
    for(int i = 0; i < n; ++i){
        string current_input;
        cin>>current_input;
        line[i] = current_input;
    }

    int changes; //the amount of changes that will be done to the line
    cin>>changes;

    for(int i = 0; i < changes; ++i){ //for each change

        string instruction; //this will be either "cut" or "leave"
        cin>>instruction;

        if(instruction.compare("cut") == 0){ //CUT
            string cutting_person, reference_person;
            cin>>cutting_person>>reference_person;

            int ref_index = 0; //find what index the person to cut is at
            for(int j = 0; j < number_of_people_in_line; ++j){
                if(line[j] == reference_person){
                    ref_index = j;
                    break;
                }
            }

            //TO ADD THE NEW PERSON, CREATE AN EMPTY SPOT AT THE RIGHT
            //INDEX AND SHIFT ALL OTHER ELEMENTS RIGHT

            //1) SHIFT ALL ELEMENTS AFTER REF_INDEX RIGHT 1
            for(int j = number_of_people_in_line; j > ref_index; --j){
                line[j] = line[j-1];
            }

            //2) SET THE REF_INDEX TO THE NEW PERSON
            line[ref_index] = cutting_person;

            ++number_of_people_in_line; //one more person now

        }else{ //LEAVE
            string leaving_name;
            cin>>leaving_name;

            int index = 0; //find what index the leaving person is at
            for(int j = 0; j < number_of_people_in_line; ++j){
                if(line[j] == leaving_name){
                    index = j;
                    break;
                }
            }

            //SHIFT EVERYTHING AFTER THE PERSON LEFT (this removes them)
            for(int j = index; j < number_of_people_in_line-1; ++j){
                line[j] = line[j+1];
            }

            --number_of_people_in_line; //one less person now
        }
    }

    
    for(int i = 0; i < number_of_people_in_line; ++i){ //Print all the people and not the empty array positions
        cout<<line[i]<<"\n";
    }

    return 0; 
}