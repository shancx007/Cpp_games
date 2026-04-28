#include <raylib.h>
float cellsize = 30;
float cellcount = 25;
Color violet = {5,155,20,255};
int main(){
    InitWindow(cellsize*cellcount,cellsize*cellcount,"TETRIS");
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(violet);
        EndDrawing();
    }
    
    
    CloseWindow();
}