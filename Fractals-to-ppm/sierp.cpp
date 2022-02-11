#include <fstream>
#include <iostream>

#define Y 2048
#define X 2048

using namespace std;

int main(void){
    int row, i, x;
    int size = 2048;

    ofstream fout("output_sierp.ppm");
    fout << "P3" << endl;
    fout << X << " " << Y << endl;
    fout << "256" << endl;
    
    for (row = size - 1; row >= 0; row--){
        for (i = 0; i < row; i++){
            fout << 1 <<" "<< 1 << " " << 1 << " ";
        }
        for (x = 0; (x+row) < size; x++){
            if (x&row){
                fout << 1 <<" "<< 1 << " " << 1 << " ";
            }else {
                fout << 200 <<" "<< 200 << " " << 200 << " ";
            }
        }
        fout << endl;
    }
    fout.close();
    return 0;
}