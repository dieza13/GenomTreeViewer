#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsView"
#include "treecreatercontext.h"
#include "acidsetcontext.h"
#include "QVBoxLayout"
#include "stdlib.h"
#include "QFileDialog"
#include <QDesktopWidget>
#include "QList"
#include "QMessageBox"
#include "QMouseEvent"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainNode = NULL;
    desktopX = QApplication::desktop()->width();
    desktopY = QApplication::desktop()->height();
    ui->centralWidget->setMinimumWidth(desktopX * 0.67);
    ui->centralWidget->setMinimumHeight(desktopY * 0.67);
    treeCreaterContext = 0;
    acidSetContext = 0;
    ui->pushButton->setMouseTracking(true);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->viewport()->installEventFilter(ui->graphicsView);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->viewport()->installEventFilter(ui->centralWidget);



}

MainWindow::~MainWindow()
{
    mainNode = NULL;
    delete ui;
    delete acidSetContext;
    delete treeCreaterContext;
    delete mainNode;
}



void MainWindow::on_pushButton_clicked()
{
    ui->extended->setEnabled(true);
    bool extended = ui->extended->isChecked();
   const char * path = openFileDialog(0);
   if (path != NULL){
       ui->typeComboBox->setEnabled(true);
        if (mainNode != NULL) {
            deleteNodes(mainNode);
        }
//        delete mainNode;
        mainNode = 0;
        delete treeCreaterContext;
        treeCreaterContext = new TreeCreaterContext();
        mainNode = treeCreaterContext->createTree(path,ui->graphicsView, extended);
   }
}

void MainWindow::on_pushButton_2_clicked()
{
    const char * path = openFileDialog(1);
    if (path != NULL){        
        ui->AcidComboBox->setEnabled(true);
        ui->horizontalSlider->setEnabled(true);
        ui->spinBox->setEnabled(true);
        delete acidSetContext;
        acidSetContext = new AcidSetContext();
        acidSetContext->setAcidsArray(path,ui->horizontalSlider, ui->spinBox);
        acidSetContext->setAcids(mainNode,0);
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    acidSetContext->setAcids(mainNode, value);
    ui->spinBox->setValue(value);
}

const char * MainWindow::openFileDialog(int i)
{
    QString str = QFileDialog::getOpenFileName().toUtf8();
    if( (str.endsWith(".tree") && (i == 0)) || (str.endsWith(".fasta")  && (i == 1)) || (str.endsWith(".nwk")  && (i == 0))) {
        std::string fileName = str.toAscii().data();
        if (fileName.compare("") == 0) {
            return fileName.c_str();
        }
        return fileName.c_str();
    }
    return 0;
}


void MainWindow::deleteNodes(GenomNode *node)
{
    if (node->getLeftChild() != NULL) {
        deleteNodes(node->getLeftChild());
        deleteNodes(node->getRightChild());
    }
    node->genomBody->close();
}




void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{
    ui->horizontalSlider->setValue(arg1.toInt());
}

void MainWindow::resizeEvent(QResizeEvent *event)
{  
    reDraw();

}

void MainWindow::on_extended_clicked()
{
    if (!ui->extended->isChecked()) ui->extended->setIcon(QIcon(":/nonequal"));
    else  ui->extended->setIcon(QIcon(":/equal"));
    reDraw();
}

void MainWindow::reDraw()
{
    int x = ui->centralWidget->width();
    int y = ui->centralWidget->height();
    ui->graphicsView->setGeometry(0, 108, x, y - 88);
    bool extended = ui->extended->isChecked();
    if (mainNode != NULL) {
        treeCreaterContext->redrawTree(ui->graphicsView, extended);
    }
}

void MainWindow::on_typeComboBox_activated(const QString &arg1)
{

    if (mainNode != NULL) {
        mainNode->setGenomTitleColor(arg1);
    }
}

void MainWindow::on_AcidComboBox_activated(const QString &arg1)
{
    if (mainNode != NULL) {
        mainNode->setAcidColor(arg1);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
   std::cout << event->pos().x() << " " << event->pos().y() << std::endl;
       int x = event->pos().x();
       int y = event->pos().y() - ui->graphicsView->y();
       treeCreaterContext->reflectBranch(mainNode,ui->graphicsView,x,y);
}

//void QGraphicsView::mousePressEvent(QMouseEvent *event)
//{
//    std::cout << event->pos().x() << std::endl;
//    int x = event->pos().x();
//    int y = event->pos().y();



//}










