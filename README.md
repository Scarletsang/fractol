# FRACTOL

This project aims to draw fractals efficiently without using cpu threads nor the parallel power of GPU. The MLX42 library does use shaders but only for putting pixels on the screen. All calculations in this project is done on CPU.

# Compilation

This project is only compatible for macOS and Linux. For Linux user, you have to download glfw library locally on your machine. For macOS users, by default it is using the precompiled glfw library that is located inside the respository, so you don't have to install anything by yourself, for the reason that this is meant to be a school project, and including the precompiled binaries is the fastest way to let this project be evaluted smoothly.

After you cloned this project, run the following commands:

```bash
cd fractol
git submodule update --init
make
```

Run the program like the following:

```bash
./fractol mandelbrot
./fractol burningship
./fractol burningship .13 1.2
./fractol julia
./fractol julia -0.13 1.34
```

For Julia fractal, if not specified through the command line, the default value for z is -0.73 (real component) and 0.18 (imaginary component).

For burningship fractal, the numerical parameter is used to add a factor in the burningship equation. By default, the factor is 0 (real component) and 0 (imaginary component).

# Controls

Scrolling will zoom in to or zoom out from your cursor position.

Arrow keys to navigate around the space.

Press C to start color shifting animation. Press again to stop.

Press A to start animation to see border tracing in action. Press A again to stop. Meanwhile, press S to increase rendering speed, and Shift + S to decrease animation speed.

Some fractals allow you to press Z to change the a constant in the fractal equaltion. While pressing Z, the constant will be set to a value based on your cursor position.

# How are fractals drawn?

The definition of fractals are not always clear. But it often refers to systems that have infinitely recursive patterns. In this project, fractals are generated using complex dynamics - running an equation that takes complex number as input and produces new complex number result, and use the new complex number to pass into the same equation as input. Eventually what we are interested is the behavior of the generated complex number after a certain iteration of applying the same equation. Each pixel on the screen represents a complex number to pass into the same equation. The color of each pixel represents the behavior of the iterated equation when it starts iterating at that value.

If the bahavior has a pattern, it is considered to be inside the set of numbers we will color it black. If the bahvior is chaotic, a.k.a. blows to inifinity or unpredicatable, then we color them based on how many iteration is needed before we consider them as chaotic. In other words, the colors ourside of the set represents how fast the equation on that pixel is considered chaotic.

## Optimization 1: Border tracing

For a normal escape time algorithm for drawing fractals, most of the calculations are used to find values that are inside the fractals (referred to in-set values in the following paragraphs) since they always have to iterate till the pre-defined iteration limit. My solution is to first trace the border of the in-set values, and so I can just fill the in-set values with black, and only calculate the out-set values. The algorithm I used for border tracing is from [AlmondBread](https://www.ibiblio.org/e-notes/MSet/TheAlmondBreadHomepage.htm).

An unoptimized escape time algorithm, will draw from top left to bottom right of the screen, and color each pixel based on the result of applying the complex number represented by that pixel to a complex function iteratively. (Explained in the previous section) Border tracing build on top of that. Upon any new encounter of an in-set value (after calculation), it will start border trace. It checks for the 3 other neighbouring pixels in clockwise direction. If it encounters an in-set value in a neighbour, the algorithm will move to that pixel, and repeat the same process, until the algorithm lands on the the pixel where it started tracing. To improve border recognizing, the algorithm also used the Jacob's stopping criterion, which adds a condition to the stopping condition of the border tracing process - if the direction which it ends is the same direction which the border tracing starts tracing. When it border tracing ends, it will go back to the normal rendering mode, from top left to bottom right. When it encounters an inset values before calculation of that pixel, it means it is an inset value drawn by the border tracing algorithm previously, so it will starts painting black until it finds another in-set values or it reaches the boundary of the screen. This action does not calculate anything, which significantly reduces computation.

Normally, the accuracy of the border tracing algorithm can be further increased by check 7 neighbour pixels (also known as Moore neighborhood) instead of 3. However, in my case, since I will loop through the entire screen anyway, having a less accurate border just means my program have to inititate few more times the border tracing algorithm, so in my case, it does not affect the accuracy of border recognition. It might just be a slightly decrement of rendering speed.

## Optimization 2: Distance estimimation by calculating potential

This improves accuracy of the rendering by recognizing in-set values that lives between pixels. We treat each pixel as a single point, and each point is spaced evenly to create an illusion representation of a continous mathematical space (a.k.a. the complex plain). If an in-set value just happened to be between 2 values that are out-set. Just because the spacing between the pixel missed that in-set value, it is not plotted on screen. Distance estimation considers each pixel as a square. If there is one in-set values inside the square, that pixel is colored black.

I'm no physicsian, but I see potential as the following:

If I placed particles equally distanced on a plain, and they are very light in weight. Now I put a fractal shaped heavy object on the plain. The particles that are near to the object will get attracted to it and slowly moving towards it whilst the one far away will not be affected by that much. So if a pixel contains a in-set value, even though the value represented by the pixel is out-set, it will have a very large potential as it is very close to the fractal, so we are able to catch that the pixel contains at least an in-set values, thus coloring it black.

Meanwhile, the potential can also be used to color the outset values that reflects their potential, thus distance from the fractal.

Reference: [distance_estimation_method_for_fractals](docs/distance_estimation_method_for_fractals.pdf)

# How to read my code?

The program can be splitted into 3 parts:

1. The fractal calculation that determines whether the pixel on the screen is inside the fractal set.
2. A border tracing algorithm that uses the fractal calculation to color the whole screen strategically.
3. Controllers to map user controls to changing different parameters in the program, such as translation, color shifting and animating the border tracing process.

## 1. Fractal calculation

The **complex** module encapsulates all the intensive complex number calculations required to make fractal. The complex/fractal_func.c is the main logic of how each pixel of a certain fractal is drawn. Each fractal_func calculates 2 things:

1. the distance of that value (represented by the pixel) to the nearest in-set value.
2. the potential of the value (represented by the pixel)

These two things are saved inside a distance map, which is a buffer to store these 2 data of each pixel of the window.

## 2. Border tracing

The **canvas** module provides a struct that contains all the states needed to paint fractals.

The **painter** module uses the canvas interface to draw fractals strategically. The file painter/fractal_painter.c contains the main logic of the painting process.

The **border_tracer** module lives inside the **painter** module, and it is used to trace to boundaries of the in-set values of fractals, to increase program performance.

## 3. Controllers

The **context** module creates a wrapper over all states needed in the entire program, it is conviniently use to pass all program states to MLX42 hooks, which allow the user to control the fractal painting process in real time.

The main logic of the controls lives inside hooks.c, and it uses the **animation** module to switch rendering to partial rendering so that user can see the actual process of border tracing. It also uses the **translation** module when user press the arrow keys to move around the fractal space. Diagonal translation is also supported.