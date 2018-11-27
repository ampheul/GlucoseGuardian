#include "libPancreas.h"

int main(int argc, char **argv)
{
    pipe()

    std::string command = 
        "pdflatex"
        + "-jobname "
        + std::string(std::time(NULL));
    std::system(command.c_str());

    Patient patient;

    ReportMaker(patient);

    return 0;
}