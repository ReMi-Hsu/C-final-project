/*
reg 範圍 (1到150) 
n 總數-1 (5到25筆)
counter 總次數 (老師出20題) 
data陣列 原資料(老師的測資)最後全轉為0與1(2為無法解碼) 
bin陣列  data陣列轉為char的變數型態
sPtr字串 bin每行的資料
cha陣列 最後結果 
*/
#include<stdio.h>
#include<string.h>
void changeToBinary(int da[][6],int size);
void reverse(char dr[][6],int size);
void castToChar(char dct[][6],int dit[][6],int size);
void decode(char *biPtr[],char solvec[],int solvei[],int size);
int calC(int weic[],int size);
int calK(int weik[],int size);
const char *table[12]={"10000","10010","00011","10100","01100","11000","00101", "01001","10001","00001","00100","00110"};
int main(){
	FILE *cfPtr;
	char fileName[50];
	printf("please enter the file name:");
	scanf("%s",fileName);
	if((cfPtr=fopen(fileName, "r"))==NULL) 	printf("0");
	else{
	int reg;
	int counter=1;
	fscanf(cfPtr,"%d",&reg);
	while(reg!=0){
	int test1=0;
	int test2=0;
	int n=reg/6;
	int m=reg-6*n;
	int data[n+1][6]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<6;j++){
		fscanf(cfPtr,"%d",&data[i][j]);
}
}
	for(int j=0;j<m;j++){
		fscanf(cfPtr,"%d",&data[n][j]);
}
	changeToBinary(data,n+1);
	if(reg<29||reg>=150||reg%6!=5)  test1++;
	for(int i=0;i<=n;i++){
		if(data[i][5]!=0)  test1++;
		for(int j=0;j<5;j++){
			if(data[i][j]==2)  test1++;
}
}
	if(test1!=0){
		printf("case %2d: bad code",counter);
}
	else if(test1==0){
		char bin[n+1][6];
		castToChar(bin,data,n+1);
		char *sPtr[n+1];
		for(int i=0;i<=n;i++){
			sPtr[i]=bin[i];
}
		if(((strcmp(sPtr[0],table[11])!=0)||(strcmp(sPtr[n],table[11])!=0))&&((strcmp(sPtr[0],table[4])!=0)||(strcmp(sPtr[n],table[4])!=0))){
		printf("case %2d: bad code",counter);
}
		else{
			if((strcmp(sPtr[0],table[4])==0)&&(strcmp(sPtr[n],table[4])==0)) reverse(bin,n+1);
			for(int i=0;i<=n;i++){
				sPtr[i]=bin[i];
}
			char cha[n]={""};
			int weight[n]={0};
			decode(sPtr,cha,weight,n+1);
			for(int i=0;i<n;i++){
				if(cha[i]=='z') test2++;
} 
			if(test2!=0)	printf("case %2d: bad code",counter);
			else{
				if(calC(weight,n)==0)	printf("case %2d: bad C",counter);
				else{
					switch (calK(weight,n)){
					case 1:
					printf("case %2d: bad K",counter);
					break;
					case 2:
					printf("case %2d: ",counter);
					for(int i=1;i<n-2;i++){
					printf("%c",cha[i]);
}
					break;
}
}
}
}
}
		printf("\n");
		counter++;	
		fscanf(cfPtr,"%d",&reg);
}			
	fclose(cfPtr);
}
}
void reverse(char dr[][6],int size){
	char dre[size][5];
	for(int i=0;i<size;i++){
		for(int j=0;j<6;j++)
		dre[i][j]=dr[i][j];
}
	for(int i=0; i<size; i++) {
  		for(int j=0; j<5;j++) {
 		dr[i][j]=dre[size-1-i][4-j];
}
}
	for(int i=0;i<size;i++){
    	dr[i][5]='\0';
}
}
void changeToBinary(int da[][6],int size){
	int range(float datum,int dat1[],int dat2[],int ndat,int n2dat);
	float max=da[0][0];
	float min=da[0][0];
	for(int i=0;i<size;i++) {
 		for(int j=0;j<6;j++){
  		if(max<da[i][j])  max=da[i][j];
  		if(min>da[i][j]&&da[i][j]!=0)  min=da[i][j]; 
}
}
	int dx[6*size]={0};
	int d2x[6*size]={0};
	int nx=0;
	int n2x=0;
	for(int i=0;i<size;i++) {
  		for(int j=0;j<6;j++){
		if((da[i][j]/min)<=(1.05/0.95))	dx[nx++]=da[i][j];
 		else if((max/da[i][j])<=(1.05/0.95))	 d2x[n2x++]=da[i][j];
}
}
	if(max/min>2.1/0.95||max/min<1.9/0.95||(nx+n2x)!=(6*size)) {
 	for(int i=0;i<size;i++) {
  		for(int j=0;j<6;j++){
    	da[i][j]=2;
}
}
}
	else{
	int minm=min/0.95;
	float x=min;
	while((x<=minm)&&((range(x,dx,d2x,nx,n2x))==0)){
		x++;
}
	for(int i=0;i<size;i++) {
  		for(int j=0;j<6;j++){
  		if((da[i][j]/x<=1.050001)&&(da[i][j]/x>=0.94999)){
		  da[i][j]=0;
}
		else if((da[i][j]/(2*x)<=1.050001)&&(da[i][j]/(2*x)>=0.94999)){
			da[i][j]=1;
}
     	else{
     		da[i][j]=2;	
}
}
}
	da[size-1][5]=0;
}
} 
int range(float datum,int dat1[],int dat2[],int ndat,int n2dat){
	int i=0;
	int j=0;
	while((i!=ndat-1)&&(dat1[i]/datum<=1.050001)&&(dat1[i]/datum>=0.94999)){
		i++;
}
	while((j!=n2dat)&&(dat2[j]/(2*datum)<=1.050001)&&(dat2[j]/(2*datum)>=0.94999)){
		j++;
}
	if((i==ndat-1)&&(j==n2dat)) return 1;
	else return 0;	
}

