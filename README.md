# FDF - Visualizador 3D/4D 🌐

> **Un motor de renderizado para mapas topográficos 3D y figuras geométricas 4D**

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr)
[![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))

---

## 📖 ¿Qué es FDF?

**FDF** es mi extensión del proyecto Wire Frame Drawing de 42. Mientras que el proyecto base solo requiere renderizar mapas 2D como wireframes 3D, decidí ir más allá e implementar:

- **Visualización de objetos 4D** como el tesseract y el pentachoron
- **Múltiples sistemas de proyección** (isométrica, perspectiva, ortogonal)
- **Rotaciones en 4 dimensiones** con controles intuitivos
- **Interpolación de colores** automática según la elevación

### ¿Por qué amplié el proyecto?

Quería entender cómo funcionan las transformaciones geométricas desde cero, especialmente porque son fundamentales para:
- Inteligencia artificial (espacios de alta dimensión)
- Visualización de datos complejos
- Motores gráficos y videojuegos

---

## ⚡ Características

### 🔮 Renderizado 3D
- **Vistas múltiples**: isométrica, frontal, lateral, superior y perspectiva
- **Interpolación de colores** que cambia según la altura del terreno
- **Zoom y rotación** en tiempo real
- **Navegación con mouse** para explorar el mapa

### 🌌 Objetos 4D
- **Tesseract**: El cubo de 4 dimensiones (16 vértices)
- **Pentachoron**: El triángulo de 4 dimensiones (5 vértices)
- **Hexacosicoron**: Figura compleja de 120 vértices
- **Rotaciones 4D**: En 6 planos diferentes (XY, XZ, XW, YZ, YW, ZW)

---

## 🧮 ¿Cómo funcionan las rotaciones?

### El problema: rotar un punto en el espacio

Imagina que tienes un punto en 2D, por ejemplo `(3, 4)`, y quieres rotarlo 45 grados. ¿Cómo lo haces?

### Mi solución paso a paso

**Paso 1: Convertir a coordenadas polares**
```
Cualquier punto (x, y) se puede expresar como:
x = r × cos(θ)
y = r × sin(θ)

Donde r = √(x² + y²) y θ = arctan(y/x)
```

**Paso 2: Sumar el ángulo de rotación**
```
Si queremos rotar α grados:
x' = r × cos(θ + α)
y' = r × sin(θ + α)
```

**Paso 3: Aplicar identidades trigonométricas**
```
cos(θ + α) = cos(θ)cos(α) - sin(θ)sin(α)
sin(θ + α) = sin(θ)cos(α) + cos(θ)sin(α)
```

**Paso 4: Sustituir y simplificar**
```
x' = r×cos(θ)×cos(α) - r×sin(θ)×sin(α)
y' = r×sin(θ)×cos(α) + r×cos(θ)×sin(α)

Como x = r×cos(θ) e y = r×sin(θ):
x' = x×cos(α) - y×sin(α)
y' = y×cos(α) + x×sin(α)
```

### ¿Y en forma de matriz?

Mi solución es exactamente lo mismo que la matriz de rotación:

```
⎡ cos(α)  -sin(α) ⎤   ⎡ x ⎤   ⎡ x×cos(α) - y×sin(α) ⎤
⎢ sin(α)   cos(α) ⎥ × ⎢ y ⎥ = ⎢ x×sin(α) + y×cos(α) ⎥
⎣                 ⎦   ⎣   ⎦   ⎣                     ⎦
```

**Es la misma fórmula.** Las matrices son solo una forma elegante de escribir el mismo concepto.

### Rotaciones en 3D

Para 3D, hago lo mismo pero por ejes. Por ejemplo, rotar en el eje Z:

```c
void rotate_z(float *x, float *y, float angle) {
    float prev_x = *x, prev_y = *y;
    *x = prev_x * cos(angle) - prev_y * sin(angle);
    *y = prev_x * sin(angle) + prev_y * cos(angle);
}
```

### Rotaciones en 4D: más simple de lo que parece

En 4D no hay "ejes de rotación" como en 3D. En su lugar, rotas en **planos**.

Por ejemplo, para rotar en el plano XW (la 4ª dimensión):

```c
void rotate_xw(float *x, float *w, float angle) {
    float prev_x = *x, prev_w = *w;
    *x = prev_x * cos(angle) - prev_w * sin(angle);
    *w = prev_x * sin(angle) + prev_w * cos(angle);
}
```

