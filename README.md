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

### � Mapas 3D
Convierte archivos `.fdf` (que son básicamente tablas de números) en visualizaciones 3D:

```
Archivo .fdf:        →        Visualización 3D:
0  1  2  3                        /\
1  2  3  4                       /  \
2  3  4  5                      /____\
3  4  5  6
```

### 🔮 Objetos 4D imposibles
También puede mostrar figuras que existen en 4 dimensiones:

| Objeto | Vértices | ¿Qué es? |
|--------|----------|----------|
| **Tesseract** | 16 | Un "cubo" de 4D |
| **Pentachoron** | 5 | Un "triángulo" de 4D |
| **Hexacosicoron** | 120 | Una esfera de 4D |

### 🎨 Características visuales
- **Colores automáticos**: Violeta para lo bajo, dorado para lo alto
- **5 vistas diferentes**: Isométrica, frontal, lateral, superior y perspectiva
- **Navegación fluida**: Mouse para mover, scroll para zoom

---

## 🧮 La parte matemática interesante

### El problema base: ¿cómo rotar un punto?

Imagina que tienes un punto `P(3, 4)` y quieres rotarlo 45°. No hay una función mágica para esto, hay que derivar la fórmula.

### Mi proceso de demostración

**🎯 Idea clave:** Todo punto se puede expresar en coordenadas polares.

```
   Y
   ↑
   |     • P(3,4)
   |    /
   |   /
   |  /     r = √(3² + 4²) = 5
   | /      θ = arctan(4/3) ≈ 53°
   |/______→ X
   O
```

**Paso 1: Convertir el punto**
```
x = r × cos(θ) = 5 × cos(53°) = 3
y = r × sin(θ) = 5 × sin(53°) = 4
```

**Paso 2: Rotar significa sumar ángulos**
```
Nuevo ángulo = θ + α (donde α es la rotación)
x' = r × cos(θ + α)
y' = r × sin(θ + α)
```

**Paso 3: Aquí viene el truco matemático**

Uso las identidades trigonométricas:
```
cos(θ + α) = cos(θ)cos(α) - sin(θ)sin(α)
sin(θ + α) = sin(θ)cos(α) + cos(θ)sin(α)
```

**Paso 4: Sustituyo y ¡eureka!**
```
x' = r×cos(θ)×cos(α) - r×sin(θ)×sin(α)
y' = r×sin(θ)×cos(α) + r×cos(θ)×sin(α)

Como x = r×cos(θ) e y = r×sin(θ):
x' = x×cos(α) - y×sin(α)  ← ¡La fórmula final!
y' = x×sin(α) + y×cos(α)
```

### ¿Y las matrices famosas?

Mi derivación es **exactamente** la matriz de rotación:

```
⎡ cos(α)  -sin(α) ⎤   ⎡ x ⎤   ⎡ x×cos(α) - y×sin(α) ⎤
⎢ sin(α)   cos(α) ⎥ × ⎢ y ⎥ = ⎢ x×sin(α) + y×cos(α) ⎥
⎣                 ⎦   ⎣   ⎦   ⎣                     ⎦
```

**Conclusión:** Las matrices son solo una notación elegante. Lo importante es entender el **por qué**.

### Rotaciones 3D: mismo principio, más ejes

Para rotar en 3D alrededor del eje Z, uso la misma fórmula pero dejo Z intacta:

```c
void rotate_z(float *x, float *y, float angle) {
    float old_x = *x, old_y = *y;
    *x = old_x * cos(angle) - old_y * sin(angle);
    *y = old_x * sin(angle) + old_y * cos(angle);
    // Z no cambia
}
```

### Rotaciones 4D: el plot twist

**Aquí viene lo curioso:** En 4D no hay "ejes de rotación". Hay **planos de rotación**.

```
3D: Rotas ALREDEDOR de un eje    4D: Rotas DENTRO de un plano

    Z                                 4D tiene 6 planos:
    ↑                                 XY, XZ, XW, YZ, YW, ZW
    |
    • ←→ Y                           Cada plano = rotación 2D
   /
  X
```

Rotar en el plano XW es **exactamente igual** que rotar en 2D:

```c
void rotate_xw(float *x, float *w, float angle) {
    float old_x = *x, old_w = *w;
    *x = old_x * cos(angle) - old_w * sin(angle);
    *w = old_x * sin(angle) + old_w * cos(angle);
    // Y y Z no se tocan
}
```

**¡Es la misma fórmula que derivé para 2D!** Solo cambio las variables.

### El secreto de las proyecciones

Para mostrar objetos 4D en la pantalla necesito **dos proyecciones**:

**1. Proyección 4D → 3D (perspectiva)**
```c
// Imagina que estás "lejos" en la 4ª dimensión
distance = 5.0f;
factor = distance / (distance - point->w);
point->x *= factor;  // Los objetos "más profundos" en W
point->y *= factor;  // se ven más pequeños
point->z *= factor;
```

**2. Proyección 3D → 2D (POV)**
```c
// Misma idea pero desde la profundidad Z
distance = 500.0f;
factor = distance / (-point->z + distance);
point->x *= factor;  // ¡Misma fórmula!
point->y *= factor;
```

**Curiosidad:** La proyección POV y la proyección 4D→3D usan **exactamente** la misma matemática. Es perspectiva pura: "lo que está lejos se ve pequeño".

---

## 🎮 Cómo usar el programa

### ⌨️ Controles básicos

| Acción | Tecla | ¿Qué hace? |
|--------|-------|------------|
| **Rotar X/Y** | `↑↓←→` | Gira el objeto en pantalla |
| **Rotar Z** | `< >` | Gira como una rueda |
| **Mover** | Mouse + arrastrar | Desplaza la vista |
| **Zoom** | Scroll | Acerca/aleja |
| **Altura** | `+/-` | Hace el mapa más/menos montañoso |

### 🎭 Cambiar perspectiva

| Vista | Tecla | ¿Cómo se ve? |
|-------|-------|--------------|
| **Isométrica** | `I` | Como en videojuegos retro |
| **Superior** | `T` | Desde arriba (mapa 2D) |
| **Frontal** | `F` | Desde el frente |
| **Lateral** | `L` | Desde un lado |
| **Perspectiva** | `P` | Como con tus ojos |

### 🌀 Controles 4D (solo tesseract, pentachoron, etc.)

| Rotación | Teclas | Planos afectados |
|----------|--------|------------------|
| **Combo 1** | `W/S` | XZ + YW |
| **Combo 2** | `A/D` | XY + ZW |

*Los controles 4D mueven dos planos a la vez para crear efectos visuales interesantes*

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

## �‍💻 Reflexión final

Este proyecto me enseñó que **las matemáticas complejas son simples** cuando las entiendes paso a paso.

La clave no está en memorizar fórmulas, sino en **derivarlas** y ver cómo los mismos principios se aplican desde 2D hasta 4D.

Ahora, cuando veo un paper de ML con espacios de 1000 dimensiones, ya no me da miedo. Son solo muchas rotaciones 2D trabajando juntas.

---

**Mikel Garrido** - 42 Barcelona
