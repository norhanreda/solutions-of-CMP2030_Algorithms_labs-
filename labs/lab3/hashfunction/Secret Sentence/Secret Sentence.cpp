
 #include <unordered_map> 
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include<utility>
using namespace std;

// Helper function
void preprocess(string& str) {
    // Removing punctuation
    for (int i = 0, len = str.size(); i < len; i++)
    {
        // Check whether parsing character is punctuation or not 
        if (ispunct(str[i]))
        {
            str.erase(i--, 1);
            len = str.size();
        }
    }

    // Converting to lower case
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

// Helper function
vector<string> readFile() {
    ifstream f("two-cities.txt"); //taking file as inputstream

    string file;

    if (f) {
        ostringstream ss;
        ss << f.rdbuf(); // reading data
        file = ss.str();

        // Removes punctuation and converts to lower case
        preprocess(file);

        // Split into tokens on space
        istringstream iss(file);
        vector<string> tokens{ istream_iterator<string>{iss},
                          istream_iterator<string>{}  };

        return tokens;
    }

    vector<string> empty;
    return empty;
}
//////////////////////////////

bool compare(pair<string,int> & p1,pair<string,int> & p2)
{

return (p1.second>p2.second);

}
   
  void sortum(unordered_map<string,int> &m,vector<pair<string,int>> & v)
  {
    

for(auto & ite:m)
{

v.push_back(ite);

}
sort(v.begin(), v.end(), compare); 

  }
   





/////////////////////////////



// TODO: IMPLEMENT THIS FUNCTION
string findSecret(vector<string> tokens) 
{
    // Hint: you can use std::unordered_map and std::sort
     unordered_map<string, int> m;
     for(int i=0;i<tokens.size();i++ )
           m[tokens[i]]=0;

for(int i=0;i<tokens.size();i++)
{
    if (m.find(tokens[i]) != m.end() )
           
          m[tokens[i]]++;
          
          
}
string *arr1=new string[m.size()];
int *arr2=new int[m.size()];
int j=0;
for(auto it =m.begin();it!=m.end();it++)
{
    arr1[j]=it->first;
    arr2[j]=it->second;
    j++;

}

vector<pair<string,int>> v;
sortum(m,v);


/*for (auto& it : v) {
  
        cout << it.first << ' '
             << it.second << endl;
    }*/









 string result = "";

result=v[10].first+" "+v[22].first+" "+v[21].first+" "+v[42].first +" "+v[2].first +" "+v[46].first +" ";










   

    return result;
}


int main() {

    vector<string> tokens = readFile();
 cout<<findSecret(tokens)<<endl;
   


    return 0;
}
