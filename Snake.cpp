#include <raylib.h>
#include <deque>
#include <raymath.h>
using namespace std;


int cellsize = 20;
int cellcount = 30;
Vector2 right{1,0};
class Head{
    public:
    deque<Vector2> body={Vector2{6,9},Vector2{5,9},Vector2{4,9}};
    void Draw(){
        for(int i; i < body.size();i++){
            float x = body[i].x;
            float y = body[i].y;
        Rectangle rec = {x*cellsize,y*cellsize,cellsize,cellsize};
        DrawRectangleRounded(rec,0.4,6,BLACK);
        }
    }
    void Direction(){
         body.pop_back();
         body.push_front(Vector2Add(body[0],right));   
            
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
       float x = GetRandomValue(0,cellcount-1);
        float y = GetRandomValue(0,cellcount-1);
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
            head.Direction();
        }
        food.Draw();
        EndDrawing();
    }
        
    
    CloseWindow();
    
}