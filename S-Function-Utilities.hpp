#pragma once
#include <string>
#include "simstruc.h"

// Helper function to get string parameter from S-function parameters
template<>
std::string extractSFunctionParameterAsString(SimStruct *S, int paramIndex, const std::string& defaultValue = "default") {
    const mxArray* param = ssGetSFcnParam(S, paramIndex);
    if (param == nullptr || !mxIsChar(param)) {
        return defaultValue; // Default fallback
    }
    
    // Get string length and allocate buffer
    mwSize nameLen = mxGetNumberOfElements(param) + 1;
    char* nameBuffer = new char[nameLen];
    
    // Extract string from MATLAB parameter
    if (mxGetString(param, nameBuffer, nameLen) == 0) {
        std::string result(nameBuffer);
        delete[] nameBuffer;
        return result;
    } else {
        delete[] nameBuffer;
        return defaultValue;
    }
}
