#include "genomnode.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

QWidget *GenomNode::getGenomBody(){
    return genomBody;
}

GenomNode::GenomNode()
{
    level = 0;
    acidName = new QLabel();
    genomBody = new QGroupBox();
    genomBody->setFixedWidth(75);
    genomBody->setFixedHeight(30);
    QFont acidFont("Helvetica", 7);
    QFont titleFont("Helvetica", 8, QFont::Bold);
    genomBody->setFont(titleFont);
    acidName->setFont(acidFont);
    acidName->setFixedWidth(10);
    acidName->setParent(genomBody);
    genomBody->childAt(0,0)->move(5,15);
    leftChild = NULL;
    rightChild = NULL;

}

GenomNode::~GenomNode()
{
//    genomBody->
    delete genomBody, acidName, leftChild, rightChild;

}

void GenomNode::setGenomName(QString * name)
{
    genomBody->setTitle(*name);
}

QString GenomNode::getGenomName()
{
    return genomBody->title();
}

void GenomNode::setAcid(QString name)
{
    acidName->setText(name);
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

void GenomNode::setLevel(int parentLevel)
{
    level = (parentLevel + 1);
}

void GenomNode::setLeftChild(GenomNode * leftChild)
{
    this->leftChild = leftChild;
//    this->leftChild->setLevel(parentLevel);
}

void GenomNode::setRightChild(GenomNode * rightChild)
{
    this->rightChild = rightChild;
//    this->rightChild->setLevel(parentLevel);
}

GenomNode * GenomNode::getLeftChild()
{
    return leftChild;
}

GenomNode * GenomNode::getRightChild()
{
    return rightChild;
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
