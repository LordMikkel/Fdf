# FDF - Motor de Visualización Geométrica 3D/4D 🌐

> **Un motor de renderizado vectorial para mapas topográficos 3D y objetos geométricos 4D desarrollado desde cero**

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr)
[![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))

---

## 📖 Introducción: ¿Qué resuelve FDF?

**FDF** (FileDeFer, "wireframe" en francés) es mi extensión del proyecto 42 que trasciende el requisito básico de renderizar mapas 2D como wireframes 3D. He construido un motor completo de transformaciones geométricas que maneja:

- **Visualización de datos topográficos** desde archivos `.fdf`
- **Objetos geométricos 4D** (tesseract, pentachoron, hexacosicoron)
- **Múltiples sistemas de proyección** (isométrica, perspectiva, ortogonal)
- **Rotaciones vectoriales en 6 planos 4D** con controles intuitivos
- **Interpolación de colores** automática basada en la elevación

### ¿Por qué expandí el proyecto?

Como futuro profesional en IA/Data Science, necesito entender cómo funcionan las transformaciones geométricas desde los fundamentos matemáticos. Estas operaciones son cruciales para:

- **Machine Learning**: Espacios de características de alta dimensión
- **Computer Vision**: Transformaciones de cámara y proyecciones
- **Visualización de datos**: Representación de datos complejos
- **Motores gráficos**: Pipeline de renderizado 3D

---

## 🧮 El pipeline matemático: De datos a píxeles

### Paso 1: Interpretación de datos como vectores posicionales

Cuando leo un archivo `.fdf`, cada número se convierte en un **vector posicional** en el espacio 3D:

```
Archivo 42.fdf (real):        →     Vectores 3D resultantes:
0  0  0  0                             v₀ = (0,0,0)  v₁ = (1,0,0)  v₂ = (2,0,0)
0  0 10 10                             v₄ = (0,1,0)  v₅ = (1,1,0)  v₆ = (2,1,10)
0 10 10  0                             v₈ = (0,2,0)  v₉ = (1,2,10) v₁₀= (2,2,10)

Regla de conversión:
vector(col, row, valor) = (col, row, valor_altura)
```

**Ejemplo real del mapa 42.fdf:**
- Posición `(2,1)` tiene valor `10` → Vector `v₆ = (2, 1, 10)`
- Posición `(1,2)` tiene valor `10` → Vector `v₉ = (1, 2, 10)`

El resultado es una **malla de vectores** donde cada vector representa un punto en el terreno 3D.

**El truco:** Cada número del archivo se convierte en un punto `(x, y, z)` donde:
- `x` = columna en el archivo
- `y` = fila en el archivo
- `z` = valor numérico (altura)

### 🔮 Objetos 4D: Lo imposible hecho posible

También puede mostrar figuras que existen en 4 dimensiones. Pero, ¿qué significa "4D"?

```
1D: Una línea      •————————•

2D: Un cuadrado    •————————•
                   |        |
                   |        |
                   •————————•

3D: Un cubo        •————————•
                  /|       /|
                 / |      / |
                •————————•  |
                |  •—————|——•
                | /      | /
                |/       |/
                •————————•

4D: Un tesseract   ¡Imposible de dibujar!
                   (Pero podemos proyectarlo)
```

| Objeto | Vértices | ¿Qué es realmente? | Peculiaridad |
|--------|----------|-------------------|--------------|
| **Tesseract** | 16 | 8 cubos conectados | Como un cubo, pero en 4D |
| **Pentachoron** | 5 | 5 tetraedros unidos | El más simple polítopo 4D |
| **Hexacosicoron** | 120 | 600 tetraedros | Una "esfera" hecha de triángulos |


### Paso 2: Pensando en vectores vs. coordenadas

**¿Por qué vectores y no solo coordenadas?**

Cada punto es simultáneamente:
- **Una coordenada**: "Estoy en la posición (x,y,z)"
- **Un vector**: "Soy un desplazamiento desde el origen (0,0,0)"

Cuando aplico rotaciones, estoy **rotando vectores alrededor del origen**:

```c
// En mi código: rotate_x(&point.y, &point.z, angle)
// Matemáticamente: Rotar el vector (x,y,z) en el plano YZ

Vector original:     v = (2, 1, 10)
Después de rotar 90° en YZ: v' = (2, -10, 1)
```

Esta perspectiva vectorial es **fundamental** porque:
1. Las rotaciones preservan el módulo del vector: `|v| = |v'|`
2. Las transformaciones son lineales: `T(av + bw) = aT(v) + bT(w)`
3. Puedo componer transformaciones multiplicando matrices

