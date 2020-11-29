/////////////////////////////////////////////////////////////////
#define BORDERNUM					18
/////////////////////////////////////////////////////////////////
#define HIT_LEFTGOAL				0
#define HIT_RIGHTGOAL				1
#define HIT_UPBORDER				2
#define HIT_DOWNBORDER				3
#define HIT_LEFT_GOAL_UPBORDER		4
#define HIT_LEFT_GOAL_DOWNBORDER	5
#define HIT_RIGHT_GOAL_UPBORDER		6
#define HIT_RIGHT_GOAL_DOWNBORDER	7
#define HIT_LEFT_UPBORDER			8
#define HIT_LEFT_DOWNBORDER			9
#define HIT_RIGHT_UPBORDER			10
#define HIT_RIGHT_DOWNBORDER		11
#define HIT_LEFT_GOALBORDER			12
#define HIT_RIGHT_GOALBORDER		13
#define HIT_LEFTUPCORNER			14
#define HIT_LEFTDOWNCORNER			15
#define HIT_RIGHTDOWNCORNER			16
#define HIT_RIGHTUPCORNER			17
#define HIT_YH1						18
#define HIT_YH2						19
#define HIT_YHG						20
#define HIT_BH1						21
#define HIT_BH2						22
#define HIT_BHG						23
#define HIT_BALL					24	
/////////////////////////////////////////////////////////////////
#define FRONT						0
#define RIGHT						1
#define BACK						2
#define LEFT						3
///////////////////////////////////////////////////////////////////
#define BALL	0
#define HOME1	1
#define HOME2	2
#define HOME3   3
#define HOME4	4
#define HOME5	5
#define HOME6	6
#define HOME7	7
#define HOME8	8
#define HOME9	9
#define HOME10	10
#define HGOALIE 11
#define C_GO	0xaa
#define C_STOP	0x55
#define G_OFFSET      20//15         
#define G_ANGLE_BOUND 60
#define G_BOUND_BOUND 10   
///////////////////////////////////////////////////////////////////
//ËùÔÚ°ë³¡
#define GAME_RIGHT		0
#define GAME_LEFT		1
////////////////////////////////////////////////////////////////////

#define PI 3.14
#define M_PI PI
#define square(a) ((a)*(a))
#define leng(a,b,c,d) sqrt(square((a)-(c))+square((b)-(d)))
#define pleng(a,b) sqrt(square((a.x)-(b.x))+square((a.y)-(b.y)))
//////////////////////////////////////////
#define Atan(y,x) ((x == 0.0 && y == 0.0) ? (0.0) : atan2(y,x))
#define RAD2DEG (180.0/PI)
#define DEG2RAD (PI/180.0)
#define Rad2Deg(a) ((double)a * RAD2DEG)
#define Deg2Rad(a) ((double)a * DED2RAD)
#define ABS(a) ((a)<0 ? -(a) : (a))
/////////////////////////////////////////////////////////////
union CCommand{
	BYTE Stream[3];
	struct tagData{
		char Lv;
		char Rv;
		char Command;
	}Data;
	CCommand& operator =(CCommand& r)
	{
		Data.Lv=r.Data.Lv;
		Data.Rv=r.Data.Rv;
		Data.Command=r.Data.Command;
		return *this;
	}
};

struct Robot1{
	int angle;
	int sAngle;
	CPoint angleRef;
	CPoint sAngleRef;
	CPoint position, oldPosition;
	CPoint sPosition, sOldPosition;
	int nMethod;
	BYTE color[6];
	BOOL bAlive; 

	Robot1(){};
	BOOL find(){return TRUE;};
	BOOL entireFind(){return TRUE;};
	BOOL entireFind(BYTE *lpY, BYTE *lpU, BYTE *lpV){return TRUE;};
};

struct Robot2{
	int angle;             
	int sAngle;
	CPoint position, oldPosition;
	CPoint sPosition, sOldPosition;
	CPoint pos, oldPos, pos1, oldPos1;
	int nMethod;
	BYTE color[6];
	BOOL bAlive; 
	BYTE teamColor[6];

	Robot2(){};
	BOOL find(){return TRUE;};
	BOOL entireFind(){return TRUE;};
	BOOL entireFind(BYTE *lpY, BYTE *lpU, BYTE *lpV){return TRUE;};
};                                            

struct Robot3{
	CPoint position1, oldPosition1;
	CPoint sPosition1, sOldPosition1;	
	CPoint position2, oldPosition2;
	CPoint sPosition2, sOldPosition2;
	CPoint position3, oldPosition3;
	CPoint position4, oldPosition4;
	CPoint position5, oldPosition5;
	CPoint sPosition3, sOldPosition3;
	CPoint position6, oldPosition6;
	CPoint position7, oldPosition7;
	CPoint position8, oldPosition8;
	CPoint position9, oldPosition9;
	CPoint position10, oldPosition10;
	CPoint position11, oldPosition11;
	int nMethod;
	BYTE color[6];
	BOOL bAlive;

	Robot3(){};
	BOOL find1(){return TRUE;}
	BOOL find2(){return TRUE;}
	BOOL find3(){return TRUE;}	  
	BOOL entireFind(){return TRUE;}
	BOOL entireFind(BYTE *lpY, BYTE *lpU, BYTE *lpV){return TRUE;}
};
