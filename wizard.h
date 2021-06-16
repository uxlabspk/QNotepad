#ifndef WIZARD_H
#define WIZARD_H

#include <QWizard>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Wizard;
}

class Wizard : public QWizard
{
    Q_OBJECT

public:
    explicit Wizard(QWidget *parent = nullptr);
    ~Wizard();

private slots:

    void on_browse_clicked();

    void on_Classname_editingFinished();

    void on_Defaultconstructor_clicked();

    void on_Parametrizedconstructor_clicked();

    void on_Wizard_finished();

    void Generate();

private:
    Ui::Wizard *ui;
    QString Location;
    QString fileName;
    QString headerName;
    QString mainName;
    bool Default;
};

#endif // WIZARD_H
