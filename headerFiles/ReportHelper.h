#ifndef REPORTHELPER_H
#define REPORTHELPER_H

#include <string>

/// namespace to provide easy access fields when making Reports and Graphs
namespace ReportHelper
{
    /// A container for graph related strings
    ///
    /// Contains graph related strings such as the root path 
    /// and each of the distinct gnuplot files
    namespace Graph
    {
        const std::string ROOT_PATH = "base/graphing/";

        const std::string BASIC     = ROOT_PATH + "basicgraph.gnu";
        const std::string GLUCOSE   = ROOT_PATH + "glucosegraph.gnu";
        const std::string INSULIN   = ROOT_PATH + "insulingraph.gnu";
    }
    
};



#endif