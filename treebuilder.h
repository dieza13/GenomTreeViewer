#ifndef TREEBUILDER_H
#define TREEBUILDER_H
#include "string"
#include "iostream"
#include "stdlib.h"
#include "fstream"
#include "QStandardItem"
#include "QStandardItemModel"
#include "vector"
#include "genomnode.h"
#include "map"

class TreeBuilder
{
//    vector<GenomNode> genomList;
private:
    GenomNode * setNode(QString *name, GenomNode * subList);
    std::fstream file;
    int levelCount;
    std::multimap<int, GenomNode*> genomByLevelList;
    void setLevel(GenomNode * node, int level, GenomNode * subList);

public:

    TreeBuilder();
//    QList<QStandardItem*>   getTree();
    GenomNode*  getTree(int level);
    void setFile(const char *fileName);
    std::multimap<int, GenomNode*> * getGenomMap();
    void setLevelCount(int level);
    int getLevelCount();
};

#endif // TREEBUILDER_H
