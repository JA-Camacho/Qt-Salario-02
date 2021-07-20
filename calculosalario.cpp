#include "calculosalario.h"

CalculoSalario::CalculoSalario(QObject *parent) : QObject(parent)
{

}

CalculoSalario::CalculoSalario(Obrero &obrero)
{
    this->obrero = &obrero;
}

QString CalculoSalario::resultado()
{
    return tr("%1Salario Bruto: $%2\nDescuento: $%3\nSalario Neto: $%4\n")
            .arg(obrero->informacion())
            .arg(QString::number(m_salarioBruto, 'f', 2))
            .arg(QString::number(m_descuento, 'f', 2))
            .arg(QString::number(m_salarioNeto, 'f', 2));
}

void CalculoSalario::calcular()
{
    float valorHora = 0;
    switch(obrero->jornada())
    {
    case 'V':
        valorHora = VALOR_HORA_VESPERTINO;
        break;
    case 'M':
        valorHora = VALOR_HORA_MATUTINO;
        break;
    case 'N':
        valorHora = VALOR_HORA_NOCTURNO;
        break;
    }

    m_salarioBruto = obrero->horas() * valorHora;
    m_descuento = m_salarioBruto * PORCENTAJE_DESCUENTO/100;
    m_salarioNeto = m_salarioBruto - m_descuento;
}

float CalculoSalario::salarioBruto() const
{
    return m_salarioBruto;
}

float CalculoSalario::descuento() const
{
    return m_descuento;
}

float CalculoSalario::salarioNeto() const
{
    return m_salarioNeto;
}
