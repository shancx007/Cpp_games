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
vector <string> layout(16,"[ ]");
void setup(vector<string> temp){
    cout<<temp[0]<<"\t"<<temp[1]<<"\t"<<temp[2]<<"\t"<<temp[3]<<endl;
    cout<<temp[4]<<"\t"<<temp[5]<<"\t"<<temp[6]<<"\t"<<temp[7]<<endl;
    cout<<temp[8]<<"\t"<<temp[9]<<"\t"<<temp[10]<<"\t"<<temp[11]<<endl;
    cout<<temp[12]<<"\t"<<temp[13]<<"\t"<<temp[14]<<"\t"<<temp[15]<<endl;
    cout<<endl;
}
//uniform_int_distribution<int> rnd(0,51);
int main(){
for (string s : shapes){
    for(string v : values){
        cards.push_back( v + " of " + s);
        
    }
}
    shuffle(cards.begin(),cards.end(),gen);
    vector <string> board;
    for(int i = 0; i <= 7;i++){
        board.push_back(cards[i]);
        board.push_back(cards[i]);


    }
    shuffle(board.begin(),board.end(),gen);
   
    int c1,c2;
    
    int flip =0;

    while (true){
        setup(layout);
        cout<<"Enter the First choice : "<<endl;
        cin>>c1;
        c1= c1-1;
        if(layout[c1]=="[ ]"){
            layout[c1] = board[c1];
            setup(layout);
        }
        else{
            cout<<"Enter the right Input, It's already taken"<<endl;
            continue;
        }
        cout<<"Enter the Second choice : "<<endl;
        cin>>c2;
        c2 = c2-1;
        if(c1==c2){
            cout<<"NIce Try Bud"<<endl;
            continue;
        }
        if(layout[c2]=="[ ]"){
            layout[c2] = board[c2];
            setup(layout);
        }
        else{
            cout<<"Enter the right Input, It's already taken"<<endl;
            
            continue;
        }
        if(board[c1]==board[c2]){
            layout[c1]=board[c1];
            layout[c2]=board[c2];
            flip++;
            setup(layout);
        }else{
            layout[c1]="[ ]";
            layout[c2]="[ ]";
           
        }
        if (flip ==8){
            cout<<"You Win !!!"<<endl;
            setup(layout);
            break;
        } 


    }

}