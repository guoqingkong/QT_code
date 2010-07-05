#include "context.h"



Context* Context::_ctx = 0;

Context::Context():qo1(NULL),
                    qo2(NULL)
{
}

Context* Context::GetContext()
{
    if(Context::_ctx) return Context::_ctx;

    Context::_ctx = new Context();
    return Context::_ctx;
}

Context::~Context()
{
  if (qo1)
      delete qo1;
  if (qo2)
      delete qo2;
  Context::_ctx = 0;
}
