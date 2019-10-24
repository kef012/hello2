#include <iostream>
#include <istream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


bool space(char c){
    return (isspace(c));
}

bool not_space(char c){
    return (!isspace(c));
}

vector<string> split(const string& l){
    vector<string> str;
    string::iterator i,j;

    //i = find_if(i, l.end(), not_space);
   // j = find_if(j, l.end(), space);
    string s(i, j);
    
    str.push_back(s);

}
int main(int argc, char* argv[]){

    map<string, vector<int>> counters;
    vector<string> str;
    string l;
    int lnum = 0;
    string q = argv[1];

    while(  getline(cin, l) ){
    ++lnum;
   // str = split(l);
        counters[q].push_back(lnum);

    }
    vector<int>::iterator iter = counters[argv[1]].begin();
    cout << argv[0] <<  " is appeared "; // c++ is appeared
    while(iter != counters[argv[1]].end()){ 
        cout << (*iter) << " "; // line
    }
    cout << endl;
    return 0;

}