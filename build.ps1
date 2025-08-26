#!/usr/bin/env pwsh

Write-Host "Building Gunbound Thors Hammers plugin..." -ForegroundColor Green

if (!(Test-Path "build")) {
    New-Item -ItemType Directory -Path "build" | Out-Null
}

Push-Location "build"

try {
    Write-Host "Configuring CMake..." -ForegroundColor Yellow
    cmake .. -G "Visual Studio 17 2022" -A Win32
    
    if ($LASTEXITCODE -ne 0) {
        throw "CMake configuration failed"
    }
    
    Write-Host "Building project..." -ForegroundColor Yellow
    cmake --build . --config Release
    
    if ($LASTEXITCODE -ne 0) {
        throw "Build failed"
    }
    
    Write-Host "Build completed successfully!" -ForegroundColor Green
    Write-Host "Output: build\Release\plugin.dll" -ForegroundColor Cyan
}
catch {
    Write-Host "Build failed: $_" -ForegroundColor Red
    exit 1
}
finally {
    Pop-Location
}