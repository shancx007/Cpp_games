#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

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
    shuffle(ql,ql+10,gen);
    for(int i=0i<=9;i++){
        cout << ql[i].q << endl;
        cin >>Ans;

    }
}