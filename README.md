# Info about repository  
Stuff i do to learn. SFML, raylib, basic physics programs and some scripts from learning sites like cs-academy.  
  
Here is just a preview. More nice codes / simulations with descriptions can be found in */Programs*

# My take on Conway's Game of Life in raylib
The rules are on Wiki: [Wikipedia](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

### Generating random 250 x 250 size population.
White square - living square  
Grey square - dead square  

Simulation generates a random number of living squares. There is no wrapping on edges which means this simple implementation can 'stop moving' at some point.

![gol1](/Images/game-of-life1.gif)

Also if you hold LMB simulation stops and you are able to draw! :)  
Press RMB to draw with your LMB simultaneously.  (LMB -> RMB -> drawning white squares)

![gol2](/Images/game-of-life2.gif)

Note: Gifs are speeded up 3 times.

# Visualize sorting using SFML  
Along with @tadeuszwachowski!

Setting up array of numbers was the easiest part. But to manage this 'rainbow' flow we spent ~50 minutes and it was just as easy as 5 this lines... 🥴
```cpp
void setColors(float h, float *rgb) {
    float frequency = 0.05;
    int i = h/6.7;
    rgb[0] = sin(frequency*i + 0) * 127 + 128;
    rgb[1] = sin(frequency*i + 2) * 127 + 128;
    rgb[2] = sin(frequency*i + 4) * 127 + 128;
}
```

As said in title - program visualizes sorting. For now we implemented bubble sort and quicksort. Watch gifs!

### Bubble sort visualization
![Bubble sort](/Images/sorting1.gif)

### Quicksort visualization
![Quicksort](/Images/sorting2.gif)

Unfortunately for reasons unknown to me program crashes if it has >~180 numbers. I couldn't figure out what causes it. Maybe I'll manage later with help of @tadeuszwachowski. 

# Fractals in raylib

Simple program to draw fractals. In visualization there is 8 'trees'. Each is rotated by an angle of pi/4.  
Max range of forking angle: <π;π/100>

### Gif to visualize  
![fractal gif](/Images/fractals.gif)

## Galery: 
### Fractals at angle of π (a lot of lines at top of each other...)
![fractal 1](/Images/frac1.png)

### Fractals at angle of π/2
![fractal 2](/Images/frac2.png)

### Fractals at angle of ~ π/21
![fractal 3](/Images/frac3.png)

### Barnsley fern at different resolution
![fractal 4](/Images/fern0.png)
![fractal 5](/Images/fern2.png)

### Mandelbrot 
![fractal 6](/Images/mandelbrot.png)

### Sierpinski triangle 
![fractal 7](/Images/sierp2048.png)
