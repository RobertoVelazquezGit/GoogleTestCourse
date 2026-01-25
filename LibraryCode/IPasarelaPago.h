#pragma once

class IPasarelaPago {
public:
    virtual ~IPasarelaPago() = default;
    virtual bool pagar(int euros) = 0;
};

