/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MyGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *hlMain;
    QGroupBox *vbControls;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *Sliders;
    QVBoxLayout *Slider2;
    QLabel *labelAngle;
    QSlider *vsFOV;
    QSpinBox *spAngle;
    QVBoxLayout *Slider1;
    QLabel *labelFOV;
    QSlider *vsAngle;
    QSpinBox *spFOV;
    QCheckBox *chbSetCamera;
    QGroupBox *gbProjection;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *rbOrthogonal;
    QRadioButton *rbPerspective;
    QGroupBox *gbRotation;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *Rotations;
    QLabel *labelA;
    QSlider *hsRotationA;
    QLabel *labelB;
    QSlider *hsRotationB;
    QLabel *labelC;
    QSlider *hsRotationC;
    QCheckBox *chbAnimation;
    QGroupBox *gbClipping;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *Clipping;
    QLabel *labelFar;
    QLabel *labelNear;
    QDoubleSpinBox *dsbNear;
    QDoubleSpinBox *dsbFar;
    QFormLayout *flControlButtons;
    QPushButton *btnReset;
    MyGLWidget *openGLWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(914, 613);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        hlMain = new QHBoxLayout();
        hlMain->setObjectName(QString::fromUtf8("hlMain"));
        vbControls = new QGroupBox(centralWidget);
        vbControls->setObjectName(QString::fromUtf8("vbControls"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(vbControls->sizePolicy().hasHeightForWidth());
        vbControls->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(vbControls);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Sliders = new QHBoxLayout();
        Sliders->setObjectName(QString::fromUtf8("Sliders"));
        Sliders->setSizeConstraint(QLayout::SetDefaultConstraint);
        Slider2 = new QVBoxLayout();
        Slider2->setObjectName(QString::fromUtf8("Slider2"));
        Slider2->setSizeConstraint(QLayout::SetDefaultConstraint);
        labelAngle = new QLabel(vbControls);
        labelAngle->setObjectName(QString::fromUtf8("labelAngle"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelAngle->sizePolicy().hasHeightForWidth());
        labelAngle->setSizePolicy(sizePolicy1);
        labelAngle->setMinimumSize(QSize(0, 30));
        labelAngle->setMaximumSize(QSize(75, 16777215));
        labelAngle->setAlignment(Qt::AlignCenter);
        labelAngle->setWordWrap(true);

        Slider2->addWidget(labelAngle);

        vsFOV = new QSlider(vbControls);
        vsFOV->setObjectName(QString::fromUtf8("vsFOV"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(vsFOV->sizePolicy().hasHeightForWidth());
        vsFOV->setSizePolicy(sizePolicy2);
        vsFOV->setMinimum(1);
        vsFOV->setMaximum(180);
        vsFOV->setValue(75);
        vsFOV->setOrientation(Qt::Vertical);

        Slider2->addWidget(vsFOV);

        spAngle = new QSpinBox(vbControls);
        spAngle->setObjectName(QString::fromUtf8("spAngle"));
        spAngle->setMinimum(1);
        spAngle->setMaximum(180);
        spAngle->setValue(75);

        Slider2->addWidget(spAngle);


        Sliders->addLayout(Slider2);

        Slider1 = new QVBoxLayout();
        Slider1->setObjectName(QString::fromUtf8("Slider1"));
        Slider1->setSizeConstraint(QLayout::SetFixedSize);
        labelFOV = new QLabel(vbControls);
        labelFOV->setObjectName(QString::fromUtf8("labelFOV"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelFOV->sizePolicy().hasHeightForWidth());
        labelFOV->setSizePolicy(sizePolicy3);
        labelFOV->setMinimumSize(QSize(0, 30));
        labelFOV->setMaximumSize(QSize(75, 50));
        labelFOV->setAlignment(Qt::AlignCenter);

        Slider1->addWidget(labelFOV);

        vsAngle = new QSlider(vbControls);
        vsAngle->setObjectName(QString::fromUtf8("vsAngle"));
        sizePolicy2.setHeightForWidth(vsAngle->sizePolicy().hasHeightForWidth());
        vsAngle->setSizePolicy(sizePolicy2);
        vsAngle->setMaximum(360);
        vsAngle->setValue(75);
        vsAngle->setOrientation(Qt::Vertical);

        Slider1->addWidget(vsAngle);

        spFOV = new QSpinBox(vbControls);
        spFOV->setObjectName(QString::fromUtf8("spFOV"));
        spFOV->setMaximum(360);
        spFOV->setValue(75);

        Slider1->addWidget(spFOV);


        Sliders->addLayout(Slider1);


        verticalLayout->addLayout(Sliders);

        chbSetCamera = new QCheckBox(vbControls);
        chbSetCamera->setObjectName(QString::fromUtf8("chbSetCamera"));

        verticalLayout->addWidget(chbSetCamera);

        gbProjection = new QGroupBox(vbControls);
        gbProjection->setObjectName(QString::fromUtf8("gbProjection"));
        verticalLayout_3 = new QVBoxLayout(gbProjection);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        rbOrthogonal = new QRadioButton(gbProjection);
        rbOrthogonal->setObjectName(QString::fromUtf8("rbOrthogonal"));

        verticalLayout_3->addWidget(rbOrthogonal);

        rbPerspective = new QRadioButton(gbProjection);
        rbPerspective->setObjectName(QString::fromUtf8("rbPerspective"));
        rbPerspective->setChecked(true);

        verticalLayout_3->addWidget(rbPerspective);


        verticalLayout->addWidget(gbProjection);

        gbRotation = new QGroupBox(vbControls);
        gbRotation->setObjectName(QString::fromUtf8("gbRotation"));
        verticalLayout_4 = new QVBoxLayout(gbRotation);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        Rotations = new QFormLayout();
        Rotations->setObjectName(QString::fromUtf8("Rotations"));
        Rotations->setSizeConstraint(QLayout::SetDefaultConstraint);
        Rotations->setHorizontalSpacing(6);
        labelA = new QLabel(gbRotation);
        labelA->setObjectName(QString::fromUtf8("labelA"));

        Rotations->setWidget(1, QFormLayout::LabelRole, labelA);

        hsRotationA = new QSlider(gbRotation);
        hsRotationA->setObjectName(QString::fromUtf8("hsRotationA"));
        hsRotationA->setMaximum(180);
        hsRotationA->setSliderPosition(0);
        hsRotationA->setOrientation(Qt::Horizontal);

        Rotations->setWidget(1, QFormLayout::FieldRole, hsRotationA);

        labelB = new QLabel(gbRotation);
        labelB->setObjectName(QString::fromUtf8("labelB"));

        Rotations->setWidget(2, QFormLayout::LabelRole, labelB);

        hsRotationB = new QSlider(gbRotation);
        hsRotationB->setObjectName(QString::fromUtf8("hsRotationB"));
        hsRotationB->setMinimum(0);
        hsRotationB->setMaximum(180);
        hsRotationB->setSingleStep(1);
        hsRotationB->setSliderPosition(0);
        hsRotationB->setOrientation(Qt::Horizontal);

        Rotations->setWidget(2, QFormLayout::FieldRole, hsRotationB);

        labelC = new QLabel(gbRotation);
        labelC->setObjectName(QString::fromUtf8("labelC"));

        Rotations->setWidget(3, QFormLayout::LabelRole, labelC);

        hsRotationC = new QSlider(gbRotation);
        hsRotationC->setObjectName(QString::fromUtf8("hsRotationC"));
        hsRotationC->setMinimum(0);
        hsRotationC->setMaximum(180);
        hsRotationC->setOrientation(Qt::Horizontal);

        Rotations->setWidget(3, QFormLayout::FieldRole, hsRotationC);

        chbAnimation = new QCheckBox(gbRotation);
        chbAnimation->setObjectName(QString::fromUtf8("chbAnimation"));

        Rotations->setWidget(0, QFormLayout::SpanningRole, chbAnimation);


        verticalLayout_4->addLayout(Rotations);


        verticalLayout->addWidget(gbRotation);

        gbClipping = new QGroupBox(vbControls);
        gbClipping->setObjectName(QString::fromUtf8("gbClipping"));
        verticalLayout_2 = new QVBoxLayout(gbClipping);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Clipping = new QFormLayout();
        Clipping->setObjectName(QString::fromUtf8("Clipping"));
        labelFar = new QLabel(gbClipping);
        labelFar->setObjectName(QString::fromUtf8("labelFar"));

        Clipping->setWidget(1, QFormLayout::LabelRole, labelFar);

        labelNear = new QLabel(gbClipping);
        labelNear->setObjectName(QString::fromUtf8("labelNear"));

        Clipping->setWidget(0, QFormLayout::LabelRole, labelNear);

        dsbNear = new QDoubleSpinBox(gbClipping);
        dsbNear->setObjectName(QString::fromUtf8("dsbNear"));
        dsbNear->setValue(0.100000000000000);

        Clipping->setWidget(0, QFormLayout::FieldRole, dsbNear);

        dsbFar = new QDoubleSpinBox(gbClipping);
        dsbFar->setObjectName(QString::fromUtf8("dsbFar"));
        dsbFar->setMaximum(100.000000000000000);
        dsbFar->setValue(100.000000000000000);

        Clipping->setWidget(1, QFormLayout::FieldRole, dsbFar);


        verticalLayout_2->addLayout(Clipping);


        verticalLayout->addWidget(gbClipping);

        flControlButtons = new QFormLayout();
        flControlButtons->setObjectName(QString::fromUtf8("flControlButtons"));
        btnReset = new QPushButton(vbControls);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));

        flControlButtons->setWidget(0, QFormLayout::SpanningRole, btnReset);


        verticalLayout->addLayout(flControlButtons);


        hlMain->addWidget(vbControls, 0, Qt::AlignLeft);

        openGLWidget = new MyGLWidget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy4);
        openGLWidget->setMinimumSize(QSize(480, 0));

        hlMain->addWidget(openGLWidget);


        horizontalLayout_2->addLayout(hlMain);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(spAngle, SIGNAL(valueChanged(int)), vsFOV, SLOT(setValue(int)));
        QObject::connect(spFOV, SIGNAL(valueChanged(int)), vsAngle, SLOT(setValue(int)));
        QObject::connect(vsFOV, SIGNAL(valueChanged(int)), spAngle, SLOT(setValue(int)));
        QObject::connect(vsAngle, SIGNAL(valueChanged(int)), spFOV, SLOT(setValue(int)));
        QObject::connect(openGLWidget, SIGNAL(adjustNear(double)), dsbNear, SLOT(setValue(double)));
        QObject::connect(openGLWidget, SIGNAL(adjustFar(double)), dsbFar, SLOT(setValue(double)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Test", nullptr));
        vbControls->setTitle(QCoreApplication::translate("MainWindow", "Controls", nullptr));
        labelAngle->setText(QCoreApplication::translate("MainWindow", "Field Of View", nullptr));
        labelFOV->setText(QCoreApplication::translate("MainWindow", "Angle", nullptr));
        chbSetCamera->setText(QCoreApplication::translate("MainWindow", "SetCamera", nullptr));
        gbProjection->setTitle(QCoreApplication::translate("MainWindow", "Projection Mode", nullptr));
        rbOrthogonal->setText(QCoreApplication::translate("MainWindow", "Orthogonal", nullptr));
        rbPerspective->setText(QCoreApplication::translate("MainWindow", "Perspective", nullptr));
        gbRotation->setTitle(QCoreApplication::translate("MainWindow", "Rotations", nullptr));
        labelA->setText(QCoreApplication::translate("MainWindow", "Ring A", nullptr));
        labelB->setText(QCoreApplication::translate("MainWindow", "Ring B", nullptr));
        labelC->setText(QCoreApplication::translate("MainWindow", "Ring C", nullptr));
        chbAnimation->setText(QCoreApplication::translate("MainWindow", "Animation", nullptr));
        gbClipping->setTitle(QCoreApplication::translate("MainWindow", "Clipping Plane", nullptr));
        labelFar->setText(QCoreApplication::translate("MainWindow", "Far", nullptr));
        labelNear->setText(QCoreApplication::translate("MainWindow", "Near", nullptr));
        btnReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
