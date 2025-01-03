#!/bin/bash

# Para este archivo usar Saltos de Línea Unix (LF)

mkdir build
cd build

git clone https://github.com/pybind/pybind11
git clone https://github.com/TeamAguarai/Control

HDR_LIST=(
    "Control/include/_dev.h"
    "Control/include/Conversion.h"
    "Control/include/gpio.h"
    "Control/include/LowPass.h"
    "Control/include/PID.h"
    "Control/include/PulseWidth.h"
    "Control/include/Steer.h"
    "Control/include/Writer.h"
    "Control/include/Velocimeter.h"
    "Control/include/Motor.h"
    "Control/include/Drive.h"
)

SRC_LIST=(
    "Control/src/_dev.cpp"
    "Control/src/Conversion.cpp"
    "Control/src/gpio.cpp"
    "Control/src/LowPass.cpp"
    "Control/src/PID.cpp"
    "Control/src/PulseWidth.cpp"
    "Control/src/Steer.cpp"
    "Control/src/Writer.cpp"
    "Control/src/Velocimeter.cpp"
    "Control/src/Motor.cpp"
    "Control/src/Drive.cpp"
)

COMBINED_SRC="control.cpp"
COMBINED_HDR="control.h"

> $COMBINED_HDR  # Limpiar archivo combinado
for file in "${HDR_LIST[@]}"; do
    cat "$file" >> $COMBINED_HDR
    echo "" >> $COMBINED_HDR  # Añadir línea vacía entre archivos
done

> $COMBINED_SRC  # Limpiar archivo combinado
for file in "${SRC_LIST[@]}"; do
    cat "$file" >> $COMBINED_SRC
    echo "" >> $COMBINED_SRC  
done



cmake ..
make