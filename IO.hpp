#pragma once

#include "simstruc.h"
#include <algorithm>
#include <vector>
#include <type_traits>

template <typename T>
void DefineScalarInputPort(SimStruct *S, int portIndex, int isDirectFeedthrough = 0)
{
    // Check we have enough input ports, and increase it if required
    if (ssGetNumInputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of input ports configured for DefineScalarInputPort, check ssSetNumInputPorts()");
        return;
    }

    // Set port width to 1 (scalar)
    ssSetInputPortWidth(S, portIndex, 1);

    // Set data type based on template parameter T
    if constexpr (std::is_same_v<T, uint8_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_UINT8);
    }
    else if constexpr (std::is_same_v<T, int8_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_INT8);
    }
    else if constexpr (std::is_same_v<T, uint16_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_UINT16);
    }
    else if constexpr (std::is_same_v<T, int16_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_INT16);
    }
    else if constexpr (std::is_same_v<T, uint32_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_UINT32);
    }
    else if constexpr (std::is_same_v<T, int32_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_INT32);
    }
    else if constexpr (std::is_same_v<T, real32_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_SINGLE);
    }
    else if constexpr (std::is_same_v<T, real_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_DOUBLE);
    }
    else if constexpr (std::is_same_v<T, boolean_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_BOOLEAN);
    }
    else
    {
        // Default to double for unknown types
        ssSetInputPortDataType(S, portIndex, SS_DOUBLE);
    }

    // Set direct feedthrough
    ssSetInputPortDirectFeedThrough(S, portIndex, isDirectFeedthrough);
}

template <typename T>
void DefineVectorInputPort(SimStruct *S, int portIndex, int width, int isDirectFeedthrough = 0)
{
    // Check we have enough input ports, and increase it if required
    if (ssGetNumInputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of input ports configured for DefineVectorInputPort, check ssSetNumInputPorts()");
        return;
    }

    // Set port width
    ssSetInputPortWidth(S, portIndex, width);

    // Set data type based on template parameter T
    if constexpr (std::is_same_v<T, uint8_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_UINT8);
    }
    else if constexpr (std::is_same_v<T, int8_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_INT8);
    }
    else if constexpr (std::is_same_v<T, uint16_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_UINT16);
    }
    else if constexpr (std::is_same_v<T, int16_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_INT16);
    }
    else if constexpr (std::is_same_v<T, uint32_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_UINT32);
    }
    else if constexpr (std::is_same_v<T, int32_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_INT32);
    }
    else if constexpr (std::is_same_v<T, real32_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_SINGLE);
    }
    else if constexpr (std::is_same_v<T, real_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_DOUBLE);
    }
    else if constexpr (std::is_same_v<T, boolean_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_BOOLEAN);
    }
    else
    {
        // Default to double for unknown types
        ssSetInputPortDataType(S, portIndex, SS_DOUBLE);
    }

    // Set direct feedthrough
    ssSetInputPortDirectFeedThrough(S, portIndex, isDirectFeedthrough);
}

template <typename T>
void Define2DMatrixInputPort(SimStruct *S, int portIndex, int rows, int cols, int isDirectFeedthrough = 0)
{
    // Check we have enough input ports (do not modify the number here)
    if (ssGetNumInputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of input ports configured for Define2DMatrixInputPort, check ssSetNumInputPorts()");
        return;
    }

    // Set port width (total number of elements)
    ssSetInputPortWidth(S, portIndex, rows * cols);

    // Set matrix dimensions
    ssSetInputPortMatrixDimensions(S, portIndex, rows, cols);

    // Set data type based on template parameter T
    if constexpr (std::is_same_v<T, uint8_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_UINT8);
    }
    else if constexpr (std::is_same_v<T, int8_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_INT8);
    }
    else if constexpr (std::is_same_v<T, uint16_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_UINT16);
    }
    else if constexpr (std::is_same_v<T, int16_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_INT16);
    }
    else if constexpr (std::is_same_v<T, uint32_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_UINT32);
    }
    else if constexpr (std::is_same_v<T, int32_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_INT32);
    }
    else if constexpr (std::is_same_v<T, real32_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_SINGLE);
    }
    else if constexpr (std::is_same_v<T, real_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_DOUBLE);
    }
    else if constexpr (std::is_same_v<T, boolean_T>)
    {
        ssSetInputPortDataType(S, portIndex, SS_BOOLEAN);
    }
    else
    {
        // Default to double for unknown types
        ssSetInputPortDataType(S, portIndex, SS_DOUBLE);
    }

    // Set direct feedthrough
    ssSetInputPortDirectFeedThrough(S, portIndex, isDirectFeedthrough);
}

