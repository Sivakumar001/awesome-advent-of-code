#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
#include<regex>

// part 1
std::string solve(std::map<int, std::stack<char>> container_stack, std::vector<std::vector<int>> moving_data)
{
    for(auto itr: moving_data){
        int times = itr[0], from=itr[1], to=itr[2];
        while(times--){
            container_stack[to].push(container_stack[from].top());
            container_stack[from].pop();
        }
    }
    std::string ans;
    for(auto it: container_stack){
        ans += it.second.top();
    }
    return ans;
}


// part 2
std::string solve(std::map<int, std::stack<char>> container_stack, std::vector<std::vector<int>> moving_data)
{
    for(auto itr: moving_data){
        int times = itr[0], from=itr[1], to=itr[2];
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
        ans += it.second.top();
    }
    return ans;
}

int main()
{
    // i apologize for the bad input here.. :(
    std::stack<char> stk1, stk2, stk3, stk4, stk5, stk6, stk7, stk8, stk9;

    // stk1.push('Z');
    // stk1.push('N');

    // stk2.push('M');
    // stk2.push('C');
    // stk2.push('D');

    // stk3.push('P');

    stk1.push('T');
    stk1.push('P');
    stk1.push('Z');
    stk1.push('C');
    stk1.push('S');
    stk1.push('L');
    stk1.push('Q');
    stk1.push('N');


    stk2.push('L');
    stk2.push('P');
    stk2.push('T');
    stk2.push('V');
    stk2.push('H');
    stk2.push('C');
    stk2.push('G');

    stk3.push('D');
    stk3.push('C');
    stk3.push('Z');
    stk3.push('F');

    stk4.push('G');
    stk4.push('W');
    stk4.push('T');
    stk4.push('D');
    stk4.push('L');
    stk4.push('M');
    stk4.push('V');
    stk4.push('C');

    stk5.push('P');
    stk5.push('W');
    stk5.push('C');

    stk6.push('P');
    stk6.push('F');
    stk6.push('J');
    stk6.push('D');
    stk6.push('C');
    stk6.push('T');
    stk6.push('S');
    stk6.push('Z');

    stk7.push('V');
    stk7.push('W');
    stk7.push('G');
    stk7.push('B');
    stk7.push('D');

    stk8.push('N');
    stk8.push('J');
    stk8.push('S');
    stk8.push('Q');
    stk8.push('H');
    stk8.push('W');

    stk9.push('R');
    stk9.push('C');
    stk9.push('Q');
    stk9.push('F');
    stk9.push('S');
    stk9.push('L');
    stk9.push('V');


    std::map<int, std::stack<char>> container_stack;
    container_stack.insert({1, stk1});
    container_stack.insert({2, stk2});
    container_stack.insert({3, stk3});
    container_stack.insert({4, stk4});
    container_stack.insert({5, stk5});
    container_stack.insert({6, stk6});
    container_stack.insert({7, stk7});
    container_stack.insert({8, stk8});
    container_stack.insert({9, stk9});

    std::ifstream Myfile("input.txt");
    std::vector<std::vector<int>> moving_data;
    if(Myfile.is_open()){
        std::regex ptrn("[ a-z]+(\\d+)[ a-z]+(\\d+)[ a-z]+(\\d+)");
        std::smatch match;
        int count=0,from=0,to=0;


        std::string line;
        while(std::getline(Myfile, line)){
            std::regex_match(line, match, ptrn);
            moving_data.push_back({stoi(match[1]), stoi(match[2]), stoi(match[3])});
        }
    }
    std::cout << solve(container_stack, moving_data);
}