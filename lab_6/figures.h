#ifndef CPP_FIGURES_H
#define CPP_FIGURES_H

using namespace std;

struct Figure {
    string color;
    int type;
    union {
        short int r;
        int s;
        float l;
    } p; // - переменная типа Dimensions, которая может хранить
    //только одно из нескольких значений разных типов в одной
    //и той же области памяти
};

void figures_task();

#endif //CPP_FIGURES_H