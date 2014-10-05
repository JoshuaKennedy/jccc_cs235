//  CIS 235 -         Project 1 Schedule Class  
//             Use the appointment class of Homework 3 and create the schedule class
//
//    NOTES:
//       1) We will only add to the schedule, no deletes
//       2) Each new add will be placed after the previous add in the array
//            -- count keeps track of the next free cell to use

//  Use the following .H file and  driver function prototypes
//       Write all class functions
//       Write all driver functions
//       Create a driver program to test all functions
// schedule header file
#ifndef SCHEDULE_H
#define SCHEDULE_H
#include "appointment.h"
#include <iostream>
using std::ostream;
const int SCH_ENTRIES = 10;
class schedule {
	public:
	  schedule( void);              // Default Constructor

	  schedule( const char * p);    // title only

	  schedule( const schedule &);  // copy constructor

	  bool         addtoSchedule(const appointment &); // if full, return false
								//  otherwise place in the schedule and return true

	  bool         isFull(void) const;      // true if no cells left, false otherwise

	  void         print(ostream &) const;  // print all appointments

	  void         printForSource(long s, ostream &) const;
											// print only appointments that match that source

	  appointment        search( long s) const;
					//  will return a copy of the first appointment found that matches
					//        the source s,  if no match, return an appointment with
					//             a source of -1 and a description of "Not Found";

	  static void setDateFlag(int);       
	private:
	  char* title;                     // title of the schedule
	  int count;                          // number of appointments currently in the schedule
	  appointment  appointmentArray[SCH_ENTRIES];
	  static int dateFlag;                
};
#endif

			//  Driver program functions

bool  keyBoardEnterAppointment( schedule & );  // return true if successful
													  // return false if full

bool  addFutureAppointment( schedule &, const appointment & e, int d);
						// return true if successful, false if full
						// the appointment added has the same source and
						//  desc as the appointment e, but a date of d days later

bool addRecurringAppointment( schedule &, const appointment & e, int cycle, int times);
                        // return true if successful, false if full
                        // times will indicate the number of appointments to add
                        // each appointment added will have the same source and
                        //     desc as the appointment e, but a date of cycle days later
								//     than the previous appointment added to the schedule 
