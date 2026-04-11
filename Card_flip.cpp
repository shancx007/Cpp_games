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
vector <string> layout;
void setup(vector <string> temp){
    cout<<temp[0]<<temp[1]<<temp[2]<<temp[3]<<endl;
    cout<<temp[4]<<temp[5]<<temp[6]<<temp[7]<<endl;
    cout<<temp[8]<<temp[9]<<temp[10]<<temp[11]<<endl;
    cout<<temp[12]<<temp[13]<<temp[14]<<temp[15]<<endl;

}
//uniform_int_distribution<int> rnd(0,51);
int main(){
for (string s : shapes){
    for(string v : values){
        cards.push_back( v + "of" + s);
        
    }
}
    shuffle(cards.begin(),cards.end(),gen);
    vector <string> board;
    for(int i; i <= 7;i++){
        board.push_back(cards[i]);
        board.push_back(cards[i]);
        layout.push_back("[ ]");

    }
    shuffle(board.begin(),board.end(),gen);
   setup(layout);

}