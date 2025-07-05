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

## ⚡ Lo que hace el programa

### 📍 Mapas 3D: De números a montañas
Convierte archivos `.fdf` (que son básicamente tablas de números) en visualizaciones 3D:

```
Archivo .fdf:              →        Visualización 3D:
0  1  2  3                              ____
1  2  3  4                             /    \
2  3  4  5                            /      \
3  4  5  6                           /        \
                                    /__________\
Cada número = altura del terreno    Resultado: Una montaña en 3D
```

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

### 🎨 Características visuales automáticas
- **Gradiente de colores inteligente**: 
  ```
  Violeta (bajo) → Azul → Verde → Amarillo → Dorado (alto)
     ■■■■        ■■■■    ■■■■     ■■■■      ■■■■
  ```
- **5 sistemas de proyección** diferentes para ver el mismo objeto
- **Navegación intuitiva**: Como un videojuego moderno

---

## 🧮 Fundamentos matemáticos profundos

### Mi enfoque al problema: De coordenadas a píxeles

Cuando empecé este proyecto, me enfrenté a dos desafíos principales:

```
🎯 Problema 1: ¿Cómo obtener las coordenadas de objetos 4D?
🎯 Problema 2: ¿Cómo proyectar esas coordenadas en la pantalla?
```

**Mi estrategia:**
1. **Primero conseguir las coordenadas** de cada vértice (3D o 4D)
2. **Luego aplicar rotaciones** para poder "ver" el objeto desde diferentes ángulos
3. **Finalmente proyectar** esas coordenadas rotadas en la pantalla 2D

### Parte 1: Derivación completa de rotaciones 2D

**El problema fundamental:** Rotar un punto `P(3, 4)` por 45°. No existe una función mágica para esto.

#### Paso 1: La intuición geométrica

```
   Y
   ↑
   |     • P(3,4)
   |    /|
   |   / |  
   |  /  |4    r = √(3² + 4²) = 5
   | /   |     θ = arctan(4/3) ≈ 53.13°
   |/____→ X
   O  3
```

**Idea clave:** Cualquier punto se puede expresar como:
- Distancia desde el origen: `r = √(x² + y²)`
- Ángulo con el eje X: `θ = arctan(y/x)`

#### Paso 2: Coordenadas polares

```
x = r × cos(θ)  →  3 = 5 × cos(53.13°) ✓
y = r × sin(θ)  →  4 = 5 × sin(53.13°) ✓
```

#### Paso 3: Rotar = Sumar ángulos

Para rotar α grados, el nuevo ángulo es `θ + α`:

```
x' = r × cos(θ + α)
y' = r × sin(θ + α)
```

#### Paso 4: El truco matemático crucial

Aplicar las identidades trigonométricas:

```
cos(θ + α) = cos(θ)cos(α) - sin(θ)sin(α)
sin(θ + α) = sin(θ)cos(α) + cos(θ)sin(α)
```

#### Paso 5: La derivación completa

```
x' = r×cos(θ)×cos(α) - r×sin(θ)×sin(α)
y' = r×sin(θ)×cos(α) + r×cos(θ)×sin(α)

Como x = r×cos(θ) e y = r×sin(θ):

x' = x×cos(α) - y×sin(α)  ← ¡Fórmula de rotación!
y' = x×sin(α) + y×cos(α)
```

#### Verificación con ejemplo:
```
Rotar P(3,4) por 90°:
x' = 3×cos(90°) - 4×sin(90°) = 3×0 - 4×1 = -4
y' = 3×sin(90°) + 4×cos(90°) = 3×1 + 4×0 = 3

Resultado: P'(-4, 3) ✓ (Un cuarto de vuelta)
```

### Conexión con matrices

Mi derivación es **exactamente** la matriz de rotación:

```
⎡ cos(α)  -sin(α) ⎤   ⎡ x ⎤   ⎡ x×cos(α) - y×sin(α) ⎤
⎢ sin(α)   cos(α) ⎥ × ⎢ y ⎥ = ⎢ x×sin(α) + y×cos(α) ⎥
⎣                 ⎦   ⎣   ⎦   ⎣                     ⎦
```