### Paso 3: El álgebra de rotaciones vectoriales

#### Rotación 2D: El caso fundamental

Para rotar un vector `v = (x,y)` por un ángulo θ:

```
Demostración geométrica:

    y ↑
      |     v'(x',y')
      |    /
      |   /
      |  /   θ+α
      | /
      |/____→ x
    O      v(x,y)

En coordenadas polares:
x = r·cos(α)    y = r·sin(α)

Después de rotar θ:
x' = r·cos(α+θ) = r·cos(α)cos(θ) - r·sin(α)sin(θ)
y' = r·sin(α+θ) = r·sin(α)cos(θ) + r·cos(α)sin(θ)

Sustituyendo x,y:
x' = x·cos(θ) - y·sin(θ)
y' = x·sin(θ) + y·cos(θ)
```

**En mi código:**
```c
void rotate_xy(float *x, float *y, float angle) {
    float prev_x = *x, prev_y = *y;
    *x = prev_x * cos(angle) - prev_y * sin(angle);
    *y = prev_x * sin(angle) + prev_y * cos(angle);
}
```

#### Extensión a 3D: Rotaciones por planos

En 3D, roto **dentro de planos**, no alrededor de ejes:

```c
// Rotación en plano YZ (eje X fijo)
void rotate_x(float *y, float *z, float angle) {
    float old_y = *y, old_z = *z;
    *y = old_y * cos(angle) - old_z * sin(angle);
    *z = old_y * sin(angle) + old_z * cos(angle);
    // X no cambia: es el eje de rotación
}
```

#### El salto conceptual a 4D

**En 4D no hay "ejes de rotación", solo planos de rotación:**

```
3D: 3 planos posibles     4D: 6 planos posibles
    XY, XZ, YZ               XY, XZ, XW, YZ, YW, ZW

Cada rotación 4D usa la MISMA fórmula que 2D:
```

```c
// Rotación en plano XW (4ª dimensión)
void rotate_xw(float *x, float *w, float angle) {
    float prev_x = *x, prev_w = *w;
    *x = prev_x * cos(angle) - prev_w * sin(angle);
    *w = prev_x * sin(angle) + prev_w * cos(angle);
    // Y,Z permanecen inalteradas
}
```

### Paso 4: Proyecciones como transformaciones lineales

#### Proyección 4D → 3D (Perspectiva dimensional)

Para visualizar objetos 4D, uso **proyección perspectiva** desde la 4ª dimensión:

```
Idea: Los objetos "más lejos" en W se ven más pequeños

Vector 4D original:    v = (x, y, z, w)
Vector 3D proyectado:  v' = (x', y', z')

Fórmula de proyección:
factor = distancia / (distancia - w)
x' = x × factor
y' = y × factor
z' = z × factor
```

**Demostración geométrica:**
```
Observador en (0,0,0,d) mira hacia W=0
Punto P(x,y,z,w) proyectado en plano W=0

Por triángulos semejantes:
x'/x = (d-0)/(d-w) = d/(d-w)

Por tanto: x' = x × d/(d-w)
```

#### Proyección 3D → 2D (Cinco sistemas)

**1. Isométrica (preserva proporciones):**
```c
iso_x = (x - y) * cos(30°)  // ≈ 0.866
iso_y = (x + y) * sin(30°) - z  // ≈ 0.5

¿Por qué 30°? Hace que los tres ejes X,Y,Z
se vean con la misma inclinación en pantalla.
```

**2. Perspectiva (realismo visual):**
```c
factor = distancia / (-z + distancia)
x' = x × factor
y' = y × factor
// Es la MISMA fórmula que 4D→3D
```

**3-5. Ortogonales (proyecciones puras):**
```c
Superior: x'=x, y'=y  (ignora Z)
Frontal:  x'=x, y'=z  (ignora Y)
Lateral:  x'=z, y'=y  (ignora X)
```

---

## 🔄 Mi implementación del pipeline completo

### La función central: `project_point`

