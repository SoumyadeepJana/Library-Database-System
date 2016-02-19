//c++ program using linked lists
//author:Soumyadeep Jana
//compiled in Borland c++

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<fstream.h>

struct Book
{
   int     book_no;
   char    book_name[30];
   char    pub[30];
   char    author[30];
   int     nop;
   int     stat;
   Book    *next;
};

struct Member
{
    char    name[30];
    int     age;
    char     phn[10];
    int     stat;
    int     card;
    Member  *next;
};


//To write all the book details and member details in files during termination of the program.
void end(Book *bstart, Member *mstart, int k)
{

     ofstream  fout;
     Book      *bptr = bstart;
     Member    *mptr = mstart;
     fout.open("lib_book.dat",ios::binary);

     while(bptr != NULL)
     {
	  fout.write((char *)bptr,sizeof(Book));
	  bptr = bptr->next;
     }
     fout.close();

     fout.open("lib_memb.dat",ios::binary);

     while(mptr != NULL)
     {
	  fout.write((char *)mptr,sizeof(Member));
	  mptr = mptr->next;
     }
     fout.close();

     fout.open("crd_no.dat");
     fout<<k;
     fout.close();

}


//To fetch all the book records from the file and store it in a list for processing.
Book * start_book(Book *bstart)
{
   ifstream fin;

   fin.open("lib_book.dat",ios::binary);
   fin.seekg(0,ios::end);
   int len=fin.tellg();
   if(len>0)
   {
      int i=0;
      fin.seekg(0,ios::beg);
      while(i<(len/sizeof(Book)))
      {
	i++;
	Book *node = new Book;
	fin.read((char *)node,sizeof(Book));
	node->next=NULL;

	if(bstart == NULL)
	   bstart =  node;
	else
	{

	    Book *bptr = bstart;
	    while(bptr->next != NULL)
	       bptr = bptr->next;
	    bptr->next = node;
	}
      }
   }
   fin.close();
   return bstart;
}



////To fetch all the members records from the file and store it in a list for processing.
Member * start_member(Member *mstart)
{

   ifstream fin;
   fin.open("lib_memb.dat",ios::binary);
   fin.seekg(0,ios::end);
   int len = fin.tellg();

   if(len>0)
   {
      int i=0;
      fin.seekg(0,ios::beg);
     while(i<(len/sizeof(Member)))
     {
	i++;
	Member *node = new Member;
	fin.read((char *)node,sizeof(Member));
	node->next = NULL;

	if(mstart == NULL)
	   mstart =  node;
	else
	{

	    Member *mptr = mstart;
	    while(mptr->next != NULL)
	       mptr = mptr->next;
	    mptr->next = node;
	}
     }
   }
   fin.close();
   return mstart;

}


//To add new books 
Book * add_book(Book *bstart)
{
       Book *btemp = new Book;
       Book *bptr;

	       if(btemp == NULL)
		  cout<<"MEMORY FULL"<<endl;
	       else
		 {
		     cout<<"\t\tEnter the name of book:";
		     gets(btemp->book_name);
		     cout<<"\t\tEnter the name of publishers:";
		     gets(btemp->pub);
		     cout<<"\t\tEnter name of author:";
		     gets(btemp->author);
		     cout<<"\t\tEnter total no of pages:";
		     cin>>btemp->nop;
		     cout<<"\t\tEnter book no:";
		     cin>>btemp->book_no;
		     btemp->next=NULL;

		     btemp->stat = 1;

		    if(bstart == NULL)
		    {
		       bstart = btemp;
		    }
		    else
		    {
		       bptr=bstart;
		       while(bptr->next != NULL)
			  bptr = bptr->next;
		       bptr->next = btemp;
		    }
		    gotoxy(20,20);
		    cout<<"\t\t Book Successfully Added." <<endl;

		 }
     return bstart;
}


