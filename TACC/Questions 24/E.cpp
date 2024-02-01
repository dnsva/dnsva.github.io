#include <iostream>
#include <string>
#include <algorithm>

bool isInternallyReversiblyCyclic(const std::string& s) {
    int n = s.length();

    // Check if each rotation of s is internally reversibly cyclic
    for (int i = 0; i < n; ++i) {
        std::string rotated = s.substr(i) + s.substr(0, i);

        for (int len = 1; len < n; ++len) {
            // Extract substring t of length len starting from index 0
            std::string t = rotated.substr(0, len);

            // Check if the reverse of t is a substring of rotated
            std::string reverseT = t;
            std::reverse(reverseT.begin(), reverseT.end());

            if (rotated.find(reverseT) == std::string::npos) {
                // If not, the rotation is not internally reversibly cyclic
                break;
            }

            if (len == n - 1) {
                // If all rotations satisfy the condition, s is internally reversibly cyclic
                return true;
            }
        }
    }

    // If no rotation satisfies the condition, s is not internally reversibly cyclic
    return false;
}

int main() {
    // Read input string
    std::string s;
    std::cin >> s;

    // Check if s is internally reversibly cyclic
    int result = isInternallyReversiblyCyclic(s);

    // Output the result
    std::cout << result << std::endl;

    return 0;
}


/*

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check(const string& s){
    
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        string rotated = s.substr(i) + s.substr(0, i);
        for (int len = 1; len < n; ++len) {
            string t = rotated.substr(0, len);
            string reverseT = t;
            reverse(reverseT.begin(), reverseT.end());
            if (rotated.find(reverseT) == string::npos) {
                break;
            }
            if (len == n - 1) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cin>>s;
    cout<<check(s)<<"\n";
    return 0;
}

*/