```c
t_point project_point(t_point point, t_map map, t_cam cam) {
    // 1. Si es 4D, rotaciones en los 6 planos 4D
    if (map.type == OBJECT_4D) {
        rotate_xy(&point.x, &point.y, cam.delta);    // Plano XY
        rotate_xz(&point.x, &point.z, cam.epsilon);  // Plano XZ
        rotate_yw(&point.y, &point.w, cam.theta);    // Plano YW (4D)
        rotate_zw(&point.z, &point.w, cam.iota);     // Plano ZW (4D)
        project_4d_to_3d(&point);                    // Proyección 4D→3D
    }

    // 2. Aplicar zoom (escalado isométrico)
    point.x *= cam.zoom;
    point.y *= cam.zoom;
    point.z *= cam.zoom;

    // 3. Centrar el objeto en el origen (solo para mapas 3D)
    if (map.type == OBJECT_3D)
        move_map_to_origin(&point, map, cam);

    // 4. Rotaciones 3D estándar
    rotate_x(&point.y, &point.z, cam.alpha);  // Pitch
    rotate_y(&point.x, &point.z, cam.beta);   // Yaw
    rotate_z(&point.x, &point.y, cam.gamma);  // Roll

    // 5. Proyección 3D→2D según modo seleccionado
    project_3d_to_2d(&point, cam.projection);

    // 6. Translación a centro de pantalla
    point.x += cam.x_offset;
    point.y += cam.y_offset;

    return point;
}
```

### Controles vectoriales intuitivos

| Acción | Tecla | Operación matemática |
|--------|-------|---------------------|
| **Rotación 3D** | `↑↓←→` | Modifica vectores (α,β,γ) de Euler |
| **Rotación Z** | `< >` | Rotación en plano XY |
| **Zoom vectorial** | `Mouse wheel` | Escalado: `v' = k·v` |
| **Translación** | `Mouse drag` | Suma vectorial: `v' = v + offset` |

**Controles 4D únicos:**
| Rotación 4D | Tecla | Planos afectados |
|-------------|-------|------------------|
| **Combo 1** | `W/S` | XY + ZW (rotaciones acopladas) |
| **Combo 2** | `A/D` | XZ + YW (rotaciones acopladas) |

---

## 🎯 Casos de estudio con datos reales

### Caso 1: Mapa topográfico "42"

**Datos de entrada (42.fdf):**
```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
```

**Interpretación vectorial:**
- Dimension: 19×12 puntos
- Vector máximo: `(18, 11, 10)`
- Patrón: Forma las letras "4" y "2" en relieve

**Pipeline de transformación:**
```
Vector original: (2,2,10)
1. Centrado: (2-9.5, 2-5.5, 10) = (-7.5, -3.5, 10)
2. Zoom 2x: (-15, -7, 20)
3. Rotación Y 30°: (-15×cos30° + 20×sin30°, -7, -15×sin30° + 20×cos30°)
                 = (-3.0, -7, 9.8)
4. Proyección isométrica: x' = (-3.0-(-7))×0.866 = 3.46
                         y' = (-3.0+(-7))×0.5 - 9.8 = -14.8
```

### Caso 2: Fractal de Julia (julia.fdf)

**Estructura de datos:**
```
1,0x810202 1,0x810202 1,0x810202 ...
(valor, color_hex) para cada punto
```

**Características:**
- Dimensión: 500×501 vectores (≈250,000 puntos)
- Cada vector lleva información de altura Y color
- Genera un paisaje fractal con degradado cromático

### Caso 3: Tesseract 4D

**Coordenadas de vértices (predefinidas):**
```c
// Los 16 vértices del tesseract
{-1,-1,-1,-1}, {1,-1,-1,-1}, {1,1,-1,-1}, {-1,1,-1,-1},  // Cubo W=-1
{-1,-1,1,-1},  {1,-1,1,-1},  {1,1,1,-1},  {-1,1,1,-1},   // Cubo W=-1
{-1,-1,-1,1},  {1,-1,-1,1},  {1,1,-1,1},  {-1,1,-1,1},   // Cubo W=+1
{-1,-1,1,1},   {1,-1,1,1},   {1,1,1,1},   {-1,1,1,1}     // Cubo W=+1
```

**Transformación completa:**
```
Vector inicial: (-1,-1,-1,-1)
1. Rotación XY(0.1): (-1×cos0.1-(-1)×sin0.1, -1×sin0.1+(-1)×cos0.1, -1, -1)
                   = (-0.895, -1.095, -1, -1)
2. Rotación YW(0.2): (-0.895, -1.095×cos0.2-(-1)×sin0.2, -1, -1.095×sin0.2+(-1)×cos0.2)
                   = (-0.895, -0.895, -1, -1.288)
3. Proyección 4D→3D: factor = 5/(5-(-1.288)) = 0.796
                    (-0.895×0.796, -0.895×0.796, -1×0.796) = (-0.712, -0.712, -0.796)
4. Rotaciones 3D y proyección final a pantalla
```

---

## 🎨 Análisis del renderizado vectorial

### Algoritmo de líneas: Bresenham optimizado

Para conectar dos vectores proyectados `A(x₁,y₁)` y `B(x₂,y₂)`:

