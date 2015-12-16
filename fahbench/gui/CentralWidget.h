#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTableView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QPushButton>
#include <QFormLayout>
#include <QComboBox>
#include <QCheckBox>
#include <QSpinBox>

#include "DeviceTableModel.h"

enum OPENMM_PLATFORMS {
    OpenCL = 0,
    CPU = 1
};


class CentralWidget :  public QWidget {
    Q_OBJECT

public:
    CentralWidget();
    QSize sizeHint() const;

    DeviceTableModel  * device_table_model;
    QTableView * device_table_view;

    QLabel * status_bar;

    QProgressBar * progress_bar;
    QPushButton * start_button;

private:
    QVBoxLayout * layout_vbox;
    QHBoxLayout * layout_leftright;
    QFormLayout * layout_form;
    QVBoxLayout * layout_rightpanel;
    QHBoxLayout * layout_bot;

    // Config stuff to be put in `layout_form`
    QComboBox * device_wid;
    QComboBox * openmm_platform_wid;
    QComboBox * precision_wid;
    QComboBox * wu_wid;
    QCheckBox * accuracy_check_wid;
    QSpinBox * nan_check_wid;
    QSpinBox * run_length_wid;

    // Right panel stuff
    QLabel * placeholder_wid;



public slots:
    void progress_update(int, int, float);
    void message_update(const QString &);

private slots:
    void openmm_platform_changed(int);


};

#endif // CENTRALWIDGET_H
