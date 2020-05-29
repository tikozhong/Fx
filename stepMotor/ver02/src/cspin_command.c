/******************** (C) COPYRIGHT 2015 INCUBECN *****************************
* File Name          : cspin_command.c
* Author             : Tiko Zhong
* Date First Issued  : 12/01/2015
* Description        : This file provides a set of functions needed to manage the
*                      
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "cspin_command.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
uint8_t cspin_command(UART_RSRC *huartRsrc, cSPIN_Rsrc_T* pRsrc,uint8_t* str);

/* Public function prototypes -----------------------------------------------*/	
/*******************************************************************************
* Function Name  : motorCmd
* Description    : motorCmd function commands
* Input          : - huart : using this uart to print
									: - cmdStr : the command string
* Output         : None
* Return         : None
*******************************************************************************/
void motorCmdHelp(UART_RSRC *huartRsrc){
	//help@motorCmd
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"motor commands:\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].setup()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].set_abs_pos(%val)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].set_mark_pos(%val)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].set_acc(%val)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].set_dec(%val)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].set_max_spd(%val)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].set_min_spd(%val)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].set_fs_spd(%val)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].set_int_spd(%val)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].set_config(%val)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].set_status(%val)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].get_abs_pos()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].get_mark_pos()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].get_acc()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].get_dec()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].get_max_spd()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].get_min_spd()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].get_fs_spd()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].get_int_spd()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].get_config()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].get_status()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].run(fwd/rev,spd)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].move(fwd/rev,%nstep)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].go_to(%absPos)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].go_to_dir(fwd/rev,absPos)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].go_until(cpy/rst,fwd/rev,speed)\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].release_sw(cpy/rst,fwd/rev) \r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].go_home()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].go_mark()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].reset_pos()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].soft_stop()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].hard_stop()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].soft_hiz()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].hard_hiz()\r\n");
	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\tmotor[*].get_status()\r\n");
}

