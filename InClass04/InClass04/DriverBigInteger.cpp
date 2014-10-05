
#include <iostream>
using namespace::std;

#include "BigInteger.h"

int main()
{
	//   STUDENTS
	//      test the code piece by piece by adding and removing comments
	//      REMEMBER that you can use break points and the watch window to help debugging
   
	//      Your final output should match the output at the end of the program


   cout << "Number of digits in our numbers is " << BigInteger::getNumberOfDigits() << endl;

   // test default constructor and << operator
   BigInteger a;
   cout << a << endl;
   // test int argument constructor and << operator
   BigInteger b(123456789), c(999);
   //  test <<
   cout << b << ' ' << c << endl;
   // test copy constructor
   BigInteger d(b);
   cout << "d is " << d << endl;
   // test = operator
   d = c;
   cout << "d is now " << d << endl;

   // test == and + operators
   BigInteger e(123456788), f(667788), g(667788);
   cout << b << ' ' << e << ' ' << " b == e is " << ( b == e ) << endl;
   cout << f << ' ' << g << ' ' << " f == g is " << ( f == g ) << endl;
   cout << e << " + " << f << " is " <<  ( e + f ) << endl;
   // test *
   BigInteger h(20), k(60);
   cout << h << " * " << k << " is " << ( h * k ) << endl;
   // Calculate powers of 2 until overflow
   BigInteger s(1), value(0), stop(20), one(1), two(2),powerOf2(1), save(5);
   while ( !powerOf2.hasOverFlowed())
   {
	   powerOf2 = two * powerOf2;    //  multiple by 2 each time
	   cout << " 2 to the power of " << s << " is " << powerOf2 <<  endl;
	   s = s + one;
   }

   // test C++ string argument constructor
   BigInteger w("12345678901234567890");
   cout << "w is " << w << endl;
   BigInteger w1,w2,oneMillion("1000000");
   w1 = w + w;
   w2 = oneMillion * w;
   cout << w1 << " " << w2 << endl;

 
   return 0;
}
/*
Number of digits in our numbers is 50
0
123456789 999
d is 123456789
d is now 999
123456789 123456788  b == e is 0
667788 667788  f == g is 1
123456788 + 667788 is 124124576
20 * 60 is 1200
 2 to the power of 1 is 2
 2 to the power of 2 is 4
 2 to the power of 3 is 8
 2 to the power of 4 is 16
 2 to the power of 5 is 32
 2 to the power of 6 is 64
 2 to the power of 7 is 128
 2 to the power of 8 is 256
 2 to the power of 9 is 512
 2 to the power of 10 is 1024
 2 to the power of 11 is 2048
 2 to the power of 12 is 4096
 2 to the power of 13 is 8192
 2 to the power of 14 is 16384
 2 to the power of 15 is 32768
 2 to the power of 16 is 65536
 2 to the power of 17 is 131072
 2 to the power of 18 is 262144
 2 to the power of 19 is 524288
 2 to the power of 20 is 1048576
 2 to the power of 21 is 2097152
 2 to the power of 22 is 4194304
 2 to the power of 23 is 8388608
 2 to the power of 24 is 16777216
 2 to the power of 25 is 33554432
 2 to the power of 26 is 67108864
 2 to the power of 27 is 134217728
 2 to the power of 28 is 268435456
 2 to the power of 29 is 536870912
 2 to the power of 30 is 1073741824
 2 to the power of 31 is 2147483648
 2 to the power of 32 is 4294967296
 2 to the power of 33 is 8589934592
 2 to the power of 34 is 17179869184
 2 to the power of 35 is 34359738368
 2 to the power of 36 is 68719476736
 2 to the power of 37 is 137438953472
 2 to the power of 38 is 274877906944
 2 to the power of 39 is 549755813888
 2 to the power of 40 is 1099511627776
 2 to the power of 41 is 2199023255552
 2 to the power of 42 is 4398046511104
 2 to the power of 43 is 8796093022208
 2 to the power of 44 is 17592186044416
 2 to the power of 45 is 35184372088832
 2 to the power of 46 is 70368744177664
 2 to the power of 47 is 140737488355328
 2 to the power of 48 is 281474976710656
 2 to the power of 49 is 562949953421312
 2 to the power of 50 is 1125899906842624
 2 to the power of 51 is 2251799813685248
 2 to the power of 52 is 4503599627370496
 2 to the power of 53 is 9007199254740992
 2 to the power of 54 is 18014398509481984
 2 to the power of 55 is 36028797018963968
 2 to the power of 56 is 72057594037927936
 2 to the power of 57 is 144115188075855872
 2 to the power of 58 is 288230376151711744
 2 to the power of 59 is 576460752303423488
 2 to the power of 60 is 1152921504606846976
 2 to the power of 61 is 2305843009213693952
 2 to the power of 62 is 4611686018427387904
 2 to the power of 63 is 9223372036854775808
 2 to the power of 64 is 18446744073709551616
 2 to the power of 65 is 36893488147419103232
 2 to the power of 66 is 73786976294838206464
 2 to the power of 67 is 147573952589676412928
 2 to the power of 68 is 295147905179352825856
 2 to the power of 69 is 590295810358705651712
 2 to the power of 70 is 1180591620717411303424
 2 to the power of 71 is 2361183241434822606848
 2 to the power of 72 is 4722366482869645213696
 2 to the power of 73 is 9444732965739290427392
 2 to the power of 74 is 18889465931478580854784
 2 to the power of 75 is 37778931862957161709568
 2 to the power of 76 is 75557863725914323419136
 2 to the power of 77 is 151115727451828646838272
 2 to the power of 78 is 302231454903657293676544
 2 to the power of 79 is 604462909807314587353088
 2 to the power of 80 is 1208925819614629174706176
 2 to the power of 81 is 2417851639229258349412352
 2 to the power of 82 is 4835703278458516698824704
 2 to the power of 83 is 9671406556917033397649408
 2 to the power of 84 is 19342813113834066795298816
 2 to the power of 85 is 38685626227668133590597632
 2 to the power of 86 is 77371252455336267181195264
 2 to the power of 87 is 154742504910672534362390528
 2 to the power of 88 is 309485009821345068724781056
 2 to the power of 89 is 618970019642690137449562112
 2 to the power of 90 is 1237940039285380274899124224
 2 to the power of 91 is 2475880078570760549798248448
 2 to the power of 92 is 4951760157141521099596496896
 2 to the power of 93 is 9903520314283042199192993792
 2 to the power of 94 is 19807040628566084398385987584
 2 to the power of 95 is 39614081257132168796771975168
 2 to the power of 96 is 79228162514264337593543950336
 2 to the power of 97 is 158456325028528675187087900672
 2 to the power of 98 is 316912650057057350374175801344
 2 to the power of 99 is 633825300114114700748351602688
 2 to the power of 100 is 1267650600228229401496703205376
 2 to the power of 101 is 2535301200456458802993406410752
 2 to the power of 102 is 5070602400912917605986812821504
 2 to the power of 103 is 10141204801825835211973625643008
 2 to the power of 104 is 20282409603651670423947251286016
 2 to the power of 105 is 40564819207303340847894502572032
 2 to the power of 106 is 81129638414606681695789005144064
 2 to the power of 107 is 162259276829213363391578010288128
 2 to the power of 108 is 324518553658426726783156020576256
 2 to the power of 109 is 649037107316853453566312041152512
 2 to the power of 110 is 1298074214633706907132624082305024
 2 to the power of 111 is 2596148429267413814265248164610048
 2 to the power of 112 is 5192296858534827628530496329220096
 2 to the power of 113 is 10384593717069655257060992658440192
 2 to the power of 114 is 20769187434139310514121985316880384
 2 to the power of 115 is 41538374868278621028243970633760768
 2 to the power of 116 is 83076749736557242056487941267521536
 2 to the power of 117 is 166153499473114484112975882535043072
 2 to the power of 118 is 332306998946228968225951765070086144
 2 to the power of 119 is 664613997892457936451903530140172288
 2 to the power of 120 is 1329227995784915872903807060280344576
 2 to the power of 121 is 2658455991569831745807614120560689152
 2 to the power of 122 is 5316911983139663491615228241121378304
 2 to the power of 123 is 10633823966279326983230456482242756608
 2 to the power of 124 is 21267647932558653966460912964485513216
 2 to the power of 125 is 42535295865117307932921825928971026432
 2 to the power of 126 is 85070591730234615865843651857942052864
 2 to the power of 127 is 170141183460469231731687303715884105728
 2 to the power of 128 is 340282366920938463463374607431768211456
 2 to the power of 129 is 680564733841876926926749214863536422912
 2 to the power of 130 is 1361129467683753853853498429727072845824
 2 to the power of 131 is 2722258935367507707706996859454145691648
 2 to the power of 132 is 5444517870735015415413993718908291383296
 2 to the power of 133 is 10889035741470030830827987437816582766592
 2 to the power of 134 is 21778071482940061661655974875633165533184
 2 to the power of 135 is 43556142965880123323311949751266331066368
 2 to the power of 136 is 87112285931760246646623899502532662132736
 2 to the power of 137 is 174224571863520493293247799005065324265472
 2 to the power of 138 is 348449143727040986586495598010130648530944
 2 to the power of 139 is 696898287454081973172991196020261297061888
 2 to the power of 140 is 1393796574908163946345982392040522594123776
 2 to the power of 141 is 2787593149816327892691964784081045188247552
 2 to the power of 142 is 5575186299632655785383929568162090376495104
 2 to the power of 143 is 11150372599265311570767859136324180752990208
 2 to the power of 144 is 22300745198530623141535718272648361505980416
 2 to the power of 145 is 44601490397061246283071436545296723011960832
 2 to the power of 146 is 89202980794122492566142873090593446023921664
 2 to the power of 147 is 178405961588244985132285746181186892047843328
 2 to the power of 148 is 356811923176489970264571492362373784095686656
 2 to the power of 149 is 713623846352979940529142984724747568191373312
 2 to the power of 150 is 1427247692705959881058285969449495136382746624
 2 to the power of 151 is 2854495385411919762116571938898990272765493248
 2 to the power of 152 is 5708990770823839524233143877797980545530986496
 2 to the power of 153 is 11417981541647679048466287755595961091061972992
 2 to the power of 154 is 22835963083295358096932575511191922182123945984
 2 to the power of 155 is 45671926166590716193865151022383844364247891968
 2 to the power of 156 is 91343852333181432387730302044767688728495783936
 2 to the power of 157 is 182687704666362864775460604089535377456991567872
 2 to the power of 158 is 365375409332725729550921208179070754913983135744
 2 to the power of 159 is 730750818665451459101842416358141509827966271488
 2 to the power of 160 is 1461501637330902918203684832716283019655932542976
 2 to the power of 161 is 2923003274661805836407369665432566039311865085952
 2 to the power of 162 is 5846006549323611672814739330865132078623730171904
 2 to the power of 163 is 11692013098647223345629478661730264157247460343808
 2 to the power of 164 is 23384026197294446691258957323460528314494920687616
 2 to the power of 165 is 46768052394588893382517914646921056628989841375232
 2 to the power of 166 is 93536104789177786765035829293842113257979682750464
 2 to the power of 167 is 87072209578355573530071658587684226515959365500928
w is 12345678901234567890
24691357802469135780 12345678901234567890000000
Press any key to continue . . .
*/