//To add new members.
Member * add_member(Member *mstart, int  &k)
{

	       Member *mtemp = new Member;

	       if(mtemp == NULL)
	       {
		  cout<<"MEMORY FULL"<<endl;
	       }

	       else
		 {
		     cout<<"\t\tEnter the name of member:";
		     gets(mtemp->name);
		     cout<<"\t\tEnter the age:";
		     cin>>mtemp->age;
		     cout<<"\t\tEnter phone no:";
		     gets(mtemp->phn);
		     mtemp->stat=0;
		     mtemp->card=k;
		     mtemp->next = NULL;
		     k++;
		     cout<<"\t\tCard no.:"<<mtemp->card;

		    if(mstart == NULL)
		    {mstart = mtemp;}

		    else
		    {
		       Member *mptr = mstart;
		       while(mptr->next != NULL)
			  mptr = mptr->next;
		       mptr->next = mtemp;

		    }
		    gotoxy(20,20);
		    cout<<"Member added successfully"<<endl;
		 }
		 return mstart;

}


//To view the list of books.
void view_book(Book *bstart)
{

	       textcolor(WHITE);

	       if(bstart == NULL)
	       {
		    cout<<"List empty"<<endl;
	       }

	       else
	       {
		   Book *bptr = bstart;

		   while(bptr != NULL)
		   {
		      cout<<"\tName of book:"<<bptr->book_name<<endl;
		      cout<<"\tName of publishers:"<<bptr->pub<<endl;
		      cout<<"\tName of author:"<<bptr->author<<endl;
		      cout<<"\tTotal no of pages:"<<bptr->nop<<endl;
		      cout<<"\tBook no:"<<bptr->book_no<<endl;
		      cout<<"\tBook status:"<<bptr->stat<<endl;

		      bptr=bptr->next;
		      textcolor(RED);
		      cprintf("_________________________________________________");
		      cout<<endl;
		  }

	       }
}


//To view the list of members.
void view_member(Member *mstart)
{
	      if(mstart == NULL)
		    cout<<"\t\tList empty"<<endl;

	       else
	       {
		   Member *mptr = mstart;

		   while(mptr != NULL)
		   {
		       cout<<"\tName of member:"<<mptr->name<<endl;
		       cout<<"\tAge:"<<mptr->age<<endl;
		       cout<<"\tPhone no:"<<mptr->phn<<endl;
		       cout<<"\tCard Number:"<<mptr->card<<endl;
		       cout<<"\tBook issued:"<<mptr->stat<<endl;

		       mptr = mptr->next;
		       textcolor(RED);
		       cprintf("_______________________________________________");
		       cout<<endl;
		   }

	       }
}

//To issue book to a member.
void issue_book(Member *mstart)
{

	      int crd,bno;
	      Member *mptr;

	      cout<<"\t\tEnter card no to issue:";
	      cin>>crd;

	      mptr = mstart;

	      while(mptr != NULL)
	      {
		 if(mptr->card == crd)
		    break;
		 mptr=mptr->next;
	      }

	      if(mptr != NULL)
	      {
		  if(mptr->stat == 0)
		  {
		     cout<<"\t\tEnter book no:";
		     cin>>bno;
		   //  cout<<"Enter today's date:";
		    // cin>>d.day>>d.month>>d.year;
		     cout<<"\t\tISSUE SUCCESSFULL"<<endl;
		    // cout<<"Return date:"<<showDate(d)<<endl;
		     mptr->stat=bno;
		  }
		  else
		    cout<<"\t\tNot eligible to issue"<<endl;
	      }

	      else
		cout<<"\t\tCard no. not matched"<<endl;
}


//To return book
void return_book(Member *mstart)
{

	      int crd;
	      Member *mptr;

	      cout<<"\t\tEnter card no to issue:";
	      cin>>crd;

	      mptr = mstart;
	      while(mptr != NULL)
	      {
		 if(mptr->card == crd)
		    break;
		 mptr = mptr->next;
	      }

	      if(mptr != NULL)
	      {
		  if(mptr->stat > 0)
		  {
		     cout<<"\t\tBook no. of the book to be returned:"<<mptr->stat<<endl;
		     mptr->stat = 0;
		     cout<<"\t\tReturn successfull"<<endl;
		  }

		  else
		    cout<<"\t\tYou have no book to return"<<endl;
	     }

	     else
		cout<<"\t\tCard no. not matched"<<endl;
}


