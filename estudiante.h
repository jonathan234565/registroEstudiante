#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <QString>
#include "nota.h"


class Estudiante
{
private:
    QString nombre = "";
    QString apellidos = "";
    float edad;
    int carnet;
    int grupo;
    Nota mis_notas;

public:
    Estudiante() {
        nombre = "Pablo";
        apellidos = "Lars";
        edad = 0;
        carnet = 12345;
        grupo = 2;
        mis_notas = Nota();
        }

        Estudiante(QString _nombre,QString _apellidos, float _edad, int _carnet,int _grupo, Nota _mis_notas) {
            nombre = _nombre;
            apellidos = _apellidos;
            edad = _edad;
            carnet = _carnet;
            grupo = _grupo;
            mis_notas = _mis_notas;
        }

    QString get_nombre() const;
    QString get_apellidos() const;
    float get_edad() const;
    int get_carnet() const;
    int get_grupo() const;
    Nota& get_notas();

    void set_nombre(QString _nombre);
    void set_apellidos(QString _apellidos);
    void set_edad(float _edad);
    void set_carnet(int _carnet);
    void set_grupo(int _grupo);
    void set_notas(Nota _mis_notas);
    void agregar_notas();

};

#endif // ESTUDIANTE_H
