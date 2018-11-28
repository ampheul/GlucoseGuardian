#include "ReportMaker.h"

ReportMaker::ReportMaker(
    PatientInfo* patient, 
    GraphMaker graphMaker,
    std::string templateFile) 
    :
        patient(patient),
        graphMaker(graphMaker),
        templateFile(templateFile)
{}

std::string ReportMaker::makeReport()
{
    /**
     * Method:
     * Dynamically alter contents for use in latex by adding
     * a list of commands to include before the file.
     * */

    std::string graphName = this->graphMaker.makeGraph();

    std::string commandDefinitions =  
        LatexHelper::newCommand("patientName", patient->getName()) 
        + LatexHelper::newCommand("patientWeight", std::to_string(patient->getWeight()))
        + LatexHelper::newCommand("patientHeight", std::to_string(patient->getHeight()))
        + LatexHelper::newCommand("patientAge", std::to_string(patient->getAge()) )
        + LatexHelper::newCommand("patientSex", patient->getSex())
        + LatexHelper::newCommand("patientGlucoseGraph", graphName)
        + LatexHelper::newCommand("patientInsulinGraph", graphName);
    std::string inputCommand = LatexHelper::input(this->templateFile);
    std::string reportName = "report"+ std::to_string(std::time(NULL));
    std::string reportDirectory = "build/output";
    
    std::string options = 
        "-jobname " + reportName
        + " -output-directory " + reportDirectory;
    
    std::string command = 
        "pdflatex " 
        + options 
        + " \"" + commandDefinitions + inputCommand + "\"";
    std::cerr << command << std::endl;
    int sysReturn = system(command.c_str());
    
    std::cerr << "System returned " <<sysReturn<< std::endl;

    return reportDirectory + "/" + reportName + ".pdf";
    
}
