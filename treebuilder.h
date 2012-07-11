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

    std::fstream file;
    int levelCount;
    std::multimap<int, GenomNode*> genomByLevelList;

private:
    GenomNode * setNode(QString *name, double lenght, GenomNode *subList);
    void setLevel(GenomNode * node, int level, GenomNode * subList);
    double getLenght();

public:

    TreeBuilder();
    ~TreeBuilder();
    GenomNode*  getTree(int level);
    void setFile(const char *fileName);
    std::multimap<int, GenomNode*> * getGenomMap();
    void setLevelCount(int level);
    int getLevelCount();
    void closeFile();
};

#endif // TREEBUILDER_H
