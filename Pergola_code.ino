
/*


Auteur: cbaie tresneuf

Interface: arduino

Nom du projet: Pergola v1

Description: 

Toolbox: vittascience

Mode: mixed

Blocks: <xml xmlns="https://developers.google.com/blockly/xml"><variables><variable id=":6vcnacR.4KR}RvI4_+X">interrupteur_gen</variable><variable id="NFLG~[8xkK?!jHk`kthK">interrupteur_lames</variable><variable id="O3nmZN;w024!B_Z!x]Z=">interrupteur_lum</variable><variable id="M}aOg6Y;QUrq+aF/+%G(">interrupteur lum2</variable><variable id="|22F`%Ah++3Q[IDZWZ(d">lum_exterieur</variable><variable id="BDVBy;8KTfz}1mf+75F^">pluie</variable><variable id="hi39;cKDXxzgi|Mb9os,">potentiometre</variable><variable id="|5@?k%!C*;qyLvvxkf(+">vitesse_vent</variable><variable id="X#Z!6yJ0vE!~tQUZf5cx">limite_vent</variable><variable id="hSBRw%[Pdf*|xh[q)R*7">temp</variable></variables><block type="on_start" id="G[=T#8yqB70`NFgYq}GP" deletable="false" x="13" y="13"><statement name="DO"><block type="procedures_callnoreturn" id="a~OQnw=+(Op5Z}Z6-+Tq"><mutation name="recup_var"></mutation></block></statement></block><block type="forever" id="o[WN]+eeF.OUxGch67@8" deletable="false" x="13" y="213"><statement name="DO"><block type="procedures_callnoreturn" id="g)%K=Tc8n]KVGxm7x`(e"><mutation name="recup_var"></mutation><next><block type="controls_if" id="6`?Hk_[f;nKI800LUNq$"><mutation elseif="1" else="1"></mutation><value name="IF0"><block type="variables_get" id="Gz|CgG[5~mF;:Sm._iGV"><field name="VAR" id="O3nmZN;w024!B_Z!x]Z=">interrupteur_lum</field></block></value><statement name="DO0"><block type="text_comment" id="j|5@B9CSyo9PG0Ya_ApR"><field name="TEXT">Mode lumière auto</field><next><block type="controls_if" id="Q(.!JgKk4cUTa~;M#SBz"><mutation else="1"></mutation><comment pinned="false" h="80" w="160">Si la lumière est en dessous de 20% de la capacité du capteur ( 1023 ) alors la lumière s'allume </comment><value name="IF0"><block type="logic_compare" id="^+X*:3|.w2i8zK%`[.8D"><field name="OP">LTE</field><value name="A"><block type="variables_get" id="{i6vP=P3qSWT_4m;nk:m"><field name="VAR" id="|22F`%Ah++3Q[IDZWZ(d">lum_exterieur</field></block></value><value name="B"><shadow type="math_number" id="dhjN6tyISWAAO*xaiz+S"><field name="NUM">1</field></shadow><block type="math_arithmetic" id="zuF|(^fX08oEzjqt6*h|"><field name="OP">MULTIPLY</field><value name="A"><block type="math_number" id="DOV9O~Z$_G^%:hQ#_:5-"><field name="NUM">1023</field></block></value><value name="B"><shadow type="math_number" id="enC?o:sHiU.q~UbFc4{U"><field name="NUM">0.2</field></shadow></value></block></value></block></value><statement name="DO0"><block type="io_writeDigitalPin" id="gGq2}^Wo__b2gm__Q_[Q"><field name="PIN">0</field><value name="STATE"><shadow type="io_digital_signal" id="r2%CX-S[UacP_iuqz7bk"><field name="STATE">HIGH</field></shadow></value></block></statement><statement name="ELSE"><block type="io_writeDigitalPin" id="JOyk7}(D65T~^;Jf*k-R"><field name="PIN">0</field><value name="STATE"><shadow type="io_digital_signal" id="PJ#/.|O`P9,v9=wL@.v1"><field name="STATE">LOW</field></shadow></value></block></statement></block></next></block></statement><value name="IF1"><block type="variables_get" id="T{xvtllA}y6MWK8Y8}!c"><field name="VAR" id="M}aOg6Y;QUrq+aF/+%G(">interrupteur lum2</field></block></value><statement name="DO1"><block type="text_comment" id="OqV]B#/TpF#kCkY%[vSf"><field name="TEXT">Mode lumière standard</field><next><block type="io_writeDigitalPin" id="T8l8b3jec=Q3X6|#ggk7"><field name="PIN">0</field><value name="STATE"><shadow type="io_digital_signal" id="^k}M?G8ja]([Ej8(sPCI"><field name="STATE">HIGH</field></shadow></value></block></next></block></statement><statement name="ELSE"><block type="text_comment" id="z0[1W#Wim]Exi!4E$D-$"><field name="TEXT">Mode lumière éteinte</field><next><block type="io_writeDigitalPin" id="{VA~kvHNlmgP~@lEa$8f"><field name="PIN">0</field><value name="STATE"><shadow type="io_digital_signal" id="`@^*~Rtv5IMH~K,-cvJ)"><field name="STATE">LOW</field></shadow></value></block></next></block></statement><next><block type="controls_if" id="8ceagHsL)611om]y=`U7"><value name="IF0"><block type="variables_get" id="NeWCv1rI$]GaP.a$7H{N"><field name="VAR" id=":6vcnacR.4KR}RvI4_+X">interrupteur_gen</field></block></value><statement name="DO0"><block type="controls_if" id="Dmve[(BNL%W{F^Jgb3cA"><mutation else="1"></mutation><value name="IF0"><block type="variables_get" id="[:x]YZO#6:oyXTE2is:-"><field name="VAR" id="NFLG~[8xkK?!jHk`kthK">interrupteur_lames</field></block></value><statement name="DO0"><block type="text_comment" id=".*6yN?#wHb5-}ojUd1hn"><field name="TEXT">interrupteur lames = 1 -&gt; auto sinon manuel</field><next><block type="controls_if" id="H(A[~**;er-,#xg/kTQ}"><mutation elseif="3"></mutation><value name="IF0"><block type="logic_compare" id="vy[`9YEv4AP*rI6v$FKi"><field name="OP">LT</field><value name="A"><block type="variables_get" id="L9[pMOk,;bVB6-Y;~pL`"><field name="VAR" id="X#Z!6yJ0vE!~tQUZf5cx">limite_vent</field></block></value><value name="B"><shadow type="math_number" id="DvH*kh9r6xc-%*q*(aIe"><field name="NUM">1</field></shadow><block type="variables_get" id="Z1E=Gdta[~ga4sr`P@V0"><field name="VAR" id="|5@?k%!C*;qyLvvxkf(+">vitesse_vent</field></block></value></block></value><statement name="DO0"><block type="text_comment" id="Jz,nu.x]liTV]ITOr=G$"><field name="TEXT">Mode vent extreme</field><next><block type="actuators_setServoAngle" id=")-[h0SUH776T]=#,O(*d"><field name="PIN">7</field><value name="ANGLE"><shadow type="math_number" id="EvRxm#S`0m1C7juD6z%h"><field name="NUM">45</field></shadow></value></block></next></block></statement><value name="IF1"><block type="logic_operation" id="=)x-NZ#rxW9IRZ`887}K"><field name="OP">AND</field><value name="A"><block type="logic_compare" id="!A39{p3i3^y%A`oycUv;"><field name="OP">LT</field><value name="A"><block type="variables_get" id="UGB!=uk(/|8CC)0pzhtf"><field name="VAR" id="hSBRw%[Pdf*|xh[q)R*7">temp</field></block></value><value name="B"><shadow type="math_number" id="2?j_]C$`AQ`G4/7V%Ab4"><field name="NUM">2</field></shadow></value></block></value><value name="B"><block type="variables_get" id="`Xlgyih.P=bq=f7o%0jE"><field name="VAR" id="BDVBy;8KTfz}1mf+75F^">pluie</field></block></value></block></value><statement name="DO1"><block type="text_comment" id="UTAY;hJBTxjPtc63o2kq"><field name="TEXT">Mode neige</field><next><block type="actuators_setServoAngle" id="73guI.0A:E9HH$xK`/n{"><field name="PIN">7</field><value name="ANGLE"><shadow type="math_number" id=")tklwoZlb!H%UjVd(WCo"><field name="NUM">90</field></shadow></value></block></next></block></statement><value name="IF2"><block type="logic_compare" id="j9r_..ed~B={yK{!xg!Q"><field name="OP">LT</field><value name="A"><block type="variables_get" id="_q`2L-cairgg%t-r4I])"><field name="VAR" id="hSBRw%[Pdf*|xh[q)R*7">temp</field></block></value><value name="B"><shadow type="math_number" id="tKdkiPAj-HoL]vCSfuoR"><field name="NUM">2</field></shadow></value></block></value><statement name="DO2"><block type="text_comment" id="9N22$B[Hjb7jBPnK,UKQ"><field name="TEXT">Mode Gel</field><next><block type="actuators_setServoAngle" id="sy#S8[Wx:eZxOVK/#hww"><field name="PIN">7</field><value name="ANGLE"><shadow type="math_number" id="H}|0`4yR,Yj0s`5]uuB5"><field name="NUM">90</field></shadow></value></block></next></block></statement><value name="IF3"><block type="variables_get" id="HhHLyl.ME{e*h#/?*f|%"><field name="VAR" id="BDVBy;8KTfz}1mf+75F^">pluie</field></block></value><statement name="DO3"><block type="text_comment" id="J,nopbbl=C2%vH=/k#9D"><field name="TEXT">Mode pluie</field><next><block type="actuators_setServoAngle" id="b4bIAL6gCIcRIY}J7V;@"><field name="PIN">7</field><value name="ANGLE"><shadow type="math_number" id="fJHh}.@OjbcJ]n]NtD~-"><field name="NUM">25</field></shadow></value></block></next></block></statement></block></next></block></statement><statement name="ELSE"><block type="text_comment" id="mezfOpCpM0)3Ea{Sdnz."><field name="TEXT">Mode Manuel</field><next><block type="actuators_setServoAngle" id="loqJ1.r4U}g{~_UH.-c{"><field name="PIN">7</field><value name="ANGLE"><shadow type="math_number" id="e[Sd3ZGK^12s-t_pu_5F"><field name="NUM">90</field></shadow><block type="variables_get" id="P^~icBA|M_0O(g-~1+Hr"><field name="VAR" id="hi39;cKDXxzgi|Mb9os,">potentiometre</field></block></value></block></next></block></statement></block></statement></block></next></block></next></block></statement></block><block type="procedures_defnoreturn" id="+]bc+(6J=BpQPD}BH-tS" x="13" y="1938"><mutation name="recup_var"></mutation><field name="NAME">recup_var</field><statement name="STACK"><block type="variables_set" id="akBN6-o(wA24MweHS_^L"><field name="VAR" id=":6vcnacR.4KR}RvI4_+X">interrupteur_gen</field><value name="VALUE"><shadow type="math_number" id="apS|I74O(cclhicfAZ+Y"><field name="NUM">0</field></shadow><block type="io_getGroveSwitch" id="]?__dk43Rsk0ZwlAGT.q"><field name="PIN">5</field></block></value><next><block type="variables_set" id="BW//|gQA+b5xh`_z+PeV"><field name="VAR" id="NFLG~[8xkK?!jHk`kthK">interrupteur_lames</field><value name="VALUE"><shadow type="math_number" id="B?eOoOk^=opM3IX/wZAX"><field name="NUM">0</field></shadow><block type="io_getGroveSwitch" id="*)mJBR8de~ahLfUnLYx%"><field name="PIN">4</field></block></value><next><block type="text_comment" id="ciN(^VYBRCa.IeS[OZSi"><field name="TEXT">interrupteur_lum | on = auto ; off = interrupteu_lum2</field><next><block type="variables_set" id=")r4aj!1)vUzmdkcWwYDq"><field name="VAR" id="O3nmZN;w024!B_Z!x]Z=">interrupteur_lum</field><value name="VALUE"><shadow type="math_number" id="fFJ4Sudv[-Ph%{u1urUo"><field name="NUM">0</field></shadow><block type="io_getGroveSwitch" id="6{TPaDTFe:^pP:@z0PJr"><field name="PIN">10</field></block></value><next><block type="text_comment" id="kl7QVys_3wK(f#Vj5_Be"><field name="TEXT">interrupteur_lum2 | off = éteindre , on = éclairage standard  </field><next><block type="variables_set" id="X~#s8`zaP3J8swV9o(V^"><field name="VAR" id="M}aOg6Y;QUrq+aF/+%G(">interrupteur lum2</field><value name="VALUE"><shadow type="math_number"><field name="NUM">0</field></shadow><block type="io_getGroveSwitch" id="3~e?nDPtscfu7J$k`HSK"><field name="PIN">12</field></block></value><next><block type="variables_set" id=")saHyG#xBW#Kg^4WVJFM"><field name="VAR" id="|5@?k%!C*;qyLvvxkf(+">vitesse_vent</field><value name="VALUE"><shadow type="math_number" id="h]{/7lCJA`LDo$8!Nk#5"><field name="NUM">0</field></shadow><block type="io_getGroveRotaryAngle" id="]X]?/8-4NVges-.Eix(e"><field name="PIN">A0</field><comment pinned="false" h="80" w="160">Temporaire</comment></block></value><next><block type="variables_set" id="f$_PgU$ylk2%jDT7q^9d"><field name="VAR" id="hSBRw%[Pdf*|xh[q)R*7">temp</field><value name="VALUE"><shadow type="math_number" id="tX-]OQM-!t.%=J(*(S*b"><field name="NUM">0</field></shadow><block type="sensors_getGroveTemperature" id="[-t.-S={HHJ@v|x;H5NM"><field name="UNIT">CELSIUS</field><field name="PIN">A1</field></block></value><next><block type="variables_set" id="ZcTax4^P]D_tl+1nUU?S"><field name="VAR" id="hi39;cKDXxzgi|Mb9os,">potentiometre</field><value name="VALUE"><shadow type="math_number" id="v!.mtk,Pk6FE[feI`7/;"><field name="NUM">0</field></shadow><block type="io_getGroveRotaryAngle" id="AazM:TyXhaT1AULFFk/["><field name="PIN">A0</field></block></value><next><block type="variables_set" id="8v4Za/|^7)MBW|WF1S}P"><field name="VAR" id="BDVBy;8KTfz}1mf+75F^">pluie</field><value name="VALUE"><shadow type="math_number" id="a^[ta*^{eDdV7F$H|k0f"><field name="NUM">0</field></shadow><block type="sensors_getRainGauge" id="[ki(/wgA{j@HBl7)]_W}"><field name="PIN">8</field></block></value><next><block type="variables_set" id="RTt^x9jV9IRkW4d:b`Nn"><field name="VAR" id="X#Z!6yJ0vE!~tQUZf5cx">limite_vent</field><value name="VALUE"><shadow type="math_number" id="$cW`RrVZqSd+1P:WhMHx"><field name="NUM">90</field></shadow></value><next><block type="variables_set" id="``toKmf*RVD::nYg~GUs"><field name="VAR" id="|22F`%Ah++3Q[IDZWZ(d">lum_exterieur</field><value name="VALUE"><shadow type="math_number" id="E{b}IxE3.(]9D5PF/+Dc"><field name="NUM">90</field></shadow><block type="sensors_getGroveLight" id="~GggkZhz`wpP9c94yenR"><field name="PIN">A5</field></block></value></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></statement></block></xml>

Projet généré par Vittascience.

Ce fichier contient le code textuel ainsi que le code blocs. Il peut être importé de nouveau

sur l'interface http://vittascience.com/arduino


*/

