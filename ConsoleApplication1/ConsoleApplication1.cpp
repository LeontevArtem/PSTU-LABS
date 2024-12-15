#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

/// <summary>
/// Исходня функция
/// </summary>
/// <param name="x">Аргумент</param>
/// <returns></returns>
float SrcFunc(float x) {
    return 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
}
/// <summary>
/// Первая производная
/// </summary>
/// <param name="x">Аргумент</param>
/// <returns></returns>
float FirtsDerivativeFunc(float x) {
    return 3 * cos(sqrt(x)) / (2 * sqrt(x)) + 0.35;
}
/// <summary>
/// Вторая производная
/// </summary>
/// <param name="x">Аргумент</param>
/// <returns></returns>
float SecondDerivativeFunc(float x) {
    return (3 * sqrt(x) * sin(x) + 3 * cos(sqrt(x))) / (4 * x * sqrt(x));
}
/// <summary>
/// Итерационная функция
/// </summary>
/// <param name="x"></param>
/// <returns></returns>
float IterativeFunc(float x) {
    return (-3 * sin(sqrt(x)) + 3.8) / 0.35;
}



/// <summary>
/// Нахождение корня через метод касательных (Метод Ньютона)
/// </summary>
/// <param name="ResultAccuracy">Точность, до которой ведутся расчеты</param>
/// <param name="GapStart">Начало промежутка с корнем</param>
/// <param name="GapEnd">Конец промежутка с корнем</param>
/// <returns></returns>
float NewtonSolution(float ResultAccuracy, float GapStart,float GapEnd) {
    cout <<endl<< "Метод Ньютона"<<endl;
    float CurrentAccuracy=1;//текущая точность
    float ResultRoot;//искомый корень - то, что возвращаем - x1
    float Root;//текущий корень (для итераций) - x0
    if (SrcFunc(GapStart)*SecondDerivativeFunc(GapStart)>=0) {
        Root = GapStart;
    }
    else if (SrcFunc(GapEnd) * SecondDerivativeFunc(GapEnd) >= 0) {
        Root = GapEnd;
    }
    //cout << "Подходим к функции со стороны " << Root << endl;
    while (CurrentAccuracy > ResultAccuracy) {
        ResultRoot = Root - SrcFunc(Root) / FirtsDerivativeFunc(Root);
        cout << ResultRoot<<endl;
        CurrentAccuracy = abs(ResultRoot - Root);
        Root = ResultRoot;
    }
    return ResultRoot;
}
/// <summary>
/// Нахождения корня методом простых итераций
/// </summary>
/// <param name="ResultAccuracy"></param>
/// <param name="GapStart"></param>
/// <param name="GapEnd"></param>
/// <returns></returns>
float SimpleIterationsSolution(float ResultAccuracy, float GapStart, float GapEnd) {
    cout <<endl<< "Метод итераций"<<endl;
    float CurrentAccuracy = 1;//текущая точность
    float ResultRoot;//искомый корень - то, что возвращаем - x1
    float Root = GapEnd;//текущий корень (для итераций) - x0
    while (CurrentAccuracy > ResultAccuracy) {
        ResultRoot = IterativeFunc(Root);
        cout << ResultRoot << endl;
        CurrentAccuracy = abs(ResultRoot - Root);
        Root = ResultRoot;
    }
    return ResultRoot;
}
/// <summary>
/// Метод половинного деления
/// </summary>
/// <param name="ResultAccuracy"></param>
/// <param name="GapStart"></param>
/// <param name="GapEnd"></param>
/// <returns></returns>
void DihotomySolution(double ResultAccuracy, double GapStart, double GapEnd) {
    double CurrentGapStart = GapStart;//A
    double CurrentGapEnd = GapEnd;//B
    if (abs(CurrentGapStart - CurrentGapEnd)>ResultAccuracy) {
        cout << CurrentGapStart << endl;
        if (SrcFunc(CurrentGapStart) * SrcFunc(CurrentGapStart + abs(CurrentGapStart - CurrentGapEnd) / 2) < 0) DihotomySolution(ResultAccuracy, CurrentGapStart, CurrentGapStart + abs(CurrentGapStart - CurrentGapEnd) / 2);
        else DihotomySolution(ResultAccuracy, CurrentGapStart + abs(CurrentGapStart - CurrentGapEnd) / 2, CurrentGapEnd);
    }
    
}
int main()
{
    setlocale(LC_ALL,"Russian");
    float ResultAccuracy = 0.00001;
    float GapStart = 2;
    float GapEnd = 3;
    cout<<"Корень, найденный методом Ньютона = " <<NewtonSolution(ResultAccuracy, GapStart, GapEnd);
    cout << "Корень, найденный методом простых итераций = " << SimpleIterationsSolution(ResultAccuracy, GapStart, GapEnd);
    cout <<endl<< "Метод Половинного деления" << endl;
    DihotomySolution(ResultAccuracy, GapStart, GapEnd);
}





