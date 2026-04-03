#include <iostream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
unordered_map<int,char> x_o;

void board(){
        cout << x_o[1]<<"|"<<x_o[2]<<"|"<<x_o[3] << endl;
        cout << x_o[4]<<"|"<<x_o[5]<<"|"<<x_o[6] << endl;
        cout << x_o[7]<<"|"<<x_o[8]<<"|"<<x_o[9] << endl;

            }


bool insert(int where, char what){
        if (x_o[where] == ' '){
            x_o[where] = what;
            return true;
        }
        else{
            cout<<"The place already Taken by a player"<<endl;
            return false;
        }
     
    } 

void winning(){
    char winner;

    if (x_o[1]==x_o[2] && x_o[2]==x_o[3] && x_o[1]!= ' '){
        winner = x_o[1];
        cout<<"Game Over "<<winner<<" wins"<<endl;
        exit(0);
    }
    else if(x_o[4] == x_o[5] && x_o[5] == x_o[6]&& x_o[4]!= ' '){

        winner =x_o[4];
        cout<<"Game Over " <<winner<<" wins"<<endl;
        exit(0);

    }
    else if(x_o[7] == x_o[8] && x_o[8] == x_o[9]&& x_o[7] != ' '){
        winner =x_o[7];
        cout<<"Game Over "<<winner<<" wins"<<endl;
        exit(0); 
    }
    else if(x_o[1]==x_o[5] && x_o[5] == x_o[9] && x_o[1] != ' '){
        winner =x_o[1];
        cout<<"Game Over "<<winner<<" wins"<<endl;
        exit(0);
    }
    else if(x_o[3] == x_o[5] && x_o[5] == x_o[7] && x_o[3] != ' '){
        winner =x_o[3];
        cout<<"Game Over "<<winner<<" wins"<<endl;
        exit(0);
    }
    else if(x_o[1] == x_o[4] && x_o[4] == x_o[7] && x_o[1]!= ' '){
        winner =x_o[1];
        cout<<"Game Over "<<winner<<" wins"<<endl;
        exit(0);
    }
    else if(x_o[2] == x_o[5] && x_o[5] == x_o[8] && x_o[2]!= ' '){
        winner =x_o[2];
        cout<<"Game Over "<<winner<<" wins"<< endl;
        exit(0);
    }
    else if(x_o[3] == x_o[6] && x_o[6] == x_o[9]&& x_o[3]!= ' '){
        winner =x_o[3];
        cout<<"Game Over "<<winner<<" wins"<<endl;
        exit(0);
    }
   
}



     

    
int main(){
    for(int i = 1;i<=9;i++){
        x_o[i]=' ';
    }
    int val;
    int turn =1;
    char var;
    int player_count = 0;
    int computer_count = 0;
    int player_input[]={};
    int computer_input[]={};
    while(true){
        
        board();
        cout<<"Enter the Place Value : "<<endl;
        cin>>val;
        for(int player_count; player_count < 5; player_count++ ){
            player_input[player_count]=val;
        } 
        
        
        cout<< "The Number of turns is : "<<turn<<endl;
        
        if(turn%2 == 0){
            var = 'O';
         }
        else{
            var = 'X';
            
         }
       

        if(!insert(val,var)){
            continue;
        }
        winning();
        if (turn == 9){
            board();
            cout<<"It's a Draw"<<endl;
            exit(0);
        }

        turn++;
        
        }
    }

    