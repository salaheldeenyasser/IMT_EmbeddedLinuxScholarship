# IMT_EmbeddedLinuxScholarship

Collection of exercises and examples from the IMT Embedded Linux Scholarship course.

## Structure (examples)
- [Session_1/03_MovingWindow.c](Session_1/03_MovingWindow.c)
- [Session_2/06_Timer.cpp](Session_2/06_Timer.cpp)
- [Session_3/04_CounterClass.cpp](Session_3/04_CounterClass.cpp)
- [Session_4/06_StaticKeyword.cpp](Session_4/06_StaticKeyword.cpp)
- [Session_4/07_SensorClass.cpp](Session_4/07_SensorClass.cpp)
- [Session_4/08_SwapObjects.cpp](Session_4/08_SwapObjects.cpp)
- [Session_4/09_DeviceClasss.cpp](Session_4/09_DeviceClasss.cpp)
- [Session_5/12_MatrixOfVector.cpp](Session_5/12_MatrixOfVector.cpp)
- VS Code tasks: [.vscode/tasks.json](.vscode/tasks.json)
- VS Code debugger: [.vscode/launch.json](.vscode/launch.json)
- Sample I/O: [Session_5/input.txt](Session_5/input.txt), [Session_5/output.txt](Session_5/output.txt)

## Build
You can build a single source file with gcc/g++ (the workspace task uses gcc):
```sh
# compile a C file
gcc -g Session_1/03_MovingWindow.c -o main.o

# compile a C++ file
g++ -std=c++17 -g Session_5/12_MatrixOfVector.cpp -o main.o
```
Or use the VS Code build task (see [.vscode/tasks.json](.vscode/tasks.json)).

## Run
Execute the produced binary:
```sh
./main.o
```
Some programs read stdin or files (see session source files for details).

## Contributing
- Add new examples under the appropriate `Session_*` folder.
- Keep each file focused on a single concept and include a brief comment header.

## Notes
- Files are small, self-contained examples for learning C/C++ language features and basic I/O.
- Use the debugger configuration in [.vscode/launch.json](.vscode/launch.json) for step-through debugging.
