#include<bits/stdc++.h>
using namespace std;

int symbolLevel(char str){
	string firstLevel = "+-";
	string secondLevel = "*/";
	for(int i=0; i<firstLevel.size(); i++){
		if(str == firstLevel[i]){
			return 1;
		}
	}
	for(int i=0; i<secondLevel.size(); i++){
		if(str == secondLevel[i]){
			return 2;
		}
	}
}

bool isSymbol(char str){
	string symbol = "+-*/";
	for(int i=0; i<symbol.size(); i++){
		if(str == symbol[i]){
			return true;
		}
	}
	return false;
}

string get_suffix(string infix){
	stack<char>symbol;
	string suffix = "";
	int number = 0;
	bool flag = false;
	for(int i=0; i<infix.size(); i++){
		if(infix[i]==' '){
			flag = true;
		}
		else if(isSymbol(infix[i])){
			while(!symbol.empty() and symbolLevel(symbol.top())>=symbolLevel(infix[i])){
				suffix += ' ';
				suffix += symbol.top();
				symbol.pop();
			}
			symbol.push(infix[i]);
		}
		else{
			if(flag){
				suffix+=" ";
				flag = false;
			}
			suffix+=infix[i];
		}
	}
	while(!symbol.empty()){
		suffix += ' ';
		suffix += symbol.top();
		symbol.pop();
	}
	return suffix;
}

double calc(double number1,double number2,char symbol){
	if(symbol=='+'){
		return number1+number2;
	}
	if(symbol=='-'){
		return number1-number2;
	}
	if(symbol=='*'){
		return number1*number2;
	}
	if(symbol=='/'){
		return number1/number2;
	}
}

double get_answer(string suffix){
	stack<double>number;
	int num = 0;
	bool flag = false;
	for(int i=0;i<suffix.size();i++){
		if(suffix[i]==' '){
			if(flag){
				number.push(num);
				num = 0;
				flag = false;
			}
		}
		else if(isSymbol(suffix[i])){
			double number2=number.top();
			number.pop();
			double number1=number.top();
			number.pop();
			number.push(calc(number1,number2,suffix[i]));
		}
		else{
			num = num*10+suffix[i]-'0';
			flag = true;
		}
	}
	return number.top();
}

int main(){
	string infix;
	getline(cin,infix);
	printf("%.2f", get_answer(' '+get_suffix(infix)));
	return 0;
}
