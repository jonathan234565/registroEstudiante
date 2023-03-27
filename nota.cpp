#include "nota.h"

void Nota::setMate(double _mate){
    mate = _mate;
}

void Nota::setEspa(double _espa){
    espa = _espa;
}

void Nota::setCiencias(double _ciencias){
    ciencias = _ciencias;
}

void Nota::setSociales(double _sociales){
    sociales = _sociales;
}

double Nota::getMate() const{
    return mate;
}

double Nota::getEspa() const{
    return espa;
}

double Nota::getCiencias() const{
    return ciencias;
}

double Nota::getSociales() const{
    return sociales;
}

bool Nota::aprobado_mate(){
    return mate >= 70;
}

bool Nota::aprobado_espa(){
    return espa >= 70;
}

bool Nota::aprobado_ciencias(){
    return ciencias >= 70;
}

bool Nota::aprobado_sociales(){
    return sociales >= 70;
}

double Nota::get_promedio(){
    return (mate + espa + ciencias + sociales) / 4;
}
