#include <iostream>

using namespace std;

// default name

string name="root";

// Comands

string commands="Commands:\n\t-help\tto output a help message\n\t-exit\tto exit the prompt\n\t-echo\tto return an argument\n\t-whoami\tto return the users name\n\t-var\tto return all the variables\n\t-conf\tto configure the computer\n\t-cowsay\tto return an argument in cow style";

// echo

string echousg="Usage:\n\t-'echo @argument@' return @argument@";

// conf

string confusg="Usage:\n\t-'conf @argument@ @new@' change the argument's value to a new value";
string confnusg="Usage:\n\t-'conf -n @name@' change the old name to a new name";
string confarg="Arguments:\n\t-n\tto change the name";

//cowsay

string cowsayusg="Usage:\n\t-'cowsay @argument@' return @argument@ in cow style";

// vars

int curvar=0;

string var[500];
string val[500];

string in(){
	string out;
	getline(cin,out);
	return out;
}

void out(string in){
	cout << in;
}

string parser(string in,int argnum){
	in=" "+in;
	int dolz=in.length();
	int lenos=0;
	int lenspc=0;
	int bfs=0;
	int navodnici=0;
	int negat=0;
	int isvar=0;
	if(argnum==1){
		in=in+" ";
		dolz++;
		for(int i=0;i<dolz;i++){
			if(in[i]==' '&&bfs==0){
				lenspc++;
			}else if(in[i]!=' '&&bfs==0){
				bfs=1;
			}
			if(in[i]=='"'&&navodnici==0){
				navodnici=1;
			}else if(in[i]=='"'&&navodnici==1){
				navodnici=0;
				lenspc++;
				negat=1;
			}
			if(in[i]==' '&&bfs==1&&navodnici==0){
				lenos=i;
				if(negat==1){
					lenos--;
				}
				break;
			}
		}
		if(in[lenspc]=='$'){
			isvar=1;
		}
	}else if(argnum==2){
		for(int i=0;i<dolz;i++){
			if(in[i]!=' '&&bfs==0){
				bfs=1;
			}
			if(in[i]==' '&&bfs==1){
				lenos=i;
				break;
			}
		}
		lenspc=lenos;
		lenos=dolz;
	}
	string out=in.substr(lenspc,lenos-lenspc);
	if(isvar==1){
		for(int i=0;i<curvar;i++){
			if(("$"+var[i])==out){
				out=val[i];
				return out;
			}
		}
		return "";
	}
	return out;
}

string varuse(string in){
	int dolzin=in.length();
	int kolku=0;
	int lenspc=0;
	int bfs=0;
	for(int i=1;i<dolzin;i++){
		if(in[i]=='='){
			kolku++;
		}
	}
	for(int i=0;i<dolzin;i++){
		if(in[i]==' '&&bfs==0){
			lenspc++;
		}else if(in[i]!=' '&&bfs==0){
			bfs=1;
		}
		if(in[i]!=' '&&bfs==1){
			break;
		}
	}
	if(kolku==1){
		int leneq=0;
		for(int i=0;i<dolzin;i++){
			if(in[i]=='='){
				break;
			}
			leneq++;
		}
		string varname=in.substr(lenspc,leneq-lenspc);
		bool found=false;
		int posf=curvar;
		for(int i=0;i<curvar;i++){
			if(var[i]==varname){
				posf=i;
				found=true;
				break;
			}
		}
		var[posf]=varname;
		val[posf]=parser(in.substr(leneq+1,dolzin),1);
		if(found==false){
			curvar++;
		}
		return "";
	}else{
		return "No such a command '"+parser(in,1)+"'";
	}
}

string prompt(string in){
	string com=parser(in,1);
	int dolz=in.length();
	if(com=="help"){
		return commands;
	}else if(com=="echo"){
		if(dolz==4||dolz==5){
			return echousg;
		}else{
			string emp=parser(in,2);
			string ok=parser(emp,1);
			if(emp=="echo "||emp==" "||ok=="echo"||ok==""){
				return echousg;
			}else{
				return ok;
			}
		}
	}else if(com=="var"){
		string outputing;
		for(int i=0;i<curvar-1;i++){
			outputing=outputing+var[i]+'\t'+val[i]+'\n';
		}
		outputing=outputing+var[curvar-1]+'\t'+val[curvar-1];
		return outputing;
	}else if(com=="whoami"){
		return name;
	}else if(com=="conf"){
		if(dolz==4||dolz==5){
			return confusg;
		}else{
			string emp=parser(in,2);
			if(emp=="conf "||emp==" "||emp=="conf"||emp==""){
				return confusg;
			}else{
				string empfirst=parser(emp,1);
				if(empfirst=="-n"){
					string wh=parser(emp,2);
					string second=parser(wh,1);
					if(wh=="-n "||wh==" "||wh=="-n"||wh==""||second=="-n "||second==" "||second=="-n"||second==""){
						return confnusg;
					}else{
						name=second;
						return "Name changed to: "+second;
					}
				}else{
					return "No such an argument:'"+empfirst+"'\n"+confarg;
				}
			}

		}
	}else if(com=="cowsay"){
		if(dolz==6||dolz==7){
			return cowsayusg;
		}else{
			string emp=parser(in,2);
			if(emp=="cowsay "||emp==" "||emp=="cowsay"||emp==""){
				return cowsayusg;
			}else{
				string empfirst=parser(emp,1);
				string generate=" ";
				for(int i=0;i<empfirst.length()+2;i++){
					generate=generate+'_';
				}
				generate=generate+"\n< "+empfirst+" >\n ";
				for(int i=0;i<empfirst.length()+2;i++){
					generate=generate+'-';
				}
				generate=generate+"\n        "+char(92)+"   ^__^\n         "+char(92)+"  (oo)"+char(92)+"_______\n            (__)"+char(92)+"       )"+char(92)+"/"+char(92)+"\n                ||----w |\n                ||     ||";
				return generate;
			}
		}
	}else if(com==""){
		return "";
	}else{
		return varuse(in);
	}
	return "Error";
}

void recurs(){
	string cur;
	out(">>");
	cur=in();
	if(parser(cur,1)=="exit"){
		return;
	}else if(cur==""){
		recurs();
	}else{
		out(prompt(cur)+"\n");
		recurs();
	}
}

int main(int argc, char **argv){
	recurs();
	return 0;
}
