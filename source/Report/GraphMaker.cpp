

#include "GraphMaker.h"

/** 
 * Constructor for GraphMaker.
 * 
 * */
GraphMaker::GraphMaker(XRange xrange, YRange yrange, DataSet data)
{
    if (xrange.first > xrange.second)
        return;
    if (yrange.first > yrange.second)
        return;
    this->xrange = xrange;
    this->yrange = yrange;
    this->data = data;
}

std::string GraphMaker::makeGraph()
{
    int toGnuPlot[2];

    if (pipe(toGnuPlot)!= 0)
        std::exit(1);
    
    std::string graphFileName = 
        "build/output/graphs/" + std::to_string(std::time(NULL)) + ".png";
    
    FILE* pic = 
        fopen(graphFileName.c_str(), "w");
    FILE * toGnuPlotFile = 
        fdopen(toGnuPlot[1], "w");

    
    for (DataSet::iterator it = this->data.begin();
        it != this->data.end(); ++it)
    {
        fprintf(toGnuPlotFile, "%d %lf\n", (int)it->first, (double)it->second);
    }
    fclose(toGnuPlotFile);

    std::string graphBase = "base/reports/basicgraph.gnu";
    
    pid_t pid = fork();
    
    if (pid == 0)
    {   
        dup2(toGnuPlot[0], STDIN_FILENO);
        dup2(fileno(pic), STDOUT_FILENO);
        
        execlp("gnuplot", "gnuplot", graphBase.c_str(), NULL);
        std::cerr << "this line should never be reached" << std::endl;
        std::exit(1);
    }
    else
    {
        dup2(STDOUT_FILENO, STDOUT_FILENO);
        
        wait(NULL); // wait for child to exit
        
    }

    close(toGnuPlot[0]);
    fclose(pic);

    return graphFileName;
}