#!/bin/bash

# Para este archivo usar Saltos de Línea Unix (LF)

mkdir build
cd build

git clone https://github.com/pybind/pybind11
git clone https://github.com/TeamAguarai/pampas

HDR_LIST=(
    "pampas/include/_dev.h"
    "pampas/include/Conversion.h"
    "pampas/include/gpio.h"
    "pampas/include/LowPass.h"
    "pampas/include/PID.h"
    "pampas/include/PulseWidth.h"
    "pampas/include/Steer.h"
    "pampas/include/Writer.h"
    "pampas/include/Velocimeter.h"
    "pampas/include/Motor.h"
    "pampas/include/Drive.h"
)

SRC_LIST=(
    "pampas/src/_dev.cpp"
    "pampas/src/Conversion.cpp"
    "pampas/src/gpio.cpp"
    "pampas/src/LowPass.cpp"
    "pampas/src/PID.cpp"
    "pampas/src/PulseWidth.cpp"
    "pampas/src/Steer.cpp"
    "pampas/src/Writer.cpp"
    "pampas/src/Velocimeter.cpp"
    "pampas/src/Motor.cpp"
    "pampas/src/Drive.cpp"
)

COMBINED_SRC="pampas.cpp"
COMBINED_HDR="pampas.h"

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

mv -f pypampas.cpython-311-aarch64-linux-gnu.so /usr/lib/python3/dist-packages/

echo ""
echo "Libreria Pypampas instalada correctamente en /usr/lib/python3/dist-packages/"
echo "Asegurate de importar pypampas en tus proyectos de python"