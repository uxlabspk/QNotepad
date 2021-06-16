#include "wizard.h"
#include "ui_wizard.h"

Wizard::Wizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::Wizard)
{
    ui->setupUi(this);
    ui->FileLocation->setText(qApp->applicationDirPath());
    ui->Defaultconstructor->setChecked(true);
    Default = true;
}
Wizard::~Wizard()
{
    delete ui;
}

void Wizard::on_browse_clicked()
{
    Location = QFileDialog::getExistingDirectory(this,"Select the location");
    ui->FileLocation->setText(Location);
}

void Wizard::on_Classname_editingFinished()
{
    fileName = ui->Classname->text();
    headerName = fileName + ".h";
    ui->HeaderName->setText(headerName);
    mainName = fileName + ".cpp";
    ui->FileName->setText(mainName);
}

void Wizard::on_Defaultconstructor_clicked()
{
    Default = true;
}

void Wizard::on_Parametrizedconstructor_clicked()
{
    Default = false;
}

void Wizard::on_Wizard_finished()
{
    Generate();
}
void Wizard::Generate()
{
    //---------------------------Header-----------------------------------//
    QString data;
    if(Default == true)
    {
        data = "#include<iostream>\nusing namespace std;\n\nclass " + fileName + "\n{\n   private:\n"
        "\n\n   public:\n\t" + fileName + "();\n\t" + "~" + fileName + "();\n" + "};";
    }
    else if(Default == false)
    {
        data = "#include<iostream>\nusing namespace std;\n\nclass " + fileName + "\n{\n   private:\n"
        "\n\n   public:\n\t" + fileName + "();\n\t" + "~" + fileName + "();\n\t" + fileName + "(/*Argument's goes here*/);\n\t" + "\n};";
    }
    QString filename = Location + "/" + headerName;
    QFile file(filename);
    file.open(QIODevice::WriteOnly | QFile::Text);
    QTextStream out(&file);
    out << data;
    file.close();
    //---------------------------Implementaion-------------------------------//
    QString data1;
    if(Default == true)
    {
        data1 = "#include\"" + headerName + "\"\n\n" + fileName + "::" + fileName + "()\n{\n\n}\n" +
        "~" + fileName + "::" + fileName + "()\n{\n\n}";
    }
    else if(Default == false)
    {
        data1 = "#include\"" + headerName + "\"\n\n" + fileName + "::" + fileName + "()\n{\n\n}\n"
        + fileName + "::" + fileName + "(/*Argument's goes here*/)" + "\n{\n\n}\n" + "~" + fileName + "::" + fileName + "()\n{\n\n}";
    }
    QString filename1 = Location + "/" + mainName;
    QFile file1(filename1);
    file1.open(QIODevice::WriteOnly | QFile::Text);
    QTextStream out1(&file1);
    out1 << data1;
    file1.close();
    //-------------------------------------------main----------------------------//
    QString data2;
    data2 = "#include \"" + headerName + "\"\n" + "#include <iostream>\nusing namespace std;\n\nint main()\n{\n\t" + ui->Classname->text() + " a;\n\treturn 0;\n}";
    QString filename2 = Location + "/main.cpp" ;
    QFile file2(filename2);
    file2.open(QIODevice::WriteOnly | QFile::Text);
    QTextStream out2(&file2);
    out2 << data2;
    file2.close();
}
