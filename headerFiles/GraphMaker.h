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
#include <cstdio>
#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <fstream>

class GraphMaker
{
    typedef std::time_t GraphXType;
    typedef double GraphYType;
    typedef std::pair<GraphXType, GraphXType> GraphXRange;
    typedef std::pair<GraphYType, GraphYType> GraphYRange;
    typedef std::pair<GraphXType, GraphYType> GraphDataPoint;
    typedef std::vector<GraphDataPoint> GraphDataSet;

    public:
        GraphMaker(
            GraphXRange xrange, 
            GraphYRange yrange,
            GraphDataSet data);
        void makeGraph();
    private:
        GraphXRange xrange; // range (a,b), a < b
        GraphYRange yrange; // same as xrange, but for y-axis
        GraphDataSet data; // set of coordinates (x,y)
        static std::string makeGraphString(GraphDataSet data); // internal use. Makes a string for a gnuplot file.
};

#endif