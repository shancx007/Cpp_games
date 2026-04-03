#include<iostream>
#include<random>
#include <string>
using namespace std;
string choice[3] ={"ROCK","PAPER","SCISSORS"};
random_device  rd;
mt19937 gen(rd());
int c_count = 0,p_count = 0;
uniform_int_distribution<> rnd(0,2);

void winner(string p ,string c) {
    if (p == c)
    {
        cout<<"The Computer Chose : "<<c<<endl<<"It's a Draw, play again"<<endl;
    }
    else if(p == "ROCK")
    {
        if(c == "PAPER")
        {
            cout<<"The Computer Chose : "<<c<<endl<<"YOU LOSE!!!"<<endl;
            c_count++;
        }
        else if(c == "SCISSORS")
        {
            cout<<"The Computer Chose : "<<c<<endl<<"Well Good game Mate."<<endl;
            p_count++;
        }

    }
    else if(p == "SCISSORS")
    {
        if(c == "ROCK")
        {
            cout<<"The Computer Chose : "<<c<<endl<<"YOU LOSE!!!"<<endl;
            c_count++;
        }
        else if(c == "PAPER")
        {
            cout<<"The Computer Chose : "<<c<<endl<<"Well Good game Mate."<<endl;
            p_count++;
        }

    }
    else if(p == "PAPER")
    {
        if(c == "SCISSORS")
        {
            cout<<"The Computer Chose : "<<c<<endl<<"YOU LOSE!!!"<<endl;
            c_count++;
        }
        else if(c == "ROCK")
        {
            cout<<"The Computer Chose : "<<c<<endl<<"Well Good game Mate."<<endl;
            p_count++;
        }

    }
}


int best_of = 0;
int main(){
    cout<<"Enter the Best Of you want : "<<endl;
    cin>>best_of;
    if (best_of<=0){
        cout<<"Enter the right Games Pal";
    }
    else{
        for(int i = 1;i<=best_of;i++){
            string com_choice = choice[rnd(gen)];

            string player_choice ="";
            cout<<"Enter Your Choice : "<<endl;
            cin>>player_choice;
            for (char& ch:player_choice)ch = toupper(ch);
            winner(player_choice,com_choice);

    }
    if(c_count>p_count){
        cout<<"The Computer Wins, Geez Dumb Luck, Ey??"<<endl;
     
    }
    else if(c_count<p_count){
        cout<<"CONGRATES....!!!, You Win, Tuff Luck ,Ey??"<<endl;
     
    }
    else{
        cout<<"It's a Draw..., Let's Play Again,"<<endl;
     
    }
}
}



