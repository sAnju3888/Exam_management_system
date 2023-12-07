#include <stdio.h>
#include <string.h>

//structure
struct student{
    int rollnum;
    int attendance;
    int eligibility;
    char name[50];
    char feestat;
};
struct student st[100];

// function declaration statments
void eligible(int n);
void update(int n);
void delete(int n);
void addstudent(int *n);
void print(int n);

//main
int main()
{
    int n,check,i,selector;
    printf("Enter the number of students:");
        do{
        scanf("%d",&n);
        }while(n<0);

    printf("Enter Records of %d students\n",n);

    //taking inputs of student details
		for(i=0;i<n;i++){
		    printf("\nEnter the details oF %d st student\n",i+1);
		    st[i].rollnum= i+1;
		
		    printf("Enter Name:");
		    scanf("%s",st[i].name);
		
		    printf("Enter attendance percentage:");
		    do{
		    scanf("%d",&st[i].attendance);
		    }while(st[i].attendance<0||st[i].attendance>100);
		
		    printf("Enter feestatus(y/n):");
		    do{
		    scanf("%c",&st[i].feestat);
		    }while(st[i].feestat!='y'&& st[i].feestat!='n');
		
		    st[i].eligibility=0;
		
		}


//menu driven
do{
    printf("\nwhich program to run\n");
    puts("Enter 1 for delete student record");
    puts("Enter 2 for printing the student details ");
    puts("Enter 3 for knowing eligibility of students");
    puts("Enter 4 for updating the student details");
    puts("Enter 5 for adding the student");
        do{
            scanf("%d",&selector);
        }while(selector!=1&&selector!=2&&selector!=3&&selector!=4&&selector!=5);

    if(selector==1){
        delete(n);
    }else if(selector==2){
        print(n);
    }else if(selector==3){
        eligible(n);
    }else if(selector==4){
        update(n);
    }else if(selector==5){
        addstudent(&n);
    }

    puts("press 1 for running another program or other numbers for exiting");
    scanf("%d",&check);
}while(check==1);


  return 0;
}
// end of main





//function for delete student record
void delete(int n){

    int k;
    printf("enter the roll number to delete the record:");
    do{
    	scanf("%d",&k);
	}while (k<0 || k>n);
    k=k-1;
        st[k].attendance=-1;
        st[k].feestat='\0';

    printf("Person with roll number %d is successfully deleated\n",k+1);
}

// function for printing the student details
void print(int n){
    int i,k,x;
    puts("For printing all students record in the class enter 1");
    puts("To print the particular student record  with his rollno number enter 2");
    do{
    scanf("%d",&k);
    }while(k!=1 && k!=2);
    if(k==1){
        for(i;i<n;i++){
           if(st[i].attendance==-1){
            printf("student with roll number %d is deleted\n",i+1);
        	}
        	else{
            printf("Details of student with rollnum %d\n",i+1);
            printf("Name: %s\n",st[i].name);
            printf("Attendance percentage: %d\n",st[i].attendance);
            printf("fee statues: ");
                if(st[i].feestat=='y'){
                    printf("paid\n");
                }else{
                    printf("not paid\n");
                }
                if(st[i].attendance>=75){
                    if(st[i].feestat=='y'){
                        puts("Eligible for exam\n");
                    }else{
                        puts("Not eligible for exam\n");
                    }
                }else{
                    puts("Not eligible for exam\n");
                }
        } 
        }
    }else if(k==2){ 
        puts("Rollnumber of the student to print records");
        do{
            scanf("%d",&i);
        }while(i>n||i<0);
        i=i-1;
        if(st[i].attendance==-1){
            printf("student with roll number %d is deleted\n",i+1);
        }
        else{
            printf("Details of student with rollnum %d\n",i+1);
            printf("Name: %s\n",st[i].name);
            printf("Attendance percentage: %d\n",st[i].attendance);
            printf("Fee statues: ");
                if(st[i].feestat=='y'){
                    printf("paid\n");
                }else{
                    printf("not paid\n");
                }
                if(st[i].attendance>=75){
                    if(st[i].feestat=='y'){
                        puts("Eligible for exam\n");
                    }else{
                        puts("Not eligible for exam\n");
                    }
                }else{
                    puts("Not eligible for exam\n");
                }
        }
    }   
}

