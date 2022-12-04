#include<bits/stdc++.h>
#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream Myfile("input.txt");

    vector<vector<pair<int,int>>> FileData;
    // data segregation in c++ is kinda tough ngl
    if(Myfile.is_open()){
        string line;
        while(getline(Myfile, line)){
            pair<int, int> start, end;

            stringstream sline(line);
            string ranges;
            int i=0;

            while(getline(sline, ranges, ',')){

                stringstream rng(ranges);
                string number;

                while(getline(rng, number, '-')){
                    if(i==0){
                        start.first=stoi(number);
                    }
                    else if(i==1){
                        start.second=stoi(number);
                    }
                    else if(i==2){
                        end.first=stoi(number);
                    }
                    else{
                        end.second=stoi(number);
                    }
                    i++;
                }
            }
            FileData.push_back({start, end});
        }
    }

    // data retrival complete finally

    int no_pairs=0;
    for(int i=0;i<FileData.size();i++){
        auto LineData = FileData[i];
        pair<int,int> start, end;
        start = LineData[0], end=LineData[1];
        // check whether startptr is inside endptr and viceversa
        if((end.first<=start.first && end.second>=start.second) ||
            (start.first<=end.first && start.second>=end.second))
        {
            no_pairs++;
        };
    }
    cout << no_pairs << endl; // part 1

    int overlap=0;
    for(int i=0;i<FileData.size();i++){
        auto LineData = FileData[i];
        sort(begin(LineData), end(LineData)); // sort both the ptr
        if(LineData[1].first <= LineData[0].second){ // check whether end of 1st overlaps start of 2nd
            overlap++;
        }
    }
    cout << overlap << endl; // part 2

}
