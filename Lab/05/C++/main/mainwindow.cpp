#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QFileDialog>
#include <QBitArray>
#include <QFile>



bool Bit(QImage img, int count) {
    int x = (count / 3) % img.width();
    int y = (count / 3) / img.width();
    int result = count % 3;
    if (result == 0)
        return (img.pixel(x, y) >> 16) & 1;
    else if (result == 1)
        return (img.pixel(x, y) >> 8) & 1;
    else
        return img.pixel(x, y) & 1;

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::loadImage);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::saveImage);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::encodeMsg);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::decodeMsg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Допустимые форматы (*.png)"));
    img.load(fileName,"PNG");
    img.convertTo(QImage::Format_ARGB32);
    if (img.load(fileName, "PNG")) {
           ui->label->setText("Изображение успешно загружено");
           return;
       }
    else{
       ui->label->setText("Изображение не загружено");
    }
}

void MainWindow::saveImage()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить картинку"), "", tr("Допустимые форматы (*.png)"));
    if (img.save(fileName, "PNG")) {
            ui->label->setText("Изображение успешно сохранено");
        }
    else {
            ui->label->setText("Изображение не сохранено");
        }
}

void MainWindow::encodeMsg()
{
    QString text = ui->plainTextEdit->toPlainText();
    QByteArray charset = text.toUtf8();
    int bytes_size = charset.size();
    img_size = (img.width() * img.height() * 3) / 8 - const_marker.size()-messageLength;
    if (img_size<bytes_size ) {
        ui->label->setText("Ошибка. Не достаточно места!");
        return;
    }
    QByteArray vector_b;
        vector_b.push_back(const_marker);
        for (int i = messageLength - 1; i >= 0; i--) {
            vector_b.push_back((bytes_size >> i*8) & 0xff);
        }
        QString str = ui->plainTextEdit->toPlainText();
        QByteArray charsets = str.toUtf8();
        vector_b.push_back(charsets);
        int index = 0;
        int stop = (index + vector_b.size()) * 8;
        for (int i = index * 8; i < stop; ++i) {

            int x = (i / 3) % img.width();
            int y = (i / 3) / img.width();
            bool sh = (vector_b[i / 8] >> (7 - i % 8)) & 1;
            int rez = i % 3;
            if (rez == 0)
                img.setPixel(x, y, (img.pixel(x, y) & ~0x010000) | (sh << 16));
            else if (rez == 1)
                img.setPixel(x, y, (img.pixel(x, y) & ~0x000100) | (sh << 8));
            else
                img.setPixel(x, y, (img.pixel(x, y) & ~0x000001) | sh);
        }

       ui->label->setText("Сообщение добавлено в картинку!");

}

void MainWindow::decodeMsg()
{

        QByteArray vector_b;
        char count = 0;
        int index = 0;

        int last = (index + need_size) * 8;



        for (int i = index * 8; i < last; ++i) {
            count = (count << 1) | Bit(img, i);

            if (i % 8 == 7) {
                vector_b.push_back(count);
                count = 0;
            }
        }

        for (int i = 0; i < const_marker.size(); ++i) {
            if (const_marker[i] != vector_b[i]) {
                ui->label->setText("Сообщение не обнаружено");
                return;
            }
        }

        int size = 0;
        for (int i = const_marker.size(); i < const_marker.size() + messageLength; ++i) {
            size = (size << 8) + static_cast<unsigned char>(vector_b[i]);
        }

        if (size > img_size) {
            ui->label->setText("Ошибка. Размер сообщения в заголовке превышает размер изображения");
            return;
        }


        QByteArray vector_byte2;
        char count2 = 0;
        int index2 = need_size;

        int last2 = (index2 + size) * 8;



        for (int i = index2 * 8; i < last2; ++i) {
            count2 = (count2 << 1) | Bit(img, i);

            if (i % 8 == 7) {
                vector_byte2.push_back(count2);
                count2 = 0;
            }
        }


        QString text = QString::fromUtf8(vector_byte2);

        ui->plainTextEdit->setPlainText(text);
        ui->label->setText(QString("Присутствует сообщение длиной %1 байт").arg(img_size-bytes_size));

}

