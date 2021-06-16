#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QFontComboBox>
#include <QColorDialog>
#include <QCloseEvent>
#include <QTextDocumentWriter>
#include <QProcess>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSysInfo s;
    ui->label_2->setText(s.kernelVersion());
    ui->label->setText(s.kernelType());
    ui->label_3->setText("Untitled");
    ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
    ui->plainTextEdit->setTabStopDistance(20);

    QFontComboBox* comboStyle;
    comboStyle = new QFontComboBox();
        ui->horizontalLayout->addWidget(comboStyle);
        connect(comboStyle, SIGNAL(activated(QString)),
                this, SLOT(textFamily(QString)));
    setWindowModified(ui->plainTextEdit->document()->isModified());

    QFont f;
    f.setFamily("Fira code");
    comboStyle->setCurrentFont(f);
    ui->plainTextEdit->setFont(f);

    if (QApplication::arguments().size() > 1)
    {
        filename = QApplication::arguments().at(1);
        open(filename);
        detect();
    }

    ui->lineEdit->hide();
    check = 1;

    contextMenu();
    ui->plainTextEdit_2->hide();


    connect(ui->plainTextEdit->document(), &QTextDocument::modificationChanged, this, &MainWindow::documentWasModified);
    on_actionKvantum_triggered();
}
void MainWindow::documentWasModified()
{
    QString  shownName = QFileInfo(currentFile).fileName();
    if(ui->plainTextEdit->document()->isModified())
    {
        if(shownName.isEmpty())
        {
            setWindowTitle("Untitled *");
        }
        else
        {
            setWindowTitle(shownName + " *");
        }
    }
    else
    {
        if(shownName.isEmpty())
        {
            setWindowTitle("Untitled");
        }
        else
        {
            setWindowTitle(shownName + "");
        }
    }
}
void MainWindow::contextMenu()
{
    QMenu* contextMenu = new QMenu();
    setContextMenuPolicy(Qt::ActionsContextMenu);
    QIcon copy = QIcon::fromTheme("edit-copy");
    QAction* Copy = new QAction(copy,"Copy	ctrl+C", contextMenu);
    addAction(Copy);
    connect(Copy, SIGNAL(triggered()),this,SLOT(on_actionPaste_triggered()));

    QIcon cut = QIcon::fromTheme("edit-cut");
    QAction* Cut = new QAction(cut,"Cut	ctrl+X", contextMenu);
    addAction(Cut);
    connect(Cut, SIGNAL(triggered()),this,SLOT(on_actionCut_2_triggered()));

    QIcon paste = QIcon::fromTheme("edit-paste");
    QAction* Paste = new QAction(paste,"Paste	ctrl+V", contextMenu);
    addAction(Paste);
    connect(Paste, SIGNAL(triggered()),this,SLOT(on_actionPaste_2_triggered()));

    QIcon undo = QIcon::fromTheme("edit-undo");
    QAction* Undo = new QAction(undo,"Undo	ctrl+Z", contextMenu);
    addAction(Undo);
    connect(Undo, SIGNAL(triggered()),this,SLOT(on_actionCopy_triggered()));

    QIcon redo = QIcon::fromTheme("edit-redo");
    QAction* Redo = new QAction(redo,"Redo	ctrl+R", contextMenu);
    addAction(Redo);
    connect(Redo, SIGNAL(triggered()),this,SLOT(on_actionCut_triggered()));

    QIcon selectall = QIcon::fromTheme("edit-select-all");
    QAction* Select = new QAction(selectall,"Select all	ctrl+A", contextMenu);
    addAction(Select);
    connect(Select, SIGNAL(triggered()),this,SLOT(on_actionSelect_all_triggered()));

    QIcon print = QIcon::fromTheme("document-print");
    QAction* Print = new QAction(print,"Print	ctrl+P", contextMenu);
    addAction(Print);
    connect(Print, SIGNAL(triggered()),this,SLOT(on_actionPrint_triggered()));

    QIcon search = QIcon::fromTheme("document-print-preview");
    QAction* Search = new QAction(search,"Search	ctrl+g", contextMenu);
    addAction(Search);
    connect(Search, SIGNAL(triggered()),this,SLOT(on_actionSearch_with_Google_triggered()));

    QIcon exit = QIcon::fromTheme("document-close");
    QAction* Exit = new QAction(exit,"Exit	ctrl+W", contextMenu);
    addAction(Exit);
    connect(Exit, SIGNAL(triggered()),this,SLOT(on_actionExit_triggered()));
}
void MainWindow::find()
{
    ui->lineEdit->show();
}
void MainWindow::detect()
{
    if(filename.endsWith(".cpp") || filename.endsWith(".h") || filename.endsWith(".hpp") || filename.endsWith(".java"))
    {
        on_actionC_triggered();
    }
    else if(filename.endsWith(".html"))
    {
        on_actionHTML_triggered();
    }
    else if(filename.endsWith(".py") || filename.endsWith(".qml") || filename.endsWith(".sh"))
    {
        on_actionPython_triggered();
    }
    else if(filename.endsWith(".js"))
    {
        on_actionJava_script_triggered();
    }
}
void MainWindow::open(QString name)
{
    QFile file(name);
    currentFile = name;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
         QMessageBox::warning(this, "warning" , "cannot open" + file.errorString());
         return;
    }
    QString  shownName = QFileInfo(name).fileName();
    setWindowTitle(shownName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
    ui->label_3->setText(filename);
}
void MainWindow::closeEvent(QCloseEvent *e)
{
    if (maybeSave())
        e->accept();
    else
        e->ignore();
}
bool MainWindow::maybeSave()
{
    modify = ui->plainTextEdit->document()->isModified();
    if (!modify)
        return true;
    if (currentFile.startsWith(QLatin1String(":/")))
        return true;
    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this, tr("Application"),
                               tr("The document has been modified.\n"
                                  "Do you want to save your changes?"),
                               QMessageBox::Save | QMessageBox::Discard
                               | QMessageBox::Cancel);
    if (ret == QMessageBox::Save)
        return fileSave();
    else if (ret == QMessageBox::Cancel)
        return false;
    return true;
}
bool MainWindow::fileSave()
{
    on_actionSave_triggered();
    return true;
}
void MainWindow::textFamily(QString str)
{
    ui->plainTextEdit->setFont(str);
}
void MainWindow::count()
{
    QTextEdit *textEdit = new QTextEdit(nullptr);
       textEdit->setAttribute(Qt::WA_DeleteOnClose);
       textEdit->setReadOnly(true);
       textEdit->adjustSize();
       textEdit->move(this->geometry().center() - textEdit->rect().center());
       textEdit->show();

    QString text = ui->plainTextEdit->toPlainText();
    if(text.length()-size == 1){
    if(text.length() == 1){
    if(!text.at(0).isSpace()){
        counter++;
        ui->label_2->setText(QString::number(counter));
    }}

    if(text.length()>2){
    start = text.length()-1;
    end = text.length();
    if(text.at(start-1).isSpace() && !text.at(end-1).isSpace()){
        counter++;
        ui->label_2->setText(QString::number(counter));
    }}}
    else if(text.length()-size > 1){
    counter = 0;
    if(!text.at(0).isSpace()) counter++;
        for(int i = 1; i<text.length();i++){
            if(!text.at(i).isSpace() && text.at(i-1).isSpace())
                counter++;

        }   
        textEdit->setText(QString::number(counter));
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionOpen_triggered()
{
    filename = QFileDialog::getOpenFileName(this, "open this file");
    QFile file(filename);
    currentFile = filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
         QMessageBox::warning(this, "warning" , "cannot open" + file.errorString());
         return;
    }
    QString  shownName = QFileInfo(filename).fileName();
    setWindowTitle(shownName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
    detect();
    ui->label_3->setText(filename);
}

void MainWindow::on_actionNew_triggered()
{
   if(ui->plainTextEdit->document()->isModified())
   {
       QMessageBox::StandardButton ret;
       ret = QMessageBox::warning(this, tr("Application"),
                                  tr("The document has been modified.\n"
                                     "Do you want to save your changes?"),
                                  QMessageBox::Save | QMessageBox::Discard
                                  | QMessageBox::Cancel);
       if (ret == QMessageBox::Save)
       {
           on_actionSave_triggered();
           newfile();
       }
       else if (ret == QMessageBox::Cancel)
           __W_CONTINUED;
       else if(ret == QMessageBox::Discard)
           newfile();
   }
   else
   {
       newfile();
   }
}
void MainWindow::newfile()
{
    currentFile.clear();
    ui->plainTextEdit->setPlainText(QString());
    ui->label_3->setText("Untitled");
    setWindowModified(false);
    documentWasModified();
}
void MainWindow::on_actionSave_triggered()
{
    QFile file(currentFile);
      if(!file.open(QIODevice::WriteOnly | QFile::Text))
      {
          on_actionSave_as_triggered();
      }
      QTextStream out(&file);
      QString text = ui->plainTextEdit->toPlainText();
      out << text;
      file.close();
      QString  shownName = QFileInfo(filename).fileName();
      setWindowTitle(shownName);
      ui->label_3->setText(filename);
      ui->plainTextEdit->document()->setModified(false);
      detect();
}
void MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "save this file");
        QFile file(filename);
        if(!file.open(QIODevice::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(this, "warning" , "cannot save" + file.errorString());
        }
        currentFile = filename;
        QString  shownName = QFileInfo(filename).fileName();
        setWindowTitle(shownName);
        QTextStream out(&file);
        QString text = ui->plainTextEdit->toPlainText();
        out << text;
        file.close();
        ui->label_3->setText(filename);
        detect();
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
        printer.setPrinterName("naveed");
        QPrintDialog pDialog(&printer,this);
        if(pDialog.exec() == QDialog::Rejected)
        {
            QMessageBox::warning(this, "Warning", "Cannot Print this Page!!!");
            return;
        }
        ui->plainTextEdit->print(&printer);
        QMessageBox::information(this,"information","Your page is sucessfully printed");


}
void MainWindow::printPreview(QPrinter *printer)
{
#ifndef QT_NO_PRINTER
    ui->plainTextEdit->print(printer);
#endif
}

void MainWindow::on_actionExit_triggered()
{
    MainWindow::close();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->undo();
}
void MainWindow::on_actionCut_triggered()
{
    ui->plainTextEdit->redo();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->plainTextEdit->copy();
}

void MainWindow::on_actionCut_2_triggered()
{
    ui->plainTextEdit->cut();
}

void MainWindow::on_actionPaste_2_triggered()
{
    ui->plainTextEdit->paste();
}

void MainWindow::on_actionZoom_in_triggered()
{
    ui->plainTextEdit->zoomIn();
}


void MainWindow::on_actionZoom_out_triggered()
{
    ui->plainTextEdit->zoomOut();
}

void MainWindow::on_actionRead_only_triggered(bool checked)
{
    ui->plainTextEdit->setReadOnly(checked);
}

void MainWindow::on_actionOver_write_triggered(bool checked)
{
    ui->plainTextEdit->setOverwriteMode(checked);
}

void MainWindow::on_actionSelect_all_triggered()
{
    ui->plainTextEdit->selectAll();
}

void MainWindow::on_actionHTML_triggered()
{
    h = new high(ui->plainTextEdit->document());
}

void MainWindow::on_actionC_triggered()
{
    c = new highc(ui->plainTextEdit->document());
}


void MainWindow::on_actionTo_lower_triggered()
{
    QString s;
    s = ui->plainTextEdit->toPlainText().toLower();
    ui->plainTextEdit->setPlainText(s);
}

void MainWindow::on_actionTo_Upper_triggered()
{
    QString s;
    s = ui->plainTextEdit->toPlainText().toUpper();
    ui->plainTextEdit->setPlainText(s);
}

void MainWindow::on_actionTo_HTML_escape_triggered()
{
    QString s;
    s = ui->plainTextEdit->toPlainText().toHtmlEscaped();
    ui->plainTextEdit->setPlainText(s);
}

void MainWindow::on_actionInsert_comments_triggered()
{
    QTime time = QTime::currentTime();
    QString sTime = time.toString();
    QDate d = QDate::currentDate();
    QString s = d.toString();
    QTextCursor c;
    c = ui->plainTextEdit->textCursor();
    c.insertText("/*\n *   Name  : \n * \n *   Email : \n * \n *   Date : " + s + " :: " + sTime + " \n */\n");
}

void MainWindow::on_actionInsert_date_triggered()
{
    QTime time = QTime::currentTime();
    QString sTime = time.toString();
    QDate d = QDate::currentDate();
    QString s = d.toString();
    ui->plainTextEdit->insertPlainText(s + " :: " + sTime);
}

void MainWindow::on_actionPython_triggered()
{
    p = new pyhigh(ui->plainTextEdit->document());
}

void MainWindow::on_actionRun_HTML_triggered()
{
    on_actionSave_triggered();
    if(currentFile.isEmpty())
    {
        QMessageBox::information(this,"Error","This is an empty file");
    }
    else
    {
        QUrl u = QUrl::fromLocalFile(currentFile);
        QDesktopServices s;
        s.openUrl(u);
    }
}

void MainWindow::on_actionPrint_Preview_triggered()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer, this);
    preview.setWindowFlags ( Qt::Window );
    connect(&preview, SIGNAL(paintRequested(QPrinter *)), SLOT(printPreview(QPrinter *)));
    preview.exec();
}

