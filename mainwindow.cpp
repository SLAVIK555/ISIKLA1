#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //int I=20;

        double SP1[5][100];
        //double SP2[5+1][100+1];
        //double SP3[5+1][100+1];

        double A1[5][4];
        double P1[5][4];
        double C1[5][4];

        /*double A2[5+1][4+1];
        double P2[5+1][4+1];
        double C2[5+1][4+1];

        double A3[5+1][4+1];
        double P3[5+1][4+1];
        double C3[5+1][4+1];

        double A4[5+1][4+1];
        double P4[5+1][4+1];
        double C4[5+1][4+1];*/

        double U1[100];
        /*double U2[100+1];
        double U3[100+1];

        double SM=0;
        double SB=0;

        double F[100+1];*/

        for(int j=0; j<5; j++){
            for(int k=0; k<4; k++){
                A1[j][k] = rand() % (90-10+1) + 10;
                P1[j][k] = rand() % (50-5+1) + 5;
                C1[j][k] = rand() % (100-0+1) + 0;
                //cout << A1[j][i] << " " << endl;
            }
        }

        for(int j=0; j<5; j++){
            for(int i=0; i<100; i++){
            SP1[j][i]=0;
            }
        }

        for(int j=0; j<5; j++){
            for(int k=0; k<4; k++){
                for(int i=0; i<100; i++){
                    SP1[j][i] = SP1[j][i] + (A1[j][k])*exp(-pow((i-C1[j][k])/(P1[j][k]),2));
                }
            }
        }

        for(int i=0; i<100; i++){
            U1[i]=0;
        }

        for(int i=0; i<100; i++){
            for(int j=0; j<5; j++){
                U1[i]=U1[i]+SP1[j][i];
            }
        }




/*
        float R[5]={1, 1, 0.5, 1, 1.5};

        for(int j=1; j<=5; j++){
            for(int k=1; k<=4; k++){
                A2[j][k] = A1[j][k]*R[j];
                P2[j][k] = P1[j][k];
                C2[j][k] = C1[j][k];
            }
        }

        for(int j=1; j<=5; j++){
            for(int i=0; i<=100; i++){
            SP2[j][i]=0;
            }
        }

        for(int j=1; j<=5; j++){
            for(int k=1; k<=4; k++){
                for(int i=0; i<=100; i++){
                    SP2[j][i] = SP2[j][i]+A2[j][k]*exp(-pow((i-C2[j][k])/(P2[j][k]),2));
                }
            }
        }

        for(int i=0; i<=100; i++){
            U2[i]=0;
        }

        for(int i=0; i<=100; i++){
            for(int j=0; j<=5; j++){
                U2[i]=U2[i]+SP2[j][i];
            }
        }





        for(int y=0; y<=I; y++){

        for(int j=1; j<=5; j++){
            for(int k=1; k<=4; k++){
                P3[j][k] = P1[j][k];
                C3[j][k] = C1[j][k];
            }
        }

        for(int j=1; j<=5; j++){
            for(int k=1; k<=4; k++){
            A3[j][k] = U2[(int)C2[j][k]];//////////////////////////////?
            }
        }

        for(int j=1; j<=5; j++){
            for(int i=0; i<=100; i++){
            SP3[j][i]=0;
            }
        }

        for(int j=1; j<=5; j++){
            for(int k=1; k<=4; k++){
                for(int i=0; i<=100; i++){
                    SP3[j][i] = SP3[j][i]+A3[j][k]*exp(-pow((i-C3[j][k])/(P3[j][k]),2));
                }
            }
        }

        for(int i=0; i<=100; i++){
            U3[i]=0;
        }

        for(int i=0; i<=100; i++){
            for(int j=0; j<=5; j++){
                U3[i]=U3[i]+SP3[j][i];
            }
        }





        for(int i=0; i<=100; i++){
            F[i]=0;
        }

        for(int i=0; i<=100; i++){
            for(int j=0; j<5; j++){
                for(int k=0; k<4; k++){
                    F[i]=A3[j][k]*exp(-pow((i-C3[j][k])/(P3[j][k]),2))*(U2[i]/U3[i]);
                    SM=SM+F[i];
                    SB=SB+F[i]*F[i];
                    A4[j][k]=(SB/SM)*pow(2, 0.5);
                    P4[j][k] = P1[j][k];
                    C4[j][k] = C1[j][k];
                }
            }
        }

        for(int j=1; j<=5; j++){
            for(int k=1; k<=4; k++){
                A3[j][k] = A4[j][k];
                P3[j][k] = P4[j][k];
                C3[j][k] = C4[j][k];
            }
        }


    }*/


