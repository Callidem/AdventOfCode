// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string line;
    int sum, biggest;

    sum = biggest = 0;

    ifstream arq("input.txt");
    if (arq.is_open()){
        while (getline(arq, line)){
            if(!line.empty()){
                sum += stoi(line);
            }
            else {
                if(sum > biggest) biggest = sum;
                sum = 0;
            }
        }
        arq.close();
    }

    cout << "O maior numero eh " << biggest << endl;
}