// function for eligible
void eligible(int n){
    int i;

    for(i=0;i<n;i++){
        if(st[i].attendance>=75){
            if(st[i].feestat=='y'){
                st[i].eligibility=1;
            }
        }
    }
    printf("\neligible students are \n");
    for(i=0;i<n;i++){
        if(st[i].attendance!=-1){
            if(st[i].eligibility==1){
                printf("roll nmber:%d  name:%s\n",st[i].rollnum,st[i].name);
            }
        }
    }
    puts("\n");

    printf("students who are not eligible \n");
    for(i=0;i<n;i++){
        if(st[i].attendance!=-1){
            if(st[i].eligibility==0){
                printf("roll nmber:%d  name:%s\n",st[i].rollnum,st[i].name);
            }
        }
    }

}

// function for updating the student details
void update(int n){
	int check,opt,k,search,newattendance;
	char newfeestat;
	// menu driven for updating the student record

    printf("\nwhich program to run\n");
    puts("Enter 1 for updating attendance percentage");
    puts("Enter 2 for updating feestatus ");
    puts("Enter 3 for updating attendance percentage and feestat");
        do{
            scanf("%d",&opt);
        }while(opt!=1&&opt!=2&&opt!=3);
    // updating the attendance percentage of a student record
    if(opt==1){
        printf("Enter the roll number:");
    do{
    	scanf("%d",&k);
	}while(k<0 || k>n);
	search=k-1;
	printf("Enter new attendance percentage: ");
	do{
		scanf("%d",&newattendance);
	}while(newattendance<0 || newattendance>100);
	st[search].attendance=newattendance;
	printf("Name :%s\n",st[search].name);
	printf("Rollnum :%d\n",st[search].rollnum);
	printf("Attendance percentage :%d\n",st[search].attendance);
	printf("Fee stat :%c\n",st[search].feestat);
    }
	// updating the feestat of a student record
    else if(opt==2){
         printf("Enter the roll number");
    do{
    	scanf("%d",&k);
	}while(k<0 || k>n);
	search=k-1;
	printf("Enter new fee feestatus: ");
	do{
    scanf("%c",&newfeestat);
    }while(newfeestat!='y'&& newfeestat!='n');
    st[search].feestat=newfeestat;
    printf("Name :%s\n",st[search].name);
    printf("Rollnum :%d\n",st[search].rollnum);
	printf("Attendance percentage :%d\n",st[search].attendance);
	printf("Fee feestatus :%c\n",st[search].feestat);
    }
    else if(opt==3){
	printf("Enter the roll number:");
    do{
    	scanf("%d",&k);
	}while(k<0 || k>n);
	search=k-1;
	printf("Enter new attendance percentage:");
	do{
		scanf("%d",&newattendance);
	}while(newattendance<0 || newattendance>100);
	st[search].attendance=newattendance;
	printf("Enter new fee feestatus:");
	do{
    scanf("%c",&newfeestat);
    }while(newfeestat!='y'&& newfeestat!='n');
    st[search].feestat=newfeestat;
    printf("Name :%s\n",st[search].name);
    printf("Rollnum :%d\n",st[search].rollnum);
	printf("Attendance percentage :%d\n",st[search].attendance);
	printf("Fee feestatus :%c\n",st[search].feestat);

}
}

// function for adding the student
void addstudent(int *n){
	int i,flag=1,x;
	x=*n;
	for(i=0;i<=x;i++)
	{
		if(st[i].attendance==-1){
			
				printf("\nEnter the details oF %d st student\n",i+1);
    			st[i].rollnum= i+1; 
    
    			printf("Enter Name:");    
    			scanf("%s",st[i].name); 
    
    			printf("Enter attendance percentage:"); 
   				do{
   				scanf("%d",&st[i].attendance); 
    			}while(st[i].attendance<0||st[i].attendance>100);
    
    			printf("Enter feestatus(y/n):"); 
    			do{
    			scanf("%c",&st[i].feestat); 
    			}while(st[i].feestat!='y'&& st[i].feestat!='n');
    
    			st[i].eligibility=0;
			    flag=0;
			    break;
		}
		
	}
	if(flag==1){
		    *n=*n+1;
		    
		    printf("\nEnter the details oF %d st student\n",x+1);
    			st[x].rollnum= x+1; 
    
    			printf("Enter Name:");    
    			scanf("%s",st[x].name); 
    
    			printf("Enter attendance percentage:"); 
   				do{
   				scanf("%d",&st[x].attendance); 
    			}while(st[x].attendance<0||st[x].attendance>100);
    
    			printf("Enter feestatus(y/n):"); 
    			do{
    			scanf("%c",&st[x].feestat); 
    			}while(st[x].feestat!='y'&& st[x].feestat!='n');
    
    			st[x].eligibility=0;
		}
}
