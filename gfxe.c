#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gfx5.h"
#include "gfxe.h"

/**************************
* Link, the camel arrives *
**************************/

unsigned char * readRAWImage ( char * filename, int headerSize) {
	FILE *ifp = fopen(filename,"rb");

  if (ifp == NULL) {
    fprintf (stderr, "Could not open '%s' for reading. Check that the program is executing with sufficient permissions or that the file actually exists.\n",filename);
    return NULL;
  }

  fseek(ifp, 0, SEEK_END);
  int length = ftell(ifp);
  rewind(ifp);
  fseek(ifp, headerSize, SEEK_SET);
    
  length = length - headerSize;

  unsigned char * buffer = (unsigned char *) malloc((length + 1) * sizeof(char));;
	
	fread(buffer, length, 1, ifp);
		
  *(buffer + length) = '\0';

  fclose(ifp);

  return buffer;
}

void printRAWImage ( int offsetX, int offsetY, int sizeX, int sizeY, char * bufferPtr ) {	
	int i,j;
	int r,g,b;
	
	for (i=0; i < sizeX; ++i) {
		for (j=0; j < sizeY; ++j) {
			r = *(bufferPtr + 3 * (j * sizeX + i));
			g = *(bufferPtr + 3 * (j * sizeX + i) + 1);
			b = *(bufferPtr + 3 * (j * sizeX + i) + 2);
			gfx_color(r,g,b);
      gfx_point(offsetX + i, offsetY + sizeY - j);

		}
	}
}

