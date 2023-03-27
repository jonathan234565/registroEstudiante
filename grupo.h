#ifndef GRUPO_H
#define GRUPO_H
#include <QList>
#include "estudiante.h"

class Grupo{
private:
    int grupo;
    QList<Estudiante*> listaEstudiantesGrupo;

public:
    Grupo(){
        grupo = 0;
        listaEstudiantesGrupo;
    };
    Grupo (int _grupo, QList<Estudiante*> _listaEstudiantesGrupo){
        grupo = _grupo;
        listaEstudiantesGrupo = _listaEstudiantesGrupo;
    }

    int getNumGrupo();
    double getPromedioGrupo();
    Estudiante* getEstudiante(int i);
    QList<Estudiante*> getEstudiantes();

    void ordenarApellidos();
    void ordenarPromedios();
    void ordenarEdad();
    void ordenarCarnet();

    void setGrupo(int _grupo);
    void setEstudiante(Estudiante* _estudiante);
};

#endif // GRUPO_H
