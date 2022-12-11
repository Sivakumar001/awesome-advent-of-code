#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//////////////// part 1
int solve1(vector<pair<string, int>> fileData){
    int cycles = 1;
    int value = 1;
    int questions = 20;
    int total = 0;

    for(auto it: fileData){
        int cur_cycle = (it.first=="noop"?1:2);
        for(int i=0;i<cur_cycle;i++){
            if(cycles==questions){
                total += questions*value;
                questions += 40;
            }
            cycles++;
        }
        value+=it.second;
    }
    return total;
}

/////////////////// part 2
void solve2(vector<pair<string, int>> fileData){
    int cycles = 0;
    int values = 0;
    vector<vector<char>> ans(6, vector<char>(40,'.'));

    for(auto it: fileData){
        //create sprite array
        vector<char> sprite(40,'.');
        for(int i=0;i<3 && (values+i)<40;i++){
            sprite[(values+i)%40] = '#';
        }

        int cur_cycle = (it.first=="noop"?1:2);

        for(int i=0;i<cur_cycle;i++){
            if(sprite[cycles%40]=='#'){
                ans[cycles/40][cycles%40] = '#';
            }
            cycles++;
        }

        values = values+it.second;
    }
    cout << "\n" << endl;
    for(auto it: ans){
        for(auto itr: it){
            cout << itr;
        }
        cout << "\n";
    }
}


int main(){
    ifstream Myfile("inp.txt");
    vector<pair<string, int>> fileData;
    if(Myfile.is_open()){
        string line;
        while(getline(Myfile, line)){
            string command = line.substr(0, 4);
            int val = 0;
            if(command=="noop"){
                val = 0;
            }
            else{
                val = stoi(line.substr(5, line.size()-5));
            }
            fileData.push_back({command, val});
        }
    }
    cout << solve1(fileData) << endl;
    solve2(fileData);
}