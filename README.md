# Gunbound Thors Hammers v404 Plugin

DLL plugin for Gunbound Thors Hammers v404 that demonstrates packet sending and game message display functionality.

## Features

- Automatic leave packet sending on F10 keypress
- Game message display functionality with color and icon support
- Inline assembly implementation for maximum performance
- Optimized Release x86 build only

## Project Structure

```
gunbound-th-plugin/
├── ASM/
│   ├── SendPacket.cpp      # Packet sending function implementation
│   ├── SendPacket.h        # send_packet function interface
│   ├── ShowGameMessage.cpp # Game message display implementation
│   └── ShowGameMessage.h   # ShowGameMessage function interface
├── dllmain.cpp             # DLL entry point and main thread
├── CMakeLists.txt          # CMake configuration
├── build.ps1               # Automated build script
└── README.md
```

## Build

Run the PowerShell script:

```powershell
.\build.ps1
```

Or manually:

```bash
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A Win32
cmake --build . --config Release
```

Output: `build/Release/plugin.dll`

## Usage

1. Inject the DLL into the Gunbound Thors Hammers process
2. Press F10 to send leave packet

## Requirements

- Visual Studio 2022
- CMake 3.20+
- Windows x86

## Author

**rizzo**

## Acknowledgments

**Luiz Felipe (Kyll3r)** for providing the server for testing and for encouraging this project through his Java GameServer publication
