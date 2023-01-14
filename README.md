# FRACTOL

## TODO:

1. complex number calculation
2. escape time algorithm to determine color of one pixel
3. border tracing to draw the borders.
4. Fill the outside pixels using external distance estimation coloring.
5. Translation and zooming in the hook

```c
// Compute a formula from a complex number input
t_fractol_complex *apply_formula(t_fractol_complex *last_step);

// Compute a formula repeatedly by putting the result of the last
// iteration as the input of the current iteration.
int iterate_formula(t_fractol_complex *initial_value, double escape_value);

// Converts the amount of iteration 
t_fractol_color iteration_to_color(int interation);

```