template <typename T>
void DefineScalarOutputPort(SimStruct *S, int portIndex)
{
    // Check we have enough output ports (do not modify the number here)
    if (ssGetNumOutputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for DefineScalarOutputPort, check ssSetNumOutputPorts()");
        return;
    }

    // Set port width to 1 (scalar)
    ssSetOutputPortWidth(S, portIndex, 1);

    // Set data type based on template parameter T
    if constexpr (std::is_same_v<T, uint8_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_UINT8);
    }
    else if constexpr (std::is_same_v<T, int8_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_INT8);
    }
    else if constexpr (std::is_same_v<T, uint16_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_UINT16);
    }
    else if constexpr (std::is_same_v<T, int16_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_INT16);
    }
    else if constexpr (std::is_same_v<T, uint32_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_UINT32);
    }
    else if constexpr (std::is_same_v<T, int32_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_INT32);
    }
    else if constexpr (std::is_same_v<T, real32_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_SINGLE);
    }
    else if constexpr (std::is_same_v<T, real_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_DOUBLE);
    }
    else if constexpr (std::is_same_v<T, boolean_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_BOOLEAN);
    }
    else
    {
        // Default to double for unknown types
        ssSetOutputPortDataType(S, portIndex, SS_DOUBLE);
    }
}

template <typename T>
void DefineVectorOutputPort(SimStruct *S, int portIndex, int width)
{
    // Check we have enough output ports (do not modify the number here)
    if (ssGetNumOutputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for DefineVectorOutputPort, check ssSetNumOutputPorts()");
        return;
    }

    // Set port width
    ssSetOutputPortWidth(S, portIndex, width);

    // Set data type based on template parameter T
    if constexpr (std::is_same_v<T, uint8_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_UINT8);
    }
    else if constexpr (std::is_same_v<T, int8_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_INT8);
    }
    else if constexpr (std::is_same_v<T, uint16_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_UINT16);
    }
    else if constexpr (std::is_same_v<T, int16_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_INT16);
    }
    else if constexpr (std::is_same_v<T, uint32_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_UINT32);
    }
    else if constexpr (std::is_same_v<T, int32_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_INT32);
    }
    else if constexpr (std::is_same_v<T, real32_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_SINGLE);
    }
    else if constexpr (std::is_same_v<T, real_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_DOUBLE);
    }
    else if constexpr (std::is_same_v<T, boolean_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_BOOLEAN);
    }
    else
    {
        // Default to double for unknown types
        ssSetOutputPortDataType(S, portIndex, SS_DOUBLE);
    }
}

template <typename T>
void Define2DMatrixOutputPort(SimStruct *S, int portIndex, int rows, int cols)
{
    // Check we have enough output ports (do not modify the number here)
    if (ssGetNumOutputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for Define2DMatrixOutputPort, check ssSetNumOutputPorts()");
        return;
    }

    // Set port width (total number of elements)
    ssSetOutputPortWidth(S, portIndex, rows * cols);

    // Set matrix dimensions
    ssSetOutputPortMatrixDimensions(S, portIndex, rows, cols);

    // Set data type based on template parameter T
    if constexpr (std::is_same_v<T, uint8_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_UINT8);
    }
    else if constexpr (std::is_same_v<T, int8_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_INT8);
    }
    else if constexpr (std::is_same_v<T, uint16_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_UINT16);
    }
    else if constexpr (std::is_same_v<T, int16_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_INT16);
    }
    else if constexpr (std::is_same_v<T, uint32_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_UINT32);
    }
    else if constexpr (std::is_same_v<T, int32_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_INT32);
    }
    else if constexpr (std::is_same_v<T, real32_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_SINGLE);
    }
    else if constexpr (std::is_same_v<T, real_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_DOUBLE);
    }
    else if constexpr (std::is_same_v<T, boolean_T>)
    {
        ssSetOutputPortDataType(S, portIndex, SS_BOOLEAN);
    }
    else
    {
        // Default to double for unknown types
        ssSetOutputPortDataType(S, portIndex, SS_DOUBLE);
    }
}

template <typename T>
void SetScalarOutputPort(SimStruct *S, int portIndex, T value)
{
    // Check we have enough output ports
    if (ssGetNumOutputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for SetScalarOutputPort");
        return;
    }

    T* outputSignal = (T*)ssGetOutputPortSignal(S, portIndex);
    // Check if outputSignal is valid
    if (!outputSignal)
    {
        ssWarning(S, ("Failed to get output port signal for port index " + std::to_string(portIndex)).c_str());
        return;
    }

    // Set the output port value
    *outputSignal = value;
}

