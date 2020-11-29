// stdafx.cpp : source file that includes just the standard includes
//	MicroClient.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include "StrategySystem.h"

//把接收到的队员的坐标和角度放入r[0][i]里面，对方队员的坐标
//放入op里面
//取每个队员的轮速，在Velocity函数计算里面已经获得了三
//个队员的轮速
int nKick;
CStrategySystem* thePlannerR=new CStrategySystem(0);
CStrategySystem* thePlannerL=new CStrategySystem(1);
Robot2 r[2][11];
Robot3 op;//存放对方队员的坐标数据
Robot1 theball;//存放球的坐标数据.