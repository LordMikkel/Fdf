# FDF - Motor de Visualización Geométrica 3D/4D

> **Un motor de renderizado vectorial que transforma datos topográficos en visualizaciones 3D y explora la geometría 4D**

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr)
[![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))

---

## 🎯 ¿Qué es FDF?

FDF (FileDeFer) comenzó como un proyecto de 42 School para renderizar mapas topográficos en 3D. Mi implementación va más allá: es un motor completo de transformaciones geométricas que explora tanto la visualización de datos del mundo real como la geometría de dimensiones superiores.

### Características principales

- **Visualización topográfica**: Convierte datos de elevación en wireframes 3D interactivos
- **Geometría 4D**: Explora objetos imposibles de visualizar directamente (tesseract, pentachoron)
- **Múltiples proyecciones**: Isométrica, perspectiva, ortogonal - cada una con su propósito
- **Rotaciones multidimensionales**: Controles intuitivos para navegar en 3D y 4D
- **Colorización automática**: Mapeo altura-color para mejor comprensión visual

---

## 📊 De datos a visualización: El pipeline completo

### Paso 1: Interpretación de datos como vectores

Cada archivo `.fdf` contiene una matriz de elevaciones que interpreto como vectores posicionales:

```
Archivo de ejemplo (42.fdf):
0  0  0  0
0  0 10 10
0 10 10  0

Se convierte en vectores 3D:
(0,0,0) (1,0,0) (2,0,0) (3,0,0)
(0,1,0) (1,1,0) (2,1,10) (3,1,10)
(0,2,0) (1,2,10) (2,2,10) (3,2,0)
```

**Regla de conversión:**
- `x = columna` en el archivo
- `y = fila` en el archivo
- `z = valor` de elevación

Esto crea una malla de puntos donde cada coordenada representa tanto una posición como un vector desde el origen.

### Paso 2: Transformaciones geométricas

#### Las rotaciones como transformaciones lineales

Una rotación en 2D es la transformación más fundamental. Para rotar un vector `v = (x,y)` por un ángulo θ:

**Demostración paso a paso:**

Primero, expresemos el vector en coordenadas polares:
```
x = r·cos(α)
y = r·sin(α)
```

Después de rotar θ grados, el nuevo ángulo es `α + θ`:
```
x' = r·cos(α + θ)
y' = r·sin(α + θ)
```

Aplicando las identidades trigonométricas:
```
cos(α + θ) = cos(α)cos(θ) - sin(α)sin(θ)
sin(α + θ) = sin(α)cos(θ) + cos(α)sin(θ)
```

Sustituyendo:
```
x' = r·cos(α)cos(θ) - r·sin(α)sin(θ)
y' = r·sin(α)cos(θ) + r·cos(α)sin(θ)
```

Como `r·cos(α) = x` y `r·sin(α) = y`:
```
x' = x·cos(θ) - y·sin(θ)
y' = x·sin(θ) + y·cos(θ)
```

**Implementación en código:**
```c
void rotate_2d(float *x, float *y, float angle) {
    float original_x = *x;
    float original_y = *y;

    *x = original_x * cos(angle) - original_y * sin(angle);
    *y = original_x * sin(angle) + original_y * cos(angle);
}
```

#### Extensión a 3D: Rotaciones por planos

En 3D, las rotaciones ocurren en planos, no alrededor de ejes. Cada rotación 3D es una rotación 2D en un plano específico:

```c
// Rotación en plano YZ (X permanece fijo)
void rotate_x(float *y, float *z, float angle) {
    float old_y = *y;
    float old_z = *z;

    *y = old_y * cos(angle) - old_z * sin(angle);
    *z = old_y * sin(angle) + old_z * cos(angle);
    // x no cambia - es perpendicular al plano YZ
}
```

**¿Por qué funciona esto?**

Si imaginamos mirar desde el eje X hacia el origen, vemos el plano YZ como un plano 2D normal. La rotación "alrededor del eje X" es realmente una rotación *en el plano YZ*.

