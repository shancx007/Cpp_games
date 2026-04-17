#include <raylib.h>

Color mygreen = {30, 160, 120, 255};
int X_cord = 300;
int Y_cord = 300;
int main()


{
    InitWindow(600, 600, "Balls");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(mygreen);
      
        DrawCircle(X_cord,Y_cord,10,WHITE);
        if(IsKeyDown(KEY_RIGHT)) X_cord += 3;
        if(IsKeyDown(KEY_LEFT))  X_cord -= 3;
        if(IsKeyDown(KEY_UP)) Y_cord -= 3;
        if(IsKeyDown(KEY_DOWN)) Y_cord += 3;
        EndDrawing();
    }
    CloseWindow();

}