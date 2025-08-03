#pragma once
#include <string>
#include <vector>
#include "simstruc.h"

// Templated helper function to extract S-function parameters
template<typename T>
T extractSFunctionParameter(SimStruct *S, int paramIndex, const T& defaultValue);

// Specialization for std::string
template<>
std::string extractSFunctionParameter<std::string>(SimStruct *S, int paramIndex, const std::string& defaultValue) {
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

// Specialization for int
template<>
int extractSFunctionParameter<int>(SimStruct *S, int paramIndex, const int& defaultValue) {
    const mxArray* param = ssGetSFcnParam(S, paramIndex);
    if (param == nullptr || !mxIsScalar(param)) {
        return defaultValue; // Default fallback
    }
    return static_cast<int>(mxGetScalar(param));
}

// Specialization for double
template<>
double extractSFunctionParameter<double>(SimStruct *S, int paramIndex, const double& defaultValue) {
    const mxArray* param = ssGetSFcnParam(S, paramIndex);
    if (param == nullptr || !mxIsScalar(param)) {
        return defaultValue; // Default fallback
    }
    return mxGetScalar(param);
}

// Specialization for std::vector<int>
template<>
std::vector<int> extractSFunctionParameter<std::vector<int>>(SimStruct *S, int paramIndex, const std::vector<int>& defaultValue) {
    const mxArray* param = ssGetSFcnParam(S, paramIndex);
    if (param == nullptr || !mxIsNumeric(param)) {
        return defaultValue; // Default fallback
    }
    
    mwSize numElements = mxGetNumberOfElements(param);
    std::vector<int> result;
    result.reserve(numElements);
    
    double* data = mxGetPr(param);
    for (mwSize i = 0; i < numElements; ++i) {
        result.push_back(static_cast<int>(data[i]));
    }
    
    return result;
}

// Specialization for std::vector<double>
template<>
std::vector<double> extractSFunctionParameter<std::vector<double>>(SimStruct *S, int paramIndex, const std::vector<double>& defaultValue) {
    const mxArray* param = ssGetSFcnParam(S, paramIndex);
    if (param == nullptr || !mxIsNumeric(param)) {
        return defaultValue; // Default fallback
    }
    
    mwSize numElements = mxGetNumberOfElements(param);
    std::vector<double> result;
    result.reserve(numElements);
    
    double* data = mxGetPr(param);
    for (mwSize i = 0; i < numElements; ++i) {
        result.push_back(data[i]);
    }
    
    return result;
}

// Specialization for std::vector<std::string>
template<>
std::vector<std::string> extractSFunctionParameter<std::vector<std::string>>(SimStruct *S, int paramIndex, const std::vector<std::string>& defaultValue) {
    const mxArray* param = ssGetSFcnParam(S, paramIndex);
    if (param == nullptr || !mxIsCell(param)) {
        return defaultValue; // Default fallback
    }
    
    mwSize numElements = mxGetNumberOfElements(param);
    std::vector<std::string> result;
    result.reserve(numElements);
    
    for (mwSize i = 0; i < numElements; ++i) {
        const mxArray* cellElement = mxGetCell(param, i);
        if (cellElement != nullptr && mxIsChar(cellElement)) {
            mwSize nameLen = mxGetNumberOfElements(cellElement) + 1;
            char* nameBuffer = new char[nameLen];
            
            if (mxGetString(cellElement, nameBuffer, nameLen) == 0) {
                result.emplace_back(nameBuffer);
            } else {
                result.emplace_back(""); // Empty string for failed extraction
            }
            delete[] nameBuffer;
        } else {
            result.emplace_back(""); // Empty string for non-string cells
        }
    }
    
    return result;
}

