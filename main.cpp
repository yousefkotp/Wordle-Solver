#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
vector<string>v;
vector<string>::iterator it;
vector<char>badLetters;                 //char value for each black color
vector<pair<char,int>>possibleLetters; //char value and index for each yellow character
vector<pair<char,int>>rightLetters;     //char value and index for each green character
vector<pair<char,int>>specialLetters;
void populateVector(string filename){       //populating vector from dictionary text file
    ifstream file;
    file.open(filename);
    string s;
    while(getline(file,s)){
        v.push_back(s);
    }
    file.close();
}
void eliminateBadLetters(char x){       //removing words containing black characters
    for(it=v.begin();it!=v.end();){
        bool flag =false;
        string temp = *it;
        for(int i=0;i<=4;i++){
            if(x==temp[i]){
                flag =true;
                break;
            }
        }
        flag?it=v.erase(it):++it;
    }
}
void eliminatePossibleLetters(char x,int y){
    for(it=v.begin();it!=v.end();){         //removing any word which does not have yellow character in right position
        string temp =*it;
        temp[y]==x?it = v.erase(it):++it;
    }

    for(it =v.begin();it!=v.end();){        //removing any word which does not have any yellow character at all
        string temp =*it;
        bool flag =false;
        for(int k=0;k<=4;k++){
            if(x==temp[k]){
                flag =true;
                break;
            }
        }
        flag?++it:it=v.erase(it);
    }
}
void findRightLetters(char x,int y){
    for(it = v.begin();it!=v.end();){       //removing any word which does not have green character in right position
        string temp = *it;
        temp[y]!=x?it = v.erase(it):++it;
    }
}
void eliminateSpecialLetters(char x,int y){
    for(it = v.begin();it!=v.end();){
        string temp = *it;
        temp[y]==x?it = v.erase(it):++it;
    }
}
int main()
{
    cout<<"Enter EXIT to finish the program"<<endl;
    cout<<"Best words to start with:"<<endl;
    cout<<"notes, resin, tares, senor"<<endl;
    cout<< "'!' for black, '@' for yellow, '#' for green (before each letter)"<<endl;
    populateVector("wordsdictionary.txt");                  // you can change this dictionary to any dictionary you want
    while(true){
        string s;
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);        //transferring string into lower characters

        if(s=="exit")
            return 0;

        bool visited[26];                           //to make sure that repeated characters doesn't clash (like abbey for example)


        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                i++;
                visited[s[i]-'a']=true;
                rightLetters.push_back(make_pair(s[i],i/2));
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='@'){
                i++;
                possibleLetters.push_back(make_pair(s[i],i/2));
                visited[s[i]-'a']=true;
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='!'){
                i++;
                if(!visited[s[i]-'a'])
                    badLetters.push_back(s[i]);
                else
                    specialLetters.push_back(make_pair(s[i],i/2));
                visited[s[i]-'a']=true;
            }
        }

        for(int i=0;i<rightLetters.size();i++)
            findRightLetters(rightLetters[i].first,rightLetters[i].second);
        for(int i=0;i<possibleLetters.size();i++)
            eliminatePossibleLetters(possibleLetters[i].first,possibleLetters[i].second);
        for(int i=0;i<badLetters.size();i++)
            eliminateBadLetters(badLetters[i]);
        for(int i=0;i<specialLetters.size();i++)
            eliminateSpecialLetters(specialLetters[i].first,specialLetters[i].second);

        for(auto i:v)                   //printing element of vector after handling all characters
            cout<<i<<endl;

        if(v.size()==1){
            cout<<"The answer is: "<<v[0]<<endl;
            return 0;
        }else
            cout<<"there is "<<v.size()<<" possible solution"<<endl;

        for(int i=0;i<26;i++)               //reseting all the used variable since we already deleted from vector
            visited[i]=false;
        rightLetters.clear();
        possibleLetters.clear();
        badLetters.clear();
        specialLetters.clear();

    }
    return 0;
}
