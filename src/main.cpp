//
// Created by sb024667 on 12/21/2023.
//

// Your First C++ Program

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Array/Graph/Graph.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool differByOne(string& w1,string& w2) {
    int difCount = 0;
    for (int i = 0; i < w1.length(); ++i) {
        if (w1[i] != w2[i]) {
            ++difCount;
        }
    }
    return difCount == 1;
}

int main(){

    cout << "Enter Starting Word:" << endl;
    string start;
    string target;
    getline(cin,start);
    cout << "Enter Target Word:" << endl;
    getline(cin,target);

    std::vector<std::string> threeLetterWords;
    std::vector<std::string> fourLetterWords;
    std::vector<std::string> fiveLetterWords;
    std::ifstream newFile ("C:\\Users\\sb024667\\Desktop\\dictionay");
    if(newFile.is_open()){
        std::string tmp;
        while(getline(newFile,tmp)){
            if(tmp.length() == 3){
                threeLetterWords.push_back(tmp);
            }else if(tmp.length() == 4){
                fourLetterWords.push_back(tmp);
            }else if(tmp.length() == 5){
                fiveLetterWords.push_back(tmp);
            }
        }
    }
    array::Graph graph3 = array::Graph(threeLetterWords.size());
    array::Graph graph4 = array::Graph(fourLetterWords.size());
    array::Graph graph5 = array::Graph(fiveLetterWords.size());

    for (int i = 0; i < threeLetterWords.size(); ++i) {
        for (int j = i + 1; j < threeLetterWords.size(); ++j) {
            if (differByOne(threeLetterWords[i], threeLetterWords[j]) == 1) {
                graph3.addEdge(i, j);
                graph3.addEdge(j, i);

            }

        }
    }
    for (int i = 0; i < fourLetterWords.size(); ++i) {
        for (int j = i + 1; j < fourLetterWords.size(); ++j) {
            if (differByOne(fourLetterWords[i], fourLetterWords[j]) == 1) {
                graph4.addEdge(i, j);
                graph4.addEdge(j, i);
            }
        }
    }
    for (int i = 0; i < fiveLetterWords.size(); ++i) {
        for (int j = i + 1; j < fiveLetterWords.size(); ++j) {
            if (differByOne(fiveLetterWords[i], fiveLetterWords[j]) == 1) {
                graph5.addEdge(i, j);
                graph5.addEdge(j, i);
            }
        }
    }
    graph5.search(fiveLetterWords,start,target);

    return 0;
}

