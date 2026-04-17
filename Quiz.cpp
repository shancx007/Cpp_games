#include <iostream>
#include <algorithm>
#include <string>
#include <random>
using namespace std;
random_device rd;
mt19937 gen(rd());



struct quiz{
   string q;
   string ans;
    };
quiz ql[10]{
    {"Which country is known as the 'Land of the Rising Sun'?","Japan"},
    {"What is the hardest natural substance on Earth?","Diamond"},
    {"In which year did the Titanic sink on its maiden voyage from Southampton?","1912"},
    {"Who wrote the famous play Romeo and Juliet?","shakespeare"},
    {"What is the largest organ in the human body?","skin"},
    {"Which artist painted the Mona Lisa?","Leanardo da vinci"},
    {"What is the chemical symbol for the element Gold?","Au"},
    {"Which planet in our solar system is known as the 'Red Planet'","Mars"},
    {"Which legendary British rock band was fronted by Freddie Mercury?","Queen"},
    {"What do you call a polygon with eight sides?","Octagon"}
    };
int main(){
    string Ans;
    int score =0;

    shuffle(ql,ql+10,gen);
    for(int i=0; i<=4; i++){
        cout << ql[i].q << endl;
        getline(cin ,Ans);
        for(char& ch : Ans) ch = tolower(ch);
        for(char& ch : ql[i].ans) ch = tolower(ch);
        if(Ans ==ql[i].ans){
            cout<<"Your answer is right"<<endl;
            score++;

        }
        else{
            cout<<"Your Answer is wrong"<<endl;
            
        }

    }
    cout<<"Your Score is : "<<score<<endl;
}