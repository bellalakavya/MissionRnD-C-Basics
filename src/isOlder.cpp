/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int validate(int a, int b, int c);
int isOlder(char *dob1, char *dob2) {
	int i, count = 0, j, value, value1;
	int str11, str12, str13, str21, str22, str23;
	if (dob1[2] == '-'&&dob2[2] == '-'&&dob1[5] == '-'&&dob2[5] == '-'){
		str11 = (dob1[0] - 48) * 10 + dob1[1] - 48;
		str12 = (dob1[3] - 48) * 10 + dob1[4] - 48;
		str13 = (dob1[6] - 48) * 1000 + (dob1[7] - 48) * 100 + (dob1[8] - 48) * 10 + dob1[9];
		str21 = (dob2[0] - 48) * 10 + dob2[1] - 48;
		str22 = (dob2[3] - 48) * 10 + dob2[4] - 48;
		str23 = (dob2[6] - 48) * 1000 + (dob2[7] - 48) * 100 + (dob2[8] - 48) * 10 + dob2[9];
	}
	else{
		return -1;
	}
	if (str11 == str21&&str12 == str22&&str13 == str23){
		return 0;
	}
	for (i = 0, j = 0; dob1[i] != '\0'&&dob2[j] != '\0'; i++, j++){
		i++;
		j++;
	}
	if (i < 0 && i>10 && j < 0 && j>10){
		return -1;
	}
	value = validate(str11, str12, str13);
	value1 = validate(str21, str22, str23);
	if (value == -1 || value1 == -1){
		return -1;
	}
	else{
		if (str13>str23){
			return 2;
		}
		else if (str13<str23){
			return 1;
		}
		else if (str13 == str23){
			if (str12>str22){
				return 2;
			}
			else if (str12<str22){
				return 1;
			}
			else if (str12 == str22){
				if (str11>str21){
					return 2;
				}
				else if (str11<str21){
					return 1;
				}
				
			}
		}
	}
}
int validate(int a, int b, int c){
	if (b<13){
		if (b == 2){
			if (c % 4 == 0){
				if (a > 29){
					return -1;
				}
				else{
					return 1;
				}
			}
			else{
				if (a > 28){
					return -1;
				}
				else{
					return 1;
				}
			}
		}
		else if (b == 1 && b == 3 && b == 5 && b == 7 && b == 8 && b == 10 && b == 12){
			if (a > 31){
				return -1;
			}
			else{
				return 1;
			}
		}
		else if (b == 4 && b == 6 && b == 9 && b == 11){
			if (a > 30){
				return -1;
			}
			else{
				return 1;
			}
		}
	}
	else{
		return -1;
	}
}