//__________________________________________________________________________
// Author(s): Claudio Pizzolato, Monica Reggiani - June 2014
// email:  claudio.pizzolato@griffithuni.edu.au
//         monica.reggiani@gmail.com
//
// DO NOT REDISTRIBUTE WITHOUT PERMISSION
//__________________________________________________________________________
//


#include "InputQueues.h"

#include <vector>


namespace CEINMS {
    InputConnectors::~InputConnectors()
    {
        if (!queueMomentArms.empty())
        {
            for (auto it : queueMomentArms)
                delete it;
        }
    }

    //:TODO: I have no idea about this globalTimeLimit.... WHY... AND WHY SO HIDDEN.. come on
//    float globalTimeLimit = 100.;

};
