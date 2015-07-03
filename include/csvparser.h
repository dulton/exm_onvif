/**
 * csv格式解析库
 * 说明: csv格式是由','分隔的记录
 * csv格式:
 * .每条记录占一行 
 * .以逗号为分隔符 
 * .逗号前后的空格会被忽略 
 * ?.字段中包含有逗号，该字段必须用双引号括起来 
 * ?.字段中包含有换行符，该字段必须用双引号括起来 
 * ?.字段前后包含有空格，该字段必须用双引号括起来 
 * ?.字段中的双引号用两个双引号表示 
 * ?.字段中如果有双引号，该字段必须用双引号括起来 
 * .第一行记录，可以是字段名 
 */

#ifndef CSV_PARSER
#define CSV_PARSER
#ifndef IN
	#define IN 
	#define OUT
	#define IO
#endif

#define MAX_ATOM_NUM	50
#define MAX_ATOM_LEN	100 //50 wsymod

typedef	void CSV_T	;	//应用程序调用库时用到的描述csv结构的类型(只描述一条csv记录)
/****************************错误码定义**********************************************/
#define	CSV_SUCCESS			0	//操作成功
#define	CSV_NO_MEM			1000	//内存不足
#define  CSV_PARA_ERR  			1001	//参数错误
#define  CSV_PARSER_ERR			1002	//无法解析字符串
#define  CSV_OPEN_FILE_ERR		1003	//无法打开文件
#define  CSV_LOCK_FILE_ERR		1004	//无法锁定文件
#define  CSV_NO_RECORD			1005	//无法锁定文件  lsk add 2007 -11- 29

//其它值待定
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
/*
*************************************************************************
*函数名	:csv_create
*功能	: 创建一个解析csv记录的数据结构
*输入	:  无
*输出	: 
*修改日志:
*************************************************************************
*/
 CSV_T	*csv_create(void);

/*
*************************************************************************
*函数名	:csv_set_str
*功能	:设置csv结构中变量的值(字符串型)
* 注意  :如果相同位置的数据存在则进行替换原有值
*输入	:  
		CSV_T	*csv,          	之前使用csv_create得到的指针
		const 	int no,		变量序号
		const char * value 	变量值 
*输出	: 0表示成功负值表示出错
*修改日志:
*************************************************************************
*/
 int csv_set_str(
			IN CSV_T	*csv,          	/*之前使用csv_create得到的指针*/
			IN const int	no,		/*变量序号*/
			IN const char  *value 		/*变量值 */
		);
/*
*************************************************************************
*函数名	:csv_set_int
*功能	:设置csv结构中变量的值(整型值)
* 注意  :如果相同位置的数据存在则进行替换原有值
*输入	:  
		CSV_T	*csv,          	之前使用csv_create得到的指针
		const char * name, 	< 名 
		const char * value 	< 值 
*输出	: 0表示成功负值表示出错
*修改日志:
*************************************************************************
*/
 int csv_set_int(
			IN CSV_T	*csv,          	/*之前使用csv_create得到的指针*/
			IN const int	no,		/*变量序号*/
			IN const int	value 		/*变量值 */
		);




/* 
 *
 *************************************************************************
 *函数名:csv_get_int
 *功能	:读取csv结构中指定序号的变量(整数型)
 *输入	:  
		IN CSV_T 	*csv, 		//之前使用csv_create得到的指针
		IN const int	no, 		//变量序号
		IN const int 	def_val		//没有找到变量时的返回值
 *返回值: 	指定序号变量的值,没有找到则返回def_val
 *修改日志:
 *************************************************************************
 */
int csv_get_int(
			IN CSV_T 	*csv, 		/*之前使用csv_create得到的指针*/
			IN const int	no, 		//变量序号
			IN const int 	def_val		//没有找到变量时的返回值
		);
/* 
 *
 *************************************************************************
 *函数名:csv_get_str
 *功能	:读取csv结构中指定序号的变量(字符串型)
 *输入	:  
		IN CSV_T 	*csv, 		//之前使用csv_create得到的指针
		IN const int	no, 		//变量序号
		IN const char 	*def_val	//没有找到变量时的返回值
 *返回值: 	指定序号变量的值,没有找到则返回def_val
 *修改日志:
 *************************************************************************
 */
const char *csv_get_str(
			IN CSV_T 	*csv, 		/*之前使用csv_create得到的指针*/
			IN const int	no, 		//变量序号
			IN const char 	*def_val	//没有找到变量时的返回值
		);
/* 
 *
 *************************************************************************
 *函数名:csv_get_var_num
 *功能	:获取csv结构中变量的总数
 *输入	:  
		IN CSV_T 	*csv, 		//之前使用csv_create得到的指针
 *返回值: 	负值表示出错,非负值表示csv结构中变量的总数
 *修改日志:
 *************************************************************************
 */
int csv_get_var_num(
			IN CSV_T 	*csv 		/*之前使用csv_create得到的指针*/
		);


/*
************************************************************************
*函数名	:csv_get_string
*功能	:得到csv结构的字符串描述
*输入	:  
		CSV_T	*nv,          之前使用csv_create得到的指针
*输出	: 描述csv结构的字符串指针
*修改日志:
*************************************************************************
*/
 const char * csv_get_string(IN CSV_T *csv    	/*之前使用csv_create得到的指针*/);

