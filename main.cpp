#include <raylib.h>

int main(){
    InitWindow(800, 600, "My First Window");
    
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hello Raylib!", 300, 280, 30, WHITE);
        EndDrawing();
    }
    CloseWindow();
}