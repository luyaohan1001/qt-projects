/********************************************************************************
** Form generated from reading UI file 'heartratemonitordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEARTRATEMONITORDIALOG_H
#define UI_HEARTRATEMONITORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_HeartRateMonitorDialog
{
public:
    QLabel *labelHeartRateValue;

    void setupUi(QDialog *HeartRateMonitorDialog)
    {
        if (HeartRateMonitorDialog->objectName().isEmpty())
            HeartRateMonitorDialog->setObjectName(QString::fromUtf8("HeartRateMonitorDialog"));
        HeartRateMonitorDialog->resize(400, 300);
        labelHeartRateValue = new QLabel(HeartRateMonitorDialog);
        labelHeartRateValue->setObjectName(QString::fromUtf8("labelHeartRateValue"));
        labelHeartRateValue->setGeometry(QRect(180, 110, 67, 17));

        retranslateUi(HeartRateMonitorDialog);

        QMetaObject::connectSlotsByName(HeartRateMonitorDialog);
    } // setupUi

    void retranslateUi(QDialog *HeartRateMonitorDialog)
    {
        HeartRateMonitorDialog->setWindowTitle(QCoreApplication::translate("HeartRateMonitorDialog", "Dialog", nullptr));
        labelHeartRateValue->setText(QCoreApplication::translate("HeartRateMonitorDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HeartRateMonitorDialog: public Ui_HeartRateMonitorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEARTRATEMONITORDIALOG_H
