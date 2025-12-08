#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Game{
    private:
        int n;
        int red, green, blue;
        bool possible;
    public:
        Game(){red = 0; green = 0; blue = 0;}
        ~Game(){}
        Game(int i) { setN(i); red = 0; green = 0; blue = 0;}
        void setN(int i){ n = i; }
        void setR(int r){ red = r; }
        void setG(int g){ green = g; }
        void setB(int b){ blue = b; }
        void setAll (int r, int g, int b) { 
            red = r; green = g; blue = b;
            if(red <= 12 && green <= 13 && blue <= 14) possible = true; else false;    
        }
        int getN(){ return n; }
        int getR(){ return red; }
        int getG(){ return green; }
        int getB(){ return blue; }
        string print() {
            stringstream game;
            game << "red " << red << ", green " << green << ", blue " << blue;
            return game.str();
        }
        bool getPossible(){
            return possible;
        }
};

int main(void){

    ifstream arq;
    arq.open("input.txt");
    
    string line;
    int sum = 0;
    vector <Game> games;
    Game gAux;
    int r, g, b, nAux;

    while(!arq.eof()){
        stringstream gameStr;
        getline(arq, line);
        cout << "A" << line << endl;
        gameStr << line;
        gameStr >> line;
        getline(gameStr, line, ':');
        cout << "B" <<  line << endl;
        gAux = Game(stoi(line));
        r = g = b = 0;
        while(!gameStr.eof()){
            stringstream set;
            getline(gameStr, line, ';');
            cout << "C" <<  line << endl;
            set << line;
            while(!set.eof()){
                for(int i = 0; i < 3; i++) {
                    set >> nAux;
                    cout << "nAux:" << nAux << endl;
                    set >> line;
                    cout << "C1 " << line << endl;
                    if(line[line.size()-1] == ',') line.pop_back();
                    cout << "C2 " << line << endl;
                    if(line == "red" && nAux > r) {cout << "RED" <<endl; r = nAux; }
                    if(line == "green" && nAux > g) {cout << "GREEN" <<endl; g = nAux; }
                    if(line == "blue" && nAux > b) {cout << "BLUE" <<endl; b = nAux;}
                    cout << "r " << r << "/ g " << g << "/ b " << b << endl;
                    cout << "D " <<  line << endl;
                }
            }
        }
        cout << "r " << r << "/ g " << g << "/ b " << b << endl;
        gAux.setAll(r, g, b);
        cout << gAux.print() << endl;
        games.push_back(gAux);
    }
    for(int i = 0; i < games.size(); i++){
        if(games[i].getPossible() == true) sum += games[i].getN();
    }
    cout << "Answer: " << sum << endl;
}