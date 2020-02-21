#ifndef _PASSWORD_H_
#define _PASSWORD_H_
#pragma once

//get size of char
#define CHAR_SPACE(begin, end) begin = 32; end = 33
#define CHAR_NUMBER(begin, end) begin = 48; end = 58
#define CHAR_HIGHER_ALPHA(begin, end) begin = 65; end = 91
#define CHAR_LOWER_ALPHA(begin, end) begin = 97; end = 123
#define CHAR_ALL(begin, end) begin = 32; end = 127

/*mode about password type
base type:|     1      |      2      |   4    |   8   |    16     |
          | LowerAlpha | HigherAlpha | Number | Space | Character |
*/
#define TYPE_L        1
#define TYPE_H        2
#define TYPE_LH       3
#define TYPE_N        4
#define TYPE_NL       5
#define TYPE_NH       6
#define TYPE_NHL      7
#define TYPE_S        8
#define TYPE_SL       9
#define TYPE_SH       10
#define TYPE_SHL      11
#define TYPE_SN       12
#define TYPE_SNL      13
#define TYPE_SNH      14
#define TYPE_SNHL     15
#define TYPE_C        16
#define TYPE_CL       17
#define TYPE_CH       18
#define TYPE_CHL      19
#define TYPE_CN       20
#define TYPE_CNL      21
#define TYPE_CNH      22
#define TYPE_CNHL     23
#define TYPE_CS       24
#define TYPE_CSL      25
#define TYPE_CSH      26
#define TYPE_CSHL     27
#define TYPE_CSN      28
#define TYPE_CSNL     29
#define TYPE_CSNH     30
#define TYPE_ALL      31

//the number of char type
#define PASSWORD_TYPE 8
//the complexity of password
#define PASSWORD_LEIGHT_MIN 1
#define PASSWORD_LEIGHT_MAX 5

class password
{
private:
	int mode;
	int part[PASSWORD_TYPE];  //single with loop begin, double with loop end
	char guess[PASSWORD_LEIGHT_MAX];
	int len[2];
	int GuessPW(int site, int len);
public:
	int SetMode(int mode);
	int GetMode();
	int PrintPart();
	int CalcMode();
	int PrintChar();
	int GuessPW();
	password(int mode);
	~password();
};

#endif