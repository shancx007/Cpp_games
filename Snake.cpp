#include <raylib.h>
#include <deque>
#include <raymath.h>
using namespace std;


int cellsize = 20;
int cellcount = 30;

class Head{
    public:
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
         body.pop_back();
         body.push_front(Vector2Add(body[0],way));  
         if (body[0].y>27)body[0].y=2; 
         if (body[0].y<2)body[0].y=27; 
         if (body[0].x>27)body[0].x=2; 
         if (body[0].x<2)body[0].x=27; 
            
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
       float x = GetRandomValue(2,cellcount-2);
        float y = GetRandomValue(2,cellcount-2);
        return Vector2{x,y};
    }
};

int main(){
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
        head.Draw();
        
        if(willdo(0.3)){
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
        EndDrawing();
    }
        
    
    CloseWindow();
    
}