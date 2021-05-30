
#include <raylib.h>
#include <math.h>

// float ForkAngle = PI / 32;
int RecDepth = 10;

int width;
int height;

float Remap(float I, float IA, float IB, float OA, float OB){
    return (I - IA) / (IB - IA) * (OB - OA) + OA;
}

void DrawTree(Vector2 StartPos, float Angle, int Depth, float ForkAngle){
    if (Depth > 0){
        float Length = Remap(Depth, 0, RecDepth, 20, 50);

        Vector2 EndPos = {
            StartPos.x + cosf(Angle) * Length,
            StartPos.y + sinf(Angle) * Length
        };

        DrawLineEx(StartPos, EndPos, 1, WHITE);
        DrawTree(EndPos, Angle - ForkAngle, Depth - 1, ForkAngle);
        DrawTree(EndPos, Angle + ForkAngle, Depth - 1, ForkAngle);
    }
}


int main(void){
    // srand(time(nullptr));

    width = 1080;
    height = 800;

    InitWindow(width, height, "Fractals to learn");
    SetTargetFPS(60);

    int ForkingAngleMouse = 1.0f;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground({37,37,37});

        ForkingAngleMouse += ((int)GetMouseWheelMove()*1.0f);

        if (ForkingAngleMouse > 100.0f) ForkingAngleMouse = 100.0f;
        else if (ForkingAngleMouse < 1.0f) ForkingAngleMouse = 1.0f;
        // DrawTree((Vector2) {width / 2, height - 250 }, -PI / 2, RecDepth, PI/ForkingAngleMouse);

        DrawTree((Vector2) {width / 2, height/2}, 0, RecDepth, PI/ForkingAngleMouse);
        DrawTree((Vector2) {width / 2, height/2}, PI, RecDepth, PI/ForkingAngleMouse);
        DrawTree((Vector2) {width / 2, height/2}, PI/2, RecDepth, PI/ForkingAngleMouse);
        DrawTree((Vector2) {width / 2, height/2}, -PI/2, RecDepth, PI/ForkingAngleMouse);

        DrawTree((Vector2) {width / 2, height/2}, PI/4, RecDepth, PI/ForkingAngleMouse);
        DrawTree((Vector2) {width / 2, height/2}, -PI/4, RecDepth, PI/ForkingAngleMouse);
        DrawTree((Vector2) {width / 2, height/2}, 5*(PI)/4, RecDepth, PI/ForkingAngleMouse);
        DrawTree((Vector2) {width / 2, height/2}, -5*(PI)/4, RecDepth, PI/ForkingAngleMouse);
        

        EndDrawing();
    }
    
    CloseWindow();
}