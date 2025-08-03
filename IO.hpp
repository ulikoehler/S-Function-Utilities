#pragma once

#include "simstruc.h"
#include <algorithm>
#include <type_traits>

template<typename T>
void DefineScalarInputPort(SimStruct* S, int portIndex, int isDirectFeedthrough = 1) {
    // Ensure we have enough input ports
    int currentNumPorts = ssGetNumInputPorts(S);
    int requiredPorts = std::max(currentNumPorts, portIndex + 1);
    ssSetNumInputPorts(S, requiredPorts);
    
    // Set port width to 1 (scalar)
    ssSetInputPortWidth(S, portIndex, 1);
    
    // Set data type based on template parameter T
    if constexpr (std::is_same_v<T, uint8_T>) {
        ssSetInputPortDataType(S, portIndex, SS_UINT8);
    } else if constexpr (std::is_same_v<T, int8_T>) {
        ssSetInputPortDataType(S, portIndex, SS_INT8);
    } else if constexpr (std::is_same_v<T, uint16_T>) {
        ssSetInputPortDataType(S, portIndex, SS_UINT16);
    } else if constexpr (std::is_same_v<T, int16_T>) {
        ssSetInputPortDataType(S, portIndex, SS_INT16);
    } else if constexpr (std::is_same_v<T, uint32_T>) {
        ssSetInputPortDataType(S, portIndex, SS_UINT32);
    } else if constexpr (std::is_same_v<T, int32_T>) {
        ssSetInputPortDataType(S, portIndex, SS_INT32);
    } else if constexpr (std::is_same_v<T, real32_T>) {
        ssSetInputPortDataType(S, portIndex, SS_SINGLE);
    } else if constexpr (std::is_same_v<T, real_T>) {
        ssSetInputPortDataType(S, portIndex, SS_DOUBLE);
    } else if constexpr (std::is_same_v<T, boolean_T>) {
        ssSetInputPortDataType(S, portIndex, SS_BOOLEAN);
    } else {
        // Default to double for unknown types
        ssSetInputPortDataType(S, portIndex, SS_DOUBLE);
    }
    
    // Set direct feedthrough
    ssSetInputPortDirectFeedThrough(S, portIndex, isDirectFeedthrough);
}

template<typename T>
void DefineVectorInputPort(SimStruct* S, int portIndex, int width, int isDirectFeedthrough = 1) {
    // Ensure we have enough input ports
    int currentNumPorts = ssGetNumInputPorts(S);
    int requiredPorts = std::max(currentNumPorts, portIndex + 1);
    ssSetNumInputPorts(S, requiredPorts);
    
    // Set port width
    ssSetInputPortWidth(S, portIndex, width);
    
    // Set data type based on template parameter T
    if constexpr (std::is_same_v<T, uint8_T>) {
        ssSetInputPortDataType(S, portIndex, SS_UINT8);
    } else if constexpr (std::is_same_v<T, int8_T>) {
        ssSetInputPortDataType(S, portIndex, SS_INT8);
    } else if constexpr (std::is_same_v<T, uint16_T>) {
        ssSetInputPortDataType(S, portIndex, SS_UINT16);
    } else if constexpr (std::is_same_v<T, int16_T>) {
        ssSetInputPortDataType(S, portIndex, SS_INT16);
    } else if constexpr (std::is_same_v<T, uint32_T>) {
        ssSetInputPortDataType(S, portIndex, SS_UINT32);
    } else if constexpr (std::is_same_v<T, int32_T>) {
        ssSetInputPortDataType(S, portIndex, SS_INT32);
    } else if constexpr (std::is_same_v<T, real32_T>) {
        ssSetInputPortDataType(S, portIndex, SS_SINGLE);
    } else if constexpr (std::is_same_v<T, real_T>) {
        ssSetInputPortDataType(S, portIndex, SS_DOUBLE);
    } else if constexpr (std::is_same_v<T, boolean_T>) {
        ssSetInputPortDataType(S, portIndex, SS_BOOLEAN);
    } else {
        // Default to double for unknown types
        ssSetInputPortDataType(S, portIndex, SS_DOUBLE);
    }
    
    // Set direct feedthrough
    ssSetInputPortDirectFeedThrough(S, portIndex, isDirectFeedthrough);
}


