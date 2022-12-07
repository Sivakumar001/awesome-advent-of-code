#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
#include<regex>

using namespace std;

int solve1(unordered_map<string, int> sizes){
    int ans=0;
    for(auto itr: sizes){
        if(itr.second<=100000){
            ans += itr.second;
        }
    }
    return ans;
}

int solve2(unordered_map<string, int> sizes){
    int max_allocated = 70000000 - 30000000;
    int total_used = sizes["/"];
    int needs_deletion = total_used - max_allocated;

    int best_dir = INT_MAX;
    for(auto it: sizes){
        if(it.second>=needs_deletion){
            best_dir = min(best_dir, it.second);
        }
    }
    return best_dir;
}

int main(){
    ifstream Myfile("input.txt");

    vector<string> fileData;
    if(Myfile.is_open()){
        string line;
        while(getline(Myfile, line)){
            fileData.push_back(line);
        }
    }
    // data retrival is pain.. :(
    unordered_map<string, int> sizes;
    vector<string> path;

    for(auto lines: fileData){
        if(lines[0]=='$' && lines[2]=='c'){
            string cur_path = lines.substr(5, lines.size()-5);
            if(cur_path==".."){
                path.pop_back();
            }
            else
            {
                path.push_back(cur_path);
            }
        }
        else if(lines[0]=='$' && lines[2]=='l'){
            continue;
        }
        else if(isdigit(lines[0])){
            int fsize = 0;
            for(auto chr: lines){
                if(chr==' ')break;
                fsize = fsize*10+(chr-'0');
            }
            string key_string="";
            for(auto pths: path){
                key_string+=pths;
                sizes[key_string] += fsize;
            }
        }
    }
    cout << solve1(sizes) << endl;
    cout << solve2(sizes);
}
