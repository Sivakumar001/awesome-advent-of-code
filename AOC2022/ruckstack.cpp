#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream Myfile("input.txt");

    vector<string> fileData;

    if(Myfile.is_open()){
        string line;
        while(getline(Myfile, line)){
            fileData.push_back(line);
        }
    }

    int sum_priority=0;
    for(auto line: fileData){
        int lcount[256] = {0}, rcount[256] = {0};

        int p2=line.size()/2, p1=p2-1;

        while(p1>=0 && p2<line.size()){
            lcount[line[p1--]]++;
            rcount[line[p2++]]++;
        }

        for(int i=0;i<256;i++){
            if(lcount[i]>0 && rcount[i]>0){
                char itr = i;
                if(islower(itr)){
                    sum_priority+=(itr-'a') + 1; // a-a=0 in question priority starts from 1 so +1
                }
                else{
                    sum_priority+=(itr-'A') + 27; // A-A=0 in question it starts from 27
                }
            }
        }
    }
    cout << sum_priority << endl; // part 1;

    int team_prior=0;
    for(int i=0;i<fileData.size();i+=3){

        int count1[256]={0},count2[256]={0}, count3[256]={0};

        for(auto i: fileData[i]){count1[i]++;}
        for(auto i: fileData[i+1]){count2[i]++;}
        for(auto i: fileData[i+2]){count3[i]++;}

        for(int i=0;i<256;i++){
            if(count1[i]>0 && count2[i]>0 && count3[i]>0){
                char itr = i;
                if(islower(itr)){
                    team_prior += (itr-'a')+1;
                }
                else{
                    team_prior += (itr-'A')+27;
                }
            }
        }
    }
    cout << team_prior;
}