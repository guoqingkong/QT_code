#ifndef EXAMPLEWIDGET_H
#define EXAMPLEWIDGET_H
/****************************************************************************
 **
 ** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 ** All rights reserved.
 ** Contact: Nokia Corporation (qt-info@nokia.com)
 **
 ** This file is part of the examples of the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:LGPL$
 ** No Commercial Usage
 ** This file contains pre-release code and may not be distributed.
 ** You may use this file in accordance with the terms and conditions
 ** contained in the Technology Preview License Agreement accompanying
 ** this package.
 **
 ** GNU Lesser General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU Lesser
 ** General Public License version 2.1 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.LGPL included in the
 ** packaging of this file.  Please review the following information to
 ** ensure the GNU Lesser General Public License version 2.1 requirements
 ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
 **
 ** In addition, as a special exception, Nokia gives you certain additional
 ** rights.  These rights are described in the Nokia Qt LGPL Exception
 ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
 **
 ** If you have questions regarding the use of this file, please contact
 ** Nokia at qt-info@nokia.com.
 **
 **
 **
 **
 **
 **
 **
 **
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

 #include <QWidget>
 #include <QPushButton>
 #include <QVBoxLayout>
 #include <QTextBrowser>
 #include <QMaemo5InformationBox>

 class ExampleWidget : public QWidget
 {
     Q_OBJECT
 public:
     ExampleWidget()
     {
         QVBoxLayout *layout = new QVBoxLayout(this);

         QPushButton *bannerButton = new QPushButton("Show a Banner");
         QPushButton *noteButton = new QPushButton("Show a Note");
         QPushButton *complexNoteButton = new QPushButton("Show a complex Note");

         layout->addWidget(bannerButton);
         layout->addWidget(noteButton);
         layout->addWidget(complexNoteButton);

         connect(bannerButton, SIGNAL(clicked()), SLOT(showBanner()));
         connect(noteButton, SIGNAL(clicked()), SLOT(showNote()));
         connect(complexNoteButton, SIGNAL(clicked()), SLOT(showComplexNote()));
     }

 public slots:
     void showBanner()
     {
         QMaemo5InformationBox::information(this, "This is a Maemo5 <b>banner</b>",
                                            QMaemo5InformationBox::DefaultTimeout);
     }

     void showNote()
     {
         QMaemo5InformationBox::information(this, "This is a Maemo5 <b>note</b>",
                                            QMaemo5InformationBox::NoTimeout);
     }

     void showComplexNote()
     {
         QMaemo5InformationBox *box = new QMaemo5InformationBox(this);
         QTextBrowser *textBrowser = new QTextBrowser(box);
         textBrowser->setText("This is a Maemo5 <b>note</b> containing custom widget");
         box->setWidget(textBrowser);
         box->setTimeout(QMaemo5InformationBox::NoTimeout);
         box->exec();
     }
 };
#endif // EXAMPLEWIDGET_H
