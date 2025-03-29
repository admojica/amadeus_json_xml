# Employee Processor

Este es un programa de línea de comandos en C++ que procesa archivos XML y JSON con información de empleados.
Realiza las siguientes funciones:

- Calcula el salario promedio de todos los empleados.
- Identifica al empleado con el salario más alto.
- Ordena a los empleados por su ID y muestra la lista ordenada.

## Requisitos

Antes de compilar y ejecutar el programa, se deben tener instalados:

- **g++** (compilador de C++)
- **tinyxml2** (para procesar archivos XML)
- **nlohmann/json** (para procesar archivos JSON)

Se deben instalar los siguientes paquetes en macOS con Homebrew:
```sh
brew install tinyxml2
brew install nlohmann-json
```

## Compilación

El código fuente se compila con el siguiente comando:
```sh
g++ -std=c++11 -o employee_processor employee_processor.cpp -ltinyxml2
```

## Uso

Para ejecutar el programa se debe proporcionar el tipo de archivo (**xml** o **json**) y la ruta del archivo de entrada:

```sh
./employee_processor xml employees.xml
```

```sh
./employee_processor json employees.json
```


## Control de Versiones

Este proyecto usa Git para el control de versiones. Para clonar el repositorio:
```sh
git clone [<URL_DEL_REPO>](https://github.com/admojica/amadeus_json_xml)
```
