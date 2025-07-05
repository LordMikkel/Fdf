# FDF - Framework de Visualización 3D/4D 🌐

> **Un motor de renderizado matemático para visualización de mapas topográficos 3D y objetos geométricos 4D**

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr)
[![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Mathematics](https://img.shields.io/badge/Mathematics-Linear_Algebra-blue)](https://en.wikipedia.org/wiki/Linear_algebra)

---

## 📖 Descripción

**FDF** es un proyecto ambicioso que trasciende los requisitos básicos del currículo de 42, desarrollado como una profunda exploración en **geometría computacional**, **álgebra lineal** y **matemáticas aplicadas**. Este motor de renderizado implementa visualización de mapas topográficos 3D y objetos geométricos 4D con rotaciones matemáticamente precisas.

### 🎯 Motivación Personal

Elegí ampliar este proyecto para comprender en profundidad los fundamentos matemáticos que sustentan la **inteligencia artificial**, **data science** y el **desarrollo de motores gráficos**. La implementación de rotaciones en 4D y proyecciones geométricas proporciona una base sólida para futuras aplicaciones en visualización de datos multidimensionales y geometría computacional avanzada.

---

## ⚡ Características Principales

### 🔮 Renderizado 3D Avanzado
- **Múltiples perspectivas**: Isométrica, paralela, lateral, superior y POV personalizada
- **Interpolación de colores** basada en elevación topográfica
- **Transformaciones geométricas**: Traslación, escalado, zoom dinámico
- **Rotaciones matemáticamente precisas** en los tres ejes

### 🌌 Geometría 4D Implementada
- **Tesseract (Hipercubo 4D)**: 16 vértices, 32 aristas, 24 caras cuadradas
- **Pentachoron (Símplex 4D)**: 5 vértices, 10 aristas, 10 caras triangulares
- **Hexacosicoron (600-cell)**: Polítopo regular 4D con 120 vértices
- **Rotaciones en 6 planos 4D**: XY, XZ, XW, YZ, YW, ZW

### 📊 Mapas Topográficos Personalizados
- `sagrada_familia.fdf` - Representación arquitectónica de la basílica
- `fachada.fdf` - Análisis geométrico de estructuras
- `tower.fdf` - Visualización de estructuras verticales
- Soporte para mapas `.fdf` con interpolación de colores

---

## 🧮 Fundamentos Matemáticos

### Derivación de Matrices de Rotación

La implementación se basa en la **derivación propia de matrices de rotación 2D/3D mediante transformación de coordenadas polares e identidades trigonométricas**.

#### Rotación 2D - Base Matemática
```
Para un punto P(x,y) en coordenadas cartesianas:
r = √(x² + y²)
θ = arctan(y/x)

Rotación por ángulo α:
x' = r·cos(θ + α) = r·cos(θ)·cos(α) - r·sin(θ)·sin(α) = x·cos(α) - y·sin(α)
y' = r·sin(θ + α) = r·sin(θ)·cos(α) + r·cos(θ)·sin(α) = y·cos(α) + x·sin(α)
```

#### Matriz de Rotación 3D (Eje Z)
```
⎡ cos(α)  -sin(α)   0 ⎤   ⎡ x ⎤
⎢ sin(α)   cos(α)   0 ⎥ × ⎢ y ⎥
⎣   0        0      1 ⎦   ⎣ z ⎦
```

#### Extensión a 4D - Rotaciones Planares
En 4D, las rotaciones ocurren en **planos** en lugar de ejes. Cada rotación 4D se define por dos vectores ortonormales que determinan el plano de rotación:

```c
// Rotación en plano XY (equivalente a rotación 3D en Z)
void rotate_xy(float *x, float *y, float angle) {
    float prev_x = *x, prev_y = *y;
    *x = prev_x * cos(angle) - prev_y * sin(angle);
    *y = prev_x * sin(angle) + prev_y * cos(angle);
}

// Rotación en plano XW (4ª dimensión)
void rotate_xw(float *x, float *w, float angle) {
    float prev_x = *x, prev_w = *w;
    *x = prev_x * cos(angle) - prev_w * sin(angle);
    *w = prev_x * sin(angle) + prev_w * cos(angle);
}
```

### Proyección 4D→3D→2D

La visualización de objetos 4D requiere **doble proyección**:

1. **4D → 3D**: Proyección estereográfica o perspectiva desde un punto en la 4ª dimensión
2. **3D → 2D**: Proyección de perspectiva tradicional para renderizado en pantalla

```
Proyección 4D→3D: (x, y, z, w) → (x/(w+d), y/(w+d), z/(w+d))
donde d es la distancia del observador en la 4ª dimensión
```

---

## 🎮 Controles Interactivos

### Navegación 3D
- **WASD**: Movimiento de cámara
- **QE**: Rotación en eje Z
- **RF**: Zoom in/out
- **Flechas**: Rotación en ejes X e Y
- **Mouse**: Navegación intuitiva con arrastre

### Perspectivas Predefinidas
- **1**: Vista isométrica clásica
- **2**: Vista superior (plano XY)
- **3**: Vista frontal (plano XZ)
- **4**: Vista lateral (plano YZ)
- **5**: Vista POV personalizada

### Controles 4D (Solo objetos 4D)
- **7/8**: Rotación en plano XW
- **9/0**: Rotación en plano YW
- **U/I**: Rotación en plano ZW

---

## 🚀 Instalación y Uso

### Prerrequisitos
```bash
# Ubuntu/Debian
sudo apt-get install build-essential libx11-dev libxext-dev libbsd-dev

# Arch Linux
sudo pacman -S base-devel libx11 libxext
```

### Compilación
```bash
git clone [repository-url] fdf
cd fdf
make
```

### Ejecución

#### Mapas 3D
```bash
./fdf maps/sagrada_familia.fdf
./fdf maps/tower.fdf
./fdf maps/mars.fdf
```

#### Objetos 4D
```bash
make 4d
# Ejecuta automáticamente:
# ./fdf tesseract
# ./fdf pentachoron
# ./fdf hexacosicoron
```

---

## 📁 Estructura del Proyecto

```
fdf/
├── inc/                    # Headers y definiciones
│   ├── fdf.h              # Declaraciones principales
│   ├── fdf_structs.h      # Estructuras de datos
│   └── fdf_macros.h       # Constantes y macros
├── src/
│   ├── core/              # Sistema principal
│   ├── render/            # Motor de renderizado
│   │   ├── rotation_3d.c  # Rotaciones 3D
│   │   ├── rotation_4d.c  # Rotaciones 4D
│   │   ├── projection.c   # Sistemas de proyección
│   │   └── 4d.c          # Geometría 4D
│   ├── parse/             # Análisis de archivos .fdf
│   ├── events/            # Manejo de eventos
│   └── menu/              # Interfaz de usuario
├── maps/                  # Mapas topográficos
└── lib/                   # Dependencias
```

---

## 🔬 Aplicaciones y Aprendizajes

### Conocimientos Técnicos Adquiridos
- **Álgebra Lineal Aplicada**: Matrices de transformación, espacios vectoriales multidimensionales
- **Geometría Computacional**: Proyecciones, interpolación, algoritmos de línea
- **Matemáticas 4D**: Rotaciones planares, hiperobjetos, proyección estereográfica
- **Optimización de Rendimiento**: Algoritmos eficientes para renderizado en tiempo real

### Relevancia para IA y Data Science
- **Visualización de Datos Multidimensionales**: Base para técnicas como PCA, t-SNE
- **Redes Neuronales**: Comprensión geométrica de espacios de alta dimensión
- **Computer Vision**: Fundamentos de transformaciones geométricas y proyecciones
- **Matemáticas Aplicadas**: Preparación para algoritmos de optimización y análisis numérico

### Conexión con Motores Gráficos
- **Pipeline de Renderizado**: Transformaciones modelo→mundo→vista→proyección
- **Sistemas de Coordenadas**: Manejo de múltiples espacios de coordenadas
- **Optimización Gráfica**: Técnicas de culling, interpolación y anti-aliasing

---

## 🌟 Características Avanzadas

### Interpolación de Colores Inteligente
- **Gradientes basados en elevación** para representación intuitiva del terreno
- **Paletas de colores personalizables** según el rango de datos
- **Interpolación linear** suave entre puntos adyacentes

### Optimizaciones de Rendimiento
- **Algoritmo de Bresenham optimizado** para dibujo de líneas
- **Culling de geometría** fuera del viewport
- **Cálculos matemáticos optimizados** con funciones trigonométricas precalculadas

---

## 🎯 Visión Futura

Este proyecto representa un paso fundamental en mi trayectoria hacia:

- **Inteligencia Artificial**: Comprensión geométrica para algoritmos de ML
- **Data Science**: Visualización avanzada de datasets multidimensionales
- **Computer Graphics**: Base sólida para motores de renderizado 3D/4D
- **Investigación Matemática**: Exploración de geometrías no euclidianas

---

## 👨‍💻 Autor

**Mikel Garrido** - Estudiante de 42 Barcelona
*Apasionado por las matemáticas aplicadas, la inteligencia artificial y la visualización de datos*

---

*"La geometría es el arte de pensar correctamente y dibujar figuras incorrectas."* - Henri Poincaré
