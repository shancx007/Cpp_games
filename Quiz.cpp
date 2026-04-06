#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
using namespace std;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> rnd(0,9);
struct quiz{
   string q;
   string ans;
    };
quiz q1
q1.q ={
    {"Which country is known as the 'Land of the Rising Sun'?","Japan"}
    {"What is the hardest natural substance on Earth?","Diamond"}
    };


unordered_map<string,string> arrang;
arrang[quiz.q[]]="Japan";
