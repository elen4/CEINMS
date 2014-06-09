//__________________________________________________________________________
// Author(s): Claudio Pizzolato, Monica Reggiani - September 2013
// email:  claudio.pizzolato@griffithuni.edu.au
//
// DO NOT REDISTRIBUTE WITHOUT PERMISSION
//__________________________________________________________________________
//


#ifndef ModelEvaluationOnline_h
#define ModelEvaluationOnline_h

#include <vector>
#include <string>
#include "ModelEvaluationBase.h"

template <typename NMSmodelT>
class ModelEvaluationOnline : public ModelEvaluationBase {

public:
    ModelEvaluationOnline() = delete;
    ModelEvaluationOnline(NMSmodelT& subject, const std::string& outputDir = "./Output");
    void setOutputDirectory(const std::string& outputDir);
//    void setSubject(NMSmodelT& subject);
    void operator()();
    
private:
    NMSmodelT& subject_;
    std::string outputDir_;
    std::vector< std::string > dofNames_;
    std::vector< std::string > dofNamesWithExtTorque_;
    unsigned noDof_;
    double globalEmDelay_;
};

#include "ModelEvaluationOnline.cpp"

#endif