#include<bits/stdc++.h>
#include"Game.h"
using namespace std;

int randomize::randomint(int limit,int begin=0,int xsmallerthanval=1e7){
    srand (time(NULL));
    int x;
    do{
        x=rand()%limit+begin;
    }while(x>xsmallerthanval);
    return x;
}
string randomize::reversestring(string s){
    string st=s;
    reverse(st.begin(),st.end());
    return st;
}
pair <int,int> randomize::randompair(int xlimit,int ylimit,int xbegin=1,int ybegin=1,bool xgreaterthany=0){
    int x,y;
   /*
      do{
        x=randomint(xlimit,xbegin);//rand form xlimit to xbegin
        y=randomint(ylimit,ybegin);
    }while(xgreaterthany&&x<y);//inneeding of spacific number < theother
  */
   /****Edited****/
      x=randomint(xlimit,xbegin);//rand form xlimit to xbegin
      y=randomint(ylimit,ybegin);
      if(xgreaterthany&&x<=y)x=randomint(xlimit,y+1);
    return make_pair(x,y);
}
string randomize::int2string(int x){
    char sb[ 100 ];  // array of char where buffering string to int2string
    sprintf( sb,"%d", x );//fastconvertion int to array of char (bufferarray,"string",values)
    return sb;

}

int randomize::string2int(string s){
    int r = 0;
     istringstream sin(s);
     sin >> r;
      return r;
       }
string randomize::int2hex(int x){
    char sb[ 100 ];  // array of char where buffering string to int2string
    sprintf( sb,"%x", x );//fastconvertion int to array of char (bufferarray,"string",values)
    return sb;
}
void randomize::prepareAns(char &ans){
        string temp =int2hex(ans);
        ans=temp[0];
}

