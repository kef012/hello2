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
    //cout << (*str.end()) << endl;
    
    while(j+2 != str.end()){ // j+2 space 
        if(i != str.begin() ) j = ++i;

        if( space((*i)) ){ 
            i = i+2;
            j = i;
        }
        i = find_if(i, str.end(), not_space);
        j = find_if(j, str.end(), space);

        if ( isspace(*j)){ //debug
            cout << "(*j) is space!" << endl;
        }

        string s(i, j);
        if ( isspace(s.size()-1)){ 
            cout << "space!" << endl;
        }
        
        i = i+s.size();
        j = i;
      
        cout << "push_back " << s << endl;
    
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
        cout << "get line"<< endl;
        cout << line << endl;
        cout << "------" << endl;
        ++lnum;
        
        if(lnum == 1 ) q = line;
        if(line == ""){ cout << "nothing"  << endl;}
        if(lnum != 1 && line.size() != 0){
            str = split(line); 
           // copy( , , back_inserter(str));
            cout << "ccc" << endl;

            vector<string>::iterator iter = str.begin();
            while(iter != str.end()){ // about a word on the line.
                map<string, vector<int> >::iterator mapiter = counters.begin();
                while(mapiter != counters.end()){ // about counters
                    if( mapiter->first != (*iter) ){ //もし単語が無いなら登録する
                        counters[(*iter)]; //coutters に登録
                        cout << (*iter) << "　is registered" << endl;
                    }
                    if(q == (*iter) ){ //もし単語集に求める単語があれば 
                        counters[q].push_back(lnum); //その行を登録
                    }
                    ++mapiter;
                }
                ++iter;
            }
            str.clear();
        } 
    }
    map<string, vector<int> >::iterator ite = counters.begin();
    cout << "first" << ite->first << endl;
   // map< string, vector<int> >::iterator iter = counters.begin();
    vector<int>::iterator iter = counters[q].begin();
    cout << q <<  " is appeared "; // c++ is appeared
    while(iter != counters[q].end()){ 
        cout << (*iter) << "\t"; // line
        ++iter;
    }
    cout << endl;

    return 0;

}