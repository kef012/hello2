#include <iostream>
#include <istream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>


bool space(char c){
    return (isspace(c));
}

bool not_space(char c){
    return (!isspace(c));
}

std::vector<std::string> split(std::string str){
    std::vector<std::string> words;
    std::string::iterator i,j;
    
    i = str.begin();
    j = str.begin();

    while(j+2 != str.end()){ // j+2 space 
        if(i != str.begin() ) j = ++i;

        if( space((*i)) ){ 
            i = i+2;
            j = i;
        }
        i = find_if(i, str.end(), not_space);
        j = find_if(j, str.end(), space);

        std::string s(i, j);
        if ( isspace(s.size()-1)){ 
            std::cout << "space!" << std::endl;
        }
        
        i = i+s.size();
        j = i;
      
        //std::cout << "push_back " << s << std::endl;
    
        words.push_back(s); 

        //if(j+2 == str.end()){std::cout << "finish" << std::endl;}
    }
    return words;
}

int main(){

    std::map<std::string, std::vector<int> > counters;
    
    std::vector<std::string> str;
    std::string line;
    int lnum = 0; //行番号
    std::string q; //探す単語

    while(  getline(std::cin, line) ){
        std::cout << "obtained line is"<< std::endl;
        std::cout << line << std::endl;
        std::cout << std::string(10,'-') << std::endl;
        ++lnum;
        
        if(lnum == 1 ){
            q = line;
            std::cout << "let's search " << q << std::endl;
        }

        if(line == ""){ std::cout << "nothing"  << std::endl;}
        if(lnum != 1 && line.size() != 0){
            str = split(line); 

        // strに記録された文字について整形を行う
        std::vector<std::string>::iterator striter;
        for(striter = str.begin(); striter < str.end(); striter++){
            //std::cout << "seikei" << std::endl;
            if((*striter).substr(0,1) == "(" ||
               (*striter).substr(0,1) == "\'" ||
               (*striter).substr(0,1) == "\""){
               (*striter).erase(0,1);
            }
            if((*striter).substr((*striter).size()-1,(*striter).size()) == ")" ||
               (*striter).substr((*striter).size()-1,(*striter).size()) == "\'" ||
               (*striter).substr((*striter).size()-1,(*striter).size()) == "?" ||
               (*striter).substr((*striter).size()-1,(*striter).size()) == ":" ||
               (*striter).substr((*striter).size()-1,(*striter).size()) == "\""){
               (*striter).pop_back();
            }
            if((*striter).substr((*striter).size()-1,(*striter).size()) == "," || 
               (*striter).substr((*striter).size()-1,(*striter).size()) == "." ||
               (*striter).substr((*striter).size()-1,(*striter).size()) == "!") {
               (*striter).pop_back();
            }
        }
        transform ((*striter).begin(), (*striter).end(), (*striter).begin(), tolower);
        // 整形ここまで
           // std::cout << "ccc" << std::endl;

            striter = str.begin();

            while(striter != str.end()){ // about a word on the line.
                std::map<std::string, std::vector<int> >::iterator mapiter = counters.begin();
                int isFound = 0;
                while(mapiter != counters.end()){ // search all of counters  
                    if( mapiter->first == (*striter) ){ //もし単語があったらisFoundを1増やす
                        isFound = 1;
                    }
                    ++mapiter;
                }

                if(isFound != 1){
                    counters[(*striter)]; //counters に登録
                  //  std::cout << (*striter) << "　is registered" << std::endl;
                }
                counters[(*striter)].push_back(lnum);
                ++striter;
            }
            str.clear();
        } 
    }
    /*
    std::map<std::string, std::vector<int> >::iterator ite = counters.begin();
    std::vector<int>::iterator linenumiterator = ite->second.begin();
    std::cout << "first " << ite->first << " "<<(*linenumiterator) << std::endl;
    */
   // map< string, vector<int> >::iterator iter = counters.begin();

    std::cout << "RESULT for " << q << std::endl;
    std::cout << ">>>>>" << q << " is appeared " << std::endl; // c++ is appeared
    std::vector<int>::iterator linenumiter = counters[q].begin();
    
    while(linenumiter != counters[q].end()){ 
        std::cout << (*linenumiter) << "\t"; // line
        ++linenumiter;
    }
    std::cout << std::endl;

    return 0;

}