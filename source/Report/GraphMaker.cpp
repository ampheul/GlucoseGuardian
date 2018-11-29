/**
 * \file GraphMaker.h
 * \author Thomas Vandeven
 * */

#include "GraphMaker.h"


std::string GraphMaker::makeGraph(XRange xrange, YRange yrange, DataSet data, std::string gnuFile)
{
    DataSet filteredData;
    for (auto& point : data)
    {
        // check if point is in the interval [a,b] defined by xrange
        if (    std::difftime(point.first, xrange.first) >= 0 
            &&  std::difftime(xrange.second, point.first) >= 0)
        {
            filteredData.push_back(point);
        }
    }
    int toGnuPlot[2];

    if (pipe(toGnuPlot)!= 0)
        std::exit(1);
    
    std::string commands = 
        "set xtics " 
        + std::to_string((std::time_t)std::difftime(xrange.second, xrange.first)/40) + ";"
        + "set xrange ["+
            std::to_string(xrange.first) 
            + ":"
            + std::to_string(xrange.second) 
        + "];";


    std::string graphFileName = 
        "build/output/graph" + std::to_string(std::time(NULL));

    FILE* pic = 
        fopen( (graphFileName + ".png").c_str(), "w");
    FILE* toGnuPlotFile = 
        fdopen(toGnuPlot[1], "w");
    
    for (DataSet::iterator it = filteredData.begin();
        it != filteredData.end(); ++it)
    {
        fprintf(toGnuPlotFile, "%d %lf\n", (int)it->first, (double)it->second);
    }
    fclose(toGnuPlotFile);
    
    pid_t pid = fork();
    
    if (pid == 0)
    {   
        dup2(toGnuPlot[0], STDIN_FILENO);
        dup2(fileno(pic), STDOUT_FILENO);
        
        execlp("gnuplot", 
            "gnuplot", "-e", commands.c_str(), gnuFile.c_str(), 
            NULL);
        std::cerr << "this line should never be reached" << std::endl;
        std::exit(1);
    }
    else
    {
        wait(NULL); // wait for child to exit
        dup2(STDOUT_FILENO, STDOUT_FILENO);
    }

    close(toGnuPlot[0]);
    fclose(pic);

    return graphFileName;
}