template <typename T>
void SetVectorOutputPort(SimStruct *S, int portIndex, const std::vector<T> &values)
{
    // Check we have enough output ports
    if (ssGetNumOutputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for SetVectorOutputPort");
        return;
    }

    // Check if the output port width matches the expected width
    if (ssGetOutputPortWidth(S, portIndex) != values.size())
    {
        ssSetErrorStatus(S, "Output port width does not match expected width");
        return;
    }

    T* outputSignal = (T*)ssGetOutputPortSignal(S, portIndex);
    // Check if outputSignal is valid
    if (!outputSignal)
    {
        ssWarning(S, ("Failed to get output port signal for port index " + std::to_string(portIndex)).c_str());
        return;
    }

    // Set the output port values
    std::copy(values.begin(), values.end(), outputSignal);
}

template <typename T>
void SetVectorOutputPort(SimStruct *S, int portIndex, T *values, size_t size)
{
    // Check we have enough output ports
    if (ssGetNumOutputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for SetVectorOutputPort");
        return;
    }

    // Check if the output port width matches the expected width
    if (ssGetOutputPortWidth(S, portIndex) != size)
    {
        ssSetErrorStatus(S, "Output port width does not match expected width");
        return;
    }

    T* outputSignal = (T*)ssGetOutputPortSignal(S, portIndex);
    // Check if outputSignal is valid
    if (!outputSignal)
    {
        ssWarning(S, ("Failed to get output port signal for port index " + std::to_string(portIndex)).c_str());
        return;
    }

    // Set the output port values
    std::copy(values, values + size, outputSignal);
}

template <typename T, size_t W>
void SetVectorOutputPort(SimStruct *S, int portIndex, T (&values)[W])
{
    // Check we have enough output ports
    if (ssGetNumOutputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for SetVectorOutputPort");
        return;
    }

    // Check if the output port width matches the expected width
    if (ssGetOutputPortWidth(S, portIndex) != W)
    {
        ssSetErrorStatus(S, "Output port width does not match expected width");
        return;
    }

    T* outputSignal = (T*)ssGetOutputPortSignal(S, portIndex);
    // Check if outputSignal is valid
    if (!outputSignal)
    {
        ssWarning(S, ("Failed to get output port signal for port index " + std::to_string(portIndex)).c_str());
        return;
    }

    // Set the output port values
    std::copy(values, values + W, outputSignal);
}

template <typename T, size_t W>
void SetVectorOutputPort(SimStruct *S, int portIndex, std::array<T, W> values)
{
    // Check we have enough output ports
    if (ssGetNumOutputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for SetVectorOutputPort");
        return;
    }

    // Check if the output port width matches the expected width
    if (ssGetOutputPortWidth(S, portIndex) != W)
    {
        ssSetErrorStatus(S, "Output port width does not match expected width");
        return;
    }

    T* outputSignal = (T*)ssGetOutputPortSignal(S, portIndex);
    // Check if outputSignal is valid
    if (!outputSignal)
    {
        ssWarning(S, ("Failed to get output port signal for port index " + std::to_string(portIndex)).c_str());
        return;
    }

    // Set the output port values
    std::copy(values.begin(), values.end(), outputSignal);
}

template <typename T>
void Set2DMatrixOutputPort(SimStruct *S, int portIndex, std::vector<std::vector<T>> &values)
{
    // Check we have enough output ports
    if (ssGetNumOutputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for Set2DMatrixOutputPort");
        return;
    }

    if (ssGetOutputPortWidth(S, portIndex) != values[0].size() * values.size())
    {
        ssSetErrorStatus(S, "Output port width does not match expected width");
        return;
    }

    T* outputSignal = (T*)ssGetOutputPortSignal(S, portIndex);
    // Check if outputSignal is valid
    if (!outputSignal)
    {
        ssWarning(S, ("Failed to get output port signal for port index " + std::to_string(portIndex)).c_str());
        return;
    }

    // Set the output port values
    for (size_t i = 0; i < values.size(); ++i)
    {
        std::copy(values[i].begin(), values[i].end(), outputSignal + i * values[i].size());
    }
}

