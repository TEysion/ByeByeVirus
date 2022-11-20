#ifndef ResourceEngine_H
#define ResourceEngine_H

#include <QString>
#include <QImage>
#include <map>
class ResourceEngine
{
public:
    ResourceEngine();
    static void initRes();
    static const QImage& getRes(QString name);
private:
    static std::map<QString,QImage> imgMap;
};

#endif // ResourceEngine_H
