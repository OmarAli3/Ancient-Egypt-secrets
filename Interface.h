#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>//std::cin && std::cout
#include<windows.h>//Sleep() && system() &&  Hex of keyboard keys
#include<iomanip>//setw()
#include<conio.h> //getch() taking input from user without pressing enter
#include<fstream> //Dealing with files
#include<vector>

#define alll 1
#define choices_only 2
#define leave_choices 3
using namespace std;

class Interface {
public:
     char RANK='a';
     Interface();
void into_display(string, int, int);
void TrueAnswer(char);
void TakeUserAnswer();
bool pressedTrueKey();
void display_image(string[], int, int, int=2);
void reset_display(byte =1);
void display_choices(string, string, string, string, int=1);
void save_data();
void load_data();
void Exit();
     ~Interface();
private:
char TrueAns,TokenAnswer;
string display[21]=
{
    " ___________________________________________________________________ ",
    "|###################################################################|",
    "|#                               #*#                               #|",
    "|#                                *                                #|",
    "|################################___################################|",
    "|###################################################################|",
    "|#                                                                 #|",
    "|#                                                                 #|",
    "|#                                                                 #|",
    "|#                                                                 #|",
    "|#                                                                 #|",
    "|#                                                                 #|",
    "|#                                                                 #|",
    "|#                                                                 #|",
    "|#                                                                 #|",
    "|#                                                                 #|",
    "|#                                                                 #|",
    "|#                                                                 #|",
    "|#                                                                 #|",
    "|###################################################################|",
    " ___________________________________________________________________ "
};
void Loading_screen();
void into_screen();
bool  check_skip();
void set_display();

};

#endif // INTERFACE_H
