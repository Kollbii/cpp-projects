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