//To modify the details of the members.
void modify_member(Member *mstart)
{

	      int c;
	      Member *mptr;
	      mptr = mstart;

	      cout<<"\t\tEnter card no:";
	      cin>>c;

	      while(mptr != NULL)
	      {
		 if(mptr->card == c)
		     break;
		 mptr = mptr->next;
	      }

	      if(mptr != NULL)
	      {
		    cout<<"\t\tEnter name:";
		    gets(mptr->name);
		    cout<<"\t\tEnter age:";
		    cin>>mptr->age;
		    cout<<"\t\tEnter phone no:";
		    gets(mptr->phn);
	      }

	      else
	      {
		cout<<"\t\tCard no. not matched"<<endl;
	      }
}




void main()
{
   clrscr();
   int ch;
   Book  *bstart;
   Member *mstart;
   bstart =  NULL;
   mstart =  NULL;

   bstart = start_book(bstart);
   mstart = start_member(mstart);


   int k;
   ifstream fin;
   fin.open("crd_no.dat");
   fin.seekg(0,ios::end);
   int len = fin.tellg();
   fin.seekg(0,ios::beg);

   if(len > 0)
   {
       fin>>k;
       k++;
   }

   else
       k = 1000;



   do
   {  clrscr();
      gotoxy(25,1);
      cout<<"__________________________"<<endl;
      gotoxy(27,2);
      textcolor(RED);
      cprintf("WELCOME TO MY LIBRARY");
      cout<<endl;
      gotoxy(25,3);
      cout<<"__________________________"<<endl;
      gotoxy(10,5);
      textcolor(CYAN);
      cprintf("1.Add Books");
      cout<<endl;
      gotoxy(50,5);
      textcolor(GREEN);
      cprintf("2.Add Members");
      cout<<endl;
      gotoxy(10,7);
      textcolor(MAGENTA);
      cprintf("3.View all Books");
      cout<<endl;
      gotoxy(50,7);
      textcolor(YELLOW);
      cprintf("4.View all Members");
      cout<<endl;
      gotoxy(10,9);
      textcolor(BROWN);
      cprintf("5.Issue Books");
      cout<<endl;
      gotoxy(50,9);
      textcolor(BLUE);
      cprintf("6.Return Books");
      cout<<endl;
      gotoxy(25,12);
      textcolor(DARKGRAY);
      cprintf("7.Modify Membership Details");
      cout<<endl;
      gotoxy(25,14);
      textcolor(LIGHTBLUE);
      //cprintf("8.Cancel memberhip");
      //cout<<endl;
      gotoxy(30,16);
      cout<<"9.QUIT"<<endl;
      gotoxy(2,18);
      cout<<"Enter your choice : ";
      cin>>ch;

      switch(ch)
      {
	 case 1:
	       clrscr();
	       bstart = add_book(bstart);
	       getch();
	       break;


	 case 2:
	       clrscr();
	       mstart = add_member(mstart,k);
	       getch();
	       break;


	 case 3:
	       clrscr();
	       view_book(bstart);
	       getch();
	       break;



	 case 4:
	       clrscr();
	       view_member(mstart);
	       getch();
	       break;

	case 9:
	      clrscr();
	      gotoxy(40,12);
	      textcolor(RED);
	      cprintf("_________");
	      gotoxy(40,13);
	      cprintf("GOOD BYE");
	      gotoxy(40,14);
	      cprintf("_________");
	      cout<<endl;
	      sleep(2);
	      break;


	case 5:
	      clrscr();
	      issue_book(mstart);
	      getch();
	      break;



	case 6:
	      clrscr();
	      return_book(mstart);
	      getch();
	      break;

	case 7:
	      clrscr();
	      modify_member(mstart);
	      getch();
	      break;

	case 8:
	      clrscr();
	     // delete_book(bstart);
	      getch();
	      break;




	default:
	   cout<<"Wrong choice"<<endl;
      }

   }while(ch != 9);

   end(bstart,mstart,k);

}