#include <Servo.h>

#define PIN_SERVO_7  7
#define PIN_SWITCH_BUTTON_5  5
#define PIN_SWITCH_BUTTON_4  4
#define PIN_SWITCH_BUTTON_10  10
#define PIN_SWITCH_BUTTON_12  12
#define PIN_POTENTIOMETER_A0  A0
#define PIN_TEMPERATURE_SENSOR_A1  A1
#define PIN_RAIN_GAUGE_8  8
#define PIN_LIGHT_SENSOR_A5  A5

Servo servomotor_7;

boolean interrupteur_gen;
boolean interrupteur_lames;
boolean interrupteur_lum;
boolean interrupteur_lum2;
int vitesse_vent;
float temp;
int potentiometre;
boolean pluie;
int limite_vent;
int lum_exterieur;

uint16_t getAnalogMean(uint8_t pin, uint8_t n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += analogRead(pin);
    delay(1);
  }
  return sum / n;
}

float getGroveTemperature(uint8_t pin, uint8_t unit) {
  float R = 1023.0/getAnalogMean(pin, 5) - 1;
  float t = 1/(log(R)/4275+1/298.15) - 273.15; // celsius
  switch (unit) {
    case 1: // fahrenheit
      t = t * 9/5 + 32;
      break;
    case 2: // kelvin
      t += 273.15;
      break;
  }
  return t;
}

