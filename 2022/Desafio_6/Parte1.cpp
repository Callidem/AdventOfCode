// reading a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


int main(){
    string line, markers;
    bool mFound = false;
    int mLength = 14;
    
    fstream arq("input.txt");
    getline(arq, line);

    int inicio = 0;
    while(!mFound){

        markers = line.substr(inicio, mLength);
        for(int i = 0; i < markers.length(); i++){
            if(markers.find_first_of(markers[i]) == markers.find_last_of(markers[i])) mFound = true;
            else {
                mFound = false;  
                break;
            }
        }
        inicio++;
    }
    cout << "Markers: " << markers << endl;
    cout << "First marker after char " << inicio + mLength - 1;
}