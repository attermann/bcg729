/*
 * Copyright (c) 2011-2019 Belledonne Communications SARL.
 *
 * This file is part of bcg729.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "typedef.h"
#include "codecParameters.h"
#include "basicOperationsMacros.h"

/*****************************************************************************/
/* interpolateqLSP : interpolate previous and current qLSP according to      */
/*      spec. 3.2.5 : interpolated = (current+previous)/2                    */
/*    parameters:                                                            */
/*      -(i) previousqLSP : 10 values in Q0.15:  the qLSP of previous frame  */
/*      -(i) currentqLSP : 10 values in Q0.15: the qLSP of current frame     */
/*      -(o) interpolatedqLSP : 10 values in Q0.15 : the interpolated qLSP   */
/*                                                                           */
/*****************************************************************************/
void interpolateqLSP(word16_t previousqLSP[], word16_t currentqLSP[], word16_t interpolatedqLSP[])
{ /* interpolate previous and current qLSP according to spec. 3.2.5 : interpolated = (current+previous)/2 */
	int i;
	for (i=0; i<NB_LSP_COEFF; i++) {
		interpolatedqLSP[i] = (word16_t)PSHR(ADD32(previousqLSP[i], currentqLSP[i]),1);
	}
}
