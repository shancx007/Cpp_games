#include <iostream>
#include <algorithm>
#include <random>
#include <unordered_map>
using namespace std;
random_device rd;
mt19937 gen(rd());
string shapes[4]= {"hearts","spade","diamond","leaf"};
string values[13]={"A","2","3","4","5","6",7","8","9","10","J","Q","K"};
unordered_map <string,string> cards;
