/*#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string wordToNum(string line){
    int firstNum, lastNum, firstPos = 0, lastPos = 0;
    int wordsFPos[10], wordsLPos[10];

    string words[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout << line << endl;
    //cout << "A" << endl;
    
    while(firstPos != 10000){    
        firstPos = 10000;
        for(int i = 0; i < 10; i++){
            if(line.find(words[i]) != string::npos && line.find(words[i]) < firstPos) {
                firstPos = line.find(words[i]);
                firstNum = i;
            }
        }
        if(firstPos != 10000) line.replace(line.find(words[firstNum]), words[firstNum].size(), to_string(firstNum));
    }
    cout << "B" << endl;
    
    //cout << "firstNum:" << firstNum << endl;
    //cout << "C" << endl;
    
    //cout << "lastNum:" << lastNum << endl;
    
    
    if(lastPos != 0) if(line.rfind(words[lastNum]) != string::npos) line.replace(line.rfind(words[lastNum]), words[lastNum].size(), to_string(lastNum));
    cout << line << endl;
    return line;
}

int main (void){
    
    ifstream arq;
    arq.open("input.txt");
    
    string line;
    int sum = 0;

    while(!arq.eof()){
        getline(arq, line);
        line = wordToNum(line);
        int first, last, fPos, lPos;
        for(int i = 0; i < line.size(); i++){//primeiro numero
            if(line[i] > 47 && line[i] < 58) {
                first = line[i] - 48;
                fPos = i;
                cout << "Somando: " << line[i] << endl;
                break;
            }
        }
        for(int i = line.size(); i >= 0; i--){//ultimo numero
            if(line[i] > 47 && line[i] < 58) {
                last = line[i] - 48;
                lPos = i;
                cout << "Somando: " << line[i] << endl;
                break;
            }
        }
        if(fPos != lPos) sum += 10*first + last;
        cout << "sum" << sum << endl;
    }
    cout << sum;
}*/
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>

void GetInputs(std::vector<std::string>* vec) {
    std::ifstream ifs;
    ifs.open("input.txt", std::ios::in);
    std::string buf;
    while(std::getline(ifs, buf)) {
        vec->push_back(buf);
    }
}

int main() {
    std::vector<std::string> inputs;
    std::vector<std::string> numbers = 
        { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    GetInputs(&inputs);
    int64_t ans = 0;
    for (auto&& s : inputs) {
        int32_t first = s.length() - 1, last = 0;
        for (int i = 0; i < 9; i++) {
            char c = '1' + i;
            int32_t pos = s.find(c);
            if (pos != s.npos) {
                first = std::min(first, pos);
            }
            pos = s.rfind(c);
            if (pos != s.npos) {
                last = std::max(last, pos);
            }
        }
        int32_t first_word = -1, last_word = -1;
        for (int i = 0; i < 9; i++) {
            int32_t pos = s.find(numbers.at(i));
            if (pos != s.npos && pos < first) {
                first = pos;
                first_word = i + 1;
            }
            pos = s.rfind(numbers.at(i));
            if (pos != s.npos && pos > last) {
                last = pos;
                last_word = i + 1;
            }
        }
        if (first_word == -1) {
            first_word = s[first] - '0';
        }
        if (last_word == -1) {
            last_word = s[last] - '0';
        }
        int64_t number = first_word * 10 + last_word;
        ans += number;
    }
    std::cout << ans << std::endl;
}