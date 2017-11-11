#include "Tab.h"


Tab::Tab(void)
{
		comm_00[0]="G04";
		comm_00[1]="G27";
		comm_00[2]="G28";
		comm_00[3]="G29";
		comm_00[4]="G36";
		comm_00[5]="G37";
		comm_00[6]="G70";
		comm_00[7]="G71";
		comm_00[8]="G72";
		comm_00[9]="G73";
		comm_00[10]="G74";
		comm_00[11]="G75";
		comm_00[12]="G76";
		comm_00[13]="G50";
		comm_01[0]="G00";//x,y,f
		comm_01[1]="G01";//x, y,f
		comm_01[2]="G02";
		comm_01[3]="G03";
		comm_01[4]="G33";
		comm_01[5]="G34";
		comm_01[6]="G90";
		comm_01[7]="G91";
		comm_01[8]="G92";
		comm_01[9]="G94";
		comm_02[0]="G17";//x,y por defecto
		comm_02[1]="G18";//x,z
		comm_02[2]="G19"; //y,z
		comm_02[3]="G96";
		comm_02[4]="G97";
		comm_04[0]="G22";
		comm_04[1]="G23";
		comm_05[0]="G20";
		comm_05[1]="G21";
		comm_05[2]="G98";
		comm_05[3]="G99";
		comm_07[0]="G40";//desactiva compensacion de radio
		comm_07[1]="G41";// compensacion de radio de hta a izquierda
		comm_07[2]="G42";//"" "" derecha
		comm_08[0]="G25";
		comm_08[1]="G26";
		comm_09[0]="G80";
		comm_09[1]="G81";
		comm_09[2]="G82";
		comm_09[3]="G83";
		comm_09[4]="G84";
		comm_09[5]="G85";
		comm_09[6]="G86";
		comm_12[0]="G54";
		comm_12[1]="G55";
}


Tab::~Tab(void)
{
}
