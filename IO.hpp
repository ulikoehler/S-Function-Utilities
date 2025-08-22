#pragma once

#include "simstruc.h"
#include <algorithm>
#include <vector>
#include <type_traits>

/**
 * MATLAB requires error messages to be in persistent memory.
 * Since logically, only one error message can be active at any one time,
 * we store it in this variable.
 */
std::string errorMessageIO;

template <typename T>
void DefineInputPort(SimStruct *S, int portIndex, int rows = 1, int cols = 1, int isDirectFeedthrough = 0)
{
    // Check we have enough input ports (do not modify the number here)
    if (ssGetNumInputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of input ports configured for DefineInputPort, check ssSetNumInputPorts()");
        return;
    }

    // Set port width (total number of elements)
    ssSetInputPortWidth(S, portIndex, rows * cols);

    // Set matrix dimensions
    if (cols > 1)
        ssSetInputPortMatrixDimensions(S, portIndex, rows, cols);
    // DECL_AND_INIT_DIMSINFO(di);
    // if (cols > 1)
    // {
    //     int_T dims[2];
    //     di.numDims = 2;
    //     dims[0] = rows;
    //     dims[1] = cols;
    //     di.dims = dims;
    //     di.width = rows * cols;
    // }
    // else
    // {
    //     int_T dims[1];
    //     di.numDims = 1;
    //     dims[0] = rows;
    //     di.dims = dims;
    //     di.width = rows;
    // }
    // ssSetInputPortDimensionInfo(S, 0, &di);

    // Set data type based on template parameter T
    if constexpr (std::is_same_v<T, uint8_T> || std::is_same_v<T, char_T>)
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
    ssSetInputPortRequiredContiguous(S, portIndex, 1);
}

template <typename T>
inline void DefineScalarInputPort(SimStruct *S, int portIndex, int isDirectFeedthrough = 0)
{
    DefineInputPort<T>(S, portIndex, 1, 1, isDirectFeedthrough);
}

template <typename T>
inline void DefineVectorInputPort(SimStruct *S, int portIndex, int width, int isDirectFeedthrough = 0)
{
    DefineInputPort<T>(S, portIndex, width, 1, isDirectFeedthrough);
}

template <typename T>
inline void Define2DMatrixInputPort(SimStruct *S, int portIndex, int rows, int cols, int isDirectFeedthrough = 0)
{
    DefineInputPort<T>(S, portIndex, rows, cols, isDirectFeedthrough);
}

