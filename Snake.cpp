#include <raylib.h>
int cellsize = 20;
int cellcount = 30;
class Head{
    public:
    int x=15;
    int y=15;
    int speed = 1;
    void Draw(){
        DrawRectangle(x*cellsize,y*cellsize,cellsize,cellsize,BLACK);
}
    

    void Direction(double cur,double &prv){
        
        if(IsKeyPressed(KEY_UP)){
            
            
            if(cur - prv > 1.0){
            y--;
            Draw();
            prv = cur;
            cur = GetTime();
            
                }
            
            }
        
        
        
    }
};

int main(){
    InitWindow(cellcount*cellsize,cellcount*cellsize,"snake");
    SetTargetFPS(60);
    Head head;
    
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
        
        head.Direction(cur,prv);
        EndDrawing();
    }
        
    
    CloseWindow();
    
}