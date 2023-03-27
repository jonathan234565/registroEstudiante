#include "estudiante.h"

QString Estudiante::get_nombre() const{
    return nombre;
}

QString Estudiante::get_apellidos() const{
    return apellidos;
}

float Estudiante::get_edad() const{
    return edad;
}

int Estudiante::get_carnet() const{
    return carnet;
}

int Estudiante::get_grupo() const{
    return grupo;
}

Nota& Estudiante::get_notas(){
    return mis_notas;
}

void Estudiante::set_nombre(QString _nombre){
    nombre = _nombre;
}

void Estudiante::set_apellidos(QString _apellidos){
    apellidos = _apellidos;
}

void Estudiante::set_edad(float _edad){
    edad = _edad;
}

void Estudiante::set_carnet(int _carnet){
    carnet = _carnet;
}

void Estudiante::set_grupo(int _grupo){
    grupo = _grupo;
}

void Estudiante::set_notas(Nota _mis_notas){
    mis_notas = _mis_notas;
}

void Estudiante::agregar_notas(){

}
