#include "grupo.h"
#include <cmath>
#include "algorithm"

bool comparacionAscendente(int a,int b){
    return a<b;
}

int Grupo::getNumGrupo(){
    return grupo;
}

Estudiante* Grupo::getEstudiante(int i){
    return listaEstudiantesGrupo[i];
}

QList<Estudiante*> Grupo::getEstudiantes(){
    return listaEstudiantesGrupo;
}

double Grupo::getPromedioGrupo(){
    double sumatoria;
    for(int i = 0; i<listaEstudiantesGrupo.size();i++){
        sumatoria += listaEstudiantesGrupo[i]->get_notas().get_promedio();
    }
    return round((sumatoria/listaEstudiantesGrupo.size())*100)/100;
}

void Grupo::ordenarApellidos(){
    std::sort(*listaEstudiantesGrupo.begin(),*listaEstudiantesGrupo.end(),[](const Estudiante &anterior, const Estudiante &actual){
        return anterior.get_apellidos() < actual.get_apellidos(); ///Por raro que parezca hace la comparacion internamente por valor que corresponde a letra
        });
}         ///Devuelvo la lista de estudiantes del grupo especificado ordenado ascendete

void Grupo::ordenarPromedios(){
    std::sort(*listaEstudiantesGrupo.begin(),*listaEstudiantesGrupo.end(),[](Estudiante &anterior,Estudiante &actual){
        return anterior.get_notas().get_promedio() < actual.get_notas().get_promedio();
        });
}         ///Devuelvo la lista de estudiantes del grupo especificado ordenado ascendete

void Grupo::ordenarEdad(){
    std::sort(*listaEstudiantesGrupo.begin(),*listaEstudiantesGrupo.end(),[](const Estudiante &anterior, const Estudiante &actual){
        return anterior.get_edad()< actual.get_edad();
        });
}          ///Devuelvo la lista de estudiantes del grupo especificado ordenado ascendete

void Grupo::ordenarCarnet(){
    std::sort(*listaEstudiantesGrupo.begin(),*listaEstudiantesGrupo.end(),[](const Estudiante &anterior, const Estudiante &actual){
        return anterior.get_carnet() < actual.get_carnet();
        });
}           ///Devuelvo la lista de estudiantes del grupo especificado ordenado ascendete

void Grupo::setGrupo(int _grupo){
    grupo = _grupo;
}

void Grupo::setEstudiante(Estudiante* _estudiante){
    listaEstudiantesGrupo.append(_estudiante);
}