void gfx_predefined_color( char * colorname ) {
  int length = strlen(colorname)/sizeof(char);
  uint32_t hash = SuperFastHash(colorname,length);
  switch(hash) {
    case 1809820135:
      gfx_color(255,250,250);
      break;
    case 1818275625:
      gfx_color(248,248,255);
      break;
    case 3838495697:
      gfx_color(248,248,255);
      break;
    case 773700401:
      gfx_color(245,245,245);
      break;
    case 1247264491:
      gfx_color(220,220,220);
      break;
    case 1602836442:
      gfx_color(255,250,240);
      break;
    case 2156518503:
      gfx_color(255,250,240);
      break;
    case 661042986:
      gfx_color(253,245,230);
      break;
    case 2276000400:
      gfx_color(253,245,230);
      break;
    case 2242198049:
      gfx_color(250,240,230);
      break;
    case 2688316282:
      gfx_color(250,235,215);
      break;
    case 4016387158:
      gfx_color(250,235,215);
      break;
    case 1608838840:
      gfx_color(255,239,213);
      break;
    case 4118417489:
      gfx_color(255,239,213);
      break;
    case 3194735169:
      gfx_color(255,235,205);
      break;
    case 3118407921:
      gfx_color(255,235,205);
      break;
    case 1098790494:
      gfx_color(255,228,196);
      break;
    case 3730918885:
      gfx_color(255,218,185);
      break;
    case 95763105:
      gfx_color(255,218,185);
      break;
    case 386781938:
      gfx_color(255,222,173);
      break;
    case 884375227:
      gfx_color(255,222,173);
      break;
    case 1590474460:
      gfx_color(255,228,181);
      break;
    case 1852399327:
      gfx_color(255,248,220);
      break;
    case 1044824106:
      gfx_color(255,255,240);
      break;
    case 3937728182:
      gfx_color(255,250,205);
      break;
    case 2764302046:
      gfx_color(255,250,205);
      break;
    case 3737887208:
      gfx_color(255,245,238);
      break;
    case 2549008335:
      gfx_color(240,255,240);
      break;
    case 824794090:
      gfx_color(245,255,250);
      break;
    case 1223905380:
      gfx_color(245,255,250);
      break;
    case 1015987116:
      gfx_color(240,255,255);
      break;
    case 88046878:
      gfx_color(240,248,255);
      break;
    case 1733232922:
      gfx_color(240,248,255);
      break;
    case 440892202:
      gfx_color(230,230,250);
      break;
    case 3751866099:
      gfx_color(255,240,245);
      break;
    case 1989404904:
      gfx_color(255,228,225);
      break;
    case 193680519:
      gfx_color(255,228,225);
      break;
    case 228007648:
      gfx_color(255,255,255);
      break;
    case 1486411412:
      gfx_color(0,0,0);
      break;
    case 3751814917:
      gfx_color(47,79,79);
      break;
    case 1055936136:
      gfx_color(47,79,79);
      break;
    case 3154955566:
      gfx_color(105,105,105);
      break;
    case 178069509:
      gfx_color(105,105,105);
      break;
    case 2720960665:
      gfx_color(112,128,144);
      break;
    case 932828468:
      gfx_color(112,128,144);
      break;
    case 450580639:
      gfx_color(112,128,144);
      break;
    case 2453836530:
      gfx_color(119,136,153);
      break;
    case 3683935298:
      gfx_color(119,136,153);
      break;
    case 48578756:
      gfx_color(190,190,190);
      break;
    case 2400200239:
      gfx_color(190,190,190);
      break;
    case 1449335523:
      gfx_color(211,211,211);
      break;
    case 3010338699:
      gfx_color(211,211,211);
      break;
    case 1959248708:
      gfx_color(25,25,112);
      break;
    case 2942466822:
      gfx_color(25,25,112);
      break;
    case 1387523101:
      gfx_color(0,0,128);
      break;
    case 4168909231:
      gfx_color(0,0,128);
      break;
    case 1919038514:
      gfx_color(100,149,237);
      break;
    case 496162896:
      gfx_color(100,149,237);
      break;
    case 3391758673:
      gfx_color(72,61,139);
      break;
    case 729910191:
      gfx_color(106,90,205);
      break;
    case 1379156910:
      gfx_color(123,104,238);
      break;
    case 1532039902:
      gfx_color(132,112,255);
      break;
    case 4197864669:
      gfx_color(0,0,205);
      break;
    case 1570630015:
      gfx_color(65,105,225);
      break;
    case 3772473026:
      gfx_color(65,105,225);
      break;
    case 426152014:
      gfx_color(0,0,255);
      break;
    case 1437694570:
      gfx_color(30,144,255);
      break;
    case 1282020328:
      gfx_color(30,144,255);
      break;
    case 718785783:
      gfx_color(0,191,255);
      break;
    case 2470916347:
      gfx_color(135,206,235);
      break;
    case 2747026375:
      gfx_color(135,206,235);
      break;
    case 2795090452:
      gfx_color(135,206,250);
      break;
    case 40114730:
      gfx_color(70,130,180);
      break;
    case 659794552:
      gfx_color(70,130,180);
      break;
    case 1217582251:
      gfx_color(176,196,222);
      break;
    case 2667307562:
      gfx_color(173,216,230);
      break;
    case 1605922946:
      gfx_color(176,224,230);
      break;
    case 3609934049:
      gfx_color(176,224,230);
      break;
    case 1452584998:
      gfx_color(175,238,238);
      break;
    case 3213321387:
      gfx_color(0,206,209);
      break;
    case 3847418348:
      gfx_color(72,209,204);
      break;
    case 3557267935:
      gfx_color(64,224,208);
      break;
    case 257330022:
      gfx_color(0,255,255);
      break;
    case 1336600161:
      gfx_color(224,255,255);
      break;
    case 4120395142:
      gfx_color(95,158,160);
      break;
    case 2740278301:
      gfx_color(95,158,160);
      break;
    case 537047434:
      gfx_color(102,205,170);
      break;
    case 2399185416:
      gfx_color(127,255,212);
      break;
    case 1103104596:
      gfx_color(0,100,0);
      break;
    case 3331351607:
      gfx_color(85,107,47);
      break;
    case 3856522726:
      gfx_color(143,188,143);
      break;
    case 2162552393:
      gfx_color(46,139,87);
      break;
    case 3617165869:
      gfx_color(46,139,87);
      break;
    case 2735564032:
      gfx_color(60,179,113);
      break;
    case 2092320779:
      gfx_color(32,178,170);
      break;
    case 3836721390:
      gfx_color(152,251,152);
      break;
    case 3556322773:
      gfx_color(0,255,127);
      break;
    case 3457060753:
      gfx_color(0,255,127);
      break;
    case 1438799992:
      gfx_color(124,252,0);
      break;
    case 580856725:
      gfx_color(124,252,0);
      break;
    case 2376913599:
      gfx_color(0,255,0);
      break;
    case 27739481:
      gfx_color(127,255,0);
      break;
    case 2974832132:
      gfx_color(0,250,154);
      break;
    case 4072870429:
      gfx_color(173,255,47);
      break;
    case 1597776021:
      gfx_color(50,205,50);
      break;
    case 442679664:
      gfx_color(50,205,50);
      break;
    case 2993698154:
      gfx_color(154,205,50);
      break;
    case 247952604:
      gfx_color(34,139,34);
      break;
    case 2771233729:
      gfx_color(34,139,34);
      break;
    case 1027863961:
      gfx_color(107,142,35);
      break;
    case 3871470661:
      gfx_color(107,142,35);
      break;
    case 3234884398:
      gfx_color(189,183,107);
      break;
    case 3209618521:
      gfx_color(240,230,140);
      break;
    case 3305234435:
      gfx_color(238,232,170);
      break;
    case 538902704:
      gfx_color(250,250,210);
      break;
    case 4126854089:
      gfx_color(255,255,224);
      break;
    case 3640544360:
      gfx_color(255,255,0);
      break;
    case 1403881396:
      gfx_color(255,215,0);
      break;
    case 39524302:
      gfx_color(238,221,130);
      break;
    case 144362807:
      gfx_color(218,165,32);
      break;
    case 2275225379:
      gfx_color(184,134,11);
      break;
    case 309380462:
      gfx_color(188,143,143);
      break;
    case 3748555008:
      gfx_color(188,143,143);
      break;
    case 3008588914:
      gfx_color(205,92,92);
      break;
    case 3112395124:
      gfx_color(205,92,92);
      break;
    case 4223604687:
      gfx_color(139,69,19);
      break;
    case 3848163639:
      gfx_color(139,69,19);
      break;
    case 3327554784:
      gfx_color(160,82,45);
      break;
    case 3739906794:
      gfx_color(205,133,63);
      break;
    case 3766653569:
      gfx_color(222,184,135);
      break;
    case 2525812785:
      gfx_color(245,245,220);
      break;
    case 2336945412:
      gfx_color(245,222,179);
      break;
    case 2279741344:
      gfx_color(244,164,96);
      break;
    case 34114789:
      gfx_color(244,164,96);
      break;
    case 2389466489:
      gfx_color(210,180,140);
      break;
    case 2632900591:
      gfx_color(210,105,30);
      break;
    case 2327778071:
      gfx_color(178,34,34);
      break;
    case 48666330:
      gfx_color(165,42,42);
      break;
    case 598003133:
      gfx_color(233,150,122);
      break;
    case 3966770341:
      gfx_color(250,128,114);
      break;
    case 3747712592:
      gfx_color(255,160,122);
      break;
    case 138044688:
      gfx_color(255,165,0);
      break;
    case 773216263:
      gfx_color(255,140,0);
      break;
    case 3820898987:
      gfx_color(255,127,80);
      break;
    case 2845159222:
      gfx_color(240,128,128);
      break;
    case 3181594264:
      gfx_color(255,99,71);
      break;
    case 4041994562:
      gfx_color(255,69,0);
      break;
    case 1647437277:
      gfx_color(255,0,0);
      break;
    case 3872159385:
      gfx_color(255,105,180);
      break;
    case 4271173587:
      gfx_color(255,105,180);
      break;
    case 684500276:
      gfx_color(255,20,147);
      break;
    case 2289971368:
      gfx_color(255,192,203);
      break;
    case 2102634479:
      gfx_color(255,182,193);
      break;
    case 1070042258:
      gfx_color(219,112,147);
      break;
    case 2308200163:
      gfx_color(176,48,96);
      break;
    case 2573125874:
      gfx_color(199,21,133);
      break;
    case 1502315831:
      gfx_color(208,32,144);
      break;
    case 2688339307:
      gfx_color(255,0,255);
      break;
    case 2214110581:
      gfx_color(238,130,238);
      break;
    case 1599441238:
      gfx_color(221,160,221);
      break;
    case 2180047754:
      gfx_color(218,112,214);
      break;
    case 332802395:
      gfx_color(186,85,211);
      break;
    case 1513413376:
      gfx_color(153,50,204);
      break;
    case 1662174600:
      gfx_color(148,0,211);
      break;
    case 3553120079:
      gfx_color(138,43,226);
      break;
    case 46444368:
      gfx_color(160,32,240);
      break;
    case 2703329891:
      gfx_color(147,112,219);
      break;
    case 14554297:
      gfx_color(216,191,216);
      break;
    case 2002040640:
      gfx_color(255,250,250);
      break;
    case 2988352934:
      gfx_color(238,233,233);
      break;
    case 3432171877:
      gfx_color(205,201,201);
      break;
    case 1660202250:
      gfx_color(139,137,137);
      break;
    case 2040397205:
      gfx_color(255,245,238);
      break;
    case 503809468:
      gfx_color(238,229,222);
      break;
    case 4289420794:
      gfx_color(205,197,191);
      break;
    case 3196455836:
      gfx_color(139,134,130);
      break;
    case 406339950:
      gfx_color(255,239,219);
      break;
    case 1189831205:
      gfx_color(238,223,204);
      break;
    case 4015243839:
      gfx_color(205,192,176);
      break;
    case 1936725509:
      gfx_color(139,131,120);
      break;
    case 601258218:
      gfx_color(255,228,196);
      break;
    case 2069568838:
      gfx_color(238,213,183);
      break;
    case 3056722437:
      gfx_color(205,183,158);
      break;
    case 3814095982:
      gfx_color(139,125,107);
      break;
    case 2159844833:
      gfx_color(255,218,185);
      break;
    case 2277437598:
      gfx_color(238,203,173);
      break;
    case 3343053937:
      gfx_color(205,175,149);
      break;
    case 86666921:
      gfx_color(139,119,101);
      break;
    case 2112954691:
      gfx_color(255,222,173);
      break;
    case 3683421199:
      gfx_color(238,207,161);
      break;
    case 4047080441:
      gfx_color(205,179,139);
      break;
    case 1434449460:
      gfx_color(139,121,94);
      break;
    case 701602617:
      gfx_color(255,250,205);
      break;
    case 3498797096:
      gfx_color(238,233,191);
      break;
    case 1928617655:
      gfx_color(205,201,165);
      break;
    case 3807243017:
      gfx_color(139,137,112);
      break;
    case 4283750518:
      gfx_color(255,248,220);
      break;
    case 3773902367:
      gfx_color(238,232,205);
      break;
    case 3603422188:
      gfx_color(205,200,177);
      break;
    case 3023153555:
      gfx_color(139,136,120);
      break;
    case 47682936:
      gfx_color(255,255,240);
      break;
    case 2981065601:
      gfx_color(238,238,224);
      break;
    case 2586044625:
      gfx_color(205,205,193);
      break;
    case 2197437707:
      gfx_color(139,139,131);
      break;
    case 2186185342:
      gfx_color(240,255,240);
      break;
    case 2526676782:
      gfx_color(224,238,224);
      break;
    case 341098257:
      gfx_color(193,205,193);
      break;
    case 1299947167:
      gfx_color(131,139,131);
      break;
    case 2170561046:
      gfx_color(255,240,245);
      break;
    case 898850942:
      gfx_color(238,224,229);
      break;
    case 172900811:
      gfx_color(205,193,197);
      break;
    case 887203094:
      gfx_color(139,131,134);
      break;
    case 1497638367:
      gfx_color(255,228,225);
      break;
    case 62985596:
      gfx_color(238,213,210);
      break;
    case 1421840070:
      gfx_color(205,183,181);
      break;
    case 978641186:
      gfx_color(139,125,123);
      break;
    case 110524218:
      gfx_color(240,255,255);
      break;
    case 801025602:
      gfx_color(224,238,238);
      break;
    case 1973709424:
      gfx_color(193,205,205);
      break;
    case 3268296037:
      gfx_color(131,139,139);
      break;
    case 4037282576:
      gfx_color(131,111,255);
      break;
    case 2832997251:
      gfx_color(122,103,238);
      break;
    case 616579211:
      gfx_color(105,89,205);
      break;
    case 3580678904:
      gfx_color(71,60,139);
      break;
    case 2758222327:
      gfx_color(72,118,255);
      break;
    case 2026582625:
      gfx_color(67,110,238);
      break;
    case 3390895386:
      gfx_color(58,95,205);
      break;
    case 1954105149:
      gfx_color(39,64,139);
      break;
    case 2399448975:
      gfx_color(0,0,255);
      break;
    case 219386220:
      gfx_color(0,0,238);
      break;
    case 1343797919:
      gfx_color(0,0,205);
      break;
    case 2161453987:
      gfx_color(0,0,139);
      break;
    case 4290742076:
      gfx_color(30,144,255);
      break;
    case 2284960101:
      gfx_color(28,134,238);
      break;
    case 4020999224:
      gfx_color(24,116,205);
      break;
    case 1838034867:
      gfx_color(16,78,139);
      break;
    case 3025466:
      gfx_color(99,184,255);
      break;
    case 3811455560:
      gfx_color(92,172,238);
      break;
    case 4008990548:
      gfx_color(79,148,205);
      break;
    case 587120703:
      gfx_color(54,100,139);
      break;
    case 2573364245:
      gfx_color(0,191,255);
      break;
    case 289238701:
      gfx_color(0,178,238);
      break;
    case 2288558965:
      gfx_color(0,154,205);
      break;
    case 2203644535:
      gfx_color(0,104,139);
      break;
    case 2908314415:
      gfx_color(135,206,255);
      break;
    case 3250060900:
      gfx_color(126,192,238);
      break;
    case 2162481321:
      gfx_color(108,166,205);
      break;
    case 502755481:
      gfx_color(74,112,139);
      break;
    case 3919031471:
      gfx_color(176,226,255);
      break;
    case 2559109475:
      gfx_color(164,211,238);
      break;
    case 4228794170:
      gfx_color(141,182,205);
      break;
    case 982365172:
      gfx_color(96,123,139);
      break;
    case 1594070088:
      gfx_color(198,226,255);
      break;
    case 2269973979:
      gfx_color(185,211,238);
      break;
    case 1531307776:
      gfx_color(159,182,205);
      break;
    case 1395447236:
      gfx_color(108,123,139);
      break;
    case 4092518902:
      gfx_color(202,225,255);
      break;
    case 2027930302:
      gfx_color(188,210,238);
      break;
    case 2169365747:
      gfx_color(162,181,205);
      break;
    case 1357435960:
      gfx_color(110,123,139);
      break;
    case 3242841740:
      gfx_color(191,239,255);
      break;
    case 3497286401:
      gfx_color(178,223,238);
      break;
    case 3809607360:
      gfx_color(154,192,205);
      break;
    case 866136164:
      gfx_color(104,131,139);
      break;
    case 2209319328:
      gfx_color(224,255,255);
      break;
    case 2131722957:
      gfx_color(209,238,238);
      break;
    case 3815701065:
      gfx_color(180,205,205);
      break;
    case 2108976094:
      gfx_color(122,139,139);
      break;
    case 3261297810:
      gfx_color(187,255,255);
      break;
    case 3601660966:
      gfx_color(174,238,238);
      break;
    case 3364039955:
      gfx_color(150,205,205);
      break;
    case 3290238032:
      gfx_color(102,139,139);
      break;
    case 2222697860:
      gfx_color(152,245,255);
      break;
    case 4249525623:
      gfx_color(142,229,238);
      break;
    case 4107732809:
      gfx_color(122,197,205);
      break;
    case 745170325:
      gfx_color(83,134,139);
      break;
    case 1373874668:
      gfx_color(0,245,255);
      break;
    case 2492887328:
      gfx_color(0,229,238);
      break;
    case 1115914242:
      gfx_color(0,197,205);
      break;
    case 2462462927:
      gfx_color(0,134,139);
      break;
    case 1163781074:
      gfx_color(0,255,255);
      break;
    case 2357595216:
      gfx_color(0,238,238);
      break;
    case 1573841362:
      gfx_color(0,205,205);
      break;
    case 2834108938:
      gfx_color(0,139,139);
      break;
    case 1562161234:
      gfx_color(151,255,255);
      break;
    case 3215361377:
      gfx_color(141,238,238);
      break;
    case 1050844324:
      gfx_color(121,205,205);
      break;
    case 622725063:
      gfx_color(82,139,139);
      break;
    case 1352428079:
      gfx_color(127,255,212);
      break;
    case 4203491673:
      gfx_color(118,238,198);
      break;
    case 757058190:
      gfx_color(102,205,170);
      break;
    case 1373247596:
      gfx_color(69,139,116);
      break;
    case 1305039483:
      gfx_color(193,255,193);
      break;
    case 998390796:
      gfx_color(180,238,180);
      break;
    case 3009327976:
      gfx_color(155,205,155);
      break;
    case 2087877278:
      gfx_color(105,139,105);
      break;
    case 1613708065:
      gfx_color(84,255,159);
      break;
    case 3522181572:
      gfx_color(78,238,148);
      break;
    case 524035033:
      gfx_color(67,205,128);
      break;
    case 1819164203:
      gfx_color(46,139,87);
      break;
    case 2254136370:
      gfx_color(154,255,154);
      break;
    case 1716543051:
      gfx_color(144,238,144);
      break;
    case 759070427:
      gfx_color(124,205,124);
      break;
    case 2880773321:
      gfx_color(84,139,84);
      break;
    case 1840620195:
      gfx_color(0,255,127);
      break;
    case 3932201172:
      gfx_color(0,238,118);
      break;
    case 3381766499:
      gfx_color(0,205,102);
      break;
    case 3665765521:
      gfx_color(0,139,69);
      break;
    case 2908558077:
      gfx_color(0,255,0);
      break;
    case 4154574567:
      gfx_color(0,238,0);
      break;
    case 3669004019:
      gfx_color(0,205,0);
      break;
    case 979417299:
      gfx_color(0,139,0);
      break;
    case 3537624275:
      gfx_color(127,255,0);
      break;
    case 1736932855:
      gfx_color(118,238,0);
      break;
    case 4262276121:
      gfx_color(102,205,0);
      break;
    case 4172365513:
      gfx_color(69,139,0);
      break;
    case 1556102994:
      gfx_color(192,255,62);
      break;
    case 3000115937:
      gfx_color(179,238,58);
      break;
    case 2538852391:
      gfx_color(154,205,50);
      break;
    case 3236572055:
      gfx_color(105,139,34);
      break;
    case 2497784256:
      gfx_color(202,255,112);
      break;
    case 1247911328:
      gfx_color(188,238,104);
      break;
    case 4116677027:
      gfx_color(162,205,90);
      break;
    case 2009530889:
      gfx_color(110,139,61);
      break;
    case 2480869122:
      gfx_color(255,246,143);
      break;
    case 2666185277:
      gfx_color(238,230,133);
      break;
    case 2410051224:
      gfx_color(205,198,115);
      break;
    case 1817207133:
      gfx_color(139,134,78);
      break;
    case 1632458523:
      gfx_color(255,236,139);
      break;
    case 2028492752:
      gfx_color(238,220,130);
      break;
    case 3249755029:
      gfx_color(205,190,112);
      break;
    case 340253161:
      gfx_color(139,129,76);
      break;
    case 3437282338:
      gfx_color(255,255,224);
      break;
    case 3234029111:
      gfx_color(238,238,209);
      break;
    case 2873625484:
      gfx_color(205,205,180);
      break;
    case 1118195514:
      gfx_color(139,139,122);
      break;
    case 2741785792:
      gfx_color(255,255,0);
      break;
    case 4025166541:
      gfx_color(238,238,0);
      break;
    case 4067022249:
      gfx_color(205,205,0);
      break;
    case 3472666038:
      gfx_color(139,139,0);
      break;
    case 4029757942:
      gfx_color(255,215,0);
      break;
    case 379628468:
      gfx_color(238,201,0);
      break;
    case 3351040442:
      gfx_color(205,173,0);
      break;
    case 2596068076:
      gfx_color(139,117,0);
      break;
    case 1149266853:
      gfx_color(255,193,37);
      break;
    case 2639545811:
      gfx_color(238,180,34);
      break;
    case 1918623253:
      gfx_color(205,155,29);
      break;
    case 91451370:
      gfx_color(139,105,20);
      break;
    case 523727321:
      gfx_color(255,185,15);
      break;
    case 3889838587:
      gfx_color(238,173,14);
      break;
    case 2119433279:
      gfx_color(205,149,12);
      break;
    case 1644610883:
      gfx_color(139,101,8);
      break;
    case 3967564058:
      gfx_color(255,193,193);
      break;
    case 3377340157:
      gfx_color(238,180,180);
      break;
    case 2673693205:
      gfx_color(205,155,155);
      break;
    case 605310300:
      gfx_color(139,105,105);
      break;
    case 664068245:
      gfx_color(255,106,106);
      break;
    case 405405313:
      gfx_color(238,99,99);
      break;
    case 1757491075:
      gfx_color(205,85,85);
      break;
    case 2925376721:
      gfx_color(139,58,58);
      break;
    case 25179441:
      gfx_color(255,130,71);
      break;
    case 697797515:
      gfx_color(238,121,66);
      break;
    case 1095389262:
      gfx_color(205,104,57);
      break;
    case 2569855015:
      gfx_color(139,71,38);
      break;
    case 2814876979:
      gfx_color(255,211,155);
      break;
    case 4105111080:
      gfx_color(238,197,145);
      break;
    case 1881864665:
      gfx_color(205,170,125);
      break;
    case 2498320492:
      gfx_color(139,115,85);
      break;
    case 895198403:
      gfx_color(255,231,186);
      break;
    case 3166667931:
      gfx_color(238,216,174);
      break;
    case 3386667891:
      gfx_color(205,186,150);
      break;
    case 170205449:
      gfx_color(139,126,102);
      break;
    case 4154883099:
      gfx_color(255,165,79);
      break;
    case 443341449:
      gfx_color(238,154,73);
      break;
    case 3407741740:
      gfx_color(205,133,63);
      break;
    case 422749438:
      gfx_color(139,90,43);
      break;
    case 564815556:
      gfx_color(255,127,36);
      break;
    case 3118172147:
      gfx_color(238,118,33);
      break;
    case 2046235271:
      gfx_color(205,102,29);
      break;
    case 2578537869:
      gfx_color(139,69,19);
      break;
    case 3978834753:
      gfx_color(255,48,48);
      break;
    case 3264368301:
      gfx_color(238,44,44);
      break;
    case 2512443869:
      gfx_color(205,38,38);
      break;
    case 332519559:
      gfx_color(139,26,26);
      break;
    case 1160940954:
      gfx_color(255,64,64);
      break;
    case 3383015442:
      gfx_color(238,59,59);
      break;
    case 8898203:
      gfx_color(205,51,51);
      break;
    case 1437904377:
      gfx_color(139,35,35);
      break;
    case 3609429613:
      gfx_color(255,140,105);
      break;
    case 857368843:
      gfx_color(238,130,98);
      break;
    case 918259784:
      gfx_color(205,112,84);
      break;
    case 4077216419:
      gfx_color(139,76,57);
      break;
    case 1794430555:
      gfx_color(255,160,122);
      break;
    case 530491598:
      gfx_color(238,149,114);
      break;
    case 1413986959:
      gfx_color(205,129,98);
      break;
    case 3283495058:
      gfx_color(139,87,66);
      break;
    case 2161826076:
      gfx_color(255,165,0);
      break;
    case 3599794237:
      gfx_color(238,154,0);
      break;
    case 37810908:
      gfx_color(205,133,0);
      break;
    case 1050903491:
      gfx_color(139,90,0);
      break;
    case 634810244:
      gfx_color(255,127,0);
      break;
    case 2077441207:
      gfx_color(238,118,0);
      break;
    case 3125397756:
      gfx_color(205,102,0);
      break;
    case 1922755245:
      gfx_color(139,69,0);
      break;
    case 2888508953:
      gfx_color(255,114,86);
      break;
    case 1826388513:
      gfx_color(238,106,80);
      break;
    case 3676275176:
      gfx_color(205,91,69);
      break;
    case 4144360439:
      gfx_color(139,62,47);
      break;
    case 4262963913:
      gfx_color(255,99,71);
      break;
    case 3265533224:
      gfx_color(238,92,66);
      break;
    case 746762484:
      gfx_color(205,79,57);
      break;
    case 180384827:
      gfx_color(139,54,38);
      break;
    case 22684489:
      gfx_color(255,69,0);
      break;
    case 3910367374:
      gfx_color(238,64,0);
      break;
    case 1692548871:
      gfx_color(205,55,0);
      break;
    case 3432511303:
      gfx_color(139,37,0);
      break;
    case 249307724:
      gfx_color(255,0,0);
      break;
    case 3309118002:
      gfx_color(238,0,0);
      break;
    case 2255291815:
      gfx_color(205,0,0);
      break;
    case 322365706:
      gfx_color(139,0,0);
      break;
    case 2661617932:
      gfx_color(255,20,147);
      break;
    case 1874268357:
      gfx_color(238,18,137);
      break;
    case 3582165253:
      gfx_color(205,16,118);
      break;
    case 204261142:
      gfx_color(139,10,80);
      break;
    case 36517738:
      gfx_color(255,110,180);
      break;
    case 2169124460:
      gfx_color(238,106,167);
      break;
    case 449915870:
      gfx_color(205,96,144);
      break;
    case 394695536:
      gfx_color(139,58,98);
      break;
    case 3558084444:
      gfx_color(255,181,197);
      break;
    case 2740962530:
      gfx_color(238,169,184);
      break;
    case 3898439144:
      gfx_color(205,145,158);
      break;
    case 1956730746:
      gfx_color(139,99,108);
      break;
    case 3842610498:
      gfx_color(255,174,185);
      break;
    case 2387663868:
      gfx_color(238,162,173);
      break;
    case 2265730850:
      gfx_color(205,140,149);
      break;
    case 407964868:
      gfx_color(139,95,101);
      break;
    case 1646967235:
      gfx_color(255,130,171);
      break;
    case 1878272965:
      gfx_color(238,121,159);
      break;
    case 2535969463:
      gfx_color(205,104,137);
      break;
    case 4082332683:
      gfx_color(139,71,93);
      break;
    case 2208054212:
      gfx_color(255,52,179);
      break;
    case 1747351778:
      gfx_color(238,48,167);
      break;
    case 951191291:
      gfx_color(205,41,144);
      break;
    case 2971217247:
      gfx_color(139,28,98);
      break;
    case 500585469:
      gfx_color(255,62,150);
      break;
    case 4198249871:
      gfx_color(238,58,140);
      break;
    case 1935255043:
      gfx_color(205,50,120);
      break;
    case 261625477:
      gfx_color(139,34,82);
      break;
    case 1332210000:
      gfx_color(255,0,255);
      break;
    case 838790869:
      gfx_color(238,0,238);
      break;
    case 352561087:
      gfx_color(205,0,205);
      break;
    case 2177064647:
      gfx_color(139,0,139);
      break;
    case 2357494036:
      gfx_color(255,131,250);
      break;
    case 36788184:
      gfx_color(238,122,233);
      break;
    case 2863005159:
      gfx_color(205,105,201);
      break;
    case 16269112:
      gfx_color(139,71,137);
      break;
    case 1029518624:
      gfx_color(255,187,255);
      break;
    case 2187755271:
      gfx_color(238,174,238);
      break;
    case 1864707175:
      gfx_color(205,150,205);
      break;
    case 4149695260:
      gfx_color(139,102,139);
      break;
    case 1812866845:
      gfx_color(224,102,255);
      break;
    case 2700725218:
      gfx_color(209,95,238);
      break;
    case 2153529755:
      gfx_color(180,82,205);
      break;
    case 552628552:
      gfx_color(122,55,139);
      break;
    case 195733468:
      gfx_color(191,62,255);
      break;
    case 1164297590:
      gfx_color(178,58,238);
      break;
    case 1517249929:
      gfx_color(154,50,205);
      break;
    case 130616601:
      gfx_color(104,34,139);
      break;
    case 3964697437:
      gfx_color(155,48,255);
      break;
    case 3554312763:
      gfx_color(145,44,238);
      break;
    case 4161636143:
      gfx_color(125,38,205);
      break;
    case 2620371022:
      gfx_color(85,26,139);
      break;
    case 2117233981:
      gfx_color(171,130,255);
      break;
    case 1577197975:
      gfx_color(159,121,238);
      break;
    case 1031690073:
      gfx_color(137,104,205);
      break;
    case 2428702873:
      gfx_color(93,71,139);
      break;
    case 3762945583:
      gfx_color(255,225,255);
      break;
    case 1430666502:
      gfx_color(238,210,238);
      break;
    case 2555900365:
      gfx_color(205,181,205);
      break;
    case 1029107625:
      gfx_color(139,123,139);
      break;
    case 1964413183:
      gfx_color(0,0,0);
      break;
    case 720170899:
      gfx_color(0,0,0);
      break;
    case 3597762742:
      gfx_color(3,3,3);
      break;
    case 3205937369:
      gfx_color(3,3,3);
      break;
    case 3291135651:
      gfx_color(5,5,5);
      break;
    case 1809035981:
      gfx_color(5,5,5);
      break;
    case 2202336413:
      gfx_color(8,8,8);
      break;
    case 4131918048:
      gfx_color(8,8,8);
      break;
    case 4247475333:
      gfx_color(10,10,10);
      break;
    case 3313282024:
      gfx_color(10,10,10);
      break;
    case 774427806:
      gfx_color(13,13,13);
      break;
    case 70912924:
      gfx_color(13,13,13);
      break;
    case 1047003348:
      gfx_color(15,15,15);
      break;
    case 752918156:
      gfx_color(15,15,15);
      break;
    case 3159789675:
      gfx_color(18,18,18);
      break;
    case 1641426984:
      gfx_color(18,18,18);
      break;
    case 1066568737:
      gfx_color(20,20,20);
      break;
    case 104477235:
      gfx_color(20,20,20);
      break;
    case 3840384107:
      gfx_color(23,23,23);
      break;
    case 3276088503:
      gfx_color(23,23,23);
      break;
    case 2841566489:
      gfx_color(26,26,26);
      break;
    case 3410732273:
      gfx_color(26,26,26);
      break;
    case 2558816464:
      gfx_color(28,28,28);
      break;
    case 661432930:
      gfx_color(28,28,28);
      break;
    case 2794389341:
      gfx_color(31,31,31);
      break;
    case 12021451:
      gfx_color(31,31,31);
      break;
    case 4053570153:
      gfx_color(33,33,33);
      break;
    case 55246189:
      gfx_color(33,33,33);
      break;
    case 2999122973:
      gfx_color(36,36,36);
      break;
    case 3583223067:
      gfx_color(36,36,36);
      break;
    case 2737037626:
      gfx_color(38,38,38);
      break;
    case 3554241773:
      gfx_color(38,38,38);
      break;
    case 3241797591:
      gfx_color(41,41,41);
      break;
    case 2777971059:
      gfx_color(41,41,41);
      break;
    case 2949058655:
      gfx_color(43,43,43);
      break;
    case 1231856578:
      gfx_color(43,43,43);
      break;
    case 315010680:
      gfx_color(46,46,46);
      break;
    case 1187824932:
      gfx_color(46,46,46);
      break;
    case 2581292312:
      gfx_color(48,48,48);
      break;
    case 837612344:
      gfx_color(48,48,48);
      break;
    case 3762238966:
      gfx_color(51,51,51);
      break;
    case 1876201305:
      gfx_color(51,51,51);
      break;
    case 615950026:
      gfx_color(54,54,54);
      break;
    case 628194789:
      gfx_color(54,54,54);
      break;
    case 2964561298:
      gfx_color(56,56,56);
      break;
    case 3010893212:
      gfx_color(56,56,56);
      break;
    case 749305719:
      gfx_color(59,59,59);
      break;
    case 1450620846:
      gfx_color(59,59,59);
      break;
    case 3919460080:
      gfx_color(61,61,61);
      break;
    case 1504728267:
      gfx_color(61,61,61);
      break;
    case 45628466:
      gfx_color(64,64,64);
      break;
    case 2549455488:
      gfx_color(64,64,64);
      break;
    case 2307591850:
      gfx_color(66,66,66);
      break;
    case 2839579610:
      gfx_color(66,66,66);
      break;
    case 2559806428:
      gfx_color(69,69,69);
      break;
    case 1043909571:
      gfx_color(69,69,69);
      break;
    case 87993905:
      gfx_color(71,71,71);
      break;
    case 901049725:
      gfx_color(71,71,71);
      break;
    case 142444140:
      gfx_color(74,74,74);
      break;
    case 151744167:
      gfx_color(74,74,74);
      break;
    case 1479113376:
      gfx_color(77,77,77);
      break;
    case 1637822770:
      gfx_color(77,77,77);
      break;
    case 2005202871:
      gfx_color(79,79,79);
      break;
    case 1490275786:
      gfx_color(79,79,79);
      break;
    case 914022383:
      gfx_color(82,82,82);
      break;
    case 4054142730:
      gfx_color(82,82,82);
      break;
    case 3398406415:
      gfx_color(84,84,84);
      break;
    case 4051717328:
      gfx_color(84,84,84);
      break;
    case 797827442:
      gfx_color(87,87,87);
      break;
    case 674828904:
      gfx_color(87,87,87);
      break;
    case 2960944950:
      gfx_color(89,89,89);
      break;
    case 3876719001:
      gfx_color(89,89,89);
      break;
    case 3636421079:
      gfx_color(92,92,92);
      break;
    case 3554954829:
      gfx_color(92,92,92);
      break;
    case 617077384:
      gfx_color(94,94,94);
      break;
    case 601688976:
      gfx_color(94,94,94);
      break;
    case 1587795483:
      gfx_color(97,97,97);
      break;
    case 4275134947:
      gfx_color(97,97,97);
      break;
    case 4148304396:
      gfx_color(99,99,99);
      break;
    case 531202593:
      gfx_color(99,99,99);
      break;
    case 973997732:
      gfx_color(102,102,102);
      break;
    case 3612489663:
      gfx_color(102,102,102);
      break;
    case 3684745981:
      gfx_color(105,105,105);
      break;
    case 52151670:
      gfx_color(105,105,105);
      break;
    case 2110765990:
      gfx_color(107,107,107);
      break;
    case 1702417062:
      gfx_color(107,107,107);
      break;
    case 2995833962:
      gfx_color(110,110,110);
      break;
    case 1665881999:
      gfx_color(110,110,110);
      break;
    case 1260126302:
      gfx_color(112,112,112);
      break;
    case 26558260:
      gfx_color(112,112,112);
      break;
    case 4201607247:
      gfx_color(115,115,115);
      break;
    case 1525453911:
      gfx_color(115,115,115);
      break;
    case 3274866912:
      gfx_color(117,117,117);
      break;
    case 1953977057:
      gfx_color(117,117,117);
      break;
    case 4042418747:
      gfx_color(120,120,120);
      break;
    case 2475698946:
      gfx_color(120,120,120);
      break;
    case 4166508442:
      gfx_color(122,122,122);
      break;
    case 1925065865:
      gfx_color(122,122,122);
      break;
    case 3193479978:
      gfx_color(125,125,125);
      break;
    case 866751330:
      gfx_color(125,125,125);
      break;
    case 2746398309:
      gfx_color(127,127,127);
      break;
    case 1295361420:
      gfx_color(127,127,127);
      break;
    case 1332804627:
      gfx_color(130,130,130);
      break;
    case 3459795231:
      gfx_color(130,130,130);
      break;
    case 1975277646:
      gfx_color(133,133,133);
      break;
    case 1940554303:
      gfx_color(133,133,133);
      break;
    case 3098119143:
      gfx_color(135,135,135);
      break;
    case 3437808954:
      gfx_color(135,135,135);
      break;
    case 2727451825:
      gfx_color(138,138,138);
      break;
    case 2924478195:
      gfx_color(138,138,138);
      break;
    case 452743872:
      gfx_color(140,140,140);
      break;
    case 1968707384:
      gfx_color(140,140,140);
      break;
    case 3547811784:
      gfx_color(143,143,143);
      break;
    case 2703466112:
      gfx_color(143,143,143);
      break;
    case 871350615:
      gfx_color(145,145,145);
      break;
    case 2408307598:
      gfx_color(145,145,145);
      break;
    case 8647603:
      gfx_color(148,148,148);
      break;
    case 3356622528:
      gfx_color(148,148,148);
      break;
    case 4045650673:
      gfx_color(150,150,150);
      break;
    case 3933531449:
      gfx_color(150,150,150);
      break;
    case 462514179:
      gfx_color(153,153,153);
      break;
    case 3782817876:
      gfx_color(153,153,153);
      break;
    case 480667992:
      gfx_color(156,156,156);
      break;
    case 1959589678:
      gfx_color(156,156,156);
      break;
    case 680445108:
      gfx_color(158,158,158);
      break;
    case 3848861686:
      gfx_color(158,158,158);
      break;
    case 2452215026:
      gfx_color(161,161,161);
      break;
    case 4128004980:
      gfx_color(161,161,161);
      break;
    case 921502821:
      gfx_color(163,163,163);
      break;
    case 1663800297:
      gfx_color(163,163,163);
      break;
    case 9399366:
      gfx_color(166,166,166);
      break;
    case 162780221:
      gfx_color(166,166,166);
      break;
    case 1504608353:
      gfx_color(168,168,168);
      break;
    case 1509409448:
      gfx_color(168,168,168);
      break;
    case 1212299203:
      gfx_color(171,171,171);
      break;
    case 567687865:
      gfx_color(171,171,171);
      break;
    case 1645334391:
      gfx_color(173,173,173);
      break;
    case 1072799482:
      gfx_color(173,173,173);
      break;
    case 2068623354:
      gfx_color(176,176,176);
      break;
    case 389153802:
      gfx_color(176,176,176);
      break;
    case 155528936:
      gfx_color(179,179,179);
      break;
    case 3681393305:
      gfx_color(179,179,179);
      break;
    case 1877865913:
      gfx_color(181,181,181);
      break;
    case 1721009527:
      gfx_color(181,181,181);
      break;
    case 510535755:
      gfx_color(184,184,184);
      break;
    case 851887861:
      gfx_color(184,184,184);
      break;
    case 4292636914:
      gfx_color(186,186,186);
      break;
    case 652144697:
      gfx_color(186,186,186);
      break;
    case 512922551:
      gfx_color(189,189,189);
      break;
    case 1084735410:
      gfx_color(189,189,189);
      break;
    case 4065505189:
      gfx_color(191,191,191);
      break;
    case 3509553226:
      gfx_color(191,191,191);
      break;
    case 3992071699:
      gfx_color(194,194,194);
      break;
    case 180057243:
      gfx_color(194,194,194);
      break;
    case 2405284921:
      gfx_color(196,196,196);
      break;
    case 3908136760:
      gfx_color(196,196,196);
      break;
    case 4098770644:
      gfx_color(199,199,199);
      break;
    case 3867295173:
      gfx_color(199,199,199);
      break;
    case 194326491:
      gfx_color(201,201,201);
      break;
    case 14319351:
      gfx_color(201,201,201);
      break;
    case 1690751933:
      gfx_color(204,204,204);
      break;
    case 3095051871:
      gfx_color(204,204,204);
      break;
    case 1535114147:
      gfx_color(207,207,207);
      break;
    case 4207243339:
      gfx_color(207,207,207);
      break;
    case 810628802:
      gfx_color(209,209,209);
      break;
    case 218942063:
      gfx_color(209,209,209);
      break;
    case 3404561392:
      gfx_color(212,212,212);
      break;
    case 1586048480:
      gfx_color(212,212,212);
      break;
    case 1054817686:
      gfx_color(214,214,214);
      break;
    case 1614476476:
      gfx_color(214,214,214);
      break;
    case 2845490123:
      gfx_color(217,217,217);
      break;
    case 3693012877:
      gfx_color(217,217,217);
      break;
    case 274883067:
      gfx_color(219,219,219);
      break;
    case 2852638117:
      gfx_color(219,219,219);
      break;
    case 934032197:
      gfx_color(222,222,222);
      break;
    case 1745005465:
      gfx_color(222,222,222);
      break;
    case 2327084442:
      gfx_color(224,224,224);
      break;
    case 1811119171:
      gfx_color(224,224,224);
      break;
    case 2335703455:
      gfx_color(227,227,227);
      break;
    case 1930407132:
      gfx_color(227,227,227);
      break;
    case 1928840944:
      gfx_color(229,229,229);
      break;
    case 2242864700:
      gfx_color(229,229,229);
      break;
    case 1022733688:
      gfx_color(232,232,232);
      break;
    case 2981648681:
      gfx_color(232,232,232);
      break;
    case 2447150491:
      gfx_color(235,235,235);
      break;
    case 2297623795:
      gfx_color(235,235,235);
      break;
    case 781160916:
      gfx_color(237,237,237);
      break;
    case 1141900881:
      gfx_color(237,237,237);
      break;
    case 885622559:
      gfx_color(240,240,240);
      break;
    case 215226115:
      gfx_color(240,240,240);
      break;
    case 1577144973:
      gfx_color(242,242,242);
      break;
    case 1444042706:
      gfx_color(242,242,242);
      break;
    case 820874211:
      gfx_color(245,245,245);
      break;
    case 3772499684:
      gfx_color(245,245,245);
      break;
    case 320879021:
      gfx_color(247,247,247);
      break;
    case 3895366081:
      gfx_color(247,247,247);
      break;
    case 283958231:
      gfx_color(250,250,250);
      break;
    case 3651674038:
      gfx_color(250,250,250);
      break;
    case 1755161625:
      gfx_color(252,252,252);
      break;
    case 909469456:
      gfx_color(252,252,252);
      break;
    case 594564876:
      gfx_color(255,255,255);
      break;
    case 2314534225:
      gfx_color(255,255,255);
      break;
    case 2958544604:
      gfx_color(169,169,169);
      break;
    case 151103004:
      gfx_color(169,169,169);
      break;
    case 19679280:
      gfx_color(0,0,139);
      break;
    case 2581859936:
      gfx_color(0,139,139);
      break;
    case 875870020:
      gfx_color(139,0,139);
      break;
    case 2460347870:
      gfx_color(139,0,0);
      break;
    case 283465915:
      gfx_color(144,238,144);
      break;
    default:
    	fprintf(stderr,"Color '%s' undefined!\n",colorname);
    	break;
  }
}

