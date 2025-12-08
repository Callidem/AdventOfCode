#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Card{
    private:
        vector<int> wNumbers;
        vector<int> nums;
        int points = 0;
    public:
        Card(){}
        ~Card(){}
        void addWN(int n){wNumbers.push_back(n);}
        void addN(int n){nums.push_back(n);}
        vector<int> getWN(){return wNumbers;}
        vector<int> getN(){return nums;}
        void calcPoints(){
            int matches = 0;
            for(int i = 0; i < wNumbers.size(); i++){
                for(int j = 0; j < nums.size(); j++){
                    if(wNumbers[i] == nums[j]) {
                        //cout << " match: " << wNumbers[i] <<"|" << nums[j] << endl;
                        matches++;
                        break;
                    }
                }
            }
            //cout << "matches: " << matches << endl;
            if(matches > 0) points = pow(2, matches-1);
            //cout << "points" << points << endl; 
        }
        int getPoints(){ return points;}
        string print(){
            stringstream card;
            card << "card(" << points << " points) ";
            for(int i = 0; i < wNumbers.size(); i++){
                card << wNumbers[i] << " ";
            }      
            card << "| ";     
            for(int i = 0; i < nums.size(); i++){
                card << nums[i] << " ";
            }
            card << endl;
            return card.str();
        }
};

int main (void){
    
    ifstream arq;
    arq.open("input.txt");
    
    string line;
    int sum = 0, nAux;
    
    vector<Card> cards;
    while(!arq.eof()){
        stringstream wNums, nums;
        Card cAux;
        getline(arq, line, ':');
        cout << line << endl;
        getline(arq, line, '|');
        line.pop_back();
        cout << line << endl;
        wNums << line;
        while(!wNums.eof()){
            wNums >> nAux;                
            cAux.addWN(nAux);
        }
        getline(arq, line);
        nums << line;
        while(!nums.eof()){
            nums >> nAux;    
            cAux.addN(nAux);
        }
        cAux.calcPoints();
        cards.push_back(cAux);
        cout << cAux.print() << endl;
    }
    for(int i = 0; i < cards.size(); i++){
        sum += cards[i].getPoints();
    }
    cout << sum;
}