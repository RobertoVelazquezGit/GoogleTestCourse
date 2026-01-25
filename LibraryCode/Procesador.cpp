#include "pch.h"
#include "Procesador.h"

bool Procesador::procesar(IPasarelaPago& pasarela) {
    // lógica de negocio
    return pasarela.pagar(100);
}