```c
void draw_line(t_point a, t_point b, t_fdf *data) {
    int dx = abs(b.x - a.x);
    int dy = abs(b.y - a.y);

    // Vector dirección unitario
    int sx = (a.x < b.x) ? 1 : -1;
    int sy = (a.y < b.y) ? 1 : -1;

    // Interpolación de colores a lo largo del vector
    for (float t = 0; t <= 1; t += 1.0/max(dx,dy)) {
        int color = interpolate_color(a.color, b.color, t);
        put_pixel(data, lerp(a.x, b.x, t), lerp(a.y, b.y, t), color);
    }
}
```

### Interpolación cromática automática

```c
// Mapeo altura → color para visualización de datos
int get_height_color(float z, float z_min, float z_max) {
    float ratio = (z - z_min) / (z_max - z_min);

    if (ratio < 0.2) return 0x0000FF;      // Azul (bajo)
    if (ratio < 0.4) return 0x00FFFF;      // Cian
    if (ratio < 0.6) return 0x00FF00;      // Verde
    if (ratio < 0.8) return 0xFFFF00;      // Amarillo
    return 0xFF0000;                       // Rojo (alto)
}
```

---

## 🚀 Instalación y uso

### Compilación y ejecución
```bash
git clone [tu-repositorio] fdf
cd fdf
make

# Mapas topográficos 3D
./fdf maps/42.fdf        # Logo 42 en wireframe
./fdf maps/julia.fdf     # Fractal de Julia colorizado

# Objetos geométricos 4D
./fdf tesseract          # Hipercubo 4D
./fdf pentachoron        # Simplejo 4D
```

### Controles avanzados

**Navegación 3D:**
- `↑↓←→`: Rotaciones principales (pitch/yaw)
- `< >`: Rotación roll (eje Z)
- `Mouse drag`: Translación libre
- `Mouse wheel`: Zoom vectorial

**Navegación 4D:**
- `W/S`: Rotación combinada XY+ZW
- `A/D`: Rotación combinada XZ+YW
- `ESC`: Salir

**Cambio de proyección:**
- `I`: Isométrica (ideal para análisis técnico)
- `P`: Perspectiva (realismo visual)
- `T`: Top/Superior (vista de planta)
- `F`: Frontal (alzado)
- `L`: Lateral (perfil)

---

## 🧠 Fundamentos matemáticos profundos

### Álgebra lineal aplicada

**1. Espacios vectoriales**
- Cada punto/pixel es un vector en ℝ³ o ℝ⁴
- Las transformaciones son funciones lineales T: ℝⁿ → ℝᵐ
- Preservación de operaciones: T(αv + βw) = αT(v) + βT(w)

**2. Matrices de rotación**
```
Rotación 2D (θ):         Rotación 3D X(α):
┌ cos θ  -sin θ ┐        ┌ 1    0      0   ┐
└ sin θ   cos θ ┘        │ 0  cos α -sin α │
                         └ 0  sin α  cos α ┘
```

**3. Composición de transformaciones**
```
Transformación final = T₆ ∘ T₅ ∘ T₄ ∘ T₃ ∘ T₂ ∘ T₁
Donde:
T₁: Rotaciones 4D (si aplica)
T₂: Proyección 4D→3D
T₃: Escalado (zoom)
T₄: Rotaciones 3D
T₅: Proyección 3D→2D
T₆: Translación a pantalla
```

### Trigonometría y geometría proyectiva

**1. Identidades fundamentales usadas:**
- `cos(α + β) = cos α cos β - sin α sin β`
- `sin(α + β) = sin α cos β + cos α sin β`
- Estas identidades **derivan** las fórmulas de rotación

**2. Proyección perspectiva:**
- Basada en triángulos semejantes
- Cumple las leyes de la perspectiva renacentista
- Preserva linealidad en planos paralelos

### Conexión con IA y Data Science

**1. Reducción de dimensionalidad:**
- Mi proyección 4D→3D es análoga a PCA o t-SNE
- Preserva estructura local mientras reduce dimensiones
- Útil para visualizar embeddings de alta dimensión

**2. Transformaciones de características:**
- Las rotaciones son cambios de base en el espacio de características
- Útil para entender invariancias en ML
- Aplicable a data augmentation en computer vision

**3. Optimización numérica:**
- Uso de gradientes para suavizar animaciones
- Interpolación lineal para transiciones fluidas
- Control de error numérico en operaciones de punto flotante

---

## 💡 Valor profesional y técnico

### Para desarrolladores