/*******************************************************************************
* Function Name  : motorCmd
* Description    : motorCmd function commands
* Input          : - huart : using this uart to print
									: - cmdStr : the command string
* Output         : None
* Return         : None
motor[*].setup()
motor[*].set_param(reg,val)
motor[*].get_param()
motor[*].run(fwd/rev,spd)
motor[*].Step_Clock(fwd/rev)
motor[*].move(fwd/rev,nstep)
motor[*].go_to(absPos)
motor[*].go_to_dir(fwd/rev,absPos)
motor[*].go_until(cpy/rst,fwd/rev,speed)
motor[*].release_sw(cpy/rst,fwd/rev) 
motor[*].go_home()
motor[*].go_mark()
motor[*].reset_pos()
motor[*].soft_stop()
motor[*].hard_stop()
motor[*].soft_hiz()
motor[*].hard_hiz()
motor[*].get_status()
*******************************************************************************/
uint8_t motorCmd(UART_RSRC *huartRsrc, uint8_t* cmdStr, cSPIN_Rsrc_T* pRsrc, uint8_t motorSum){
	uint32_t val,indx;
	uint8_t i,j,conditions;
	
	/***********************************************************
	@	motor[*].
	@	motor[%d].
	************************************************************/	
	if(strNCmp((const char*)cmdStr,"motor[",6) == 0 ){
		if(strNCmp((const char*)cmdStr,"motor[*].",9) == 0 ){
			indx = 0xff;
			j = 9;	/* point to the next char */
		}
		else{
			conditions = 0;
			j = firstNumFrStrN(cmdStr, &indx,1);	if(j && indx<motorSum)	conditions++;
			if(strNCmp((const char*)&cmdStr[j],"].",2)==0 )						conditions++;
			if(conditions != 2)	return 0;
			j += 2;
		}
	}
	else	return 0;
	
	/***********************************************************
	@	motor[*].setup()
	************************************************************/	
	if(strNCmp((const char*)&cmdStr[j],"setup()",7)==0 ){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Setup(&pRsrc[indx]);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Setup(&pRsrc[i]);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].setup()\r\n");
		return 1;
	}

	/***********************************************************
	@	_set_param() Group
	************************************************************/
	/***********************************************************
	@	motor[*].set_abs_pos(%val)
	@ val:[-power(2,21),power(2,21)-1]
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"set_abs_pos(",12)==0 )	conditions++;
	i=firstNumFrStrN(&cmdStr[j], &val,10);	if(i)										conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )						conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");		
		if(indx < motorSum){
			cSPIN_Set_Param(&pRsrc[indx], cSPIN_ABS_POS, val);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Set_Param(&pRsrc[i], cSPIN_ABS_POS, val);	
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].set_abs_pos(");	huartRsrc->PrintDec(&huartRsrc->cfg, val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");		
		return 1;
	}
	
	/***********************************************************
	@	motor[*].set_mark_pos(%val)
	@ val:[-power(2,21),power(2,21)-1]
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"set_mark_pos(",13)==0 )	conditions++;
	i = firstNumFrStrN(&cmdStr[j], &val,9);	if(i)									conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )						conditions++;
	if(conditions==3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Set_Param(&pRsrc[indx], cSPIN_MARK, val);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Set_Param(&pRsrc[i], cSPIN_MARK, val);	
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].set_mark_pos(");	huartRsrc->PrintDec(&huartRsrc->cfg, val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");		
		return 1;
	}

	/***********************************************************
	@	motor[*].motor[*].set_acc(%val)
	@ val:in uStep
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"set_acc(",8)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)							conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )			conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Set_Param(&pRsrc[indx], cSPIN_ACC, AccDec_Steps_to_Par(val));
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Set_Param(&pRsrc[i], cSPIN_ACC, AccDec_Steps_to_Par(val));
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].set_acc(");	huartRsrc->PrintDec(&huartRsrc->cfg, val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");		
		return 1;
	}
	
	/***********************************************************
	@	motor[*].set_dec(%val)
	@ val:in uStep
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"set_dec(",8)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)							conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )			conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");
		if(indx < motorSum){
			cSPIN_Set_Param(&pRsrc[indx], cSPIN_DEC, AccDec_Steps_to_Par(val));
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Set_Param(&pRsrc[i], cSPIN_DEC, AccDec_Steps_to_Par(val));
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].set_dec(");	huartRsrc->PrintDec(&huartRsrc->cfg, val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");
		return 1;
	}

	/***********************************************************
	@	motor[*].set_max_spd(%val)
	@ val:in uStep
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"set_max_spd(",12)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)										conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )						conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Set_Param(&pRsrc[indx], cSPIN_MAX_SPEED, MaxSpd_Steps_to_Par(val));
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Set_Param(&pRsrc[i], cSPIN_MAX_SPEED, MaxSpd_Steps_to_Par(val));
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].set_max_spd(");		huartRsrc->PrintDec(&huartRsrc->cfg, val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");
		return 1;
	}

	/***********************************************************
	@	motor[*].set_min_spd(%val)
	@ val:in uStep
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"set_min_spd(",12)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)										conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )						conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Set_Param(&pRsrc[indx], cSPIN_MIN_SPEED, MinSpd_Steps_to_Par(val));
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Set_Param(&pRsrc[i], cSPIN_MIN_SPEED, MinSpd_Steps_to_Par(val));
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].set_min_spd(");		huartRsrc->PrintDec(&huartRsrc->cfg, val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");				
		return 1;
	}

	/***********************************************************
	@	motor[*].set_fs_spd(%val)
	@ val:in uStep
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"set_fs_spd(",11)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)									conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )					conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");		
		if(indx < motorSum){
			cSPIN_Set_Param(&pRsrc[indx], cSPIN_FS_SPD, FSSpd_Steps_to_Par(val));
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Set_Param(&pRsrc[i], cSPIN_FS_SPD, FSSpd_Steps_to_Par(val));
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].set_fs_spd(");	huartRsrc->PrintDec(&huartRsrc->cfg, val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");				
		return 1;
	}

	/***********************************************************
	@	motor[*].set_int_spd(%val)
	@ val:in uStep
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"set_int_spd(",12)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)										conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )						conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");		
		if(indx < motorSum){
			cSPIN_Set_Param(&pRsrc[indx], cSPIN_INT_SPD, IntSpd_Steps_to_Par(val));
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Set_Param(&pRsrc[i], cSPIN_INT_SPD, IntSpd_Steps_to_Par(val));
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].set_int_spd(");	huartRsrc->PrintDec(&huartRsrc->cfg, val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");				
		return 1;
	}

	/***********************************************************
	@	motor[*].set_config(%val)
	@ val:in uStep
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"set_config(",11)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)									conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )					conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");		
		if(indx < motorSum){
			cSPIN_Set_Param(&pRsrc[i], cSPIN_CONFIG, val);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Set_Param(&pRsrc[i], cSPIN_CONFIG, val);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].set_config(");	huartRsrc->PrintDec(&huartRsrc->cfg, val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");	
		return 1;
	}

	/***********************************************************
	@	motor[*].set_status(%val)
	@ val:in uStep
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"set_status(",11)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)									conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )					conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");		
		if(indx < motorSum){
			cSPIN_Set_Param(&pRsrc[i], cSPIN_STATUS, val);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Set_Param(&pRsrc[i], cSPIN_STATUS, val);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].set_status(");	huartRsrc->PrintDec(&huartRsrc->cfg, val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");	
		return 1;
	}

	/***********************************************************
	@	_get_param() Group
	************************************************************/
	/***********************************************************
	@	motor[*].get_abs_pos()
	@ return	:
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"get_abs_pos()",13)==0 ){
		if(indx < motorSum){
			pRsrc[indx].reg.ABS_POS = cSPIN_Get_Param(&pRsrc[indx], cSPIN_ABS_POS);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	huartRsrc->PrintDec(&huartRsrc->cfg,indx);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].abs_pos= ");	huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[indx].reg.ABS_POS);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\r\n");				
		}
		else{
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[*].abs_pos=\t");
			for(i=0;i<motorSum;i++){
				pRsrc[i].reg.ABS_POS = cSPIN_Get_Param(&pRsrc[i], cSPIN_ABS_POS);
				huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[i].reg.ABS_POS);	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\t");
			}	
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\r\n");				
		}
		return 1;
	}

	/***********************************************************
	@	motor[*].get_mark_pos()
	@ return	:
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"get_mark_pos()",14)==0 ){
		if(indx < motorSum){
			pRsrc[indx].reg.MARK = cSPIN_Get_Param(&pRsrc[indx], cSPIN_MARK);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	huartRsrc->PrintDec(&huartRsrc->cfg,indx);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].mark_pos= ");	huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[indx].reg.MARK);
			return 1;			
		}
		else{
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[*].mark_pos=\t");	
			for(i=0;i<motorSum;i++){
				pRsrc[i].reg.MARK = cSPIN_Get_Param(&pRsrc[i], cSPIN_MARK);
				huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[i].reg.MARK);	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\t");	
			}			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\r\n");
		return 1;
	}

	/***********************************************************
	@	motor[*].get_acc()
	@ return	:
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"get_acc()",9)==0 ){
		if(indx < motorSum){
			pRsrc[indx].reg.ACC = cSPIN_Get_Param(&pRsrc[indx], cSPIN_ACC);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	huartRsrc->PrintDec(&huartRsrc->cfg,indx);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].acc= ");	huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[indx].reg.ACC);		
		}
		else{
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[*].acc=\t");	
			for(i=0;i<motorSum;i++){
				pRsrc[i].reg.ACC = cSPIN_Get_Param(&pRsrc[i], cSPIN_ACC);
				huartRsrc->PrintDec(&huartRsrc->cfg,i);
				huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[i].reg.ACC);	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\t");	
			}			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\r\n");
		return 1;
	}

	/***********************************************************
	@	motor[*].get_dec()
	@ return	:
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"get_dec()",9)==0 ){
		if(indx < motorSum){
			pRsrc[indx].reg.DEC = cSPIN_Get_Param(&pRsrc[indx], cSPIN_DEC);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	huartRsrc->PrintDec(&huartRsrc->cfg,indx);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].dec= ");	huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[indx].reg.DEC);	
		}
		else{
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[*].dec=\t");	
			for(i=0;i<motorSum;i++){
				pRsrc[i].reg.DEC = cSPIN_Get_Param(&pRsrc[i], cSPIN_DEC);
				huartRsrc->PrintDec(&huartRsrc->cfg,i);
				huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[i].reg.DEC);	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\t");	
			}			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\r\n");
		return 1;
	}

	/***********************************************************
	@	motor[*].get_max_spd()
	@ return	:
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"get_max_spd()",13)==0 ){
		if(indx < motorSum){
			pRsrc[indx].reg.MAX_SPEED = cSPIN_Get_Param(&pRsrc[indx], cSPIN_MAX_SPEED);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	huartRsrc->PrintDec(&huartRsrc->cfg,indx);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].max_spd= ");	huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[indx].reg.MAX_SPEED);	
		}
		else{
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[*].max_spd=\t");
			for(i=0;i<motorSum;i++){
				pRsrc[i].reg.MAX_SPEED = cSPIN_Get_Param(&pRsrc[i], cSPIN_MAX_SPEED);
				huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[i].reg.MAX_SPEED);	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\t");
			}			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\r\n");	
		return 1;
	}

	/***********************************************************
	@	motor[*].get_min_spd()
	@ return	:
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"get_min_spd()",13)==0 ){
		if(indx < motorSum){
			pRsrc[indx].reg.MIN_SPEED = cSPIN_Get_Param(&pRsrc[indx], cSPIN_MIN_SPEED);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	huartRsrc->PrintDec(&huartRsrc->cfg,indx);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].min_spd= ");	huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[indx].reg.MIN_SPEED);
		}
		else{
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[*].min_spd=\t");			
			for(i=0;i<motorSum;i++){
				pRsrc[i].reg.MIN_SPEED = cSPIN_Get_Param(&pRsrc[i], cSPIN_MIN_SPEED);
				huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[i].reg.MIN_SPEED);	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\t");
			}			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\r\n");		
		return 1;
	}

	/***********************************************************
	@	motor[*].get_fs_spd()
	@ return	:
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"get_fs_spd()",12)==0 ){
		if(indx < motorSum){
			pRsrc[indx].reg.FS_SPD = cSPIN_Get_Param(&pRsrc[indx], cSPIN_FS_SPD);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	huartRsrc->PrintDec(&huartRsrc->cfg,indx);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].fs_spd= ");	huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[indx].reg.FS_SPD);
		}
		else{
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[*].fs_spd= \t");			
			for(i=0;i<motorSum;i++){
				pRsrc[i].reg.FS_SPD = cSPIN_Get_Param(&pRsrc[i], cSPIN_FS_SPD);
				huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[i].reg.FS_SPD);	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\t");	
			}			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\r\n");		
		return 1;
	}

	/***********************************************************
	@	motor[*].get_int_spd()
	@ return	:
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"get_int_spd()",13)==0 ){
		if(indx < motorSum){
			pRsrc[indx].reg.INT_SPD = cSPIN_Get_Param(&pRsrc[indx], cSPIN_INT_SPD);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	huartRsrc->PrintDec(&huartRsrc->cfg,indx);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].int_spd= ");	huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[indx].reg.INT_SPD);
		}
		else{
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[*].int_spd= \t");
			for(i=0;i<motorSum;i++){
				pRsrc[i].reg.INT_SPD = cSPIN_Get_Param(&pRsrc[i], cSPIN_INT_SPD);
				huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[i].reg.INT_SPD);	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\t");	
			}			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\r\n");			
		return 1;
	}

	/***********************************************************
	@	motor[*].get_config()
	@ return	:
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"get_config()",12)==0 ){
		if(indx < motorSum){
			pRsrc[indx].reg.CONFIG = cSPIN_Get_Param(&pRsrc[indx], cSPIN_CONFIG);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	huartRsrc->PrintDec(&huartRsrc->cfg,indx);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].config= ");	huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[indx].reg.CONFIG);
		}
		else{
			for(i=0;i<motorSum;i++){
				pRsrc[i].reg.CONFIG = cSPIN_Get_Param(&pRsrc[i], cSPIN_CONFIG);
				huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[*].config= \t");			huartRsrc->PrintDec(&huartRsrc->cfg,i);
				huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[i].reg.CONFIG);	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\t");	
			}			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\r\n");	
		return 1;
	}

	/***********************************************************
	@	motor[*].get_status()
	@ return	:
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"get_status()",12)==0 ){
		if(indx < motorSum){
			pRsrc[indx].reg.STATUS = cSPIN_Get_Param(&pRsrc[indx], cSPIN_STATUS);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	huartRsrc->PrintDec(&huartRsrc->cfg,indx);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].status= ");	huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[indx].reg.STATUS);	
		}
		else{
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[*].status= \t");			
			for(i=0;i<motorSum;i++){
				pRsrc[i].reg.STATUS = cSPIN_Get_Param(&pRsrc[i], cSPIN_STATUS);
				huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[i].reg.STATUS);	huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\t");
			}			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\r\n");
		return 1;
	}

	/***********************************************************
	@	motor[*].run(fwd/rev,spd)
	@ spd	: steps/s, 
		This command can be given anytime and is immediately executed.
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"run(fwd,",8)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)							conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )			conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Run(&pRsrc[indx], FWD, Speed_Steps_to_Par(val));
			huartRsrc->PrintDec(&huartRsrc->cfg,indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Run(&pRsrc[i], FWD, Speed_Steps_to_Par(val));
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].run(fwd,");		huartRsrc->PrintDec(&huartRsrc->cfg,val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");	
		return 1;
	}
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"run(rev,",8)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)							conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )			conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Run(&pRsrc[indx], REV, Speed_Steps_to_Par(val));
			huartRsrc->PrintDec(&huartRsrc->cfg,indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Run(&pRsrc[i], REV, Speed_Steps_to_Par(val));
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");		
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].run(rev,");		huartRsrc->PrintDec(&huartRsrc->cfg,val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");	
		return 1;
	}

	/***********************************************************
	@	motor[*].move(fwd/rev,%nstep)
	@ spd	: steps/s, 
		This command can be given anytime and is immediately executed.
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"move(fwd,",9)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)								conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )				conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Move(&pRsrc[indx], FWD, val);
			huartRsrc->PrintDec(&huartRsrc->cfg,indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Move(&pRsrc[i], FWD, val);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");		
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].move(fwd,");	huartRsrc->PrintDec(&huartRsrc->cfg,val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");			
		return 1;
	}
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"move(rev,",9)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)								conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )				conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Move(&pRsrc[indx], REV, val);
			huartRsrc->PrintDec(&huartRsrc->cfg,indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Move(&pRsrc[i], REV, val);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");		
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].move(rev,");	huartRsrc->PrintDec(&huartRsrc->cfg,val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");			
		return 1;
	}
	
	/***********************************************************
	@	motor[*].go_to(%absPos)
	@ absPos	: 
		This command can be given anytime and is immediately executed.
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"go_to(",6)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)						conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )		conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Go_To(&pRsrc[indx], val);
			huartRsrc->PrintDec(&huartRsrc->cfg,indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Go_To(&pRsrc[i], val);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");	
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].go_to(");			huartRsrc->PrintDec(&huartRsrc->cfg,val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");			
		return 1;
	}
	
	/***********************************************************
	@	motor[*].go_to_dir(fwd/rev,absPos)
	@ spd	: steps/s, 
		This command can be given anytime and is immediately executed.
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"go_to_dir(fwd,",14)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)											conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )							conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");			
		if(indx < motorSum){
			cSPIN_Go_To_Dir(&pRsrc[indx], FWD, val);
			huartRsrc->PrintDec(&huartRsrc->cfg,indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Go_To_Dir(&pRsrc[i], FWD, val);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");	
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].go_to_dir(fwd,");	huartRsrc->PrintDec(&huartRsrc->cfg,val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");		
		return 1;
	}
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"go_to_dir(rev,",14)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)											conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )							conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");			
		if(indx < motorSum){
			cSPIN_Go_To_Dir(&pRsrc[indx], REV, val);
			huartRsrc->PrintDec(&huartRsrc->cfg,indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Go_To_Dir(&pRsrc[i], REV, val);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");	
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].go_to_dir(rev,");	huartRsrc->PrintDec(&huartRsrc->cfg,val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");		
		return 1;
	}
	
	/***********************************************************
	@	motor[*].go_until(cpy/rst,fwd/rev,speed)
	@ spd	: steps/s, 
		This command can be given anytime and is immediately executed.
	************************************************************/
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"go_until(rst,fwd,",17)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)												conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )								conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");					
		if(indx < motorSum){
			cSPIN_Go_Until(&pRsrc[indx], ACTION_RESET, FWD, Speed_Steps_to_Par(val));
			huartRsrc->PrintDec(&huartRsrc->cfg,indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Go_Until(&pRsrc[i], ACTION_RESET, FWD, Speed_Steps_to_Par(val));
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].go_until(rst,fwd,");	huartRsrc->PrintDec(&huartRsrc->cfg,val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");
		return 1;
	}
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"go_until(rst,rev,",17)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)												conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )								conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");
		if(indx < motorSum){
			cSPIN_Go_Until(&pRsrc[indx], ACTION_RESET, REV, Speed_Steps_to_Par(val));
			huartRsrc->PrintDec(&huartRsrc->cfg,indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Go_Until(&pRsrc[i], ACTION_RESET, REV, Speed_Steps_to_Par(val));
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");		
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].go_until(rst,rev,");	huartRsrc->PrintDec(&huartRsrc->cfg,val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");		
		return 1;
	}
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"go_until(cpy,fwd,",17)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)												conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )								conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");					
		if(indx < motorSum){
			cSPIN_Go_Until(&pRsrc[indx], ACTION_COPY, FWD, Speed_Steps_to_Par(val));
			huartRsrc->PrintDec(&huartRsrc->cfg,indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Go_Until(&pRsrc[i], ACTION_COPY, FWD, Speed_Steps_to_Par(val));
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");		
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].go_until(cpy,fwd,");	huartRsrc->PrintDec(&huartRsrc->cfg,val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");		
		return 1;
	}
	conditions = 0;
	if(strNCmp((const char*)&cmdStr[j],"go_until(cpy,rev,",17)==0 )	conditions++;
	i=firstNumFrStr(&cmdStr[j], &val);	if(i)												conditions++;
	if(strNCmp((const char*)&cmdStr[j+i],")",1)==0 )								conditions++;
	if(conditions == 3){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");					
		if(indx < motorSum){
			cSPIN_Go_Until(&pRsrc[indx], ACTION_COPY, REV, Speed_Steps_to_Par(val));
			huartRsrc->PrintDec(&huartRsrc->cfg,indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Go_Until(&pRsrc[i], ACTION_COPY, REV, Speed_Steps_to_Par(val));
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");		
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].go_until(cpy,rev,");	huartRsrc->PrintDec(&huartRsrc->cfg,val);
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)")\r\n");		
		return 1;
	}
	
	/***********************************************************
	@	motor[*].release_sw(cpy/rst,fwd/rev) 
	@ 
		This command can be given anytime and is immediately executed.
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"release_sw(rst,fwd)",19)==0 ){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");
		if(indx < motorSum){
			cSPIN_Release_SW(&pRsrc[indx], ACTION_RESET, FWD);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Release_SW(&pRsrc[i], ACTION_RESET, FWD);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].release_sw(rst,fwd)\r\n");
		return 1;
	}
	if(strNCmp((const char*)&cmdStr[j],"release_sw(rst,rev)",19)==0 ){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");
		if(indx < motorSum){
			cSPIN_Release_SW(&pRsrc[indx], ACTION_RESET, REV);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Release_SW(&pRsrc[i], ACTION_RESET, REV);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].release_sw(rst,rev)\r\n");
		return 1;
	}
	if(strNCmp((const char*)&cmdStr[j],"release_sw(cpy,fwd)",19)==0 ){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");
		if(indx < motorSum){
			cSPIN_Release_SW(&pRsrc[indx], ACTION_COPY, FWD);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Release_SW(&pRsrc[i], ACTION_COPY, FWD);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].release_sw(cpy,fwd)\r\n");
		return 1;
	}
	if(strNCmp((const char*)&cmdStr[j],"release_sw(cpy,rev)",19)==0 ){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");
		if(indx < motorSum){
			cSPIN_Release_SW(&pRsrc[indx], ACTION_COPY, REV);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Release_SW(&pRsrc[i], ACTION_COPY, REV);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].release_sw(rst,rev)\r\n");
		return 1;
	}

	/***********************************************************
	@	motor[*].go_home()
	@ 
		This command can be given anytime and is immediately executed.
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"go_home()",9)==0 ){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Go_Home(&pRsrc[indx]);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Go_Home(&pRsrc[i]);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].go_home()\r\n");	
		return 1;
	}

	/***********************************************************
	@	motor[*].go_mark()
	@ 
		This command can be given anytime and is immediately executed.
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"go_mark()",9)==0 ){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Go_Mark(&pRsrc[indx]);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);	
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Go_Mark(&pRsrc[i]);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].go_mark()\r\n");	
		return 1;
	}

	/***********************************************************
	@	motor[*].reset_pos()
	@ 
		This command can be given anytime and is immediately executed.
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"reset_pos()",11)==0 ){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Reset_Pos(&pRsrc[indx]);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Reset_Pos(&pRsrc[i]);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].reset_pos()\r\n");
		return 1;
	}

	/***********************************************************
	@	motor[*].soft_stop()
	@ 
		This command can be given anytime and is immediately executed.
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"soft_stop()",11)==0 ){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Soft_Stop(&pRsrc[indx]);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Soft_Stop(&pRsrc[i]);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].soft_stop()\r\n");		
		return 1;
	}
	
	/***********************************************************
	@	motor[*].hard_stop()
	@ 
		This command can be given anytime and is immediately executed.
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"hard_stop()",11)==0 ){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Hard_Stop(&pRsrc[indx]);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Hard_Stop(&pRsrc[i]);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].hard_stop()\r\n");	
		return 1;
	}

	/***********************************************************
	@	motor[*].soft_hiz()
	@ 
		This command can be given anytime and is immediately executed.
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"soft_hiz()",10)==0 ){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Soft_HiZ(&pRsrc[indx]);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Soft_HiZ(&pRsrc[i]);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].soft_hiz()\r\n");
		return 1;
	}
	
	/***********************************************************
	@	motor[*].hard_hiz()
	@ 
		This command can be given anytime and is immediately executed.
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"hard_hiz()",10)==0 ){
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	
		if(indx < motorSum){
			cSPIN_Hard_HiZ(&pRsrc[indx]);
			huartRsrc->PrintDec(&huartRsrc->cfg, indx);
		}
		else{
			for(i=0;i<motorSum;i++)	cSPIN_Hard_HiZ(&pRsrc[i]);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"*");		
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].hard_hiz()\r\n");			
		return 1;
	}
	
	/***********************************************************
	@	motor[*].get_status()
	@ 
		This command can be given anytime and is immediately executed.
	************************************************************/
	if(strNCmp((const char*)&cmdStr[j],"get_status()",12)==0 ){
		if(indx < motorSum){
			pRsrc[i].reg.STATUS = cSPIN_Get_Status(&pRsrc[indx]);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[");	huartRsrc->PrintDec(&huartRsrc->cfg,indx);
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"].status= ");		huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[i].reg.STATUS);
		}
		else{
			huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"+ok @motor[*].status= \t");	
			for(i=0;i<motorSum;i++){
				pRsrc[i].reg.STATUS = cSPIN_Get_Status(&pRsrc[i]);
				huartRsrc->PrintDec(&huartRsrc->cfg,pRsrc[i].reg.STATUS);
				huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\t");
			}			
		}
		huartRsrc->PrintStr(&huartRsrc->cfg, (uint8_t*)"\r\n");	
		return 1;
	}
	
	return 0;
}

/******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE****/