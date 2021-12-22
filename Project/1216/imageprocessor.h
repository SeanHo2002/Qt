#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QImage>
#include <QLabel>
class ImageProcessor : public QMainWindow{
    Q_OBJECT

public:
    ImageProcessor(QWidget *parent = nullptr);
    ~ImageProcessor();
    void createActions();
    void createMenu();
    void createToolBars();
    void loadFile(QString filename);
private slots:
    void showOpenFile();
    void setImageSizeBig();
    void setImageSizeSmall();
private:
    QWidget  *central;
    QMenu    *fileMenu;
    QToolBar *fileTool;
    QImage   img;
    QString  filename;
    QLabel   *imgWin,*result;
    QAction  *openFileActon;
    QAction  *exitAction;
    QAction  *enlargeAction;
    QAction  *narrowAction;
};
#endif // IMAGEPROCESSOR_H
