#include "StdAfx.h"
#include "StrategySystem.h"

IMPLEMENT_DYNAMIC(CStrategySystem, CObject)

extern int nKick;
#define  BALL_WIDTH		78
#define  BALL_LENGTH	156 
#define  BALL_DIS	    26 
#define  CORNER         115

CStrategySystem::CStrategySystem(int id)
{
	m_OurTeam=id;
	boundRect.SetRect(65,95,965,723);
	if(id)
		m_nGameArea=GAME_LEFT;
	else
		m_nGameArea=GAME_RIGHT;
	for(int i=0;i<35;i++)
		command[i]=0;
	C_Home1.Data.Lv=0;
	C_Home1.Data.Rv=0;
	C_Home1.Data.Command=C_STOP;
	C_Home2.Data.Lv=0;
	C_Home2.Data.Rv=0;
	C_Home2.Data.Command=C_STOP;
	C_Home3.Data.Lv=0;
	C_Home3.Data.Rv=0;
	C_Home3.Data.Command=C_STOP;
	C_Home4.Data.Lv=0;
	C_Home4.Data.Rv=0;
	C_Home4.Data.Command=C_STOP;
	C_Home5.Data.Lv=0;
	C_Home5.Data.Rv=0;
	C_Home5.Data.Command=C_STOP;
	C_Home6.Data.Lv=0;
	C_Home6.Data.Rv=0;
	C_Home6.Data.Command=C_STOP;
	C_Home7.Data.Lv=0;
	C_Home7.Data.Rv=0;
	C_Home7.Data.Command=C_STOP;
	C_Home8.Data.Lv=0;
	C_Home8.Data.Rv=0;
	C_Home8.Data.Command=C_STOP;
	C_Home9.Data.Lv=0;
	C_Home9.Data.Rv=0;
	C_Home9.Data.Command=C_STOP;
	C_Home10.Data.Lv=0;
	C_Home10.Data.Rv=0;
	C_Home10.Data.Command=C_STOP;
	C_Home11.Data.Lv=0;
	C_Home11.Data.Rv=0;
	C_Home11.Data.Command=C_STOP;

	m_nStrategy=id;//left=1,right=0
	nKick=0;
	nKick2=0;
	nShoot=0;
	nSweep=0;
}



CStrategySystem::~CStrategySystem()
{

}

void CStrategySystem::Action()
{
	//Position(HOME1,CPoint(700,500));
	//Position(2,CPoint(600,200));
	//Position(3,CPoint(700,300));
	//Position(4,CPoint(200,200));
	//Position(5,CPoint(800,500));
	//Position(6,CPoint(300,300));
	//Position(7,CPoint(100,100));
	//Position(8,CPoint(600,600));
	//Think();
}

void CStrategySystem::Think()
{

	switch(m_nStrategy)
	{
	case 0:
		NormalGame();
		break;
	case 1:
		NormalGame();
		break;
	}
}


void CStrategySystem::NormalGame()
{
	
	Position(HOME1,CPoint(ball.position.x,ball.position.y));
	Position(HOME2,CPoint(ball.position.x,ball.position.y));
	Velocity(HOME3,20,-10);
	Velocity(HOME4,20,-10);
	Velocity(HOME5,20,-10);
	Velocity(HOME6,-20,10);
	Velocity(HOME7,-20,10);
	Velocity(HOME8,-20,10);
	Velocity(HOME9,-20,10);
	Velocity(HOME10,-20,10);
	Goalie(HGOALIE);

}

void CStrategySystem::NormalGame1()
{

}

void CStrategySystem::NormalGame2()
{

}

void CStrategySystem::NormalGame3()
{

}

void CStrategySystem::NormalGame4()
{
	
}

void CStrategySystem::NormalGame5()
{
	Velocity(HOME1,20,-10);
	Velocity(HOME2,20,-10);
	Velocity(HOME3,20,-10);
	Velocity(HOME4,20,-10);
	Velocity(HOME5,20,-10);
	Velocity(HOME6,-20,10);
	Velocity(HOME7,-20,10);
	Velocity(HOME8,-20,10);
	Velocity(HOME9,-20,10);
	Velocity(HOME10,-20,10);
	Velocity(HGOALIE,-20,10);


}


