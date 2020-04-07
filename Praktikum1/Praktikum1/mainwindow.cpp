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
    connect(ui->dsbNear, &QDoubleSpinBox::setValue, ui->openGLWidget, &MyGLWidget::setNear);
    connect(ui->dsbFar, &QDoubleSpinBox::setValue, ui->openGLWidget, &MyGLWidget::setFar);
    connect(ui->hsRotationA, &QSlider::valueChanged, ui->openGLWidget, &MyGLWidget::setRotationA);
    connect(ui->hsRotationB, &QSlider::valueChanged, ui->openGLWidget, &MyGLWidget::setRotationB);
    connect(ui->hsRotationC, &QSlider::valueChanged, ui->openGLWidget, &MyGLWidget::setRotationC);
}

MainWindow::~MainWindow() {
    delete ui;
}

