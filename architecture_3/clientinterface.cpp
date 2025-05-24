#include "clientinterface.h"

#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>
#include <QJsonObject>
#include <QHttpMultiPart>
#include <QJsonDocument>
#include <QJsonArray>

ClientInterface* ClientInterface::instance = nullptr;

ClientInterface::ClientInterface(QObject *parent) : QObject{parent}
{
    m_client = new QNetworkAccessManager();
    QObject::connect(
        m_client, &QNetworkAccessManager::finished,
        this, &ClientInterface::responseReceived);
    //m_client->get(QNetworkRequest(QUrl("http://localhost:8000/api/nargile.get/1011")));
}

ClientInterface::~ClientInterface()
{
    m_client->deleteLater();
}

ClientInterface* ClientInterface::getInstance()
{
    // Проверить создан ли хотя бы 1 объект ClientInterface
    // если нет, то создать и вернуть ссылку
    // иначе вернуть ссылку
    if (!instance) {
        instance = new ClientInterface();
    }
    return instance;
}

void ClientInterface::responseReceived(QNetworkReply *reply)
{
    qDebug() << "Server response:\n" << reply->readAll();
}

void ClientInterface::addFormPart(QHttpMultiPart* multiPart, const QString& name, const QString& value)
{
    QHttpPart part;
    part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"" + name + "\""));
    part.setBody(value.toUtf8());
    multiPart->append(part);
}

Nargile* ClientInterface::getNargile(const int id)
{
    QNetworkReply* reply =
        m_client->get(QNetworkRequest(QUrl(QString("http://localhost:8000/api/nargile.get/") + QString::number(id))));

    QJsonParseError jsonErr;
    QJsonDocument QJsonDoc = QJsonDocument::fromJson(reply->readAll(), &jsonErr);
    QJsonObject jsonRootObj = QJsonDoc.object();

    qDebug() << "***reply***" << reply;
    Nargile result;  // Stack-allocated object (not a pointer)
    result.id = jsonRootObj["id"].toInt();
    result.name = jsonRootObj["name"].toString();
    result.bowl_type = jsonRootObj["bowl_type"].toString();
    result.bowl_material = jsonRootObj["bowl_material"].toString();
    result.tobacco = jsonRootObj["tobacco"].toString();
    result.years_of_usage = jsonRootObj["years_of_usage"].toInt();
    result.flask_volume = jsonRootObj["flask_volume"].toInt();

    reply->deleteLater();
    return &result;
}

void ClientInterface::getNargile()
{
    m_client->get(QNetworkRequest(QUrl(QString("http://localhost:8000/api/nargile.get"))));
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

    m_client->post(request, multiPart);
    multiPart->setParent(m_client); // delete the multiPart with the reply
}

void ClientInterface::deleteNargile(const int id)
{
    m_client->get(QNetworkRequest(QUrl(QString("http://localhost:8000/api/nargile.delete/") + QString::number(id))));
}
