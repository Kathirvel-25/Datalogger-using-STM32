/*
 * logdata.h
 *
 *  Created on: 14-Jan-2026
 *      Author: Kathirvel A
 */

#ifndef LOGDATA_H_
#define LOGDATA_H_
#include "stdint.h"

typedef struct __attribute__((packed)) {

	char lat[15];
	char ns[2];
	char ew[2];
	char lon[15];

    uint16_t temp;


}logdata;

extern logdata da;

#endif /* LOGDATA_H_ */
