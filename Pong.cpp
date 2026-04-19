#include <raylib.h>
Color green ={30 , 160 , 120, 255};


class Ball{
    public: 
        float Y_cord = GetScreenHeight()/2;
        float X_cord = GetScreenWidth()/2;
        float radius = 10;
        float x_speed = 6;
        float y_speed = 6;
        int player1 =0, player2 = 0;
      
      
    void Draw(){
         DrawCircle(X_cord,Y_cord, radius, WHITE);
    }
    void Direction(){

        X_cord += x_speed;
        Y_cord += y_speed;
        //if(X_cord + radius >= GetScreenWidth() || X_cord - radius <= 0) x_speed *=-1;
        if(Y_cord + radius >= GetScreenHeight() || Y_cord - radius <= 0) y_speed *=-1;
       

        }
 
    
    
};
class Paddle{
    public:
        float x1 = 10;
        float y1 = GetScreenHeight()/2-70;
        float x2 = GetScreenWidth()-30;
        float y2 = GetScreenHeight()/2-70;
        float H = 140;
        float W = 20;
    void Draw(){
       DrawRectangle(x1,y1,W,H,WHITE);
       DrawRectangle(x2,y2,W,H,WHITE);
    }
     void Direction(){
        if(IsKeyDown(KEY_UP)) y2 -= 8;
        if(IsKeyDown(KEY_DOWN)) y2 += 8;
        if(y2<=5)y2=5;
        if(y2>= GetScreenHeight()-130)y2= GetScreenHeight()-130;
        if(IsKeyDown(KEY_W)) y1 -= 8;
        if(IsKeyDown(KEY_S)) y1 += 8;
        if(y1<=5)y1=5;
        if(y1 >= GetScreenHeight()-130)y1= GetScreenHeight()-130;
     }
};


int main(){
   
    InitWindow(1200,680, "Balls");
   
    SetTargetFPS(60);
    Paddle pad;
    Ball ball;
    
    bool isGameOver = false;
    while (!WindowShouldClose())
    
    
    {
        BeginDrawing();
        ClearBackground(green);
        if(isGameOver == false){
       
        ball.Direction();
        pad.Direction();
        ball.Draw();
        pad.Draw();
       
        
        if (ball.X_cord - ball.radius >= GetScreenWidth()){
            ball.player1+=1;
            ball.Y_cord = GetScreenHeight()/2;
            ball.X_cord = GetScreenWidth()/2;
        }
        if (ball.X_cord + ball.radius <= 0){
            ball.player2+=1;
            ball.Y_cord = GetScreenHeight()/2;
            ball.X_cord = GetScreenWidth()/2;
        }
        if(CheckCollisionCircleRec({ball.X_cord,ball.Y_cord},ball.radius,{pad.x1,pad.y1,pad.W,pad.H})) ball.x_speed *=-1;
        if(CheckCollisionCircleRec({ball.X_cord,ball.Y_cord},ball.radius,{pad.x2,pad.y2,pad.W,pad.H})) ball.x_speed *=-1;
       
    }

        if(ball.player1== 10){ 
            DrawText("PLAYER 1 WINS!!!",300,300,75,RED);
            isGameOver = true;
        }
        if(ball.player2== 10) {
            
            DrawText("PLAYER 2 WINS!!!",300,300,75,RED);
            isGameOver = true;

        }
    
        DrawLine(GetScreenWidth()/2,GetScreenHeight(), GetScreenWidth()/2,0 , WHITE);
        DrawCircleLines(GetScreenWidth()/2,GetScreenHeight()/2,150,WHITE);


        DrawText(TextFormat("Score : %d",ball.player1),150,30,75,WHITE);
        DrawText(TextFormat("Score : %d",ball.player2),750,30,75,BLUE);
      
       
       
    

        EndDrawing();
    }
    CloseWindow();
}