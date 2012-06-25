#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsView"
#include "treecreatercontext.h"
#include "acidsetcontext.h"
#include "QVBoxLayout"
#include "stdlib.h"
#include "QFileDialog"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainNode = NULL;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete acidSetContext;
    delete mainNode;
}

void MainWindow::on_pushButton_clicked()
{
   const char * path = openFileDialog(0);
   if (path != NULL){
        if (!mainNode == NULL) {
            deleteNodes(mainNode);
        }
        TreeCreaterContext * treeCreaterContext = new TreeCreaterContext();
        mainNode = treeCreaterContext->createTree(path,ui->graphicsView);
   }


}

void MainWindow::on_pushButton_2_clicked()
{
    const char * path = openFileDialog(1);

    ui->horizontalSlider->setEnabled(true);
    acidSetContext = new AcidSetContext();
    acidSetContext->setAcidsArray(path,ui->horizontalSlider);
    acidSetContext->setAcids(mainNode,0);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    acidSetContext->setAcids(mainNode, value);
}

const char * MainWindow::openFileDialog(int i)
{
    QString str = QFileDialog::getOpenFileName().toUtf8();
    if( (str.endsWith(".tree") && (i == 0)) || (str.endsWith(".fasta")  && (i == 1))) {
        std::string fileName = str.toAscii().data();
        if (fileName.compare("") == 0) {
            return fileName.c_str();
        }
        return fileName.c_str();
    }
    return NULL;
}


void MainWindow::deleteNodes(GenomNode *node)
{
    if (node->getLeftChild() != NULL) {
        deleteNodes(node->getLeftChild());
        deleteNodes(node->getRightChild());
    }
     ui->graphicsView->childAt(node->getNodeX(),node->getNodeY())->close();
}

