#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;
random_device rd;
mt19937 gen(rd());
string shapes[4]= {"hearts","spade","diamond","leaf"};
string values[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
vector <string> cards;
int main(){
for (string s : shapes){
    for(string v : values){
        cards.push_back( v + "of" + s);
        
    }
}
    shuffle(cards,cards+52,gen);
}