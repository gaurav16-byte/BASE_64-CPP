#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string binary(char c)
{
	string rev_bin="", bin="";
	int ascii=c, mod, div, a;
	for(a=1;a<=8;a++)
	{
		mod=ascii%2;
		div=ascii/2;
		if(mod==0){
			rev_bin+="0";
		}
		else{
			rev_bin+="1";
		}
		ascii=div;
	}
	for(a=7;a>=0;a--)
	{
		bin+=rev_bin[a];
	}
	return bin;
}

string correction(string ch)			//TO MAKE THE ARRAY EXACTLY DIVISIBLE BY 6...
{
	int a=0, less, mod, div, size;
	size=ch.length();		//LENGTH OF THE ARRAY
	mod=size%6;				//TO CHECK THE NUMBER OF EXTRA BITS
	less=6-mod;				//NUMBER OF MISSING BITS FOR COMPLETION OF ANOTHER ROUND OF 6 BITS
	if(mod>0)
	{
		while(a<less){
			ch+="0";
			a+=1;
		}
	}
	return ch;
}

string str_to_arr(string ch)
{
	int div=ch.length()/6, a, b, add=0;
	char c;
	int arrays[div][6];
	string base="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", final="";
	
	for(a=0;a<=div-1;a++)
	{
		for(b=0;b<=5;b++)
		{
			c=ch[a*6+b];
			if(c=='0'){
				arrays[a][b]=0;
			}
			else{
				arrays[a][b]=1;
			}
		}
	}
	
	for(a=0;a<=div-1;a++)
	{
		for(b=0;b<=5;b++)
		{
			if(arrays[a][b]==1){
				add+=pow(2,5-b);
			}
		}
		final+=base[add];
		add=0;
	}
	return final;
}

int main()
{
	string ascii_to_bin="", input;
	char alpha;
	int a;
	
	cout << "Enter a string: ";
	cin >>  input;
	
	for(a=0;a<=input.length()-1;a++)						//TO GET FULL BINARY STRING OF STRING INPUT
	{
		alpha=input[a];
		ascii_to_bin+=binary(alpha);
	}
	string correct_string=correction(ascii_to_bin);			//CORRECT STRING CONTAINS STRING PERFECTLY DIVISIBLE BY 6
	string output=str_to_arr(correct_string);
	cout << "The BASE64 encoding is: " << output;
	
	return 0;
}