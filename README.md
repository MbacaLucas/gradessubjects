# 🎓 Student Grade Tracker 

![C++](https://img.shields.io/badge/C++-17-blue.svg?style=flat-square&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Complete-green.svg?style=flat-square)
![Build](https://img.shields.io/badge/Build-Passing-brightgreen.svg?style=flat-square)

Un sistema de gestión académica desarrollado en C++ para el seguimiento de calificaciones estudiantiles.



## 🎯 Descripción del Proyecto
La aplicación permite registrar estudiantes y sus respectivas notas vinculadas a un catálogo de materias (Mathematics, History, Programming). El sistema no solo organiza la información, sino que calcula automáticamente el **Promedio General** del grupo utilizando algoritmos de la Standard Template Library (STL).

## 🚀 Características Técnicas
* **Arquitectura Relacional**: Implementación de `structs` vinculados (`Subject` <-> `Grade`) mediante llaves foráneas lógicas (`subjectId`).
* **Algoritmos de la STL**:
    * `std::find_if`: Búsqueda eficiente de nombres de materias mediante **Expresiones Lambda**.
    * `std::accumulate`: Procesamiento de sumas de punto flotante para cálculos estadísticos.
* **Seguridad y Robustez**:
    * Manejo de **Operadores Ternarios** para prevenir errores de división por cero (`grades.empty()`).
    * Validación exhaustiva de entrada de datos mediante bucles `do-while`.
    * Limpieza de buffers de entrada con `std::ws`.
* **Formateo Profesional**: Uso exhaustivo de `<iomanip>` (`setw`, `setprecision`, `fixed`) para generar reportes alineados y estéticos.

## 🛠️ Instalación y Uso
Requiere un compilador con soporte para **C++17**.

```bash
# Compilar el sistema de calificaciones
g++ -std=c++17 -o grade_tracker main.cpp

# Ejecutar el programa
./grade_tracker

resultado

ID   Student                  Subject        Score
=======================================================
1    Juan Perez               Mathematics    9.5
2    Maria Garcia             Programming    10.0
3    Carlos Ruiz              History        7.8
=======================================================
OVERALL AVERAGE: 9.10
