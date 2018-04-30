#include "config.h"
#include <exception>

config::config(const QString &path)
{
    settings = new QSettings(path, QSettings::IniFormat);
}

config::~config()
{
    delete settings;
}

void config::Load()
{
    //web
    port = Get("web/listen_port").toInt();
    ccurrency = Get("web/concurrency").toInt();

    //end
    *lstream << "All settings loaded.";
}

QVariant config::Get(const QString &type)
{
    if(settings->contains(type))
        return settings->value(type);
    else
    {
        *lstream << "Error: CANNOT find settings " + type;
        QVariant null;
        return null;
    }
}
