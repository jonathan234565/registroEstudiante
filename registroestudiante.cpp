#include "registroestudiante.h"
#include "./ui_registroestudiante.h"

RegistroEstudiante::RegistroEstudiante(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegistroEstudiante)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(9);
    QStringList titulos;
    titulos <<"Grupo"<<"Nombre"<<"Apellidos"<<"Edad"<<"Carnet"<<"Matematica"<<"Español"<<"Ciencias"<<"Sociales";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
}

RegistroEstudiante::~RegistroEstudiante()
{
    delete ui;
}

void RegistroEstudiante::imprimirItem(int i){

    int fila = ui->tableWidget->rowCount();

    ui->tableWidget->insertRow(fila);
    ///ui->tableWidget->setItem(fila,0,new QTableWidgetItem(QString::number(listaEstudiantes[i].get_grupo())));
    ui->tableWidget->setItem(fila,1,new QTableWidgetItem(listaEstudiantes[i].get_nombre()));
    ui->tableWidget->setItem(fila,2,new QTableWidgetItem(listaEstudiantes[i].get_apellidos()));
    ui->tableWidget->setItem(fila,3,new QTableWidgetItem(QString::number(listaEstudiantes[i].get_edad())));
    ui->tableWidget->setItem(fila,4,new QTableWidgetItem(QString::number(listaEstudiantes[i].get_carnet())));
    ui->tableWidget->setItem(fila,5,new QTableWidgetItem(QString::number(listaEstudiantes[i].get_notas().getMate())));
    ui->tableWidget->setItem(fila,6,new QTableWidgetItem(QString::number(listaEstudiantes[i].get_notas().getEspa())));
    ui->tableWidget->setItem(fila,7,new QTableWidgetItem(QString::number(listaEstudiantes[i].get_notas().getCiencias())));
    ui->tableWidget->setItem(fila,8,new QTableWidgetItem(QString::number(listaEstudiantes[i].get_notas().getSociales())));

    ui->tableWidget->insertRow(fila+1);
}

