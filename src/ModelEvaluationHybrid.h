#ifndef ModelEvaluationHybrid_h
#define ModelEvaluationHybrid_h

#include <vector>
#include <string>
#include "ModelEvaluationBase.h"

template <typename NMSmodelT, typename ErrorMinimizerT>
class ModelEvaluationHybrid : public ModelEvaluationBase {

public:
    ModelEvaluationHybrid(NMSmodelT& subject, ErrorMinimizerT& torqueErrorMinimizer);
    void operator()();
    
private:
    NMSmodelT& subject_;
    ErrorMinimizerT& torqueErrorMinimizer_;
    std::vector< std::string > dofNames_;
    std::vector< std::string > dofNamesWithExtTorque_;
    unsigned noDof_;
};

#include "ModelEvaluationHybrid.cpp"

#endif
