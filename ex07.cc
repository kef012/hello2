#include <iostream>
#include <istream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <cstdlib>


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

        if( space((*i)) ){ //段落があった場合二文字進める
            i = i+2;
            j = i;
        }
        i = find_if(i, str.end(), not_space);
        j = find_if(j, str.end(), space);

        std::string s(i, j);
        /*
        if ( isspace(s.size()-1)){ 
            std::cout << s << " has space!" << std::endl;
        //    std::string s(i, j-1);
        }
        */
        
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
    std::string q = ""; //探す単語

    while(  getline(std::cin, line) ){
        /*
        std::cout << "obtained line is"<< std::endl;
        std::cout << line << std::endl;
        std::cout << std::string(10,'-') << std::endl;
        */
        ++lnum;
        transform(line.begin(), line.end(), line.begin(), tolower);
        
        if(lnum == 1 ){
            counters[line];
            q = (*counters.begin()).first;
            std::cout << "let's search " << (*counters.begin()).first << std::endl;
        }

        if(line == ""){ std::cout << "nothing"  << std::endl;}

        if(lnum != 1 && line.size() != 0){ 
            str = split(line); 
            // strに記録された文字について整形を行う
            std::vector<std::string>::iterator striter;
            
            for(striter = str.begin(); striter < str.end(); striter++){
                //std::cout << "before : " << (*striter) << std::endl;
                if((*striter).substr(0,1) == "(" ||
                   (*striter).substr(0,1) == "\'" ||
                   (*striter).substr(0,1) == "\""){
                   (*striter).erase(0,1);
                }
                if((*striter).substr((*striter).size()-1,(*striter).size()) == ")" ||
                   (*striter).substr((*striter).size()-1,(*striter).size()) == "\'" ||
                   (*striter).substr((*striter).size()-1,(*striter).size()) == "\""){
                   (*striter).pop_back();
                }
                if((*striter).substr((*striter).size()-1,(*striter).size()) == "," || 
                   (*striter).substr((*striter).size()-1,(*striter).size()) == "." ||
                   (*striter).substr((*striter).size()-1,(*striter).size()) == ":" ||
                   (*striter).substr((*striter).size()-1,(*striter).size()) == "?" ||
                   (*striter).substr((*striter).size()-1,(*striter).size()) == "!") {
                   (*striter).pop_back();
                }
            }
            /*
            for(striter = str.begin(); striter < str.end(); striter++){
                std::cout << "after : " << (*striter) << std::endl;
            }
            */
            // 整形ここまで

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
                    //std::cout << (*striter) << " is registered" << std::endl;
                }
                counters[(*striter)].push_back(lnum);
                ++striter;
            }
            str.clear();
        } 
    }
    
    //検索結果出力
    std::string query = q;
    std::cout << "let's search " << q <<"!"<< std::endl;
    // let's search c++! って出力されるはず！
    std::cout << "なんでや" << std::endl;
    std::map<std::string, std::vector<int> >::iterator mapiter;
    mapiter = counters.begin();
    while(mapiter != counters.end()){
       
            std::cout << mapiter->first << " is appeared at ";
            std::vector<int>::iterator linenumiter = counters[mapiter->first].begin();

        while(linenumiter != counters[mapiter->first].end()){ 
            std::cout << (*linenumiter) << " "; // line
            ++linenumiter;
        }
        std::cout << std::endl;
         if(mapiter->first == query){
            /*
            std::cout << "RESULT " ; 
            std::cout << mapiter->first << " is appeared " << std::endl;
            */
            break;
        }
       ++mapiter;
    }
    /*
    std::vector<int>::iterator linenumiter = counters[q].begin();
    while(linenumiter != counters[q].end()){ 
        std::cout << (*linenumiter) << "\t"; // line
        ++linenumiter;
    }
    std::cout << std::endl;
    */
    return 0;

}