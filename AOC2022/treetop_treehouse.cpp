#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int find_scene(vector<string> fileData, int row, int col){
    int cur_tree = fileData[row][col];
    int row_len=fileData.size(), col_len=fileData[0].size();

    int left=0,right=0,top=0,bottom=0;

    int l=row-1,r=row+1;

    // top
    while(l>=0){
        top++;
        if(fileData[l][col]>=cur_tree){
            break;
        }
        l--;
    }

    // bottom
    while(r<col_len){
        bottom++;
        if(fileData[r][col]>=cur_tree){
            break;
        }
        r++;
    }

    l=col-1,r=col+1;
    // left
    while(l>=0){
        left++;
        if(fileData[row][l]>=cur_tree){
            break;
        }
        l--;
    }
    // right
    while(r<row_len){
        right++;
        if(fileData[row][r]>=cur_tree){
            break;
        }
        r++;
    }

    return left*right*top*bottom;
}

int solve2(vector<string> fileData){
    int max_scenic=INT_MIN;
    int r=fileData.size(),c=fileData[0].size();

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int cur_scenic = find_scene(fileData, i, j);
            max_scenic = max(max_scenic, cur_scenic);
        }
    }
    return max_scenic;
}

bool is_visible(vector<string> fileData, int row, int col){
    char cur_tree = fileData[row][col];
    int row_len=fileData.size(), col_len=fileData[0].size();

    bool left=1,right=1,top=1,bottom=1;

    int l=row-1,r=row+1;
    // top
    while(l>=0){
        if(fileData[l][col]>=cur_tree){
            top=0;break;
        }
        l--;
    }
    // bottom
    while(r<col_len){
        if(fileData[r][col]>=cur_tree){
            bottom=0;break;
        }
        r++;
    }

    l=col-1,r=col+1;
    // left
    while(l>=0){
        if(fileData[row][l]>=cur_tree){
            left=0;break;
        }
        l--;
    }
    // right
    while(r<row_len){
        if(fileData[row][r]>=cur_tree){
            right=0;break;
        }
        r++;
    }

    return left|right|top|bottom;
}

int solve1(vector<string> fileData){
    int count=0;
    int r=fileData.size(), c=fileData[0].size();

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(is_visible(fileData, i, j)){
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<string> fileData;
    ifstream Myfile("input.txt");

    if(Myfile.is_open()){
        string line;
        while(getline(Myfile, line)){
            fileData.push_back(line);
        }
    }
    cout << solve1(fileData) << endl;
    cout << solve2(fileData);
}
