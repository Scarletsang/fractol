# FRACTOL

Pseudo code for border tracing algorithm:

1. set all pixels alpha channels to 0
2. loop with a pointer on the image, from top left to bottom right:
  if pixel is empty, calculate the pixel
  if pixel is in-set and left is boundary or out-set, border trace
  if pixel is boundary and right is in-set, fill until the pixel isnt empty

```c
UP = 0b00
RIGHT = 0b01
DOWN = 0b10
LEFT = 0b11

/*
Directions:
U, R, D, D, L, L, U, U
R, D, L, L, U, U, R, R
D, L, U, U, R, R, D, D
L, U, R, R, D, D, L, L

Observation: directions only change when step is 1, 2, 4, or 6.
*/

DRAW_MANDELBROT()
  SET_IMAGE_TO_EMPTY(image)
  while y < height of the image
    while x < width of the image
      current = GET_PIXEL(image, x, y)
      if current = EMPTY
        current = CALCULATE_AND_FILL(current)

      if current = INSET && left = BOUNDARY/OUTSET
        current = BORDER_TRACE(current)

      if current = BOUNDARY/OUTSET && right = INSET
        current = FILL_INSET(current)

FILL_INSET(current)
  current++
  while (current = EMPTY)
    fill INSET
    current++

BORDER_TRACE(current)
  tracer = current
  dir = DOWN
  step = 1
  while true
    /* Stopping condition is using Jacob's stopping criterion, so that
    it is able to trace a bigger family of boundaries
    */
    if MOORE(tracer, dir, step) == current && dir == DOWN
      return tracer + 1

// Moore's neighbour, finding boundaries based on the 8 neighbouring pixels
MOORE(tracer, dir, step)
  tracer = MOVE_TRACER(tracer, dir)
  if (tracer = EMPTY)
    tracer = CALCULATE_AND_FILL(tracer)
  if (tracer = INSET)
    dir = OPPOSITE_DIR(dir)
    return tracer
  else
    step++
    dir = CLOCKWISE(dir, step)
    return MOORE(tracer, dir)

// change direction of the convolution just like Moore's neightbour.
CLOCKWISE(dir, step)
  if (step == 1 || (step & 1) == 0)
    return (CHANGE_DIR(dir))
  return (dir)

OPPOSITE_DIR(dir)
  return CHANGE_DIR(CHANGE_DIR(dir))

CHANGE_DIR(dir)
  if (dir == LEFT) return UP
  return (dir + 1)
```
