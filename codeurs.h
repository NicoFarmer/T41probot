#ifndef CODEURS_H
#define CODEURS_H

#include <QuadEncoder.h>

class CCodeurs
{
public:
    CCodeurs();

    void init();

    long read_CodeurGauche();
    long read_CodeurDroit();

    void read_Codeurs_G_D(long *G, long *D);

private : 
  QuadEncoder m_encoder_G;
  QuadEncoder m_encoder_D;
};

#endif // CODEURS_H
