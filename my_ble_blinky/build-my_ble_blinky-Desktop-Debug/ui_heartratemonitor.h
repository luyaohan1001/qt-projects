/********************************************************************************
** Form generated from reading UI file 'heartratemonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEARTRATEMONITOR_H
#define UI_HEARTRATEMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HeartRateMonitor
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *HeartRateMonitor)
    {
        if (HeartRateMonitor->objectName().isEmpty())
            HeartRateMonitor->setObjectName(QString::fromUtf8("HeartRateMonitor"));
        HeartRateMonitor->resize(400, 300);
        pushButton = new QPushButton(HeartRateMonitor);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 130, 89, 25));

        retranslateUi(HeartRateMonitor);

        QMetaObject::connectSlotsByName(HeartRateMonitor);
    } // setupUi

    void retranslateUi(QDialog *HeartRateMonitor)
    {
        HeartRateMonitor->setWindowTitle(QCoreApplication::translate("HeartRateMonitor", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("HeartRateMonitor", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HeartRateMonitor: public Ui_HeartRateMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEARTRATEMONITOR_H
