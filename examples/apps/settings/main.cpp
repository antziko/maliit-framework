/* * This file is part of meego-im-framework *
 *
 * Copyright (C) 2012 Mattia Barbon <mattia@develer.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * and appearing in the file LICENSE.LGPL included in the packaging
 * of this file.
 */

#include "mainwindow.h"

#include <QApplication>
#if (defined(Q_WS_QPA) || defined(Q_WS_QWS)) && (QT_VERSION < 0x050000)
#include <QInputContextFactory>
#endif


int main(int argc, char **argv)
{
    QApplication kit(argc, argv);
#if (defined(Q_WS_QPA) || defined(Q_WS_QWS)) && (QT_VERSION < 0x050000)
    // Workaround for lighthouse Qt
    kit.setInputContext(QInputContextFactory::create("Maliit", &kit));
#endif
    MainWindow settings;

    settings.show();
    kit.exec();
}
