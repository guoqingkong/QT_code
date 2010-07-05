#ifndef CONTEXT_H
#define CONTEXT_H

#include<QObject>

class Context
{
public:
    Context();
    virtual ~Context();
    static Context* GetContext();

public:
    QWidget* qo1;
    QWidget* qo2;

    static Context* _ctx;
};

#endif // CONTEXT_H
