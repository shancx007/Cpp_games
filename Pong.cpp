#include <raylib.h>
Color green ={30 , 160 , 120, 255};

float Zx_cords = 30;
float Zy_cords = 670;
float Z_radius = 20;
class Ball{
    public: 
        float Y_cord = GetScreenHeight()/2;
        float X_cord = GetScreenWidth()/2;
        float radius = 10;
        float x_speed = 6;
        float y_speed = 6;
        int player1 , player2;
      
    void Draw(){
         DrawCircle(X_cord,Y_cord, radius, WHITE);
    }
    void Direction(){

        X_cord += x_speed;
        Y_cord += y_speed;
        //if(X_cord + radius >= GetScreenWidth() || X_cord - radius <= 0) x_speed *=-1;
        if(Y_cord + radius >= GetScreenHeight() || Y_cord - radius <= 0) y_speed *=-1;
       

        }
    int Score(){
        if (X_cord<=GetScreenWeight())
    }
    
    
};
class Paddle{
    public:
        float x1 = 10;
        float y1 = GetScreenHeight()/2-60;
        float x2 = GetScreenWidth()-30;
        float y2 = GetScreenHeight()/2-60;
        float H = 120;
        float W = 20;
    void Draw(){
       DrawRectangle(x1,y1,W,H,WHITE);
       DrawRectangle(x2,y2,W,H,WHITE);
    }
     void Direction(){
        if(IsKeyDown(KEY_UP)) y2 -= 7;
        if(IsKeyDown(KEY_DOWN)) y2 += 7;
        if(y2<=5)y2=5;
        if(y2>= GetScreenHeight()-130)y2= GetScreenHeight()-130;
        if(IsKeyDown(KEY_W)) y1 -= 7;
        if(IsKeyDown(KEY_S)) y1 += 7;
        if(y1<=5)y1=5;
        if(y1 >= GetScreenHeight()-130)y1= GetScreenHeight()-130;
     }
};


int main(){
   
    InitWindow(1200,680, "Balls");

    SetTargetFPS(60);
    Paddle pad;
    Ball ball;
  
    while (!WindowShouldClose())
    
    {
        BeginDrawing();
        ClearBackground(green);
        ball.Draw();
        pad.Draw();

        //DrawRectangle(10,GetScreenHeight()/2-60,30,120,WHITE);
        //DrawRectangle(GetScreenWidth()-40,GetScreenHeight()/2-60,30,120,WHITE);
        DrawLine(GetScreenWidth()/2,GetScreenHeight(), GetScreenWidth()/2,0 , WHITE);
        DrawCircleLines(GetScreenWidth()/2,GetScreenHeight()/2,150,WHITE);

        ball.Direction();
        pad.Direction();
        if(CheckCollisionCircleRec({ball.X_cord,ball.Y_cord},ball.radius,{pad.x1,pad.y1,pad.W,pad.H})) ball.x_speed *=-1;
        if(CheckCollisionCircleRec({ball.X_cord,ball.Y_cord},ball.radius,{pad.x2,pad.y2,pad.W,pad.H})) ball.x_speed *=-1;
        
       


        EndDrawing();
    }
    CloseWindow();
}