void RegistroEstudiante::imprimirEstudiantesGrupo(int grupo){
    QList<Estudiante*> ptrListaOrdenada = listaGrupos[grupo].getEstudiantes();

    for(int i = 0; i<ptrListaOrdenada.size();i++){
        int fila = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(fila);
        ui->tableWidget->setItem(fila,1,new QTableWidgetItem(QString::number(grupo)));
        ui->tableWidget->setItem(fila,1,new QTableWidgetItem(ptrListaOrdenada[i]->get_nombre()));
        ui->tableWidget->setItem(fila,2,new QTableWidgetItem(ptrListaOrdenada[i]->get_apellidos()));
        ui->tableWidget->setItem(fila,3,new QTableWidgetItem(QString::number(ptrListaOrdenada[i]->get_edad())));
        ui->tableWidget->setItem(fila,4,new QTableWidgetItem(QString::number(ptrListaOrdenada[i]->get_carnet())));
        ui->tableWidget->setItem(fila,5,new QTableWidgetItem(QString::number(ptrListaOrdenada[i]->get_notas().getMate())));
        ui->tableWidget->setItem(fila,6,new QTableWidgetItem(QString::number(ptrListaOrdenada[i]->get_notas().getEspa())));
        ui->tableWidget->setItem(fila,7,new QTableWidgetItem(QString::number(ptrListaOrdenada[i]->get_notas().getCiencias())));
        ui->tableWidget->setItem(fila,8,new QTableWidgetItem(QString::number(ptrListaOrdenada[i]->get_notas().getSociales())));
    }ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void RegistroEstudiante::on_pushButtonAgregarEstudiante_clicked()
{
    Estudiante estudiante;
    estudiante.set_nombre(ui->lineEditNombre->text());
    estudiante.set_apellidos(ui->lineEditApellidos->text());
    estudiante.set_edad(ui->lineEditEdad->text().toInt());
    estudiante.set_carnet(ui->lineEditCarnet->text().toInt());
    listaEstudiantes.append(estudiante);

    imprimirItem(listaEstudiantes.size()-1);

    ui->lineEditNombre->clear();
    ui->lineEditApellidos->clear();
    ui->lineEditEdad->clear();
    ui->lineEditCarnet->clear();
}


void RegistroEstudiante::on_pushButtonAgregarEstudianteGrupo_clicked()
{
    bool error = false;
    bool encontrado = false;
    int carnet = ui->lineEditCarnetGrupo->text().toInt();
    int numeroGrupo = ui->lineEditGrupoAgregar->text().toInt();

    ui->labelAviso->clear();

    for(int i=0; i<listaEstudiantes.size();i++){        ///Busco en los alumnos
        if (carnet == listaEstudiantes[i].get_carnet()){
            Estudiante* ptrEstudiante = &listaEstudiantes[i];

            encontrado = true;
            for(int j=0; j<listaGrupos.size();j++){      ///Busco si ya existe el grupo
                if(numeroGrupo == listaGrupos[j].getNumGrupo()){
                    listaGrupos[j].setEstudiante(ptrEstudiante); ///Adentro del set se hace el append
                    ui->labelAviso->setText("Estudiante agregado a grupo existente");
                    imprimirItem(i);           ///Imprimo con el valor de i que se refiere a la lista general
                    error = true;
                    break;
                }
            }
            if(error == false){ ///Ya termino de buscar y no lo encontro
                Grupo grupo; ///Lo creo aqui porque hay un tema con las listas, aunque ingrese una copia a la lista los cambios en la variable externa puede causar errores. Me gustaría entender porque
                grupo.setEstudiante(ptrEstudiante); ///Le meto un elemento estudiante a la lista de estudiantes dentro de grupo
                grupo.setGrupo(numeroGrupo);
                listaGrupos.append(grupo); ///Si no existe creo un nuevo objeto grupo
                ui->labelAviso->setText("Estudiante agregado a nuevo grupo");
                imprimirItem(i);           ///Imprimo con el valor de i que se refiere a la lista general
                error = true;
                break;
            }
        }
    }if (encontrado==false)
        ui->labelAviso->setText("Carnet no se encuentra asociado a un estudiante");
    ui->lineEditGrupoAgregar->clear();
    ui->lineEditCarnetGrupo->clear();
}


void RegistroEstudiante::on_pushButtonAgregarNotas_clicked()
{
    Nota nota;
    bool encontrado = false;
    int carnet = ui->lineEditCarnetNotas->text().toInt();
    ///int numeroGrupo = ui->lineEditGrupoAgregar->text().toInt();

     ui->labelAviso->clear();

    for(int i=0; i<listaEstudiantes.size();i++){      ///Busco el estudiante
        if(carnet == listaEstudiantes[i].get_carnet()){
            nota.setMate(ui->lineEditMate->text().toDouble());
            nota.setEspa(ui->lineEditEspa->text().toDouble());
            nota.setCiencias(ui->lineEditCiencias->text().toDouble());
            nota.setSociales(ui->lineEditSociales->text().toDouble());
            listaEstudiantes[i].set_notas(nota);  ///Le meto las notas al estudiante
            ui->labelAviso->setText("Notas agregadas exitosamente");
            imprimirItem(i);           ///Imprimo con el valor de i que se refiere a la lista general
            encontrado = true;
            break;
        }
    }if (encontrado == false) ///No se encuentra el carnet registrado en la lista de estudiantes
        ui->labelAviso->setText("Carnet no se encuentra asociado a un estudiante");

    ui->lineEditCarnetNotas->clear();
    ui->lineEditMate->clear();
    ui->lineEditEspa->clear();
    ui->lineEditCiencias->clear();
    ui->lineEditSociales->clear();
}


void RegistroEstudiante::on_pushButtonModificarInformacion_clicked()
{
    QString parametroModificar = ui->comboBoxModificar->currentText();
    bool encontrado = false;
    int carnet = ui->lineEditCarnetModificar->text().toInt();

     ui->labelAviso->clear();

    for(int i=0; i<listaEstudiantes.size();i++){      ///Busco el estudiante
        if(carnet == listaEstudiantes[i].get_carnet()){
            encontrado = true;
            if(parametroModificar == "Nombre"){
                listaEstudiantes[i].set_nombre(ui->lineEditNuevoValor->text());
                ui->labelAviso->setText("Nombre modificado exitosamente");
                imprimirItem(i);
                break;

            }else if(parametroModificar == "Apellidos"){
                listaEstudiantes[i].set_apellidos(ui->lineEditNuevoValor->text());
                ui->labelAviso->setText("Apellidos modificados exitosamente");
                imprimirItem(i);

            }else if(parametroModificar == "Edad"){
                listaEstudiantes[i].set_edad(ui->lineEditNuevoValor->text().toInt());
                ui->labelAviso->setText("Edad modificada exitosamente");
                imprimirItem(i);
                break;

            }else if(parametroModificar == "Carnet"){
                listaEstudiantes[i].set_carnet(ui->lineEditNuevoValor->text().toInt());
                ui->labelAviso->setText("Carnet modificado exitosamente");
                imprimirItem(i);
                break;

            }else if(parametroModificar == "Grupo"){
                listaEstudiantes[i].set_grupo(ui->lineEditNuevoValor->text().toInt());  ///Esta tengo que revisarla
                ui->labelAviso->setText("Grupo modificado exitosamente");
                imprimirItem(i);
                break;

            }else if(parametroModificar == "Nota Matematicas"){
                listaEstudiantes[i].get_notas().setMate(ui->lineEditNuevoValor->text().toDouble());
                ui->labelAviso->setText("Nota matematica modificada exitosamente");
                imprimirItem(i);
                break;

            }else if(parametroModificar == "Nota Español"){
                listaEstudiantes[i].get_notas().setEspa(ui->lineEditNuevoValor->text().toDouble());
                ui->labelAviso->setText("Nota español modificada exitosamente");
                imprimirItem(i);
                break;

            }else if(parametroModificar == "Nota Ciencias"){
                listaEstudiantes[i].get_notas().setCiencias(ui->lineEditNuevoValor->text().toDouble());
                ui->labelAviso->setText("Nota ciencias modificada exitosamente");
                imprimirItem(i);
                break;

            }else if(parametroModificar == "Nota Sociales"){
                listaEstudiantes[i].get_notas().setSociales(ui->lineEditNuevoValor->text().toDouble());
                ui->labelAviso->setText("Nota sociales modificada exitosamente");
                imprimirItem(i);
                break;

            }
        }
    }if (encontrado == false) ///No se encuentra el carnet registrado en la lista de estudiantes
        ui->labelAviso->setText("Carnet no se encuentra asociado a un estudiante");
    ui->lineEditCarnetModificar->clear();
    ui->lineEditNuevoValor->clear();
}


void RegistroEstudiante::on_pushButtonMostrarPromedio_clicked()
{
    int carnet = ui->lineEditCarnetMostrarPromedio->text().toInt();
    bool encontrado = false;

    ui->labelAviso->clear();

    for(int i=0; i<listaEstudiantes.size();i++){      ///Busco el estudiante
        if(carnet == listaEstudiantes[i].get_carnet()){
            encontrado = true;
            ui->labelAviso->setText("El promedio del estudiante es: " + QString::number(listaEstudiantes[i].get_notas().get_promedio()));

        }if (encontrado == false) ///No se encuentra el carnet registrado en la lista de estudiantes
            ui->labelAviso->setText("Carnet no se encuentra asociado a un estudiante");
        ui->lineEditCarnetMostrarPromedio->clear();
        ui->lineEditNuevoValor->clear();
    }
}


void RegistroEstudiante::on_pushButtonMostrarLista_clicked()
{
    QString parametroListar = ui->comboBoxListarGrupo->currentText();
    bool encontrado = false;
    int grupo = ui->lineEditGrupoListar->text().toInt();

    ui->labelAviso->clear();

    for(int i=0; i<listaGrupos.size();i++){      ///Busco el estudiante
        if(grupo == listaGrupos[i].getNumGrupo()){
            ui->labelAviso->setText("Grupo encontrado en la base de datos");
            encontrado = true;
            if(parametroListar == "Apellidos"){
                listaGrupos[i].ordenarApellidos();
                imprimirEstudiantesGrupo(i);
                                               ///Aqui le meto la lista ordenada a la funcion de imprimir
                                               ///Depues de este puedo meter otro condicional para cambiar el orden
                                               ///Eso me recuerda que debo hacer la opcion de eliminar estudiante
                                               ///de grupo, eliminar grupo y las validaciones, lo escribo aqui para
                                               /// recordarlo
                                               /// Una validacion importante es evitar tener dos objetos con el mismo
                                               /// carnet y actualizar los cambios a los objetos en el grupo
                                               /// Tambien ver la manera de conseguir el numero de grupo si existe al
                                               /// imprimir item

                break;

            }else if(parametroListar == "Promedio"){
                listaGrupos[i].ordenarPromedios();
                imprimirEstudiantesGrupo(i);

            }else if(parametroListar== "Edad"){
                listaGrupos[i].ordenarEdad();
                imprimirEstudiantesGrupo(i);
                break;

            }else if(parametroListar == "Carnet"){
                listaGrupos[i].ordenarCarnet();
                imprimirEstudiantesGrupo(i);
                break;
            }
        }

    }if(encontrado == false)
        ui->labelAviso->setText("Grupo no se encuentra en la base de datos");
}

void RegistroEstudiante::on_pushButtonMostrarPromedioGrupo_clicked()
{
    int grupo = ui->lineEditGrupoPromedio->text().toInt();
    bool encontrado = false;

    ui->labelAviso->clear();

    for(int i=0; i<listaGrupos.size();i++){      ///Busco el estudiante
        if(grupo == listaGrupos[i].getNumGrupo()){
            encontrado = true;
            ui->labelAviso->setText("El promedio del grupo es: " + QString::number(listaGrupos[i].getPromedioGrupo()));

        }if (encontrado == false) ///No se encuentra el carnet registrado en la lista de estudiantes
            ui->labelAviso->setText("Carnet no se encuentra asociado a un estudiante");
        ui->lineEditGrupoPromedio->clear();
    }
}

