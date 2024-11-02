#ifndef ENERGIA_POTENCIAL_H
#define ENERGIA_POTENCIAL_H

class EnergiaPotencialGravitatoria {
public:
    EnergiaPotencialGravitatoria(float masa, float altura);

    float calcularPotencialTierra() const;

    void set_masa(float nueva_masa);
    void set_altura(float nueva_altura);

    float get_masa() const;
    float get_altura() const;

private:
    float masa;
    float altura;

    static constexpr float g = 9.81;
};

#endif
