#include "GraphMaker.h"

GraphMaker::GraphMaker(
    std::pair<double,double> xrange,
    std::pair<double,double> yrange,
    std::vector<std::pair<std::time_t,double>> data)
{
    if (xrange.first > xrange.second)
        xrange.swap();
    if (yrange.first > yrange.second)
        yrange.swap();
    this->xrange = xrange;
    this->yrange = yrange;
    this->data = data;
}

void GraphMaker::makeGraph()
{
    
    
    int toGnuPlot[2];
    int fromGnuPlot[2];

    pipe(fromGnuPlot);
    pipe(toGnuPlot);
    pid_t pid = fork();

    if (pid == 0)
    {
        dup2(STDIN_FILENO, pipeOut[0]);
        dup2(STDOUT_FILENO, gnuPlot)
        // this is the forked program
        execlp("gnuplot", "gnuplot", "-", NULL);
    }
    else if (pid > 0)
    {
        dup2(STDOUT_FILENO, toGnuPlot[1]);
        std::cout << "set ouput " << std::time(NULL);
        
        close(toGnuPlot[1]);

        dup2(STDOUT_FILENO, STDOUT_FILENO);
    }
    else
    {
        std::cerr << "ERROR forking in GraphMaker" << std::endl;
    }


}