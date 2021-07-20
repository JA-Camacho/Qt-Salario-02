#include "principal.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Crea un objeto para manejar las traducciones
    QTranslator traduccion;

    //Tomar el lenguaje y pais local de la computadora
    QString lenguajeLocal = QLocale::system().name();

    //Creamos una lista separando el idioma y el pais
    QStringList lenguaje = lenguajeLocal.split("_");

    //Evaluar el idioma por defecto de la computadora
    if(lenguaje.at(0) == "ru")
        //Cargar un idioma
        traduccion.load(":/traducciones/Traducciones/Qt_Salario-02_ru_RU.qm");
    else if(lenguaje.at(0) == "en")
        traduccion.load(":/traducciones/Traducciones/Qt_Salario-02_en_US.qm");
    else
        traduccion.load(":/traducciones/Traducciones/Qt_Salario-02_es_EC.qm");

    //Establecer un idioma a la aplicacion*/
    a.installTranslator(&traduccion);
    Principal w;
    w.show();
    return a.exec();
}
