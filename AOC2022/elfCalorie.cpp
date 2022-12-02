#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    ifstream fileReader("input.txt");
    vector<int> elfCalories;
    int cur_calories=0;
    // extract data from input
    if(fileReader.is_open()){
        string line;
        while(getline(fileReader, line)){
            if(line=="\n"){
                elfCalories.push_back(cur_calories);
                cur_calories=0;
            }
            else{
                cur_calories+=stoi(line);
            }
        }
    }
    // part 1
    cout << *max_element(begin(elfCalories), end(elfCalories)) << endl;
    // part 2
    sort(begin(elfCalories), end(elfCalories), greater<int>());
    int first3_calorie = 0;
    for(int i=0;i<3;i++){
        first3_calorie+=elfCalories[i];
    }
    cout << first3_calorie << endl;
    return 0;
}