/*  Paul Hsieh's code for hash function
		http://www.azillionmonkeys.com/qed/hash.html
 */

#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
  || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
#define get16bits(d) (*((const uint16_t *) (d)))
#endif

#if !defined (get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
                       +(uint32_t)(((const uint8_t *)(d))[0]) )
#endif

uint32_t SuperFastHash (const char * data, int len) {
uint32_t hash = len, tmp;
int rem;

    if (len <= 0 || data == NULL) return 0;

    rem = len & 3;
    len >>= 2;

    /* Main loop */
    for (;len > 0; len--) {
        hash  += get16bits (data);
        tmp    = (get16bits (data+2) << 11) ^ hash;
        hash   = (hash << 16) ^ tmp;
        data  += 2*sizeof (uint16_t);
        hash  += hash >> 11;
    }

    /* Handle end cases */
    switch (rem) {
        case 3: hash += get16bits (data);
                hash ^= hash << 16;
                hash ^= ((signed char)data[sizeof (uint16_t)]) << 18;
                hash += hash >> 11;
                break;
        case 2: hash += get16bits (data);
                hash ^= hash << 11;
                hash += hash >> 17;
                break;
        case 1: hash += (signed char)*data;
                hash ^= hash << 10;
                hash += hash >> 1;
    }

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;

    return hash;
}
