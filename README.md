# Wordle-Solver
A Wordle Solver console application using C++ by an easy yet efficient algorithm.
## Table of Content
- [Wordle-Solver](#wordle-solver)
  * [Tools](#tools)
  * [How to enter Input](#how-to-enter-input)
  * [Algorithm Explained](#algorithm-explained)
  * [Author](#author)
## Tools
1. Code Blocks (IDE)
2. C++
3. STL library

## How to enter Input
For each bad letter (aka black letter) put '!' before it. For each possible letter (aka yellow letter) put '@' before it. For each right letter (aka green letter) put '#' before it.

Example: 

      !n@o#t!e!s
      
 where:  n,e,s are black, o is yellow, t is green
 
 **Don't put spaces between letters as input.**
## Algorithm Explained
1. Populate vector named 'v' with words inside the dictionary using "populateVector" function
2. Take input from user
3. If the letter in the word is Green, insert it in "rightLetters" vector along with its index. If the letter is Yellow, insert it in "possibleLetters" vector along with its index.
4. If the letter is black, we will check if it has been previously inserted in right or possible vector, if so we will insert it in "specialLetters" vector, else we will inser it in "badLetters" vector.
5. For each Bad letter in the word (Red Letter): 

       Iterate through the vector of words, if any word contain such bad letter, remove it from vector
 ```cpp
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
 ```
 4. For each Possible letter in the word (Yellow Letter):

            Iterate through vector of words
                  If any words doesn't contain that yellow character at all, remove it
                  If any word has yellow character in the same position as entered in input, remove it.
```cpp
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
```
5. For each Right letter (Green Letter): 
            
            Iterate through vector of words, if any word doesn't have that character in same position as entered, remove it.
```cpp
void findRightLetters(char x,int y){
    for(it = v.begin();it!=v.end();){       //removing any word which does not have green character in right position
        string temp = *it;
        temp[y]!=x?it = v.erase(it):++it;
    }
}
```
6. For each (Special letter): 

            Iterate through vector of words, if any word have that character in same position as entered, remove it.

```cpp
void eliminateSpecialLetters(char x,int y){
    for(it = v.begin();it!=v.end();){
        string temp = *it;
        temp[y]==x?it = v.erase(it):++it;
    }
}
```

> Special letter are the letters which are green and (black) at the same time. Meaning special letters are just black letters with index.
          
      
## Author 
[Yousef Kotp](https://github.com/yousefkotp)

