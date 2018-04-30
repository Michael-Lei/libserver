#pragma once

#include "utils/file/logstream.h"
#include <QtCore>
#include <QSettings>

/*
 * Read basic configuration file and parse parameters
 *
 * Usage: config conf(PATH);
 */

struct config
{
    QSettings* settings;

public:
    config(const QString &path);
    ~config();
    QVariant Get(const QString &type);
    void Load();

    //web
    int port;
    int ccurrency;
};