template <typename T>
void Set2DMatrixOutputPort(SimStruct *S, int portIndex, T **values, size_t rows, size_t cols)
{
    // Check we have enough output ports
    if (ssGetNumOutputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for Set2DMatrixOutputPort");
        return;
    }

    if (ssGetOutputPortWidth(S, portIndex) != cols * rows)
    {
        ssSetErrorStatus(S, "Output port width does not match expected width");
        return;
    }

    T* outputSignal = (T*)ssGetOutputPortSignal(S, portIndex);
    // Check if outputSignal is valid
    if (!outputSignal)
    {
        ssWarning(S, ("Failed to get output port signal for port index " + std::to_string(portIndex)).c_str());
        return;
    }

    // Set the output port values
    for (size_t i = 0; i < rows; ++i)
    {
        std::copy(values[i], values[i] + cols, outputSignal + i * cols);
    }
}

template <typename T, size_t W, size_t H>
void Set2DMatrixOutputPort(SimStruct *S, int portIndex, T (&values)[W][H])
{
    // Check we have enough output ports
    if (ssGetNumOutputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for Set2DMatrixOutputPort");
        return;
    }

    if (ssGetOutputPortWidth(S, portIndex) != W * H)
    {
        ssSetErrorStatus(S, "Output port width does not match expected width");
        return;
    }

    T* outputSignal = (T*)ssGetOutputPortSignal(S, portIndex);
    // Check if outputSignal is valid
    if (!outputSignal)
    {
        ssWarning(S, ("Failed to get output port signal for port index " + std::to_string(portIndex)).c_str());
        return;
    }

    // Set the output port values
    for (size_t i = 0; i < H; ++i)
    {
        std::copy(values[i], values[i] + W, outputSignal + i * W);
    }
}

template <typename T, size_t W, size_t H>
void Set2DMatrixOutputPort(SimStruct *S, int portIndex, std::array<std::array<T, W>, H> values)
{
    // Check we have enough output ports
    if (ssGetNumOutputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for Set2DMatrixOutputPort");
        return;
    }

    if (ssGetOutputPortWidth(S, portIndex) != W * H)
    {
        ssSetErrorStatus(S, "Output port width does not match expected width");
        return;
    }

    T* outputSignal = (T*)ssGetOutputPortSignal(S, portIndex);
    // Check if outputSignal is valid
    if (!outputSignal)
    {
        ssWarning(S, ("Failed to get output port signal for port index " + std::to_string(portIndex)).c_str());
        return;
    }

    // Set the output port values
    for (size_t i = 0; i < H; ++i)
    {
        std::copy(values[i].begin(), values[i].end(), outputSignal + i * W);
    }
}

template <typename T>
std::optional<T> GetScalarInputPort(SimStruct *S, int portIndex)
{
    // Check we have enough input ports
    if (ssGetNumInputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of input ports configured for GetScalarInputPort");
        return std::nullopt;
    }

    T* inputSignal = (T*)ssGetInputPortSignal(S, portIndex);
    // Check if inputSignal is valid
    if (!inputSignal)
    {
        ssWarning(S, ("Failed to get input port signal for port index " + std::to_string(portIndex)).c_str());
        return std::nullopt;
    }

    // Get the input port value
    return *inputSignal;
}

template <typename T>
std::optional<std::vector<T>> GetVectorInputPort(SimStruct *S, int portIndex, size_t width)
{
    // Check we have enough input ports
    if (ssGetNumInputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of input ports configured for GetVectorInputPort");
        return std::nullopt;
    }

    // Get the input port signal
    T *inputSignal = (T *)ssGetInputPortSignal(S, portIndex);
    if (!inputSignal)
    {
        ssWarning(S, ("Failed to get input port signal for port index " + std::to_string(portIndex)).c_str());
        return std::nullopt;
    }

    // Check if the input port width matches the expected width
    if (ssGetInputPortWidth(S, portIndex) != width)
    {
        ssSetErrorStatus(S, "Input port width does not match expected width");
        return std::nullopt;
    }

    // Get the input port values
    std::vector<T> values;
    for (size_t i = 0; i < width; ++i)
    {
        values.push_back(inputSignal[i]);
    }
    return values;
}

template <typename T, size_t W>
std::optional<std::array<T, W>> GetVectorInputPort(SimStruct *S, int portIndex)
{
    // Check we have enough input ports
    if (ssGetNumInputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of input ports configured for GetVectorInputPort");
        return std::nullopt;
    }

    // Get the input port signal
    T *inputSignal = (T *)ssGetInputPortSignal(S, portIndex);
    if (!inputSignal)
    {
        ssWarning(S, ("Failed to get input port signal for port index " + std::to_string(portIndex)).c_str());
        return std::nullopt;
    }

    // Check if the input port width matches the expected width
    if (ssGetInputPortWidth(S, portIndex) != W)
    {
        ssSetErrorStatus(S, "Input port width does not match expected width");
        return std::nullopt;
    }

    // Get the input port values
    std::array<T, W> values;
    for (size_t i = 0; i < W; ++i)
    {
        values[i] = inputSignal[i];
    }
    return values;
}

