#include <iostream>
#include <istream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

bool space(char c){
    return (isspace(c));
}

bool not_space(char c){
    return (!isspace(c));
}

vector<string> split(string& str){
    vector<string> words;
    string::iterator i,j;
    i = str.begin();

    i = find_if(i, str.end(), not_space);
    j = find_if(j, str.end(), space);
    string s(i, j);
    
    words.push_back(s);

    return words;
}

int main(){

    map<string, vector<int> > counters;
    vector<string> str;
    string line;
    int lnum = 0; //行番号
    string q; //探す単語

    while(  getline(cin, line) ){
        ++lnum;
        if(lnum == 1 ) q = line;
        else{ 
            str = split(line);

            vector<string>::iterator iter = str.begin();
            while(iter != str.end()){
                if((*iter) == q ){ //もし単語集に求める単語があれば
                    counters[q].push_back(lnum); //その行を登録
                }
                ++iter;
            }
        }
    }

    vector<int>::iterator iter = counters[q].begin();
    cout << q <<  " is appeared "; // c++ is appeared
    while(iter != counters[q].end()){ 
        cout << (*iter) << " "; // line
        ++iter;
    }
    cout << endl;
    return 0;

}