#### El salto conceptual a 4D

**Aquí está la clave:** En 4D no hay "ejes de rotación". Solo hay planos de rotación.

```
Dimensión | Planos de rotación posibles
----------|---------------------------
2D        | 1 plano: XY
3D        | 3 planos: XY, XZ, YZ
4D        | 6 planos: XY, XZ, XW, YZ, YW, ZW
```

Cada rotación 4D usa **exactamente la misma fórmula** que las rotaciones 2D:

```c
// Rotación en plano XW (la cuarta dimensión)
void rotate_xw(float *x, float *w, float angle) {
    float prev_x = *x;
    float prev_w = *w;

    *x = prev_x * cos(angle) - prev_w * sin(angle);
    *w = prev_x * sin(angle) + prev_w * cos(angle);
    // y, z permanecen inalteradas
}
```

### Paso 3: Proyecciones - Reduciendo dimensiones

#### Proyección 4D → 3D: Perspectiva dimensional

Para visualizar objetos 4D, necesitamos "aplastarlos" a 3D usando proyección perspectiva:

**Demostración geométrica:**

Imaginemos un observador en la posición `(0,0,0,d)` en la cuarta dimensión, mirando hacia el "plano" W=0:

```
Observador ---------> Plano W=0
(0,0,0,d)            (x',y',z',0)
            \
             \
              \
               Punto P(x,y,z,w)
```

Por triángulos semejantes:
```
distancia_proyectada / distancia_real = distancia_observador / distancia_total

x' / x = d / (d - w)

Por tanto: x' = x × d / (d - w)
```

Lo mismo aplica para y' y z'. El factor de proyección es:
```
factor = d / (d - w)
```

**Implementación:**
```c
void project_4d_to_3d(t_point *point, float distance) {
    float factor = distance / (distance - point->w);

    point->x *= factor;
    point->y *= factor;
    point->z *= factor;
    // w se descarta después de la proyección
}
```

#### Proyección 3D → 2D: Múltiples sistemas

**1. Proyección Isométrica**

La proyección isométrica preserva las proporciones y es ideal para análisis técnico:

```c
// Ángulos que hacen que X, Y, Z se vean igualmente inclinados
float iso_angle = 30.0 * M_PI / 180.0; // 30 grados en radianes

iso_x = (x - y) * cos(iso_angle);  // ≈ 0.866
iso_y = (x + y) * sin(iso_angle) - z;  // ≈ 0.5
```

**¿Por qué 30 grados?**

En una proyección isométrica verdadera, los tres ejes X, Y, Z forman ángulos de 120° entre sí cuando se proyectan al plano 2D. Esto requiere que cada eje tenga una inclinación de 30° respecto a la horizontal.

**2. Proyección Perspectiva**

Simula cómo vemos los objetos en la realidad - los objetos más lejanos se ven más pequeños:

```c
void project_perspective(t_point *point, float distance) {
    float factor = distance / (distance - point->z);

    point->x *= factor;
    point->y *= factor;
    // z se usa para el cálculo pero no se renderiza
}
```

**3. Proyecciones Ortogonales**

Proyecciones "puras" que eliminan una dimensión:

```c
// Vista superior (elimina Z)
top_x = x;
top_y = y;

// Vista frontal (elimina Y)
front_x = x;
front_y = z;

// Vista lateral (elimina X)
side_x = z;
side_y = y;
```

---

## 🔮 Explorando la geometría 4D

### ¿Qué significa "4D"?

```
1D: Una línea
•————————•

2D: Un cuadrado
•————————•
|        |
|        |
•————————•

3D: Un cubo
    •————————•
   /|       /|
  / |      / |
 •————————•  |
 |  •—————|——•
 | /      | /
 |/       |/
 •————————•

4D: Un tesseract
(Imposible de dibujar directamente)
```

### Objetos 4D implementados

