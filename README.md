# Laboratorio 10 – Problema de la Mochila 0/1

**Fecha de entrega:** 24 de junio de 2025, 23:59

---

## Descripción

En este laboratorio se implementa la solución al **problema de la mochila 0/1** mediante **programación dinámica**. Dado un conjunto de objetos con peso y valor, y una capacidad máxima de la mochila, se busca la combinación de objetos que maximice el valor total sin exceder el límite de peso.

---

## Objetivo

- Construir la tabla de decisión (matriz DP) paso a paso.  
- Determinar el valor máximo alcanzable para capacidad 4 lb.  
- Identificar qué objetos conforman la solución óptima.

---

## Datos del Problema

| Objeto   | Peso (lb) | Valor (\$) |
|:--------:|:---------:|:----------:|
| Guitarra |     1     |   1 500    |
| Laptop   |     3     |   2 000    |
| Estéreo  |     4     |   3 000    |
| iPhone   |     1     |   2 000    |

- **Capacidad máxima:** 4 lb

---

## Metodología

1. **Estructura DP**  
   Creamos una matriz `dp[i][w]`, donde  
   - `i` = número de objetos considerados (0..4)  
   - `w` = capacidad disponible (0..4 lb)

2. **Recurrencia**  
   Para cada objeto _i_ y capacidad _w_:

dp[i][w] = max(
dp[i-1][w], // no incluir objeto i
dp[i-1][w - peso_i] + valor_i // incluir objeto i (si cabe)
)


3. **Marcas**  
En cada celda registramos, además del valor máximo, una letra que indica el objeto agregado en ese paso:
- **G** = Guitarra  
- **L** = Laptop  
- **S** = Estéreo  
- **I** = iPhone  

---

## Resultados

### 1. Tabla de Decisión (DP)

| Ítem\Capacidad |  0   |     1      |     2      |      3      |       4       |
|---------------:|-----:|-----------:|-----------:|------------:|--------------:|
| **F0 (ninguno)** |  0   |     0      |     0      |     0       |      0        |
| **Guitarra (G)** |  0   | 1500 **G** | 1500 **G** | 1500 **G**  | 1500 **G**    |
| **Estéreo (S)**  |  0   | 1500 **G** | 1500 **G** | 1500 **G**  | 3000 **S**    |
| **Laptop (L)**   |  0   | 1500 **G** | 1500 **G** | 2000 **L**  | 3500 **LG**   |
| **iPhone (I)**   |  0   | 2000 **I** | 3500 **IG**| 3500 **IL** | 4000 **ILG**  |

- **Valor óptimo** (fila 4, cap 4): **\$4 000**  
- **Marcas finales**: IL → incluye **iPhone + Laptop**

### 2. Selección Óptima

- **Valor total:** \$4 000  
- **Objetos elegidos:**  
1. iPhone (1 lb, \$2 000)  
2. Laptop   (3 lb, \$2 000)  

---
