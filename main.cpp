#include<bits/stdc++.h>
#include"Interface.h"
#include"Game.h"
#include"IMAGES.h"
int G_over=0;
Interface game;
addition a;
subtraction s;
multiplication m;
/**MAP OF RANKS GIVIN TO PLAYER BASED ON KEYS FROM a TO f **/
map<char,string> Rank=
{
    {'a',"Farmer"},
    {'b',"Craft_Man"},
    {'c',"Soldier"},
    {'d',"Scriber"},
    {'e',"Priest"},
    {'f',"Great_Pharaoh"}
};

/**MAIN OPTIONS**/
string option1="N ) New game",option2="L ) Load last state",option3="    Rank : ",option4="X ) exit";

/**VARIABLES TO GET LEVEL QUESTION AND TRUE ANSWER**/
array<string,4>arr;
string q;
char ans;
void intro();//displaying the intro of the game
void check_mainOption(bool=0);//to check the main options of the game "Exit","Load game","New game"
void Q_and_A();//Checking question and answer between level and player
void level_1(int );//level 1
void level_2(int );//level 2
void level_3(int );//level 3
void level_4(int );//level 4
void level_5(int );//level 5
void level_6(int );//level 6
void play(int=6);
int main()
{
    intro();
    check_mainOption(1);
    play(1);

    return 0;
}

void intro()
{
    /**Displaying the intro image**/
    game.display_image(intro_image,I,1,1);
    Sleep(5000);    //delay 5 seconds
    /**Reading data from the intro file **/
    ifstream Intro("intro.txt");
    string st;
    game.reset_display(0);
    getline(Intro,st);
    /**sending the data of the file to display**/
    game.into_display(st,2,3);
    Sleep(2000);//delay 2 second
    Intro.close();//closing the file intro.txt
    game.reset_display(alll);
    game.display_choices(option1,option2,"Last Rank : "+Rank[game.RANK],option4,0);

}

