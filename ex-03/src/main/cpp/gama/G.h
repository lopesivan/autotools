/*
 * G.h
 *
 *  Created on: Jan 23, 2013
 *      Author: ivan
 */

#ifndef G_H_
#define G_H_

#include <iostream>

class G {

private:
	char* myName;

public:
	G();
	virtual ~G();

	char* getMyName() const;
	void setMyName(char*);
};

#endif /* G_H_ */
