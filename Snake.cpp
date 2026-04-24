#include <raylib.h>
Color mygreen = {30, 160, 120, 255};


class Head{
    public:
    int x = 600;
    int y = 350;
    void Draw(){
        DrawRectangle(x,y,20,20,WHITE);
    }
   
        
        

};

int main(){
    Head head;
    InitWindow(1200,700,"Snakes");
   
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        ClearBackground(mygreen);
        BeginDrawing();
        head.Draw();
        if(IsKeyPressed(KEY_UP)){
            while(true){
                head.x+=3;
            }
        }
        
        
        EndDrawing();
    }
    CloseWindow();
}