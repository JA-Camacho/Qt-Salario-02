#ifndef OBRERO_H
#define OBRERO_H

#include <QObject>

class Obrero : public QObject
{
    Q_OBJECT
private:
    int m_horas;      //Numeros de horas trabajadas
    QString m_nombre; //Nombre del Obrero
    char m_jornada;   //Jornada del Obrero
public:
    explicit Obrero(QObject *parent = nullptr);
    Obrero(QString nombre, int horas, char jornada);
    int horas() const;
    QString nombre() const;
    char jornada() const;
    QString getJornada();
    QString informacion();

signals:

};

#endif // OBRERO_H
