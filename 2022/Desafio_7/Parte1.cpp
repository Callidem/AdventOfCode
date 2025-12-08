// reading a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


class Folder{
    public:
        Folder *father;
        int level;//numero de espacos antes do "-"
        int directFileSize;
        string name;
        vector<Folder> subFolder;

        Folder(){
            father = nullptr;
            level = 0;
            name = "/";
        }

        Folder(int l, string n){
            level = l;
            name = n;
        }

        Folder(string n, Folder *papa)
        {
            level = papa->level + 2;
            name = n;
        }
        void addSubFolder(string n){
            Folder f(n, this);
            this->subFolder.push_back(f);
        }
        void addSubFile(int d){
            directFileSize += d;
        }
        int size(){
            return directFileSize + subFolder.size();
        }
        int searchSubFolder(string n){
            for(int i = 0; i < subFolder.size(); i++){
                if(subFolder[i].name == n) return i;
            }
            return -1;
        }
};

Folder* findRoot(Folder *f){
    Folder *aux = f;
    while(true){
        if(aux->father != nullptr) aux = aux->father;
        else return aux;
    }
}

string bigFolders(Folder *root){
    string aux;
    if(root->size() > 100000) aux = root->name;
    for(int i = 0; i < root->subFolder.size(); i++){
        if(root->subFolder[i].size() > 100000) aux = aux + 
    }
}

int main(){
    string line, sAux;
    int fSize = 0;

    fstream arq("input.txt");

    getline(arq, line);
    
    Folder currentDir;

    while(!arq.eof()){
        cout << "A" << endl;
        getline(arq, line);
        string name, size;
        stringstream ss;
        ss << line;
        ss >> sAux;
        if(sAux == "$"){
            ss >> sAux;
            if(sAux == "cd"){
                ss >> sAux;
                if(sAux == ".." && currentDir.level > 0) currentDir = *currentDir.father;
                else{
                    int j = currentDir.searchSubFolder(sAux);
                    if(j > 0)
                    currentDir = currentDir.subFolder[j];
                }
            }
        }
        else if(sAux == "dir"){
            ss >> sAux;
            currentDir.addSubFolder(sAux);
        }
        else {
            ss >> sAux;
            currentDir.addSubFile(stoi(sAux));
        }
    }
    Folder *father, *current;

}