template<typename T>
void Define2DMatrixInputPort(SimStruct* S, int portIndex, int rows, int cols, int isDirectFeedthrough = 1) {
    // Ensure we have enough input ports
    int currentNumPorts = ssGetNumInputPorts(S);
    int requiredPorts = std::max(currentNumPorts, portIndex + 1);
    ssSetNumInputPorts(S, requiredPorts);
    
    // Set port width (total number of elements)
    ssSetInputPortWidth(S, portIndex, rows * cols);
    
    // Set matrix dimensions
    ssSetInputPortMatrixDimensions(S, portIndex, rows, cols);
    
    // Set data type based on template parameter T
    if constexpr (std::is_same_v<T, uint8_T>) {
        ssSetInputPortDataType(S, portIndex, SS_UINT8);
    } else if constexpr (std::is_same_v<T, int8_T>) {
        ssSetInputPortDataType(S, portIndex, SS_INT8);
    } else if constexpr (std::is_same_v<T, uint16_T>) {
        ssSetInputPortDataType(S, portIndex, SS_UINT16);
    } else if constexpr (std::is_same_v<T, int16_T>) {
        ssSetInputPortDataType(S, portIndex, SS_INT16);
    } else if constexpr (std::is_same_v<T, uint32_T>) {
        ssSetInputPortDataType(S, portIndex, SS_UINT32);
    } else if constexpr (std::is_same_v<T, int32_T>) {
        ssSetInputPortDataType(S, portIndex, SS_INT32);
    } else if constexpr (std::is_same_v<T, real32_T>) {
        ssSetInputPortDataType(S, portIndex, SS_SINGLE);
    } else if constexpr (std::is_same_v<T, real_T>) {
        ssSetInputPortDataType(S, portIndex, SS_DOUBLE);
    } else if constexpr (std::is_same_v<T, boolean_T>) {
        ssSetInputPortDataType(S, portIndex, SS_BOOLEAN);
    } else {
        // Default to double for unknown types
        ssSetInputPortDataType(S, portIndex, SS_DOUBLE);
    }
    
    // Set direct feedthrough
    ssSetInputPortDirectFeedThrough(S, portIndex, isDirectFeedthrough);
}

template<typename T>
void DefineScalarOutputPort(SimStruct* S, int portIndex) {
    // Ensure we have enough output ports
    int currentNumPorts = ssGetNumOutputPorts(S);
    int requiredPorts = std::max(currentNumPorts, portIndex + 1);
    ssSetNumOutputPorts(S, requiredPorts);
    
    // Set port width to 1 (scalar)
    ssSetOutputPortWidth(S, portIndex, 1);
    
    // Set data type based on template parameter T
    if constexpr (std::is_same_v<T, uint8_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_UINT8);
    } else if constexpr (std::is_same_v<T, int8_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_INT8);
    } else if constexpr (std::is_same_v<T, uint16_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_UINT16);
    } else if constexpr (std::is_same_v<T, int16_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_INT16);
    } else if constexpr (std::is_same_v<T, uint32_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_UINT32);
    } else if constexpr (std::is_same_v<T, int32_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_INT32);
    } else if constexpr (std::is_same_v<T, real32_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_SINGLE);
    } else if constexpr (std::is_same_v<T, real_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_DOUBLE);
    } else if constexpr (std::is_same_v<T, boolean_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_BOOLEAN);
    } else {
        // Default to double for unknown types
        ssSetOutputPortDataType(S, portIndex, SS_DOUBLE);
    }
}

template<typename T>
void DefineVectorOutputPort(SimStruct* S, int portIndex, int width) {
    // Ensure we have enough output ports
    int currentNumPorts = ssGetNumOutputPorts(S);
    int requiredPorts = std::max(currentNumPorts, portIndex + 1);
    ssSetNumOutputPorts(S, requiredPorts);
    
    // Set port width
    ssSetOutputPortWidth(S, portIndex, width);
    
    // Set data type based on template parameter T
    if constexpr (std::is_same_v<T, uint8_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_UINT8);
    } else if constexpr (std::is_same_v<T, int8_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_INT8);
    } else if constexpr (std::is_same_v<T, uint16_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_UINT16);
    } else if constexpr (std::is_same_v<T, int16_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_INT16);
    } else if constexpr (std::is_same_v<T, uint32_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_UINT32);
    } else if constexpr (std::is_same_v<T, int32_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_INT32);
    } else if constexpr (std::is_same_v<T, real32_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_SINGLE);
    } else if constexpr (std::is_same_v<T, real_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_DOUBLE);
    } else if constexpr (std::is_same_v<T, boolean_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_BOOLEAN);
    } else {
        // Default to double for unknown types
        ssSetOutputPortDataType(S, portIndex, SS_DOUBLE);
    }
}

template<typename T>
void Define2DMatrixOutputPort(SimStruct* S, int portIndex, int rows, int cols) {
    // Ensure we have enough output ports
    int currentNumPorts = ssGetNumOutputPorts(S);
    int requiredPorts = std::max(currentNumPorts, portIndex + 1);
    ssSetNumOutputPorts(S, requiredPorts);
    
    // Set port width (total number of elements)
    ssSetOutputPortWidth(S, portIndex, rows * cols);
    
    // Set matrix dimensions
    ssSetOutputPortMatrixDimensions(S, portIndex, rows, cols);
    
    // Set data type based on template parameter T
    if constexpr (std::is_same_v<T, uint8_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_UINT8);
    } else if constexpr (std::is_same_v<T, int8_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_INT8);
    } else if constexpr (std::is_same_v<T, uint16_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_UINT16);
    } else if constexpr (std::is_same_v<T, int16_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_INT16);
    } else if constexpr (std::is_same_v<T, uint32_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_UINT32);
    } else if constexpr (std::is_same_v<T, int32_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_INT32);
    } else if constexpr (std::is_same_v<T, real32_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_SINGLE);
    } else if constexpr (std::is_same_v<T, real_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_DOUBLE);
    } else if constexpr (std::is_same_v<T, boolean_T>) {
        ssSetOutputPortDataType(S, portIndex, SS_BOOLEAN);
    } else {
        // Default to double for unknown types
        ssSetOutputPortDataType(S, portIndex, SS_DOUBLE);
    }
}
