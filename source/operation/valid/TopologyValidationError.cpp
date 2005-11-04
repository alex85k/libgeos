/**********************************************************************
 * $Id$
 *
 * GEOS - Geometry Engine Open Source
 * http://geos.refractions.net
 *
 * Copyright (C) 2001-2002 Vivid Solutions Inc.
 * Copyright (C) 2005 Refractions Research Inc.
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 **********************************************************************
 *
 * Last port: operation/valid/TopologyValidationError.java rev. 1.13
 *
 **********************************************************************/

#include <geos/opValid.h>
//#include <stdio.h>

namespace geos {

string TopologyValidationError::errMsg[]={
	"Topology Validation Error",
	"Repeated Point",
	"Hole lies outside shell",
	"Holes are nested",
	"Interior is disconnected",
	"Self-intersection",
	"Ring Self-intersection",
	"Nested shells",
	"Duplicate Rings",
	"Too few points in geometry component",
	"Invalid Coordinate",
	"Ring is not closed"
};

TopologyValidationError::TopologyValidationError(int newErrorType,Coordinate newPt):
	errorType(newErrorType),
	pt(newPt)
{
}

TopologyValidationError::TopologyValidationError(int newErrorType):
	errorType(newErrorType),
	pt(Coordinate::nullCoord)
{
}

int TopologyValidationError::getErrorType() {
	return errorType;
}

Coordinate& TopologyValidationError::getCoordinate(){
	return pt;
}

string TopologyValidationError::getMessage(){
	return errMsg[errorType];
}

string TopologyValidationError::toString() {
	return (getMessage().append(" at or near point")).append(pt.toString());
}

} // namespace geos

/**********************************************************************
 * $Log$
 * Revision 1.9  2005/11/04 11:04:09  strk
 * Ported revision 1.38 of IsValidOp.java (adding closed Ring checks).
 * Changed NestedRingTester classes to use Coorinate pointers
 * rather then actual objects, to speedup NULL tests.
 * Added JTS port revision when applicable.
 *
 * Revision 1.8  2004/11/05 11:41:57  strk
 * Made IsValidOp handle IllegalArgumentException throw from GeometryGraph
 * as a sign of invalidity (just for Polygon geometries).
 * Removed leaks generated by this specific exception.
 *
 * Revision 1.7  2004/09/13 10:14:47  strk
 * Added INVALID_COORDINATE code num and error message.
 *
 * Revision 1.6  2004/07/02 13:28:29  strk
 * Fixed all #include lines to reflect headers layout change.
 * Added client application build tips in README.
 *
 * Revision 1.5  2003/11/07 01:23:43  pramsey
 * Add standard CVS headers licence notices and copyrights to all cpp and h
 * files.
 *
 *
 **********************************************************************/