**Conclusión fundamental:** Las matrices son solo notación elegante. Lo importante es entender el **origen geométrico**.

### Parte 2: Extensión a 3D

Para 3D, aplico la misma lógica pero por ejes separados:

```c
// Rotación alrededor del eje Z (como en 2D, Z no cambia)
void rotate_z(float *x, float *y, float angle) {
    float old_x = *x, old_y = *y;
    *x = old_x * cos(angle) - old_y * sin(angle);
    *y = old_x * sin(angle) + old_y * cos(angle);
    // Z permanece intacta
}

// Rotación alrededor del eje X (Y y Z cambian)
void rotate_x(float *y, float *z, float angle) {
    float old_y = *y, old_z = *z;
    *y = old_y * cos(angle) - old_z * sin(angle);
    *z = old_y * sin(angle) + old_z * cos(angle);
    // X permanece intacta
}
```

### Parte 3: El salto conceptual a 4D

**Aquí viene lo fascinante:** En 4D no hay "ejes de rotación". Hay **planos de rotación**.

```
3D: Rotas ALREDEDOR de un eje    4D: Rotas DENTRO de un plano

    Z                                 4D tiene 6 planos posibles:
    ↑                                 XY, XZ, XW, YZ, YW, ZW
    |                                 
    • ←→ Y                           Cada plano se comporta
   /                                  exactamente como 2D
  X                                  
```

**La revelación:** Rotar en cualquier plano 4D es **idéntico** a la rotación 2D:

```c
// Rotación en plano XW (4ª dimensión)
void rotate_xw(float *x, float *w, float angle) {
    float old_x = *x, old_w = *w;
    *x = old_x * cos(angle) - old_w * sin(angle);
    *w = old_x * sin(angle) + old_w * cos(angle);
    // Y y Z no se tocan
}

// Rotación en plano YZ (normal en 3D)
void rotate_yz(float *y, float *z, float angle) {
    float old_y = *y, old_z = *z;
    *y = old_y * cos(angle) - old_z * sin(angle);
    *z = old_y * sin(angle) + old_z * cos(angle);
    // X y W no se tocan
}
```

**¡Es la misma fórmula que derivé para 2D!** Solo cambio las variables que participan.

### Parte 4: Los objetos 4D y sus peculiaridades

#### El Tesseract: Un cubo en 4D

```
Cómo construir un tesseract:
1. Toma un cubo 3D
2. "Extrúdelo" en la 4ª dimensión
3. Conecta cada vértice con su "gemelo" 4D

Resultado:
- 16 vértices (8 originales + 8 "extruidos")
- 32 aristas (12×2 del cubo + 8 conexiones 4D)
- 24 caras cuadradas
- 8 "celdas" cúbicas
```

En mi código, genero las coordenadas así:

```c
// Los 8 vértices del cubo original (w = -1)
{ -1, -1, -1, -1 }, { 1, -1, -1, -1 }, { 1, 1, -1, -1 }, ...
// Los 8 vértices del cubo "extruido" (w = +1)  
{ -1, -1, -1,  1 }, { 1, -1, -1,  1 }, { 1, 1, -1,  1 }, ...
```

#### El Pentachoron: Simplicidad en 4D

```
Es el equivalente 4D de un triángulo:
- 2D: triángulo (3 vértices)
- 3D: tetraedro (4 vértices) 
- 4D: pentachoron (5 vértices)

Cada vértice está conectado con todos los demás.
Es la figura 4D más simple posible.
```

### Parte 5: La matemática de las proyecciones

#### Proyección 4D → 3D: Perspectiva dimensional

Para mostrar objetos 4D, uso **proyección perspectiva** desde la 4ª dimensión:

```
Concepto: Los objetos "más lejos" en W se ven más pequeños

Fórmula matemática:
    factor = distancia / (distancia - point.w)
    
Aplicación:
    point.x *= factor
    point.y *= factor  
    point.z *= factor
```

**Demostración matemática:**