void castToChar(char dct[][6],int dit[][6],int size){
	for(int i=0; i<size; ++i) {
 		for(int j=0; j<5; ++j) {
  		if(dit[i][j]==1)	dct[i][j]='1'; 
  		else	dct[i][j]='0';
}
}
	for(int i=0;i<size;i++){
 	dct[i][5]='\0';
}
}
void decode(char *biPtr[],char solvec[],int solvei[],int size){
	for(int i=1; i<size-1; ++i ) {
    int x=11;
  		for(int j=0;j<11;j++){
	  	if(strcmp(biPtr[i],table[j])==0)	x=j;
	  	switch(x) {
   		case 0:
    	solvec[i]='0';
    	solvei[i]=0;
    	break;
   		case 1:
    	solvec[i]='1';
   		solvei[i]=1;
    	break;
   		case 2:
    	solvec[i]='2';
    	solvei[i]=2;
    	break;
   		case 3:
    	solvec[i]='3';
    	solvei[i]=3;
    	break;
   		case 4:
    	solvec[i]='4';
    	solvei[i]=4;
    	break;
   		case 5:
    	solvec[i]='5';
    	solvei[i]=5;
    	break;
   		case 6:
    	solvec[i]='6';
    	solvei[i]=6;
    	break;
   		case 7:
    	solvec[i]='7';
    	solvei[i]=7;
   	 	break;
   		case 8:
    	solvec[i]='8';
    	solvei[i]=8;
    	break;
   		case 9:
    	solvec[i]='9';
    	solvei[i]=9;
    	break;
   		case 10:
    	solvec[i]='-';
    	solvei[i]=10;
    	break;
    	case 11:
    	solvec[i]='z';
    	break;
} 
}
}
	solvec[size-1]='\0';
}
int calC(int weic[],int size){
	int totalc=0;
	for(int i=1; i<size-2; ++i) {
	totalc += ((size-3-i)%10+1)*weic[i]; 
}
 	if(weic[size-2]!=totalc%11) return 0;
 	else return 3;
}
int calK(int weik[], int size){
	int totalk=0;
	for(int i=1; i<size-1; ++i) {
 	totalk += ((size-2-i)%9+1)*weik[i]; 
}
	if(weik[size-1]!=totalk%11) return 1;
	else return 2;
}
