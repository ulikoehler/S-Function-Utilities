#pragma once
#include <string>
#include <vector>
#include <optional>
#include "simstruc.h"

// Templated helper function to extract S-function parameters.
// Returns std::nullopt on any error instead of a caller-provided default.
template<typename T>
std::optional<T> extractSFunctionParameter(SimStruct *S, int paramIndex);

/**
 * MATLAB requires error messages to be in persistent memory.
 * Since logically, only one error message can be active at any one time,
 * we store it in this variable.
 */
std::string errorMessage;

// Specialization for std::string
template<>
std::optional<std::string> extractSFunctionParameter<std::string>(SimStruct *S, int paramIndex) {
    // Check if the number of configured parameters is sufficient
    if (ssGetNumSFcnParams(S) <= paramIndex) {
        errorMessage =
                "Insufficient number of parameters set via ssSetNumSFcnParams().\n"
                "Expected at least " + std::to_string(paramIndex + 1) +
                ", but got " + std::to_string(ssGetNumSFcnParams(S));
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    // Get parameter
    const mxArray* param = ssGetSFcnParam(S, paramIndex);
    if (param == nullptr) {
        errorMessage = "Parameter at index " + std::to_string(paramIndex) + " is null (not set?)";
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    if(!mxIsChar(param)) {
        errorMessage = "Parameter at index " + std::to_string(paramIndex) + " is not a string but " + mxGetClassName(param);
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    
    // Get string length and allocate buffer
    const char* pCharArray = mxArrayToString(param);

    printf("Extracted string parameter '%s'\n", pCharArray);

    std::string result(pCharArray);
    // Free temporary buffer
    mxFree((void*)pCharArray);
    return result;
}

// Specialization for int
template<>
std::optional<int> extractSFunctionParameter<int>(SimStruct *S, int paramIndex) {
    // Check if the number of configured parameters is sufficient
    if (ssGetNumSFcnParams(S) <= paramIndex) {
        errorMessage =
                "Insufficient number of parameters set via ssSetNumSFcnParams().\n"
                "Expected at least " + std::to_string(paramIndex + 1) +
                ", but got " + std::to_string(ssGetNumSFcnParams(S));
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    const mxArray* param = ssGetSFcnParam(S, paramIndex);
    if (param == nullptr) {
        errorMessage = "Parameter at index " + std::to_string(paramIndex) + " is null (not set?)";
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    if (!mxIsNumeric(param) || mxGetNumberOfElements(param) != 1) {
        if (!mxIsNumeric(param)) {
            errorMessage = "Parameter at index " + std::to_string(paramIndex) + " is not numeric but " + mxGetClassName(param);
            ssSetErrorStatus(S, errorMessage.c_str());
            return std::nullopt;
        }
        if (mxGetNumberOfElements(param) != 1) {
            errorMessage = "Parameter at index " + std::to_string(paramIndex) + " must be a scalar (1 element) but has " + std::to_string(mxGetNumberOfElements(param));
            ssSetErrorStatus(S, errorMessage.c_str());
            return std::nullopt;
        }
    }
    return static_cast<int>(mxGetScalar(param));
}

// Specialization for double
template<>
std::optional<double> extractSFunctionParameter<double>(SimStruct *S, int paramIndex) {
    if (ssGetNumSFcnParams(S) <= paramIndex) {
        errorMessage =
                "Insufficient number of parameters set via ssSetNumSFcnParams().\n"
                "Expected at least " + std::to_string(paramIndex + 1) +
                ", but got " + std::to_string(ssGetNumSFcnParams(S));
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    const mxArray* param = ssGetSFcnParam(S, paramIndex);
    if (param == nullptr) {
        errorMessage = "Parameter at index " + std::to_string(paramIndex) + " is null (not set?)";
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    if (!mxIsNumeric(param) || mxGetNumberOfElements(param) != 1) {
        if (!mxIsNumeric(param)) {
            errorMessage = "Parameter at index " + std::to_string(paramIndex) + " is not numeric but " + mxGetClassName(param);
            ssSetErrorStatus(S, errorMessage.c_str());
            return std::nullopt;
        }
        if (mxGetNumberOfElements(param) != 1) {
            errorMessage = "Parameter at index " + std::to_string(paramIndex) + " must be a scalar (1 element) but has " + std::to_string(mxGetNumberOfElements(param));
            ssSetErrorStatus(S, errorMessage.c_str());
            return std::nullopt;
        }
    }
    return mxGetScalar(param);
}

// Specialization for bool
template<>
std::optional<bool> extractSFunctionParameter<bool>(SimStruct *S, int paramIndex) {
    if (ssGetNumSFcnParams(S) <= paramIndex) {
        errorMessage =
                "Insufficient number of parameters set via ssSetNumSFcnParams().\n"
                "Expected at least " + std::to_string(paramIndex + 1) +
                ", but got " + std::to_string(ssGetNumSFcnParams(S));
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    const mxArray* param = ssGetSFcnParam(S, paramIndex);
    if (param == nullptr) {
        errorMessage = "Parameter at index " + std::to_string(paramIndex) + " is null (not set?)";
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    if (!mxIsNumeric(param) || mxGetNumberOfElements(param) != 1) {
        if (!mxIsNumeric(param)) {
            errorMessage = "Parameter at index " + std::to_string(paramIndex) + " is not numeric but " + mxGetClassName(param);
            ssSetErrorStatus(S, errorMessage.c_str());
            return std::nullopt;
        }
        if (mxGetNumberOfElements(param) != 1) {
            errorMessage = "Parameter at index " + std::to_string(paramIndex) + " must be a scalar (1 element) but has " + std::to_string(mxGetNumberOfElements(param));
            ssSetErrorStatus(S, errorMessage.c_str());
            return std::nullopt;
        }
    }
    return static_cast<bool>(mxGetScalar(param));
}

// Specialization for std::vector<int>
template<>
std::optional<std::vector<int>> extractSFunctionParameter<std::vector<int>>(SimStruct *S, int paramIndex) {
    if (ssGetNumSFcnParams(S) <= paramIndex) {
        errorMessage =
                "Insufficient number of parameters set via ssSetNumSFcnParams().\n"
                "Expected at least " + std::to_string(paramIndex + 1) +
                ", but got " + std::to_string(ssGetNumSFcnParams(S));
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    const mxArray* param = ssGetSFcnParam(S, paramIndex);
    if (param == nullptr) {
        errorMessage = "Parameter at index " + std::to_string(paramIndex) + " is null (not set?)";
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    if (!mxIsNumeric(param)) {
        errorMessage = "Parameter at index " + std::to_string(paramIndex) + " is not a numeric array but " + mxGetClassName(param);
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
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
std::optional<std::vector<double>> extractSFunctionParameter<std::vector<double>>(SimStruct *S, int paramIndex) {
    if (ssGetNumSFcnParams(S) <= paramIndex) {
        errorMessage =
                "Insufficient number of parameters set via ssSetNumSFcnParams().\n"
                "Expected at least " + std::to_string(paramIndex + 1) +
                ", but got " + std::to_string(ssGetNumSFcnParams(S));
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    const mxArray* param = ssGetSFcnParam(S, paramIndex);
    if (param == nullptr) {
        errorMessage = "Parameter at index " + std::to_string(paramIndex) + " is null (not set?)";
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    if (!mxIsNumeric(param)) {
        errorMessage = "Parameter at index " + std::to_string(paramIndex) + " is not a numeric array but " + mxGetClassName(param);
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
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
std::optional<std::vector<std::string>> extractSFunctionParameter<std::vector<std::string>>(SimStruct *S, int paramIndex) {
    if (ssGetNumSFcnParams(S) <= paramIndex) {
        errorMessage =
                "Insufficient number of parameters set via ssSetNumSFcnParams().\n"
                "Expected at least " + std::to_string(paramIndex + 1) +
                ", but got " + std::to_string(ssGetNumSFcnParams(S));
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    const mxArray* param = ssGetSFcnParam(S, paramIndex);
    if (param == nullptr) {
        errorMessage = "Parameter at index " + std::to_string(paramIndex) + " is null (not set?)";
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    if (!mxIsCell(param)) {
        errorMessage = "Parameter at index " + std::to_string(paramIndex) + " is not a cell array but " + mxGetClassName(param);
        ssSetErrorStatus(S, errorMessage.c_str());
        return std::nullopt;
    }
    mwSize numElements = mxGetNumberOfElements(param);
    std::vector<std::string> result;
    result.reserve(numElements);
    for (mwSize i = 0; i < numElements; ++i) {
        const mxArray* cellElement = mxGetCell(param, i);
        if (cellElement == nullptr || !mxIsChar(cellElement)) {
            errorMessage = "Cell element " + std::to_string(i) + " in parameter at index " + std::to_string(paramIndex) + " is not a string";
            ssSetErrorStatus(S, errorMessage.c_str());
            return std::nullopt;
        }
        char* nameBuffer = mxArrayToString(cellElement);
        if (nameBuffer == nullptr) {
            errorMessage = "Failed to convert cell element " + std::to_string(i) + " to string in parameter at index " + std::to_string(paramIndex);
            ssSetErrorStatus(S, errorMessage.c_str());
            return std::nullopt;
        }
        result.emplace_back(nameBuffer);
        mxFree(nameBuffer);
    }
    return result;
}

