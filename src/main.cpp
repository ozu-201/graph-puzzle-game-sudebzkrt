//
// Created by sb024667 on 12/21/2023.
//

// Your First C++ Program

#include <iostream>
#include "List/Graph/Graph.h"
#include <string>
#include <fstream>
#include <vector>

using namespace list;

std::vector<std::string> readDictionary(const std::string& filename){
    std::vector<std::string> words;
    std::ifstream dictionaryFile(filename);
    std::string word;
    while(dictionaryFile>> word){
    words.push_back(word);
}
return words;
}

void createGraphForWordLength(Graph& graph,const std::vector<std::string>&words, int wordLength){
    for(const std::string&word:words){
        if(word.length() == wordLength){
            graph.addNode(word);
        }
    }
}

int main() {
const std::string dictionaryFileName="sjhkshgfhbka";
const int vertexCount=26;
std::vector<std::string>dictionaryWords= readDictionary(dictionaryFileName);
Graph graph3(vertexCount);
Graph graph4(vertexCount);
Graph graph5(vertexCount);
    createGraphForWordLength(graph3,dictionaryWords,3);
    createGraphForWordLength(graph4,dictionaryWords,4);
    createGraphForWordLength(graph5,dictionaryWords,5);
}