```
Si tengo un punto P(x,y,z,w) en 4D y quiero proyectarlo a 3D:

1. Imagino que mi "ojo" está en la coordenada W = distancia
2. Los rayos de luz van desde P hasta mi ojo
3. La proyección es donde ese rayo intersecta el "plano de proyección" W = 0

Geometricamente:
   Ojo(0,0,0,d) ←——————— P(x,y,z,w)
                    ↓
                Proyección(x',y',z',0)

Por triángulos semejantes:
   x'/x = (d-0)/(d-w) = d/(d-w)
   
Por tanto: x' = x × d/(d-w)
```

#### Proyección 3D → 2D: Cinco sistemas diferentes

**1. Proyección Isométrica**

```
Es una proyección ortogonal especial que preserva las proporciones:

    iso_x = (x - y) × cos(30°)
    iso_y = (x + y) × sin(30°) - z

¿Por qué 30°? Es el ángulo que hace que los ejes X, Y, Z 
se vean con la misma inclinación en pantalla.

Demostración visual:
     Y
     ↑  ╱ Z
     | ╱
     |╱____→ X
     
En isométrica se ve como:
       ╱
      ╱
     ╱____
    ╱     ╲
   ╱_______╲
```

**2. Proyección en Perspectiva (POV)**

```
¡La misma matemática que 4D→3D!

factor = distancia / (-z + distancia)
x' = x × factor
y' = y × factor

¿Por qué -z? Por convención, Z negativo significa "alejándose" 
de la cámara.
```

**Curiosidad matemática:** La proyección POV y la proyección 4D→3D usan **exactamente** la misma fórmula. Es perspectiva pura: "lo que está lejos se ve pequeño".

**3-5. Proyecciones Ortogonales**

```
Superior:  x' = x, y' = y  (ignora Z)
Frontal:   x' = x, y' = z  (ignora Y) 
Lateral:   x' = z, y' = y  (ignora X)
```

### Parte 6: Mi proceso de desarrollo

#### Fase 1: Conseguir las coordenadas

```c
// Para mapas 3D: Leer archivo .fdf
for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
        map->points[y][x].x = x;        // Columna
        map->points[y][x].y = y;        // Fila  
        map->points[y][x].z = valor;    // Altura del archivo
        map->points[y][x].w = 0;        // No hay 4ª dimensión
    }
}

// Para objetos 4D: Coordenadas matemáticas predefinidas
static t_point tesseract_points[16] = {
    {-1, -1, -1, -1}, {1, -1, -1, -1}, {1, 1, -1, -1}, ...
};
```

#### Fase 2: Aplicar rotaciones

```c
t_point project_point(t_point point, t_map map, t_cam cam) {
    // Si es 4D, primero rotar en los 6 planos 4D
    if (map.type == OBJECT_4D) {
        rotate_xy(&point.x, &point.y, cam.delta);   // Plano XY
        rotate_xz(&point.x, &point.z, cam.epsilon); // Plano XZ  
        rotate_xw(&point.x, &point.w, cam.theta);   // Plano XW (4D)
        rotate_yz(&point.y, &point.z, cam.gamma);   // Plano YZ
        rotate_yw(&point.y, &point.w, cam.iota);    // Plano YW (4D)
        rotate_zw(&point.z, &point.w, cam.phi);     // Plano ZW (4D)
        
        // Proyectar 4D → 3D
        project_4d_to_3d(&point);
    }
    
    // Aplicar zoom
    point.x *= cam.zoom;
    point.y *= cam.zoom;
    point.z *= cam.zoom;
    
    // Rotaciones 3D estándar
    rotate_x(&point.y, &point.z, cam.alpha);  // Pitch
    rotate_y(&point.x, &point.z, cam.beta);   // Yaw
    rotate_z(&point.x, &point.y, cam.gamma);  // Roll
    
    // Proyectar 3D → 2D según el modo seleccionado
    project_3d_to_2d(&point, cam.projection);
    
    // Trasladar al centro de la pantalla
    point.x += cam.x_offset + WINDOW_WIDTH/2;
    point.y += cam.y_offset + WINDOW_HEIGHT/2;
    
    return point;
}
```

