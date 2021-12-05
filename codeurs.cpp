#include "codeurs.h"


CCodeurs::CCodeurs() :
  m_encoder_G(1, 0, 1, 0),  // Configuration codeur1 : pin0 et 1 / Pas de pull ups
  m_encoder_D(2, 2, 3, 0)   // Configuration codeur2 : pin2 et 3 / Pas de pull ups
{

}

// _________________________________________________
void CCodeurs::init()
{
    m_encoder_G.setInitConfig();
    m_encoder_G.init();

    m_encoder_D.setInitConfig();
    m_encoder_D.init();
}

// _________________________________________________
long CCodeurs::read_CodeurGauche()
{
    return m_encoder_G.read();
}

// _________________________________________________
long CCodeurs::read_CodeurDroit()
{
    return m_encoder_D.read();
}

// _________________________________________________
void CCodeurs::read_Codeurs_G_D(long *G, long *D)
{
    if (G) *G= read_CodeurGauche();
    if (D) *D= read_CodeurDroit();
}
