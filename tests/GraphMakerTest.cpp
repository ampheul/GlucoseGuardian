#include "libPancreas.h"

DataPoint gen_point(int i)
{
    return  DataPoint((std::time_t)i, (YType) std::sin(0.02*i)  );
}

int main(int argc, char** argv)
{
    // generate dataset
    
    DataSet data;
    
    for (int i =0; i < 100; i++)
    {
        data.push_back(gen_point(std::time(NULL) + i*20));
    }

    GraphMaker graph(XRange(0, 1),  YRange(0, 1), data);
    graph.makeGraph();
    return 0;
}