#include "clientinterface.h"

#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>
#include <QJsonObject>
#include <QHttpMultiPart>
#include <QJsonDocument>
#include <QJsonArray>
#include <QEventLoop>
#include <QNetworkAccessManager>

ClientInterface * ClientInterface::instance = nullptr;


ClientInterface::ClientInterface(QObject *parent) : QObject{parent}
{
    m_client = new QNetworkAccessManager();
}


ClientInterface *ClientInterface::getInstance()
{
    // проверить создан ли объект да вернуть ссылку, нет создать и вернуть ссылку
    if(!instance){
        instance = new ClientInterface();
    }

    return instance;
}

ClientInterface::~ClientInterface()
{
    m_client->deleteLater();
}

void ClientInterface::responseReceived(QNetworkReply *reply)
{
    qDebug() << "Server response:\n" << reply->readAll() << "\n";
}

void ClientInterface::addFormPart(QHttpMultiPart* multiPart, const QString& name, const QString& value)
{
    QHttpPart part;
    part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"" + name + "\""));
    part.setBody(value.toUtf8());
    multiPart->append(part);
}

void ClientInterface::extracted(QList<Nargile>& list, QJsonArray &jsonArray)
{
    for (const QJsonValue &value : jsonArray) {
        QJsonObject jsonRootObj = value.toObject();
        Nargile nargile;
        nargile.id = jsonRootObj["id"].toInt();
        nargile.name = jsonRootObj["name"].toString();
        nargile.bowl_type = jsonRootObj["bowl_type"].toString();
        nargile.bowl_material = jsonRootObj["bowl_material"].toString();
        nargile.tobacco = jsonRootObj["tobacco"].toString();
        nargile.years_of_usage = jsonRootObj["years_of_usage"].toInt();
        nargile.flask_volume = jsonRootObj["flask_volume"].toInt();
        list.append(nargile);
    }
}

QList<Nargile> ClientInterface::getNargile()
{
    QList<Nargile> list;

    QNetworkReply *reply = m_client->get(
        QNetworkRequest(QUrl(QString("http://localhost:8000/api/nargile.get"))));

    QEventLoop evtLoop;
    QObject::connect(m_client, &QNetworkAccessManager::finished,
                     &evtLoop, &QEventLoop::quit);
    evtLoop.exec();

    QJsonParseError jsonErr;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll(), &jsonErr);
    // QJsonObject jsonRootObj = jsonDoc.object();

    if (jsonDoc.isArray()) {
        QJsonArray jsonArray = jsonDoc.array();
        extracted(list, jsonArray);
    }

    int i = 1;
    for(const Nargile& nargile : list) {
        qDebug() << i << "nargile";
        i++;
        nargile.Display();
    }

    return list;
}

void ClientInterface::getNargile(const int id)
{
    QNetworkReply* reply = m_client->get(QNetworkRequest(QUrl(QString("http://localhost:8000/api/nargile.get/") + QString::number(id))));

    // Wait for the request to finish (if not using signals/slots)
    QEventLoop loop;
    QObject::connect(m_client, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Now try parsing
    QJsonParseError jsonErr;
    QJsonDocument QJsonDoc = QJsonDocument::fromJson(reply->readAll(), &jsonErr);

    if (jsonErr.error != QJsonParseError::NoError) {
        qDebug() << "JSON Parse Error:" << jsonErr.errorString();
        qDebug() << "At offset:" << jsonErr.offset;
        return; // Or handle error
    }

    QJsonObject jsonRootObj = QJsonDoc.object();
    Nargile result;
    result.id = jsonRootObj["id"].toInt();
    result.name = jsonRootObj["name"].toString();
    result.bowl_type = jsonRootObj["bowl_type"].toString();
    result.bowl_material = jsonRootObj["bowl_material"].toString();
    result.tobacco = jsonRootObj["tobacco"].toString();
    result.years_of_usage = jsonRootObj["years_of_usage"].toInt();
    result.flask_volume = jsonRootObj["flask_volume"].toInt();
    result.Display();
    reply->deleteLater();
}

void ClientInterface::createNargile(const QString name,
                                    const QString bowl_type,
                                    const QString bowl_material,
                                    const QString tobacco,
                                    const int years_of_usage,
                                    const int flask_volume) {

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    // Add each field as a separate part
    addFormPart(multiPart, "name", name);
    addFormPart(multiPart, "bowl_type", bowl_type);
    addFormPart(multiPart, "bowl_material", bowl_material);
    addFormPart(multiPart, "tobacco", tobacco);
    addFormPart(multiPart, "years_of_usage", QString::number(years_of_usage));
    addFormPart(multiPart, "flask_volume", QString::number(flask_volume));

    QNetworkRequest request(QUrl("http://localhost:8000/api/nargile.create/"));

    qDebug() << "Create " << name << " request sent\n";
    m_client->post(request, multiPart);
    multiPart->setParent(m_client); // delete the multiPart with the reply
}

void ClientInterface::updateNargile(const int id,
                                    const QString name,
                                    const QString bowl_type,
                                    const QString bowl_material,
                                    const QString tobacco,
                                    const int years_of_usage,
                                    const int flask_volume) {

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    // Add each field as a separate part
    addFormPart(multiPart, "name", name);
    addFormPart(multiPart, "bowl_type", bowl_type);
    addFormPart(multiPart, "bowl_material", bowl_material);
    addFormPart(multiPart, "tobacco", tobacco);
    addFormPart(multiPart, "years_of_usage", QString::number(years_of_usage));
    addFormPart(multiPart, "flask_volume", QString::number(flask_volume));

    QNetworkRequest request((QUrl(QString("http://localhost:8000/api/nargile.update/") + QString::number(id))));

    qDebug() << "Update " << id << " request sent\n";
    m_client->post(request, multiPart);
    multiPart->setParent(m_client); // delete the multiPart with the reply
}

void ClientInterface::deleteNargile(const int id)
{
    QNetworkRequest request(QNetworkRequest(QUrl(QString("http://localhost:8000/api/nargile.delete/") + QString::number(id))));
    qDebug() << "Delete " << id << " request sent\n";
    m_client->get(request);
}
