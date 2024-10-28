#include <QFileDialog>
#include <QGridLayout>
#include "Visualizer.h"
#include "STLReader.h"
#include "DataWriter.h"
#include "ObjWriter.h"
#include "OBJReader.h"
#include "STLWriter.h"

Visualizer::Visualizer(QWidget* parent)
    : QMainWindow(parent)
{
    setupUi();

    connect(STLFileLoad, &QPushButton::clicked, this, &Visualizer::onSTLLoadFileClick);
    connect(OBJTranslate, &QPushButton::clicked, this, &Visualizer::onOBJTranslateClick);
    connect(OBJFileLoad, &QPushButton::clicked, this, &Visualizer::onOBJLoadFileClick);
    connect(STLTranslate, &QPushButton::clicked, this, &Visualizer::onSTLTranslateClick);
}

Visualizer::~Visualizer()
{

}

void Visualizer::setupUi()
{
    STLFileLoad = new QPushButton("Load STL File", this);
    OBJTranslate = new QPushButton("OBJ Translator", this);
    loadEdit1 = new QTextEdit(this);
    translateEdit1 = new QTextEdit(this);

    OBJFileLoad = new QPushButton("Load OBJ File", this);
    STLTranslate = new QPushButton("STL Translator", this);
    loadEdit2 = new QTextEdit(this);
    translateEdit2 = new QTextEdit(this);

    QGridLayout* layout = new QGridLayout(this);

    layout->addWidget(STLFileLoad, 0, 0);
    layout->addWidget(OBJTranslate, 1, 0);
    layout->addWidget(loadEdit1, 0, 1);
    layout->addWidget(translateEdit1, 1, 1);
    layout->addWidget(OBJFileLoad, 2, 0);
    layout->addWidget(STLTranslate, 3, 0);
    layout->addWidget(loadEdit2, 2, 1);
    layout->addWidget(translateEdit2, 3, 1);

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);

    STLFileLoad->setFixedSize(100, 30);
    OBJTranslate->setFixedSize(100, 30);
    loadEdit1->setFixedHeight(30);
    translateEdit1->setFixedHeight(30);

    loadEdit1->setReadOnly(true);
    translateEdit1->setReadOnly(true);

    OBJFileLoad->setFixedSize(100, 30);
    STLTranslate->setFixedSize(100, 30);
    loadEdit2->setFixedHeight(30);
    translateEdit2->setFixedHeight(30);

    loadEdit2->setReadOnly(true);
    translateEdit2->setReadOnly(true);
}

void  Visualizer::onSTLLoadFileClick()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open STL File"), "", tr("STL Files (*.stl)"));

    if (!fileName.isEmpty())
    {
        loadEdit1->clear();
        
        STLReader reader;
        reader.read(fileName.toStdString(), triangulation);

        loadEdit1->setText("File loaded successfully from - " + fileName);
    }
}

void Visualizer::onOBJTranslateClick()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Data File"), "/data", tr("Data Files (*.obj)"));

    if (!fileName.isEmpty())
    {
        translateEdit1->clear();
        
        ObjWriter writer;
        writer.Write(fileName.toStdString(), triangulation);

        translateEdit1->setText("File saved successfully to - " + fileName);

    }
}

void  Visualizer::onOBJLoadFileClick()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open OBJ File"), "", tr("OBJ Files (*.obj)"));

    if (!fileName.isEmpty())
    {
        loadEdit2->clear();

        OBJReader objreader;
        objreader.read(fileName.toStdString(), triangulation);

        loadEdit2->setText("File loaded successfully from - " + fileName);
    }
}

void Visualizer::onSTLTranslateClick()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Data File"), "/data", tr("Data Files (*.stl)"));

    if (!fileName.isEmpty())
    {
        translateEdit2->clear();

        STLWriter writer;
        writer.Write(fileName.toStdString(), triangulation);

        translateEdit2->setText("File saved successfully to - " + fileName);

    }
}