/*
************************************************************************
*函数名	:csv_parse_string
*功能	:  解析csv格式的字符串到结构
*输入	:  
		IN const char *  str 		//描述csv格式的字符串
*输出	: 
		IN CSV_T	*csv,        	//之前使用csv_create得到的指针
*返回值 :	0表示成功负值表示失败
*修改日志:
*************************************************************************
*/
 int csv_parse_string(
			OUT CSV_T	*csv,        	//之前使用csv_create得到的指针
			IN  const char *  str 		//描述csv格式的字符串
		);
 /*
************************************************************************
*函数名	:csv_destroy
*功能	:  销毁一个已经使用过的csv结构
*输入	:  
			CSV_T	*csv,          之前使用csv_create得到的指针
*输出	:  无
*修改日志:
*************************************************************************
*/
void csv_destroy(IN CSV_T *csv          	/*之前使用csv_create得到的指针*/);
/*
************************************************************************
*函数名	:csv_get_error_str
*功能	:  获取错误码的字符串描述
*输入	:  int errno, 接口返回的错误代码的绝对值
*返回值	:     错误描述字符串指针
*修改日志:
*************************************************************************
*/
const char *csv_get_error_str(IN int errno);
/*
************************************************************************
*函数名	:csvfile_get_total_records
*功能	:获取一个文件中的csv记录总数
*输入	: 	 IN const char *filename;	//csv结构文件
*返回值	:0表示成功负值表示失败
*修改日志:
*************************************************************************
*/
int csvfile_get_total_records(IN const char *filename	//csv结构文件
								);
/*
************************************************************************
*函数名	:csvfile_get_record
*功能	:从csv文件中获取指定记录号的结构信息
*输入	:  
	 IN const char *filename;	//csv结构文件
	 IN int record_no;		//csv结构中的记录号(正值表示按正序访问,负值表示按倒序访问)
*输出 	:OUT CSV_T *csv;		//指定记录号的记录信息
*返回值	:0表示成功负值表示失败
*修改日志:
*************************************************************************
*/
int csvfile_get_record(IN const char *filename,	//csv结构文件
			IN int record_no,		//csv结构中的记录号(正值表示按正序访问,负值表示按倒序访问)
			OUT CSV_T *csv			//指定记录号的记录信息
			);

/*
************************************************************************
*函数名	:csvfile_set_record
*功能	:将csv结构写入csv文件中
*输入	:  
	 IN const char *filename;	//csv结构文件
	 IN int record_no;		//csv结构中的记录号(正值表示按正序访问,负值表示按倒序访问)
	 				//正序时如果超出最大序号则表示从文件尾部插入
					//倒序时如果超出范围则表示从首部插入
* 	 IN CSV_T *csv;			//指定记录号的记录信息
*返回值	:0表示成功负值表示失败
*修改日志:
*************************************************************************
*/
int csvfile_set_record(IN const char *filename,	//csv结构文件
			IN int record_no,		//csv结构中的记录号(正值表示按正序访问,负值表示按倒序访问)
	 						//正序时如果超出最大序号则表示从文件尾部插入
							//倒序时如果超出范围则表示从首部插入
			IN  CSV_T *csv			//指定记录号的记录信息
			);
/*
************************************************************************
*函数名	:csvfile_insert_record
*功能	:将csv结构插入csv文件中
*输入	:  
	 IN const char *filename;	//csv结构文件
	 IN int record_no;			//csv结构中的记录号(正值表示按正序访问,负值表示按倒序访问)
	 						//正序时如果超出最大序号则表示从文件尾部插入
							//倒序时如果超出范围则表示从首部插入
							// record_no =1 时从文件头插入记录信息
							// record_no =-1时从文件尾部插入记录信息
* 	 IN CSV_T *csv;			//指定记录号的记录信息
*返回值	:0表示成功负值表示失败
*修改日志:
*************************************************************************
*/
int csvfile_insert_record( IN const char *filename,	//csv结构文件
			IN int record_no, //csv结构中的记录号(正值表示按正序访问,负值表示按倒序访问)
	 						//正序时如果超出最大序号则表示从文件尾部插入
							//倒序时如果超出范围则表示从首部插入
							// record_no =1 时从文件头插入记录信息
							// record_no =-1时从文件尾部插入记录信息
			IN CSV_T *csv		//指定记录号的记录信息
					     );


/*
************************************************************************
*函数名	:csvfile_rm_record
*功能	:将filename文件中的第record_no条信息删除掉
*输入	:  
	 IN const char *filename;	//csv结构文件
	 IN int record_no;		//csv结构中的记录号(正值表示按正序访问,负值表示按倒序访问)
	 				//正序时如果超出最大序号则表示从文件尾部删除
					//倒序时如果超出范围则表示从首部删除
*返回值	:0表示成功，负值表示失败
*修改日志:
*************************************************************************
*/
int csvfile_rm_record(IN const char *filename, IN  int record_no);

////test
int force_lockfile(int fd, short int cmd, int wait);

#if 0
/*
************************************************************************
*函数名	:csvfile_insert_record_head
*功能	:将csv结构插入csv文件头部原来的记录信息下移
*输入	:  
	 IN const char *filename;	//csv结构文件
* 	 IN CSV_T *csv;			//指定记录号的记录信息
*返回值	:0表示成功负值表示失败
*修改日志:
*************************************************************************
*/
int csvfile_insert_record_head(IN const char *filename, //csv结构文件
			IN CSV_T *csv//指定记录号的记录信息
						);
/*
************************************************************************
*函数名	:csvfile_insert_record_tail
*功能	:将csv结构插入csv文件尾部原来的记录信息不变
*输入	:  
	 IN const char *filename;	//csv结构文件
* 	 IN CSV_T *csv;			//指定记录号的记录信息
*返回值	:0表示成功负值表示失败
*修改日志:
*************************************************************************
*/
int csvfile_insert_record_tail(IN const char *filename, //csv结构文件
			IN CSV_T *csv//指定记录号的记录信息
						);
#endif
#endif 
