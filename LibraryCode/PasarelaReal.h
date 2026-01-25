#pragma once
#include "IPasarelaPago.h"
class PasarelaReal :
    public IPasarelaPago
{
public:
    bool pagar(int euros) override;
};

