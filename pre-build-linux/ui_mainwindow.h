/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionPrint;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionCut;
    QAction *actionPaste;
    QAction *actionCut_2;
    QAction *actionPaste_2;
    QAction *actionZoom_in;
    QAction *actionZoom_out;
    QAction *actionRead_only;
    QAction *actionOver_write;
    QAction *actionSelect_all;
    QAction *actionHTML;
    QAction *actionC;
    QAction *actionTo_lower;
    QAction *actionTo_Upper;
    QAction *actionTo_HTML_escape;
    QAction *actionInsert_comments;
    QAction *actionInsert_date;
    QAction *actionPython;
    QAction *actionRun_HTML;
    QAction *actionPrint_Preview;
    QAction *actionWord_Count;
    QAction *actionRun_SPYDER_file;
    QAction *actionExport_to_HTML;
    QAction *actionAbout_Qt;
    QAction *actionFind;
    QAction *actionAdd_new;
    QAction *actionSearch_with_Google;
    QAction *actionJava_script;
    QAction *actionKvantum;
    QAction *actionWindows;
    QAction *actionFusion;
    QAction *actionBreezr;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPlainTextEdit *plainTextEdit_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QMenu *menuFiles;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuTools;
    QMenu *menuHighlight;
    QMenu *menuConvert;
    QMenu *menuRun;
    QMenu *menuExport;
    QMenu *menuAbout;
    QMenu *menuProjects;
    QMenu *menuStyles;
    QMenu *menuStyle;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix2/wind/parrot.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/new/prefix2/wind/parrot.svg"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setDocumentMode(false);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        QString iconThemeName = QString::fromUtf8("document-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8(":/new/prefix2/wind/document-new.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionNew->setIcon(icon1);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8(":/new/prefix2/wind/document-open.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionOpen->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8(":/new/prefix2/wind/document-save.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionSave->setIcon(icon3);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("document-save-as");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8(":/new/prefix2/wind/document-save-as.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave_as->setIcon(icon4);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon5;
        iconThemeName = QString::fromUtf8("document-print");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8(":/new/prefix2/wind/document-print.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionPrint->setIcon(icon5);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon6;
        iconThemeName = QString::fromUtf8("document-close");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QString::fromUtf8(":/new/prefix2/wind/edit-delete.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionExit->setIcon(icon6);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon7;
        iconThemeName = QString::fromUtf8("edit-undo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QString::fromUtf8(":/new/prefix2/wind/edit-undo.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionCopy->setIcon(icon7);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon8;
        iconThemeName = QString::fromUtf8("edit-redo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QString::fromUtf8(":/new/prefix2/wind/edit-undo-rtl.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionCut->setIcon(icon8);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon9;
        iconThemeName = QString::fromUtf8("edit-copy");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QString::fromUtf8(":/new/prefix2/wind/edit-copy.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionPaste->setIcon(icon9);
        actionCut_2 = new QAction(MainWindow);
        actionCut_2->setObjectName(QString::fromUtf8("actionCut_2"));
        QIcon icon10;
        iconThemeName = QString::fromUtf8("edit-cut");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon10 = QIcon::fromTheme(iconThemeName);
        } else {
            icon10.addFile(QString::fromUtf8(":/new/prefix2/wind/edit-cut.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionCut_2->setIcon(icon10);
        actionPaste_2 = new QAction(MainWindow);
        actionPaste_2->setObjectName(QString::fromUtf8("actionPaste_2"));
        QIcon icon11;
        iconThemeName = QString::fromUtf8("edit-paste");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon11 = QIcon::fromTheme(iconThemeName);
        } else {
            icon11.addFile(QString::fromUtf8(":/new/prefix2/wind/edit-paste.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionPaste_2->setIcon(icon11);
        actionZoom_in = new QAction(MainWindow);
        actionZoom_in->setObjectName(QString::fromUtf8("actionZoom_in"));
        QIcon icon12;
        iconThemeName = QString::fromUtf8("zoom-in");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon12 = QIcon::fromTheme(iconThemeName);
        } else {
            icon12.addFile(QString::fromUtf8(":/new/prefix2/wind/zoom-in.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionZoom_in->setIcon(icon12);
        actionZoom_out = new QAction(MainWindow);
        actionZoom_out->setObjectName(QString::fromUtf8("actionZoom_out"));
        QIcon icon13;
        iconThemeName = QString::fromUtf8("zoom-out");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon13 = QIcon::fromTheme(iconThemeName);
        } else {
            icon13.addFile(QString::fromUtf8(":/new/prefix2/wind/zoom-out.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionZoom_out->setIcon(icon13);
        actionRead_only = new QAction(MainWindow);
        actionRead_only->setObjectName(QString::fromUtf8("actionRead_only"));
        actionRead_only->setCheckable(true);
        actionOver_write = new QAction(MainWindow);
        actionOver_write->setObjectName(QString::fromUtf8("actionOver_write"));
        actionOver_write->setCheckable(true);
        actionSelect_all = new QAction(MainWindow);
        actionSelect_all->setObjectName(QString::fromUtf8("actionSelect_all"));
        QIcon icon14;
        iconThemeName = QString::fromUtf8("edit-select-all");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon14 = QIcon::fromTheme(iconThemeName);
        } else {
            icon14.addFile(QString::fromUtf8(":/new/prefix2/wind/edit-select-all-symbolic.svg"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionSelect_all->setIcon(icon14);
        actionHTML = new QAction(MainWindow);
        actionHTML->setObjectName(QString::fromUtf8("actionHTML"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix2/wind/text-html.svg"), QSize(), QIcon::Normal, QIcon::On);
        actionHTML->setIcon(icon15);
        actionC = new QAction(MainWindow);
        actionC->setObjectName(QString::fromUtf8("actionC"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/new/prefix2/wind/text-x-c++src.svg"), QSize(), QIcon::Normal, QIcon::On);
        actionC->setIcon(icon16);
        actionTo_lower = new QAction(MainWindow);
        actionTo_lower->setObjectName(QString::fromUtf8("actionTo_lower"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/new/prefix2/wind/view-sort-descending.png"), QSize(), QIcon::Normal, QIcon::On);
        actionTo_lower->setIcon(icon17);
        actionTo_Upper = new QAction(MainWindow);
        actionTo_Upper->setObjectName(QString::fromUtf8("actionTo_Upper"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/new/prefix2/wind/view-sort-ascending.png"), QSize(), QIcon::Normal, QIcon::On);
        actionTo_Upper->setIcon(icon18);
        actionTo_HTML_escape = new QAction(MainWindow);
        actionTo_HTML_escape->setObjectName(QString::fromUtf8("actionTo_HTML_escape"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/new/prefix2/wind/interface_subroutine_gen.png"), QSize(), QIcon::Normal, QIcon::On);
        actionTo_HTML_escape->setIcon(icon19);
        actionInsert_comments = new QAction(MainWindow);
        actionInsert_comments->setObjectName(QString::fromUtf8("actionInsert_comments"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/new/prefix2/wind/comment_block.png"), QSize(), QIcon::Normal, QIcon::On);
        actionInsert_comments->setIcon(icon20);
        actionInsert_date = new QAction(MainWindow);
        actionInsert_date->setObjectName(QString::fromUtf8("actionInsert_date"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/new/prefix2/wind/folder-temp.svg"), QSize(), QIcon::Normal, QIcon::On);
        actionInsert_date->setIcon(icon21);
        actionPython = new QAction(MainWindow);
        actionPython->setObjectName(QString::fromUtf8("actionPython"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/new/prefix2/wind/text-x-python.svg"), QSize(), QIcon::Normal, QIcon::On);
        actionPython->setIcon(icon22);
        actionRun_HTML = new QAction(MainWindow);
        actionRun_HTML->setObjectName(QString::fromUtf8("actionRun_HTML"));
        QIcon icon23;
        iconThemeName = QString::fromUtf8("html");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon23 = QIcon::fromTheme(iconThemeName);
        } else {
            icon23.addFile(QString::fromUtf8(":/new/prefix2/wind/folder-copycom.svg"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionRun_HTML->setIcon(icon23);
        actionPrint_Preview = new QAction(MainWindow);
        actionPrint_Preview->setObjectName(QString::fromUtf8("actionPrint_Preview"));
        QIcon icon24;
        iconThemeName = QString::fromUtf8("document-print-preview");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon24 = QIcon::fromTheme(iconThemeName);
        } else {
            icon24.addFile(QString::fromUtf8(":/new/prefix2/wind/document-print-preview.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionPrint_Preview->setIcon(icon24);
        actionWord_Count = new QAction(MainWindow);
        actionWord_Count->setObjectName(QString::fromUtf8("actionWord_Count"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/new/prefix2/wind/logo.png"), QSize(), QIcon::Normal, QIcon::On);
        actionWord_Count->setIcon(icon25);
        actionRun_SPYDER_file = new QAction(MainWindow);
        actionRun_SPYDER_file->setObjectName(QString::fromUtf8("actionRun_SPYDER_file"));
        QIcon icon26;
        iconThemeName = QString::fromUtf8("spyder");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon26 = QIcon::fromTheme(iconThemeName);
        } else {
            icon26.addFile(QString::fromUtf8(":/new/prefix2/wind/spyder.ico"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionRun_SPYDER_file->setIcon(icon26);
        actionExport_to_HTML = new QAction(MainWindow);
        actionExport_to_HTML->setObjectName(QString::fromUtf8("actionExport_to_HTML"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/new/prefix2/wind/text-html-symbolic.svg"), QSize(), QIcon::Normal, QIcon::On);
        actionExport_to_HTML->setIcon(icon27);
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/new/prefix2/wind/help-about.png"), QSize(), QIcon::Normal, QIcon::On);
        actionAbout_Qt->setIcon(icon28);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        QIcon icon29;
        iconThemeName = QString::fromUtf8("edit-find");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon29 = QIcon::fromTheme(iconThemeName);
        } else {
            icon29.addFile(QString::fromUtf8(":/new/prefix2/wind/zoom-out.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionFind->setIcon(icon29);
        actionAdd_new = new QAction(MainWindow);
        actionAdd_new->setObjectName(QString::fromUtf8("actionAdd_new"));
        actionSearch_with_Google = new QAction(MainWindow);
        actionSearch_with_Google->setObjectName(QString::fromUtf8("actionSearch_with_Google"));
        actionJava_script = new QAction(MainWindow);
        actionJava_script->setObjectName(QString::fromUtf8("actionJava_script"));
        actionKvantum = new QAction(MainWindow);
        actionKvantum->setObjectName(QString::fromUtf8("actionKvantum"));
        actionWindows = new QAction(MainWindow);
        actionWindows->setObjectName(QString::fromUtf8("actionWindows"));
        actionFusion = new QAction(MainWindow);
        actionFusion->setObjectName(QString::fromUtf8("actionFusion"));
        actionBreezr = new QAction(MainWindow);
        actionBreezr->setObjectName(QString::fromUtf8("actionBreezr"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit_2->sizePolicy().hasHeightForWidth());
        plainTextEdit_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(plainTextEdit_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy1);
        plainTextEdit->setContextMenuPolicy(Qt::NoContextMenu);
        plainTextEdit->setFrameShape(QFrame::StyledPanel);
        plainTextEdit->setFrameShadow(QFrame::Sunken);
        plainTextEdit->setLineWidth(1);
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plainTextEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        plainTextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        plainTextEdit->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        plainTextEdit->setBackgroundVisible(false);

        gridLayout->addWidget(plainTextEdit, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuFiles = new QMenu(menubar);
        menuFiles->setObjectName(QString::fromUtf8("menuFiles"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuHighlight = new QMenu(menuTools);
        menuHighlight->setObjectName(QString::fromUtf8("menuHighlight"));
        menuConvert = new QMenu(menuTools);
        menuConvert->setObjectName(QString::fromUtf8("menuConvert"));
        menuRun = new QMenu(menubar);
        menuRun->setObjectName(QString::fromUtf8("menuRun"));
        menuExport = new QMenu(menubar);
        menuExport->setObjectName(QString::fromUtf8("menuExport"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuProjects = new QMenu(menubar);
        menuProjects->setObjectName(QString::fromUtf8("menuProjects"));
        menuStyles = new QMenu(menubar);
        menuStyles->setObjectName(QString::fromUtf8("menuStyles"));
        menuStyle = new QMenu(menubar);
        menuStyle->setObjectName(QString::fromUtf8("menuStyle"));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setCursor(QCursor(Qt::ArrowCursor));
        toolBar->setAutoFillBackground(false);
        toolBar->setMovable(false);
        toolBar->setOrientation(Qt::Horizontal);
        toolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFiles->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuExport->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuRun->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menubar->addAction(menuProjects->menuAction());
        menubar->addAction(menuStyles->menuAction());
        menubar->addAction(menuStyle->menuAction());
        menuFiles->addAction(actionNew);
        menuFiles->addAction(actionOpen);
        menuFiles->addAction(actionSave);
        menuFiles->addAction(actionSave_as);
        menuFiles->addAction(actionPrint);
        menuFiles->addAction(actionExit);
        menuFiles->addAction(actionPrint_Preview);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionCut_2);
        menuEdit->addAction(actionPaste_2);
        menuEdit->addAction(actionSelect_all);
        menuEdit->addAction(actionFind);
        menuView->addAction(actionZoom_in);
        menuView->addAction(actionZoom_out);
        menuView->addAction(actionRead_only);
        menuView->addAction(actionOver_write);
        menuTools->addAction(menuHighlight->menuAction());
        menuTools->addAction(menuConvert->menuAction());
        menuTools->addAction(actionInsert_comments);
        menuTools->addAction(actionInsert_date);
        menuTools->addAction(actionWord_Count);
        menuHighlight->addAction(actionHTML);
        menuHighlight->addAction(actionC);
        menuHighlight->addAction(actionPython);
        menuHighlight->addAction(actionJava_script);
        menuConvert->addAction(actionTo_lower);
        menuConvert->addAction(actionTo_Upper);
        menuConvert->addAction(actionTo_HTML_escape);
        menuRun->addAction(actionRun_HTML);
        menuRun->addSeparator();
        menuRun->addAction(actionRun_SPYDER_file);
        menuExport->addAction(actionExport_to_HTML);
        menuAbout->addAction(actionAbout_Qt);
        menuProjects->addAction(actionAdd_new);
        menuStyles->addAction(actionSearch_with_Google);
        menuStyle->addAction(actionKvantum);
        menuStyle->addAction(actionWindows);
        menuStyle->addAction(actionFusion);
        menuStyle->addAction(actionBreezr);
        toolBar->addAction(actionNew);
        toolBar->addSeparator();
        toolBar->addAction(actionOpen);
        toolBar->addSeparator();
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionSave_as);
        toolBar->addSeparator();
        toolBar->addAction(actionPrint);
        toolBar->addSeparator();
        toolBar->addAction(actionPrint_Preview);
        toolBar->addSeparator();
        toolBar->addAction(actionRun_HTML);
        toolBar->addSeparator();
        toolBar->addAction(actionRun_SPYDER_file);
        toolBar->addSeparator();
        toolBar->addAction(actionExit);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "NotePad", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save ", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_as->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPrint->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
#if QT_CONFIG(shortcut)
        actionPrint->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut_2->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
#if QT_CONFIG(shortcut)
        actionCut_2->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste_2->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste_2->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoom_in->setText(QCoreApplication::translate("MainWindow", "Zoom in", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_in->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+.", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoom_out->setText(QCoreApplication::translate("MainWindow", "Zoom out", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_out->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+,", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRead_only->setText(QCoreApplication::translate("MainWindow", "Read only", nullptr));
#if QT_CONFIG(shortcut)
        actionRead_only->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOver_write->setText(QCoreApplication::translate("MainWindow", "Over write", nullptr));
#if QT_CONFIG(shortcut)
        actionOver_write->setShortcut(QCoreApplication::translate("MainWindow", "Ins", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelect_all->setText(QCoreApplication::translate("MainWindow", "Select all", nullptr));
#if QT_CONFIG(shortcut)
        actionSelect_all->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionHTML->setText(QCoreApplication::translate("MainWindow", "HTML", nullptr));
        actionC->setText(QCoreApplication::translate("MainWindow", "C++", nullptr));
        actionTo_lower->setText(QCoreApplication::translate("MainWindow", "To lower", nullptr));
        actionTo_Upper->setText(QCoreApplication::translate("MainWindow", "To Upper", nullptr));
        actionTo_HTML_escape->setText(QCoreApplication::translate("MainWindow", "To HTML escape", nullptr));
        actionInsert_comments->setText(QCoreApplication::translate("MainWindow", "Insert comments", nullptr));
        actionInsert_date->setText(QCoreApplication::translate("MainWindow", "Insert Time", nullptr));
        actionPython->setText(QCoreApplication::translate("MainWindow", "Python", nullptr));
        actionRun_HTML->setText(QCoreApplication::translate("MainWindow", "Run HTML", nullptr));
        actionPrint_Preview->setText(QCoreApplication::translate("MainWindow", "Print Preview", nullptr));
        actionWord_Count->setText(QCoreApplication::translate("MainWindow", "Word Count", nullptr));
        actionRun_SPYDER_file->setText(QCoreApplication::translate("MainWindow", "Run SPYDER file", nullptr));
        actionExport_to_HTML->setText(QCoreApplication::translate("MainWindow", "Export to HTML", nullptr));
        actionAbout_Qt->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        actionFind->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
#if QT_CONFIG(shortcut)
        actionFind->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAdd_new->setText(QCoreApplication::translate("MainWindow", "Add new", nullptr));
#if QT_CONFIG(shortcut)
        actionAdd_new->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSearch_with_Google->setText(QCoreApplication::translate("MainWindow", "Search with Google", nullptr));
#if QT_CONFIG(shortcut)
        actionSearch_with_Google->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+G", nullptr));
#endif // QT_CONFIG(shortcut)
        actionJava_script->setText(QCoreApplication::translate("MainWindow", "Java script", nullptr));
        actionKvantum->setText(QCoreApplication::translate("MainWindow", "Kvantum", nullptr));
        actionWindows->setText(QCoreApplication::translate("MainWindow", "Windows", nullptr));
        actionFusion->setText(QCoreApplication::translate("MainWindow", "Fusion", nullptr));
        actionBreezr->setText(QCoreApplication::translate("MainWindow", "Breeze", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuFiles->setTitle(QCoreApplication::translate("MainWindow", "Files", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuHighlight->setTitle(QCoreApplication::translate("MainWindow", "Highlight", nullptr));
        menuConvert->setTitle(QCoreApplication::translate("MainWindow", "Convert ", nullptr));
        menuRun->setTitle(QCoreApplication::translate("MainWindow", "Run", nullptr));
        menuExport->setTitle(QCoreApplication::translate("MainWindow", "Export", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuProjects->setTitle(QCoreApplication::translate("MainWindow", "Projects", nullptr));
        menuStyles->setTitle(QCoreApplication::translate("MainWindow", "Search", nullptr));
        menuStyle->setTitle(QCoreApplication::translate("MainWindow", "Style", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
