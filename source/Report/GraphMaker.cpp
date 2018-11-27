

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

void GraphMaker::makeGraph()
{
    int toGnuPlot[2];

    if (pipe(toGnuPlot)!= 0)
        std::exit(1);
    
    std::string graphFileName = "build/output/graphs/" + std::to_string(std::time(NULL)) + ".png";
    this->graphFile = graphFileName;
    FILE* pic = 
        fdopen(graphFileName.c_str(), "w");
    FILE * toGnuPlotFile = 
        fdopen(toGnuPlot[1], "w");

    
    for (DataSet::iterator it = this->data.begin();
        it != this->data.end(); ++it)
    {
        fprintf(toGnuPlotFile, "%d %lf\n", (int)it->first, (double)it->second);
    }
    fclose(toGnuPlotFile);


    pid_t pid = fork();
    
    if (pid == 0)
    {   
        dup2(toGnuPlot[0], STDIN_FILENO);
        dup2(fileno(pic), STDOUT_FILENO);
        
        execlp("gnuplot", "gnuplot", "contours.7.gnu", NULL);
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

}

std::string GraphMaker::makeGraphString(DataSet data)
{
    std::ifstream plotFile("contours.7.gnu");
    
    std::stringstream ss;
    std::string s;

    while ( !plotFile.eof() )
    {
        std::getline(plotFile, s);
        ss << s << std::endl;
    }
    
    for (auto & point : data)
    {
        ss << point.first <<" "<< point.second << std::endl;
    }
    ss << "EOF" << std::endl;

    return ss.str();
}