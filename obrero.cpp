#include "obrero.h"

int Obrero::horas() const
{
    return m_horas;
}

QString Obrero::nombre() const
{
    return m_nombre;
}

char Obrero::jornada() const
{
    return m_jornada;
}

QString Obrero::getJornada()
{
    QString str;
    switch(jornada())
    {
    case 'V':
        str = "Vespertina";
        break;
    case 'M':
        str = "Matutina";
        break;
    case 'N':
        str = "Nocturna";
        break;
    }
    return str;
}

QString Obrero::informacion()
{
    return tr("Obrero %1\nHoras: %2\nJornada: %3\n")
            .arg(nombre())
            .arg(horas())
            .arg(getJornada());
}

Obrero::Obrero(QString nombre, int horas, char jornada)
{
    m_nombre = nombre;
    m_horas = horas;
    m_jornada = jornada;
}
