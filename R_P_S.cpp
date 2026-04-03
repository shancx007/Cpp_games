#include<iostream>
#include<random>
#include <string>
using namespace std;
string choice ={"ROCK","PAPER","SCISSORS"};
random_device  rd;
mt19937 gen(rd()); 
uniform_int_distribution<> rand(0,2);


