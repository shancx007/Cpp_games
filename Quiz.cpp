#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
using namespace std;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> rnd(0,9):
string q1="Which country is known as the 'Land of the Rising Sun'?";
string q2="What is the hardest natural substance on Earth?";
string q3="In which year did the Titanic sink on its maiden voyage from Southampton?";
string q4="Who wrote the famous play Romeo and Juliet?";
string q5="What is the largest organ in the human body?";
string q6="Which artist painted the Mona Lisa?";
string q7="What is the chemical symbol for the element Gold?";
string q8="Which planet in our solar system is known as the 'Red Planet'?";
string q9="Which legendary British rock band was fronted by Freddie Mercury?";
string q0="What do you call a polygon with eight sides?";
unordered_map<string,string> quations;
quations[q1]="Japan";