/***************************************************************************************
 *
 *  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
 *
 *  By downloading, copying, installing or using the software you agree to this license.
 *  If you do not agree to this license, do not download, install, 
 *  copy or use the software.
 *
 *  Copyright (C) 2010-2014, Happytimesoft Corporation, all rights reserved.
 *
 *  Redistribution and use in binary forms, with or without modification, are permitted.
 *
 *  Unless required by applicable law or agreed to in writing, software distributed 
 *  under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 *  CONDITIONS OF ANY KIND, either express or implied. See the License for the specific
 *  language governing permissions and limitations under the License.
 *
****************************************************************************************/

#ifndef SOAP_H
#define SOAP_H

#include "sys_inc.h"
#include "onvif.h"
#include "xml_node.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL onvif_rly_handler(XMLN * p_xml, eOnvifAction act, ONVIF_DEVICE * p_dev, void * p_res);

#ifdef __cplusplus
}
#endif


#endif


