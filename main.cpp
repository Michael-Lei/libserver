// Qt lib import
#include <QCoreApplication>

#include "utils/dbwrapper/db-wrapper.h"
#include "utils/config.h"
#include "utils/file/logstream.h"
#include "utils/web/webserver.h"
static QTextStream cout(stdout, QIODevice::WriteOnly);
LogStream* lstream;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // load logstream
    lstream = new LogStream();

    // load configuration file
    config conf("./config.conf");
    conf.Load();

    // initiate websocket
    webServer server;
    server.init(8080, 5);
    //server.init(conf.port, conf.ccurrency);
    return a.exec();
}
