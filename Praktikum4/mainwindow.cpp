#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <MyGLWidget.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->vsFOV, &QSlider::valueChanged, ui->openGLWidget, &MyGLWidget::setFOV);
    connect(ui->vsAngle, &QSlider::valueChanged, ui->openGLWidget, &MyGLWidget::setAngle);
    connect(ui->vsFOV, &QSlider::valueChanged, [=](int val) {
        qInfo() << "FOV is: " << val;
    });
    connect(ui->vsAngle, &QSlider::valueChanged, [=](int val) {
        qInfo() << "Angle is: " << val;
    });
    connect(ui->rbOrthogonal, &QRadioButton::toggled, ui->openGLWidget, &MyGLWidget::setProjectionMode);
    connect(ui->rbPerspective, &QRadioButton::toggled, ui->openGLWidget, &MyGLWidget::setProjectionMode);

    void (QDoubleSpinBox::* dsbSignal)(double) = &QDoubleSpinBox::valueChanged;
    connect(ui->dsbNear, dsbSignal, ui->openGLWidget, &MyGLWidget::setNear);
    connect(ui->dsbFar, dsbSignal, ui->openGLWidget, &MyGLWidget::setFar);
    connect(ui->hsRotationA, &QSlider::valueChanged, ui->openGLWidget, &MyGLWidget::setRotationA);
    connect(ui->hsRotationB, &QSlider::valueChanged, ui->openGLWidget, &MyGLWidget::setRotationB);
    connect(ui->hsRotationC, &QSlider::valueChanged, ui->openGLWidget, &MyGLWidget::setRotationC);
    connect(ui->btnReset, &QPushButton::clicked, this, &MainWindow::reset);
    connect(ui->chbAnimation, &QCheckBox::toggled, ui->openGLWidget, &MyGLWidget::setIsAnimated);
    connect(ui->chbSetCamera, &QCheckBox::toggled, ui->openGLWidget, &MyGLWidget::setCameraToCenter);
    connect(ui->chbMaterial, &QCheckBox::toggled, ui->openGLWidget, &MyGLWidget::setMaterial);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::reset() {
    ui->vsFOV->setValue (45);
    ui->spFOV->setValue (45);
    ui->vsAngle->setValue (75);
    ui->spAngle->setValue (75);
    ui->rbPerspective->setChecked (true);
    ui->chbMaterial->setChecked(false);

    ui->dsbNear->setValue (0.1);
    ui->dsbFar->setValue (100);

    ui->hsRotationA->setValue (0);
    ui->hsRotationB->setValue (0);
    ui->hsRotationC->setValue (0);

}
