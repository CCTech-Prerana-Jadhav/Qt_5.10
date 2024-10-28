#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

#include "Triangulation.h"

class Visualizer : public QMainWindow
{
    Q_OBJECT

public:
    Visualizer(QWidget *parent = nullptr);
    ~Visualizer();

private slots:
    void onSTLLoadFileClick();
    void onOBJTranslateClick();
    void onOBJLoadFileClick();
    void onSTLTranslateClick();

private:
    void setupUi();

private:
    Triangulation triangulation;

    QPushButton* STLFileLoad;
    QPushButton* OBJTranslate;
    QPushButton* OBJFileLoad;
    QPushButton* STLTranslate;
    QTextEdit* loadEdit1;
    QTextEdit* translateEdit1;
    QTextEdit* loadEdit2;
    QTextEdit* translateEdit2;
};
