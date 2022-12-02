#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    ifstream Myfile("input.txt");

    vector<pair<char, char>> data;
    if(Myfile.is_open()){
        string line;
        while(getline(Myfile, line)){
            data.push_back({line[0], line[2]});
        }
    }

    // part 1
    unordered_map<char, char> winruleboard; //win rules
    winruleboard.insert({'A', 'Y'});
    winruleboard.insert({'B', 'Z'});
    winruleboard.insert({'C', 'X'});
    int total_score=0;

    for(int i=0;i<data.size();i++){
        char opponent = data[i].first, player = data[i].second;
        if(winruleboard[opponent]==player){ // won
            total_score+=(player-'W')+6;
        }
        else if(opponent+23==player){ //draw
            total_score+=(player-'W')+3;
        }
        else{ // lost
            total_score+=player-'W';
        }
    }
    cout << total_score << endl;

    // part 2
    unordered_map<char, char> loseruleboard;
    loseruleboard.insert({'A','Z'});
    loseruleboard.insert({'B','X'});
    loseruleboard.insert({'C','Y'});

    total_score = 0;
    for(int i=0;i<data.size();i++){
        char opponent = data[i].first, condn = data[i].second;
        if(condn == 'X'){ // lose
            total_score+=loseruleboard[opponent]-'W';
        }
        else if(condn == 'Z'){ //win
            total_score+=(winruleboard[opponent]-'W')+6;
        }
        else if(condn=='Y'){ // draw
            total_score+=(opponent-'@')+3;
        }
    }
    cout << total_score << endl;
    Myfile.close();
}