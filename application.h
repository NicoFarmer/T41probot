#ifndef APPLICATION_H
#define APPLICATION_H

#include "Arduino.h"

#include "codeurs.h"
#include "moteurs.h"
#include "strategie.h"
#include "asservissement.h"
#include "debug_serial.h"

class CApplication
{
public:
    CApplication();

#define PERIODE_TICK    (5)
#define TEMPO_5msec     (5/PERIODE_TICK)
#define TEMPO_10msec    (10/PERIODE_TICK)
#define TEMPO_20msec    (20/PERIODE_TICK)
#define TEMPO_50msec    (50/PERIODE_TICK)
#define TEMPO_100msec   (100/PERIODE_TICK)
#define TEMPO_200msec   (200/PERIODE_TICK)
#define TEMPO_500msec   (500/PERIODE_TICK)
#define TEMPO_1sec      (1000/PERIODE_TICK)
#define TEMPO_2sec      (2000/PERIODE_TICK)
#define TEMPO_5sec      (5000/PERIODE_TICK)
#define TEMPO_10sec     (10000/PERIODE_TICK)
#define TEMPO_15sec     (15000/PERIODE_TICK)

    void init();
    void run();
    void Sequenceur();

    CMoteurs            m_moteurs;
    CCodeurs            m_codeurs;
    CAsservissement     m_asservissement;
    CDebugSerial        m_debug_serial;
};

extern CApplication application;

#endif // APPLICATION_H
