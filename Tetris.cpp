#include <raylib.h>
float cellsize = 30;
float cellcount = 25;
Color violet = {5,155,200,255};
class Square{
    void shape(){
        Vector2 Long{{x,y},{x,y},{x,y},{x,y}};
        vector2 Z_1 = {{x,y},{x+1,y},{x+1,y-1},{x+1,y-2}};
        Vector2 Z_2 = {{x,y},{x,y+1},{x+1,y+1},{x+1,y+2}};
        Vector2 B_l{{x,y},{x+1,y},{x+1,y+1},{x+1,y+2}};
    }
};

int main(){
    InitWindow(cellsize*cellcount,cellsize*cellcount,"TETRIS");
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(violet);
        

        EndDrawing();
    }
    
    
    CloseWindow();
}