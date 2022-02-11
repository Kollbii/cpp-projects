#include <iostream>
#include <fstream>

//For better resolution change this. Aspect ratio 2:3
#define Y 2000
#define X 3000

#define MAX_N 100
#define MIN_REAL -2
#define MAX_REAL 1
#define MIN_IMAG -1
#define MAX_IMAG 1

using namespace std;

double mapToReal(int x, int width, double minR, double maxR){
    return x * ((double)(maxR-minR)/width) + minR;
}

double mapToImag(int y, int height, double minI, double maxI){
    return y * ((double)(maxI-minI)/height) + minI;
}

int MandelSet(double cr, double ci, int max_iter){
    int i=0;
    double tr=0.0, ti=0.0;
    while (i < max_iter && tr*tr + ti*ti < 4.0){
        double tmp = tr*tr - ti*ti + cr;
        ti = 2.0*tr*ti + ci;
        tr = tmp;
        i++; 
    }
    return i;
}

int main(void){

    ofstream fout("output_mand.ppm");
    fout << "P3" << endl;
    fout << X << " " << Y << endl;
    fout << "256" << endl;

    for (int y = 0; y < Y; y++){
        for (int x = 0; x < X; x++){
            double cr = mapToReal(x, X, MIN_REAL, MAX_REAL);
            double ci = mapToImag(y, Y, MIN_IMAG, MAX_IMAG);

            int n = MandelSet(cr, ci, MAX_N);

            fout << (n % 256) << " " << (n % 256) << " " << (n % 256) << " ";
        }
        fout << endl;
    }
    fout.close();
    cout << "End" << endl;
    return 0;
}