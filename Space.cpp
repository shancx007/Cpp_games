#include<iostream>
#include<raylib.h>
using namespace std;
float cellsize = 10;
float cellcount = 30;
Color mint = {126,240,193,255};


class Ship{
    public:
    float x = 13;
    float y = 27;

    void Draw(){
        DrawRectangle(x*cellsize,y*cellsize,3*cellsize,2*cellsize,BLACK);
    }
    void Move(){
        if(IsKeyDown(KEY_LEFT))x+=-0.5;
        if(IsKeyDown(KEY_RIGHT))x+=0.5;
        if(x>=26)x=26;
        if(x<=1)x=1;
    }
    double last = 0;
    float up = (27*cellsize)-cellsize;
    void bullets(){
        
        double curr = GetTime();
        if (curr - last >= 0.5){
            DrawRectangle((x*cellsize)+13,(up),4,cellsize,BLACK);
            up-=10;
            last = curr;
    }
}
    
};

int main(){
    Ship ship;
    InitWindow(cellsize*cellcount,cellcount*cellsize,"Space_Game");
    SetTargetFPS(60);
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(mint);
        ship.Draw();
        ship.Move();
        ship.bullets();
        EndDrawing();
    }
   CloseWindow();
}