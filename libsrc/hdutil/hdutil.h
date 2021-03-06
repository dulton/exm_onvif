/*
	基于mpdisk和fileindex库，供hdmodule和diskman调用
								--wsy Dec 2007
*/

#ifndef HDUTIL_H
#define HDUTIL_H


#ifndef IN
#define IN
#define	OUT
#define IO
#endif

#include <stdio.h>
#include "stdio.h"
#include "unistd.h"
#include "time.h"

struct file_info_struct //文件信息相关数据结构
{
	time_t 	stime;					//开始时间
	int		channel;				//通道
	int		type;					//录像类型 定义与struct hd_enc_struct中的state一样
	int		len;						//文件长度(秒)
	int		trig;					//触发状态  
	int		remote;					//手动录像触发
	int		lock;					//是否被锁
	int 	ing_flag;				//是否正在录像
	char	partition[16];			//所在分区,如"/hqdata/hda3"
};


 /*************************************************************************
 * 	函数名:	hdutil_create_dirs()
 *	功能:	根据文件名逐级判断是否存在该目录，如果没有则创建
 *	输入:	file,文件名
 *	输出:	
 * 	返回值:	0表示成功，负值表示失败
 *************************************************************************/
int hdutil_create_dirs(char *file);

/*************************************************************************
 * 	函数名:	hdutil_lock_all_files()
 *	功能:	加解锁所有的录像文件
 *	输入:	mode, 1为加锁，0为解锁
 *	输出:	
 * 	返回值:	0表示成功,负值表示失败
 *************************************************************************/
int hdutil_lock_all_files(int mode);

/*************************************************************************
* 	函数名:hdutil_get_hderr_reboot_flag()
*	功能:	判断是否HDERR_RBT_TIME内已因为硬盘问题重启过
*	输入:	无
* 	返回值:	1表示应该重启，0表示不要重启
*************************************************************************/
int hdutil_get_hderr_reboot_flag(void);

 /*************************************************************************
 * 	函数名:	hdutil_lock_filename()
 *	功能:	将文件名加上锁标志
 *	输入:	filename,文件名
 *	输出:	tname,加锁后的文件名
 * 	返回值:	0表示成功，负值表示失败
 *************************************************************************/
int hdutil_lock_filename(char *filename,char* tname);


 /*************************************************************************
 * 	函数名:	hdutil_unlock_filename()
 *	功能:	将有锁定标志的文件去掉锁定标志
 *	输入:	filename,文件名
 *	输出:	tname,解锁后的文件名
 * 	返回值:	0表示成功，负值表示失败
 *************************************************************************/
int hdutil_unlock_filename(char *filename,char *tname);

/*************************************************************************
 * 	函数名:	hdutil_filename2finfo()
 *	功能:	将文件名转换成对应的文件信息
 *	输入:	filename，文件名
 *  输出:	info,文件信息相关数据结构
 * 	返回值:	0表示成功,负值表示失败
 *************************************************************************/
int hdutil_filename2finfo(char *filename,struct file_info_struct *info);



/*************************************************************************
 *	函数名	hdutil_init_all_partitions()
 *	功能:	处理系统当前所有存在的分区，
 			清理lostfound目录，
 			初始化索引文件 
 *	输入:	
 *	输出:	
 * 	返回值:	0
 *************************************************************************/
int hdutil_init_all_partitions(void);

			
/*************************************************************************
 *	函数名	hdutil_recreat_db_for_all()
 *	功能:	处理系统当前所有存在的分区，
 			强制重新创建文件索引
 *	输入:	
 *	输出:	
 * 	返回值:	0
 *************************************************************************/
int hdutil_recreat_db_for_all(void);

/*************************************************************************
 * 	函数名:	hdutil_get_oldest_file_partition()
 *	功能:	找到当前最早的可删除文件所在的分区
 *	输入:	
 *	输出:	oldest_partition:最早的可删除文件所在的分区
 * 	返回值:	0表示成功,负值表示没有找到
 *************************************************************************/
int hdutil_get_oldest_file_partition(OUT char* oldest_partition);
			
		

/*************************************************************************
 * 	函数名:	hdutil_filename2dirs()
 *	功能:	为文件名解析出其应该创建的目录名称
 *	输入:	partition,形如"/hqdata/hda1"
 *			filename，形如HQ_C00_D20051024125934_L30_T00.AVI
 *  输出:	dir,形如/hqdata/hda1/2005/10/24/12/HQ_C00_D20051024125934_L30_T00.AVI
 * 	返回值:	0表示成功,负值表示失败
 *************************************************************************/
int hdutil_filename2dirs(char *partition, char *filename, char *dir);

			

#endif
