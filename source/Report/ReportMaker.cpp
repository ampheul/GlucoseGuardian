#include "ReportMaker.h"

ReportMaker::ReportMaker(Patient patient, GraphMaker graphMaker) 
    : 
        patient(patient), 
        graphMaker(graphMaker)
{}

void ReportMaker::makeReport()
{
    /**
     * Method:
     * pipe latex code into a latex file and use this to pipe into latex.
     * The file we pipe to will be included as input in the latex header
     * */
    int toLatex[2];
    pipe(toLatex);
    FILE* latexWrite = fdopen(toLatex[1],"w");

    fprintf(latexWrite, "\\documentclass{article}");

    


    return;
}
/** return a string for a latex command.
 * 
 * Returns a string for a latex command in the form 
 *      \newcommand{\[command]}{\[definition]}
 * where [command] and [definition] are replaced with the respective arguments.
 * */
std::string latexNewCommand(std::string command, std::string definition)
{
    return "\\newcommand{\\" + command + "}[\\" + defintion + "}"
}


    