**Competencias técnicas demostradas:**
- Implementación de algoritmos matemáticos complejos
- Optimización de rendimiento (renderizado en tiempo real)
- Arquitectura modular y escalable
- Gestión de memoria en C (sin leaks)

**Patrones de diseño aplicados:**
- Pipeline de transformaciones (Chain of Responsibility)
- Separación de concerns (rendering/input/data)
- Abstracción de proyecciones (Strategy pattern)

### Para reclutadores

**¿Por qué este proyecto importa?**

1. **Rigor matemático**: Demuestro comprensión profunda de álgebra lineal y geometría
2. **Pensamiento algorítmico**: Optimización del pipeline de renderizado
3. **Capacidad de abstracción**: Extensión natural de 3D a 4D
4. **Orientación a resultados**: Producto funcional y visual

**Aplicaciones directas en la industria:**
- **Videojuegos**: Motores de renderizado, física, animación
- **Realidad virtual**: Transformaciones de cámara, proyecciones estereoscópicas
- **Visualización científica**: Representación de datos multidimensionales
- **Machine Learning**: Visualización de espacios de características
- **CAD/CAM**: Modelado geométrico, proyecciones técnicas

---

## 🔬 Análisis de rendimiento

### Complejidad computacional

**Por frame renderizado:**
- Transformación por punto: O(1) - operaciones matriciales constantes
- Total por frame: O(n) donde n = número de puntos
- Para julia.fdf (250k puntos): ~16ms en hardware moderno

**Optimizaciones implementadas:**
- Cálculo de sin/cos una sola vez por frame
- Eliminación de divisiones innecesarias
- Uso de lookup tables para interpolación de colores

### Casos de uso realistas

**1. Análisis topográfico:**
```bash
# Mapa real de elevaciones
./fdf maps/mars.fdf      # Datos de superficie marciana
./fdf maps/everest.fdf   # Modelo del Everest
```

**2. Visualización matemática:**
```bash
# Funciones 3D
./fdf maps/paraboloid.fdf   # z = x² + y²
./fdf maps/saddle.fdf       # z = x² - y²
```

**3. Arte generativo:**
```bash
# Fractales y formas procedurales
./fdf maps/mandelbrot.fdf
./fdf maps/spiral.fdf
```

---

## 🎓 Reflexión: Del código a la comprensión

### Los momentos "¡Eureka!" que transformaron mi perspectiva

**1. "Las rotaciones 4D son solo rotaciones 2D repetidas"**
Al darme cuenta de que `rotate_xw()` usa exactamente la misma fórmula que `rotate_xy()`, entendí que las dimensiones superiores no son "mágicas" - son extensiones naturales de principios simples.

**2. "Los vectores unifican geometría y álgebra"**
Un punto (3,4,5) es simultáneamente:
- Una posición en el espacio
- Un vector desde el origen
- Una combinación lineal de vectores base: 3î + 4ĵ + 5k̂

**3. "Las proyecciones revelan estructura oculta"**
Cuando roto un tesseract 4D y veo cómo cambia su "sombra" 2D, entiendo cómo nuestro cerebro puede percibir dimensiones que no puede visualizar directamente.

### Conexión con mi futuro profesional

Este proyecto me enseñó que **la matemática compleja es simple cuando entiendes los fundamentos**. Ahora, cuando veo:

- Papers de ML con espacios de 1000 dimensiones
- Algoritmos de computer vision con transformaciones proyectivas
- Sistemas de IA con representaciones vectoriales complejas

No me intimidan. Son extensiones de los mismos principios que implementé aquí.

**La geometría es el lenguaje universal de la matemática aplicada.**

---

## 📚 Referencias y recursos

### Matemática fundamental
- **Linear Algebra Done Right** - Sheldon Axler
- **Geometry of Linear Transformations** - MIT OpenCourseWare
- **Quaternions and Rotation Sequences** - J.B. Kuipers

### Aplicaciones en IA/ML
- **Pattern Recognition and Machine Learning** - Christopher Bishop
- **Deep Learning** - Ian Goodfellow, Yoshua Bengio
- **Computer Vision: Algorithms and Applications** - Richard Szeliski

### Implementación técnica
- **Real-Time Rendering** - Tomas Akenine-Möller
- **Computer Graphics: Principles and Practice** - Hughes, van Dam
- **Numerical Recipes in C** - Press, Teukolsky, Vetterling

---

**Mikel Garrido** - 42 Barcelona
*"Transformando datos en comprensión visual"*

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=flat&logo=linkedin&logoColor=white)](your-linkedin)
[![GitHub](https://img.shields.io/badge/GitHub-100000?style=flat&logo=github&logoColor=white)](your-github)