//-------------------------------------------------------------------------------------------------------------------------------------------------
        double a = 0; //Начало интервала, где рисуем график по оси Ox
        double b = 100; //Конец интервала, где рисуем график по оси Ox

        int N= b-a; //Вычисляем количество точек, которые будем отрисовывать
        QVector<double> x(N);
        QVector<double> y1(N);

        //Вычисляем наши данные
        for (int i=0; i<100; i++)//Пробегаем по всем точкам
        {
            x[i] = i;
            y1[i] = U1[i];//Формула нашей функции
        }

        //ui->widget->clearGraphs();//Если нужно, но очищаем все графики
        //Добавляем один график в widget
        ui->widget->addGraph();
        //Говорим, что отрисовать нужно график по нашим двум массивам x и y
        ui->widget->graph(0)->setData(x, y1);

        //Подписываем оси Ox и Oy
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");

        //Установим область, которая будет показываться на графике
        ui->widget->xAxis->setRange(a, b);//Для оси Ox

        //Для показа границ по оси Oy сложнее, так как надо по правильному
        //вычислить минимальное и максимальное значение в векторах
        double minY1 = y1[0], maxY1 = y1[0];
        for (int i=1; i<N; i++)
        {
            if (y1[i]<minY1) {
                minY1 = y1[i];
            }
            if (y1[i]>maxY1) {
                maxY1 = y1[i];
            }
        }
        ui->widget->yAxis->setRange(minY1, maxY1);//Для оси Oy

        //И перерисуем график на нашем widget
        ui->widget->replot();
}

