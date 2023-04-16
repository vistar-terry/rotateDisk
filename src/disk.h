#ifndef DISK_H
#define DISK_H

#include <QPushButton>

class Disk : public QPushButton
{
    Q_OBJECT
public:
    Disk(QString imgPath, bool flag = 1);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int setAngle();

private:
    bool rotateFlag; //对象是否可以旋转
    QString btnImg; //按钮背景图片路径
    QPixmap pix; //按钮背景图片对象
    qreal scale; //图片缩放等级

    int oldAngle = 0; //图片拖动前的角度位置
    int currentAngle = 0; //图片拖动后的角度位置
    int mouseAngle = 0; //鼠标拖动的角度

    QPointF pressPoint; //鼠标点击点
    QPointF currentPoint; //鼠标当前点
    QPointF corePoint; //旋转中心点

signals:

};

#endif // DISK_H