void CStrategySystem::Angle(int which, int desired_angle)
{
	Robot2 *robot;
	int theta_e, vL, vR; 
	
	switch(which){
	case HOME1:	
		robot = &home1;
		break;
	case HOME2:            
		robot = &home2;
		break;
	case HOME3:	
		robot = &home3;
		break;
	case HOME4:	
		robot = &home4;
		break;
	case HOME5:	
		robot = &home5;
		break;
	case HOME6:	
		robot = &home6;
		break;
	case HOME7:	
		robot = &home7;
		break;
	case HOME8:	
		robot = &home8;
		break;
	case HOME9:	
		robot = &home9;
		break;
	case HOME10:	
		robot = &home10;
		break;
	case HGOALIE:      
		robot = &hgoalie;
		break;
	}

	theta_e = desired_angle - robot->angle;
	while(theta_e > 180)
		theta_e -= 360;
	while(theta_e < -180)
		theta_e += 360;                                      
	if(theta_e < -90)  
		theta_e += 180; 
	else if(theta_e > 90)  
		theta_e -= 180;		
	vL = (int)(60.0/90.0*theta_e);  
	vR = (int)(-60.0/90.0*theta_e);
	Velocity(which, vL, vR);
}

void CStrategySystem::Velocity(int which, int vL, int vR)
{
	if(vL < -127)	vL = -127;
	if(vL > 127)	vL = 127;

	if(vR < -127)	vR = -127;
	if(vR > 127)	vR = 127;

	switch(which){
	case HOME1:
		command[2] = vL;
		command[3] = vR;
		command[4] = C_GO;
		break;
	case HOME2:           
		command[5] = vL;
		command[6] = vR;
		command[7] = C_GO;	
		break;
	case HOME3:           
		command[8] = vL;
		command[9] = vR;
		command[10] = C_GO;	
		break;
	case HOME4:           
		command[11] = vL;
		command[12] = vR;
		command[13] = C_GO;	
		break;
	case HOME5:           
		command[14] = vL;
		command[15] = vR;
		command[16] = C_GO;	
		break;
	case HOME6:           
		command[17] = vL;
		command[18] = vR;
		command[19] = C_GO;	
		break;
	case HOME7:           
		command[20] = vL;
		command[21] = vR;
		command[22] = C_GO;	
		break;
	case HOME8:           
		command[23] = vL;
		command[24] = vR;
		command[25] = C_GO;	
		break;
	case HOME9:           
		command[26] = vL;
		command[27] = vR;
		command[28] = C_GO;	
		break;
	case HOME10:           
		command[29] = vL;
		command[30] = vR;
		command[31] = C_GO;	
		break;
	case HGOALIE:         
		command[32] = vL;
		command[33] = vR;
		command[34] = C_GO;	
		break;
	}
}


void CStrategySystem::Position(int which, CPoint point)
{
	Robot2 *robot;    
	double distance_e;                 
	int dx, dy, desired_angle, theta_e, vL, vR;
	
	switch(which){
	case HOME1:	
		robot = &home1;
		break;
	case HOME2:            
		robot = &home2;
		break;
	case HOME3:	
		robot = &home3;
		break;
	case HOME4:	
		robot = &home4;
		break;
	case HOME5:	
		robot = &home5;
		break;
	case HOME6:	
		robot = &home6;
		break;
	case HOME7:	
		robot = &home7;
		break;
	case HOME8:	
		robot = &home8;
		break;
	case HOME9:	
		robot = &home9;
		break;
	case HOME10:	
		robot = &home10;
		break;
	case HGOALIE:      
		robot = &hgoalie;
		break;
	}
        
	dx = point.x - robot->position.x;
	dy = point.y - robot->position.y;
	                                            
	distance_e = sqrt(1.0*dx*dx+1.0*dy*dy);	                                            

    if(dx == 0 && dy == 0)
		desired_angle = 90;
	else
		desired_angle = (int)(180.0/M_PI*atan2((double)(dy), (double)(dx)));
	
	theta_e = desired_angle - robot->angle;

	while(theta_e > 180)
		theta_e -= 360;
	while(theta_e < -180)
		theta_e += 360;                                      

	if(theta_e < -90){  
		theta_e += 180; 
		distance_e = -distance_e;		
	}
	else if(theta_e > 90){  
		theta_e -= 180;		
		distance_e = -distance_e;
	}

	vL = (int)(5.*(100.0/1000.0*distance_e+40.0/90.0*theta_e));
	vR = (int)(5.*(100.0/1000.0*distance_e-40.0/90.0*theta_e));

	Velocity(which, vL, vR);  
}

