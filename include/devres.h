#ifndef DEV_RESOURCE_H
#define DEV_RESOURCE_H

/**********************************************************************************************^M
 * 函数名       :get_video_enc_key()^M
 * 功能 		:获取指定编号的视频编码器使用的缓冲池的key
 * 输入 		:no 视频编码器号
 * 返回值       	:非负值表示对应视频编码器的key
 *				负值表示出错
 *					-EINVAL表示参数非法
 **********************************************************************************************/
int get_video_enc_key(int no);

/**********************************************************************************************^M
 * 函数名       :get_audio_enc_key()^M
 * 功能 		:获取指定编号的音频编码器缓冲池的key
 * 输入 		:no 音频编码器号
 * 返回值       	:非负值表示对应视频编码器的key
 *				负值表示出错
 *					-EINVAL表示参数非法
 **********************************************************************************************/
int get_audio_enc_key(int no);

/**********************************************************************************************^M
 * 函数名       :get_audio_dec_key()^M
 * 功能 		:获取指定编号的音频解码器缓冲池的key
 * 输入 		:no 音频解码器号
 * 返回值       	:非负值表示对应视频编码器的key
 *				负值表示出错
 *					-EINVAL表示参数非法
 **********************************************************************************************/
int get_onvif_pool_key(int no,int type);


/**********************************************************************************************^M
 * 函数名       :get_audio_dec_key()^M
 * 功能 		:获取指定编号的音频解码器缓冲池的key
 * 输入 		:no 音频解码器号
 * 返回值       	:非负值表示对应视频编码器的key
 *				负值表示出错
 *					-EINVAL表示参数非法
 **********************************************************************************************/
int get_audio_dec_key(int no);

/**********************************************************************************************^M
 * 函数名       :get_total_hqenc_num()^M
 * 功能 		:	获取录像通道总数
 * 输入 		:无^M
 * 返回值       	:正值表示录像通道总数M
 *				负值表示出错
 **********************************************************************************************/
int get_total_hqenc_num(void);

/**********************************************************************************************^M
 * 函数名       :get_hqenc_video_ch()^M
 * 功能 		:根据路像通道号获取相应的视频编码器号
 * 输入 		:no 音频解码器号
 * 返回值       	:非负值表示对应视频编码器的key
 *				负值表示出错
 *					-EINVAL表示参数非法
 **********************************************************************************************/
int get_hqenc_video_ch(int hqch);

/**********************************************************************************************^M
 * 函数名       :get_net_video_ch()^M
 * 功能 		:根据网络图像通道号获取相应的视频编码器号
 * 输入 		:netch:网络视频通道号
 * 返回值       	:非负值表示对应视频编码器编号
 *				负值表示出错
 *					-EINVAL表示参数非法
 **********************************************************************************************/
int get_net_video_ch(int netch);

/**********************************************************************************************^M
 * 函数名       :get_hqenc_video_key()
 * 功能 		:获取高清晰录像的视频采集key
 * 输入 		:ch:高清晰路像通道号
 * 返回值       	:非负值表示对应视频编码器的key
 *				负值表示出错
 *					-EINVAL表示参数非法
 **********************************************************************************************/
int get_hqenc_video_key(int ch);

/**********************************************************************************************^M
 * 函数名       :get_hqenc_queue_key()
 * 功能 		:获取高清晰录像使用的消息队列的key
 * 输入 		:ch:高清晰路像通道号
 * 返回值       	:非负值表示对应消息队列的key
 *				负值表示出错
 *					-EINVAL表示参数非法
 **********************************************************************************************/
int get_hqenc_queue_key(int ch);

/**********************************************************************************************^M
 * 函数名       :get_hqenc_audio_key()
 * 功能 		:获取高清晰录像的音频采集key
 * 输入 		:ch:高清晰路像通道号
 * 返回值       	:非负值表示对应音频编码器的key
 *				负值表示出错
 *				-EINVAL表示参数非法
 **********************************************************************************************/
int get_hqenc_audio_key(int ch);

/**********************************************************************************************^M
 * 函数名       :get_tcprtimg_stat_key()
 * 功能         :获取音视频上行服务状态、参数变量的共享内存key
 * 输入         :无
 * 返回值       :音视频上行服务状态的key
 **********************************************************************************************/
int get_tcprtimg_stat_key(void);
/**********************************************************************************************^M
 * 函数名       :get_video_enc_node()
 * 功能 		:获取视频编码器节点名
 * 输入 		:no视频编码器编号
 * 返回值       	:视频编码器设备节点字符串
 *				NULL表示失败(可能是没有初始化devinfo()，或者参数错误)
 **********************************************************************************************/
char *get_video_enc_node(int no);

/**********************************************************************************************^M
 * 函数名       :get_video_enc_driver()
 * 功能 		:获取视频编码器驱动路径
 * 输入 		:no视频编码器编号
 * 返回值       	:视频编码器驱动程序路径
 *				NULL表示失败(可能是没有初始化devinfo()，或者参数错误)
 **********************************************************************************************/
char *get_video_enc_driver(int no);

/**********************************************************************************************^M
 * 函数名       :get_video_enc_name()
 * 功能 		:获取视频编码器的设备名字(卸载时要用)
 * 输入 		:no视频编码器编号
 * 返回值       	:视频编码器驱动程序路径
 *				NULL表示失败(可能是没有初始化devinfo()，或者参数错误)
 **********************************************************************************************/
char *get_video_enc_name(int no);

/**********************************************************************************************^M
 * 函数名       :get_video_enc_ini_sec()
 * 功能 		:获取视频编码器在ini配置文件中存放参数的节名
 * 输入 		:no视频编码器编号
 * 返回值       	:相应的视频编码器配置文件节名字符串
 *				NULL表示失败(可能是没有初始化devinfo()，或者参数错误)
 **********************************************************************************************/
char *get_video_enc_ini_sec(int no);



#endif
