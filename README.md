# C++ Design Patterns

Learning C++ design patterns. One Git repository at this root; each pattern is a
self-contained folder with its own source, build file, and notes.

```text
Desing_Patterns/
  .git/  .gitignore  .clang-format  .vscode/
  command/        Complete: headers, sources, tests, CMake (see command/Readme.md)
  singleton/      Work in progress: single main.cpp
```

There is no root-level CMake project. Build a pattern from inside its folder, for
example:

```bash
cd command
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

Full steps are in [command/Readme.md](command/Readme.md).

## Editor Setup

Uses the installed **C/C++** and **CMake Tools** extensions.

- `Ctrl+S` formats C/C++ files using `.clang-format`. It does not add headers; use
  `Ctrl+.` (Quick Fix) or `Ctrl+Space` (completion) for that.
- `Ctrl+Shift+B` configures and builds the `command` project; use **Tasks: Run
  Task** for its test and run tasks. Change the folder in `.vscode/tasks.json`
  and `cmake.sourceDirectory` in `.vscode/settings.json` to work on another pattern.

## Adding a Pattern

Create a folder (for example `factory/`) with its own `CMakeLists.txt`, using
`command/CMakeLists.txt` as the template, and keep its `include/`, `src/`, and
`tests/` folders inside it. Start with a single `main.cpp` and split it when it
grows.
