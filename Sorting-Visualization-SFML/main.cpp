#include <SFML/Graphics.hpp>
#include <time.h>
#include <math.h>

/*
    Maybe some sounds added later :)
*/

const int NUMBERS = 160; // CHANGE HERE
int finished = 0;
sf::RectangleShape rects[NUMBERS];
sf::RenderWindow window(sf::VideoMode(1200, 800), "Visualization of algorithms");

void setColors(float h, float *rgb) {
    float frequency = 0.05;
    int i = h/6.7;
    rgb[0] = sin(frequency*i + 0) * 127 + 128;
    rgb[1] = sin(frequency*i + 2) * 127 + 128;
    rgb[2] = sin(frequency*i + 4) * 127 + 128;
}

void setRandoms(){
    for (int i = 0; i < NUMBERS; i++){
        sf::RectangleShape rect;
        float colors[3];
        int height = 800 - rand()%800;
        rect.setPosition(i*8, 800);             // CHANGE HERE
        rect.setSize(sf::Vector2f(5, height));  // CHANGE HERE
        setColors((float)height, colors);
        rect.setFillColor(sf::Color(colors[0], colors[1], colors[2]));
        rect.rotate(180);
        rects[i] = rect;
    }
}

void quick_sort(sf::RectangleShape *tab, int left, int right){
	if (right <= left) return;
	
	int i = left - 1, j = right + 1; 
	int pivot = tab[(left+right)/2].getSize().y;
	
	while (1) {

		while(pivot > tab[++i].getSize().y);
		
		while(pivot < tab[--j].getSize().y);
		
		if ( i <= j) {
            sf::RectangleShape temp;
            temp = rects[i];
            rects[i] = rects[j];
            rects[j] = temp;
            rects[i].setPosition(8*i, 800);            // CHANGE HERE
            rects[j].setPosition(8*j, 800);            // CHANGE HERE

            window.clear(sf::Color(37,37,37));
            for (int k = 0; k < NUMBERS; k++)
                window.draw(rects[k]);
            window.display();
            sf::sleep(sf::milliseconds(10));
        }
		else {
			break;
        }
	}

	if(j > left)
	    quick_sort(tab, left, j);
	if(i < right)
	    quick_sort(tab, i, right);
}

int main(){
    srand(time(nullptr));

    /* Fill data */
    setRandoms();

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (!finished){

            /* Bubble sort */
            
            for (int i = 0; i < NUMBERS; i++)
            for (int j = i + 1; j < NUMBERS; j++){

                window.clear(sf::Color(37,37,37));  

                if (rects[i].getSize().y > rects[j].getSize().y){
                    sf::RectangleShape temp;
                    temp = rects[i];
                    rects[i] = rects[j];
                    rects[j] = temp;
                    rects[i].setPosition(8*i, 800);        // CHANGE HERE
                    rects[j].setPosition(8*j, 800);        // CHANGE HERE
                }

                for (int k = 0; k < NUMBERS; k++)
                    window.draw(rects[k]);
                window.display();
            }
        
            /* Quicksort */

            // quick_sort(rects, 0, NUMBERS - 1);       // UNHASH THIS BUT HASH BUBBLE SORT LOOPS
            finished = 1;
        }

        // finished = 0;    // <-- UNHASH TO GET INFINITE LOOP OF GENERATE -> SORT
        // setRandoms();    // <-- 
        sf::sleep(sf::milliseconds(1000));
        window.clear(sf::Color(37,37,37));

        for (int k = 0; k < NUMBERS; k++)
            window.draw(rects[k]);

        window.display();
    }

   return 0;
}
