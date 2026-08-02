# QT Blackjack

A cross-platform 2D Blackjack card game built with C++20, Qt (Qt6 / Qt5), and CMake. Features smooth card animations, sound effects, custom typography, and a modern betting interface.

---

## Prerequisites

- **C++ Compiler**: A compiler supporting C++20 (MSVC 2019+, GCC 10+, Clang 10+).
- **CMake**: Version 3.16 or higher.
- **Qt Framework**: Qt 6 or Qt 5.

---

## Building & Running

### 1. Command Line (CMake)

Clone the repository and build from the root directory:

```bash
git clone https://github.com/miikeGit/Blackjack.git

cd Blackjack

cmake -B build -S .

cmake --build build --config Release
```

> **Note on Qt Path**: If CMake cannot locate your Qt installation automatically, pass your Qt CMake configuration directory via `CMAKE_PREFIX_PATH`:
>
> ```bash
> cmake -B build -S . -DCMAKE_PREFIX_PATH="C:/Qt/6.6.0/msvc2019_64"
> ```

### 2. Qt Creator

1. Open **Qt Creator**.
2. Select **Open File or Project** and open `CMakeLists.txt`.
3. Choose your desired Qt kit (e.g. Qt 6.x Desktop MSVC / GCC / Clang).
4. Click **Build** and **Run**.

### 3. Visual Studio / VS Code

- **Visual Studio**: File -> Open -> Folder (select project directory). Visual Studio with CMake Tools will detect `CMakeLists.txt` automatically.
- **VS Code**: Ensure the *CMake Tools* extension is installed. Select your kit/compiler and click **Build**.