

/*


Auteur: cbaie tresneuf  

Interface: arduino

Nom du projet: Pergola v1

Description: No-description

Toolbox: vittascience

Mode: blocks

Blocks: <xml xmlns="https://developers.google.com/blockly/xml"><variables><variable id="hSBRw%[Pdf*|xh[q)R*7">temp</variable><variable id=":6vcnacR.4KR}RvI4_+X">interrupteur_gen</variable><variable id="O3nmZN;w024!B_Z!x]Z=">interrupteur_lum</variable><variable id="0E}CXTg?ewI:M[S%OpZr">texte1</variable><variable id="M}aOg6Y;QUrq+aF/+%G(">interrupteur lum2</variable><variable id="NFLG~[8xkK?!jHk`kthK">interrupteur_lames</variable><variable id="|5@?k%!C*;qyLvvxkf(+">vitesse_vent</variable><variable id="|22F`%Ah++3Q[IDZWZ(d">lum_exterieur</variable><variable id="BDVBy;8KTfz}1mf+75F^">pluie</variable><variable id="hi39;cKDXxzgi|Mb9os,">potentiometre</variable><variable id="X#Z!6yJ0vE!~tQUZf5cx">limite_vent</variable></variables><block type="on_start" id="G[=T#8yqB70`NFgYq}GP" deletable="false" x="13" y="13"><statement name="DO"><block type="procedures_callnoreturn" id="a~OQnw=+(Op5Z}Z6-+Tq"><mutation name="recup_var"></mutation><next><block type="procedures_callnoreturn" id="%alpwhdp2A?mhCkF1s^#"><mutation name="lcd"></mutation></block></next></block></statement></block><block type="controls_if" id="8ceagHsL)611om]y=`U7" disabled="true" x="287" y="237"><value name="IF0"><block type="variables_get" id="NeWCv1rI$]GaP.a$7H{N" disabled="true"><field name="VAR" id=":6vcnacR.4KR}RvI4_+X">interrupteur_gen</field></block></value></block><block type="forever" id="o[WN]+eeF.OUxGch67@8" deletable="false" x="13" y="263"><statement name="DO"><block type="text_comment" id="+6RSzgC7Su5|oja($.(|"><field name="TEXT">Mettre if interupteur gen avant prod final</field><next><block type="procedures_callnoreturn" id="g)%K=Tc8n]KVGxm7x`(e"><mutation name="recup_var"></mutation><next><block type="procedures_callnoreturn" id="~S,o@%D(e]JyqJ)`#kAY"><mutation name="lcd"></mutation><next><block type="controls_if" id="6`?Hk_[f;nKI800LUNq$"><mutation elseif="1" else="1"></mutation><value name="IF0"><block type="variables_get" id="Gz|CgG[5~mF;:Sm._iGV"><field name="VAR" id="O3nmZN;w024!B_Z!x]Z=">interrupteur_lum</field></block></value><statement name="DO0"><block type="text_comment" id="j|5@B9CSyo9PG0Ya_ApR"><field name="TEXT">Mode lumière auto</field><next><block type="controls_if" id="Q(.!JgKk4cUTa~;M#SBz"><mutation else="1"></mutation><comment pinned="false" h="80" w="160">Si la lumière est en dessous de 20% de la capacité du capteur ( 1023 ) alors la lumière s'allume </comment><value name="IF0"><block type="logic_compare" id="^+X*:3|.w2i8zK%`[.8D"><field name="OP">LTE</field><value name="A"><block type="variables_get" id="{i6vP=P3qSWT_4m;nk:m"><field name="VAR" id="|22F`%Ah++3Q[IDZWZ(d">lum_exterieur</field></block></value><value name="B"><shadow type="math_number" id="dhjN6tyISWAAO*xaiz+S"><field name="NUM">1</field></shadow><block type="math_arithmetic" id="zuF|(^fX08oEzjqt6*h|"><field name="OP">MULTIPLY</field><value name="A"><block type="math_number" id="DOV9O~Z$_G^%:hQ#_:5-"><field name="NUM">1023</field></block></value><value name="B"><shadow type="math_number" id="enC?o:sHiU.q~UbFc4{U"><field name="NUM">0.2</field></shadow></value></block></value></block></value><statement name="DO0"><block type="io_writeDigitalPin" id="gGq2}^Wo__b2gm__Q_[Q"><field name="PIN">13</field><value name="STATE"><shadow type="io_digital_signal" id="r2%CX-S[UacP_iuqz7bk"><field name="STATE">HIGH</field></shadow></value></block></statement><statement name="ELSE"><block type="io_writeDigitalPin" id="JOyk7}(D65T~^;Jf*k-R"><field name="PIN">13</field><value name="STATE"><shadow type="io_digital_signal" id="PJ#/.|O`P9,v9=wL@.v1"><field name="STATE">LOW</field></shadow></value></block></statement></block></next></block></statement><value name="IF1"><block type="variables_get" id="T{xvtllA}y6MWK8Y8}!c"><field name="VAR" id="M}aOg6Y;QUrq+aF/+%G(">interrupteur lum2</field></block></value><statement name="DO1"><block type="text_comment" id="OqV]B#/TpF#kCkY%[vSf"><field name="TEXT">Mode lumière standard</field><next><block type="io_writeDigitalPin" id="T8l8b3jec=Q3X6|#ggk7"><field name="PIN">13</field><value name="STATE"><shadow type="io_digital_signal" id="^k}M?G8ja]([Ej8(sPCI"><field name="STATE">HIGH</field></shadow></value></block></next></block></statement><statement name="ELSE"><block type="text_comment" id="z0[1W#Wim]Exi!4E$D-$"><field name="TEXT">Mode lumière éteinte</field><next><block type="io_writeDigitalPin" id="{VA~kvHNlmgP~@lEa$8f"><field name="PIN">13</field><value name="STATE"><shadow type="io_digital_signal" id="`@^*~Rtv5IMH~K,-cvJ)"><field name="STATE">LOW</field></shadow></value></block></next></block></statement><next><block type="controls_if" id="Dmve[(BNL%W{F^Jgb3cA"><mutation else="1"></mutation><value name="IF0"><block type="variables_get" id="[:x]YZO#6:oyXTE2is:-"><field name="VAR" id="NFLG~[8xkK?!jHk`kthK">interrupteur_lames</field></block></value><statement name="DO0"><block type="text_comment" id=".*6yN?#wHb5-}ojUd1hn"><field name="TEXT">interrupteur lames = 1 -&gt; auto sinon manuel</field><next><block type="controls_if" id="H(A[~**;er-,#xg/kTQ}"><mutation elseif="3"></mutation><value name="IF0"><block type="logic_compare" id="vy[`9YEv4AP*rI6v$FKi"><field name="OP">LT</field><value name="A"><block type="variables_get" id="L9[pMOk,;bVB6-Y;~pL`"><field name="VAR" id="X#Z!6yJ0vE!~tQUZf5cx">limite_vent</field></block></value><value name="B"><shadow type="math_number" id="DvH*kh9r6xc-%*q*(aIe"><field name="NUM">1</field></shadow><block type="variables_get" id="Z1E=Gdta[~ga4sr`P@V0"><field name="VAR" id="|5@?k%!C*;qyLvvxkf(+">vitesse_vent</field></block></value></block></value><statement name="DO0"><block type="text_comment" id="Jz,nu.x]liTV]ITOr=G$"><field name="TEXT">Mode vent extreme</field><next><block type="actuators_setServoAngle" id=")-[h0SUH776T]=#,O(*d"><field name="PIN">7</field><value name="ANGLE"><shadow type="math_number" id="EvRxm#S`0m1C7juD6z%h"><field name="NUM">45</field></shadow></value></block></next></block></statement><value name="IF1"><block type="logic_operation" id="=)x-NZ#rxW9IRZ`887}K"><field name="OP">AND</field><value name="A"><block type="logic_compare" id="!A39{p3i3^y%A`oycUv;"><field name="OP">LT</field><value name="A"><block type="variables_get" id="UGB!=uk(/|8CC)0pzhtf"><field name="VAR" id="hSBRw%[Pdf*|xh[q)R*7">temp</field></block></value><value name="B"><shadow type="math_number" id="2?j_]C$`AQ`G4/7V%Ab4"><field name="NUM">2</field></shadow></value></block></value><value name="B"><block type="variables_get" id="!cS}sJWpzzMNN1+Q!t?}"><field name="VAR" id="BDVBy;8KTfz}1mf+75F^">pluie</field></block></value></block></value><statement name="DO1"><block type="text_comment" id="UTAY;hJBTxjPtc63o2kq"><field name="TEXT">Mode neige</field><next><block type="actuators_setServoAngle" id="73guI.0A:E9HH$xK`/n{"><field name="PIN">7</field><value name="ANGLE"><shadow type="math_number" id=")tklwoZlb!H%UjVd(WCo"><field name="NUM">90</field></shadow></value></block></next></block></statement><value name="IF2"><block type="logic_compare" id="j9r_..ed~B={yK{!xg!Q"><field name="OP">LT</field><value name="A"><block type="variables_get" id="_q`2L-cairgg%t-r4I])"><field name="VAR" id="hSBRw%[Pdf*|xh[q)R*7">temp</field></block></value><value name="B"><shadow type="math_number" id="tKdkiPAj-HoL]vCSfuoR"><field name="NUM">2</field></shadow></value></block></value><statement name="DO2"><block type="text_comment" id="9N22$B[Hjb7jBPnK,UKQ"><field name="TEXT">Mode Gel</field><next><block type="actuators_setServoAngle" id="sy#S8[Wx:eZxOVK/#hww"><field name="PIN">7</field><value name="ANGLE"><shadow type="math_number" id="H}|0`4yR,Yj0s`5]uuB5"><field name="NUM">90</field></shadow></value></block></next></block></statement><value name="IF3"><block type="variables_get" id="[2i~L*mgf7x`nu27qRbm"><field name="VAR" id="BDVBy;8KTfz}1mf+75F^">pluie</field></block></value><statement name="DO3"><block type="text_comment" id="J,nopbbl=C2%vH=/k#9D"><field name="TEXT">Mode pluie</field><next><block type="actuators_setServoAngle" id="b4bIAL6gCIcRIY}J7V;@"><field name="PIN">7</field><value name="ANGLE"><shadow type="math_number" id="fJHh}.@OjbcJ]n]NtD~-"><field name="NUM">25</field></shadow></value></block></next></block></statement></block></next></block></statement><statement name="ELSE"><block type="text_comment" id="mezfOpCpM0)3Ea{Sdnz."><field name="TEXT">Mode Manuel</field><next><block type="actuators_setServoAngle" id="loqJ1.r4U}g{~_UH.-c{"><field name="PIN">7</field><value name="ANGLE"><shadow type="math_number" id="e[Sd3ZGK^12s-t_pu_5F"><field name="NUM">90</field></shadow><block type="variables_get" id="P^~icBA|M_0O(g-~1+Hr"><field name="VAR" id="hi39;cKDXxzgi|Mb9os,">potentiometre</field></block></value></block></next></block></statement></block></next></block></next></block></next></block></next></block></statement></block><block type="logic_compare" id="KwmRQ+Yf(E$`;@-OA-XS" disabled="true" x="13" y="2163"><field name="OP">GTE</field><value name="B"><shadow type="math_number"><field name="NUM">1</field></shadow><block type="math_arithmetic" id="8~`S[6x+=8Y}E]a}mJzg" disabled="true"><field name="OP">MULTIPLY</field><value name="A"><block type="math_number" id="-?!(@)eJ1CnScT0kQ3El" disabled="true"><field name="NUM">1023</field></block></value><value name="B"><shadow type="math_number" id="=%$%ewhk5,t;v1$;+Rq=" disabled="true"><field name="NUM">0.2</field></shadow></value></block></value></block><block type="logic_compare" id="0_/nPmlCw|Prhpa`Tw(G" disabled="true" x="13" y="2263"><field name="OP">GTE</field><value name="B"><shadow type="math_number"><field name="NUM">1</field></shadow><block type="math_arithmetic" id="UcrbBxqC6XuWRiC{YZGJ" disabled="true"><field name="OP">MULTIPLY</field><value name="A"><block type="math_number" id="??w+$s))*UWi,F?80zL}" disabled="true"><field name="NUM">1023</field></block></value><value name="B"><shadow type="math_number" id=".I7jjF0CzZ*nW`HL=kEr" disabled="true"><field name="NUM">0.2</field></shadow></value></block></value></block><block type="procedures_defnoreturn" id="}~]EW+e{;{gN`hF9OQdF" x="13" y="2363"><mutation name="lcd"></mutation><field name="NAME">lcd</field><statement name="STACK"><block type="controls_if" id="^a3Z.TV~QHNx7WM)B/:G"><mutation else="1"></mutation><value name="IF0"><block type="variables_get" id="r.:B(_1SMDD_psN~2Fmn"><field name="VAR" id="O3nmZN;w024!B_Z!x]Z=">interrupteur_lum</field></block></value><statement name="DO0"><block type="variables_set" id=")x~6#u7Ch%h~eW(Trw+^"><field name="VAR" id="0E}CXTg?ewI:M[S%OpZr">texte1</field><value name="VALUE"><shadow type="text" id="D}b!tEy(=,$fI)7D/bU+"><field name="TEXT">Automatique</field></shadow></value></block></statement><statement name="ELSE"><block type="controls_if" id="g#9qMpbBoi)MjUIDe@}N"><mutation else="1"></mutation><value name="IF0"><block type="variables_get" id="?38jGyTe=^EkVbeQ9%UG"><field name="VAR" id="M}aOg6Y;QUrq+aF/+%G(">interrupteur lum2</field></block></value><statement name="DO0"><block type="variables_set" id="oKVo-m/vdpPt1[+0toGV"><field name="VAR" id="0E}CXTg?ewI:M[S%OpZr">texte1</field><value name="VALUE"><shadow type="text" id="!nm`?.85rRYn2YkIjeG$"><field name="TEXT">Manuel: On</field></shadow></value></block></statement><statement name="ELSE"><block type="variables_set" id="Wd6}acwTw?!_krw#^r(:"><field name="VAR" id="0E}CXTg?ewI:M[S%OpZr">texte1</field><value name="VALUE"><shadow type="text" id="J6a0`2YT).(F@ptZ`rgd"><field name="TEXT">Manuel: Off</field></shadow></value></block></statement></block></statement><next><block type="display_lcdRGBSetPaletteColor" id="nnBG#@-5p/nc/F9pB]o/"><value name="COLOR"><block type="colour_picker" id=".CW36`y#]`J?EE1(Kxi["><field name="COLOUR">#3333ff</field></block></value><next><block type="display_lcdRGBSetText" id="igLmq_jmEv*NEx,,hHe?"><field name="ADDR">0x3e</field><field name="LINE">0</field><field name="POS">0</field><value name="TEXT"><shadow type="text" id="),mL7O5jmk[rvu!+k|;D"><field name="TEXT"></field></shadow><block type="text_join" id="s4%-*,,!N(6[|akD|eOl"><mutation items="2"></mutation><value name="ADD0"><block type="text" id="=z#ZWa!p^ym~bN~9xRzW"><field name="TEXT">Lumiere : </field></block></value><value name="ADD1"><block type="variables_get" id="B^$hYHDFbq^RGiRfWs1q"><field name="VAR" id="0E}CXTg?ewI:M[S%OpZr">texte1</field></block></value></block></value><next><block type="display_lcdRGBSetText" id="MGJPx$Y1u$;M6~p.3rno"><field name="ADDR">0x3e</field><field name="LINE">1</field><field name="POS">0</field><value name="TEXT"><shadow type="text"><field name="TEXT"></field></shadow><block type="text_join" id="be39QN0-Y!|..?5AWY.g"><mutation items="2"></mutation><value name="ADD0"><block type="text" id="=VF|^}?m#T5CS{{{DrXS"><field name="TEXT">Vent :  </field></block></value><value name="ADD1"><block type="variables_get" id="L.QNmU;kqjb)oMwt;O:]"><field name="VAR" id="|5@?k%!C*;qyLvvxkf(+">vitesse_vent</field></block></value></block></value><next><block type="io_wait" id="KAa!$|mYB//f,#YlWSh6"><field name="UNIT">SECOND</field><value name="TIME"><shadow type="math_number" id="sI+FWA.u#iIJ?}Ly#{Hw"><field name="NUM">3</field></shadow></value><next><block type="display_lcdRGBSetText" id="jiI)[tx+o~Rec3O,46pg"><field name="ADDR">0x3e</field><field name="LINE">1</field><field name="POS">0</field><value name="TEXT"><shadow type="text"><field name="TEXT"></field></shadow><block type="text_join" id="3PjMT8df8%;SHD;$QOOb"><mutation items="2"></mutation><value name="ADD0"><block type="text" id="s-u1=:-PQz0g!IDM%:w!"><field name="TEXT"> | Temp : </field></block></value><value name="ADD1"><block type="variables_get" id="#Q]tjo:D4Ll[C71hRh5-"><field name="VAR" id="hSBRw%[Pdf*|xh[q)R*7">temp</field></block></value></block></value></block></next></block></next></block></next></block></next></block></next></block></statement></block><block type="text" id="#F^ORDz%t|%3MIwB/k3Z" disabled="true" x="894" y="2974"><field name="TEXT"> | Temp : </field></block><block type="variables_get" id="Rb@L4CJ+*0MebcOJ;qal" disabled="true" x="1052" y="2975"><field name="VAR" id="hSBRw%[Pdf*|xh[q)R*7">temp</field></block><block type="variables_get" id="A.LT=GLxlW|hb+Bj/IE[" disabled="true" x="876" y="3081"><field name="VAR" id="hSBRw%[Pdf*|xh[q)R*7">temp</field></block><block type="text" id="uA(iY8H*o4%EFPtf,w0L" disabled="true" x="641" y="3113"><field name="TEXT">Vent :  </field></block><block type="procedures_defnoreturn" id="+]bc+(6J=BpQPD}BH-tS" x="43" y="3168"><mutation name="recup_var"></mutation><field name="NAME">recup_var</field><statement name="STACK"><block type="text_comment" id="A?mvl)!Z?[{!H7$wkm0}"><field name="TEXT">Mettre "true" de interrupteur gen sur d5 avant prod</field><next><block type="variables_set" id="akBN6-o(wA24MweHS_^L"><field name="VAR" id=":6vcnacR.4KR}RvI4_+X">interrupteur_gen</field><value name="VALUE"><shadow type="math_number" id="apS|I74O(cclhicfAZ+Y"><field name="NUM">0</field></shadow><block type="logic_boolean" id="A]4F1?Hl*{z5ifu(|[!*"><field name="BOOL">TRUE</field></block></value><next><block type="variables_set" id="BW//|gQA+b5xh`_z+PeV"><field name="VAR" id="NFLG~[8xkK?!jHk`kthK">interrupteur_lames</field><value name="VALUE"><shadow type="math_number" id="B?eOoOk^=opM3IX/wZAX"><field name="NUM">0</field></shadow><block type="io_readDigitalPin" id="Zzl8-*)9*K_6rZAO2p!~"><field name="PIN">4</field></block></value><next><block type="text_comment" id="ciN(^VYBRCa.IeS[OZSi"><field name="TEXT">interrupteur_lum | on = auto ; off = interrupteu_lum2</field><next><block type="text_comment" id="S/l?YFPiD~ugI$#-gAZx"><field name="TEXT">Mettre "true" de interrupteur lum sur d10 avant prod</field><next><block type="variables_set" id=")r4aj!1)vUzmdkcWwYDq"><field name="VAR" id="O3nmZN;w024!B_Z!x]Z=">interrupteur_lum</field><value name="VALUE"><shadow type="math_number" id="fFJ4Sudv[-Ph%{u1urUo"><field name="NUM">0</field></shadow><block type="logic_boolean" id="=]hACaq2t=YSq.EEbAjE"><field name="BOOL">TRUE</field></block></value><next><block type="text_comment" id="kl7QVys_3wK(f#Vj5_Be"><field name="TEXT">interrupteur_lum2 | off = éteindre , on = éclairage standard  </field><next><block type="variables_set" id="X~#s8`zaP3J8swV9o(V^"><field name="VAR" id="M}aOg6Y;QUrq+aF/+%G(">interrupteur lum2</field><value name="VALUE"><shadow type="math_number"><field name="NUM">0</field></shadow><block type="io_readDigitalPin" id="=L$*Lzw;JKo:q+{`cU.3"><field name="PIN">12</field></block></value><next><block type="variables_set" id=")saHyG#xBW#Kg^4WVJFM"><field name="VAR" id="|5@?k%!C*;qyLvvxkf(+">vitesse_vent</field><value name="VALUE"><shadow type="math_number" id="h]{/7lCJA`LDo$8!Nk#5"><field name="NUM">0</field></shadow><block type="io_readAnalogPin" id="2F1AA$Kfiu$O`(jv4YW$"><field name="PIN">A1</field></block></value><next><block type="variables_set" id="f$_PgU$ylk2%jDT7q^9d"><field name="VAR" id="hSBRw%[Pdf*|xh[q)R*7">temp</field><value name="VALUE"><shadow type="math_number" id="tX-]OQM-!t.%=J(*(S*b"><field name="NUM">0</field></shadow><block type="sensors_getGroveTemperature" id="`#bOZXj]oZ7b6a63P|*E"><field name="UNIT">CELSIUS</field><field name="PIN">A0</field></block></value><next><block type="variables_set" id="ZcTax4^P]D_tl+1nUU?S"><field name="VAR" id="hi39;cKDXxzgi|Mb9os,">potentiometre</field><value name="VALUE"><shadow type="math_number" id="v!.mtk,Pk6FE[feI`7/;"><field name="NUM">0</field></shadow><block type="io_readAnalogPin" id="yUsl=G.%D]lmIWm*q)J2"><field name="PIN">A3</field></block></value><next><block type="variables_set" id="8v4Za/|^7)MBW|WF1S}P"><field name="VAR" id="BDVBy;8KTfz}1mf+75F^">pluie</field><value name="VALUE"><shadow type="math_number" id="a^[ta*^{eDdV7F$H|k0f"><field name="NUM">0</field></shadow><block type="io_readDigitalPin" id="=AJQZaAl7h*C{@5pq82~"><field name="PIN">6</field></block></value><next><block type="variables_set" id="RTt^x9jV9IRkW4d:b`Nn"><field name="VAR" id="X#Z!6yJ0vE!~tQUZf5cx">limite_vent</field><value name="VALUE"><shadow type="math_number" id="$cW`RrVZqSd+1P:WhMHx"><field name="NUM">90</field></shadow><block type="math_arithmetic" id="gmqvgwQ3]WBr3%ufbpY0"><field name="OP">MULTIPLY</field><value name="A"><block type="math_number" id="xV*-M-47e:@@CZ_=4GU9"><field name="NUM">1023</field></block></value><value name="B"><shadow type="math_number" id="x_!A3Mb%u?C3td]fZl-e"><field name="NUM">0.7</field></shadow></value></block></value><next><block type="variables_set" id="``toKmf*RVD::nYg~GUs"><field name="VAR" id="|22F`%Ah++3Q[IDZWZ(d">lum_exterieur</field><value name="VALUE"><shadow type="math_number" id="E{b}IxE3.(]9D5PF/+Dc"><field name="NUM">90</field></shadow><block type="io_readAnalogPin" id="5$yMbQJpI[8sg!0#*|S|"><field name="PIN">A2</field></block></value><next><block type="communication_serialWrite" id="4,m()p]FVAowW?iCMFT="><mutation newlines="true"></mutation><field name="NEWLINES">1</field><value name="TEXT"><shadow type="text" id="Y_m|%|sb=5mWQfVyP-;s"><field name="TEXT">Bonjour !</field></shadow><block type="text_join" id="f|z(Nr!b80n?qbQDW]AN"><mutation items="2"></mutation><value name="ADD0"><block type="text" id="S60`qUoTTRDoI}MVCn~."><field name="TEXT">Capteur lum : </field></block></value><value name="ADD1"><block type="variables_get" id="j[h(11*QqUq,w~MV^mAL"><field name="VAR" id="|22F`%Ah++3Q[IDZWZ(d">lum_exterieur</field></block></value></block></value><next><block type="communication_serialWrite" id="MWd?*3|9)FsAJhYzOZ+X"><mutation newlines="true"></mutation><field name="NEWLINES">1</field><value name="TEXT"><shadow type="text" id="-%J=aM]Sg5,8=S6c1a~8"><field name="TEXT">Bonjour !</field></shadow><block type="text_join" id="vQ^w|}=MQ[3Fc:Dm/1H("><mutation items="2"></mutation><value name="ADD0"><block type="text" id="wQ?Af``i_~C?{$?742_L"><field name="TEXT">Capteur pluie : </field></block></value><value name="ADD1"><block type="variables_get" id="E|,9_1IuF/X1j+x+I:Hg"><field name="VAR" id="BDVBy;8KTfz}1mf+75F^">pluie</field></block></value></block></value><next><block type="communication_serialWrite" id="PY3(]]][%2_|*XmI4I^_"><mutation newlines="true"></mutation><field name="NEWLINES">1</field><value name="TEXT"><shadow type="text"><field name="TEXT">Bonjour !</field></shadow><block type="text_join" id="AK|1W9ZwSJs1yH!N733o"><mutation items="2"></mutation><value name="ADD0"><block type="text" id="C$PN)QoJKU4,C.jE1o+S"><field name="TEXT">Capteur temp : </field></block></value><value name="ADD1"><block type="variables_get" id="chVc~YCl%|=Fl@J8?3RQ"><field name="VAR" id="hSBRw%[Pdf*|xh[q)R*7">temp</field></block></value></block></value></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></statement></block><block type="io_readDigitalPin" id="h?|Ok{[]2kBxr7i%?#zV" disabled="true" x="513" y="3238"><field name="PIN">5</field></block><block type="logic_boolean" id=".X;xHR)|CVhK_R7bOaDF" disabled="true" x="513" y="3238"><field name="BOOL">TRUE</field></block><block type="logic_boolean" id="-69,T(8,;D|-YOS-7;sG" disabled="true" x="737" y="3338"><field name="BOOL">TRUE</field></block><block type="io_readDigitalPin" id="/;cfZB.sc6#i|Y_4a1(!" disabled="true" x="587" y="3437"><field name="PIN">10</field></block><block type="io_getGroveSwitch" id="3~e?nDPtscfu7J$k`HSK" disabled="true" x="13" y="4038"><field name="PIN">12</field></block><block type="io_getGroveSlidePotentiometer" id="}IU3_9-X2!Bg}ce,05]p" disabled="true" x="13" y="4138"><field name="PIN">A1</field></block><block type="io_readAnalogPin" id="1htjZ!uHuoFtks^UG2S#" disabled="true" x="13" y="4238"><field name="PIN">A0</field></block><block type="io_getGroveSlidePotentiometer" id="fV=)T.V8}Zug|q+,%2S{" disabled="true" x="13" y="4338"><field name="PIN">A0</field></block></xml>

Projet généré par Vittascience.

Ce fichier contient le code textuel ainsi que le code blocs. Il peut être importé de nouveau

sur l'interface http://vittascience.com/arduino


*/
#include <Servo.h>
#include <Wire.h>
#include <rgb_lcd.h>

