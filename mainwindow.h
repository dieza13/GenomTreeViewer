#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "genomnode.h"
#include "acidsetcontext.h"

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


private:
    GenomNode * mainNode;
    AcidSetContext * acidSetContext;
    Ui::MainWindow * ui;

private:
    const char * openFileDialog(int i);
    void deleteNodes(GenomNode * node);
    void resizeEvent(QResizeEvent* event);
};



#endif // MAINWINDOW_H