void MainWindow::on_pushButton_2_clicked()
{
    double SP1[5][100];
    double SP2[5][100];
    //double SP3[5+1][100+1];

    double A1[5][4];
    double P1[5][4];
    double C1[5][4];

    double A2[5][4];
    double P2[5][4];
    double C2[5][4];

    /*double A3[5+1][4+1];
    double P3[5+1][4+1];
    double C3[5+1][4+1];

    double A4[5+1][4+1];
    double P4[5+1][4+1];
    double C4[5+1][4+1];*/

    double U1[100];
    double U2[100];
    /*double U3[100+1];

    double SM=0;
    double SB=0;

    double F[100+1];*/

    for(int j=0; j<5; j++){
        for(int k=0; k<4; k++){
            A1[j][k] = rand() % (90-10+1) + 10;
            P1[j][k] = rand() % (50-5+1) + 5;
            C1[j][k] = rand() % (100-0+1) + 0;
            //cout << A1[j][i] << " " << endl;
        }
    }

    for(int j=0; j<5; j++){
        for(int i=0; i<100; i++){
        SP1[j][i]=0;
        }
    }

    for(int j=0; j<5; j++){
        for(int k=0; k<4; k++){
            for(int i=0; i<100; i++){
                SP1[j][i] = SP1[j][i] + (A1[j][k])*exp(-pow((i-C1[j][k])/(P1[j][k]),2));
            }
        }
    }

    for(int i=0; i<100; i++){
        U1[i]=0;
    }

    for(int i=0; i<100; i++){
        for(int j=0; j<5; j++){
            U1[i]=U1[i]+SP1[j][i];
        }
    }





    double R[5]={1, 1, 0.5, 1, 1.5};

    for(int j=1; j<5; j++){
        for(int k=1; k<4; k++){
            A2[j][k] = A1[j][k]*R[j];
            P2[j][k] = P1[j][k];
            C2[j][k] = C1[j][k];
        }
    }

    for(int j=1; j<5; j++){
        for(int i=0; i<100; i++){
        SP2[j][i]=0;
        }
    }

    for(int j=1; j<5; j++){
        for(int k=1; k<4; k++){
            for(int i=0; i<100; i++){
                SP2[j][i] = SP2[j][i]+A2[j][k]*exp(-pow((i-C2[j][k])/(P2[j][k]),2));
            }
        }
    }

    for(int i=0; i<100; i++){
        U2[i]=0;
    }

    for(int i=0; i<100; i++){
        for(int j=0; j<5; j++){
            U2[i]=U2[i]+SP2[j][i];
        }
    }




/*
    for(int y=0; y<=I; y++){

    for(int j=1; j<=5; j++){
        for(int k=1; k<=4; k++){
            P3[j][k] = P1[j][k];
            C3[j][k] = C1[j][k];
        }
    }

    for(int j=1; j<=5; j++){
        for(int k=1; k<=4; k++){
        A3[j][k] = U2[(int)C2[j][k]];//////////////////////////////?
        }
    }

    for(int j=1; j<=5; j++){
        for(int i=0; i<=100; i++){
        SP3[j][i]=0;
        }
    }

    for(int j=1; j<=5; j++){
        for(int k=1; k<=4; k++){
            for(int i=0; i<=100; i++){
                SP3[j][i] = SP3[j][i]+A3[j][k]*exp(-pow((i-C3[j][k])/(P3[j][k]),2));
            }
        }
    }

    for(int i=0; i<=100; i++){
        U3[i]=0;
    }

    for(int i=0; i<=100; i++){
        for(int j=0; j<=5; j++){
            U3[i]=U3[i]+SP3[j][i];
        }
    }





    for(int i=0; i<=100; i++){
        F[i]=0;
    }

    for(int i=0; i<=100; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<4; k++){
                F[i]=A3[j][k]*exp(-pow((i-C3[j][k])/(P3[j][k]),2))*(U2[i]/U3[i]);
                SM=SM+F[i];
                SB=SB+F[i]*F[i];
                A4[j][k]=(SB/SM)*pow(2, 0.5);
                P4[j][k] = P1[j][k];
                C4[j][k] = C1[j][k];
            }
        }
    }

    for(int j=1; j<=5; j++){
        for(int k=1; k<=4; k++){
            A3[j][k] = A4[j][k];
            P3[j][k] = P4[j][k];
            C3[j][k] = C4[j][k];
        }
    }


}*/


//-------------------------------------------------------------------------------------------------------------------------------------------------
    double a = 0; //Начало интервала, где рисуем график по оси Ox
    double b = 100; //Конец интервала, где рисуем график по оси Ox

    int N= b-a; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x2(N);
    QVector<double> y2(N);

    //Вычисляем наши данные
    for (int i=0; i<100; i++)//Пробегаем по всем точкам
    {
        x2[i] = i;
        y2[i] = U2[i];//Формула нашей функции
    }

    ui->widget->clearGraphs();//Если нужно, но очищаем все графики
    //Добавляем один график в widget
    ui->widget->addGraph();
    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    ui->widget->graph()->setData(x2, y2);

    //Подписываем оси Ox и Oy
    //ui->widget->xAxis->setLabel("x");
   //ui->widget->yAxis->setLabel("y");

    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(a, b);//Для оси Ox

    //Для показа границ по оси Oy сложнее, так как надо по правильному
    //вычислить минимальное и максимальное значение в векторах
    double minY2 = y2[0], maxY2 = y2[0];
    for (int i=1; i<N; i++)
    {
        if (y2[i]<minY2) {
            minY2 = y2[i];
        }
        if (y2[i]>maxY2) {
            maxY2 = y2[i];
        }
    }
    ui->widget->yAxis->setRange(minY2, maxY2);//Для оси Oy

    //И перерисуем график на нашем widget
    ui->widget->replot();
}

