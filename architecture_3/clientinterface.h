#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include <QObject>
#include <QNetworkAccessManager>


class Nargile
{
public:
    int id = -1;
    QString name;
    QString bowl_type;
    QString bowl_material;
    QString tobacco;
    int years_of_usage;
    int flask_volume;

    void Display() const {
        qDebug() << this->name << "\n" <<
            this->bowl_type << "\n" <<
            this->bowl_material << "NetworkReplyHttpImpl(0x1c5946278d0)\n" <<
            this->tobacco << "\n" <<
            this->years_of_usage << "\n" <<
            this->flask_volume << "\n";
    }
};

class ClientInterface : public QObject
{
    Q_OBJECT
public:
    static ClientInterface* getInstance();
    static ClientInterface* instance;
    ~ClientInterface();
    Nargile* getNargile(const int id);
    void getNargile();
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
    explicit ClientInterface(QObject *parent = nullptr);
    QNetworkAccessManager *m_client = nullptr;
    void addFormPart(QHttpMultiPart* multiPart, const QString& name, const QString& value);
};

#endif // CLIENTINTERFACE_H
