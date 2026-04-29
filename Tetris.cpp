#include <raylib.h>
float cellsize = 30;
float cellcount = 25;
Color violet = {5,155,200,255};
class Square{
    void place(){
        
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