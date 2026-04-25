#include <raylib.h>
int cellsize = 20;
int cellcount = 30;
class Head{
    public:
    int x=15;
    int y=15;
    void Draw(){
        DrawRectangle(x*cellsize,y*cellsize,cellsize,cellsize,BLACK);
}
    void Direction(){
        
    }
};

int main(){
    InitWindow(cellcount*cellsize,cellcount*cellsize,"snake");
    SetTargetFPS(60);
    Head head;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GREEN);
        DrawLine(2*cellsize,2*cellsize,28*cellsize,2*cellsize,BLACK);
        DrawLine(28*cellsize,2*cellsize,28*cellsize,28*cellsize,BLACK);
        DrawLine(28*cellsize,28*cellsize,2*cellsize,28*cellsize,BLACK);
        DrawLine(2*cellsize,28*cellsize,2*cellsize,2*cellsize,BLACK);
        head.Draw();
        EndDrawing();
    }
    CloseWindow();
    
}