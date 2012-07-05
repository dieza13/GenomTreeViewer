#ifndef GENOMNODE_H
#define GENOMNODE_H
#include "QGroupBox"
#include "QLabel"

class GenomNode
{
private:

    GenomNode * leftChild;
    GenomNode * rightChild;
    int nodeX;
    int nodeY;
    double linkLenght;
    int level;


public:
    QWidget * getGenomBody() ;
    QLabel * acidName;
    QGroupBox * genomBody;
    int index;
    GenomNode();
    ~GenomNode();
    void setGenomName(QString * name);
    QString getGenomName();
    void setAcid(QString name);
    QString getAcid();
    void showGenom(QWidget  * parent);
    void setIndex(int parentLevel);
    void setLeftChild(GenomNode * leftChild);
    void setRightChild(GenomNode * rightChild);
    GenomNode * getLeftChild();
    GenomNode * getRightChild();
    int getIndex();
    int getLevel();
    void setNodeX(int x);
    void setNodeY(int y);
    int getNodeX();
    int getNodeY();
    void setLenght(double lenght);
    double getLenght();
    void setAcidColor(QString color);
    void setGenomTitleColor(QString color);
};

#endif // GENOMNODE_H
