#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QImage img;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void loadImage();
    void saveImage();
    void encodeMsg();
    void decodeMsg();

private:

    Ui::MainWindow *ui;
    int messageLength = 4;
    int img_size;
    int bytes_size;
    const std::array<char, 3> const_marker {
           static_cast<char>(0b11100010),
           static_cast<char>(0b10011101),
           static_cast<char>(0b10100100)
       };

    int need_size = messageLength + const_marker.size();
};
#endif // MAINWINDOW_H
