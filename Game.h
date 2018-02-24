#ifndef GAME_H_
#define GAME_H_
#include<bits/stdc++.h>
using namespace std;

class randomize{

public:

int randomint(int limit,int begin,int xsmallerthanval);
string reversestring(string s);
pair <int,int> randompair(int xlimit,int ylimit,int xbegin,int ybegin,bool xgreaterthany);
string int2string(int x);
void mappingkeys(unordered_map <int,string> x,array<int,4> &mappedkeys);
string map2string(unordered_map <int,string> mp);
string array2string(array<int,4> arr);
string int2hex(int x);
int string2int(string s);
void prepareAns(char &ans);
void map2arrayofstrings(unordered_map <int,string> mp,array<string,4> &arr);
void array2arrayofchoices(array<int,4> mp,array<string,4> &arr);
};

class addition:public randomize{

    public:

    void Level_1(array<string,4> &arr,string &q,char &ans);
    void Level_2(array<string,4> &arr,string &q,char &ans);
    void Level_3(array<string,4> &arr,string &q,char &ans);
    void Level_4(array<string,4> &arr,string &q,char &ans);
    void Level_5(array<string,4> &arr,string &q,char &ans);
    void Level_6(array<string,4> &arr,string &q,char &ans);

    private:

    void Createchoicesmap(unordered_map <int,string> &mp,int x,int y);
    void Createchoicesset(unordered_map <int,string> &mp);
    void CreatechoicessetLevel1(unordered_map <int,string> &mp);
    void CreatechoicessetLevel2(unordered_map <int,string> &mp);

};
class subtraction :public randomize{

    public:

    void Level_1(array<string,4> &arr,string &q,char &ans);
    void Level_2(array<string,4> &arr,string &q,char &ans);
    void Level_3(array<string,4> &arr,string &q,char &ans);
    void Level_4(array<string,4> &arr,string &q,char &ans);
    void Level_5(array<string,4> &arr,string &q,char &ans);
    void Level_6(array<string,4> &arr,string &q,char &ans);

    private:

    void Createchoicesmap(unordered_map <int,string> &mp,int x,int y);
    void Createchoicesset(unordered_map <int,string> &mp);
    void CreatechoicessetLevel1(unordered_map <int,string> &mp);
    void CreatechoicessetLevel2(unordered_map <int,string> &mp);


};
class multiplication :public randomize{

    public:

    void Level_1(array<string,4> &arr,string &q,char &ans);
    void Level_2(array<string,4> &arr,string &q,char &ans);
    void Level_3(array<string,4> &arr,string &q,char &ans);
    void Level_4(array<string,4> &arr,string &q,char &ans);
    void Level_5(array<string,4> &arr,string &q,char &ans);
    void Level_6(array<string,4> &arr,string &q,char &ans);

    private:

    void Createchoicesmap(unordered_map <int,string> &mp,int x,int y);
    void Createchoicesset(unordered_map <int,string> &mp);
    void CreatechoicessetLevel1(unordered_map <int,string> &mp);
    void CreatechoicessetLevel2(unordered_map <int,string> &mp);


};

#endif // GAME_H_
