#include "treebuilder.h"
#include <iostream>
#include "stdlib.h"
#include <fstream>
#include <string>




void TreeBuilder::setFile(const char *fileName)
{
    file.open(fileName);
}

std::multimap<int, GenomNode*> * TreeBuilder::getGenomMap()
{
    getTree(0)[1];
    file.close();
    return &genomByLevelList;
}

void TreeBuilder::setLevelCount(int level)
{
    if (levelCount < level) levelCount = level;
}

int TreeBuilder::getLevelCount()
{
    return levelCount;
}

GenomNode * TreeBuilder::getTree(int level)
{
    GenomNode * list = new GenomNode[2]();
    GenomNode * subList = NULL;
    QString nodeName = NULL;
    while(!file.eof()){
        char ch;
        file.get(ch);
        if (ch == '(') {
            GenomNode * newList = getTree(level+1);
            subList = newList;
        }
        if (ch == ',') {
            list[0] = *setNode(&nodeName, subList);
            setLevel(&list[0],level,subList);
            nodeName = "";
            subList =  NULL;

        }
        if (ch == ')') {
            break;
        }
        if (isalnum(ch)) {
            nodeName += ch;
        }
        if (ch == '_') {
            nodeName = "";
        }

    }
    if (nodeName != NULL) {
        list[1] = *setNode(&nodeName, subList);
        setLevel(&list[1],level,subList);

        if (level != 0) {
            genomByLevelList.insert(std::make_pair(list[0].getLevel(), &list[0]));
        }
        int lv = list[1].getLevel();
        GenomNode * node = &list[1];
        genomByLevelList.insert(std::make_pair(lv, node));
    }
    return list;
}

GenomNode * TreeBuilder::setNode(QString * name, GenomNode * subList)
{
    GenomNode *currentNode;
    currentNode = new GenomNode();
    currentNode->setGenomName(name);
    currentNode->setLeftChild(&subList[0]);
    currentNode->setRightChild(&subList[1]);
    return currentNode;
}

void TreeBuilder::setLevel(GenomNode * node, int level, GenomNode * subList)
{
    if (subList == NULL) node->level = -1;
    else {
        node->setLevel(level);
        if (node->getLevel() > levelCount) levelCount = node->getLevel();
    }
}

TreeBuilder::TreeBuilder()
{
    levelCount = 0;
}