**¡Es exactamente la misma fórmula que en 2D!** Solo cambias las variables que participan en la rotación.

En 4D tienes 6 planos posibles: XY, XZ, XW, YZ, YW, ZW. Cada uno se comporta como una rotación 2D independiente.

---

## 🎮 Controles

### Navegación básica
- **Flechas**: Rotar en ejes X e Y
- **< >** (comas): Rotar en eje Z
- **+/-**: Escalar altura del mapa
- **Mouse**: Arrastrar para mover la vista
- **Scroll**: Zoom in/out
- **ESC**: Salir

### Cambiar vista
- **I**: Vista isométrica
- **T**: Vista superior
- **F**: Vista frontal
- **L**: Vista lateral
- **P**: Vista en perspectiva

### Controles 4D (solo para objetos 4D)
- **W/S**: Rotar en planos XZ y YW
- **A/D**: Rotar en planos XY y ZW

---

## 🚀 Instalación y Uso

### Compilación
```bash
git clone [tu-repositorio-url] fdf
cd fdf
make
```

### Ejecución

#### Mapas 3D
```bash
./fdf maps/42.fdf
./fdf maps/mars.fdf
./fdf maps/julia.fdf
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
├── inc/                    # Headers
│   ├── fdf.h              # Funciones principales
│   ├── fdf_structs.h      # Estructuras de datos
│   └── fdf_macros.h       # Constantes y teclas
├── src/
│   ├── core/              # Inicialización y gestión de memoria
│   ├── render/            # Motor de renderizado
│   │   ├── rotation_3d.c  # Rotaciones en 3D
│   │   ├── rotation_4d.c  # Rotaciones en 4D
│   │   ├── projection.c   # Proyecciones 4D→3D→2D
│   │   └── 4d.c          # Generación de objetos 4D
│   ├── parse/             # Lectura de archivos .fdf
│   ├── events/            # Controles de teclado/mouse
│   └── menu/              # Interfaz gráfica
├── maps/                  # Archivos .fdf de ejemplo
└── lib/                   # MiniLibX y libft
```

---

## 🔬 Lo que aprendí

### Conceptos técnicos
- **Rotaciones desde cero**: Derivar las fórmulas sin memorizar matrices
- **Geometría 4D**: Cómo visualizar objetos que no podemos imaginar
- **Proyecciones**: Convertir múltiples dimensiones en una imagen 2D
- **Optimización gráfica**: Algoritmos eficientes para tiempo real

### Conexión con otros campos
- **Machine Learning**: Los espacios de alta dimensión son comunes en ML
- **Visualización de datos**: Técnicas para representar información compleja
- **Motores gráficos**: Pipeline básico de transformaciones geométricas
- **Matemáticas aplicadas**: Resolver problemas reales con conceptos teóricos

---

## 🌟 Características técnicas destacadas

### Proyección 4D inteligente
Para mostrar objetos 4D en la pantalla, uso **doble proyección**:

1. **4D → 3D**: Proyecto desde la 4ª dimensión usando perspectiva
```c
// En projection.c
factor = distance / (distance - point->w);
point->x *= factor;
point->y *= factor;
point->z *= factor;
```

2. **3D → 2D**: Proyecto a la pantalla con vista isométrica o perspectiva

### Interpolación de colores automática
El programa analiza automáticamente la altura mínima y máxima del mapa, y asigna colores que van desde violeta (bajo) hasta dorado (alto), pasando por azul y verde.

### Pipeline de renderizado optimizado
```c
// En project_point()
if (map.type == OBJECT_4D) {
    // 1. Rotaciones 4D
    rotate_xy(&point.x, &point.y, cam.delta);
    rotate_xw(&point.x, &point.w, cam.epsilon);
    // ... más rotaciones 4D

    // 2. Proyección 4D→3D
    project_4d_to_3d(&point);
}

// 3. Transformaciones 3D estándar
point.x *= cam.zoom;
rotate_x(&point.y, &point.z, cam.alpha);
// ...

// 4. Proyección final 3D→2D
project_3d_to_2d(&point, cam.projection);
```

---

## 👨‍💻 Autor

**Mikel Garrido** - Estudiante de 42 Barcelona

---

*Este proyecto me enseñó que las matemáticas complejas, cuando las entiendes paso a paso, son más simples de lo que parecen.*
