/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *deleteButton;
    QComboBox *createComboBox3;
    QSpinBox *createSpinBox1;
    QPushButton *updateButton;
    QPushButton *getIDButton;
    QSpinBox *updateSpinBox;
    QComboBox *updateComboBox2;
    QSpinBox *updateSpinBox2;
    QPushButton *createButton;
    QSpinBox *updateSpinBox1;
    QSpinBox *deleteSpinBox;
    QSpinBox *createSpinBox2;
    QLineEdit *updateLineEdit;
    QComboBox *createComboBox1;
    QPushButton *getAllButton;
    QSpinBox *getIDSpinBox;
    QComboBox *createComboBox2;
    QComboBox *updateComboBox1;
    QComboBox *updateComboBox3;
    QLineEdit *createLineEdit;
    QLabel *labelButton;
    QLabel *labelID;
    QLabel *labelName;
    QLabel *labelBowlType;
    QLabel *labelBowlMaterial;
    QLabel *labelTobacco;
    QLabel *labelYearsOfUsage;
    QLabel *labelFlaskVolume;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(982, 558);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(100, 90, 811, 211));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        deleteButton = new QPushButton(gridLayoutWidget);
        deleteButton->setObjectName("deleteButton");

        gridLayout->addWidget(deleteButton, 5, 0, 1, 1);

        createComboBox3 = new QComboBox(gridLayoutWidget);
        createComboBox3->addItem(QString());
        createComboBox3->addItem(QString());
        createComboBox3->addItem(QString());
        createComboBox3->setObjectName("createComboBox3");

        gridLayout->addWidget(createComboBox3, 3, 5, 1, 1);

        createSpinBox1 = new QSpinBox(gridLayoutWidget);
        createSpinBox1->setObjectName("createSpinBox1");
        createSpinBox1->setMaximum(10);

        gridLayout->addWidget(createSpinBox1, 3, 6, 1, 1);

        updateButton = new QPushButton(gridLayoutWidget);
        updateButton->setObjectName("updateButton");

        gridLayout->addWidget(updateButton, 4, 0, 1, 1);

        getIDButton = new QPushButton(gridLayoutWidget);
        getIDButton->setObjectName("getIDButton");

        gridLayout->addWidget(getIDButton, 1, 0, 1, 1);

        updateSpinBox = new QSpinBox(gridLayoutWidget);
        updateSpinBox->setObjectName("updateSpinBox");
        updateSpinBox->setMaximum(10000);

        gridLayout->addWidget(updateSpinBox, 4, 1, 1, 1);

        updateComboBox2 = new QComboBox(gridLayoutWidget);
        updateComboBox2->addItem(QString());
        updateComboBox2->addItem(QString());
        updateComboBox2->addItem(QString());
        updateComboBox2->addItem(QString());
        updateComboBox2->setObjectName("updateComboBox2");

        gridLayout->addWidget(updateComboBox2, 4, 4, 1, 1);

        updateSpinBox2 = new QSpinBox(gridLayoutWidget);
        updateSpinBox2->setObjectName("updateSpinBox2");
        updateSpinBox2->setMinimum(3);
        updateSpinBox2->setMaximum(5);

        gridLayout->addWidget(updateSpinBox2, 4, 7, 1, 1);

        createButton = new QPushButton(gridLayoutWidget);
        createButton->setObjectName("createButton");

        gridLayout->addWidget(createButton, 3, 0, 1, 1);

        updateSpinBox1 = new QSpinBox(gridLayoutWidget);
        updateSpinBox1->setObjectName("updateSpinBox1");
        updateSpinBox1->setMaximum(10);

        gridLayout->addWidget(updateSpinBox1, 4, 6, 1, 1);

        deleteSpinBox = new QSpinBox(gridLayoutWidget);
        deleteSpinBox->setObjectName("deleteSpinBox");
        deleteSpinBox->setMaximum(10000);

        gridLayout->addWidget(deleteSpinBox, 5, 1, 1, 1);

        createSpinBox2 = new QSpinBox(gridLayoutWidget);
        createSpinBox2->setObjectName("createSpinBox2");
        createSpinBox2->setMinimum(3);
        createSpinBox2->setMaximum(5);

        gridLayout->addWidget(createSpinBox2, 3, 7, 1, 1);

        updateLineEdit = new QLineEdit(gridLayoutWidget);
        updateLineEdit->setObjectName("updateLineEdit");
        updateLineEdit->setMaxLength(30);

        gridLayout->addWidget(updateLineEdit, 4, 2, 1, 1);

        createComboBox1 = new QComboBox(gridLayoutWidget);
        createComboBox1->addItem(QString());
        createComboBox1->addItem(QString());
        createComboBox1->addItem(QString());
        createComboBox1->setObjectName("createComboBox1");

        gridLayout->addWidget(createComboBox1, 3, 3, 1, 1);

        getAllButton = new QPushButton(gridLayoutWidget);
        getAllButton->setObjectName("getAllButton");

        gridLayout->addWidget(getAllButton, 2, 0, 1, 1);

        getIDSpinBox = new QSpinBox(gridLayoutWidget);
        getIDSpinBox->setObjectName("getIDSpinBox");
        getIDSpinBox->setMaximum(10000);

        gridLayout->addWidget(getIDSpinBox, 1, 1, 1, 1);

        createComboBox2 = new QComboBox(gridLayoutWidget);
        createComboBox2->addItem(QString());
        createComboBox2->addItem(QString());
        createComboBox2->addItem(QString());
        createComboBox2->addItem(QString());
        createComboBox2->setObjectName("createComboBox2");

        gridLayout->addWidget(createComboBox2, 3, 4, 1, 1);

        updateComboBox1 = new QComboBox(gridLayoutWidget);
        updateComboBox1->addItem(QString());
        updateComboBox1->addItem(QString());
        updateComboBox1->addItem(QString());
        updateComboBox1->setObjectName("updateComboBox1");

        gridLayout->addWidget(updateComboBox1, 4, 3, 1, 1);

        updateComboBox3 = new QComboBox(gridLayoutWidget);
        updateComboBox3->addItem(QString());
        updateComboBox3->addItem(QString());
        updateComboBox3->addItem(QString());
        updateComboBox3->setObjectName("updateComboBox3");

        gridLayout->addWidget(updateComboBox3, 4, 5, 1, 1);

        createLineEdit = new QLineEdit(gridLayoutWidget);
        createLineEdit->setObjectName("createLineEdit");
        createLineEdit->setMaxLength(30);

        gridLayout->addWidget(createLineEdit, 3, 2, 1, 1);

        labelButton = new QLabel(gridLayoutWidget);
        labelButton->setObjectName("labelButton");

        gridLayout->addWidget(labelButton, 0, 0, 1, 1);

        labelID = new QLabel(gridLayoutWidget);
        labelID->setObjectName("labelID");

        gridLayout->addWidget(labelID, 0, 1, 1, 1);

        labelName = new QLabel(gridLayoutWidget);
        labelName->setObjectName("labelName");

        gridLayout->addWidget(labelName, 0, 2, 1, 1);

        labelBowlType = new QLabel(gridLayoutWidget);
        labelBowlType->setObjectName("labelBowlType");

        gridLayout->addWidget(labelBowlType, 0, 3, 1, 1);

        labelBowlMaterial = new QLabel(gridLayoutWidget);
        labelBowlMaterial->setObjectName("labelBowlMaterial");

        gridLayout->addWidget(labelBowlMaterial, 0, 4, 1, 1);

        labelTobacco = new QLabel(gridLayoutWidget);
        labelTobacco->setObjectName("labelTobacco");

        gridLayout->addWidget(labelTobacco, 0, 5, 1, 1);

        labelYearsOfUsage = new QLabel(gridLayoutWidget);
        labelYearsOfUsage->setObjectName("labelYearsOfUsage");

        gridLayout->addWidget(labelYearsOfUsage, 0, 6, 1, 1);

        labelFlaskVolume = new QLabel(gridLayoutWidget);
        labelFlaskVolume->setObjectName("labelFlaskVolume");

        gridLayout->addWidget(labelFlaskVolume, 0, 7, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 982, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        createComboBox3->setItemText(0, QCoreApplication::translate("MainWindow", "Sweet", nullptr));
        createComboBox3->setItemText(1, QCoreApplication::translate("MainWindow", "Sour", nullptr));
        createComboBox3->setItemText(2, QCoreApplication::translate("MainWindow", "Cytrus", nullptr));

        updateButton->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        getIDButton->setText(QCoreApplication::translate("MainWindow", "Get ID", nullptr));
        updateComboBox2->setItemText(0, QCoreApplication::translate("MainWindow", "Glass", nullptr));
        updateComboBox2->setItemText(1, QCoreApplication::translate("MainWindow", "Silicon", nullptr));
        updateComboBox2->setItemText(2, QCoreApplication::translate("MainWindow", "Ceramic", nullptr));
        updateComboBox2->setItemText(3, QCoreApplication::translate("MainWindow", "Clay", nullptr));

        createButton->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        createComboBox1->setItemText(0, QCoreApplication::translate("MainWindow", "Turk", nullptr));
        createComboBox1->setItemText(1, QCoreApplication::translate("MainWindow", "Race phunnel", nullptr));
        createComboBox1->setItemText(2, QCoreApplication::translate("MainWindow", "Race classic", nullptr));

        getAllButton->setText(QCoreApplication::translate("MainWindow", "Get All", nullptr));
        createComboBox2->setItemText(0, QCoreApplication::translate("MainWindow", "Glass", nullptr));
        createComboBox2->setItemText(1, QCoreApplication::translate("MainWindow", "Silicon", nullptr));
        createComboBox2->setItemText(2, QCoreApplication::translate("MainWindow", "Ceramic", nullptr));
        createComboBox2->setItemText(3, QCoreApplication::translate("MainWindow", "Clay", nullptr));

        updateComboBox1->setItemText(0, QCoreApplication::translate("MainWindow", "Turk", nullptr));
        updateComboBox1->setItemText(1, QCoreApplication::translate("MainWindow", "Race phunnel", nullptr));
        updateComboBox1->setItemText(2, QCoreApplication::translate("MainWindow", "Race classic", nullptr));

        updateComboBox3->setItemText(0, QCoreApplication::translate("MainWindow", "Sweet", nullptr));
        updateComboBox3->setItemText(1, QCoreApplication::translate("MainWindow", "Sour", nullptr));
        updateComboBox3->setItemText(2, QCoreApplication::translate("MainWindow", "Cytrus", nullptr));

        createLineEdit->setText(QString());
        labelButton->setText(QCoreApplication::translate("MainWindow", "Button", nullptr));
        labelID->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        labelName->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        labelBowlType->setText(QCoreApplication::translate("MainWindow", "bowl type", nullptr));
        labelBowlMaterial->setText(QCoreApplication::translate("MainWindow", "bowl material", nullptr));
        labelTobacco->setText(QCoreApplication::translate("MainWindow", "tobacco", nullptr));
        labelYearsOfUsage->setText(QCoreApplication::translate("MainWindow", "years of usage", nullptr));
        labelFlaskVolume->setText(QCoreApplication::translate("MainWindow", "flask volume", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
