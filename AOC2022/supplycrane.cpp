#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
#include<regex>

///////////// part 1
std::string solve1(std::vector<std::stack<char>> container_stack, std::vector<std::vector<int>> moving_data)
{
    for(auto itr: moving_data){
        int times = itr[0], from=itr[1]-1, to=itr[2]-1;
        while(times--){
            container_stack[to].push(container_stack[from].top());
            container_stack[from].pop();
        }
    }
    std::string ans;
    for(auto it: container_stack){
        ans += it.top();
    }
    return ans;
}


///////////// part 2
std::string solve2(std::vector<std::stack<char>> container_stack, std::vector<std::vector<int>> moving_data)
{
    for(auto itr: moving_data){
        int times = itr[0], from=itr[1]-1, to=itr[2]-1;
        std::stack<char> tmp;
        while(times--){
            tmp.push(container_stack[from].top());
            container_stack[from].pop();
        }
        times = itr[0];
        while(times--){
            container_stack[to].push(tmp.top());
            tmp.pop();
        }
    }
    std::string ans;
    for(auto it: container_stack){
        ans += it.top();
    }
    return ans;
}


int main()
{
    std::vector<std::stack<char>> container_stack;
    std::vector<std::vector<int>> moving_data;

    std::ifstream Myfile("input.txt");
    std::vector<std::string> InputFileAsString;

    // convert the file into an array of strings
    if(Myfile.is_open()){
        std::string line;
        while(std::getline(Myfile, line)){
            InputFileAsString.push_back(line);
        }
    }

    // find the space b/w the stack lines and move part lines
    int blankLine=0;
    for(auto line: InputFileAsString){
        if(line.size()==0){
            break;
        }
        blankLine++;
    }

    // now add the above stack part into a real stack ds
    std::string stk_line = InputFileAsString[blankLine-1];
    for(int i=0;i<stk_line.size();i++){
        if(stk_line[i]==' ')continue;
        std::stack<char> tmp_stk;

        for(int j=blankLine-2;j>=0;j--){
            if(InputFileAsString[j][i]==' ' || InputFileAsString[j].size()<=i)break;
            tmp_stk.push(InputFileAsString[j][i]);
        }
        container_stack.push_back(tmp_stk);
    }

    // simple regex to store 3 groups of numbers among letters
    std::regex ptrn("move (\\d+)[ a-z]+(\\d+)[ a-z]+(\\d+)");
    std::smatch match;
    for(auto line: InputFileAsString){
        int count=0,from=0,to=0;
        if(std::regex_match(line, match, ptrn)){
            moving_data.push_back({stoi(match[1]), stoi(match[2]), stoi(match[3])});
        }
    }

    std::cout << solve1(container_stack, moving_data) << std::endl;
    std::cout << solve2(container_stack, moving_data) << std::endl;

}