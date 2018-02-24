#include"Interface.h"

Interface::Interface()
{
    /**CONSTRUCTOR TO Configure SCREEN AND LOAD DATA**/
    set_display();
    Loading_screen();
    load_data();
}
Interface::~Interface()
{
    /**DESTRUCTOR TO TO AUTOMATIC SAVE DATA AFTER FINISHING**/
    save_data();
}

void Interface::into_display(string s,int row,int colomn)
{
    /**SENDING STRINGS TO THE MAIN ARRAY OF DISPLAY**/
    int sizeOf_s=s.size();///get size of coming string
    int widthOf_d=display[row].size()-4;///get size of the row of our shape
    while((sizeOf_s!=0)&&(sizeOf_s>=widthOf_d-colomn))///IN CASE WIDTH OF STRING LINE IS GREATER THAN THE WIDTH OF THE GAME SCREEN
    {
        display[18].replace(13,38, "<<<<press Enter to skip this intro>>>>");
        ///DIVIDING THE STRING TO SMALL PARTS EQUAL WIDTH OF GAME SCREEN
        string st=s.substr(0,widthOf_d-colomn);
        display[row].replace(colomn, widthOf_d - colomn, st);
        s.erase(0,(int)st.size());
        ///ADING '-' AT THE END OF LINE IF THE LAST WORD IN THE LINE IS CUT
        if(s[0]!=' '&&st[st.size()-1]!=' ')
             display[row][widthOf_d]='-';
        ///IF THERE IS A SPACE AT THE BEGIN OF A LINE...DELETE THIS SPACE
        else if (s[0]==' ')s.erase(0,1);
        sizeOf_s=s.size();
        if(check_skip()==1)return;
        ++row;
        into_screen();
        ///DELAY BETWEEN EVERY LINE
        Sleep(800);
        if(row==18)///CLEARING THE SCREEN IF THE STRING REACHED THE LAST LINE OF GAME SCREEN AND RESET THE CURSOR ON THE FIRST LINE
        {
            Sleep(2000);
            reset_display(0);
            row=2;
        }
    }
    ///IN CASE WIDTH OF STRING LINE IS LESS THAN THE WIDTH OF THE GAME SCREEN
    display[row].replace(colomn,sizeOf_s,s);
    into_screen();
}
void Interface::display_image(string image[], int sz,int colomn, int row)
{
    reset_display(0);
    /**SENDING IMAGE PIXELS TO THE ARRAY OF THE DISPLAY**/
    for(int i=0; i<sz; ++i)display[row++].replace(colomn,image[i].size(),image[i]);
    into_screen();
}
void Interface::TrueAnswer(char TrueAns)
{
    /***ASSIGN THE VALUE OF THE TRUE ANSWER TO THE PRIVATE CHAR VAR TrueAns***/
    this->TrueAns=TrueAns;
}

void Interface::TakeUserAnswer()
{
    /**TAKING ANSWER FROM USER WITHOUT PRESS ENTER AND WITHOUT DISPLAY IT ON SCREEN**/
    TokenAnswer = getch();
    if(TokenAnswer==0x0D)TakeUserAnswer();
}

