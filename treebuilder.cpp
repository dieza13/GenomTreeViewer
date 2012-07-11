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

void TreeBuilder::closeFile()
{
    file.close();
}

GenomNode * TreeBuilder::getTree(int level)
{
    GenomNode * list = new GenomNode[2]();
    GenomNode * subList = NULL;
    QString nodeName = NULL;
    double lenght = 1;
    while(!file.eof()){
        char ch;
        file.get(ch);
        if (ch == '(') {
            GenomNode * newList = getTree(level+1);
            subList = newList;
        }
        if (ch == ',') {
            list[0] = *setNode(&nodeName, lenght, subList);
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
        if (ch == ':') {
            lenght = getLenght();
        }

    }
    if (nodeName != NULL) {
        list[1] = *setNode(&nodeName, lenght, subList);
        setLevel(&list[1],level,subList);        
        if (level != 0) {
            genomByLevelList.insert(std::make_pair(list[0].getIndex(), &list[0]));
        }
        int lv = list[1].getIndex();
        GenomNode * node = &list[1];
        genomByLevelList.insert(std::make_pair(lv, node));
    }
    return list;
}

GenomNode * TreeBuilder::setNode(QString * name, double lenght, GenomNode * subList)
{
    GenomNode *currentNode;
    currentNode = new GenomNode();
    currentNode->setLenght(lenght);
    std::cout << lenght << std::endl;
    currentNode->setGenomName(name);
    currentNode->setLeftChild(&subList[0]);
    currentNode->setRightChild(&subList[1]);
    return currentNode;
}

void TreeBuilder::setLevel(GenomNode * node, int level, GenomNode * subList)
{
    node->setIndex(level);
    if (subList == NULL) {        
        node->index = -1;
        node->setLeftChild(0);
        node->setRightChild(0);
    }
    else {        
        if (node->getIndex() > levelCount) levelCount = node->getIndex();
    }
}

double TreeBuilder::getLenght()
{
    char ch;
    QString str;
    double lenght;
    file.get(ch);
    while (isalnum(ch) || ch == '.' || ch == ' ')  {
        str += ch;
        file.get(ch);
    }
    file.putback(ch);

    lenght = str.toDouble();
    return lenght;
}

TreeBuilder::TreeBuilder()
{
    levelCount = 0;
}

TreeBuilder::~TreeBuilder()
{
}






