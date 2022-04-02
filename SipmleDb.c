
#include "SimpleDb.h"

u8  id_list[10];
u8 * id_list_ptr=&id_list;
u8 id_list_size;
u8 * id_list_size_ptr=&id_list_size;


Boolean SDB_IsFull(void)
{

  u8 counter=0;
  for(u8 i=0;i<10;i++){
      if (Struct_array[i].Student_ID!=0 )
          counter ++;
      else
          break;
  }
   if (counter==10)
      return TRUE;
   else
      return FALSE;
}


u8 SDB_GetUsedSize(void)
{
  u8 counter=0;
  for(u8 i=0;i<10;i++)
    {
     if (Struct_array[i].Student_ID!=0 )
        counter ++;
    }
  return counter;
}


Boolean SDB_AddEntry(u8 id,u8 year,u8 *subjects,u8 *grades)
{

  Boolean flag=FALSE;
  Boolean flagIsFull=SDB_IsFull();
  if (flagIsFull==TRUE)
      printf("%s\n","the database is full");
  else
    {
      u8 index=0;
      for(u8 i=0;i<10;i++)
        {
         if(Struct_array[i].Student_ID==0)
         {
            index=i;
            break;
         }
        }
     Struct_array[index].Student_ID=id;
     Struct_array[index].Student_Year=year;
     id_list[index]=id;
     id_list_size=id_list_size+1;

     for(u8 j=0;j<3;j++)
     {
        Struct_array[index].Course_ID[j]=*(subjects+j);
        if(*(grades+j)>=0 && *(grades+j)<=100 )

           Struct_array[index].Course_Grade[j]=*(grades+j);
        else
        {
           printf("%s\n","the grade is not valid");
           SDB_DeleteEntry(id);
        }
    }



    if(Struct_array[index].Student_ID==id && Struct_array[index].Student_Year==year)
    {
        for(u8 j=0;j<3;j++)
            {
            if( Struct_array[index].Course_ID[j]!=*(subjects+j)|| Struct_array[index].Course_Grade[j]!=*(grades+j))
                {
                    flag=FALSE;
                    break;
                 }
                 else
                    flag=TRUE;
            }
    }
  }
    return flag;
}


Boolean SDB_ReadEntry(u8 id,u8* year,u8 *subjects,u8 *grades)
{
  Boolean flag=FALSE;
  for(u8 i=0;i<10;i++)
    {
      if(Struct_array[i].Student_ID==id && Struct_array[i].Student_Year==*year)
      {
            for(u8 j=0;j<3;j++)
            {
                 if( Struct_array[i].Course_ID[j]!=*(subjects+j)|| Struct_array[i].Course_Grade[j]!=*(grades+j))
                 {
                    flag=FALSE;
                    break;
                 }
                else
                    flag=TRUE;
            }
     }
   }
  return flag;
}


void SDB_GetIdList(u8 *count,u8 *arr)
{

    printf("%s %d\n","the number of entries currently exist in the database is :",*count);
    printf("%s","the ID list :");
    for(u8 i=0;i<10;i++)
    {
        if(i==0)
           printf("%c",'{');
        if(*(arr+i) !=0 && i!=(*count-1))
           printf("%d %c",*(arr+i),',');
        else if(*(arr+i) !=0 )
             printf("%d ",*(arr+i));
        if(i==9)
           printf("%c \n",'}');

    }
}



Boolean SDB_IsIdExist(u8 id)
{
  Boolean flag=FALSE;
  for(u8 i=0;i<10;i++)
    {
     if (Struct_array[i].Student_ID==id )
     {
        flag=TRUE;
        break;
    }
    }
  return flag;
}


void SDB_DeleteEntry(u8 id)
{

  for(u8 i=0;i<10;i++)
   {
     if (Struct_array[i].Student_ID==id )
       {

           Struct_array[i].Student_ID=0;
           Struct_array[i].Student_Year=0;
           id_list[i]=0;
           id_list_size=id_list_size-1;

           for (u8 j=0;j<3;j++)
            {
             Struct_array[i].Course_ID[j]=0;
             Struct_array[i].Course_Grade[j]=0;
            }

       }
    }
}


void print_database(void)
{
     for(u8 i=0;i<10;i++)
        {

        printf("%c",'{');
        printf("%d %c",Struct_array[i].Student_ID,',');
        printf("%d %c",Struct_array[i].Student_Year,',');

        for (u8 j=0;j<3;j++)
            {
            if (j==0)
                printf("%c",'{');

            if(j!=2)
                printf("%d %c", Struct_array[i].Course_ID[j],',');

            if(j==2)
                {
                printf("%d", Struct_array[i].Course_ID[j]);
                printf("%c %c",'}',',');
                }
           }
        for (u8 k=0;k<3;k++)
            {
            if (k==0)
                printf("%c",'{');

            if (k!=2)
                printf("%d %c", Struct_array[i].Course_Grade[k],',');

            if(k==2)
                {
                printf("%d", Struct_array[i].Course_Grade[k]);
                printf("%c %c",'}','}');
                if(i!=9)
                  printf("%c",',');
                 }
            }

        }
}