void recup_var() {
  interrupteur_gen = digitalRead(PIN_SWITCH_BUTTON_5);
  interrupteur_lames = digitalRead(PIN_SWITCH_BUTTON_4);
  //interrupteur_lum | on = auto ; off = interrupteu_lum2
  interrupteur_lum = digitalRead(PIN_SWITCH_BUTTON_10);
  //interrupteur_lum2 | off = éteindre , on = éclairage standard
  interrupteur_lum2 = digitalRead(PIN_SWITCH_BUTTON_12);
  // Temporaire
  vitesse_vent = analogRead(PIN_POTENTIOMETER_A0);
  temp = getGroveTemperature(PIN_TEMPERATURE_SENSOR_A1, 0);
  potentiometre = analogRead(PIN_POTENTIOMETER_A0);
  pluie = digitalRead(PIN_RAIN_GAUGE_8);
  limite_vent = 90;
  lum_exterieur = getAnalogMean(PIN_LIGHT_SENSOR_A5, 5);
}


void setup() {
  pinMode(0, OUTPUT);
  servomotor_7.attach(PIN_SERVO_7);
  pinMode(PIN_SWITCH_BUTTON_5, INPUT);
  pinMode(PIN_SWITCH_BUTTON_4, INPUT);
  pinMode(PIN_SWITCH_BUTTON_10, INPUT);
  pinMode(PIN_SWITCH_BUTTON_12, INPUT);
  pinMode(PIN_POTENTIOMETER_A0, INPUT);
  pinMode(PIN_TEMPERATURE_SENSOR_A1, INPUT);
  pinMode(PIN_RAIN_GAUGE_8, INPUT);
  pinMode(PIN_LIGHT_SENSOR_A5, INPUT);
  recup_var();
}

void loop() {
  recup_var();
  if (interrupteur_lum) {
    //Mode lumière auto
    // Si la lumière est en dessous de 20% de la capacité du capteur ( 1023 ) alors la lumière s'allume
    if (lum_exterieur <= 1023 * 0.2) {
      digitalWrite(0, HIGH);
    } else {
      digitalWrite(0, LOW);
    }
  } else if (interrupteur_lum2) {
    //Mode lumière standard
    digitalWrite(0, HIGH);
  } else {
    //Mode lumière éteinte
    digitalWrite(0, LOW);
  }
  if (interrupteur_gen) {
    if (interrupteur_lames) {
      //interrupteur lames = 1 -> auto sinon manuel
      if (limite_vent < vitesse_vent) {
        //Mode vent extreme
        servomotor_7.write(45);
      } else if (temp < 2 && pluie) {
        //Mode neige
        servomotor_7.write(90);
      } else if (temp < 2) {
        //Mode Gel
        servomotor_7.write(90);
      } else if (pluie) {
        //Mode pluie
        servomotor_7.write(25);
      }
    } else {
      //Mode Manuel
      servomotor_7.write(potentiometre);
    }
  }
}