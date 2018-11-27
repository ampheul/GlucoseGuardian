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
     * Dynamically alter contents for use in latex by adding
     * a list of commands to include before the file.
     * */
       
    std::string commandDefinitions =  latexNewCommand("patient", patient.getName()) 
        + latexNewCommand("weight", std::to_string(patient.getWeight()))
        + latexNewCommand("height", std::to_string(patient.getHeight()))
        + latexNewCommand("age", std::to_string(patient.getAge())
        + latexNewCommand("sex", patient.getSex()));
    
    std::string options = 
        "-jobname " + std::to_string(std::time(NULL))
        + "-output-directory " + "build/output/latex";
    
    std::string command = "pdflatex " + options + " \"" + commandDefinitions+"\""
    system(command.c_str());
    
    return;
}

/** Returns a string for a latex command.
 * 
 * Returns a string for a latex command in the form 
 *      \newcommand{\[command]}{\[definition]}
 * where [command] and [definition] are replaced with the respective arguments.
 * */

std::string latexNewCommand(std::string command, std::string definition)
{
    return "\\newcommand{\\" + command + "}[\\" + definition + "}";
}

std::string latexHeader()
{
    return "\\documentclass{article}\n";
}

std::string latexBegin(std::string environment)
{
    return "\\begin{" + environment + "}";
}

std::string latexEnd(std::string environment)
{
    return "\\end{" + environment + "}";
}

std::string inEnvironment(std::string environment, std::string text)
{
    return 
        latexBegin(environment) + "\n"
        + text + "\n"
        + latexEnd(environment);
}

    