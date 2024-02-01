//Cut in Line

#include <iostream>
#include <vector>

using namespace std;

//solution with vectors (would be the same for arraylists)

int main(){

    int n; //the initial number of people
    cin>>n;

    vector<string>line; //stores the people in the line

    /* Get the current line input: */
    for(int i = 0; i < n; ++i){
        string current_input;
        cin>>current_input;
        line.push_back(current_input);
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
            for(int j = 0; j < line.size(); ++j){
                if(line[j] == reference_person){
                    ref_index = j;
                    break;
                }
            }

            line.insert(line.begin()+ref_index, cutting_person); //add the new person

        }else{ //LEAVE
            string leaving_name;
            cin>>leaving_name;

            int index = 0; //find what index the leaving person is at
            for(int j = 0; j < line.size(); ++j){
                if(line[j] == leaving_name){
                    index = j;
                    break;
                }
            }
            line.erase(line.begin()+index); //get rid of the element
        }
    }

    for(string s : line){ //output each person in the line
        cout<<s<<"\n";
    }

    return 0; 
}