void MainWindow::on_actionWord_Count_triggered()
{
    count();
}
void MainWindow::on_actionRun_SPYDER_file_triggered()
{
    on_actionSave_triggered();
    if(currentFile.isEmpty())
    {
        QMessageBox::information(this,"Error","This is an empty file");
    }
    else
    {
        QString p = "python3 ";
        QString cmd = p + currentFile;
        const char* cmd1 = cmd.toLocal8Bit().constData();
        system(cmd1);
    }
}

void MainWindow::on_actionExport_to_HTML_triggered()
{
    QString f = QFileDialog::getSaveFileName(this,"Save the file",tr("Export.html"));
    QTextDocumentWriter writer(f);
    writer.write(ui->plainTextEdit->document());
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this,"About Qt");
}
void MainWindow::on_lineEdit_returnPressed()
{
    QString word = ui->lineEdit->text();
        if (word.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Search Field"),
                                     tr("The search field is empty. "
                                        "Please enter a word and click Find."));
        }
        else
        {
           ui->plainTextEdit->find(word,QTextDocument::FindFlags(QTextDocument::FindCaseSensitively));
        }
}

void MainWindow::on_actionFind_triggered()
{
    if(check == 1)
    {
        find();
        check = 0;
    }
    else
    {
        ui->lineEdit->hide();
        check = 1;
    }
}

void MainWindow::on_actionAdd_new_triggered()
{
    wizard.show();
}
void MainWindow::on_actionSearch_with_Google_triggered()
{
    QString text;
    text = ui->plainTextEdit->textCursor().selectedText();
    const QString gsearchUrl = QStringLiteral("http://www.google.com/search?q=%1");
    QString url = gsearchUrl.arg(text);
    QDesktopServices::openUrl(url);
}
void MainWindow::on_actionJava_script_triggered()
{
    js = new highjs(ui->plainTextEdit->document());
}

void MainWindow::on_actionKvantum_triggered()
{
   QStyle *style = QStyleFactory::create("Kvantum");
   QApplication::setStyle(style);
}

void MainWindow::on_actionWindows_triggered()
{
    QStyle *style = QStyleFactory::create("Windows");
    QApplication::setStyle(style);
}

void MainWindow::on_actionFusion_triggered()
{
    QStyle *style = QStyleFactory::create("Fusion");
    QApplication::setStyle(style);
}

void MainWindow::on_actionBreezr_triggered()
{
    QStyle *style = QStyleFactory::create("Breeze");
    QApplication::setStyle(style);
}

