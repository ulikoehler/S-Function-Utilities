#pragma once
#include <string>
#include <vector>
#include <optional>
#include "simstruc.h"

static inline bool isRTWOrSizesOnlyCall(SimStruct *S)
{
#if defined(MATLAB_MEX_FILE)
    return ssRTWGenIsCodeGen(S) || (ssGetSimMode(S) == SS_SIMMODE_SIZES_CALL_ONLY);
#else
    // In generated code, these branches aren't relevant; return false.
    return false;
#endif
}

// Returns std::nullopt on any error instead of a caller-provided default.
template <typename T>
bool writeSFunctionParameterToRTW(SimStruct *S, std::string paramName, T value);

template <>
bool writeSFunctionParameterToRTW<std::string>(SimStruct *S, std::string paramName, std::string value){
    if (!ssWriteRTWStrParam(S, paramName.c_str(), value.c_str()))
    {
        ssSetErrorStatus(S, ("Failed to write RTW parameter '" + paramName + "'").c_str());
        return false;
    }
    return true;
}

template <>
bool writeSFunctionParameterToRTW<int>(SimStruct *S, std::string paramName, int value){
    if (!ssWriteRTWScalarParam(S, paramName.c_str(), &value, SS_INT32))
    {
        ssSetErrorStatus(S, ("Failed to write RTW parameter '" + paramName + "'").c_str());
        return false;
    }
    return true;
}

template <>
bool writeSFunctionParameterToRTW<double>(SimStruct *S, std::string paramName, double value){
    if (!ssWriteRTWScalarParam(S, paramName.c_str(), &value, SS_DOUBLE))
    {
        ssSetErrorStatus(S, ("Failed to write RTW parameter '" + paramName + "'").c_str());
        return false;
    }
    return true;
}

template <>
bool writeSFunctionParameterToRTW<bool>(SimStruct *S, std::string paramName, bool value){
    if (!ssWriteRTWScalarParam(S, paramName.c_str(), &value, SS_BOOLEAN))
    {
        ssSetErrorStatus(S, ("Failed to write RTW parameter '" + paramName + "'").c_str());
        return false;
    }
    return true;
}

template <>
bool writeSFunctionParameterToRTW<std::vector<std::string>>(SimStruct *S, std::string paramName, std::vector<std::string> value){
    int c_size = 0;
    for (const auto &str : value) {
        c_size += str.size() + 1; // +1 for null terminator
    }

    char *data = new char[c_size];

    int offset = 0;
    for (const auto &str : value) {
        std::strcpy(data+offset, str.c_str());
        offset += str.size() + 1; // Move pointer forward
    }

    if (!ssWriteRTWStrVectParam(S, paramName.c_str(), data, value.size()))
    {
        ssSetErrorStatus(S, ("Failed to write RTW parameter '" + paramName + "'").c_str());
        delete[] data;
        return false;
    }
    delete[] data;
    return true;
}

template <>
bool writeSFunctionParameterToRTW<std::vector<int>>(SimStruct *S, std::string paramName, std::vector<int> value){
    int *data = new int[value.size()];
    std::copy(value.begin(), value.end(), data);
    if (!ssWriteRTWVectParam(S, paramName.c_str(), data, SS_INT32, value.size()))
    {
        ssSetErrorStatus(S, ("Failed to write RTW parameter '" + paramName + "'").c_str());
        delete[] data;
        return false;
    }
    delete[] data;
    return true;
}

template <>
bool writeSFunctionParameterToRTW<std::vector<double>>(SimStruct *S, std::string paramName, std::vector<double> value){
    double *data = new double[value.size()];
    std::copy(value.begin(), value.end(), data);
    if (!ssWriteRTWVectParam(S, paramName.c_str(), data, SS_DOUBLE, value.size()))
    {
        ssSetErrorStatus(S, ("Failed to write RTW parameter '" + paramName + "'").c_str());
        delete[] data;
        return false;
    }
    delete[] data;
    return true;
}

template <>
bool writeSFunctionParameterToRTW<std::vector<bool>>(SimStruct *S, std::string paramName, std::vector<bool> value){
    bool *data = new bool[value.size()];
    std::copy(value.begin(), value.end(), data);
    if (!ssWriteRTWVectParam(S, paramName.c_str(), data, SS_BOOLEAN, value.size()))
    {
        ssSetErrorStatus(S, ("Failed to write RTW parameter '" + paramName + "'").c_str());
        delete[] data;
        return false;
    }
    delete[] data;
    return true;
}

// bool writeSFunctionMaskTableToRTW(SimStruct *S, std::string paramName, std::vector<std::vector<std::string>> value) // TODO