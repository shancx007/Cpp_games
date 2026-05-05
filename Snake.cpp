#include <raylib.h>
#include <deque>
#include <raymath.h>
using namespace std;


float cellsize = 20.0;
float cellcount = 30.0;

class Head{
    public:
    bool addtail = false;
   
    
    deque<Vector2> body={Vector2{6,9},Vector2{5,9},Vector2{4,9}};
    Vector2 way{1,0};
    void Draw(){
        for(int i=0; i < body.size();i++){
            float x = body[i].x;
            float y = body[i].y;
        Rectangle rec = {x*cellsize,y*cellsize,cellsize,cellsize};
        DrawRectangleRounded(rec,0.4,6,BLACK);
        }
    }
    void DirectionR(){
        
        if(!addtail){
         body.pop_back();
        }
        addtail = false;
         body.push_front(Vector2Add(body[0],way));  
         if (body[0].y>27)body[0].y=2; 
         if (body[0].y<2)body[0].y=27; 
         if (body[0].x>27)body[0].x=2; 
         if (body[0].x<2)body[0].x=27; 
            
    }
    void reset(int &val){
        body={Vector2{6,9},Vector2{5,9},Vector2{4,9}};
        way={1,0};
        val =0;
    }
    

};
double perv_time = 0;

bool willdo(double interval){
    double curr_time = GetTime();
    if(curr_time - perv_time > interval){
        perv_time = curr_time;
        return true;
    }
    else{
        return false;
        }
    
}
class Food{
    public:
    Vector2 pos = GenerateRandomPos();
    void Draw(){
        DrawRectangle(pos.x*cellsize,pos.y*cellsize,cellsize,cellsize,BLACK);
    }
    Vector2 GenerateRandomPos(){
       float x = GetRandomValue(2,cellcount-3);
        float y = GetRandomValue(2,cellcount-3);
        return Vector2{x,y};
    }
};

int main(){
    int score=0;
    bool gameOver = false;
    InitWindow(cellcount*cellsize,cellcount*cellsize,"snake");
    SetTargetFPS(60);
    Head head;
    Food food;
     
    double prv = GetTime();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GREEN);
        double cur = GetTime();
        
        DrawLine(2*cellsize,2*cellsize,28*cellsize,2*cellsize,BLACK);
        DrawLine(28*cellsize,2*cellsize,28*cellsize,28*cellsize,BLACK);
        DrawLine(28*cellsize,28*cellsize,2*cellsize,28*cellsize,BLACK);
        DrawLine(2*cellsize,28*cellsize,2*cellsize,2*cellsize,BLACK);
       if(!gameOver){ 
        head.Draw();
        
        if(willdo(0.1)){
            head.DirectionR();
        }
        if(IsKeyPressed(KEY_UP)){
            if(head.way.y == 1){
            head.way={0,1};
            }
            else{
        head.way={0,-1};
            }
        }
        if(IsKeyPressed(KEY_RIGHT)){
            if(head.way.x==- 1){
               head.way={-1,0}; 
            }
            else{
        head.way={1,0};
            }
        }
        if(IsKeyPressed(KEY_LEFT)){
            if(head.way.x== 1){
                head.way={1,0};
            }
            else{
            head.way={-1,0};
            }
        }
        if(IsKeyPressed(KEY_DOWN)){
            if(  head.way.y==-1){
                head.way={0,-1};
            }
            else{
            head.way={0,1};
            }
        }
       
        food.Draw();
        if(CheckCollisionRecs({food.pos.x*cellsize,food.pos.y*cellsize,cellsize,cellsize},{head.body[0].x*cellsize,head.body[0].y*cellsize,cellsize,cellsize})){
            food.pos = food.GenerateRandomPos();
            head.addtail = true;
            score++;
        }
         DrawText(TextFormat("Score : %d",score),25*cellsize,1*cellsize,1*cellsize,WHITE);
    
        for(int i = 2; i<head.body.size();i++){
if(CheckCollisionRecs({head.body[0].x*cellsize,head.body[0].y*cellsize,cellsize,cellsize},{head.body[i].x*cellsize,head.body[i].y*cellsize,cellsize,cellsize})){
   
    gameOver = true;
}
        }

        }
        if(gameOver){
            DrawText("Game Over!!!",6*cellsize,10*cellsize,70,BLACK);
        }
        if(IsKeyPressed(KEY_SPACE)){
            gameOver=false;
            head.reset(score);

        }
    

        EndDrawing();
    }
        
    
    CloseWindow();
    
}