#define ANGLE_BOUND 60
#define BOUND_BOUND 12
#define G_OFFSET		20
#define G_ANGLE_BOUND	60
#define G_BOUND_BOUND	10


void CStrategySystem::ReceiveData(Robot1 bal,Robot2 ho1,Robot2 ho2,Robot2 ho3,Robot2 ho4,
		             Robot2 ho5,Robot2 ho6,Robot2 ho7,Robot2 ho8,Robot2 ho9,
					 Robot2 ho10,Robot2 hgo,Robot3 opp)
{
	if(m_nGameArea==GAME_RIGHT)
	{
		ball.position=bal.position;   
		//추가
		//ball.oldPosition=bal.oldPosition;
		
		home1.position=ho1.position;      
		home1.angle=ho1.angle;
		
		home2.position=ho2.position;       
		home2.angle=ho2.angle;
		
		home3.position=ho3.position;
		home3.angle=ho3.angle;

		home4.position=ho4.position;
		home4.angle=ho4.angle;

		home5.position=ho5.position;
		home5.angle=ho5.angle;

		home6.position=ho6.position;
		home6.angle=ho6.angle;

		home7.position=ho7.position;
		home7.angle=ho7.angle;

		home8.position=ho8.position;
		home8.angle=ho8.angle;

		home9.position=ho9.position;
		home9.angle=ho9.angle;

		home10.position=ho10.position;
		home10.angle=ho10.angle;

		hgoalie.position=hgo.position;    
		hgoalie.angle=hgo.angle;
		
		opponent.position1=opp.position1;   
		opponent.position2=opp.position2;
		opponent.position3=opp.position3;
		opponent.position4=opp.position4;
		opponent.position5=opp.position5;
		opponent.position6=opp.position6;
		opponent.position7=opp.position7;
		opponent.position8=opp.position8;
		opponent.position9=opp.position9;
		opponent.position10=opp.position10;
		opponent.position11=opp.position11;
	
	}
	else  
	{
		
		ball.position.x=1030-bal.position.x;
		ball.position.y=818-bal.position.y;
	
		//추가

		//ball.oldPosition.x = 1270-bal.oldPosition.x;
		//ball.oldPosition.y = 1127-bal.oldPosition.y;

		home1.position.x=1030-ho1.position.x;
		home1.position.y=818-ho1.position.y;
		if(home1.angle>0)
			home1.angle=ho1.angle-180;
		else
			home1.angle   =180+ho1.angle;
		home2.position.x=1030-ho2.position.x;
		home2.position.y=818-ho2.position.y;
		if(home2.angle>0)
			home2.angle=ho2.angle-180;
		else
			home2.angle=180+ho2.angle;
		home3.position.x=1030-ho3.position.x;
		home3.position.y=818-ho3.position.y;
		if(home3.angle>0)
			home3.angle=ho3.angle-180;
		else
			home3.angle=180+ho3.angle;
		home4.position.x=1030-ho4.position.x;
		home4.position.y=818-ho4.position.y;
		if(home4.angle>0)
			home4.angle=ho4.angle-180;
		else
			home4.angle=180+ho4.angle;
		home5.position.x=1030-ho5.position.x;
		home5.position.y=818-ho5.position.y;
		if(home5.angle>0)
			home5.angle=ho5.angle-180;
		else
			home5.angle   =180+ho5.angle;
		//*/
		home6.position.x=1030-ho6.position.x;
		home6.position.y=818-ho6.position.y;
		///*
		if(home6.angle>0)
			home6.angle=ho6.angle-180;
		else
			home6.angle   =180+ho6.angle;
		//*/
		home7.position.x=1030-ho7.position.x;
		home7.position.y=818-ho7.position.y;
		///*
		if(home7.angle>0)
			home7.angle=ho7.angle-180;
		else
			home7.angle   =180+ho7.angle;
		//*/
		home8.position.x=1030-ho8.position.x;
		home8.position.y=818-ho8.position.y;
		///*
		if(home8.angle>0)
			home8.angle=ho8.angle-180;
		else
			home8.angle   =180+ho8.angle;
		//*/
		home9.position.x=1030-ho9.position.x;
		home9.position.y=818-ho9.position.y;
		///*
		if(home9.angle>0)
			home9.angle=ho9.angle-180;
		else
			home9.angle   =180+ho9.angle;
		//*/
		home10.position.x=1030-ho10.position.x;
		home10.position.y=818-ho10.position.y;
		///*
		if(home10.angle>0)
			home10.angle=ho10.angle-180;
		else
			home10.angle   =180+ho10.angle;
		//*/
		hgoalie.position.x=1030-hgo.position.x;
		hgoalie.position.y=818-hgo.position.y;
		///*
		if(hgoalie.angle>0)
			hgoalie.angle=hgo.angle-180;
		else
			hgoalie.angle=180+hgo.angle;
		//*/
		opponent.position1.x=1030-opp.position1.x;
		opponent.position2.x=1030-opp.position2.x;
		opponent.position3.x=1030-opp.position3.x;
		opponent.position4.x=1030-opp.position4.x;
		opponent.position5.x=1030-opp.position5.x;
		opponent.position6.x=1030-opp.position6.x;
		opponent.position7.x=1030-opp.position7.x;
		opponent.position8.x=1030-opp.position8.x;
		opponent.position9.x=1030-opp.position9.x;
		opponent.position10.x=1030-opp.position10.x;
		opponent.position11.x=1030-opp.position11.x;

		opponent.position1.y=818-opp.position1.y;
		opponent.position2.y=818-opp.position2.y;
		opponent.position3.y=818-opp.position3.y;
		opponent.position4.y=818-opp.position4.y;
		opponent.position5.y=818-opp.position5.y;
		opponent.position6.y=818-opp.position6.y;
		opponent.position7.y=818-opp.position7.y;
		opponent.position8.y=818-opp.position8.y;
		opponent.position9.y=818-opp.position9.y;
		opponent.position10.y=818-opp.position10.y;
		opponent.position11.y=818-opp.position11.y;
	
	}
}

