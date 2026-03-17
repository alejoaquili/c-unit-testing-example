# Modificadores en C: `const`, `restrict` e `inline`

Documentación de los modificadores usados en punteros y funciones en este proyecto (referencias en `src/include/MemoryManager.h` y `src/MemoryManagerTest.c`).

---

## 1. `const` aplicado a punteros

La posición de `const` respecto al `*` cambia el significado.

### Puntero constante (`*const`)

```c
void *const p;
```

- **Qué es constante:** el **puntero** (la variable que guarda la dirección).
- **Qué significa:** no se puede reasignar `p`; no puedes hacer `p = otra_direccion` dentro del ámbito donde se usa.
- **Qué sí se puede:** leer y escribir la memoria apuntada (tras castear), porque lo constante es la variable puntero, no el contenido.

**En el proyecto:**

```c
// MemoryManager.h
MemoryManagerADT createMemoryManager(void *const restrict memoryForMemoryManager, void *const restrict managedMemory);
```

La función se compromete a no reasignar los parámetros `memoryForMemoryManager` ni `managedMemory`; puede usar esas direcciones para leer/escribir la memoria del memoryManager y la memoria gestionada.

### Puntero a constante (`const *`)

```c
const void *p;
// o
void const *p;
```

- **Qué es constante:** el **objeto apuntado** (no se puede modificar a través de este puntero).
- **Qué significa:** no puedes hacer `*p = valor` (ni escribir en la memoria mediante `p`); solo lectura a través de `p`.
- **Qué sí se puede:** cambiar a qué apunta `p`, es decir `p = otra_direccion`.

### Resumen rápido

| Declaración     | Puntero reasignable | Contenido modificable mediante el puntero |
|-----------------|---------------------|-------------------------------------------|
| `void *p`       | Sí                  | Sí                                        |
| `void *const p` | No                  | Sí                                        |
| `const void *p` | Sí                  | No                                        |
| `const void *const p` | No            | No                                        |

---

## 2. `restrict` (C99)

```c
void *allocMemory(MemoryManagerADT const restrict memoryManager, const size_t memoryToAllocate);
```

### Qué indica

`restrict` le dice al compilador que **ese puntero es, en el ámbito de la función (o del bloque), la única forma de acceder al objeto apuntado**. Es decir, no hay otro puntero que apunte al mismo bloque de memoria (no hay aliasing).

### Para qué sirve

- **Optimización:** el compilador puede suponer que las escrituras por un puntero `restrict` no afectan las lecturas por otro; puede mantener valores en registros y reordenar accesos con más libertad.
- **Documentación:** deja explícito que el contrato del código es “estas regiones no se solapan”.

### Responsabilidad del programador

Si pasas dos punteros que sí se solapan a parámetros marcados como `restrict`, el comportamiento queda **indefinido**. En este proyecto tiene sentido: `memoryForMemoryManager` y `managedMemory` son bloques distintos (uno para el memory manager, otro para la memoria gestionada).

---

## 3. `inline`

```c
// Declaración (en tests)
static inline void givenAMemoryManager(CuTest *const cuTest);

// Definición
inline void givenAMemoryManager(CuTest *const cuTest) {
    // ...
}
```

### Qué indica

`inline` es una **sugerencia al compilador** para que intente insertar el cuerpo de la función en el lugar de la llamada (evitando el coste de la llamada) en lugar de generar una función separada. El compilador puede ignorar la sugerencia.

### Comportamiento en C

- **C99:** una función `inline` puede tener una definición “visible” en cada unidad de compilación; si no se usa como `inline`, hace falta exactamente una definición externa (sin `inline`) en algún `.c` para el enlazado.
- **`static inline`:** la función es interna a la unidad de compilación (no se exporta). Combinar `static` con `inline` evita problemas de definiciones múltiples y suele usarse para funciones pequeñas en headers o en un solo `.c` (como ayudantes de test).

### Cuándo usarlo

- Funciones cortas y llamadas con frecuencia (por ejemplo helpers de tests como `givenAMemoryManager`, `whenMemoryIsAllocated`).
- No garantiza que la función sea “inlined”; es una pista. Para funciones solo usadas en un archivo, `static inline` es una convención clara y segura.

---

## Referencias en el proyecto

| Archivo                | Uso |
|------------------------|-----|
| `src/include/MemoryManager.h` | `void *const restrict` en `createMemoryManager`; `MemoryManagerADT const restrict` y `const size_t` en `allocMemory`. |
| `src/MemoryManagerTest.c`     | `CuTest *const` en parámetros de tests; `static inline` en declaraciones y `inline` en definiciones de helpers. |

---

## Resumen en una línea

- **`*const`:** el puntero no se reasigna.
- **`const *`:** no se modifica lo apuntado a través de ese puntero.
- **`restrict`:** solo este puntero accede a esa región; permite optimizaciones y documenta “no solapamiento”.
- **`inline`:** sugerencia de expansión en el lugar de la llamada; `static inline` para funciones internas y pequeñas.
