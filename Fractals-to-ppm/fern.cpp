#include <fstream>
#include <iostream>
#include <stdlib.h>

int main(void){
    std::cout << "Starting" << std::endl;

    int **arr=new int*[3000];
	for(int i = 0; i < 3000; i++){
		arr[i] = new int[3000];
        for (int j = 0; j < 3000; j++){
            arr[i][j] = 0;
        }
	}

    double r, x, y, x1, y1;
    const int resolution = 20000000;

    // Gener points
    x=0.0;
    y=0.0;
    for (int i = 0; i < resolution; i++){
        r = ((double) rand() / (RAND_MAX));
        if (r < 0.1){
            x1 = 0.00 * x + 0.00 * y;
            y1 = 0.00 * x + 0.16 * y + 0.00;
        } else if( r < 0.86){
            x1 = 0.85 * x + 0.04 * y;
            y1 = -0.04 * x + 0.85 * y + 1.60;
        } else if (r < 0.93){
            x1 = 0.20 * x - 0.26 * y;
            y1 = 0.23 * x + 0.22 * y + 1.60;
        } else {
            x1 = -0.15 * x + 0.28 * y;
            y1 = 0.26 * x + 0.24 * y + 0.44;
        }

        int p1 = (int)(x1*290 + 1500);
        int p2 = (int)(y1*290);
        arr[p1][p2]=1;

        x=x1;
        y=y1;
    }

    std::ofstream fout("output_ferns.ppm");
    fout << "P3" << std::endl;
    fout << "3000" << " " << "3000" << std::endl;
    fout << "256" << std::endl;

    // Write points to *.ppm
    for (int i = 0; i < 3000; i++){
        for (int j = 0; j < 3000; j++){
            if (arr[i][j]==1){
                fout << 255 << " " << 255 << " " << 255 << " ";
            }else{
                fout << 1 << " " << 1 << " " << 1 << " ";
            }
        }
        fout << std::endl;
    }
    fout.close();
    std::cout << "End" << std::endl;
    return 0;
}