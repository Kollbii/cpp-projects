// My take on visualization of Conway's Game of Life using raylib

#include <raylib.h>
#include <iostream>
#include <stdlib.h>


int width;
int height;

// #define N 50*2
#define N 250

void getRandomStart(int L[N][N]){
    for (int i = 1; i < N - 1; i ++){
        for (int j = 1; j < N - 1; j++){
            if (GetRandomValue(0,1) == 0) L[i][j] = 1;
        }
    }
}

void updateLivings(int L[N][N]){
    int NEXT[N][N];
    int sumAround = 0;
    // int dirs[8][2] {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    for (int i = 1; i < N - 1; i++)
    for (int j = 1; j < N - 1; j++){
        NEXT[i][j] = L[i][j];

        sumAround = L[i-1][j] + L[i-1][j+1] + L[i][j + 1] + L[i+1][j+1] + L[i+1][j] + L[i+1][j-1] + L[i][j-1] + L[i-1][j-1];   

        if(L[i][j] == 1){
            if (sumAround < 2 || sumAround > 3) NEXT[i][j] = 0;
            else NEXT[i][j] = 1;
        } else {
            if (sumAround == 3) NEXT[i][j] = 1;
        }
    }

    for (int i = 1; i < N - 1; i++)
    for (int j = 1; j < N - 1; j++){
        L[i][j] = NEXT[i][j];
    }

}


int main(void){

    width = 1000;
    height = 1000;

    InitWindow(width, height, "Game of Life");
    SetTargetFPS(30);

    int SQUARESIZE = 4;
    
    int L[N][N] = {0};
    getRandomStart(L);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground({37,37,37});

        for (int i = 0, x = 0; i < width; i += SQUARESIZE, x++)
        for (int j = 0, y = 0; j < height; j += SQUARESIZE, y++){
            if (L[x][y] == 1) DrawRectangle(i, j, SQUARESIZE, SQUARESIZE, WHITE);
        }
        

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)){
                Vector2 mPos = GetMousePosition();
                std::cout << ((int)mPos.x  % 1000)/ 4<< "-" << ((int)mPos.y % 1000)/4 <<" ";
                DrawTextEx(GetFontDefault(), "Draw now!" ,{(float)width / 2 - 100, 10}, 25, 10, RED);
                L[((int)mPos.x % 999) / 4 + 1][((int)mPos.y % 999) / 4 + 1] = 1;
            }
            
        } else {
            updateLivings(L);
        }

        EndDrawing();
    }
    
    CloseWindow();
}