template <typename T>
void DefineOutputPort(SimStruct *S, int portIndex, int rows = 1, int cols = 1)
{
    // Check we have enough output ports (do not modify the number here)
    if (ssGetNumOutputPorts(S) <= portIndex)
    {
        ssSetErrorStatus(S, "Insufficient number of output ports configured for DefineOutputPort, check ssSetNumOutputPorts()");
        return;
    }

    // // Set port width (total number of elements)
    ssSetOutputPortWidth(S, portIndex, rows * cols);

    // fprintf(stderr, "Output port width %d does not match expected width %d for Port %d\n",
    //         ssGetOutputPortWidth(S, portIndex), rows * cols, portIndex);
    // Set matrix dimensions
    if (cols > 1)
        ssSetOutputPortMatrixDimensions(S, portIndex, rows, cols);
    // DECL_AND_INIT_DIMSINFO(di);
    // if (cols > 1)
    // {
    //     int_T dims[2];
    //     di.numDims = 2;
    //     dims[0] = rows;
    //     dims[1] = cols;
    //     di.dims = dims;
    //     di.width = rows * cols;
    // }
    // else
    // {
    //     int_T dims[1];
    //     di.numDims = 1;
    //     dims[0] = rows;
    //     di.dims = dims;
    //     di.width = rows;
    // }
    // ssSetOutputPortDimensionInfo(S, 0, &di);

    // Set data type based on template parameter T
    if constexpr (std::is_same_v<T, uint8_T> || std::is_same_v<T, char_T>)
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
inline void DefineScalarOutputPort(SimStruct *S, int portIndex)
{
    DefineOutputPort<T>(S, portIndex, 1, 1);
}

template <typename T>
inline void DefineVectorOutputPort(SimStruct *S, int portIndex, int width)
{
    DefineOutputPort<T>(S, portIndex, width, 1);
}

template <typename T>
inline void Define2DMatrixOutputPort(SimStruct *S, int portIndex, int rows, int cols)
{
    DefineOutputPort<T>(S, portIndex, rows, cols);
}

template <typename T>
inline T *GetOutputPortSignal(SimStruct *S, int portIndex, size_t size)
{
    // Check we have enough output ports
    if (ssGetNumOutputPorts(S) <= portIndex)
    {
        errorMessageIO = "Insufficient number of output ports configured for Port " + std::to_string(portIndex);
        ssSetErrorStatus(S, errorMessageIO.c_str());
        return nullptr;
    }

    // Check if the output port width matches the expected width
    if (ssGetOutputPortWidth(S, portIndex) != size)
    {
        errorMessageIO = "Output port width " + std::to_string(ssGetOutputPortWidth(S, portIndex)) + " does not match expected width " + std::to_string(size) + " for Port " + std::to_string(portIndex);
        ssSetErrorStatus(S, errorMessageIO.c_str());
        return nullptr;
    }

    T *outputSignal = (T *)ssGetOutputPortSignal(S, portIndex);
    // Check if outputSignal is valid
    if (!outputSignal)
    {
        errorMessageIO = "Failed to get output port signal for port index " + std::to_string(portIndex);
        ssWarning(S, errorMessageIO.c_str());
        return nullptr;
    }

    return outputSignal;
}

template <typename T>
void SetScalarOutputPort(SimStruct *S, int portIndex, T value)
{
    T *outputSignal = GetOutputPortSignal<T>(S, portIndex, 1);
    if (!outputSignal)
        return;

    // Set the output port value
    *outputSignal = value;
}

template <typename T>
void SetVectorOutputPort(SimStruct *S, int portIndex, const std::vector<T> &values)
{
    T *outputSignal = GetOutputPortSignal<T>(S, portIndex, values.size());
    if (!outputSignal)
        return;

    // Set the output port values
    std::copy(values.begin(), values.end(), outputSignal);
}

template <typename T>
void SetVectorOutputPort(SimStruct *S, int portIndex, T *values, size_t size)
{
    T *outputSignal = GetOutputPortSignal<T>(S, portIndex, size);
    if (!outputSignal)
        return;

    // Set the output port values
    std::copy(values, values + size, outputSignal);
}

template <typename T, size_t W>
void SetVectorOutputPort(SimStruct *S, int portIndex, T *values)
{
    T *outputSignal = GetOutputPortSignal<T>(S, portIndex, W);
    if (!outputSignal)
        return;

    // Set the output port values
    std::copy(values, values + W, outputSignal);
}

template <typename T, size_t W>
void SetVectorOutputPort(SimStruct *S, int portIndex, std::array<T, W> values)
{
    T *outputSignal = GetOutputPortSignal<T>(S, portIndex, W);
    if (!outputSignal)
        return;

    // Set the output port values
    std::copy(values.begin(), values.end(), outputSignal);
}

template <typename T>
void Set2DMatrixOutputPort(SimStruct *S, int portIndex, std::vector<std::vector<T>> &values)
{
    T *outputSignal = GetOutputPortSignal<T>(S, portIndex, values.size() * values[0].size());
    if (!outputSignal)
        return;

    // Set the output port values
    for (size_t i = 0; i < values.size(); ++i)
    {
        std::copy(values[i].begin(), values[i].end(), outputSignal + i * values[i].size());
    }
}

template <typename T>
void Set2DMatrixOutputPort(SimStruct *S, int portIndex, T *values, size_t rows, size_t cols)
{
    T *outputSignal = GetOutputPortSignal<T>(S, portIndex, rows * cols);
    if (!outputSignal)
        return;

    std::copy(values, values + (rows * cols), outputSignal);
}

template <typename T, size_t W, size_t H>
void Set2DMatrixOutputPort(SimStruct *S, int portIndex, T *values)
{
    T *outputSignal = GetOutputPortSignal<T>(S, portIndex, W * H);
    if (!outputSignal)
        return;

    std::copy(values, values + (W * H), outputSignal);
}

template <typename T, size_t W, size_t H>
void Set2DMatrixOutputPort(SimStruct *S, int portIndex, std::array<std::array<T, W>, H> values)
{
    T *outputSignal = GetOutputPortSignal<T>(S, portIndex, W * H);
    if (!outputSignal)
        return;

    // Set the output port values
    for (size_t i = 0; i < H; ++i)
    {
        std::copy(values[i].begin(), values[i].end(), outputSignal + i * W);
    }
}

template <typename T, size_t W, size_t H>
void Set2DMatrixOutputPort(SimStruct *S, int portIndex, T **values)
{
    T *outputSignal = GetOutputPortSignal<T>(S, portIndex, W * H);
    if (!outputSignal)
        return;

    // Set the output port values from 2D array
    for (size_t i = 0; i < W; ++i)
    {
        std::copy(values[i], values[i] + H, outputSignal + i * H);
    }
}

template <typename T, size_t W, size_t H>
void Set2DMatrixOutputPort(SimStruct *S, int portIndex, T (&values)[W][H])
{
    T *outputSignal = GetOutputPortSignal<T>(S, portIndex, W * H);
    if (!outputSignal)
        return;

    // Set the output port values from 2D array
    for (size_t i = 0; i < W; ++i)
    {
        std::copy(values[i], values[i] + H, outputSignal + i * H);
    }
}

template <typename T>
inline T *GetInputPortSignal(SimStruct *S, int portIndex, size_t size)
{
    // Check we have enough input ports
    if (ssGetNumInputPorts(S) <= portIndex)
    {
        errorMessageIO = "Insufficient number of input ports configured for Port " + std::to_string(portIndex);
        ssSetErrorStatus(S, errorMessageIO.c_str());
        return nullptr;
    }

    // Check if the input port width matches the expected width
    if (ssGetInputPortWidth(S, portIndex) != size)
    {
        errorMessageIO = "Input port width " + std::to_string(ssGetInputPortWidth(S, portIndex)) + " does not match expected width " + std::to_string(size) + " for Port " + std::to_string(portIndex);
        ssSetErrorStatus(S, errorMessageIO.c_str());
        return nullptr;
    }

    // Get the input port signal
    T *inputSignal = (T *)ssGetInputPortSignal(S, portIndex);
    if (!inputSignal)
    {
        errorMessageIO = "Failed to get input port signal for port index " + std::to_string(portIndex);
        ssWarning(S, errorMessageIO.c_str());
        return nullptr;
    }

    return inputSignal;
}

template <typename T>
std::optional<T> GetScalarInputPort(SimStruct *S, int portIndex)
{
    T *inputSignal = GetInputPortSignal<T>(S, portIndex, 1);
    if (!inputSignal)
        return std::nullopt;

    // Get the input port value
    return *inputSignal;
}

template <typename T>
std::optional<std::vector<T>> GetVectorInputPort(SimStruct *S, int portIndex, size_t width)
{
    T *inputSignal = GetInputPortSignal<T>(S, portIndex, width);
    if (!inputSignal)
        return std::nullopt;

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
    T *inputSignal = GetInputPortSignal<T>(S, portIndex, W);
    if (!inputSignal)
        return std::nullopt;

    // Get the input port values
    std::array<T, W> values;
    std::copy(inputSignal, inputSignal + W, values.begin());
    return values;
}

template <typename T, size_t W>
bool GetVectorInputPort(SimStruct *S, int portIndex, T *values)
{
    T *inputSignal = GetInputPortSignal<T>(S, portIndex, W);
    if (!inputSignal)
        return false;

    std::copy(inputSignal, inputSignal + W, values);

    return true;
}

template <typename T>
std::optional<std::vector<std::vector<T>>> Get2DMatrixInputPort(SimStruct *S, int portIndex, size_t width, size_t height)
{
    T *inputSignal = GetInputPortSignal<T>(S, portIndex, width * height);
    if (!inputSignal)
        return std::nullopt;

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
    T *inputSignal = GetInputPortSignal<T>(S, portIndex, W * H);
    if (!inputSignal)
        return std::nullopt;

    // Get the input port values
    std::array<std::array<T, H>, W> values;
    for (size_t i = 0; i < W; ++i)
    {
        std::copy(inputSignal + i * H, inputSignal + (i + 1) * H, values[i].begin());
    }
    return values;
}

template <typename T, size_t W, size_t H>
bool Get2DMatrixInputPort(SimStruct *S, int portIndex, T *values)
{
    T *inputSignal = GetInputPortSignal<T>(S, portIndex, W * H);
    if (!inputSignal)
        return false;

    // Get the input port values
    std::copy(inputSignal, inputSignal + (W * H), values);

    return true;
}

template <typename T, size_t W, size_t H>
bool Get2DMatrixInputPort(SimStruct *S, int portIndex, T **values)
{
    T *inputSignal = GetInputPortSignal<T>(S, portIndex, W * H);
    if (!inputSignal)
        return false;

    // Get the input port values and copy them to the 2D array
    for (size_t i = 0; i < W; ++i)
    {
        std::copy(inputSignal + i * H, inputSignal + (i + 1) * H, values[i]);
    }

    return true;
}

template <typename T, size_t W, size_t H>
bool Get2DMatrixInputPort(SimStruct *S, int portIndex, T (&values)[W][H])
{
    T *inputSignal = GetInputPortSignal<T>(S, portIndex, W * H);
    if (!inputSignal)
        return false;

    // Get the input port values and copy them to the 2D array
    for (size_t i = 0; i < W; ++i)
    {
        std::copy(inputSignal + i * H, inputSignal + (i + 1) * H, values[i]);
    }

    return true;
}

template <typename T, size_t W, size_t H>
bool GetInputPort(SimStruct *S, int portIndex, T *output)
{
    T *inputSignal = GetInputPortSignal<T>(S, portIndex, W * H);
    if (!inputSignal)
        return false;

    // Get the input port values
    std::copy(inputSignal, inputSignal + (W * H), output);

    return true;
}

template <typename T>
bool GetInputPort(SimStruct *S, int portIndex, T *output, size_t width = 1, size_t height = 1)
{
    T *inputSignal = GetInputPortSignal<T>(S, portIndex, width * height);
    if (!inputSignal)
        return false;

    // Get the input port values
    std::copy(inputSignal, inputSignal + (width * height), output);

    return true;
}