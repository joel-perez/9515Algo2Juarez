# 9515Algo2Juarez

![FIUBA](https://raw.githubusercontent.com/joel-perez/9515Algo2Juarez/master/img/logo_fiuba.png)

Algoritmos y Programación II - Juarez - 2do Cuatrimestre 2019

# Trabajo Práctico Individual N&ordm; 1: :microscope: "Células, anticuerpos y suero"

# Objetivo
Desarrollar un programa que se ejecute por línea de comando el cual, basándose en un archivo de texto, indique el resumen y la estadística de células, anticuerpos y dosis de suero.

# Datos de entrada

El archivo de texto a leer se llamará "estado.txt", cada línea será la información de la existencia y coordenadas (x,y) de algún tipo de célula, de un anticuerpo o de alguna dosis de suero. Los datos por línea estarán separados por un espacio.

- Células: pueden ser de cuatro tipos: S, X, Y o Z.
- Anticuerpo: es único.
- Dosis de suero: pueden ser de dos tipos: A o B. Además, se indicará cuántas dosis hay.

Salvo los tipos, el resto estará escrito en minúsculas y sin acentos.
Tanto las células como los anticuerpos a leer, estarán ubicados en un tejido de longitud 1000 y alto 600. Por lo tanto, el rango de posiciones valido para cada elemento a incorporar va a depender de su tamaño.

# En general:

- Las células tienen un tamaño de 60x60:
  Su rango sera de 0 a 940 para el eje x; de 0 a 540 para el eje y

- Los anticuerpos tienen un tamaño de 28x30:
  Su rango sera de 0 a 972 para el eje x; de 0 a 570 para el eje y

- Dichas posiciones estarán dadas por números reales.

# Ejemplo:

```
celula X 10.5 10.3
celula S 100.2 10.4
celula Y 200 25.3
anticuerpo 500.32 452.4
celula Z 340.2 354.5
celula X 504.13 235.6
dosis A 20
anticuerpo 765.4 467.8
dosis B 10
dosis A 10
```

Es decir, la primer linea nos indicara que hay una celula de tipo X en la coordenada (10.5;10.3) y la ultima linea indicara que hay 10 dosis A.

# Salida

La aplicación debe, luego de procesar el archivo, mostrar un cuadro resumen con la siguiente información:

| Elemento   | Cantidad    | Porcentaje sobre el total |
| ---------- | ----------- | ------------------------- |
| Célula S   | #S          | #S / (#S + #X + #Y + #Z)  |
| Célula X   | #X          | #X / (#S + #X + #Y + #Z)  |
| Célula Y   | #Y          | #Y / (#S + #X + #Y + #Z)  |
| Célula Z   | #Z          | #Z / (#S + #X + #Y + #Z)  |
| Anticuerpo | #anticuerpo |                           |
| Dosis A    | #A          | #A / (#A + #B)            |
| Dosis B    | #B          | #B / (#A + #B)            |

Nota: el dibujo de la tabla no es necesario.

Con el ejemplo anterior quedaría:

| Elemento   | Cantidad | Porcentaje |
| ---------- | -------- | ---------- |
| Células S  | 1        | 20         |
| Células X  | 2        | 40         |
| Células Y  | 1        | 20         |
| Células Z  | 1        | 20         |
| Anticuerpo | 2        |            |
| Dosis A    | 30       | 75         |
| Dosis B    | 10       | 25         |

# Aclaraciones

- El archivo está bien formado (no tiene errores).
- El archivo admite que las células y anticuerpos están ubicados de forma tal que no hay superposición entre los mismos
- Este trabajo tiene relación con futuros trabajos prácticos.

# Normas de entrega

Se deberá subir un archivo comprimido al campus, en un link que se habilitará para esta entrega. Este archivo deberá tener un nombre formado de la siguiente manera:

ApellidoNombre-TP1

Deberá contener solo los archivos fuente.

La fecha de entrega vence el día jueves 12/09/19 a las 23.55hs.

Se evaluará: funcionalidad, eficiencia, algoritmo utilizado, buenas prácticas de programación (como nombres, sangrías, etc.), modularización, comentarios.

Puntaje: 5 puntos.