#pragma once
#include "IPasarelaPago.h"

class Procesador {
public:
    bool procesar(IPasarelaPago& pasarela);
};

