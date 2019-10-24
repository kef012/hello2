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

vector<string> split(string str){
    vector<string> words;
    string::iterator i,j;
    
    i = str.begin();
    j = str.begin();
    cout << (*str.end()) << endl;
    while(j+2 != str.end()){ // j+2 space 
       // cout << "ccc" << endl;
        if(i != str.begin() ) j = ++i;

        i = find_if(i, str.end(), not_space);
        j = find_if(j, str.end(), space);
        if ( isspace(*j)){ 
            cout << "(*j) has space!" << endl;
        }
        string s(i, j);
        if ( isspace(s.size()-1)){ 
            cout << "space!" << endl;
        }
        
        i = i+s.size();
        j = i;
      
        cout << s << endl;
    
        words.push_back(s); 

        if(j+2 == str.end()){cout << "finish" << endl;}
    }
    cout << "bbb" << endl;
    return words;
}

int main(){

    map<string, vector<int> > counters;
    vector<string> str;
    string line;
    int lnum = 0; //行番号
    string q; //探す単語

    while(  getline(cin, line) ){
        cout << "aaa" << endl;
        ++lnum;
        if(lnum == 1 ) q = line;
        if(lnum != 1 && line.size() != 0){ 
            copy(split(line).begin(), split(line).end(), back_inserter(str));
            cout << "ccc" << endl;
            vector<string>::iterator iter = str.begin();
            while(iter != str.end()){
                if((*iter) == q ){ //もし単語集に求める単語があれば
                    counters[q].push_back(lnum); //その行を登録
                }
                ++iter;
            }
        }
        str.clear();
    }

    vector<int>::iterator iter = counters[q].begin();
    cout << q <<  " is appeared "; // c++ is appeared
    while(iter != counters[q].end()){ 
        cout << (*iter) << "\t"; // line
        ++iter;
    }
    cout << endl;

    return 0;

}