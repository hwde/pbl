#ifndef _PBL_CGI_CGI_H_
#define _PBL_CGI_CGI_H_
/*
 pblCgi.h - include file for Common Gateway Interface functions.

 Copyright (c) 2018 Peter Graf. All rights reserved.

 This file is part of PBL - The Program Base Library.
 PBL is free software.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 For more information on the Program Base Library or Peter Graf,
 please see: http://www.mission-base.com/.

$Log: pblCgi.h,v $
Revision 1.27  2018/03/10 21:49:22  peter
Integration with ArvosDirectoryService

Revision 1.26  2018/03/10 19:08:59  peter
Removed warnings found by Visual Studio 2017 Version 15.6.0.

Revision 1.25  2018/03/10 16:22:21  peter
More work on cgi functions

Revision 1.24  2018/02/23 23:20:24  peter
Started to work on the cgi code

 */

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <ctype.h>
#include <time.h>

#ifdef _WIN32

#include <winsock2.h>

#else
#include <sys/time.h>
#include <unistd.h>
#endif

#include "pbl.h"

	/*****************************************************************************/
	/* #defines                                                                  */
	/*****************************************************************************/

#define PBL_CGI_KEY_DURATION                   "pblCgiDURATION"

#define PBL_CGI_MAX_LINE_LENGTH                (4 * 1024)

#define PBL_CGI_TRACE if(pblCgiTraceFile) pblCgiTrace

	/*****************************************************************************/
	/* Variable declarations                                                     */
	/*****************************************************************************/

	extern FILE * pblCgiTraceFile;
	extern char * pblCgiValueIncrement;

	/*****************************************************************************/
	/* Function declarations                                                     */
	/*****************************************************************************/

	extern void pblCgiTrace(const char * format, ...);

	extern FILE * pblCgiFopen(char * traceFilePath, char * openType);
	extern char * pblCgiGetEnv(char * name);

	extern void pblCgiExitOnError(const char * format, ...);
	extern char * pblCgiSprintf(const char * format, ...);

	extern int pblCgiStrArrayContains(char ** array, char * string);
	extern char * pblCgiStrNCpy(char *dest, char *string, size_t n);
	extern char * pblCgiStrTrim(char * string);
	extern int pblCgiStrIsNullOrWhiteSpace(char * string);
	extern char * pblCgiStrRangeDup(char * start, char * end);
	extern char * pblCgiStrDup(char * string);
	extern int pblCgiStrEquals(char * s1, char * s2);
	extern int pblCgiStrCmp(char * s1, char * s2);
	extern char * pblCgiStrCat(char * s1, char * s2);
	extern char * pblCgiStrFromTime(time_t t);
	extern int pblCgiStrSplit(char * string, char * splitString, size_t size, char * result[]);
	extern PblList * pblCgiStrSplitToList(char * string, char * splitString);
	extern char * pblCgiStrToHexFromBuffer(unsigned char * buffer, size_t length);

	extern PblMap * pblCgiNewMap(void);
	extern int pblCgiMapIsEmpty(PblMap * map);
	extern void pblCgiMapFree(PblMap * map);
	extern PblMap * pblCgiFileToMap(PblMap * map, char * traceFilePath);

	extern void pblCgiParseQuery(int argc, char * argv[]);
	extern char * pblCgiQueryValue(char * key);
	extern char * pblCgiQueryValueForIteration(char * key, int iteration);

	extern PblMap * pblCgiValueMap(void);
	extern void pblCgiSetValue(char * key, char * value);
	extern void pblCgiSetValueForIteration(char * key, char * value, int iteration);
	extern void pblCgiSetValueToMap(char * key, char * value, int iteration, PblMap * map);
	extern void pblCgiUnSetValue(char * key);
	extern void pblCgiUnSetValueForIteration(char * key, int iteration);
	extern void pblCgiUnSetValueFromMap(char * key, int iteration, PblMap * map);
	extern void pblCgiClearValues(void);
	extern char * pblCgiValue(char * key);
	extern char * pblCgiValueForIteration(char * key, int iteration);
	extern char * pblCgiValueFromMap(char * key, int iteration, PblMap * map);

	extern char * pblCgiGetCoockie(char * cookieKey, char * cookieTag);
	extern void pblCgiPrint(char * directory, char * fileName, char * contentType);

#ifdef __cplusplus
}
#endif

#endif
