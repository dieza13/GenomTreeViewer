#include "genomnode.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPalette"


QWidget *GenomNode::getGenomBody(){
    return genomBody;
}

GenomNode::GenomNode()
{
    index = 0;
    acidName = new QLabel();    
    genomBody = new QGroupBox();    
    genomBody->setFixedHeight(30);
    QFont acidFont("Helvetica", 7);
    QFont titleFont("Helvetica", 8, QFont::Bold);
    genomBody->setFont(titleFont);
    acidName->setFont(acidFont);
    acidName->setFixedWidth(100);
    acidName->setParent(genomBody);
    genomBody->childAt(0,0)->move(5,15);
    QString color = "black";
    QPalette pal;
    pal.setColor(QPalette::Text, color);
    genomBody->setPalette(pal);
    acidName->setPalette(pal);
    rightChild = 0;
    leftChild = 0;
    nodeX = 0;
    nodeY = 0;


}

GenomNode::~GenomNode()
{
    delete acidName;
    delete genomBody;
    delete leftChild;
    delete rightChild;
}



void GenomNode::setGenomName(QString * name)
{
    genomBody->setTitle(*name);

    genomBody->setFixedWidth(name->size() * 7 + 7);
}

QString GenomNode::getGenomName()
{
    return genomBody->title();
}

void GenomNode::setAcid(QString name)
{

    acidName->setText(name);
    acidName->setFixedWidth(15);

}

QString GenomNode::getAcid()
{
    return acidName->text();
}

void GenomNode::showGenom(QWidget  * parent)
{
    genomBody->setParent(parent);
    genomBody->show();
    acidName->show();
}

void GenomNode::setIndex(int parentLevel)
{
    index = (parentLevel + 1);
    level = (parentLevel + 1);
}

void GenomNode::setLeftChild(GenomNode * leftChild)
{
    this->leftChild = leftChild;
}

void GenomNode::setRightChild(GenomNode * rightChild)
{
    this->rightChild = rightChild;
}

GenomNode * GenomNode::getLeftChild()
{
    return leftChild;
}

GenomNode * GenomNode::getRightChild()
{
    return rightChild;
}

int GenomNode::getIndex()
{
    return index;
}

int GenomNode::getLevel()
{
    return level;
}

void GenomNode::setNodeX(int x)
{
    nodeX = x;
}

void GenomNode::setNodeY(int y)
{
    nodeY = y;
}

int GenomNode::getNodeX()
{
    return nodeX;
}

int GenomNode::getNodeY()
{
    return nodeY;
}

void GenomNode::setLenght(double lenght)
{
    linkLenght = lenght;
}

double GenomNode::getLenght()
{
    return linkLenght;
}

void GenomNode::setAcidColor(QString color)
{
    QPalette pal;
    pal.setColor(QPalette::Text, color);

    if (leftChild != NULL) {
        leftChild->setAcidColor(color);
        rightChild->setAcidColor(color);
    }
    acidName->setPalette(pal);
}

void GenomNode::setGenomTitleColor(QString color)
{
    QPalette pal;
    pal.setColor(QPalette::Text, color);

    if (leftChild != NULL) {
        leftChild->setGenomTitleColor(color);
        rightChild->setGenomTitleColor(color);
    }

    genomBody->setStyleSheet("QGroupBox::title {color:" + color + ";}");
}
