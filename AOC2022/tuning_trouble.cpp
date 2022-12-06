#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

///////// part 1
int solve1(string str){
    deque<char> chr_seq;
    set<char> seq_set;
    int pos=0;

    for(pos; pos<str.size(); pos++){
        chr_seq.push_back(str[pos]);

        if(pos>=3){ // zero based index
            seq_set.insert(chr_seq.begin(), chr_seq.end());
            if(chr_seq.size()==seq_set.size())break;

            chr_seq.pop_front();
            seq_set.clear();
        }
    }
    return pos+1; // convert to 1 based index
}

////////////// part 2
int solve2(string str){
    deque<char> chr_seq;
    set<char> seq_set;
    int pos=0;

    for(pos; pos<str.size(); pos++){
        chr_seq.push_back(str[pos]);

        if(pos>=13){ // zero based index
            seq_set.insert(chr_seq.begin(), chr_seq.end());
            if(chr_seq.size()==seq_set.size())break;

            chr_seq.pop_front();
            seq_set.clear();
        }
    }
    return pos+1; // convert to one based index
}


int main(){
    ifstream Myfile("input.txt");

    vector<string> FileData;
    if(Myfile.is_open()){
        string line;
        while(getline(Myfile, line)){
            FileData.push_back(line);
        }
    }

    string str = FileData[0];
    cout << solve1(str) << endl;
    cout << solve2(str) << endl;
}


