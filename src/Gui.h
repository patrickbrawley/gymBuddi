#ifndef SIGNAPSE_GUI_H
#define SIGNAPSE_GUI_H

#include <QCoreApplication>
#include "QtGeneratedGui.h"
#include "stdlib.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

#include "ProgressBar.h"
#include "gymBuddi.h"
#include "SceneCallback.h"

#define testFolder "test/pose_test/"


class Gui : public QWidget, public SceneCallback{
    Q_OBJECT
public:
    virtual void NextScene(Scene next);
    Gui(QMainWindow* win, Ui_MainWindow* ui_win);
    void SetVisible(bool visible);
    void SetTargetImage(int target);
    void SetTargetImage(std::string target);
    void SetTask(std::string newTask);
    void buttonPressed();
    void updateThreshold();


private:
    QMainWindow *widget;
    Ui_MainWindow *ui;
    ProgressBar progressBar;
    void setDemoImage(cv::Mat img);
    void setTaskText(std::string letter);
    void makeConnections();
    std::string currentTask;
signals:
    void progressChanged(int progress);
    
};

#endif
