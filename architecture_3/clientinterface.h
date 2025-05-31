#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include <QObject>
#include <QNetworkAccessManager>


class Nargile
{
public:
    int id;
    QString name;
    QString bowl_type;
    QString bowl_material;
    QString tobacco;
    int years_of_usage;
    int flask_volume;
    Nargile()
    {
        this->id = -1;
    }

    void setID(const int id) {
        this->id = id;
    }

    void Display() const {
        qDebug() << "Nargile: id = " << this->id <<
            "\nNargile: name = " << this->name <<
            "\nNargile: bowl_type = " << this->bowl_type <<
            "\nNargile: bowl_material = " << this->bowl_material <<
            "\nNargile: tobacco = " << this->tobacco <<
            "\nNargile: years_of_usage = " << this->years_of_usage <<
            "\nNargile: flask_volume = " << this->flask_volume << "\n";
    }
};

class ClientInterface : public QObject
{
    Q_OBJECT
public:
    static ClientInterface* getInstance();
    static ClientInterface* instance;
    ~ClientInterface();
    void getNargile(const int id);
    QList<Nargile> getNargile();
    void createNargile(const QString name,
                       const QString bowl_type,
                       const QString bowl_material,
                       const QString tobacco,
                       const int years_of_usage,
                       const int flask_volume);
    void updateNargile(const int id,
                       const QString name,
                       const QString bowl_type,
                       const QString bowl_material,
                       const QString tobacco,
                       const int years_of_usage,
                       const int flask_volume);
    void deleteNargile(const int id);

public slots:
    void responseReceived(QNetworkReply *reply);
private:
    void extracted(QList<Nargile> &list, QJsonArray &jsonArray);
    explicit ClientInterface(QObject *parent = nullptr);
    QNetworkAccessManager *m_client = nullptr;
    void addFormPart(QHttpMultiPart* multiPart, const QString& name, const QString& value);
};

#endif // CLIENTINTERFACE_H
