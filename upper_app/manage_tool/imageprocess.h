#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include "typedef.h"

#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#if USE_OPENCV == 1
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#endif

class COpencvImgProcess
{
public:
    COpencvImgProcess(){};
    ~COpencvImgProcess(){};

    //���ݵ�ַ����ͼ��
    bool load_image(QLabel *label, QString Path);
    void load_image(QLabel *label, const QImage &image);

    void set_file_extra(const QString &str)
    {
        file_extra = str;
    }

    const QString get_file_extra()
    {
        return file_extra;
    }

#if USE_OPENCV == 1
    void load_image(QLabel *label, const cv::Mat &mat);

    //ͼ���ֵ�˲�
    bool blur_image(QLabel *label, QString Path);

    //ͼ��Ҷ�ת��
    bool gray_image(QLabel *label, QString Path);

    //ͼ��ʴ -- ����������С
    bool erode_image(QLabel *label, QString Path);

    //ͼ������ -- ������������
    bool dilate_image(QLabel *label, QString Path);

    //��Ե���
    bool canny_image(QLabel *label, QString Path);

    //������չ
    bool line_scale_image(QLabel *label, QString Path);

    //��������չ
    bool noline_scale_image(QLabel *label, QString Path);

    //ֱ��ͼ����
    bool equalizeHist_image(QLabel *label, QString Path);

    //����任
    bool warpaffine_image(QLabel *label, QString Path);

    //�����߱任
    bool houghlines_image(QLabel *label, QString Path);

    //ֱ��ͼ
    bool hist_image(QLabel *label, QString Path);
#else
    //ͼ���ֵ�˲�
    void blur_image(QLabel *label, QString Path){
        return load_image(label, Path);
    };

    //ͼ��ʴ -- ����������С
    void erode_image(QLabel *label, QString Path){
        return load_image(label, Path);
    };

    //ͼ������ -- ������������
    void dilate_image(QLabel *label, QString Path){
       return load_image(label, Path);
    };

    //��Ե���
    void canny_image(QLabel *label, QString Path){
        return load_image(label, Path);
    };


    //������չ
    bool line_scale_image(QLabel *label, QString Path){
        return load_image(label, Path);
    };

    //��������չ
    bool noline_scale_image(QLabel *label, QString Path){
        return load_image(label, Path);
    };

    //ֱ��ͼ����
    bool equalizeHist_image(QLabel *label, QString Path){
        return load_image(label, Path);
    };

    //����任
    bool warpaffine_image(QLabel *label, QString Path){
        return load_image(label, Path);
    };

    //�����߱任
    bool houghlines_image(QLabel *label, QString Path){
        return load_image(label, Path);
    }

    //ֱ��ͼ
    bool hist_image(QLabel *label, QString Path)��
        return load_image(label, Path);
    ��
#endif

private:
    QString file_extra{""};

#if USE_OPENCV == 1
    //��Opencv�ڲ�ͼ��ת��ΪQImage����
    QImage cvMattoQImage(const cv::Mat& mat);
    cv::Mat QImagetocvMat(const QImage &image);			// QImage �ĳ� Mat
#endif
};


#endif // IMAGEPROCESS_H
