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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QSlider *vsAngle;
    QSpinBox *spAngle;
    QVBoxLayout *Slider1;
    QLabel *labelFOV;
    QSlider *vsFOV;
    QSpinBox *spFOV;
    QGroupBox *gbProjection;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *rbOrthogonal;
    QRadioButton *rbPerspective;
    QGroupBox *gbRotation;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *Rotations;
    QSlider *hsRotationA;
    QSlider *hsRotationB;
    QSlider *hsRotationC;
    QLabel *labelA;
    QLabel *labelB;
    QLabel *labelC;
    QGroupBox *gbClipping;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *Clipping;
    QLabel *labelFar;
    QLabel *labelNear;
    QDoubleSpinBox *dsbNear;
    QDoubleSpinBox *dsbFar;
    QFormLayout *flControlButtons;
    QPushButton *rbReset;
    QOpenGLWidget *openGLWdget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(914, 607);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        hlMain = new QHBoxLayout();
        hlMain->setObjectName(QString::fromUtf8("hlMain"));
        vbControls = new QGroupBox(centralWidget);
        vbControls->setObjectName(QString::fromUtf8("vbControls"));
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
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelAngle->sizePolicy().hasHeightForWidth());
        labelAngle->setSizePolicy(sizePolicy);
        labelAngle->setMinimumSize(QSize(0, 30));
        labelAngle->setMaximumSize(QSize(75, 16777215));
        labelAngle->setAlignment(Qt::AlignCenter);
        labelAngle->setWordWrap(true);

        Slider2->addWidget(labelAngle);

        vsAngle = new QSlider(vbControls);
        vsAngle->setObjectName(QString::fromUtf8("vsAngle"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(vsAngle->sizePolicy().hasHeightForWidth());
        vsAngle->setSizePolicy(sizePolicy1);
        vsAngle->setOrientation(Qt::Vertical);

        Slider2->addWidget(vsAngle);

        spAngle = new QSpinBox(vbControls);
        spAngle->setObjectName(QString::fromUtf8("spAngle"));
        spAngle->setMinimum(45);
        spAngle->setMaximum(90);

        Slider2->addWidget(spAngle);


        Sliders->addLayout(Slider2);

        Slider1 = new QVBoxLayout();
        Slider1->setObjectName(QString::fromUtf8("Slider1"));
        Slider1->setSizeConstraint(QLayout::SetFixedSize);
        labelFOV = new QLabel(vbControls);
        labelFOV->setObjectName(QString::fromUtf8("labelFOV"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelFOV->sizePolicy().hasHeightForWidth());
        labelFOV->setSizePolicy(sizePolicy2);
        labelFOV->setMinimumSize(QSize(0, 30));
        labelFOV->setMaximumSize(QSize(75, 50));
        labelFOV->setAlignment(Qt::AlignCenter);

        Slider1->addWidget(labelFOV);

        vsFOV = new QSlider(vbControls);
        vsFOV->setObjectName(QString::fromUtf8("vsFOV"));
        sizePolicy1.setHeightForWidth(vsFOV->sizePolicy().hasHeightForWidth());
        vsFOV->setSizePolicy(sizePolicy1);
        vsFOV->setOrientation(Qt::Vertical);

        Slider1->addWidget(vsFOV);

        spFOV = new QSpinBox(vbControls);
        spFOV->setObjectName(QString::fromUtf8("spFOV"));

        Slider1->addWidget(spFOV);


        Sliders->addLayout(Slider1);


        verticalLayout->addLayout(Sliders);

        gbProjection = new QGroupBox(vbControls);
        gbProjection->setObjectName(QString::fromUtf8("gbProjection"));
        verticalLayout_3 = new QVBoxLayout(gbProjection);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        rbOrthogonal = new QRadioButton(gbProjection);
        rbOrthogonal->setObjectName(QString::fromUtf8("rbOrthogonal"));

        verticalLayout_3->addWidget(rbOrthogonal);

        rbPerspective = new QRadioButton(gbProjection);
        rbPerspective->setObjectName(QString::fromUtf8("rbPerspective"));

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
        hsRotationA = new QSlider(gbRotation);
        hsRotationA->setObjectName(QString::fromUtf8("hsRotationA"));
        hsRotationA->setOrientation(Qt::Horizontal);

        Rotations->setWidget(1, QFormLayout::FieldRole, hsRotationA);

        hsRotationB = new QSlider(gbRotation);
        hsRotationB->setObjectName(QString::fromUtf8("hsRotationB"));
        hsRotationB->setOrientation(Qt::Horizontal);

        Rotations->setWidget(2, QFormLayout::FieldRole, hsRotationB);

        hsRotationC = new QSlider(gbRotation);
        hsRotationC->setObjectName(QString::fromUtf8("hsRotationC"));
        hsRotationC->setOrientation(Qt::Horizontal);

        Rotations->setWidget(3, QFormLayout::FieldRole, hsRotationC);

        labelA = new QLabel(gbRotation);
        labelA->setObjectName(QString::fromUtf8("labelA"));

        Rotations->setWidget(1, QFormLayout::LabelRole, labelA);

        labelB = new QLabel(gbRotation);
        labelB->setObjectName(QString::fromUtf8("labelB"));

        Rotations->setWidget(2, QFormLayout::LabelRole, labelB);

        labelC = new QLabel(gbRotation);
        labelC->setObjectName(QString::fromUtf8("labelC"));

        Rotations->setWidget(3, QFormLayout::LabelRole, labelC);


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

        Clipping->setWidget(0, QFormLayout::FieldRole, dsbNear);

        dsbFar = new QDoubleSpinBox(gbClipping);
        dsbFar->setObjectName(QString::fromUtf8("dsbFar"));

        Clipping->setWidget(1, QFormLayout::FieldRole, dsbFar);


        verticalLayout_2->addLayout(Clipping);


        verticalLayout->addWidget(gbClipping);

        flControlButtons = new QFormLayout();
        flControlButtons->setObjectName(QString::fromUtf8("flControlButtons"));
        rbReset = new QPushButton(vbControls);
        rbReset->setObjectName(QString::fromUtf8("rbReset"));

        flControlButtons->setWidget(0, QFormLayout::SpanningRole, rbReset);


        verticalLayout->addLayout(flControlButtons);


        hlMain->addWidget(vbControls, 0, Qt::AlignLeft);

        openGLWdget = new QOpenGLWidget(centralWidget);
        openGLWdget->setObjectName(QString::fromUtf8("openGLWdget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(openGLWdget->sizePolicy().hasHeightForWidth());
        openGLWdget->setSizePolicy(sizePolicy3);

        hlMain->addWidget(openGLWdget);


        horizontalLayout_2->addLayout(hlMain);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Test", nullptr));
        vbControls->setTitle(QCoreApplication::translate("MainWindow", "Controls", nullptr));
        labelAngle->setText(QCoreApplication::translate("MainWindow", "Field Of View", nullptr));
        labelFOV->setText(QCoreApplication::translate("MainWindow", "Angle", nullptr));
        gbProjection->setTitle(QCoreApplication::translate("MainWindow", "Projection Mode", nullptr));
        rbOrthogonal->setText(QCoreApplication::translate("MainWindow", "Orthogonal", nullptr));
        rbPerspective->setText(QCoreApplication::translate("MainWindow", "Perspective", nullptr));
        gbRotation->setTitle(QCoreApplication::translate("MainWindow", "Rotations", nullptr));
        labelA->setText(QCoreApplication::translate("MainWindow", "Ring A", nullptr));
        labelB->setText(QCoreApplication::translate("MainWindow", "Ring B", nullptr));
        labelC->setText(QCoreApplication::translate("MainWindow", "Ring C", nullptr));
        gbClipping->setTitle(QCoreApplication::translate("MainWindow", "Clipping Plane", nullptr));
        labelFar->setText(QCoreApplication::translate("MainWindow", "Far", nullptr));
        labelNear->setText(QCoreApplication::translate("MainWindow", "Near", nullptr));
        rbReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H