void randomize::mappingkeys(unordered_map <int,string> x,array<int,4> &mappedkeys){
    int i=0;
    for(auto p:x){
        mappedkeys[i]=p.first;
        i++;
    }
}
string randomize::map2string(unordered_map <int,string> mp){
    string st="";
    int j=1;
    for(auto i:mp){
        st+=int2string(j)+')'+i.second+"\t\t";
        j++;
    }
    return st;
}
string randomize::array2string(array<int,4> arr){
    string st="";
    int j=1;
    for(auto i:arr){
        st+=int2string(j)+')'+int2string(i)+"\t\t";
        j++;
    }
    return st;
}
void randomize::map2arrayofstrings(unordered_map <int,string> mp,array<string,4> &arr){
    int j=1;
    for(auto i:mp){
        arr[j-1]=int2string(j)+')'+i.second;
        j++;
    }
}
void randomize::array2arrayofchoices(array<int,4> mp,array<string,4> &arr){
    int j=1;
    for(auto i:mp){
        arr[j-1]=int2string(j)+')'+int2string(i);
        j++;
    }
}


    void addition::Createchoicesmap(unordered_map <int,string> &mp,int x=9,int y=9){
        do{
            pair<int,int>num=randompair(x,y,1,2);
            string ansstring=int2string(num.first)+" + "+int2string(num.second);//createanswerstring
            mp.insert({num.first+num.second,ansstring});//inserting answer and its string
        }while(mp.size()<4);
    }
    void addition::Createchoicesset(unordered_map <int,string> &mp){
        int x,y,z;
        do{
            x=randomint(8,2),y=randomint(7,3),z=randomint(9,1);
            string ansstring=int2string(x)+" + "+int2string(y)+" + "+int2string(z);//createanswerstring
            mp.insert({x+y+z,ansstring});//inserting answer and its string
        }while(mp.size()<4);

    }
    void addition::CreatechoicessetLevel1(unordered_map <int,string> &mp){
        int ans;
        string AnswerString;
        do{
            pair<int,int>num=randompair(19,18,1,2);//randomizing pair of numbers
            ans=num.first+num.second;//calculating answer
            AnswerString=int2string(num.first)+" + "+int2string(num.second);
            mp.insert({ans,AnswerString});
        }while(mp.size()<4);
    }
    void addition::CreatechoicessetLevel2(unordered_map <int,string> &mp){
        int ans;
        string AnswerString;
        do{
            pair<int,int>num=randompair(19,18,1,2,1);//randomizing where x > y
            ans=num.first+num.second; //print folowing [ ] + %d = %d first y second x
            AnswerString="[ ] + "+int2string(num.second)+" = "+int2string(ans);
            ans=num.first;
            mp.insert({ans,AnswerString});
        }while(mp.size()<4);
    }
    void addition::Level_1(array<string,4> &arr,string &q,char &ans){
        unordered_map<int,string>mp;
        array<int,4> mappedkeys;
        CreatechoicessetLevel1(mp);
        mappingkeys(mp,mappedkeys);
        array2arrayofchoices(mappedkeys,arr);
        ans=randomint(4);//randomizing answer
        q=mp[mappedkeys[ans]]+" =";//string for answer
        ans++;
        prepareAns(ans);
    }
    void addition::Level_2(array<string,4> &arr,string &q,char &ans){
        unordered_map<int,string>mp;
        array<int,4> mappedkeys;
        CreatechoicessetLevel2(mp);
        mappingkeys(mp,mappedkeys);
        array2arrayofchoices(mappedkeys,arr);
        ans=randomint(4);//randomizing answer
        q=mp[mappedkeys[ans]];//string for answer
        ans++;
        prepareAns(ans);
    }
    void addition::Level_3(array<string,4> &arr,string &q,char &ans){
        unordered_map <int,string> mp;//map for holding choices
        Createchoicesmap(mp);//creating choices
        map2arrayofstrings(mp,arr);//creating string of choices
        array<int,4> mappedkeys;//array for mapping keys
        mappingkeys(mp,mappedkeys);//mapping keys
        ans=randomint(4);//randomizing answer
        q=int2string(mappedkeys[ans]);//string for answer
        ans++;//prepare answer for comparing by +1 on it
        prepareAns(ans);
    }
    void addition::Level_4(array<string,4> &arr,string &q,char &ans){
        unordered_map <int,string> mp;
        Createchoicesmap(mp);//creating answers
        array<int,4> mappedkeys;
        mappingkeys(mp,mappedkeys);//mappingkeys answers
        map2arrayofstrings(mp,arr);//creating string of choices
        int operation=randomint(2);//random between Smallest and Greatest
        if (operation){//geting answer using distance between pointers
            ans=max_element(mappedkeys.begin(),mappedkeys.end())-mappedkeys.begin()+1;
            q="Greatest?";
        }else{
            ans=min_element(mappedkeys.begin(),mappedkeys.end())-mappedkeys.begin()+1;
            q="Smallest?";
        }
        prepareAns(ans);
    }
    void addition::Level_5(array<string,4> &arr,string &q,char &ans){
        unordered_map <int,string> mp;
        Createchoicesmap(mp);//creating answers
        array<int,4> mappedkeys;
        mappingkeys(mp,mappedkeys);//mappingkeys answers
        map2arrayofstrings(mp,arr);
        ans=randomint(4);
        int subtract;
        string AnswerString;
        bool found=0;
        do{//creating question
            subtract=randomint(9,1,mappedkeys[ans]);//random value to subtract
            AnswerString=int2string(mappedkeys[ans]-subtract)+" + "+int2string(subtract);//creating AnswerString
            found=0;//flag for dublicatied answer
            string ReversedAnswerString=reversestring(AnswerString);//revers stringanswer for 0 dublication
            for(auto i:mp){//search for dublication
                if(i.second==AnswerString)found=1;
                else if(i.second==ReversedAnswerString)found=1;
            }
        }while(found);//return above in case of dublication
        ans++;
        q=AnswerString;
        prepareAns(ans);
    }
    void addition::Level_6(array<string,4> &arr,string &q,char &ans){
        unordered_map<int,string>mp;
        array<int,4> mappedkeys;
        Createchoicesset(mp);
        mappingkeys(mp,mappedkeys);
        map2arrayofstrings(mp,arr);
        ans=randomint(4);
        q=mp[mappedkeys[ans]];
        /***Edited***/
        string n1=q.substr(0,1),n2=q.substr(4,1),n3=q.substr(8,1);
        int N1=string2int(n1),N2=string2int(n2),N3=string2int(n3);
        int x=randomint(N2,1);
        N2-=x;N1+=x;
        int y=randomint(N1,1);
        N1-=y;N3+=y;
        q=int2string(N1)+" + "+int2string(N2)+" + "+int2string(N3)+" =";
        ans++;
        /***Edited***/

        prepareAns(ans);
    }


    void subtraction::Createchoicesmap(unordered_map <int,string> &mp,int x=20,int y=9){
        do{
            pair<int,int>num=randompair(x,y,1,1,1);
            string ansstring=int2string(num.first)+" - "+int2string(num.second);//createanswerstring
            mp.insert({num.first-num.second,ansstring});//inserting answer and its string
        }while(mp.size()<4);
    }
    void subtraction::Createchoicesset(unordered_map <int,string> &mp){
        int x,y,z;
        do{
            x=randomint(9,19),y=randomint(9,2),z=randomint(9,1);
            string ansstring=int2string(x)+" - "+int2string(y)+" - "+int2string(z);//createanswerstring
            mp.insert({x-y-z,ansstring});//inserting answer and its string
        }while(mp.size()<4);
    }
    void subtraction::CreatechoicessetLevel1(unordered_map <int,string> &mp){
            int ans;
            string AnswerString;
            do{
                pair<int,int>num=randompair(19,8,2,1,1);//randomizing pair of numbers
                ans=num.first-num.second;//calculating answer
                AnswerString=int2string(num.first)+" - "+int2string(num.second);
                mp.insert({ans,AnswerString});
            }while(mp.size()<4);
        }
        void subtraction::CreatechoicessetLevel2(unordered_map <int,string> &mp){
            int ans;
            string AnswerString;
            do{
                pair<int,int>num=randompair(19,18,1,2);//randomizing where x > y
                ans=num.first+num.second; //print folowing [ ] + %d = %d first y second x
                AnswerString="[ ] - "+int2string(num.second)+" = "+int2string(num.first);
                mp.insert({ans,AnswerString});
            }while(mp.size()<4);
        }
        void subtraction::Level_1(array<string,4> &arr,string &q,char &ans){
            unordered_map<int,string>mp;
            array<int,4> mappedkeys;
            CreatechoicessetLevel1(mp);
            mappingkeys(mp,mappedkeys);
            array2arrayofchoices(mappedkeys,arr);
            ans=randomint(4);//randomizing answer
            q=mp[mappedkeys[ans]]+" =";//string for answer
            ans++;
            prepareAns(ans);
        }
        void subtraction::Level_2(array<string,4> &arr,string &q,char &ans){
            unordered_map<int,string>mp;
            array<int,4> mappedkeys;
            CreatechoicessetLevel2(mp);
            mappingkeys(mp,mappedkeys);
            array2arrayofchoices(mappedkeys,arr);
            ans=randomint(4);//randomizing answer
            q=mp[mappedkeys[ans]];//string for answer
            ans++;
            prepareAns(ans);
        }
    void subtraction::Level_3(array<string,4> &arr,string &q,char &ans){
        unordered_map <int,string> mp;//map for holding choices
        Createchoicesmap(mp);//creating choices
        map2arrayofstrings(mp,arr);//creating string of choices
        array<int,4> mappedkeys;//array for mapping keys
        mappingkeys(mp,mappedkeys);//mapping keys
        ans=randomint(4);//randomizing answer
        q=int2string(mappedkeys[ans]);//string for answer
        ans++;//prepare answer for comparing by +1 on it
    prepareAns(ans);
    }
    void subtraction::Level_4(array<string,4> &arr,string &q,char &ans){
        unordered_map <int,string> mp;
        Createchoicesmap(mp);//creating answers
        array<int,4> mappedkeys;
        mappingkeys(mp,mappedkeys);//mappingkeys answers
        map2arrayofstrings(mp,arr);//creating string of choices
        int operation=randomint(2);//random between Smallest and Greatest
        if (operation){//geting answer using distance between pointers
            ans=max_element(mappedkeys.begin(),mappedkeys.end())-mappedkeys.begin()+1;
            q="Greatest?";
        }else{
            ans=min_element(mappedkeys.begin(),mappedkeys.end())-mappedkeys.begin()+1;
            q="Smallest?";
        }
        prepareAns(ans);
    }
    void subtraction::Level_5(array<string,4> &arr,string &q,char &ans){
        unordered_map <int,string> mp;
        Createchoicesmap(mp);//creating answers
        array<int,4> mappedkeys;
        mappingkeys(mp,mappedkeys);//mappingkeys answers
        map2arrayofstrings(mp,arr);
        ans=randomint(4);
        int add;
        string AnswerString;
        bool found=0;
        do{//creating question
            add=randomint(20,1,mappedkeys[ans]);//random value to add
            AnswerString=int2string(mappedkeys[ans]+add)+" - "+int2string(add);//creating AnswerString
            found=0;//flag for dublicatied answer
            string ReversedAnswerString=reversestring(AnswerString);//revers stringanswer for 0 dublication
            for(auto i:mp){//search for dublication
                if(i.second==AnswerString)found=1;
                else if(i.second==ReversedAnswerString)found=1;
            }
        }while(found);//return above in case of dublication
        ans++;//prepare answer for comparing by +1 on it
        q=AnswerString;
        prepareAns(ans);
    }
    void subtraction::Level_6(array<string,4> &arr,string &q,char &ans){
        unordered_map<int,string>mp;
        array<int,4> mappedkeys;
        Createchoicesset(mp);//creating answers
        mappingkeys(mp,mappedkeys);//mapping map keys
        map2arrayofstrings(mp,arr);//creating answers string
        ans=randomint(4);//random answers form choices
        q=mp[mappedkeys[ans]];//creating question
        /***Edited***/
        string n1=q.substr(0,2),n2=q.substr(5,2),n3=q.substr(9,2);
        int N1=string2int(n1),N2=string2int(n2),N3=string2int(n3);
       /***1st sol***/
         int x=randomint(N2,1);
         int y=randomint(2);
         if(y==1){

            N1+=(2*x);
            N2+=x;
            N3+=x;
         }
         else {
            N1+=x;
            N2+=x;
         }
         q=int2string(N1)+" - "+int2string(N2)+" - "+int2string(N3)+" =";
       /***2nd sol***/
       /*
        for(;;){
           int x=randomint(9,19),y=randomint(9,2),z=randomint(9,1);
           if((N1!=x||N2!=y||N3!=z)&&((x-y-z)==(N1-N2-N3)))
           {
            q=int2string(x)+" - "+int2string(y)+" - "+int2string(z)+" =";
               break;
           }
        }
        */
        /***Edited***/

        ans++;//prepare answer for comparing by +1 on it
    prepareAns(ans);
    }


    void multiplication::Createchoicesmap(unordered_map <int,string> &mp,int x=9,int y=9){
        mp.clear();
        do{
            pair<int,int>num=randompair(x,y);
            string ansstring=int2string(num.first)+" x "+int2string(num.second);//createanswerstring
            mp.insert({num.first*num.second,ansstring});//inserting answer and its string
        }while(mp.size()<4);
    }
    void multiplication::Createchoicesset(unordered_map <int,string> &mp){
        int x,y,z;
        do{
            x=randomint(8,2),y=randomint(7,3),z=randomint(9,1);
            string ansstring=int2string(x)+" x "+int2string(y)+" x "+int2string(z);//createanswerstring
            mp.insert({x*y*z,ansstring});//inserting answer and its string
        }while(mp.size()<4);
    }
    void multiplication::CreatechoicessetLevel1(unordered_map <int,string> &mp){
        int ans;
        string AnswerString;
        do{
            pair<int,int>num=randompair(5,4);//randomizing pair of numbers
            ans=num.first*num.second;//calculating answer
            AnswerString=int2string(num.first)+" x "+int2string(num.second);
            mp.insert({ans,AnswerString});
        }while(mp.size()<4);
    }
    void multiplication::CreatechoicessetLevel2(unordered_map <int,string> &mp){
        int ans;
        string AnswerString;
        do{
            pair<int,int>num=randompair(9,9,2,1,1);//randomizing where x > y
            ans=num.first*num.second; //print folowing [ ] + %d = %d first y second x
            AnswerString="[ ] x "+int2string(num.second)+" = "+int2string(ans);
            ans=num.first;
            mp.insert({ans,AnswerString});
        }while(mp.size()<4);
    }
    void multiplication::Level_1(array<string,4> &arr,string &q,char &ans){
        unordered_map<int,string>mp;
        array<int,4> mappedkeys;
        CreatechoicessetLevel1(mp);
        mappingkeys(mp,mappedkeys);
        array2arrayofchoices(mappedkeys,arr);
        ans=randomint(4);//randomizing answer
        q=mp[mappedkeys[ans]]+" =";//string for answer
        ans++;
        prepareAns(ans);
    }
    void multiplication::Level_2(array<string,4> &arr,string &q,char &ans){
        unordered_map<int,string>mp;
        array<int,4> mappedkeys;
        CreatechoicessetLevel2(mp);
        mappingkeys(mp,mappedkeys);
        array2arrayofchoices(mappedkeys,arr);
        ans=randomint(4);//randomizing answer
        q=mp[mappedkeys[ans]];//string for answer
        ans++;
        prepareAns(ans);
    }
    void multiplication::Level_3(array<string,4> &arr,string &q,char &ans){
        unordered_map <int,string> mp;//map for holding choices
        Createchoicesmap(mp);//creating choices
        map2arrayofstrings(mp,arr);//creating string of choices
        array<int,4> mappedkeys;//array for mapping keys
        mappingkeys(mp,mappedkeys);//mapping keys
        ans=randomint(4);//randomizing answer
        q=int2string(mappedkeys[ans]);//string for answer
        ans++;//prepare answer for comparing by +1 on it
        prepareAns(ans);
    }
    void multiplication::Level_4(array<string,4> &arr,string &q,char &ans){
        unordered_map <int,string> mp;
        Createchoicesmap(mp);//creating answers
        array<int,4> mappedkeys;
        mappingkeys(mp,mappedkeys);//mappingkeys answers
        map2arrayofstrings(mp,arr);//creating string of choices
        int operation=randomint(2);//random between Smallest and Greatest
        if (operation){//geting answer using distance between pointers
            ans=max_element(mappedkeys.begin(),mappedkeys.end())-mappedkeys.begin()+1;
            q="Greatest?";
        }else{
            ans=min_element(mappedkeys.begin(),mappedkeys.end())-mappedkeys.begin()+1;
            q="Smallest?";
        }
        prepareAns(ans);
    }
    void multiplication::Level_5(array<string,4> &arr,string &q,char &ans){
        unordered_map <int,string> mp;
        Createchoicesmap(mp);//creating answers
        array<int,4> mappedkeys;
        mappingkeys(mp,mappedkeys);//mappingkeys answers
        map2arrayofstrings(mp,arr);
        int rad,num1;
        do{//creating question
            ans=randomint(4);
            rad=randomint(7,1);
            num1=mappedkeys[ans]/rad;
            q=int2string(num1)+" x "+int2string(rad);
        }while(mappedkeys[ans]%rad!=0);//return above in case of dublication
        ans++;
        prepareAns(ans);
    }
    void multiplication::Level_6(array<string,4> &arr,string &q,char &ans){
        unordered_map<int,string>mp;
        array<int,4> mappedkeys;
        Createchoicesset(mp);
        mappingkeys(mp,mappedkeys);
        map2arrayofstrings(mp,arr);
        ans=randomint(4);
        q=int2string(mappedkeys[ans])+" =";
        ans++;
        prepareAns(ans);
    }

