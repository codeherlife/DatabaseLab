//
//  Name this file: database.c
//  DatabaseLab
//
//  Student Name: Melanie Summers;
//  Student id: 012090935;
//  Name of the assignment: Database Lab;
//  Date: 11/27/18;
//  Name and version of the C Compiler: Xcode v. 10.1 (10B61);
//  Name of Operating System: Mac OS High Sierra v. 10.13.6;


#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define MAX 100

FILE *fp, *fpIn;

typedef struct {
    char first[8];
    char initial[2];
    char last[10];
    char street[17];
    char city[12];
    char state[3];
    char zip[6];
    int age;
    char sex[2];
    int tenure;
    double salary;
} Employee;

int main(void);
int inputData(Employee workers[]);
void outputContents (Employee workers[], int workerCounter);
void outputMen (Employee workers[], int workerCounter);
void outputBallerLady (Employee workers[], int workerCounter);
void outputPoorGuy (Employee workers[], int workerCounter);
void averageSalary (Employee workers[], int workerCounter);
void womenGetLess (Employee workers[], int workerCounter);
void ratioMen (Employee workers[], int workerCounter);

int main(void) {
    Employee workers[SIZE];
    int workerCounter;
    
    fp = fopen("csis.txt", "w");
    
    if(!(fpIn = fopen("/Users/codeherlife/Desktop/CSCI 112/DatabaseLab/DatabaseLab/DatabaseLab/payfile.txt", "r"))) {
        printf(     "payfile.txt could not be opened for input.");
        fprintf(fp, "payfile.txt could not be opened for input.");
        fclose(fp);
        exit(1);
    }
    
    workerCounter = inputData(workers);
    outputContents(workers, workerCounter);
    
    
    fclose(fpIn);
    fclose(fp);
    return 0;
}

void strsub(char buf[], char sub[], int start, int end){
    int i, j;
    
    for(j=0, i=start; i<=end; i++, j++){
        sub[j] = buf[i];
    }
    sub[j] = '\0';
}

//(A) this function should read data for employees into an array of structures:
int inputData(Employee workers[]) {
    int i=0;
    char buf[MAX];
    char temp[MAX];
    FILE *fp;
    
    fp = fopen("payfile.txt", "r");
    if (fp == NULL) {
        puts("File patfile.txt could not be opened for input.");
        exit(1);
    }
    while (!feof(fp)) {
        fgets(buf, MAX, fp);
        strsub(buf, workers[i].first, 0, 6);
        strsub(buf, workers[i].initial, 8, 8);
        strsub(buf, workers[i].last, 10, 18);
        strsub(buf, workers[i].street, 20, 35);
        strsub(buf, workers[i].city, 37, 47);
        strsub(buf, workers[i].state, 49, 50);
        strsub(buf, workers[i].zip, 52, 56);
        strsub(buf, temp, 58, 59);
        workers[i].age = atoi(temp);
        strsub(buf, workers[i].sex, 61, 61);
        strsub(buf, temp, 63, 63);
        workers[i].tenure = atoi(temp);
        strsub(buf, temp, 65, 70);
        workers[i].salary = atof(temp);
        ++i;
    }
    fclose(fp);
    return i;
}

//(b)this function should output the contents of each structure into an easily read format, similar to the format of the input file:
void outputContents (Employee workers[], int workerCounter){
    int i;
    for(i = 0; i < workerCounter; i++){
        printf(     "%s", workers[i].first);
        fprintf(fp, "%s", workers[i].first);
        printf(     " %s", workers[i].initial);
        fprintf(fp, " %s", workers[i].initial);
        printf(     " %s", workers[i].last);
        fprintf(fp, " %s", workers[i].last);
        printf(     " %s", workers[i].street);
        fprintf(fp, " %s", workers[i].street);
        printf(     " %s", workers[i].city);
        fprintf(fp, " %s", workers[i].city);
        printf(     " %s", workers[i].state);
        fprintf(fp, " %s", workers[i].state);
        printf(     " %s", workers[i].zip);
        fprintf(fp, " %s", workers[i].zip);
        printf(     " %d", workers[i].age);
        fprintf(fp, " %d", workers[i].age);
        printf(     " %s", workers[i].sex);
        fprintf(fp, " %s", workers[i].sex);
        printf(     " %d", workers[i].tenure);
        fprintf(fp, " %d", workers[i].tenure);
        printf(     " %f", workers[i].salary);
        fprintf(fp, " %f", workers[i].salary);
    }
}

//(C)in this function- output the first and last name of all men on the payroll
void outputMen (Employee workers[], int workerCounter){
    
}

//(D)in this function- output the first and last name of the highest paid woman on the payroll
void outputBallerLady (Employee workers[], int workerCounter){
    
}

//(E)in this function- output the first and last name of the lowest paid man on the payroll
void outputPoorGuy (Employee workers[], int workerCounter){
    
}

//(F) in this function- output the average salary for all employees
void averageSalary (Employee workers[], int workerCounter){
    
}

//(G) in this function- output the first and last name of all women earning less than the average salary.
void womenGetLess (Employee workers[], int workerCounter){
    
}

//(H) in this function- output to 3 decimal places the ratio of the number of men above the average salary to the number  of men below the average salary.
void ratioMen (Employee workers[], int workerCounter){
    
}

//(H) in this function- output to 3 decimal places the ratio of the number of men above the average salary to the number  of men below the average salary.

