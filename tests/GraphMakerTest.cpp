#include "libPancreas.h"

DataPoint gen_point(std::time_t anchor, std::time_t timeAgo, int i)
{
    // seconds into the past which point lies 
    
    return  DataPoint(
        (XType) (anchor - timeAgo), 
        (YType) std::sin(0.2*i));
}

DataSet gen_dataset(XRange xrange, YRange yrange)
{
    int numPoints = 100;
    DataSet data;

    std::time_t currentTime = xrange.second;
    std::time_t timeAgo = (std::time_t)std::difftime(xrange.second, xrange.first)/100;
    std::time_t anchor = currentTime - timeAgo*numPoints;
    
    for (int i =0; i < numPoints; i++)
    {
        DataPoint d = gen_point(anchor, -i*timeAgo, i);
        data.push_back(d);
    }
    return data;
}

int main(int argc, char** argv)
{
    std::time_t oneWeek = (std::time_t)7*24*60*60;
    std::time_t currentTime = std::time(NULL);

    XRange xrange( currentTime - oneWeek, currentTime);
    YRange yrange(0,10.1);
    /*PatientInfo * spaghetti = Spaghetti().makePatient();
        std::cerr <<"here"<<std::endl; 

    vector<MonitorRecord> *records = spaghetti->getMonitorRecords();
    DataSet data;
    std::cerr <<"here"; 
    for (auto& record: *records)
    {
        std::cout << record.getReading().getAmount()
            <<" " << record.getRecordTime() << std::endl;

        data.push_back(DataPoint(
            (XType)record.getRecordTime(), 
            (YType)record.getReading().getAmount()));
        std::cout << data.back().first <<" " << data.back().second<<std::endl;

    }*/
    DataSet data = gen_dataset(xrange,yrange);
    
    /*
    if (records->empty())
    {
        std::cerr << "AAAAAHHHH input empty\n";
    }
    */

    GraphMaker graph;

    // make the graph
    std::string graphname = graph.makeGraph(xrange, yrange, data);
    
    // tell us about it
    std::cout << "Made graph. Stored in:\t\v" << graphname << std::endl;
    
    return 0;
}