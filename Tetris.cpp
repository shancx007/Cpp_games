#include <raylib.h>
#include <deque>
using namespace std;
float cellsize = 30;
float cellcount = 20;
Color violet = {5,155,200,255};
  deque<Vector2> blocks;
class Moids{
    float x = 5;
    float y = 5;
    public:
  
    blocks = {
        deque<Vector2> Long={Vector2{x,y},Vector2{x,y},Vector2{x,y},Vector2{x,y}};
        deque<Vector2> Z_1 = {Vector2{x,y},Vector2{x+1,y},Vector2{x+1,y-1},Vector2{x+1,y-2}},
        deque<Vector2> Z_2 = {Vector2{x,y},Vector2{x,y+1},Vector2{x+1,y+1},Vector2{x+1,y+2}},
        deque<Vector2> B_l={Vector2{x,y},Vector2{x+1,y},Vector2{x+1,y+1},Vector2{x+1,y+2}},
        deque<Vector2> B_r={Vector2{x,y},Vector2{x,y+1},Vector2{x,y+2},Vector2{x+1,y}},
        deque<Vector2> Iso={Vector2{x,y},Vector2{x,y+1},Vector2{x+1,y},Vector2{x+1,y+1}},
        deque<Vector2> Square={Vector2{x,y},Vector2{x+1,y},Vector2{x+1,y+1},Vector2{x,y+1}},};
        void Draw(){
            DrawRectangle(x*cellsize,y*cellsize,cellsize,cellsize,BLACK);
        }
};

int main(){
    InitWindow(cellsize*cellcount,cellsize*cellcount,"TETRIS");
    Moids moid;
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(violet);
        moid.Draw();

        EndDrawing();
    }
    
    
    CloseWindow();
}