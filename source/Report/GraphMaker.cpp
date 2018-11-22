#include "GraphMaker.h"

GraphMaker::GraphMaker(
    std::pair<double,double> xrange,
    std::pair<double,double> yrange,
    std::vector<std::pair<std::time_t,double>> data)
{
    if (xrange.first > xrange.second)
        return;
    if (yrange.first > yrange.second)
        return;
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
        dup2(STDIN_FILENO, toGnuPlot[0]);
        dup2(STDOUT_FILENO, fromGnuPlot[1]);
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