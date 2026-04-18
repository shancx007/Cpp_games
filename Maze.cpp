#include <raylib.h>
Color green ={30 , 160 , 120, 255};
float Y_cord = 350;
float X_cord = 500;
float Zx_cords = 30;
float Zy_cords = 670;
float Z_radius = 20;
int main(){
    InitWindow(1000,700, "Balls");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    
    {
        BeginDrawing();
        ClearBackground(green);
        DrawCircle(X_cord,Y_cord, 10, WHITE);
        DrawCircle(Zx_cords,Zy_cords,Z_radius,RED);
        if(IsKeyDown(KEY_RIGHT)) X_cord += 3;
        if(IsKeyDown(KEY_LEFT))  X_cord -= 3;
        if(IsKeyDown(KEY_UP)) Y_cord -= 3;
        if(IsKeyDown(KEY_DOWN)) Y_cord += 3;
        
        if (X_cord < 0)   X_cord = 0;
        if (X_cord > 990) X_cord = 990;
        if (Y_cord < 0)   Y_cord = 0;
        if (Y_cord > 690) Y_cord = 690;
        if(CheckCollisionCircles({X_cord,Y_cord},10,{Zx_cords,Zy_cords},Z_radius )) DrawText("You Won!!!", 300, 250, 100, ORANGE);
        


        EndDrawing();
    }
    CloseWindow();
}