#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "genomnode.h"
#include "acidsetcontext.h"
#include "treecreatercontext.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(const QString &arg1);


    void on_extended_clicked();

    void on_typeComboBox_activated(const QString &arg1);

    void on_AcidComboBox_activated(const QString &arg1);

private:
    GenomNode * mainNode;
    AcidSetContext * acidSetContext;
    Ui::MainWindow * ui;
    TreeCreaterContext * treeCreaterContext;
    int desktopX;
    int desktopY;

private:
    const char * openFileDialog(int i);
    void deleteNodes(GenomNode * node);
    void resizeEvent(QResizeEvent* event);
    void closeNodes(GenomNode *node);
    void reDraw();
};



#endif // MAINWINDOW_H
