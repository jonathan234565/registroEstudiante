#ifndef REGISTROESTUDIANTE_H
#define REGISTROESTUDIANTE_H

#include <QMainWindow>
#include "estudiante.h"
#include "grupo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RegistroEstudiante; }
QT_END_NAMESPACE

class RegistroEstudiante : public QMainWindow
{
    Q_OBJECT

public:
    void imprimirItem(int i);
    void imprimirEstudiantesGrupo(int grupo);
    RegistroEstudiante(QWidget *parent = nullptr);
    ~RegistroEstudiante();



private slots:
    void on_pushButtonAgregarEstudiante_clicked();

    void on_pushButtonAgregarEstudianteGrupo_clicked();

    void on_pushButtonAgregarNotas_clicked();

    void on_pushButtonModificarInformacion_clicked();

    void on_pushButtonMostrarPromedio_clicked();

    void on_pushButtonMostrarLista_clicked();

    void on_pushButtonMostrarPromedioGrupo_clicked();

private:
    QList<Grupo> listaGrupos;
    QList<Estudiante> listaEstudiantes;
    Ui::RegistroEstudiante *ui;
};
#endif // REGISTROESTUDIANTE_H
