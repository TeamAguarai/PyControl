<div align="center">
<h1>PyControl</h1>

Controla un vehículo RC como el <a href="https://www.amazon.com/Hobao-HB-VS-C30BU-Hyper-Buggy-Engine/dp/B00MY3ROS2">HYPER VS 1/8 BUGGY NITRO</a> a través de un **Raspberry Pi 3** con *python* 
<br>Basado en la libreria en *c++* <a href="https://github.com/TeamAguarai/Control">Control</a>

</div>

## ⚠️ Instalación
> El proyecto está diseñado únicamente para un vehículo con características idénticas al [HYPER VS 1/8 BUGGY NITRO](https://www.amazon.com/Hobao-HB-VS-C30BU-Hyper-Buggy-Engine/dp/B00MY3ROS2)

El proyecto se instala a través de bindings de la libreria <a href="https://github.com/TeamAguarai/Control">Control</a>

En cualquier carpeta de tu sistema, clona este repositorio y ejecuta build.sh (con permisos de administrador)

```bash
git clone https://github.com/TeamAguarai/PyControl/
cd PyControl
sudo ./build.sh
```

## 🎮 Uso
Importa pycontrol en tus proyectos personales
```python
import pycontrol
```
