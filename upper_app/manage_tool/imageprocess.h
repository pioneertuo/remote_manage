#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include "typedef.h"

#include <QFileDialog>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "mainwindow.h"
#include "ui_mainwindow.h"

class COpencvImgProcess;

// ͼ��ת��
class COpencvImgProcess
{
public:
    COpencvImgProcess(){};
    ~COpencvImgProcess(){};
//    QImage cvMattoImage(const cv::Mat& mat)
//    {
//        if(mat.type() == CV_8UC1)					// ��ͨ��
//        {
//            QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
//            image.setColorCount(256);				// �Ҷȼ���256
//                for (int i = 0; i < 256; i++)
//                {
//                    image.setColor(i, qRgb(i, i, i));
//                }
//                uchar *pSrc = mat.data;					// ����mat����
//                for (int row = 0; row < mat.rows; row++)
//                {
//                    uchar *pDest = image.scanLine(row);
//                    memcpy(pDest, pSrc, mat.cols);
//                    pSrc += mat.step;
//                }
//                return image;
//            }

//            else if (mat.type() == CV_8UC3)				// 3ͨ��
//            {
//                const uchar *pSrc = (const uchar*)mat.data;			// ��������
//                QImage image(pSrc, mat.cols, mat.rows, (int)mat.step, QImage::Format_RGB888);	// R, G, B ��Ӧ 0,1,2
//                return image.rgbSwapped();				// rgbSwapped��Ϊ����ʾЧ��ɫ�ʺ�һЩ��
//            }
//            else if (mat.type() == CV_8UC4)
//            {
//                const uchar *pSrc = (const uchar*)mat.data;			// ��������
//                    // Create QImage with same dimensions as input Mat
//                QImage image(pSrc,mat.cols, mat.rows, (int)mat.step, QImage::Format_ARGB32);		// B,G,R,A ��Ӧ 0,1,2,3
//                return image.copy();
//            }
//            else
//            {
//                return QImage();
//            }
//    }

    //virtual cv::Mat QImage2cvMat(QImage image) = 0;			// QImage �ĳ� Mat
    //virtual QImage splitBGR(QImage src, int color) = 0;			// ��ȡRGB����
    //virtual QImage splitColor(QImage src, cv::String model, int color) = 0;		// ��ȡ����

    void load_image(QLabel *label, QString Path)
    {
        QImage image;
        if(!(image.load(Path))){
            qDebug()<<"Image load failed, Path:"<<Path;
            return;
        }
        qDebug()<<"Image load ok";
        label->clear();
        label->setPixmap(QPixmap::fromImage(image));
        label->setScaledContents(true);
//        cv::Mat ImgMat = cv::imread(Path.toStdString(), 1);
//        QImage image = cvMattoImage(ImgMat);
//        qDebug()<<"Image load ok";
//        label->clear();
//        label->setPixmap(QPixmap::fromImage(image));
//        label->setScaledContents(true);
    }

    void load_image(QLabel *label, QImage *pImage)
    {
        label->clear();
        label->setPixmap(QPixmap::fromImage(*pImage));
        label->setScaledContents(true);
    }
};


#endif // IMAGEPROCESS_H
