//    CIS 235     Lab 2
//    You will not need to change this code except for COUNT_TOLL_FREE
//    Student - decide upon a member function that you want to use
//                     and prototype that member function in the
//                     class definition

#ifndef PHONE_H
#define PHONE_H
#include <iostream>
using namespace::std;

const int COUNT_TOLL_FREE = 11;

class phone {
	public:
		phone(void);                              // Default constructor

		phone(int area, int exchange, int num);   // 3 Argument constructor

		phone(const phone &);                     // Copy constructor

		phone(const char []);           // pass a string as the parameter
													//   of the form "913-469-8500"
		                                            //or of the form "9134698500"

		~phone(void);                   // One and only destructor

		void   setPhone( int area, int exchange, int num);

		void   setPhone( const char []);

		void   getPhone(char *) const;        //  form a string in caller's memory
		                                      //    of the form 913-469-8500

		int    getNumber(void) const;   // return the phone number as an integer
		                                //   but without the area code

		void   print(ostream & w) const;    //   will print   ddd-ddd-dddd

		void   input(void);                 //   user types a string,with or without -'s

		void   copyTo( phone & ) const;       //   copy invoking instance to parameter

		bool   isSmaller(const phone & ) const;  // return true if invoking instance
															//    is smaller than parameter
		bool   sameAreaCode(const phone &) const; // return true if the invoking instance
		                                                    //  and the parameter have
		                                                    //  the same area code
		bool   tollFree(void) const;   // return true if a toll free number
	private:

		void phoneTakeApart(const char pd[]);

		static const char SEPARATOR;       // Class data, not member data

		static const int TOLL_FREE_EXCHANGES[COUNT_TOLL_FREE];

		int   areaCode,
			  theExchange,
			  theLast4;
};
#endif