| Objeto | Vértices | Descripción | Analogía |
|--------|----------|-------------|----------|
| **Tesseract** | 16 | Hipercubo 4D | Como un cubo, pero con una dimensión extra |
| **Pentachoron** | 5 | Simplejo 4D | El análogo 4D de un triángulo/tetraedro |
| **Hexacosicoron** | 120 | Polítopo complejo | Una "esfera" hecha de 600 tetraedros |

### Construyendo un tesseract

Un tesseract se construye tomando dos cubos y conectando sus vértices correspondientes:

```c
// Cubo 1: W = -1
{-1,-1,-1,-1}, {1,-1,-1,-1}, {1,1,-1,-1}, {-1,1,-1,-1},
{-1,-1,1,-1},  {1,-1,1,-1},  {1,1,1,-1},  {-1,1,1,-1},

// Cubo 2: W = +1
{-1,-1,-1,1},  {1,-1,-1,1},  {1,1,-1,1},  {-1,1,-1,1},
{-1,-1,1,1},   {1,-1,1,1},   {1,1,1,1},   {-1,1,1,1}
```

Cada vértice del primer cubo se conecta con su correspondiente en el segundo cubo, creando un objeto 4D.

---

## 🎨 El motor de renderizado

### Algoritmo de líneas vectoriales

Para conectar dos puntos proyectados, uso una versión optimizada del algoritmo de Bresenham con interpolación de colores:

```c
void draw_line(t_point start, t_point end, t_fdf *data) {
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int steps = max(dx, dy);

    // Interpolación paramétrica
    for (int i = 0; i <= steps; i++) {
        float t = (float)i / steps;

        int x = start.x + t * (end.x - start.x);
        int y = start.y + t * (end.y - start.y);
        int color = interpolate_color(start.color, end.color, t);

        put_pixel(data, x, y, color);
    }
}
```

### Mapeo automático de colores

Para visualizar elevaciones, mapeo automáticamente alturas a colores:

```c
int	interpolate_color(int color1, int color2, float t)
{
	t_color	c;

	c.r1 = (color1 >> 16) & 0xFF;
	c.g1 = (color1 >> 8) & 0xFF;
	c.b1 = (color1) & 0xFF;
	c.r2 = (color2 >> 16) & 0xFF;
	c.g2 = (color2 >> 8) & 0xFF;
	c.b2 = (color2) & 0xFF;
	c.r = c.r1 + (int)((c.r2 - c.r1) * t);
	c.g = c.g1 + (int)((c.g2 - c.g1) * t);
	c.b = c.b1 + (int)((c.b2 - c.b1) * t);
	return ((c.r << 16) | (c.g << 8) | c.b);
}
```

### El pipeline completo

```c
t_point project_point(t_point point, t_map map, t_cam cam) {
    // 1. Rotaciones 4D (si es un objeto 4D)
    if (map.type == OBJECT_4D) {
        rotate_xy(&point.x, &point.y, cam.angle_xy);
        rotate_xz(&point.x, &point.z, cam.angle_xz);
        rotate_xw(&point.x, &point.w, cam.angle_xw);
        rotate_yz(&point.y, &point.z, cam.angle_yz);
        rotate_yw(&point.y, &point.w, cam.angle_yw);
        rotate_zw(&point.z, &point.w, cam.angle_zw);

        // Proyección 4D → 3D
        project_4d_to_3d(&point, cam.distance_4d);
    }

    // 2. Escalado (zoom)
    point.x *= cam.zoom;
    point.y *= cam.zoom;
    point.z *= cam.zoom;

    // 3. Centrado del objeto
    if (map.type == TOPOGRAPHIC_MAP) {
        point.x -= map.width / 2;
        point.y -= map.height / 2;
    }

    // 4. Rotaciones 3D
    rotate_x(&point.y, &point.z, cam.pitch);
    rotate_y(&point.x, &point.z, cam.yaw);
    rotate_z(&point.x, &point.y, cam.roll);

    // 5. Proyección 3D → 2D
    switch(cam.projection) {
        case ISOMETRIC:
            project_isometric(&point);
            break;
        case PERSPECTIVE:
            project_perspective(&point, cam.distance_3d);
            break;
        case ORTHOGONAL:
            project_orthogonal(&point, cam.view_direction);
            break;
    }

    // 6. Translación a pantalla
    point.x += cam.center_x;
    point.y += cam.center_y;

    return point;
}
```

