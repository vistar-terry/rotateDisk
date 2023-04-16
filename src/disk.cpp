//***************************************************************************
// 作者：万俟淋曦
//
// 编写时间：2020年2月20日07:50:43
//
// 使用软件：Qt Creator 4.11.0
//
// 编写环境：Qt 5.14.0 (MSVC 2017, 32 bit)
//
// 功能：鼠标拖动旋转
//
// 最后修改：2020年4月4日22:35:17
//
// 笔者刚刚学习这块内容，如有不妥之处，欢迎交流，QQ:1055311345, 群：483166883
//***************************************************************************

#include "disk.h"
#include <QDebug>
#include <QBitmap>
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>

Disk::Disk(QString imgPath, bool flag){
    btnImg = imgPath;
    rotateFlag = flag;

    bool ret = pix.load(btnImg);
    if(!ret){
        QString str = QString("图片 %1 加载失败！").arg(btnImg);
        qDebug() << str;
        return;
    }
    scale = 1;
    corePoint = QPointF(this->width()/qreal(2), this->height()/qreal(2));

    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setMask(QBitmap(pix.mask()));
    //设置初始背景图
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
}

//鼠标拖动旋转的角度
int Disk::setAngle(){
    QLineF lineBegin(corePoint, pressPoint);
    QLineF lineEnd(corePoint, currentPoint);
    mouseAngle = 360 - lineBegin.angleTo(lineEnd);
    return mouseAngle;
}

//鼠标按下事件
void Disk::mousePressEvent(QMouseEvent *event){
    pressPoint = event->pos();
    oldAngle = currentAngle;
}

//鼠标移动事件
void Disk::mouseMoveEvent(QMouseEvent *event){
    currentPoint = event->pos();

    if(oldAngle > 360){
        oldAngle = oldAngle % 360;
    }

    currentAngle = setAngle() + oldAngle;

    if(currentAngle > 360){
        currentAngle = currentAngle % 360;
    }
////    //输出旋转角度
//    qDebug() << btnImg << "oldAngle" << oldAngle;
//    qDebug() << btnImg << "mouseAngle" << mouseAngle;
//    qDebug() << btnImg << "currentAngle" << currentAngle;

    if(rotateFlag){
        QTransform rotatematrix;
        rotatematrix.rotate(currentAngle); //通过角度创建旋转矩阵
        QPixmap fitpixmap = pix.transformed(rotatematrix,Qt::SmoothTransformation);//旋转

        // 更新背景图
        this->setIcon(fitpixmap);
        this->setIconSize(QSize(fitpixmap.width(), fitpixmap.height()));
    }
}