#define PIN_SERVO_7  7
#define PIN_TEMPERATURE_SENSOR_A0  A14                          
#define PIN_POTENTIOMETER_A2  A2

Servo servomotor_7;
rgb_lcd lcdRgb;

String texte1;
int loop_lrgb;
boolean interrupteur_gen;
boolean interrupteur_lames;
boolean interrupteur_lum;
boolean interrupteur_lum2;
int vitesse_vent;
float temp;
int potentiometre;
boolean pluie;
float limite_vent;
int lum_exterieur;

uint16_t getAnalogMean(uint8_t pin, uint8_t n) { //Stabilitée des capteur  ; moyenne des valeur 
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += analogRead(pin);
    delay(1);
  }
  return sum / n;
}

float getGroveTemperature(uint8_t pin, uint8_t unit) { // Code constructeur de conversion, source Seeed, modifié par vittascience
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

void serial_setupConnection(int baudrate) {
  Serial.begin(baudrate);
  while (!Serial) {
    Serial.println("En attente de l'ouverture du port série...");
    delay(1000);
  }
  Serial.println("Port série activé. Baudrate: " + String(baudrate));
  delay(50);
}

void lcd() {
  if (interrupteur_lum) {
    texte1 = "Automatique";
  } else {
    if (interrupteur_lum2) {
      texte1 = "Manuel: On";
    } else {
      texte1 = "Manuel: Off";
    }
  }
  lcdRgb.setRGB(51, 51, 255);
  lcdRgb.setCursor(0, 0);
  lcdRgb.print(String((String("Lumiere : ") + String(texte1))));
  loop_lrgb += 1;
  if (loop_lrgb >= 0 && loop_lrgb < 60) {
    lcdRgb.setCursor(0, 1);
    lcdRgb.print(String((String("Lum :  ") + String(lum_exterieur))));
  } else if (loop_lrgb >= 60 && loop_lrgb < 120) {
    lcdRgb.setCursor(0, 1);
    lcdRgb.print(String((String("Temp : ") + String(temp))));
  } else if (loop_lrgb > 120) {
    loop_lrgb = 0;
  }
}

void recup_var() {
  //Mettre "true" de interrupteur gen sur d5 avant prod
  interrupteur_gen = true;
  interrupteur_lames = digitalRead(4);
  //interrupteur_lum | on = auto ; off = interrupteu_lum2
  //Mettre "true" de interrupteur lum sur d10 avant prod
  interrupteur_lum = true;
  //interrupteur_lum2 | off = éteindre , on = éclairage standard
  interrupteur_lum2 = digitalRead(12);
  vitesse_vent = analogRead(A6);
  temp = getGroveTemperature(PIN_TEMPERATURE_SENSOR_A0, 0);
  potentiometre = analogRead(PIN_POTENTIOMETER_A2);
  pluie = digitalRead(6);
  limite_vent = 1023 * 0.7;
  lum_exterieur = analogRead(A4);
  Serial.println((String("Capteur lum : ") + String(lum_exterieur)));
  Serial.println((String("Capteur pluie : ") + String(pluie)));
  Serial.println((String("Capteur temp : ") + String(temp)));
}


void setup() {
  Serial.begin(9600);
  lcdRgb.begin(16, 2);
  servomotor_7.attach(PIN_SERVO_7);  // Attacher le servo une seule fois dans setup
  servomotor_7.write(0);  // Mettre le servo à 0 degrés
  pinMode(PIN_TEMPERATURE_SENSOR_A0, INPUT);
  pinMode(PIN_POTENTIOMETER_A2, INPUT);  // Définir la broche du potentiomètre comme entrée
  pinMode(A4, INPUT);
  pinMode(A6, INPUT);
  pinMode(4, INPUT);
  pinMode(10, INPUT); // inter lum 1
  pinMode(12, INPUT); // inter lum 2
  pinMode(6, INPUT); // pluie
  pinMode(13, INPUT); // lum temp
  serial_setupConnection(9600);
  recup_var();
  lcd();
}

void loop() {
  //Mettre if interupteur gen avant prod final
  recup_var();
  lcd();
  if (interrupteur_lum) {
    //Mode lumière auto
    // Si la lumière est en dessous de 20% de la capacité du capteur ( 1023 ) alors la lumière s'allume
    if (lum_exterieur <= 1023 * 0.2) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  } else if (interrupteur_lum2) {
    //Mode lumière standard
    digitalWrite(13, HIGH);
  } else {
    //Mode lumière éteinte
    digitalWrite(13, LOW);
  }
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
    int potValue = analogRead(PIN_POTENTIOMETER_A2);  // Lire la valeur du potentiomètre
    float angle = (potValue / 1023.0) * 90;  // Convertir la valeur en angle (0 à 180 degrés)
    servomotor_7.write(angle);  // Définir l'angle du servo
    delay(15);  // Ajouter un léger délai pour stabiliser le signal
  }
}
