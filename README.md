# 9515Algo2Juarez

![FIUBA](https://raw.githubusercontent.com/joel-perez/9515Algo2Juarez/master/img/logo_fiuba.png)

Algoritmos y Programación II - Juarez - 2do Cuatrimestre 2019

# Trabajo Práctico N 2: :skull: "Virus Z"

# Objetivo

Desarrollar un programa que basándose en el Trabajo Practico N 1, que cree los objetos de entrada y permita una visualización de los mismos.

# Descripción

¡El país está infestado de un nuevo tipo de influenza o gripe! No se sabe exactamente cuándo comenzó la epidemia pero si se conocen las causas de la misma.
Las primeras semanas de la infección fueron nefastas, pero afortunadamente nuestros brillantes científicos e ingenieros han ideado un procedimiento que permitiría revertir la enfermedad causada por el virus Z (tal como lo han llamado ciertos medios amarillistas).
El proceso de infección cuando el virus Z ingresa al organismo humano infecta inicialmente a unas pocas células sanas (S).
En el interior, las células actúan como lugares de anclaje para los filamentos intermedios en forma de cuerda, los cuales forman una red estructural en el citoplasma.
Mediante estas uniones los filamentos intermedios de las células adyacentes están conectados formando una red continua que se extiende a todo el tejido.

Con el paso del tiempo las células Z van infectando a las células sanas S más cercanas, convirtiéndolas en células enfermas (En futuros TPs daremos más información acerca de la modalidad de este contagio).
Además del estado Z, las células infectadas tienen dos estados previos: X e Y (considerados también en el TP N 1).
Las células cambian el estado de gravedad con el paso del tiempo: del estado X pasan al Y, y luego al Z.
Una vez en estado Z comienza el contagio a sus células vecinas, convirtiendo a todas ellas en estado X.
Si la célula Z no tiene vecinas a quien contagiar, termina la serie de contagios (ver imagen).

![Celulas](https://raw.githubusercontent.com/joel-perez/9515Algo2Juarez/master/img/grafo_celulas.png)

Algunas de las características de las células son:

- Tamaño (dato tenido en cuenta en el TP N 1)
- Cantidad de enzimas.
- Cantidad de proteínas.
- Material genético: Indica el ADN, o ácido desoxirribonucleico.
- Organismo unicelular: Indica si la célula forma parte de un organismo pluricelular o no.

Adicionalmente, las células X e Y tienen como característica adicional:

- %Inflamación

Y las células Z (Además de las características de las X e Y):
- %Mutación

Un organismo infectado puede sobrevivir con algunas de estas células infectadas, pero si en algún momento la proporción de células Z en el organismo supera a la proporción de células sanas, el proceso se torna irreversible.

Afortunadamente, nuestros brillantes científicos e ingenieros han aunado esfuerzos y han dado con una insólita solución a este problema.
Utilizando lo último en nanotecnología, han ideado una nave miniatura a la cual llaman NanoBot, que es capaz de inyectarse en el torrente sanguíneo del organismo infectado y combatir desde allí las células Z. Para ello, nuestros infectologos han desarrollado dos tipos de suero-munición.

Uno capaz de destruir células que se aplica cuando el NanoBot entra en contacto con alguna célula de la red. Lamentablemente, si esta munición se aplica a células sanas, también las destruye.
Otro, capaz de replicar células con el objetivo de aumentar la proporción de células sanas en el organismo. Esta munición tampoco distingue entre células Z y células sanas, y en consecuencia si se dispara contra una célula Z, esta también se replica.

Al suero destructivo lo llamaremos suero A y al constructivo suero B (tal como se mencionaron en el TP N1). Cuando una dosis de suero A se aplica a una célula, genera un proceso de debilitación en la misma.
Si la célula era de tipo Z, esta pasa a ser del tipo que denominamos Y, y si era de tipo Y, pasa a ser de tipo X.
Finalmente si es de tipo X y le aplicamos una dosis de suero A, la célula se destruye por completo.
Así, mediante sucesivos impactos de esta munición, es posible destruir una célula Z.
Lamentablemente, si aplicamos el suero A a una célula sana, la misma se destruye inmediatamente.

Por otro lado, si una célula es impactada por el suero B, la misma pasa al tipo siguiente en gravedad.
Si la célula es ya sana, entonces la célula realiza un proceso de mitosis, convirtiéndose en dos células sanas, pero si aplicamos incorrectamente este suero a una célula enferma, empeora su tipo (si era X, pasa a Y; si era Y pasa a Z; y si era Z, se duplica).

Ambos sueros pueden aplicarse mediante el armamento con el que cuenta el NanoBot, pero la cantidad de dosis está limitada a 15 disparos para cada suero.
Una vez utilizadas todas las dosis se debe esperar un tiempo determinado para que automáticamente se generen nuevas dosis a ser utilizadas.

El cuerpo humano es un organismo extraordinario y los infectólogos han notado que algunos organismos han comenzado a desarrollar anticuerpos, capaces de revertir el proceso de la influenza convirtiendo directamente a las células Z en células sanas nuevamente.
Estos anticuerpos son generados cada tanto y a intervalos de tiempo irregulares.
Además, los anticuerpos no poseen inteligencia como para encontrar células Z por si solos, sino que se transportan por el organismo en forma errática hasta dar con alguna de estas células malignas.
Al contacto con una de ellas, el anticuerpo es consumido por la misma, la cual se convierte automáticamente en una célula sana.
Con el fin de utilizar el NanoBot para guiar a los anticuerpos hacia las células Z, el grupo de ingenieros ha agregado al NanoBot un nuevo instrumental capaz de atrapar los anticuerpos y arrastrarlos con la nave hasta donde se desee.
Los anticuerpos pueden luego desprenderse del NanoBot para permitirles continuar con su camino.
Afortunadamente, al desprender de la nave a un anticuerpo, este sigue en la misma dirección que traía la misma y a la misma velocidad, con lo cual podemos utilizar el NanoBot para "dirigir" los anticuerpos hacia las células Z.

# Datos de entrada

Se deberá leer el archivo de texto de la forma descripta en el TP N 1 y crear los objetos en las cantidades y con las características que describa dicho archivo.

# Salida

La aplicación debe, luego de procesar el archivo de entrada, crear todos los objetos involucrados, ubicándolos al momento de su creación en un vector polimórfico. Adicionalmente se debe poder recorrer el vector, mostrando las características de los objetos creados, permitiéndole al usuario consultarlos mediante la opción "mostrar" desde línea de comando.

# Aclaraciones

- Las mismas consideradas en el TP N 1.
- El diseño del reporte de los objetos creados, al igual que la definición del comportamiento de los objetos, quedan a libre decisión del equipo de trabajo.
- Para el desarrollo de este TP no se debe considerar el armado de la red citoplasma.

# Normas de entrega

Se deberá subir un archivo comprimido al campus, en un link que se habilitará para esta entrega. Este archivo deberá tener un nombre formado de la siguiente manera:

NombreGrupo-TP2

Deberá contener solo los archivos fuente.

La fecha de entrega vence el día lunes 14/10/19 a las 23.55hs.

Se evaluará: funcionalidad, eficiencia, algoritmo utilizado, buenas prácticas de programación (como nombres, sangrías, etc.), modularización, comentarios.

Puntaje: 10 puntos.