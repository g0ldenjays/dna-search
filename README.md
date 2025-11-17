# DNA Search

### Iván Gallardo, Noviembre 2025

---

## Descripción general

**DNA Search** es una implementación en C de un **indexador genómico basado en un árbol cuaternario (trie 4-ario)**, diseñado para procesar secuencias de ADN y permitir consultas eficientes sobre genes de longitud fija.

El programa construye una estructura jerárquica donde cada nivel del árbol representa una base nitrogenada (A, C, G, T), y las hojas almacenan las posiciones exactas en las que aparece cada gen dentro de la secuencia cargada.

Se trata de un proyecto académico orientado a estructuras de datos, manejo de memoria, modularización y diseño de sistemas de búsqueda basados en tries.

---

## Compilación del programa

1. Descargue o clone el repositorio.
2. Abra una terminal y diríjase al directorio donde se encuentran los archivos.
3. Ejecute:

   ```bash
   make
   ```
4. Una vez compilado, el programa puede ejecutarse mediante:

   * En Linux / WSL:

     ```bash
     ./bio
     ```
   * En Windows (MinGW):

     ```bash
     bio.exe
     ```

El proyecto utiliza únicamente C estándar (`-std=c99`) y puede compilarse tanto en Windows como en Linux sin modificaciones adicionales.

---

## Flujo de uso del programa

1. Ejecutar el programa desde la terminal.
2. Ingresar el comando:

   ```
   start N
   ```

   donde **N ≥ 1** corresponde a la longitud del gen a indexar y a la altura del árbol cuaternario que se generará.
3. Con un archivo `adn_largo.txt` o `adn_corto.txt` en el directorio (incluido en el repositorio), ingresar:

   ```
   read adn_largo.txt
   ```

   Esto cargará la secuencia de ADN, validará su contenido y poblará el trie con todas las apariciones de genes de longitud **N**.

> En esta etapa, el programa prepara la estructura interna para permitir búsquedas posteriores mediante comandos como `search`, `all`, `max` y `min`.

---

## Detalles del archivo de entrada

* El archivo `.txt` debe contener **una única línea** con la secuencia completa de ADN, compuesta exclusivamente por los caracteres:

  ```
  A C G T
  ```
* La línea debe finalizar con un salto de línea (`Enter`), pero no debe contener espacios, tabulaciones ni caracteres adicionales.
* No deben existir líneas adicionales con contenido; cualquier línea secundaria debe permanecer vacía.

Ejemplo válido de `adn.txt`:

```
TACTAAGAAGC

```
Nótese el espacio adicional bajo la secuencia.