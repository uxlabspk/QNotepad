#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
#include <high.h>
#include <highlightcplus.h>
#include <pyhigh.h>
#include <QPrintPreviewDialog>
#include <QDesktopServices>
#include <QPlainTextEdit>
#include <highjs.h>
#include <QStyleFactory>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_2_triggered();

    void on_actionPaste_2_triggered();

    void on_actionZoom_in_triggered();

    void on_actionZoom_out_triggered();

    void on_actionRead_only_triggered(bool checked);

    void on_actionOver_write_triggered(bool checked);

    void on_actionSelect_all_triggered();

    void on_actionHTML_triggered();

    void on_actionC_triggered();

    void on_actionTo_lower_triggered();

    void on_actionTo_Upper_triggered();

    void on_actionTo_HTML_escape_triggered();

    void on_actionInsert_comments_triggered();

    void on_actionInsert_date_triggered();

    void on_actionPython_triggered();

    void on_actionRun_HTML_triggered();

    void printPreview(QPrinter *printer);

    void on_actionPrint_Preview_triggered();

    void count();

    void on_actionWord_Count_triggered();

    void textFamily(QString);

    void closeEvent(QCloseEvent *e);

    bool maybeSave();

    bool fileSave();

    void on_actionExport_to_HTML_triggered();

    void newfile();

    void on_actionAbout_Qt_triggered();

    void open(QString name);

    void detect();

    void find();

    void on_lineEdit_returnPressed();

    void on_actionFind_triggered();

    void on_actionSearch_with_Google_triggered();

    void contextMenu();

    void on_actionJava_script_triggered();

    void documentWasModified();

    void on_actionFollow_me_on_twitter_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile;
    high* h;
    highc * c;
    QString filename;
    QString name;
    pyhigh* p;
    int size = 0;
    int counter = 0;
    int start = 0;
    int end = 0;
    bool check;
    bool modify;
    QPlainTextEdit* edit;
    highjs* js;
};
#endif // MAINWINDOW_H
