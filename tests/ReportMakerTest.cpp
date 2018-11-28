#include "libPancreas.h"

int main(int argc, char **argv)
{
    PatientInfo* spaghetti = Spaghetti().makePatient();

    std::time_t baseTime = std::time(NULL);
	std::time_t oneWeek = (time_t)7*24*60*60;
	

	// construct data for graphMaker
	DataSet data; 

	for (auto& record : spaghetti->getMonitorRecords())
	{
		data.push_back(
			DataPoint(
				(XType)record.getRecordTime(),
				(YType)record.getReading().getAmount())
			);
	}
	std::cerr << "here"<<std::endl;

	// construct ranges for graphMaker
	XRange xrange(baseTime-oneWeek,baseTime);
	YRange yrange(0,200);
	// instantiate graphMaker
	GraphMaker graphMaker(xrange, yrange, data);
    
	// instantiate reportMaker
	ReportMaker reportMaker(spaghetti, graphMaker);

	// make the report
	std::string reportLocation = reportMaker.makeReport();

	// talk about it.
	std::cerr << "Done making report. Stored in:\t\v"<< reportLocation << std::endl;

    return 0;
}

