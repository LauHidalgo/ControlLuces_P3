#include <QCoreApplication>
#include <Qfile>
#include <Qstring>
#include <Qdebug>
#include <QTextStream>
#include <QByteArray>


void Write (QString Filename){

    QFile mFile(Filename);

    if(!mFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug () << "could not open file for written";
        return;
    }

    QTextStream stream (&mFile);
    stream << "Domingo 9 nov 2016\n";
    stream << "Lunes 12 ene 2017\n";
    qDebug () << "File written";
    stream.flush();
    mFile.close();


}

void Read (QString Filename){
    QFile mFile(Filename);

    if(!mFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug () << "could not open file for reading";
        return;
    }
    QTextStream stream (&mFile);
    QString line;

    do {
        line = stream.readLine();
        qDebug () << line;
    } while(!line.isNull());


    //QString mText = in.readAll();
    //qDebug () << mText;
    //mFile.flush();
    mFile.close();
    qDebug () << "File Read";

}

void Write_last_line (QString Filename) {
     QFile Carlos_File(Filename);
     QTextStream in (&Carlos_File);
     QTextStream meter (&Carlos_File);
     QString line;
     if (!Carlos_File.open(QIODevice::WriteOnly | QIODevice::ReadOnly | QIODevice::Text)){
            return;
        }
     do {
         line = in.readLine();
         qDebug () << line;
     } while(!line.isNull());

        in << "Sabado 03 abril 2027\n";


     Carlos_File.close();
}

void test_readfile (QString Filename){
    QFile mFile(Filename);
    QTextStream stream (&mFile);
    QString line;
    QString currentID;
    int x = 1; //this counts how many lines there are inside the text file

    if(!mFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug () << "could not open file for reading";
        return;
    }
    qDebug () << "############################";
    qDebug () << "Dia_semana  Dia_mes Mes Ano ";
    qDebug () << "############################";
    do {
            line = stream.readLine();
            QStringList parts = line.split(" ", QString::KeepEmptyParts);

            if (parts.length() == 4) {
                QString Dia_semana = parts[0];
                QString Dia_mes = parts[1];
                QString Mes  = parts[2];
                QString Ano  = parts[3];

                qDebug () <<x<<" "<<Dia_semana <<" "<<Dia_mes<<" "<<Mes <<" "<<Ano;


                x++; //this counts how many lines there are inside the text file
                currentID = parts[0];//current ID number
            }
        }while (!line.isNull());

        mFile.flush();
        mFile.close();


 }

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString mFilename =  "C:/Users/cmril/Desktop/QT_file/my_file.txt";
   //Write (mFilename);
   //Read(mFilename);
   //Write_last_line (mFilename);
   test_readfile (mFilename);

    return a.exec();
}