void MainWindow::on_pushButton_3_clicked()
{
    int I=20;

    double SP1[5][100];
    double SP2[5][100];
    double SP3[5][100];

    double A1[5][4];
    double P1[5][4];
    double C1[5][4];

    double A2[5][4];
    double P2[5][4];
    double C2[5][4];

    double A3[5][4+1];
    double P3[5][4+1];
    double C3[5][4+1];

    double A4[5][4];
    double P4[5][4];
    double C4[5][4];

    double U1[100];
    double U2[100];
    double U3[100+1];

    double SM=0;
    double SB=0;

    double F[100];

    for(int j=0; j<5; j++){
        for(int k=0; k<4; k++){
            A1[j][k] = rand() % (90-10+1) + 10;
            P1[j][k] = rand() % (50-5+1) + 5;
            C1[j][k] = rand() % (100-0+1) + 0;
            //cout << A1[j][i] << " " << endl;
        }
    }

    for(int j=0; j<5; j++){
        for(int i=0; i<100; i++){
        SP1[j][i]=0;
        }
    }

    for(int j=0; j<5; j++){
        for(int k=0; k<4; k++){
            for(int i=0; i<100; i++){
                SP1[j][i] = SP1[j][i] + (A1[j][k])*exp(-pow((i-C1[j][k])/(P1[j][k]),2));
            }
        }
    }

    for(int i=0; i<100; i++){
        U1[i]=0;
    }

    for(int i=0; i<100; i++){
        for(int j=0; j<5; j++){
            U1[i]=U1[i]+SP1[j][i];
        }
    }





    double R[5]={1, 1, 0.5, 1, 1.5};

    for(int j=1; j<5; j++){
        for(int k=1; k<4; k++){
            A2[j][k] = A1[j][k]*R[j];
            P2[j][k] = P1[j][k];
            C2[j][k] = C1[j][k];
        }
    }

    for(int j=1; j<5; j++){
        for(int i=0; i<100; i++){
        SP2[j][i]=0;
        }
    }

    for(int j=1; j<5; j++){
        for(int k=1; k<4; k++){
            for(int i=0; i<100; i++){
                SP2[j][i] = SP2[j][i]+A2[j][k]*exp(-pow((i-C2[j][k])/(P2[j][k]),2));
            }
        }
    }

    for(int i=0; i<100; i++){
        U2[i]=0;
    }

    for(int i=0; i<100; i++){
        for(int j=0; j<5; j++){
            U2[i]=U2[i]+SP2[j][i];
        }
    }





    for(int y=0; y<I; y++){

    for(int j=1; j<5; j++){
        for(int k=1; k<4; k++){
            P3[j][k] = P1[j][k];
            C3[j][k] = C1[j][k];
        }
    }

    for(int j=1; j<5; j++){
        for(int k=1; k<4; k++){
        A3[j][k] = U2[(int)C2[j][k]];//////////////////////////////?
        }
    }

    for(int j=1; j<5; j++){
        for(int i=0; i<100; i++){
        SP3[j][i]=0;
        }
    }

    for(int j=1; j<5; j++){
        for(int k=1; k<4; k++){
            for(int i=0; i<100; i++){
                SP3[j][i] = SP3[j][i]+A3[j][k]*exp(-pow((i-C3[j][k])/(P3[j][k]),2));
            }
        }
    }

    for(int i=0; i<100; i++){
        U3[i]=0;
    }

    for(int i=0; i<100; i++){
        for(int j=0; j<5; j++){
            U3[i]=U3[i]+SP3[j][i];
        }
    }





    for(int i=0; i<100; i++){
        F[i]=0;
    }

    for(int i=0; i<100; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<4; k++){
                F[i]=A3[j][k]*exp(-pow((i-C3[j][k])/(P3[j][k]),2))*(U2[i]/U3[i]);
                SM=SM+F[i];
                SB=SB+F[i]*F[i];
                A4[j][k]=(SB/SM)*pow(2, 0.5);
                P4[j][k] = P1[j][k];
                C4[j][k] = C1[j][k];
            }
        }
    }

    for(int j=1; j<5; j++){
        for(int k=1; k<4; k++){
            A3[j][k] = A4[j][k];
            P3[j][k] = P4[j][k];
            C3[j][k] = C4[j][k];
        }
    }


}


//-------------------------------------------------------------------------------------------------------------------------------------------------
    double a = 0; //Начало интервала, где рисуем график по оси Ox
    double b = 100; //Конец интервала, где рисуем график по оси Ox

    int N= b-a; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x(N);
    QVector<double> y3(N);

    //Вычисляем наши данные
    for (int i=0; i<100; i++)//Пробегаем по всем точкам
    {
        x[i] = i;
        y3[i] = U3[i];//Формула нашей функции
    }

    ui->widget->clearGraphs();//Если нужно, но очищаем все графики
    //Добавляем один график в widget
    ui->widget->addGraph();
    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    ui->widget->graph()->setData(x, y3);

    //Подписываем оси Ox и Oy
    //ui->widget->xAxis->setLabel("x");
   //ui->widget->yAxis->setLabel("y");

    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(a, b);//Для оси Ox

    //Для показа границ по оси Oy сложнее, так как надо по правильному
    //вычислить минимальное и максимальное значение в векторах
    double minY3 = y3[0], maxY3 = y3[0];
    for (int i=1; i<N; i++)
    {
        if (y3[i]<minY3) {
            minY3 = y3[i];
        }
        if (y3[i]>maxY3) {
            maxY3 = y3[i];
        }
    }
    ui->widget->yAxis->setRange(minY3, maxY3);//Для оси Oy

    //И перерисуем график на нашем widget
    ui->widget->replot();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->widget->clearGraphs();

    ui->widget->replot();
}





