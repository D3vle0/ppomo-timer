#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <Windows.h>

int count=0;
FILE *f;
SYSTEMTIME st;

void go();
void rest();
int main() {
    
	GetLocalTime(&st);
    printf("%d:%d:%d\n", st.wHour, st.wMinute, st.wSecond);
    if (!(st.wMinute==30 || st.wMinute==0)){
        printf("0초가 될때까지 기다리는 중...\n");
        for (int i=1;i<=61;i++){
            if (st.wSecond==0)
                break;
            else
                Sleep(1000);
        }
    }
    system("cls");
    printf("타이머는 다음 뽀모 시작 시각에 자동으로 시작됩니다.\n");
    for (int j=1;j<=60;j++){
        if (st.wMinute==30)
            go();
        else if (st.wMinute==00)
            go();
        else
            Sleep(60000);
    }
}

void go(){

    for (int k=1500;k>0;k--){
        system("cls");
        printf("%d초 남았습니다.\n", k);
        printf("%d:%d\n", k/60, k%60);
        Sleep(1000);
    }
    printf("\a");
    printf("\a");
    printf("\a");
    count+=1;
    GetLocalTime(&st);
	f=fopen("timeline.txt","a");
    fprintf(f,"\n");
	fprintf(f,"%d.%d %d:%d - %d뽀모", st.wMonth, st.wDay, st.wHour, st.wMinute, count);
	fclose(f);
    rest();
}

void rest(){
    for (int k=300;k>0;k--){
        system("cls");
        printf("%d초 남았습니다.\n", k);
        printf("%d:%d\n", k/60, k%60);
        Sleep(1000);
    }
    printf("\a");
    printf("\a");
    go();
}