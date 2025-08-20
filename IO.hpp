#pragma once

#include "simstruc.h"
#include <algorithm>
#include <type_traits>

template<typename T>
void DefineScalarInputPort(SimStruct* S, int portIndex, int isDirectFeedthrough = 0) {
    // Check we have enough input ports, and increase it if required
    if (ssGetNumInputPorts(S) <= portIndex) {
        ssSetErrorStatus(S, "Insufficient number of input ports configured for DefineScalarInputPort, check ssSetNumInputPorts()");
        return;
    }
    
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
void DefineVectorInputPort(SimStruct* S, int portIndex, int width, int isDirectFeedthrough = 0) {
    // Check we have enough input ports, and increase it if required
    if (ssGetNumInputPorts(S) <= portIndex) {
        ssSetErrorStatus(S, "Insufficient number of input ports configured for DefineVectorInputPort, check ssSetNumInputPorts()");
        return;
    }
    
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
void Define2DMatrixInputPort(SimStruct* S, int portIndex, int rows, int cols, int isDirectFeedthrough = 0) {
    // Check we have enough input ports (do not modify the number here)
    if (ssGetNumInputPorts(S) <= portIndex) {
        ssSetErrorStatus(S, "Insufficient number of input ports configured for Define2DMatrixInputPort, check ssSetNumInputPorts()");
        return;
    }
    
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
    // Check we have enough output ports (do not modify the number here)
    if (ssGetNumOutputPorts(S) <= portIndex) {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for DefineScalarOutputPort, check ssSetNumOutputPorts()");
        return;
    }

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
    // Check we have enough output ports (do not modify the number here)
    if (ssGetNumOutputPorts(S) <= portIndex) {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for DefineVectorOutputPort, check ssSetNumOutputPorts()");
        return;
    }

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
    // Check we have enough output ports (do not modify the number here)
    if (ssGetNumOutputPorts(S) <= portIndex) {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for Define2DMatrixOutputPort, check ssSetNumOutputPorts()");
        return;
    }

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
