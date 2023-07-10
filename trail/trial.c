// #include "mlx/mlx.h"

// #define WIDTH 800
// #define HEIGHT 600
// #define MAX_ITERATIONS 20000

// typedef struct
// {
//     double x;
//     double y;
// } complex;

// int mandelbrot_set(complex c)
// {
//     complex z;
//     z.x = 0;
//     z.y = 0;

//     int iterations = 0;
//     while (z.x * z.x + z.y * z.y < 4 && iterations < MAX_ITERATIONS)
//     {
//         double temp = z.x * z.x - z.y * z.y + c.x;
//         z.y = 2 * z.x * z.y + c.y;
//         z.x = temp;
//         iterations++;
//     }

//     return iterations;
// }

// int main()
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot Set");

//     int x, y;
//     double scale = 4;
//     complex offset;
//     offset.x = -0.5;
//     offset.y = 0;

//     for (y = 0; y < HEIGHT; y++)
//     {
//         for (x = 0; x < WIDTH; x++)
//         {
//             complex c;
//             c.x = (x - WIDTH / 2.0) * scale / WIDTH + offset.x;
//             c.y = (y - HEIGHT / 2.0) * scale / HEIGHT + offset.y;

//             int iterations = mandelbrot_set(c);

//             if (iterations == MAX_ITERATIONS)
//                 mlx_pixel_put(mlx, win, x, y, 0x000000); // Set pixel to black
//             else
//                 mlx_pixel_put(mlx, win, x, y, iterations * 0x000FCCA46 / MAX_ITERATIONS); // Gradually change pixel color based on iterations
//         }
//     }

//     mlx_loop(mlx);

//     return 0;
// }
