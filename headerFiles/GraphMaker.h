/**\file GraphMaker.h
 * Author:  Thomas Vandeven
 * Date:    November 7th 2018
 * 
 * GraphMaker Produces graphs given xrange, yrange and a set of data.
 * */

#ifndef GRAPHMAKER_H
#define GRAPHMAKER_H



#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <sys/wait.h>

typedef std::time_t XType;
typedef double YType;
typedef std::pair<XType, XType> XRange;
typedef std::pair<YType, YType> YRange;
typedef std::pair<XType, YType> DataPoint;
typedef std::vector<DataPoint> DataSet;

/**! A class for generating graphs of patient data
 *  
 * Uses GnuPlot to generate graphs of class data.
 * */
class GraphMaker
{
    public:

        GraphMaker(XRange xrange, YRange yrange, DataSet data);
        void makeGraph();

    private:

        XRange xrange; //! range (a,b), a < b
        YRange yrange; //! same as xrange, but for y-axis
        DataSet data; //! set of coordinates (x,y)
        std::string graphFile; ///! The .gnu file to be used when creating the graph
        static std::string makeGraphString(DataSet data); //! internal use. Makes a string for a gnuplot file.
};

#endif