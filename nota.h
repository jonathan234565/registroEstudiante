#ifndef NOTA_H
#define NOTA_H


class Nota{
private:
    double mate;
    double espa;
    double ciencias;
    double sociales;

public:
    Nota(){
            mate = 0;
            espa = 0;
            ciencias = 0;
            sociales = 0;
        }

    Nota(double _mate, double _espa, double _ciencias, double _sociales){
            mate = _mate;
            espa = _espa;
            ciencias = _ciencias;
            sociales = _sociales;
        }

    void setMate(double _mate);
    void setEspa(double _espa);
    void setCiencias(double _ciencias);
    void setSociales(double _sociales);

    double getMate() const;
    double getEspa() const;
    double getCiencias() const;
    double getSociales() const;
    double get_promedio();

    bool aprobado_mate();
    bool aprobado_espa();
    bool aprobado_ciencias();
    bool aprobado_sociales();



};
#endif // NOTA_H
