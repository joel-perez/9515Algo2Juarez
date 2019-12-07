# 9515Algo2Juarez

![FIUBA](https://raw.githubusercontent.com/joel-perez/9515Algo2Juarez/master/img/logo_fiuba.png)

Algoritmos y Programación II - Juarez - 2do Cuatrimestre 2019

# Trabajos Prácticos:

:microscope: Celulas, Anticuerpos y Suero

:skull: "Virus Z"

:fireworks: "Nanobot"
 
# Grupo: Sobrecargados


# Libreria SDL

## Instalacion en Linux

En una ventana de terminal, ejecutar los siguientes comandos:

```
sudo apt-cache search libsdl2

sudo apt-get update

sudo apt-get install libsdl2-dev
```

En caso que hubiera un error como el siguiente:

no se pudo bloquear /var/lib/dpkg/lock

Ejecutar el siguiente comando:

```
sudo fuser -vki  /var/lib/dpkg/lock
```

Finalmente:

```
sudo apt-get install libsdl2-ttf-dev
```

## Instalacion en Windows

Se deben descargar los siguientes archivos:

* MinGW:      https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/
* SDL2:       https://www.libsdl.org/release/SDL2-devel-2.0.10-mingw.tar.gz
* SDL2Image:  https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.5-mingw.tar.gz
* SDL2ttf:    https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.15-mingw.tar.gz
