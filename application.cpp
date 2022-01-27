#include <FlexiTimer2.h>
#include "application.h"

CApplication::CApplication()
{
}

static boolean tick = 0;
void flash()
{
  tick = 1;
}


//___________________________________________________________________________
void CApplication::init(void)
{
  pinMode(LED_BUILTIN, OUTPUT);

  FlexiTimer2::set(PERIODE_TICK, 1.0/1000, flash); // call every 10ms "ticks"
  FlexiTimer2::start();

  m_debug_serial.affiche_menu();
  m_strategie.init();

}


//___________________________________________________________________________
void CApplication::run(void)
{
  if (tick==1)
  {
    tick = 0;
    Sequenceur();
  }

  while(Serial.available() > 0) {
    char incomingByte = Serial.read();
    m_debug_serial.analyze(incomingByte);
  }
}

//___________________________________________________________________________
 /*!
   \brief Sequenceur de taches

   \param --
   \return --
*/
void CApplication::Sequenceur(void)
{
  static unsigned int cpt5msec = 0;
  static unsigned int cpt10msec = 0;
  static unsigned int cpt20msec = 0;
  static unsigned int cpt50msec = 0;
  static unsigned int cpt100msec = 0;
  static unsigned int cpt200msec = 0;
  static unsigned int cpt500msec = 0;
  static unsigned int cpt1sec = 0;
  static bool toggle = false;

  // ______________________________
  cpt5msec++;
  if (cpt5msec >= TEMPO_5msec) {
    cpt5msec = 0;
   m_asservissement.asserv(); 
}
  // ______________________________
  cpt10msec++;
  if (cpt10msec >= TEMPO_10msec) {
    cpt10msec = 0;
}

  // ______________________________
  cpt20msec++;
  if (cpt20msec >= TEMPO_20msec) {
    cpt20msec = 0;

    m_strategie.run();
 
 }


  // ______________________________
  cpt50msec++;
  if (cpt50msec >= TEMPO_50msec) {
    cpt50msec = 0;

    digitalWrite(LED_BUILTIN, toggle);
    toggle = ! toggle;
}

  // ______________________________
  cpt100msec++;
  if (cpt100msec >= TEMPO_100msec) {
    cpt100msec = 0;
    //m_power_switch.configDirections(0xFF,0);
    //m_power_switch.refreshOutputs();
  }

  // ______________________________
  cpt200msec++;
  if (cpt200msec >= TEMPO_200msec) {
    cpt200msec = 0;
 }
  // ______________________________
  cpt500msec++;
  if (cpt500msec >= TEMPO_500msec) {
    cpt500msec = 0;
  }
  // ______________________________
  cpt1sec++;
  if (cpt1sec >= TEMPO_1sec) {
    cpt1sec = 0;
  }

}
