# IMT_Scholarship

Repository for IMT scholarship practice work across C/C++, Linux administration, and Qt examples.

## Project Structure

```text
IMT_Scholarship/
├── README.md
├── main.o
├── .vscode/
│   ├── launch.json
│   └── tasks.json
├── CPP/
│   ├── Practice/
│   │   ├── 00_Micsillaneous/
│   │   │   ├── PrintBinary
│   │   │   └── PrintBinary.c
│   │   └── 01_Pointers/
│   └── Sessions/
│       ├── Session_01/
│       │   ├── 01_HelloWorld.cpp
│       │   ├── 02_HelloWorld2.cpp
│       │   └── 03_MovingWindow.c
│       ├── Session_02/
│       │   ├── 01_PrintBinary.cpp
│       │   ├── 02_HeterogeneousArray.cpp
│       │   ├── 03_IntegerClass.cpp
│       │   ├── 04_SensorData.cpp
│       │   ├── 05_Stack.cpp
│       │   ├── 06_Timer.cpp
│       │   └── 07_AdvancedTimer.cpp
│       ├── Session_03/
│       │   ├── 01_comaSeparator.cpp
│       │   ├── 02_CSVParsing.cpp
│       │   ├── 03_CartesianPoint.cpp
│       │   └── 04_CounterClass.cpp
│       ├── Session_04/
│       │   ├── 01_SwapWithRef.cpp
│       │   ├── 02_SwapWithPointer.cpp
│       │   ├── 03_CounterWithRef.cpp
│       │   ├── 04_EnumClass.cpp
│       │   ├── 05_InlineKeyword.cpp
│       │   ├── 06_StaticKeyword.cpp
│       │   ├── 07_SensorClass.cpp
│       │   ├── 08_SwapObjects.cpp
│       │   ├── 09_DeviceClasss.cpp
│       │   ├── 10_AritmeticOverloading.cpp
│       │   └── 11_BankSystem.cpp
│       ├── Session_05/
│       │   ├── 01_StreamsOP.cpp
│       │   ├── 02_GetLine.cpp
│       │   ├── 03_ParseEntireFile.cpp
│       │   ├── 04_MultiOpParsing.cpp
│       │   ├── 06_UARTConfig.cpp
│       │   ├── 07_CommandLineArgs.cpp
│       │   ├── 08_ParseCMDLineArgs.cpp
│       │   ├── 09_ArithmeticInOutParsing.cpp
│       │   ├── 10_Template.cpp
│       │   ├── 11_Vectors.cpp
│       │   ├── 12_MatrixOfVector.cpp
│       │   ├── input.txt
│       │   └── output.txt
│       ├── Session_06/
│       │   ├── 01_Containers.cpp
│       │   ├── 02_SumOfNums.cpp
│       │   ├── 04_VactorOPAssignment.cpp
│       │   ├── input.txt
│       │   └── sizevscapacity.csv
│       ├── Session_07/
│       │   ├── 01_Stack.cpp
│       │   ├── 02_ValidParenthesis.cpp
│       │   ├── 03_CinClac.cpp
│       │   ├── 04_MovingAvarage.cpp
│       │   ├── 05_Map.cpp
│       │   ├── 06_CallableObjects.cpp
│       │   ├── 07_StringToMap.cpp
│       │   └── 08_ReverseQueueByStack.cpp
│       ├── Session_08/
│       │   ├── 01_.cpp
│       │   ├── 02_.cpp
│       │   ├── 03_.cpp
│       │   └── 04_.cpp
│       ├── Session_09/
│       │   ├── 01_tuple.cpp
│       │   ├── 02_Algorithms.cpp
│       │   ├── 03_ReverseArrayOfStrings.cpp
│       │   ├── 04_.cpp
│       │   ├── 05_.cpp
│       │   ├── 06_.cpp
│       │   └── 07_Assignment.cpp
│       ├── Session_10/
│       │   ├── 01_VoidPtr.cpp
│       │   ├── 02_AnyGenericDT.cpp
│       │   ├── 03_VariantGenericDT.cpp
│       │   ├── 04_ParseFileInVariant.cpp
│       │   ├── 05_UniquePointer.cpp
│       │   ├── 06_UniquePtrExercise.cpp
│       │   ├── 07_SharedPointer.cpp
│       │   ├── 08_Namespace.cpp
│       │   ├── 09_Modularity/
│       │   │   ├── ex.cpp
│       │   │   ├── main.cpp
│       │   │   ├── mod.cpp
│       │   │   └── mod.hpp
│       │   ├── 10_.cpp
│       │   ├── input.txt
│       │   └── output.txt
│       ├── Session_11/
│       │   └── 01_.cpp
│       └── Session_12/
│           ├── 01_ErrorHandling.cpp
│           ├── 02_TrafficLight.cpp
│           └── 03_ATM.cpp
├── LinuxAdministration/
│   ├── Session_14/
│   │   ├── a-file.i
│   │   ├── a-file.o
│   │   ├── a-file.s
│   │   ├── a.out
│   │   ├── file
│   │   ├── file.c
│   │   ├── makefile
│   │   ├── userid
│   │   ├── userid.cpp
│   │   ├── workingdirectory
│   │   └── workingdirectory.cpp
│   ├── Session_15/
│   │   ├── file
│   │   ├── file1.c
│   │   ├── file2
│   │   ├── mycat
│   │   ├── mycat.c
│   │   ├── mycp
│   │   ├── mycp.c
│   │   ├── write
│   │   ├── write.asm
│   │   └── write.o
│   ├── Session_16/
│   │   └── myless.c
│   ├── Session_17/
│   │   └── 10_.cpp
│   └── Session_18/
│       ├── folder1/
│       ├── folder2/
│       ├── myscript.sh
│       ├── myscript1.sh
│       ├── myscript2.sh
│       ├── myscript3.sh
│       ├── myscript4.sh
│       ├── myscript5.sh
│       ├── myscript6.sh
│       ├── myscript7.sh
│       ├── myscript8.sh
│       ├── myscript9.sh
│       ├── myscript10.sh
│       ├── myscript11.sh
│       ├── myscript12.sh
│       ├── myscript13.sh
│       ├── myscript14.sh
│       ├── myscript15.sh
│       ├── myscript16.sh
│       ├── myscript17.sh
│       ├── myscript18.sh
│       ├── myscript19.sh
│       ├── myscript20.sh
│       ├── myscript21.sh
│       ├── myscript22.sh
│       ├── myscript23.sh
│       ├── myscript24.sh
│       ├── myscript25.sh
│       └── myscript26.sh
└── QT/
	├── .vscode/
	│   └── c_cpp_properties.json
	└── Examples/
		└── Example1/
			├── .vscode/
			│   ├── c_cpp_properties.json
			│   └── settings.json
			├── build/
			│   ├── .qmake.stash
			│   └── Makefile
			├── Example1.pro
			└── main.cpp
```

## Build and Run

Use GCC/G++ directly from the repository root:

```sh
# C example
gcc -g CPP/Sessions/Session_01/03_MovingWindow.c -o main.o

# C++ example
g++ -std=c++17 -g CPP/Sessions/Session_05/12_MatrixOfVector.cpp -o main.o

# run
./main.o
```

VS Code task configuration is available in `.vscode/tasks.json`.

## Notes

- This repository contains both source files and generated artifacts (for example: `a.out`, object files, and local build output folders).
- Some examples depend on local input files inside their session folder.