void Interface::set_display()
{
    /***FORMING OUR MAIN GAME SHAPE***/
    /***EVERY SHAPE HAS A HEXA CODE **/
///0xffffffcd  ═
///0xfffffff7  ≈
///0xffffffc9  ╔

///0xffffffc8  ╚

///0xffffffba  ║
///0xffffffbb  ╗

///0xffffffbc  ╝

    display[0][0]=0xffffffc9;
    display[0][1]=0xffffffcd;
    display[0][display[0].size()-1]=0xffffffbb;
    display[0][display[0].size()-2]=0xffffffcd;
    display[19][0]=0xffffffc8;
    display[19][1]=0xffffffcd;
    display[19][display[0].size()-1]=0xffffffbc;
    display[19][display[0].size()-2]=0xffffffcd;
    for(int i=2; i<display[0].size()-2; ++i)
    {
        display[0][i]=0xfffffff7;
        display[19][i]=0xfffffff7;
    }
    for(int i=1; i<19; ++i)
    {
        display[i][0]=0xffffffba;
        display[i][display[0].size()-1]=0xffffffba;

    }
}
void Interface::reset_display(byte b)
{
    string spaces= "#                                                                 #",
           inner_border="###################################################################";
    /**automatic reset to the inner border**/
    display[1].replace(1,inner_border.size(),inner_border);
    display[5].replace(1,inner_border.size(),inner_border);
    inner_border.replace(32,3,"___");
    display[4].replace(1,inner_border.size(),inner_border);
    switch(b)
    {
    case 0:
    {
        /**TO FREE ALL THE GAME DISPLAY EXCEPT THE INNER AND OUTER BORDERS**/
        string space= "                                                                   ";
        for(int i=1; i<19; ++i)display[i].replace(1,space.size(),space);
        break;
    }
    case alll :/**TO FREE ALL THE GAME DISPLAY EXCEPT THE INNER AND OUTER BORDERS**/
    {
        /**TO FREE THE AREA IN THE MIDDLE OF THE GAME**/
        for(int i=6; i<19; ++i)display[i].replace(1,spaces.size(),spaces);
        /**TO FREE THE AREA OF THE MAIN CHOICES**/
        /**AND SEPARATE THE CHOICES BY "*" AND "#*#" **/
        spaces.replace(32,3,"#*#");
        display[3].replace(1,spaces.size(),spaces);
        spaces.replace(32,3,"#*#");
        display[2].replace(1,spaces.size(),spaces);
        break;
    }
    case choices_only:  /**TO FREE THE AREA OF CHOICES ONLY **/
    {
        spaces.replace(32,3,"#*#");
        display[3].replace(1,spaces.size(),spaces);
        spaces.replace(32,3,"#*#");
        display[2].replace(1,spaces.size(),spaces);

        break;
    }

    case leave_choices:  /**TO FREE THE AREA IN THE MIDDLE OF THE GAME ONLY AND LEAVE CHOICES**/
    {
        for(int i=6; i<19; ++i)display[i].replace(1,spaces.size(),spaces);
        break;
    }

    }
}
bool Interface::pressedTrueKey()
{
    /***CHECK IF THE USER PRESSED THE KEY OF THE TRUE ANSWER ***/
    if(TokenAnswer==TrueAns)return 1;
    else return 0;
}
bool Interface::check_skip()
{
    if(GetAsyncKeyState(0x0D))return 1;///Enter key
    else return 0;
}
void Interface::Loading_screen()
{
    /***RANDOMIZE THE NUMBER OF DISPLAYING THE WORD "LOADING" AND "." ON THE SCREEN***/
    srand(time(NULL));
    int l=min(rand()%3+1,rand()%4+1);
    for(int j=0; j<l; ++j)
    {
        reset_display(0);
        int k=rand()%7+3;
        string s="loading";
        for(int i=0; i<k; ++i)
        {
            into_display(s,9,24);
            Sleep(300);
            s+=".";
        }
    }
    /**CHANGING THE FONT COLOR TO RED**/
    system("color 4");
}
void Interface::display_choices(string a, string b, string c, string d,int x)
{
   /**TELLING THE USER HOW TO ANSWER QUESTIONS**/
    into_display(" Press the key of your choice ",5,20);
    int r1,r2,c1,c2;
    /***IF r!=1 DISPLAYING MAIN CHOICES ON THE TOP OF SCREEN. ROW NUMBER 2 AND 3***/
    /***IF r=1 DISPLAYING ANSWER CHOICES ON THE  THE ROW NUMBER 13 AND 15 ***/
    if(x!=1)
    {
        r1=2;
        r2=3;
        c1=4;
        c2=38;
    }
    else
    {
        r1=13;
        r2=15;
           c1=14;
        c2=30;
    }
    into_display(a,r1,c1);
    into_display(b,r1,c2);
    into_display(c,r2,c1);
    into_display(d,r2,c2);
}
void Interface::into_screen()
{
    system("cls");   /**CLEARING THE SCREEN**/
    /***Display & Making the game in the middle of screen***/
    cout<<"\n\n\n\n\n";
    for(int i=0; i<21; ++i)cout<<setw(90)<<display[i]<<endl;
}

void Interface::load_data()
{
    /**CREATING ifstream OBJECT NAMED loadD TO LOAD DATA FROM FILE NAMED score.txt**/
    ifstream loadD("score.txt");
        loadD>>RANK;
    /**CLOSING FILE TO AVOID CRASHES AND MAKE IT AVAILABLE FOR OTHER USAGE**/
    loadD.close();
}

void Interface::save_data()
{
    /**CREATING Ofstream OBJECT NAMED saveD TO SAVE DATA TO FILE NAMED score.txt**/
    ofstream saveD("score.txt");
        saveD<<RANK;
    /**CLOSING FILE TO AVOID CRASHES AND MAKE IT AVAILABLE FOR OTHER USAGE**/
    saveD.close();
    reset_display(0);
    into_display("Data saved successfully",9,20);
}

void Interface::Exit()
{
    /***TO EXIT THE GAME***/
   exit(0);

}
