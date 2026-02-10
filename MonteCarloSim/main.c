#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
# include <math.h>

int main(){


    // Generate random points on a disk

    int numPoints = 100; // number of random points to generate
    double radius = 1.0; // radius of the disk
    double PI = 3.141592653589793;
    double x, y, z; // variables to store coordinates of the points


    for (int i = 0; i < numPoints; i++){
        double r = radius * sqrt((double)rand() / RAND_MAX); // random radius with uniform distribution
        double theta = 2 * PI * ((double)rand() / RAND_MAX); // random angle with uniform distribution

        x = r * cos(theta); // x coordinate of the point
        y = r * sin(theta); // y coordinate of the point
        z = 0.0; // z coordinate is 0 for points on the disk

        printf("Point %d: (%.4f, %.4f, %.4f)\n", i + 1, x, y, z); // print the coordinates of the point
    }


    return 0;
}