---

## 🚀 Instalación y uso

### Compilación

```bash
git clone [tu-repositorio] fdf
cd fdf
make
```

### Ejemplos de uso

```bash
# Mapas topográficos
./fdf maps/42.fdf          # Logo de 42 School
./fdf maps/julia.fdf       # Conjunto de Julia (fractal)
./fdf maps/pyramide.fdf    # Pirámide simple

# Objetos 4D
./fdf tesseract            # Hipercubo 4D
./fdf pentachoron         # Simplejo 4D
./fdf hexacosicoron       # Polítopo complejo
```

### Controles interactivos

**Navegación 3D:**
- `↑↓←→`: Rotación pitch/yaw
- `< >`: Rotación roll
- `Mouse drag`: Translación libre
- `Mouse wheel`: Zoom

**Navegación 4D:**
- `W/S`: Rotación planos XY + ZW
- `A/D`: Rotación planos XZ + YW
- `Q/E`: Rotación planos YZ + XW

**Proyecciones:**
- `I`: Isométrica
- `P`: Perspectiva
- `T`: Vista superior
- `F`: Vista frontal
- `L`: Vista lateral

---

## 🔬 Análisis de rendimiento

### Complejidad computacional

**Por cada frame:**
- Transformación por punto: O(1) operaciones vectoriales
- Total: O(n) donde n = número de puntos
- Para mapas grandes (500×500): ~25ms en hardware moderno

### Optimizaciones implementadas

1. **Precálculo trigonométrico**: `sin()` y `cos()` se calculan una vez por frame
2. **Eliminación de divisiones**: Uso multiplicación por inversos precalculados
3. **Interpolación vectorizada**: Operaciones SIMD cuando es posible
4. **Clipping inteligente**: Solo renderizo puntos visibles

---

## 💭 Reflexiones técnicas

### Lecciones aprendidas

**1. La elegancia de las matemáticas unificadas**

Descubrir que las rotaciones 4D usan exactamente la misma fórmula que las rotaciones 2D fue revelador. No hay "magia" en las dimensiones superiores - son extensiones naturales de principios simples.

**2. La importancia de la visualización**

Ver cómo un tesseract "respira" mientras rota en 4D ayuda a entender conceptos que son imposibles de imaginar directamente. La visualización no es solo útil - es esencial para la comprensión.

**3. El poder de la abstracción vectorial**

Tratar cada punto como un vector permite operaciones elegantes y composables. Las transformaciones se vuelven funciones matemáticas limpias en lugar de código imperativo complicado.

### Aplicaciones en el mundo real

Este proyecto conecta directamente con:

- **Computer Graphics**: Pipelines de renderizado, transformaciones de cámara
- **Machine Learning**: Visualización de espacios de características multidimensionales
- **Realidad Virtual**: Proyecciones estereoscópicas, tracking de movimiento
- **Análisis de datos**: Representación visual de datasets complejos
- **Ingeniería**: CAD, simulaciones físicas, análisis estructural

---

## 🎯 Conclusión

FDF comenzó como un proyecto de visualización de mapas topográficos y evolucionó hacia una exploración profunda de la geometría multidimensional. A través de la implementación de transformaciones vectoriales, proyecciones y algoritmos de renderizado, no solo creé una herramienta funcional, sino que desarrollé una comprensión intuitiva de conceptos matemáticos fundamentales.

El proyecto demuestra que las matemáticas complejas se vuelven accesibles cuando se construyen paso a paso desde principios básicos, y que la visualización es una herramienta poderosa para entender abstracciones que desafían la intuición.

---

**Mikel Garrido** - 42 Barcelona

*"Convirtiendo matemáticas abstractas en experiencias visuales comprensibles"*
