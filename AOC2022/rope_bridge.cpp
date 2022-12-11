#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int solve1(vector<pair<char, int>> fileData){
    vector<pair<int,int>> tail_locations(9, {0,0});

}

pair<int, int> get_near_tail(pair<int, int> head, pair<int, int> tail){
    if(abs(head.first-tail.first)>=2){
        if(head.second<tail.second){
            tail.second--;
        }
        else{
            tail.second++;
        }
    }
    else if(abs(head.second-tail.second)>=2){
        if(head.first<tail.first){
            tail.first--;
        }
        else{
            tail.first++;
        }
    }
    else if(abs(head.first-tail.first)>=2 && abs(head.second-tail.second)>=2){
        if(head.first<tail.first){
            tail.first--;
        }
        else{
            tail.first++;
        }
        if(head.second<tail.second){
            tail.second--;
        }
        else{
            tail.second++;
        }
    }
    return tail;
}

int main(){
    ifstream Myfile("inp.txt");

    vector<pair<char, int>> fileData;
    if(Myfile.is_open()){
        string line;
        while(getline(Myfile, line)){
            int tiles = stoi(line.substr(2, line.size()-2));
            fileData.push_back(make_pair(line[0], tiles));
        }
    }
    cout << solve1(fileData) << endl;
}