#### Fase 3: Renderizar en pantalla

```c
// El algoritmo de Bresenham para dibujar líneas suaves
void draw_line(t_point a, t_point b, t_fdf *data) {
    // Calcular diferencias
    int dx = abs(b.x - a.x);
    int dy = abs(b.y - a.y);
    
    // ... algoritmo optimizado ...
    
    // Interpolar colores a lo largo de la línea
    int color = interpolate_color(a.color, b.color, t);
    put_pixel(data, x, y, color);
}
```

### ¿Por qué las rotaciones nos permiten "interpretar" el 4D?

**La clave conceptual:** Nuestro cerebro no puede visualizar 4D directamente, pero **sí puede percibir movimiento y cambio**.

Cuando roto un tesseract en tiempo real:
1. **Cada frame** muestra una "sombra" 2D diferente del objeto 4D
2. **El movimiento** revela la estructura que no podemos ver estáticamente
3. **Nuestro cerebro** integra estas "sombras" en una comprensión del objeto completo

Es como usar una linterna para explorar una cueva oscura: cada momento ilumina una parte diferente, pero el movimiento te da la imagen completa.

---

## 🎮 Cómo usar el programa

### ⌨️ Controles básicos

| Acción | Tecla | ¿Qué hace matemáticamente? |
|--------|-------|---------------------------|
| **Rotar X/Y** | `↑↓←→` | Modifica ángulos α (pitch) y β (yaw) |
| **Rotar Z** | `< >` | Modifica ángulo γ (roll) |
| **Mover** | Mouse + arrastrar | Cambia x_offset, y_offset |
| **Zoom** | Scroll | Multiplica factor de escala |
| **Altura** | `+/-` | Escala coordenada Z del terreno |

### 🎭 Cambiar perspectiva

| Vista | Tecla | Proyección matemática |
|-------|-------|--------------------|
| **Isométrica** | `I` | `x'=(x-y)×cos(30°), y'=(x+y)×sin(30°)-z` |
| **Superior** | `T` | `x'=x, y'=y` |
| **Frontal** | `F` | `x'=x, y'=z` |
| **Lateral** | `L` | `x'=z, y'=y` |
| **Perspectiva** | `P` | `factor=d/(-z+d), x'=x×factor` |

### 🌀 Controles 4D (solo objetos 4D)

| Rotación | Teclas | Planos matemáticos |
|----------|--------|--------------------|
| **Combo 1** | `W/S` | XZ + YW (rotaciones acopladas) |
| **Combo 2** | `A/D` | XY + ZW (rotaciones acopladas) |

*Los controles 4D mueven múltiples planos simultáneamente para crear efectos visuales hipnóticos*

---

## 🚀 Instalación y prueba

### Compilar y ejecutar
```bash
git clone [tu-repositorio] fdf
cd fdf
make

# Probar con mapas 3D
./fdf maps/42.fdf
./fdf maps/mars.fdf
./fdf maps/julia.fdf

# Probar objetos 4D
make 4d
```

---

## 👨‍💻 Reflexión final

Este proyecto me enseñó que **las matemáticas complejas son simples** cuando las entiendes paso a paso.

### Los "¡aha!" moments clave:

1. **Rotaciones 4D = Rotaciones 2D:** El mismo principio se aplica, solo cambias las variables
2. **Perspectiva es universal:** La misma fórmula funciona para 4D→3D y 3D→2D  
3. **El movimiento revela estructura:** Las rotaciones nos permiten "ver" dimensiones imposibles
4. **Derivar > Memorizar:** Entender el origen de las fórmulas es más poderoso que memorizarlas

### Conexión con mi futuro:

Ahora, cuando veo papers de ML con espacios de 1000 dimensiones, o algoritmos de computer vision con transformaciones complejas, ya no me intimidan. Son solo extensiones de los mismos principios fundamentales que derivé aquí.

**La geometría es el lenguaje universal de la matemática aplicada.**

---

**Mikel Garrido** - 42 Barcelona
