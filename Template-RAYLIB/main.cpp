#include <raylib.h>


int width;
int height;


int main(void){
    // srand(time(nullptr));

    width = 1080;
    height = 720;

    InitWindow(width, height, "INSERT_NAME_HERE");
    SetTargetFPS(60);


    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground({37,37,37});

        EndDrawing();
    }
    
    CloseWindow();
}
