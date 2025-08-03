# S-Function-Utilities
Utility methods for making it easier to write Matlab/Simulink S-Functions

## S-Function Port Definition Utilities

The file `S-Function-Utilities/IO.hpp` provides template functions to simplify the definition of input and output ports in Simulink S-Functions.

### Where to use these functions

Call these functions in the S-Function's `mdlInitializeSizes` method, after you have set the number of input/output ports, but before you use the ports in other methods. For example:

```cpp
#define S_FUNCTION_NAME  my_sfunction
#define S_FUNCTION_LEVEL 2
#include "simstruc.h"
#include "S-Function-Utilities/IO.hpp"

static void mdlInitializeSizes(SimStruct *S)
{
    // Example: Define a scalar input port (double)
    DefineScalarInputPort<real_T>(S, 0);

    // Example: Define a vector input port (uint8, width 4)
    DefineVectorInputPort<uint8_T>(S, 1, 4);

    // Example: Define a 2D matrix input port (double, 3x3)
    Define2DMatrixInputPort<real_T>(S, 2, 3, 3);

    // Example: Define a scalar output port (int32)
    DefineScalarOutputPort<int32_T>(S, 0);

    // Example: Define a vector output port (double, width DOF)
    DefineVectorOutputPort<real_T>(S, 1, DOF);

    // Example: Define a 2D matrix output port (float, 2x6)
    Define2DMatrixOutputPort<real32_T>(S, 2, 2, 6);
}
```

### Function Reference

#### Input Ports
- `DefineScalarInputPort<T>(SimStruct* S, int portIndex, int isDirectFeedthrough = 1)`
- `DefineVectorInputPort<T>(SimStruct* S, int portIndex, int width, int isDirectFeedthrough = 1)`
- `Define2DMatrixInputPort<T>(SimStruct* S, int portIndex, int rows, int cols, int isDirectFeedthrough = 1)`

#### Output Ports
- `DefineScalarOutputPort<T>(SimStruct* S, int portIndex)`
- `DefineVectorOutputPort<T>(SimStruct* S, int portIndex, int width)`
- `Define2DMatrixOutputPort<T>(SimStruct* S, int portIndex, int rows, int cols)`

### Notes
- The template parameter `T` should be one of the Simulink types: `real_T`, `real32_T`, `int32_T`, `uint32_T`, `int16_T`, `uint16_T`, `int8_T`, `uint8_T`, `boolean_T`.
- For input ports, you can set `isDirectFeedthrough` to 0 or 1 depending on your model's requirements.
- These functions automatically ensure the number of ports is sufficient and set the correct data type and dimensions.
- Always call these functions in `mdlInitializeSizes` before using the ports in other S-Function methods.