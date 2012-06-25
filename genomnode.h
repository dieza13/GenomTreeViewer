#ifndef GENOMNODE_H
#define GENOMNODE_H
#include "QGroupBox"
#include "QLabel"

class GenomNode
{
private:

    QLabel * acidName;
    GenomNode * leftChild;
    GenomNode * rightChild;
    int nodeX;
    int nodeY;

public:
    QWidget * getGenomBody() ;


    QGroupBox * genomBody;
    int level;
    GenomNode();
    ~GenomNode();
    void setGenomName(QString * name);
    QString getGenomName();
    void setAcid(QString name);
    QString getAcid();
    void showGenom(QWidget  * parent);
    void setLevel(int parentLevel);
    void setLeftChild(GenomNode * leftChild);
    void setRightChild(GenomNode * rightChild);
    GenomNode * getLeftChild();
    GenomNode * getRightChild();
    int getLevel();
    void setNodeX(int x);
    void setNodeY(int y);
    int getNodeX();
    int getNodeY();

};

#endif // GENOMNODE_H
