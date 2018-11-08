/**
 * Author:  Thomas Vandeven
 * Date:    November 7th 2018
 * 
 * GraphMaker Produces graphs given xrange, yrange and a set of data.
 * */

#ifndef GRAPHMAKER_H
#define GRAPHMAKER_H

/** GraphMaker
 * produces graphs given x range, y range, and a set of data
 */

#include <unistd.h>
#include <iostream>
#include <ctime>

class GraphMaker
{
    public:
        GraphMaker(
            std::pair<double,double> xrange, 
            std::vector<std::pair<double, double>> data);
        void makeGraph();
    private:
        std::pair<double, double> xrange; // range (a,b), a < b
        std::pair<double, double> yrange; // same as xrange, but for y-axis
        std::vector<std::pair<std::time_t,double>> data; // set of coordinates (x,y)
};

#endif