void CStrategySystem::Stop(int which)
{
	int vL,vR;
	vL=vR=0;
	Velocity(which,vL,vR);
}


void CStrategySystem::Goalie(int which)
{
	Robot2 *robot;
	CPoint target; 
	int dx, dy;
	
	switch(which){
	case HOME1:	
		robot = &home1;
		break;
	case HOME2:            
		robot = &home2;
		break;
	case HOME3:	
		robot = &home3;
		break;
	case HOME4:	
		robot = &home4;
		break;
	case HGOALIE:      
		robot = &hgoalie;
		break;
	}

	target.y = ball.position.y;
	target.x = boundRect.right - 10;

	if(target.y < boundRect.top + (boundRect.bottom-boundRect.top)/3)
	{
		target.y = boundRect.top + (boundRect.bottom-boundRect.top)/3;
	}
	else if(target.y > boundRect.bottom - (boundRect.bottom-boundRect.top)/3)
	{
		target.y = boundRect.bottom - (boundRect.bottom-boundRect.top)/3;
	}

	dx = robot->position.x - target.x ;
	dy = robot->position.y - target.y; 

	if(dx*dx+dy*dy > 10)  
		//Position(which, CPoint(target.x,target.y));
		Position(which,CPoint(500,300));
	else 
		Angle(which, 90);
}