void check_mainOption(bool pause)
{
    if(pause)system("pause>nul");
    if(GetAsyncKeyState(78)||GetAsyncKeyState(110))///N & n
    {
        game.RANK='a';
    }
    else if (GetAsyncKeyState(88)||GetAsyncKeyState(120))///X & x
    {
        game.reset_display(0);
        game.display_image(game_over,g,5,2);
        Sleep(3000);
        game.Exit();
    }
    else if (GetAsyncKeyState(76)||GetAsyncKeyState(108))///L & l
    {
        game.load_data();
    }
    else if(pause)
    {
        cout<<"\a";
        check_mainOption(pause);
    }
}
void Q_and_A()
{
    game.reset_display(leave_choices);
    game.TrueAnswer(ans);
    game.into_display("Question  :  "+q,9,15);
    game.into_display("Answer    : ",10,15);
    game.display_choices(arr[0],arr[1],arr[2],arr[3]);

    game.TakeUserAnswer();
    check_mainOption();
    while(!game.pressedTrueKey())
    {
        if(G_over==2){
        game.reset_display(0);
        game.display_image(game_over,g,5,2);
        Sleep(3000);
        game.Exit();
        }
        game.into_display("  refused",10,26);
        cout<<"\a";
        game.TakeUserAnswer();
        check_mainOption();
        ++G_over;
    }
    if(game.pressedTrueKey())
    {
        game.into_display("  accepted",10,26);
      ///  Sleep(500);
    }

}
void level_1(int b)
{
    G_over=0;
    game.reset_display(alll);
    game.display_choices("","",option3+Rank[game.RANK],option4,0);
    while (b>0)
    {
        a.Level_1(arr,q,ans);
        Q_and_A();

        s.Level_1(arr,q,ans);
        Q_and_A();

        m.Level_1(arr,q,ans);
        Q_and_A();

        --b;
    }
    game.RANK='b';
}
void level_2(int b)
{
    G_over=0;
    game.reset_display(0);
    game.display_image(pyramid_name,p1,4,4);
    Sleep(5000);
    ifstream level("level_2.txt");
    while(!level.eof())
    {
        game.reset_display(0);
        string st;
        getline(level,st);

        game.into_display(st,2,3);
        Sleep(2000);
    }
    level.close();
    game.reset_display(alll);
    game.display_choices("","",option3+Rank[game.RANK],option4,0);
    while (b>0)
    {
        a.Level_2(arr,q,ans);
        Q_and_A();

        s.Level_2(arr,q,ans);
        Q_and_A();

        m.Level_2(arr,q,ans);
        Q_and_A();

        --b;
    }
    game.reset_display(0);
    game.display_image(pyramid_image,p2,5,1);
    game.into_display("Level completed..Get ready for the next level",18,10);
    Sleep(3000);
    game.RANK='c';
}
void level_3(int b)
{
    G_over=0;
    game.reset_display(0);
    game.display_image(sphinx_name,s1,16,6);
    Sleep(5000);
    ifstream level("level_3.txt");
     while(!level.eof())
    {
        game.reset_display(0);
        string st;
        getline(level,st);

        game.into_display(st,2,3);
        Sleep(2000);
    }
    level.close();
    game.reset_display(alll);
    game.display_choices("","",option3+Rank[game.RANK],option4,0);

    while (b>0)
    {
        a.Level_3(arr,q,ans);
        Q_and_A();

        s.Level_3(arr,q,ans);
        Q_and_A();

        m.Level_3(arr,q,ans);
        Q_and_A();

        --b;
    }
    game.reset_display(0);
    game.display_image(sphinx_image,s2,1,1);
    game.into_display("Level completed..Get ready for the next level",18,10);
    Sleep(3000);
    game.RANK='d';
}
void level_4(int b)
{
    G_over=0;
    game.reset_display(0);
    game.display_image(lotus_name,L1,18,6);
    Sleep(5000);
    ifstream level("level_4.txt");
     while(!level.eof())
    {
        game.reset_display(0);
        string st;
        getline(level,st);

        game.into_display(st,2,3);
        Sleep(2000);
    }
    level.close();
    game.reset_display(alll);
    game.display_choices("","",option3+Rank[game.RANK],option4,0);

    while (b>0)
    {
        a.Level_4(arr,q,ans);
        Q_and_A();

        s.Level_4(arr,q,ans);
        Q_and_A();

        m.Level_4(arr,q,ans);
        Q_and_A();

        --b;
    }
    game.reset_display(0);
    game.display_image(lotus_image,L2,10,2);
    game.into_display("Level completed..Get ready for the next level",18,10);
    Sleep(3000);
    game.RANK='e';
}
void level_5(int b)
{
    G_over=0;
    /**there is no image**/
    ifstream level("level_5.txt");
     while(!level.eof())
    {
        game.reset_display(0);
        string st;
        getline(level,st);

        game.into_display(st,2,3);
        Sleep(2000);
    }
    level.close();
    game.reset_display(alll);
    game.display_choices("","",option3+Rank[game.RANK],option4,0);

    while (b>0)
    {
        a.Level_5(arr,q,ans);
        Q_and_A();

        s.Level_5(arr,q,ans);
        Q_and_A();

        m.Level_5(arr,q,ans);
        Q_and_A();

        --b;
    }
    game.reset_display(0);
    /**there is no image**/
    game.into_display("Level completed..Get ready for the next level",18,10);
    Sleep(3000);
    game.RANK='f';
}
void level_6(int b)
{
    G_over=0;
    /**there is no image**/
    ifstream level("level_6.txt");
     while(!level.eof())
    {
        game.reset_display(0);
        string st;
        getline(level,st);

        game.into_display(st,2,3);
        Sleep(2000);
    }
    level.close();
    game.reset_display(alll);
    game.display_choices("","",option3+Rank[game.RANK],option4,0);

    while (b>0)
    {
        a.Level_6(arr,q,ans);
        Q_and_A();

        s.Level_6(arr,q,ans);
        Q_and_A();

        m.Level_6(arr,q,ans);
        Q_and_A();

        --b;
    }
    game.reset_display(0);
    game.into_display("Game completed....Thank you",10,15);
    Sleep(3000);
    game.reset_display(0);
    game.display_image(intro_image,I,1,1);
    Sleep(3000);
}
void play(int n)
{
    switch(game.RANK)
    {
    case 'a':level_1(n);
    case 'b':level_2(n);
    case 'c':level_3(n);
    case 'd':level_4(n);
    case 'e':level_5(n);
    case 'f':level_6(n);
    }
}
