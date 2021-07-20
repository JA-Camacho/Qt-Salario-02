#ifndef ACERCA_H
#define ACERCA_H

#include <QDialog>

namespace Ui {
class Acerca;
}

class Acerca : public QDialog
{
    Q_OBJECT

public:
    explicit Acerca(QWidget *parent = nullptr);
    ~Acerca();
    QString VERSION;
    void setVersion(const QString &value);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Acerca *ui;
    QString version;
};

#endif // ACERCA_H
