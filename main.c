
#include "SimpleDb.h"

extern u8 id_list;
extern u8 * id_list_ptr;
extern u8 id_list_size;
extern u8 * id_list_size_ptr;

/*
the warning is about the function Boolean SDB_AddEntry(u8 id,u8 year,u8 *subjects,u8 *grades);
it tells initialization from incompatible pointer type (argument 3 and 4 because they are both pointers to array)
which means that this IDE understands the syntax of a pointer to an array as int (*ptr)[size]
but when I wrote with this syntax, it gives a warning which tells
initialization from passing an argument of 'SDB_AddEntry' from incompatible pointer type (argument 3 and 4 because they are both pointers to array)
but I left it as given in the description because the name of the array is a pointer to the first element in the array so it works correctly
Also, it repeats the warning with every created entry (argument 3 and 4 because they are both pointers to array)
we here created 13 entries so the warning is repeated 26 times
*/

int main(){
/*
test 1
adding the first entry to the array
*/
u8 id[3]={1,2,3};
u8 *ptrid=&id;
u8 g[3]={70,80,90};
u8 *ptrg=&g;
SDB_AddEntry(1,3,ptrid,ptrg);

/*
adding the second entry to the array
*/
u8 id2[3]={4,5,6};
u8 *ptrid2=&id2;
u8 g2[3]={75,88,99};
u8 *ptrg2=&g2;
SDB_AddEntry(2,2,ptrid2,ptrg2);

/*
adding the third entry to the array
*/
u8 id3[3]={7,8,9};
u8 *ptrid3=&id3;
/*
there is here a grade out of boundaries
so the entry will be deleted and will not be added and a message will be displayed saying that "the grade is not valid"
*/
u8 g3[3]={55,66,105};
u8 *ptrg3=&g3;
SDB_AddEntry(3,5,ptrid3,ptrg3);

/*
testing the SDB_IsFull function
the expected output is 0 because the array has only 2 entries
*/
Boolean IsFull=SDB_IsFull();
printf("%s%d\n","SDB_IsFull() =",IsFull);

/*
testing the SDB_GetUsedSize function
the expected output is 2 because the array has only 2 entries
*/
u8 size=SDB_GetUsedSize();
printf("%s%d\n","SDB_GetUsedSize() =",size);

print_database();

/*
test 2
adding the third entry to the array
*/
u8 id4[3]={1,2,3};
u8 *ptrid4=&id4;
u8 g4[3]={50,85,99};
u8 *ptrg4=&g4;
SDB_AddEntry(4,3,ptrid4,ptrg4);

/*
adding the fourth entry to the array
*/
u8 id5[3]={4,5,6};
u8 *ptrid5=&id5;
u8 g5[3]={65,88,99};
u8 *ptrg5=&g5;
SDB_AddEntry(5,5,ptrid5,ptrg5);

/*
adding the fifth entry to the array
*/
u8 id6[3]={7,8,9};
u8 *ptrid6=&id6;
u8 g6[3]={55,66,80};
u8 *ptrg6=&g6;
u8 year6=1;
u8 *ptryear6=&year6;
SDB_AddEntry(6,1,ptrid6,ptrg6);

/*
testing the SDB_ReadEntry function
the expected output is 1 because the entry exists
*/
Boolean Read=SDB_ReadEntry(6,ptryear6,ptrid6,ptrg6);
printf("\n\n%s%d\n","SDB_ReadEntry()=",Read);

/*
testing the SDB_IsFull function
the expected output is 0 because the array has only 5 entries
*/
Boolean IsFull2=SDB_IsFull();
printf("%s%d\n","SDB_IsFull() =",IsFull2);

/*
testing the SDB_GetIdList function
the expected output is 5 which is th number of the IDs and it will return the ID list which is 1,2,4,5,6
*/
SDB_GetIdList(id_list_size_ptr,id_list_ptr);

print_database();

/*
test 3
adding the sixth entry to the array
*/
u8 id7[3]={1,3,2};
u8 *ptrid7=&id7;
u8 g7[3]={60,75,82};
u8 *ptrg7=&g7;
SDB_AddEntry(7,2,ptrid7,ptrg7);

/*
adding the seventh entry to the array
*/
u8 id8[3]={4,6,5};
u8 *ptrid8=&id8;
u8 g8[3]={65,77,86};
u8 *ptrg8=&g8;
SDB_AddEntry(8,5,ptrid8,ptrg8);

/*
adding the eighth entry to the array
*/
u8 id9[3]={7,9,8};
u8 *ptrid9=&id9;
u8 g9[3]={55,66,80};
u8 *ptrg9=&g9;
SDB_AddEntry(9,1,ptrid9,ptrg9);

/*
testing the SDB_GetUsedSize function
the expected output is 8 because the array has 8 entries
*/
u8 size2=SDB_GetUsedSize();
printf("\n\n%s%d\n","SDB_GetUsedSize() =",size2);

/*
testing the SDB_IsIdExist function
the expected output is 1 because the ID exists
*/
Boolean IDexist=SDB_IsIdExist(9);
printf("%s%d\n","SDB_IsIdExist()=",IDexist);

/*
testing the SDB_DeleteEntry function
*/
SDB_DeleteEntry(9);

/*
testing the SDB_IsIdExist function
the expected output is 0 because the ID has been deleted
*/
Boolean IDexist2=SDB_IsIdExist(9);
printf("%s%d\n","after deleting this entry, SDB_IsIdExist()=",IDexist2);

/*
testing the SDB_GetUsedSize function
the expected output is 7 because the eighth ID has been deleted
*/
u8 size3=SDB_GetUsedSize();
printf("%s%d\n","SDB_GetUsedSize() =",size3);

/*
testing the SDB_IsFull function
the expected output is 0 because the array has 7 entries
*/
Boolean IsFull3=SDB_IsFull();
printf("%s%d\n","SDB_IsFull() =",IsFull3);

print_database();

/*
case 4
adding the eighth entry to the array
*/
u8 id10[3]={2,3,1};
u8 *ptrid10=&id10;
u8 g10[3]={90,85,92};
u8 *ptrg10=&g10;
SDB_AddEntry(10,4,ptrid10,ptrg10);

/*
adding the ninth entry to the array
*/
u8 id11[3]={5,6,4};
u8 *ptrid11=&id11;
u8 g11[3]={95,76,66};
u8 *ptrg11=&g11;
SDB_AddEntry(11,5,ptrid11,ptrg11);

/*
adding the tenth entry to the array
*/
u8 id12[3]={8,9,7};
u8 *ptrid12=&id12;
u8 g12[3]={85,76,90};
u8 *ptrg12=&g12;
SDB_AddEntry(12,1,ptrid12,ptrg12);

/*
testing the SDB_GetUsedSize function
the expected output is 10 because the array has 10 entries
*/
u8 size4=SDB_GetUsedSize();
printf("\n\n%s%d\n","SDB_GetUsedSize() =",size4);

/*
testing the SDB_IsFull function
the expected output is 1 because the array has 10 entries which is the maximum size of the database
*/
Boolean IsFull4=SDB_IsFull();
printf("%s%d\n","SDB_IsFull() =",IsFull4);

/*
testing the SDB_GetIdList function
the expected output is 10 which is th number of the IDs and return the ID list which is 1,2,4,5,6,7,8,10,11,12
the ID 3 was deleted because it has a grade =105 which is outof boundary and we deleted ID 9 to test the SDB_DeleteEntry function
*/
SDB_GetIdList(id_list_size_ptr,id_list_ptr);

/*
adding another entry but the array is now full so we are expecting that it will not be added
the SDB_AddEntry function checks first if the array is full, it will display a message saying that "the database is full",
otherwise the entry wil be added
*/
u8 id13[3]={8,9,7};
u8 *ptrid13=&id13;
u8 g13[3]={85,76,90};
u8 *ptrg13=&g13;
SDB_AddEntry(13,1,ptrid13,ptrg13);

/*
testing the SDB_GetIdList function
the expected output is 10 which is th number of the IDs and it will return the ID list which is 1,2,4,5,6,7,8,10,11,12
as the last entry  will not be added because the database is full
*/
SDB_GetIdList(id_list_size_ptr,id_list_ptr);

/*
expected output is to print database without the last entry
*/
print_database();

return 0;
}