template <typename T, size_t W>
bool GetVectorInputPort(SimStruct *S, int portIndex, T (&output)[W])
{
    // Check we have enough input ports
    if (ssGetNumInputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of input ports configured for GetVectorInputPort");
        return false;
    }

    // Get the input port signal
    T *inputSignal = (T *)ssGetInputPortSignal(S, portIndex);
    if (!inputSignal)
    {
        ssWarning(S, ("Failed to get input port signal for port index " + std::to_string(portIndex)).c_str());
        return false;
    }

    // Check if the input port width matches the expected width
    if (ssGetInputPortWidth(S, portIndex) != W)
    {
        ssSetErrorStatus(S, "Input port width does not match expected width");
        return false;
    }

    // Get the input port values
    for (size_t i = 0; i < W; ++i)
    {
        output[i] = inputSignal[i];
    }

    return true;
}

template <typename T>
std::optional<std::vector<std::vector<T>>> Get2DMatrixInputPort(SimStruct *S, int portIndex, size_t width, size_t height)
{
    // Check we have enough input ports
    if (ssGetNumInputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of input ports configured for Get2DMatrixInputPort");
        return std::nullopt;
    }

    // Get the input port signal
    T *inputSignal = (T *)ssGetInputPortSignal(S, portIndex);
    if (!inputSignal)
    {
        ssWarning(S, ("Failed to get input port signal for port index " + std::to_string(portIndex)).c_str());
        return std::nullopt;
    }

    // Check if the input port width matches the expected width
    if (ssGetInputPortWidth(S, portIndex) != width * height)
    {
        ssSetErrorStatus(S, "Input port width does not match expected width");
        return std::nullopt;
    }

    // Get the input port values
    std::vector<std::vector<T>> values;
    for (size_t i = 0; i < width; ++i)
    {
        std::vector<T> row;
        for (size_t j = 0; j < height; ++j)
        {
            row.push_back(inputSignal[i * height + j]);
        }
        values.push_back(row);
    }
    return values;
}

template <typename T, size_t W, size_t H>
std::optional<std::array<std::array<T, H>, W>> Get2DMatrixInputPort(SimStruct *S, int portIndex)
{
    // Check we have enough input ports
    if (ssGetNumInputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of input ports configured for Get2DMatrixInputPort");
        return std::nullopt;
    }

    // Get the input port signal
    T *inputSignal = (T *)ssGetInputPortSignal(S, portIndex);
    if (!inputSignal)
    {
        ssWarning(S, ("Failed to get input port signal for port index " + std::to_string(portIndex)).c_str());
        return std::nullopt;
    }

    // Check if the input port width matches the expected width
    if (ssGetInputPortWidth(S, portIndex) != W * H)
    {
        ssSetErrorStatus(S, "Input port width does not match expected width");
        return std::nullopt;
    }

    // Get the input port values
    std::array<std::array<T, H>, W> values;
    for (size_t i = 0; i < W; ++i)
    {
        for (size_t j = 0; j < H; ++j)
        {
            values[i][j] = inputSignal[i * H + j];
        }
    }
    return values;
}

template <typename T, size_t W, size_t H>
bool Get2DMatrixInputPort(SimStruct *S, int portIndex, T (&output)[W][H])
{
    // Check we have enough input ports
    if (ssGetNumInputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of input ports configured for Get2DMatrixInputPort");
        return false;
    }

    // Get the input port signal
    T *inputSignal = (T *)ssGetInputPortSignal(S, portIndex);
    if (!inputSignal)
    {
        ssWarning(S, ("Failed to get input port signal for port index " + std::to_string(portIndex)).c_str());
        return false;
    }

    // Check if the input port width matches the expected width
    if (ssGetInputPortWidth(S, portIndex) != W * H)
    {
        ssSetErrorStatus(S, "Input port width does not match expected width");
        return false;
    }

    // Get the input port values
    for (size_t i = 0; i < W; ++i)
    {
        for (size_t j = 0; j < H; ++j)
        {
            output[i][j] = inputSignal[i * H + j];
        }
    }

    return true;
}