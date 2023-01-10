#include <iostream>  //libraries to be edited
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <cstring>
#include <unistd.h>
#include <windows.h> // sleep
#include <cctype> // to uppper
#include <fstream>
#include <cstdlib> //rand function
#include <sstream> // to convert int -> string
using namespace std ;
void main_menu();
void us();


                                       

	
void us ()
	{
		system ("cls");
		int count ;
		for(count = 0;count<1;count++)
		{
			Sleep(50);
			cout << "\n\n\n\n" ;
			Sleep(50);
			cout << "|----------------------------------------------------------------|" << endl ;
			Sleep(50);
			cout << "|                HOSPITAL MANAGEMENT SYSTEM                      |" << endl ;
			Sleep(50);
			cout << "|                                                                |" << endl ;
			Sleep(50);
			cout << "|                ABBAS DOSSA 20K-1660                            |" << endl ;
			Sleep(50);
			cout << "|                MUHAMMAD BASIT 20K-1622                         |" << endl ;
			Sleep(50);
			cout << "|                MAAZ HAIDER 20K-1727                            |" << endl ;
			Sleep(50);
			cout << "|----------------------------------------------------------------|" << endl ;
			Sleep(50);
			cout << "\n\n\n\n" ;
		}
	}

class human         //main  class all ther class inherited
{
	protected : 
	
		string name ;
    	long int ID ;  //patient ID OR DOCTOR ID 
    	int age ;
    	string address ;
    	long long int phoneNumber ;
    	string email ;
  	
	public  : 
		
		
		virtual void check_detail_menu () =0 ;
		human ()
		{
			ID=0 ;
			phoneNumber=0 ;
		}
		void set_name (const string nm)
		{
			this->name=nm;
		}
		string get_name () const 
		{
			return name ;
		}
		void set_age (const int age)
		{
			this->age=age ;
		}
		int get_age () const 
		{
			return age ;
		}
		void set_email ( const string em)
		{
			this->email=em;
		}
		string get_email () const 
		{
			return email ;
		}
		void set_ID ( const long int i)
		{
			this->ID=i;
		}
		void set_add ( const string x)
		{
			this->address=x;
		}
		string get_add () const 
		{
			return address ;
		}
		void set_phoneNumber ( const long int y )
		{
			this->ID=y;
		}
		long int get_phoneNumber () const 
		{
			return phoneNumber ;
		}

		
		
		 
		
		
		
};

class doctor : protected human 
{
	private :
		string department ;
		string firstName ;
		string lastName ;
		string password ;
		string MRnumber ;
		int patientWeight ;
		float costOfSurgery ;
	public :
	
		doctor ()
		{
			costOfSurgery =0.0 ;
			department ="";
			firstName ="";
			lastName ="";
			password ="";
			MRnumber ="";
			patientWeight =0;
		}
		void docMenu ()
		{
			system("cls");
			cout << "\t"<< " :: DOCTORS MENU :: " << "\t" ;
			cout << "\n\n\n";
			cout << " 1- CHECK PATIENT INFO " << endl;  //details // appointment // invoice 
			cout << "\n\n\n";
			cout << " 2- MAKE PRESCRIPTION FOR PATIENT " << endl ;
			cout << "\n\n\n";
			cout << " 3- CHECK APPOINTMENTS BOOKED "<< endl ;
			cout << "\n\n\n";
			cout << " 4- SCHEDULE A SURGERY" << endl ;
			cout << "\n\n\n" ;
			cout << " 5- CHECK DOCTOR MR# NUMBER  " << endl ;
			cout << "\n\n\n" ;
			cout << " 6- CHECK MEDICINE AVAILED " << endl ;
			cout << "\n\n\n";
			cout << " 7- GO BACK" << endl ;
			char ch= getch();
			if (ch==49)
			{
				check_detail_menu () ;		
			}
			else if ( ch == 50 )
			{
				doc_prescription ();
			}
			else if ( ch == 51 )
			{
				check_patient_appointments () ;	
			} 
			else if ( ch == 52)
			{
				schedule_surgery();
			}
			else if ( ch == 53)
			{
				check_MR () ;
			}
			else if ( ch == 54)
			{
				check_med_availed ();
			}
			else if ( ch == 55)
			{
				main_menu();
			}
			else 
			{
				docMenu ();
			}
		}
		
		
		void check_med_availed ()
		{
			system("cls");
			cout << "ENTER MR# NUMBER : " << endl ;
			cin >> MRnumber ;
			
			ifstream obj ;
			obj.open((MRnumber +"med" +".txt").c_str());
			string tr ;
			while ( getline(obj, tr))
			{
				cout << tr << endl ;
			}
			
			obj.close();
			cout << "PRESS ENTER TO GO BACK : " << endl ;
			char chu ;
			chu=getch();
			if ( chu == 49)
			{
				docMenu();
			}
			else{docMenu();
			}
		}
		void check_detail_menu () 
		{
			system("cls");
			cout << "\t" << " :: PATIENT DETAILS :: " << "\t" << "\n\n" ;
			cout << " :: 1 - ENTER ID  ::  2 - GO BACK  :: " << endl ;
			char chu ;
			long int l ;
			string s1,k;
			chu =getch();
			if ( chu == 49 )
			{
				system("cls");
				cout << "ENTER : " ;	
				cin >> l ;
				set_ID (l);
				ostringstream strg;
				strg<< ID ;
				s1 = strg.str();	
				string ch ;
				ch= s1 + "details";
			
				ifstream obj ;
				obj.open((ch+".txt").c_str());  //wouldnt work with c_str ?
				if ( obj == NULL )
				{
					cout << " WRONG PATIENT ID ENTERED " << endl;
					check_detail_menu () ; 
				}
				while ( getline(obj,k))
				{
					cout << k << endl;
				}
				obj.close();
				
				cout << "PRESS ENTER TO GO BACK " << endl;
				chu=getch();
				if ( chu==13)
				{
					docMenu();
				}
			}
			else if ( chu == 50)
			{
				docMenu();
			}
			else {
				docMenu();
			}
			
		}
		void doc_prescription () 
		{
			system("cls");
			char chu;
			int x,s,sel=0;
			string s1,cr,temp,temp2,temp3;
			cout << "\t" << " :: PRESCRIPTION :: " << "\t" << "\n\n\n" ;
			cout << "ENTER PATIENT ID TO EVALUATE : "  ;
			cin >> ID ;
			ostringstream strg;
			strg<< ID ;
			s1 = strg.str();	
			string ch ;
			ch = s1 + "details" ;
			ifstream obj ;
			obj.open((ch + ".txt").c_str());
			if ( obj != NULL)
			{
				cout << "\t\t"<<"ID SUCCESSFULLY MATCHED " << "\t"<< "\n\n\n" ;
				obj.close();
				ch= s1 + "prescription";
				fstream obj2 ,obj9;
				obj2.open((ch + ".txt").c_str() , ios :: app);
				obj9.open((ch + ".txt").c_str() , ios :: in);
				if ( obj2 == NULL )
				{
					cout << "NO FILE " << endl ;docMenu();
				}
				
				
				obj2 << " :: DOCTORS PRESCRIPTION :: " << endl ;
				obj2 << "\n\n" ;
				obj2 << " PATIENT ID : " << ID << "\n\n" ;
				cout << "Enter weight : " ;
				cin >> patientWeight ;
				obj2 << "PATIENT WEIGHT : "<< patientWeight<< endl ; 
				obj2 << "\n\n" ;
				
				if (1)
				{
					while (1)
					{	system("cls");
						cout <<"\n"<< "CHOOSE WHAT DO YOU WANT TO ENTER : " << endl ;
						cout << "\n" ;
						cout << " 1- DIAGNOS A PATIENT " << endl ;
						cout << "\n" ;
						cout << " 2- WRITE MEDICATION  " << endl ;
						cout << "\n" ;
						cout << " 3- PRESCRIBE A SURGERY " << endl ;
						cout << "\n" ;
						cout << " 4- REFER TO ANOTHER DOCTOR " << endl ;
						cout << "\n" ;
						cout << " 5- PROVIDE A DIET PLAN " << endl ;
						cout << "\n" ;
						cout << " 6- WRITE BLOOD TESTS " << endl ;
						cout << "\n" ;
						cout << " 7- END " ;
						chu =getch() ;
						fflush(stdin);
						if ( chu == 49)
						{
							system("cls");
							cout << " :: DIAGNOS A PATIENT :: " << "\n\n" ;
							cout << " ENTER THE DISEASE : " << endl ;
							getline (cin,temp) ;
							obj2 <<"\n\n" << "DIAGNOS : " << endl ;
							obj2 << temp << "\n" ; 
						}
						else if ( chu == 50)
						{
							system("cls");
							cout << " :: MEDICATION FOR A PATIENT :: " << "\n\n" ;
							cout << " ENTER NUMBER OF MEDICINES : "  ;
							obj2 <<"\n\n" <<" MEDICATION : " << endl ;
							
							cin >> x ;
							cout << "\n";
							for ( int i=0 ; i<x ; i++)
							{
								cout << "ENTER MEDICINE "<< i+1 << ": "  ;
								getline (cin, temp) ;
								fflush(stdin);
								obj2 << "MEDICINE# " << i+1 << ":" << temp << endl;
								cout << "ENTER DOSAGE AND TIME :" ;
								getline (cin , temp) ; 
								obj2 <<  "DOSAGE AND TIME : " << temp << endl ;
							}
							
						}
						else if ( chu == 51)
						{
							system("cls");
									string x;
			cout <<"\t\t"<< " :: PRESCRIBE A SURGERY :: " << "\t\t" << "\n\n\n\n";
			obj2 << "PRESCRIBE A SURGERY : " << "\n" ;
			cout << "CHOOSE DOCTOR'S DEPARTMENT : " <<endl;
			cout << "1 - ONCOLOGY " << endl ;
			cout << "2 - RADIOLOGY " << endl ;
			cout << "3 - DENTAL " << endl ;
			cout << "4 - KIDNEY " << endl ;
			cout << "5 - EYE,EAR,NOSE " << endl ;
			cout << "6 - NEUROLOGY " << endl ;
//			cout << "7 - DERMATOLOGY " << endl ;
			cout << "7 - CARDIOLOGY " << endl ;
			cout << "\n\n" << " 8 - GO BACK " << "\n\n" ;
			char chu ;
			chu=getch();
			if ( chu == 49 )
			{	system("cls");
				cout << "\t"<< " :: ONCOLOGY :: " << endl <<"\n\n";
				while (1){
				
				cout << " 1 - CYROSURGERY " << endl ;
				cout << " 2 - LASERS " << endl ;
				cout << " 3 - PHOTODYNAMIC THERAPY " << endl ;
				cout << " 4 - HYPERTHERMIA " << endl ;
				cout << " 5 - OTHER " << endl ;
				cout << " 6 - GO BACK " <<  endl ;
				char c ;
				c=getch();
				if (c== 49)
				{
					obj2 <<  "CYROSURGERY" << endl ;
					cout << " CYROSURGERY  ADDED " << endl ;
				}
				else if ( c== 50)
				{
					obj2 << "LASERS" << endl ;
					cout << "LASERS ADDED " << endl ;	
				}
				else if ( c== 51)
				{
					obj2 << "PHOTODYNAMIC THERAPY" << endl ;
					cout << "PHOTODYNAMIC THERAPY ADDED " << endl ;
				}
				else if ( c== 52)
				{
					obj2 << "HYPERTHERMIA" << endl ;
					cout << "HYPERTHERMIA ADDED " << endl ;
					
				}
				else if ( c == 53)
				{
					cout << "ENTER " << endl ;
					cin >> x ;
					obj2 << x << endl;
					cout << "ADDED" << endl ;
				}
				else if ( c== 54)
				{
					break ;
				}
				else 
				{
					break ;
				}
				
				}
			}
			else if ( chu == 50)
			{
				system("cls");
				cout <<"\t" << " :: RADIOLOGY :: " << "\t" << "\n\n" ;
				while (1)
				{
					
				
				cout << " 1 - endovascular treatment of aneurysms and tumors " << endl ;
				
				cout << " 2 - OTHER " << endl ;
				cout << " 3 - GO BACK " <<  endl ;
				char c ;
				c=getch();
				if (c== 49)
				{
					obj2 <<  " endovascular treatment of aneurysms and tumors" << endl ;
					cout << "  ADDED " << endl ;
				}
				
				else if ( c == 50)
				{
					cout << "ENTER " << endl ;
					cin >> x ;
					obj2 << x << endl;
					cout << "ADDED" << endl ;
				}
				else if ( c== 51)
				{
					break;
				}
				else 
				{
					break ;
				}
				
				}
			}
			else if ( chu == 51)
			{
				system("cls");
				cout << "\t\t" << " :: DENTAL :: " << "\t\t" << "\n\n" ;
				while (1){
				
				cout << " 1 - Root Canal " << endl ;
				cout << " 2 - Dental Implants " << endl ;
				cout << " 3 - Wisdom Tooth Extraction " << endl ;
				cout << " 4 - Reconstructive Surgery " << endl ;
				cout << " 5 - OTHER " << endl ;
				cout << " 6 - GO BACK " <<  endl ;
				char c ;
				c=getch();
				if (c== 49)
				{
					obj2 <<  "Root Canal " << endl ;
					cout << " Root Canal ADDED " << endl ;
				}
				else if ( c== 50)
				{
					obj2 << " Dental Implants " << endl ;
					cout << "Dental Implants ADDED " << endl ;	
				}
				else if ( c== 51)
				{
					obj2 << " Wisdom Tooth Extraction" << endl ;
					cout << "Wisdom Tooth Extraction ADDED " << endl ;
				}
				else if ( c== 52)
				{
					obj2 << "Reconstructive Surgery" << endl ;
					cout << "Reconstructive Surgery ADDED " << endl ;
					
				}
				else if ( c == 53)
				{
					cout << "ENTER " << endl ;
					cin >> x ;
					obj2 << x << endl;
					cout << "ADDED" << endl ;
				}
				else if ( c== 54)
				{
					break ;
				}
				else 
				{
					break ;
				}
				
				}//while
			}
			else if ( chu == 52)
			{
				system("cls");
				cout << "\t\t" << " :: KIDNEY :: " << "\t\t" << "\n\n" ;
				while (1){
				
				cout << " 1 - Laparoscopic surgery " << endl ;
				cout << " 2 - Radical nephrectomy " << endl ;
				cout << " 3 - Partial nephrectomy " << endl ;
			
				cout << " 4 - OTHER " << endl ;
				cout << " 5 - GO BACK " <<  endl ;
				char c ;
				c=getch();
				if (c== 49)
				{
					obj2 <<  " Laparoscopic surgery " << endl ;
					cout << " Laparoscopic surgery ADDED " << endl ;
				}
				else if ( c== 50)
				{
					obj2 << " Radical nephrectomy " << endl ;
					cout << "Radical nephrectomy ADDED " << endl ;	
				}
				else if ( c== 51)
				{
					obj2 << " Partial nephrectomy " << endl ;
					cout << "Partial nephrectomy ADDED " << endl ;
				}
				
				else if ( c == 52)
				{
					cout << "ENTER " << endl ;
					cin >> x ;
					obj2 << x << endl;
					cout << "ADDED" << endl ;
				}
				else if ( c== 53)
				{
					break ;
				}
				else 
				{
					break ;
				}
				
				}//while
			
			}
			else if ( chu== 53)
			{
				system("cls");
				cout << "\t\t" << " :: EYE , EAR , NOSE  :: " << "\t\t" << "\n\n" ;
				while (1){
				
				cout << " 1 - RETINAL RE-ATTACHMENT / DE-ATTACHMENT  " << endl ;
				cout << " 2 - CATARACT " << endl ;
				cout << " 3 - Acoustic Neuroma Surgery. " << endl ;
				cout << " 4 - Cochlear Implant " << endl ;
				cout << " 5 - Myringotomy Eardrum Repair " << endl ;
				cout << " 6 - Augmentation " << endl ;
				cout << " 7 - Rhinoplasty " << endl ;
				cout << " 8 - OTHER " << endl ;
				cout << " 9 - GO BACK " <<  endl ;
				char c ;
				c=getch();
				if (c== 49)
				{
					obj2 <<  " RETINAL RE-ATTACHMENT / DE-ATTACHMENT" << endl ;
					cout << " RETINAL RE-ATTACHMENT / DE-ATTACHMENT ADDED " << endl ;
				}
				else if ( c== 50)
				{
					obj2 << " CATARACT " << endl ;
					cout << "CATARACT ADDED " << endl ;	
				}
				else if ( c== 51)
				{
					obj2 << " Acoustic Neuroma Surgery " << endl ;
					cout << "Acoustic Neuroma Surgery ADDED " << endl ;	
				}
				else if ( c== 52)
				{
					obj2 << " Cochlear Implant " << endl ;
					cout << "Cochlear Implant ADDED " << endl ;	
				}
				else if ( c== 53)
				{
					obj2 << " Myringotomy Eardrum Repair " << endl ;
					cout << " Myringotomy Eardrum Repair ADDED " << endl ;	
				}
				else if ( c== 54)
				{
					obj2 << "Augmentation" << endl ;
					cout << " Augmentation ADDED " << endl ;
				}
				else if ( c== 55)
				{
					obj2 << " Rhinoplasty" << endl ;
					cout << "Rhinoplasty ADDED " << endl ;
					
				}
				else if ( c == 56)
				{
					cout << "ENTER " << endl ;
					cin >> x ;
					obj2 << x << endl;
					cout << "ADDED" << endl ;
				}
				else if ( c== 57)
				{
					break ;
				}
				else 
				{
					break ;
				}
				
				}
			}
			else if ( chu == 54)
			{
				system("cls");
				cout << "\t\t" << " :: NEUROLOGY :: " << "\t\t" << "\n\n" ;
				while (1){
				
				cout << " 1 - Craniotomy " << endl ;
				cout << " 2 - Deep brain stimulation (DBS) " << endl ;
				cout << " 3 - Neuroendoscopy " << endl ;
				cout << " 4 - Thrombectomy and cerebral aneurysm repair " << endl ;
				cout << " 5 - OTHER " << endl ;
				cout << " 6 - GO BACK " <<  endl ;
				char c ;
				c=getch();
				if (c== 49)
				{
					obj2 <<  "Craniotomy " << endl ;
					cout << " Craniotomy ADDED " << endl ;
				}
				else if ( c== 50)
				{
					obj2 << " Deep brain stimulation (DBS) " << endl ;
					cout <<  "Deep brain stimulation (DBS) ADDED " << endl ;	
				}
				else if ( c== 51)
				{
					obj2 << " Neuroendoscopy " << endl ;
					cout << " Neuroendoscopy ADDED " << endl ;
				}
				else if ( c== 52)
				{
					obj2 << " Thrombectomy and cerebral aneurysm repair." << endl ;
					cout << "Thrombectomy and cerebral aneurysm repair. ADDED " << endl ;
					
				}
				else if ( c == 53)
				{
					cout << "ENTER " << endl ;
					cin >> x ;
					obj2 << x << endl;
					cout << "ADDED" << endl ;
				}
				else if ( c== 54)
				{
					break ;
				}
				else 
				{
					break ;
				}
				
				}
			}
			else if ( chu ==55)
			{
				system("cls");
				cout << "\t\t" << " :: CARDIOLOGY  :: " << "\t\t" << "\n\n" ;
				while (1){
				
				cout << " 1 - Heart valve repair or replacement " << endl ;
				cout << " 2 - Maze surgery " << endl ;
				cout << " 3 - Aneurysm repair " << endl ;
				cout << " 4 - Heart transplant " << endl ;
				cout << " 5 - OTHER " << endl ;
				cout << " 6 - GO BACK " <<  endl ;
				char c ;
				c=getch();
				if (c== 49)
				{
					obj2 <<  "Heart valve repair or replacement " << endl ;
					cout << " Heart valve repair or replacement ADDED " << endl ;
				}
				else if ( c== 50)
				{
					obj2 << " Maze surgery " << endl ;
					cout <<  " Maze surgery ADDED " << endl ;	
				}
				else if ( c== 51)
				{
					obj2 << " Aneurysm repair " << endl ;
					cout << " Aneurysm repair ADDED " << endl ;
				}
				else if ( c== 52)
				{
					obj2 << " " << endl ;
					cout << " Heart transplant ADDED " << endl ;
					
				}
				else if ( c == 53)
				{
					cout << "ENTER " << endl ;
					cin >> x ;
					obj2 << x << endl;
					cout << "ADDED" << endl ;
				}
				else if ( c== 54)
				{
					break ;
				}
				else 
				{
					break ;
				}
				
				}
			}
			else if ( chu == 56)
			{
				docMenu();
			}
			else {
				doc_prescription ();
			}
						
						}
						else if ( chu == 52)
						{
							system("cls");
							obj2 << "\n\n" << "REFER ANOTHER DOCTOR TO PATIENT : " <<endl 
							;cout << " :: REFER A PATIENT :: " << "\n\n" ;
							cout << "ENTER DOCTORS NAME  : "  ;
							getline (cin , temp ) ;
							obj2 << "DOCTORS NAME : " << temp << endl ;
							cout <<endl<< "ENTERS DOCTORS DEPARTMENT : " ;
							getline (cin , temp ) ;
							obj2 << "DOCTORS DEPARTMENT : " << temp << endl ;
						}
						else if ( chu == 53)
						{
							system("cls");
							obj2 << "\n\n" << "DIET PLAN : " <<endl ;
							cout << " :: PROVIDE A DIET PLAN  :: " << "\n\n" ;
							cout << "ENTER DOCTORS DIET PLAN  : "  ;
							getline (cin , temp ) ;
							obj2 << temp << endl ;
						}
						else if ( chu == 54)
						{
							system("cls");
							obj2 << "\n\n" << " BLOOD TESTS :  " <<endl ;
							cout << "ENTER DOCTORS DEPARTMENT : " << endl ;
							cin  >> department ;
							fflush(stdin);
							cout << "ENTER DOCTOR'S MR# NUMBER : " << endl ;
							cin >> MRnumber ;
							ifstream obj4,obj5 ;
							obj4.open((department + ".txt").c_str());
							obj5.open((department +"2" + ".txt").c_str());
							if ( obj4 == NULL|| obj5 == NULL){
								cout << "no file" ; docMenu();
							}
							cout << "\t\t" << " :: DEPARTMENT MATCHED :: " << "\t" << "\n" ;
						
							while ( obj4 >> temp2 )
							{
								
								if (temp2 == MRnumber)
								{
									cout << "\t\t" << "MR# matched " << "\t" << "\n" ;
									obj4.seekg(0);
									getline (obj4 ,temp);
									cout << "WELCOME DCTOR " << temp << "\n\n" ;
									getch();
									sel =566 ;	
									break;	
								}
							}
							while ( obj5 >> temp3 )
							{
								if ( temp3 == MRnumber)
								{
									cout << "\t\t" << "MR# matched " << "\t" << "\n" ;
									obj5.seekg(0);
									getline (obj5 ,temp);
									cout << "WELCOME DCTOR " << temp << "\n\n" ;
									getch();
									sel =566 ;
									break;
								}
							}
							obj4.close();obj5.close();
							
							fstream obj6 ;
							obj6.open("BLOODREQUESTS.txt",ios :: app);
							obj6<< endl ;
							obj6<< ID << endl ;
							obj6.close();
							
							if  (sel == 566 )
							{
							
							cout << " :: PROVIDE BLOOD TESTS :: " << "\n\n" ;
							cout << " ENTER NUMBER OF BLOOD TESTS : " ;
							cin >> x ;
							
							ofstream obj3 ;
							ch = s1 + "lab" ;
							obj3.open((ch + ".txt").c_str());
							if (obj3 == NULL){cout << "no file " ; docMenu();
							}
							obj3 << "PATIENT ID # " <<ID << endl ;
							obj3 << "DOCTOR MR# NUMBER : " << MRnumber << endl ;
							for ( int i=0 ; i<x ; i++)
							{
								
								cout <<endl << "BLOOD TEST# " << i+1 << ":" ;
								fflush(stdin);
								getline (cin , temp) ;
								obj2 <<endl << "BLOOD TEST# " << i+1 << ":" ;
								obj2 << temp ;
								obj3 <<endl << "BLOOD TEST# " << i+1 << ":" ;
								obj3 << temp ;
							}
							
							obj3.close();
						
							}
						}
						else if ( chu == 55)
						{
							break ;
							
						}					
					}
					obj2.close ();
				}
				while (1){
				
				cout <<"\n"<< "PRESS ENTER TO GO BACK : " << endl ;
				chu=getch();
				if ( chu == 13)
				{
					docMenu();
					break;
				}
				else {
				}

				}
			}
		}
		
		
		void schedule_surgery () 
		{
			system("cls") ;
			char c ;
			int s=0;
			string ch ,s1 , str , temp="";
			cout << "\t\t" << " :: SCHEDULE SURGERY :: " << "\t\t" << "\n\n\n\n" ;
			cout << "ENTER PATIENT ID  : " ; 
			cin >> ID ;
			ostringstream strg; // to cnvert long int -> string 
			strg<< ID ;
			s1 = strg.str();	
			ch= s1 + "details";
			
			ifstream obj,obj2,obj3,obj4,obj5,obj6,obj7,obj8,obj9,obj10 ;
			obj.open((ch + ".txt").c_str());
			if ( obj != NULL )
			{
				obj.close();
				cout << "\t\t\t" << "id matched " << "\t" << endl ;
				cout << "ENTER DOCTOR'S MR# NUMBER  : "  << "\n\n";
				cin >>MRnumber;
				//oncology
				obj2.open("oncology.txt");
				if ( obj2 != NULL)
				{
					while ( obj2 >> str)
					{
						if ( MRnumber == str )
						{
							obj2.seekg(0);
							obj2>>str ;
							system("cls");
							cout << "WELCOME DR." << str << endl ;
							s=67 ;
							cout << "\n\n" ;
							cout << "CHOOSE YOUR SURGERY : " << endl ;
							cout << " 1 - CYROSURGERY " << endl ;
							cout << " 2 - LASERS " << endl ;
							cout << " 3 - PHOTODYNAMIC THERAPY " << endl ;
							cout << " 4 - HYPERTHERMIA " << endl ;
							cout << " 5 - GO BACK " <<  endl ;
							c=getch();
							if (c== 49)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : CYROSURGERY " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "CYROSURGERY:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
							}
							else if ( c== 50)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : LASERS " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "LASERS:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 51)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : PHOTODYNAMIC THERAPY " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "THERAPY:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 52)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : HYPERTHERMIA " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "HYPERTHERMIA:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
								
							}
							else if ( c== 53)
							{
								docMenu();
							}
						}
					}
				}
				obj2.close();
				//oncology2
				obj2.open("oncology2.txt");
				if ( obj2 != NULL)
				{
					while ( obj2 >> str)
					{
						if ( MRnumber == str )
						{
							obj2.seekg(0);
							obj2>>str ;
							system("cls");
							cout << "WELCOME DR." << str << endl ;
							s=67 ;
							cout << "\n\n" ;
							cout << "CHOOSE YOUR SURGERY : " << endl ;
							cout << " 1 - CYROSURGERY " << endl ;
							cout << " 2 - LASERS " << endl ;
							cout << " 3 - PHOTODYNAMIC THERAPY " << endl ;
							cout << " 4 - HYPERTHERMIA " << endl ;
							cout << " 5 - GO BACK " <<  endl ;
							c=getch();
							if (c== 49)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : CYROSURGERY " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "CYROSURGERY:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
							}
							else if ( c== 50)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : LASERS " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "LASERS:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 51)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : PHOTODYNAMIC THERAPY " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "THERAPY:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 52)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : HYPERTHERMIA " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "HYPERTHERMIA:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
								
							}
							else if ( c== 53)
							{
								docMenu();
							}
						}
					}
				}
				obj2.close();
				///radiology
				obj2.open("radiology.txt");
				if ( obj2 != NULL)
				{
					while ( obj2 >> str)
					{
						if ( MRnumber == str )
						{
							obj2.seekg(0);
							obj2>>str ;
							system("cls");
							cout << "WELCOME DR." << str << endl ;
							s=67 ;
							cout << "\n\n" ;
							cout << "CHOOSE YOUR SURGERY : " << endl ;
							cout << " 1 - endovascular treatment of aneurysms and tumors " << endl ;
							cout << " 2 - GO BACK " << endl ;
							c=getch();
							if (c== 49)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED :  endovascular treatment of aneurysms and tumors " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "tumors:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
							}
							else if ( c== 53)
							{
								docMenu();
							}
						}
					}
				}
				obj2.close();
				//rad2 
				obj2.open("radiology2.txt");
				if ( obj2 != NULL)
				{
					while ( obj2 >> str)
					{
						if ( MRnumber == str )
						{
							obj2.seekg(0);
							obj2>>str ;
							system("cls");
							cout << "WELCOME DR." << str << endl ;
							s=67 ;
							cout << "\n\n" ;
							cout << "CHOOSE YOUR SURGERY : " << endl ;
							cout << " 1 - endovascular treatment of aneurysms and tumors " << endl ;
							cout << " 2 - GO BACK " << endl ;
							c=getch();
							if (c== 49)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED :  endovascular treatment of aneurysms and tumors " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "tumors:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
							}
							else if ( c== 53)
							{
								docMenu();
							}
						}
					}
				}
				obj2.close();
				//dental1 
				obj2.open("dental.txt");
				if ( obj2 != NULL)
				{
					while ( obj2 >> str)
					{
						if ( MRnumber == str )
						{
							obj2.seekg(0);
							obj2>>str ;
							system("cls");
							cout << "WELCOME DR." << str << endl ;
							s=67 ;
							cout << "\n\n" ;
							cout << "CHOOSE YOUR SURGERY : " << endl ;
							cout << " 1 - Root Canal " << endl ;
							cout << " 2 - Dental Implants " << endl ;
							cout << " 3 - Wisdom Tooth Extraction " << endl ;
							cout << " 4 - Reconstructive Surgery " << endl ;
							cout << " 5 - GO BACK " <<  endl ;
							c=getch();
							if (c== 49)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Root Canal  " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Canal:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
							}
							else if ( c== 50)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Dental Implants " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Implants:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 51)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Wisdom Tooth Extraction " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Extraction:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 52)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Reconstructive Surgery " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "ReconstructiveSurgery:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
								
							}
							else if ( c== 53)
							{
								docMenu();
							}
						}
					}
				}
				obj2.close();
				//dental2
				obj2.open("dental2.txt");
				if ( obj2 != NULL)
				{
					while ( obj2 >> str)
					{
						if ( MRnumber == str )
						{
							obj2.seekg(0);
							obj2>>str ;
							system("cls");
							cout << "WELCOME DR." << str << endl ;
							s=67 ;
							cout << "\n\n" ;
							cout << "CHOOSE YOUR SURGERY : " << endl ;
							cout << " 1 - Root Canal " << endl ;
							cout << " 2 - Dental Implants " << endl ;
							cout << " 3 - Wisdom Tooth Extraction " << endl ;
							cout << " 4 - Reconstructive Surgery " << endl ;
							cout << " 5 - GO BACK " <<  endl ;
							c=getch();
							if (c== 49)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Root Canal  " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Canal:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
							}
							else if ( c== 50)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Dental Implants " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Implants:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 51)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Wisdom Tooth Extraction " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Extraction:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 52)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Reconstructive Surgery " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "ReconstructiveSurgery:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
								
							}
							else if ( c== 53)
							{
								docMenu();
							}
						}
					}
				}
				obj2.close();
				//kidney1
				obj2.open("kidney, bladder.txt");
				if ( obj2 != NULL)
				{
					while ( obj2 >> str)
					{
						if ( MRnumber == str )
						{
							obj2.seekg(0);
							obj2>>str ;
							system("cls");
							cout << "WELCOME DR." << str << endl ;
							s=67 ;
							cout << "\n\n" ;
							cout << "CHOOSE YOUR SURGERY : " << endl ;
							cout << " 1 - Laparoscopic surgery " << endl ;
							cout << " 2 - Radical nephrectomy " << endl ;
							cout << " 3 - Partial nephrectomy " << endl ;
							cout << " 4 - GO BACK " <<  endl ;
							c=getch();
							if (c== 49)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Laparoscopic surgery  " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Laparoscopicsurgery:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
							}
							else if ( c== 50)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Radical nephrectomy" <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "nephrectomy:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 51)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Partial nephrectomy " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Partialnephrectomy:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							
							else if ( c== 52)
							{
								docMenu();
							}
						}
					}
				}
				obj2.close();
				//kidney2
				obj2.open("kidney, bladder2.txt");
				if ( obj2 != NULL)
				{
					while ( obj2 >> str)
					{
						if ( MRnumber == str )
						{
							obj2.seekg(0);
							obj2>>str ;
							system("cls");
							cout << "WELCOME DR." << str << endl ;
							s=67 ;
							cout << "\n\n" ;
							cout << "CHOOSE YOUR SURGERY : " << endl ;
							cout << " 1 - Laparoscopic surgery " << endl ;
							cout << " 2 - Radical nephrectomy " << endl ;
							cout << " 3 - Partial nephrectomy " << endl ;
							cout << " 4 - GO BACK " <<  endl ;
							c=getch();
							if (c== 49)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Laparoscopic surgery  " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Laparoscopicsurgery:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
							}
							else if ( c== 50)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Radical nephrectomy" <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "nephrectomy:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 51)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Partial nephrectomy " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Partialnephrectomy:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							
							else if ( c== 52)
							{
								docMenu();
							}
						}
					}
				}
				obj2.close();
				//eye1
				obj2.open("eye, ear, nose and throat.txt");
				if ( obj2 != NULL)
				{
					while ( obj2 >> str)
					{
						if ( MRnumber == str )
						{
							obj2.seekg(0);
							obj2>>str ;
							system("cls");
							cout << "WELCOME DR." << str << endl ;
							s=67 ;
							cout << "\n\n" ;
							cout << "CHOOSE YOUR SURGERY : " << endl ;
							cout << " 1 - RETINAL RE-ATTACHMENT / DE-ATTACHMENT  " << endl ;
							cout << " 2 - CATARACT " << endl ;
							cout << " 3 - Acoustic NeuromaSurgery. " << endl ;
							cout << " 4 - CochlearImplant " << endl ;
							cout << " 5 - Myringotomy Eardrum Repair " << endl ;
							cout << " 6 - Augmentation " << endl ;
							cout << " 7 - Rhinoplasty " << endl ;
							cout << " 8 - GO BACK " <<  endl ;
							c=getch();
							if (c== 49)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : RETINAL RE-ATTACHMENT / DE-ATTACHMENT  " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "DE-ATTACHMENT:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
							}
							else if ( c== 50)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : CATARACT" <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "CATARACT:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 51)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Acoustic NeuromaSurgery" <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "NeuromaSurgery:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 52)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : CochlearImplant " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "CochlearImplant:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 53)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Myringotomy Eardrum Repair" <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Repair:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 54)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Augmentation " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Augmentation:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 55)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Rhinoplasty " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Rhinoplasty:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							
							else if ( c== 56)
							{
								docMenu();
							}
						}
					}
				}
				obj2.close();
				//eye2
				obj2.open("eye, ear, nose and throat2.txt");
				if ( obj2 != NULL)
				{
					while ( obj2 >> str)
					{
						if ( MRnumber == str )
						{
							obj2.seekg(0);
							obj2>>str ;
							system("cls");
							cout << "WELCOME DR." << str << endl ;
							s=67 ;
							cout << "\n\n" ;
							cout << "CHOOSE YOUR SURGERY : " << endl ;
							cout << " 1 - RETINAL RE-ATTACHMENT / DE-ATTACHMENT  " << endl ;
							cout << " 2 - CATARACT " << endl ;
							cout << " 3 - Acoustic NeuromaSurgery. " << endl ;
							cout << " 4 - CochlearImplant " << endl ;
							cout << " 5 - Myringotomy Eardrum Repair " << endl ;
							cout << " 6 - Augmentation " << endl ;
							cout << " 7 - Rhinoplasty " << endl ;
							cout << " 8 - GO BACK " <<  endl ;
							c=getch();
							if (c== 49)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : RETINAL RE-ATTACHMENT / DE-ATTACHMENT  " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "DE-ATTACHMENT:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
							}
							else if ( c== 50)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : CATARACT" <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "CATARACT:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 51)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Acoustic NeuromaSurgery" <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "NeuromaSurgery:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 52)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : CochlearImplant " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "CochlearImplant:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 53)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Myringotomy Eardrum Repair" <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Repair:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 54)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Augmentation " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Augmentation:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 55)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Rhinoplasty " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Rhinoplasty:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							
							else if ( c== 56)
							{
								docMenu();
							}
						}
					}
				}
				obj2.close();
				//neuro1
				obj2.open("neurology.txt");
				if ( obj2 != NULL)
				{
					while ( obj2 >> str)
					{
						if ( MRnumber == str )
						{
							obj2.seekg(0);
							obj2>>str ;
							system("cls");
							cout << "WELCOME DR." << str << endl ;
							s=67 ;
							cout << "\n\n" ;
							cout << "CHOOSE YOUR SURGERY : " << endl ;
							cout << " 1 - Craniotomy " << endl ;
							cout << " 2 - Deep brain stimulation (DBS) " << endl ;
							cout << " 3 - Neuroendoscopy " << endl ;
							cout << " 4 - Thrombectomy and cerebral aneurysm repair " << endl ;
							cout << " 5 - GO BACK " <<  endl ;
							c=getch();
							if (c== 49)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Craniotomy  " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Craniotomy:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
							}
							else if ( c== 50)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Deep brain stimulation (DBS) " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "(DBS):")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 51)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Neuroendoscopy " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Neuroendoscopy:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 52)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Thrombectomy and cerebral aneurysmrepair " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "aneurysmrepair:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
								
							}
							else if ( c== 53)
							{
								docMenu();
							}
						}
					}
				}
				obj2.close();
				//neuro2
				obj2.open("neurology2.txt");
				if ( obj2 != NULL)
				{
					while ( obj2 >> str)
					{
						if ( MRnumber == str )
						{
							obj2.seekg(0);
							obj2>>str ;
							system("cls");
							cout << "WELCOME DR." << str << endl ;
							s=67 ;
							cout << "\n\n" ;
							cout << "CHOOSE YOUR SURGERY : " << endl ;
							cout << " 1 - Craniotomy " << endl ;
							cout << " 2 - Deep brain stimulation (DBS) " << endl ;
							cout << " 3 - Neuroendoscopy " << endl ;
							cout << " 4 - Thrombectomy and cerebral aneurysm repair " << endl ;
							cout << " 5 - GO BACK " <<  endl ;
							c=getch();
							if (c== 49)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Craniotomy  " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Craniotomy:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
							}
							else if ( c== 50)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Deep brain stimulation (DBS) " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "(DBS):")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 51)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Neuroendoscopy " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Neuroendoscopy:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 52)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Thrombectomy and cerebral aneurysmrepair " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "aneurysmrepair:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
								
							}
							else if ( c== 53)
							{
								docMenu();
							}
						}
					}
				}
				obj2.close();
				//cardio1
				obj2.open("cardiology.txt");
				if ( obj2 != NULL)
				{
					while ( obj2 >> str)
					{
						if ( MRnumber == str )
						{
							obj2.seekg(0);
							obj2>>str ;
							system("cls");
							cout << "WELCOME DR." << str << endl ;
							s=67 ;
							cout << "\n\n" ;
							cout << "CHOOSE YOUR SURGERY : " << endl ;
							cout << " 1 - Heart valve repair or replacement " << endl ;
							cout << " 2 - Maze surgery " << endl ;
							cout << " 3 - Aneurysm repair " << endl ;
							cout << " 4 - Heart transplant " << endl ;
							cout << " 5 - GO BACK " <<  endl ;
							c=getch();
							if (c== 49)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Heart valve repair or replacement " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "replacement:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
							}
							else if ( c== 50)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Maze surgery " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Mazesurgery:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 51)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Aneurysm repair " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Aneurysm:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 52)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Heart transplant " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "transplant:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
								
							}
							else if ( c== 53)
							{
								docMenu();
							}
						}
					}
				}
				obj2.close();
				//cardio2
				obj2.open("cardiology.txt");
				if ( obj2 != NULL)
				{
					while ( obj2 >> str)
					{
						if ( MRnumber == str )
						{
							obj2.seekg(0);
							obj2>>str ;
							system("cls");
							cout << "WELCOME DR." << str << endl ;
							s=67 ;
							cout << "\n\n" ;
							cout << "CHOOSE YOUR SURGERY : " << endl ;
							cout << " 1 - Heart valve repair or replacement " << endl ;
							cout << " 2 - Maze surgery " << endl ;
							cout << " 3 - Aneurysm repair " << endl ;
							cout << " 4 - Heart transplant " << endl ;
							cout << " 5 - GO BACK " <<  endl ;
							c=getch();
							if (c== 49)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Heart valve repair or replacement " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "replacement:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
							}
							else if ( c== 50)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Maze surgery " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Mazesurgery:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 51)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Aneurysm repair " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "Aneurysm:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();	
							}
							else if ( c== 52)
							{
								fstream o ;
								o.open((s1 +"invoice" + ".txt").c_str() , ios :: app);
								o << " SURGERY SCHEDULED : Heart transplant " <<endl;
								ifstream p ;
								p.open("surgerycosts.txt");
								while ( p >> temp)
								{
									if (temp == "transplant:")
									{
										p>>temp ;
										p>>temp ;
										costOfSurgery =::atof(temp.c_str());
									}
								}
								p.close();
								o << " COST OF SURGERY: $ " << costOfSurgery << endl ;
								cout << "\n\n"<<"surgery scheduled " << "\n\n" ;
								o.close();
								
							}
							else if ( c== 53)
							{
								docMenu();
							}
						}
					}
				}
				obj2.close();
				/////////
		
		 		if ( s!= 67)
		 		{
		 			cout << "\n\n" << "WRONG MR NUMBER ENTERED " << "\n\n" <<endl ;
		 			getch();
		 			docMenu();
				 }
			}
		}
		void check_MR ()
		{
			system("cls");
			char chu ;
			cout << "\t" << " :: DOCTOR MR# NUMBER :: " << "\t" <<"\n" ;
			cout << "CHOOSE DOCTOR's DEPARTMENT : " <<endl ;
			cout << "\n\n\n";
			cout << " 1 - EYE,EAR,NOSE AND THROAT" << endl ;
			cout << " 2 - CHILDRENS HOSPITAL" <<endl;			
			cout << " 3 - KIDNEY AND BLADDER " << endl;
			cout << " 4 - ONCOLOGY" <<endl;
			cout << " 5 - DENTAL" << endl;
			cout << " 6 - CLINICAL IMAGING (RADIOLOGY) " << endl ;
			cout << " 7 - CARDIOLOGY" <<endl ;
			cout << " 8 - NEUROLOGY " <<endl ;
			cout << " 9 - DERMATOLOGY" << endl ; 
			cout << " 10. GO BACK " << endl ;
			int sel;
			cin >> sel ;
			if ( sel == 1){
					department = "eye, ear, nose and throat" ;
				}
			else if ( sel == 2)
			{
				department = "childrens hospital" ;
			}		
			else if ( sel == 3)
			{
				department = "kidney, bladder" ;
			}	
			else if ( sel == 4)
			{
				department="oncology";
			}	
			else if ( sel == 5)
			{
				department= "dental" ;
			}
			else if ( sel == 6)
			{
				department="clinical imaging" ;
			}
			else if ( sel == 7)
			{
				department = "cardiology";
			}
			else if ( sel == 8)
			{
				department="neurology";
			}
			else if ( sel == 9)
			{
				department="dermatology";
			}
			else if ( sel == 10)
			{
				docMenu();
			}
			
			
			string trt , trt2 ,fn,sn;
			ifstream obj, obj2 ;
			obj.open((department + ".txt").c_str());
			obj2.open((department + "2" + ".txt").c_str());
			if ( obj == NULL || obj2 == NULL )
			{
				cout << "WRONG DEPARTMENT ENTERED OR A SPELLING MISTAKE :: " << endl ;
				check_MR();
			}
			system("cls");
			obj >> trt ;
			obj2 >> trt2 ;
			fflush(stdin);
			cout << " ENTER YOUR FIRST NAME(IN UPPERCASE) :  " << endl ;
			cin >> fn ;
//			cout << fn << endl << trt ;
			if ( fn == trt)
			{
				cout << "first name matched " << endl ;
				obj >> trt ;
			
				cout << "ENTER LAST NAME : "<< endl ;
				cin >> sn ;
				if ( sn == trt)
				{
					cout << "LAST NAME MATCHED " << endl ;
					obj >> trt ;	obj >> trt ;
					cout << "MR NUMBER : " << trt << endl ;
			
				}
				
				obj.close();
			}
			else if ( fn == trt2)
			{
				cout << "first name matched " << endl ;
				obj2 >> trt ;
				cout << "ENTER LAST NAME : "<< endl ;
				cin >> sn ;
				if ( sn == trt)
				{
					cout << "LAST NAME MATCHED " << endl ;
					obj2 >> trt ;	obj2 >> trt ;
					cout << "MR NUMBER : " << trt << endl ;
				
				}
				
				obj2.close();
			}
			else if ( fn != trt && fn != trt2)
			{
				cout << "SELECT :: 1- ENTER AGAIN  :: 2- GO BACK " << "\n\n" ;
				
				chu =getch();
				if ( chu == 49 )
				{
					check_MR();
				}
				else if ( chu == 50)
				{
					docMenu();
				}
				else 
				{
					check_MR();
				}
			} 
			
			
			cout << "\n"<<" PRESS ENTER TO GO BACK " << endl ;
			chu=getch();
			if ( chu == 13)
			{
				docMenu() ;
			}
		}
		
		void check_patient_appointments ()
		{
			system("cls");
			cout << "\t" << " :: CHECK APPOINTMENTS :: " << "\t" << "\n\n\n";
			cout << "ENTER MR# NUMBER : " ;
			cin >> MRnumber ;
			cout << "\n" << " PRESS ENTER TO PROCEED           2 - GO BACK " << "\n\n" ;
			char chu ;
			string str;
			chu=getch();
			if ( chu == 13)
			{
				ifstream obj ;
				obj.open((MRnumber + ".txt").c_str());
				if ( obj != NULL )
				{
					while ( getline(obj , str))
					{
						cout << str << endl ;
					}
				}
				else if ( obj == NULL)
				{
					cout << " NO APPOINTMENTS ON THIS MR# " << endl ;
					getch();
					docMenu() ;
				}
				obj.close();
			}
			else if ( chu == 50 )
			{
				docMenu() ;
			}
			else {
				docMenu();
			}
			
		}
		
		int doctor_verification ()
		{   
			system("cls");
			cout << "\n" << " :: DOCTOR VERIFICATION :: " << "\n\n\n\n" ;
			string  n,n2 ;
			int c=0 , nl;
			char chu;
			cout << " 1 - GO FOR VERIFICATION " << endl ;
			cout << "\n\n\n\n";
			cout << " 2 - GO BACK " << endl ;
			chu=getch();
			if ( chu == 49)
			{
				
			
			ifstream obj ;
			ifstream obj2 ;
			obj2.open("DOCTORSpassword.bin");
			obj.open("DOCTORSname.txt");
			if (obj == NULL || obj2 == NULL )
			{
				cout << "no file "; main_menu();
			}
			system("cls");
			cout << "ENTER FIRST NAME : " << endl ;
			cin >> firstName ;
			
			while ( obj >> n )
			{
				if ( n == firstName )
				{
					cout << "\t\t"<< "FIRST NAME MATCHED " << "\t" << endl ;
					c++ ;//inc
					cout << "ENTER LAST NAME : " << endl ;;
					cin >> lastName ;
					obj >> n ;
					if ( n == lastName )
					{
						cout << "\t\t"<< "LAST NAME MATCHED " << "\t" << endl ;
						c++ ;//inc-> 2
						if ( c == 2)
						{
						
							cout <<"\n\n " << " ENTER PASSWORD : (your password chould be 8 characters long )" << endl ;
							
							while ( obj2 >> n2)
							{
								 nl = n2.length();
								obj2.seekg(0);
								break;
							}
//							int no = n+ 1 ;
							char ch[nl + 1];
							for ( int i=0 ; i<nl+1 ; i++) //8 chaaracters long password
							{
		
								chu=getch();
								if ( chu != 13)
								{
		
									ch[i] = chu ;
									cout << "*" ;
								}
								else if ( chu == 13)
								{
									break;
								}
							}
							int c=0;
							char co[nl + 1];
 
    							// copying the contents of the
    							// string to char array
   							strcpy(co, n2.c_str());
						
							while ( obj2 >> n2)
							{
								for ( int i=0 ; i <nl+1 ; i++)
								{
									if ( ch[i] == co[i] )
									{
									 c++ ;
									}
								}
								
								if ( c==7 || c == 8 )
								{
									cout << "\t\t"<< "PASSWORD MATCHED " << "\t" << endl ;
									getch();
									return 6 ;
									break ;
								}
								else{
									obj2.close();
									cout << "incorrect password !" << endl ;
									sleep(1);
									doctor_verification ();
								}
							}
						}
					}
//				
					
				}
				
			}
			obj.close();
			obj2.close();
			}
			else if ( chu == 50){
				main_menu();
			}
			else
			{
				doctor_verification ();
			}
		}

		
};

class patient : protected human 
{
	private :
		
		string s1 ; // string converted ID 
		string oncologyWord ;
		string cardiologyWord;
		string childWord ;
		string dermaWord ;
		string dWord;
		string eyeWord ;
		string imageWord ;
		string neuroWord ;
		string 	kidneyWord;
		string age ; // variable overloaded
		string phoneNumber ;
		string MRoncology ;
		string MRoncology2 ;
		string MRcardiology ;
		string MRcardiology2 ;
		string MReye ;
		string MReye2; 
		string MRchild ;
		string MRchild2 ;
		string MRdental ;
		string MRdental2 ;
		string MRderm ;
		string MRderm2 ;
		string MRneuro ;
		string MRneuro2 ;
		string MRkidney ;
		string MRkidney2 ;
		string MRimage ;
		string MRimage2 ;
		string patientPass ;
		long long int aidCNIC ;
		float bill ;	
		string bloodType ;
		string fatherName ;
		string motherName ;
		string symptoms ;
		string diseaseBefore ;
		string medsBefore ;
//		string department ;
		string trustyName ;
		float monthlyIncAid ;
		float extraIncAid ;
		float expBillAid ;
		float expSchoolingAid ;
		float otherExpAid ;
		float hospitalBill;
		int financialAid ;
		float appointmentTotalBill ;
		float surgeryTotalBill;
		float medicineTotalBill ;
	public :

		patient ()
		{	
			trustyName="" ;
			monthlyIncAid =0.0 ;
			extraIncAid = 0.0 ;
			expBillAid =0.0 ;
			bloodType = "" ;fatherName = "" ;motherName = "";bill =0.0;
			oncologyWord = "oncology" ;
			cardiologyWord = "cardiology" ;
			childWord = "childrens hospital";
			dermaWord = "dermatology" ;
			dWord ="dental" ;
			eyeWord = "eye, ear, nose and throat" ;
			kidneyWord = "kidney, bladder" ;
			neuroWord = "neurology" ;
			imageWord = "clinical imaging" ;
			patientPass="";
			MRoncology = "10000001" ;  //hardcoded MR NUMBER 
			MRoncology2 = "10000002" ;
			MRcardiology = "10000003" ;
			MRcardiology2="10000004" ;
			MReye = "10000005" ;
			MReye2 = "10000006" ;
			MRchild = "10000007" ;
			MRchild2= "10000008" ;
			MRdental = "10000009" ;
			MRdental2 = "10000010" ; 
			MRderm = "10000011" ;
			MRderm2= "10000012" ;
			MRkidney="10000013" ;
			MRkidney2="10000014" ;
			MRneuro ="10000015" ;
			MRneuro2="10000016" ;
			MRimage = "10000017" ;
			MRimage2 ="10000018" ;
			aidCNIC = 0;
			expSchoolingAid = 0.0 ;
			otherExpAid = 0.0 ;
			hospitalBill = 0.0 ;
			financialAid=0;
			surgeryTotalBill =0.0 ;
			appointmentTotalBill =0.0 ;
			medicineTotalBill=0.0;
		}
		void set_age ( string x)
		{
			this->age=x ;
		}
		void set_phoneNumber ( string x)
		{
			this->phoneNumber = x;
		}
		void set_fatherName(string x)
		{
			this->fatherName=x ;
		}
		void set_motherName ( string x)
		{
			this->motherName=x ;
		}
		void set_bloodType( string x)
		{
			this->bloodType=x ;
		}
		void check_detail_menu ()   // to check patient details like address etc .
		{
			system("cls");
			cout << " :: CHECK DETAILS :: " << endl ;
			cout << "\n\n\n\n" ;
			cout << "ENTER ID : " << endl ;
			cin >> ID ;
			ostringstream strg; // to cnvert long int -> string 
			strg<< ID ;
			s1 = strg.str();	
			string ch ;
			ch= s1 + "details";
			cout << "----------------------------------" << endl ;
			cout << "----------------------------------" << "\n\n" ;
			ifstream obj ;
			obj.open((ch+".txt").c_str());
			if ( obj == NULL ){
				cout << "NO FILE PREENT " << endl ;
				patient_menu();
			}
			
			while ( getline (obj , ch ))
			{
				cout << ch << endl ;
				
			}
			obj.close();
			
			cout <<"\n\n"<< " 1- GO BACK " << endl ;
			char choo ;
			choo=getch();
			if ( choo == 49)
			{
				patient_menu();
			}
			
		}
		
		void patient_menu ()
		{	
			system("cls");
			cout << "   ::   PATIENT MENU   ::  " << endl ;
			printf ("\n\n\n");
			cout << " 1- APPOINTMENT " <<endl ;  //  appointment -> book apointment || check appointment det ails || delete appointment 
			printf ("\n\n\n");
			cout << " 2. CHECK PATIENT DETAILS " << endl ;
			cout <<"\n\n\n";
			cout << " 3- CHECK PATIENT INVOICE " << endl ;
			cout << "\n\n\n" ;
			cout << " 4- UPDATE PATIENT INFORMATION " << endl ;
			cout << "\n\n\n";
			cout << " 5- PATIENT AID " << endl ;
			cout << "\n\n\n" ;
			cout << " 6- HOSPITAL DEPARTMENTS " << endl ;
			cout << "\n\n\n" ;
			cout << " 7- GO BACK " << endl ;
						
			char ch;
			while (1)
			{
			
			ch= getch();
			if ( ch == 49)
			{
				patient_appointment();
				break;
			}
			else if ( ch == 50)
			{
				check_detail_menu ();
				break;
			}
			else if ( ch == 51)
			{
				patient_invoice();
				break;
			}
			else if ( ch == 52)
			{
				update_info();
				break;
			}
			else if ( ch == 53)
			{
				patient_aid ();
				break;
			}
			else if ( ch == 54) 
			{
				department_menu();
				break;
			}
			else if ( ch == 55)
			{
				main_menu();
				break;
			}
			
			} //nd of while loop
			 	
		}	
		
		
		void patient_aid ()
		{
			system("cls");
			cout << "\t\t" << " :: PATIENT AID :: "<< "\t\t" << endl ;
			cout << "\n\n\n\n" ;
			cout << " 1 - FILL PATIENT AID FORM  " << endl ;
			cout << " \n\n" ;
			cout << " 2 - CHECK AID REQUEST EVALUATION " << endl ;
			cout << "\n\n" ;
			cout << " 3 - GO BACK " << endl ;
			cout << "\n\n" ;
			char chu ;
			chu = getch();
			if ( chu == 49 )
			{
				aid_form ();
			}
			else if ( chu == 50)
			{
				pat_aid_req ();
			}
			else if ( chu == 51)
			{
				patient_menu();
			}
			else 
			{
				patient_aid ();
			}
		}
		
		void pat_aid_req () 
		{
			system("cls");
			cout << "\t"<<" :: CHECK PATIENT AID REQUEST :: " << "\t" << "\n\n\n\n" ;
			cout << "1 - ENTER ID FOR PATIENT AID CONFIRMATION " << endl ;
			cout << "\n\n" ;
			cout << "2 - GO BACK " << endl ;
			char chu ;
			int sel =0;
			string str="" ,srk="",x="" ;
			chu =getch();
			if ( chu == 49)
			{
				system("cls");
				cout << " ENTER PATIENT ID : " << endl ;
				cin >> ID ;
				ostringstream strg; // to cnvert long int -> string 
				strg<< ID ;
				s1 = strg.str();
				ifstream obj,obj2,obj4 ;
				obj.open(( s1 + "details" + ".txt").c_str());
				if ( obj != NULL )
				{
					cout << "\t\t" << " id confirmed " << "\t" << endl ;
					obj.close();
					getch();
//					system("cls");
					obj2.open(( s1 + "aid" + ".txt").c_str());
					if ( obj2 == NULL){exit(1);
					}
					
					//from invoic -> hospital bill
					obj4.open((s1 + "invoice" + ".txt").c_str());
					if ( obj4 != NULL )
					{			
						while ( obj4 >> x)
						{
							if ( x == "APPOINTMENT:")
							{
								obj4 >> x ;
								obj4 >> x ;
//							cout << x << endl ;
								appointmentTotalBill = ::atof(x.c_str());
								hospitalBill = hospitalBill + appointmentTotalBill ;	
							}
							else if ( x == "MEDICINE:")
							{
								obj4 >> x ;obj4 >> x ;
							
								medicineTotalBill = ::atof(x.c_str());
								hospitalBill = hospitalBill + medicineTotalBill ;
							}
							else if ( x== "SURGERY:")
							{
								obj4 >> x ;
								obj4 >> x ;
						
								surgeryTotalBill = ::atof(x.c_str());
								hospitalBill = hospitalBill + surgeryTotalBill ;
							}
						}
						obj4.close();
						while ( obj2 >> str)
						{
							if ( str == "::APPROVED::" )
							{
								cout << " CONGRATULATIONS YOU HAVE BEEN CHOSEN FOR THE HOSPITALS FINANCIAL AID PROGRAMME " << endl ;
								sel=678; 
							}
							else if ( str == "::REJECTED::")
							{
								cout << " APOLOGIES YOU HAVE BEEN REJECTED FROM THE HOSPITALS FINANCIAL AID PROGRAMME " << endl ;
								
							}
							else if ( str == "GIVEN(in" && sel==678 )
							{
								obj2 >> srk ;
								obj2 >> srk ;
								financialAid = ::atof(srk.c_str());
								cout << "FINANCIAL AID GIVEN : " << financialAid << "%" << endl ;
								cout << "TOTAL HOSPITAL EXPENDITURE AFTER FINANCIAL AID : $ " << hospitalBill - hospitalBill*financialAid*0.01 << endl ;
							}
						}
					}		
						
						obj2.close();
				}
					cout << "\n\n\n\n" ;
					cout << " PRESS ENTER TO GO BACK " << endl ;
					chu=getch();
					if ( chu == 13)
					{
						patient_aid ();
					}
					else {
						pat_aid_req();
					}
				
			}
			
			else if ( chu == 50)
			{
				patient_aid ();
			}
			else {
				pat_aid_req();
			}
		}
		
		void aid_form ()
		{
			system("cls");
			cout << " :: PATIENT FINANCIAL AID FORM :: " <<  endl ;
			cout << "\n\n\n\n" ;
			cout << " ENTER PATIENT ID : " ;
			cin >> ID ;
			string s1,l,str,x;
			double temp , temp2 ,temp3 ;
			ostringstream strg; // to cnvert long int -> string 
			strg<< ID ;
			s1 = strg.str();
			ifstream obj ;
			obj.open(( s1 + "details" + ".txt").c_str());
			if ( obj != NULL )
			{
				cout << "\t\t" << "id successfully matched " << "\t\t" << endl ;
				system("cls");
				while ( obj >> str)
				{
					if ( str == "NAME")
					{
						obj >> str ;
						obj >> str ;
						cout << "WELCOME " << str << endl<< "\n\n\n" ;
						break;
					}
				}
				obj.close();
				ofstream obj2,obj3 ;
				obj2.open((s1 + "aid" + ".txt").c_str());
				
				obj3.open("AIDrequests.bin");
				obj3 << s1 << endl ;
				obj3.close();
				
				if ( obj2 == NULL )
				{
					exit(1);
				}
				obj2 <<"\t"<< " :: FINANCIAL AID FORM :: " << "\t\t" << "\n\n" ;
				cout << " PLEASE ENTER YOUR CNIC : " ;					cin >> aidCNIC ;
				obj2 << "CNIC : " << aidCNIC << endl ;
				obj2 << " PROFESSION : " << endl ;
				while (1){
						
					system("cls");
					cout << " CHOOSE YOUR PROFESSION  : " << endl ;
					cout << " 1 - CIVIL SERVANT " << endl ;
					cout << " 2 - GOVERNMENT OFFICER " << endl ;
					cout << " 3 - EMPLOYEE AT A FIRM/COMPANY " << endl ;
					cout << " 4 - DOCTOR " << endl ;
					cout << " 5 - BUSINESS MAN " << endl ;
					cout << " 6 - OTHER " << endl ;
					cout << " 7 - EXIT " << endl ;
					char c;
					c=getch();
					if ( c == 49)
					{
						obj2 << "CIVIL SERVANT" << endl ;
						cout << "added" ;
					}
					else if ( c== 50)
					{
						obj2 << " GOVERNMENT OFFICER " << endl ;
						cout << " added" ;
					}
					else if ( c== 51)
					{
						obj2 << " EMPLOYEE AT A FIRM/COMPANY" << endl ;
						cout << " added" ;
					}
					else if ( c== 52)
					{
						obj2 << "  DOCTOR " << endl ;
						cout << "added";
					}
					else if ( c== 53)
					{
						obj2 << "BUSINESS MAN" << endl ;
						cout << "added" ;
					}
					else if ( c== 54)
					{
						cout << "enter" ;
						getline ( cin , x) ;
						obj2 << x<< endl ;
					}
					else if ( c== 55)
					{
						break ;
					}
					else{
						break;
					}
				
				}
				system ("cls");
				cout << endl << " EMAIL YOUR PAY CHEQUE / BANK STATEMENT " << endl ;
				cout << "EMAIL : akuFA@gmail.com " << endl ;
				obj2 << " PAY CHEQUE / BANK STATEMENT EMAILED AT akuFA@gmail.com  "	<< endl ;
				obj2 << "\n\n" ;
				cout << " ACCORDING TO OUR HOSPITAL POLICY , A TRUSTY IS NECESSARY FOR CONFIRMING PATIENTS REQUEST FOR ASSISTANCE " << endl;
				cout <<"\n"<< "ENTER YOUR TRUSTY'S NAME : "  << endl ;
				cin >> trustyName ;
				obj2 << "TRUSTY'S NAME : " << trustyName << endl ;
				fflush(stdin);
				cout << "\n"<<" ENTER MONTHLY INCOME OF YOUR HOUSEHOLD (YOURS/FATHERS/MOTHERS) "<< endl << ":: AND PROVIDE PROOF OF THAT :: " << endl;
				cin >> monthlyIncAid ;
				obj2 << " MONTHLY INCOME : $ " << monthlyIncAid << endl ;
				fflush(stdin);
				cout << "\n\n";
				cout << " ENTER ANY EXTRA INCOME ( SMALL BUSSINESS / ONLINE WORK / ETC ) : " << endl ;
				cin >> extraIncAid ;
				obj2 << " EXTRA INCOME ( SMALL BUSSINESS / ONLINE WORK / ETC ) : $ " << extraIncAid << endl ;
				fflush(stdin);
				cout << "\n\n";
				cout << " :: ENTER TOTAL EXPENDITURE :: AND PROVIDE PROPER PROOF OF THAT ::  " << endl ;
				cout << "ENTER EXPANSE OF BILLS : " << endl ;
				cin >> expBillAid ;
				obj2 << " EXPANSE OF BILLS : $ " << expBillAid << endl ;
				fflush(stdin);
				cout << "\n\n";
				cout << "EXPANSE OF SCHOOLING (IF NONE YOU CAN ENTER ZERO) : " << endl ;
				cin >> expSchoolingAid ;
				obj2 << " EXPANSE OF SCHOOLING : $ " << expSchoolingAid << endl ;
				cout << "\n\n";
				fflush(stdin);
				cout << " OTHER EXPANSES : " << endl ;
				cin >> otherExpAid ;
				obj2 << "OTHER EXPANSES : $ " << otherExpAid << endl ;
				fflush(stdin);
				cout << "\n\n";
				obj2 << "\n\n\n"<< " INCOME : $ " << monthlyIncAid + extraIncAid << endl ;
				obj2 << " EXPENDITURE : $ " << expBillAid + expSchoolingAid + otherExpAid << endl ;	
		
				ifstream obj4 ;  // calculating hospital expenditure 
				ostringstream strg; // to cnvert long int -> string 
				strg<< ID ;
				l = strg.str();
				obj4.open((l + "invoice" + ".txt").c_str());
				if ( obj4 != NULL )
				{			
					while ( obj4 >> x)
					{
						if ( x == "APPOINTMENT:")
						{
							obj4 >> x ;
							obj4 >> x ;
//							cout << x << endl ;
							temp = ::atof(x.c_str());
							hospitalBill = hospitalBill + temp ;	
						}
						else if ( x == "MEDICINE:")
						{
							obj4 >> x ;obj4 >> x ;
							temp2 = ::atof(x.c_str());
							hospitalBill = hospitalBill + temp2 ;
						}
						else if ( x== "SURGERY:")
						{
							obj4 >> x ;
							obj4 >> x ;
							temp3 = ::atof(x.c_str());
							hospitalBill = hospitalBill + temp3 ;
						}
					}
					obj4.close(); 
					cout << "TOTAL HOSPITAL BILL : " << hospitalBill << endl ;
					obj2 << " TOTAL HOSPITAL EXPENDITURE : $ " << hospitalBill << endl ;
					obj2.close();
					//evaluating hospital aid
					cout << "\n\n";
					cout << "loading ...." << endl ;
					sleep(3);
					cout << "FORM FILLED , NOW YOU CAN WAIT FOR CONFIRMATION " << endl ;
					cout << "loading ...." << endl ;
					sleep(3);
					cout << "YOUR FORM HAS BEEN SUBMITED SUCCESSFULLY " << endl ;
					
					cout << "PRESS ENTER TO GO BACK : " << endl ;
					char chu ;
					chu = getch();
					if ( chu ==13)
					{
						patient_menu();
					}
					else 
					{
						patient_menu() ;
					}
				}
			}
			
		}
		
		int patient_verification () // pass -> binary file to be mae in appointments section .
		{
			system("cls");
			int count =0 ;
			cout << "\n\n" << " :: WELCOME :: " << "\n\n"<< endl ;
			cout << "1 - SIGN UP " << endl ;
			cout << "2 - LOGIN (ONLY IF YOUR ACCOUNT IS MADE ) " << endl ;
			cout << "\n\n\n\n\n\n" << "3 - GO BACK " << "\n"   ;
			char c ;
			c=getch() ;
			if ( c== 49)
			{
				system("cls");
				cout << " :: SIGN UP ::   " << "\n\n" ;
				while (1)
				{
				
					cout << "ENTER USER NAME : " << endl ;
					fflush(stdin);
					getline(cin , name );
					ifstream obj2 ;
					obj2.open((name + "password" +".bin").c_str());
					if  ( obj2 != NULL )
					{
						system("cls");
						cout << "USER NAME ALREADY CHOSEN " << endl ;
						cout << "SELECT A DIFFERENT USER NAME  " << endl ;
						cout << "1- " << name + "2001" << endl ;
						cout << "2- " << name + "kk" << endl ;
						cout << "3- " << name + "001" << endl ;
						cout << "4- " << name + "khi" << endl ;
						cout << "5- " << name + "890" << endl ;
						char chu;
						cout << "6- EXIT " << endl ;
						chu=getch();
						if ( chu == 49 )
						{
							name = name + "2001" ;
							cout << "USER NAME UPDATED " << endl ;
						}
						else if ( chu == 50)
						{
							name =name + "kk" ;
							cout << "USER NAME UPDATED " << endl ;
						}
						else if ( chu == 51)
						{
							name =  name + "001" ;
							cout << "USER NAME UPDATED " << endl ;
						}
						else if ( chu == 52)
						{
							name = name + "khi" ;
							cout << "USER NAME UPDATED " << endl ;
						}
						else if ( chu == 53)
						{
							name = name + "890" ;
							cout << "USER NAME UPDATED " << endl 
						;}
						else if ( chu == 54)
						{
							main_menu();
						}
						 
					}
					obj2.close();
					cout << "\t\t" << "(your password should be maximum 10 characters long )" <<endl;
					cout << " ENTER PASSWORD : " << endl;
					char chn[10] ,chu;
					for ( int i=0 ; i<10 ; i++)
					{
		
						chu=getch();
						if ( chu != 13)
						{
		
							chn[i]=chu ;
							cout << "*" ;
						}
						else if( chu == 13)
						{
							for ( int j=i ; j<10 ;j++)
							{
								chn[j] = '\0';
							}
							break;
						}
					}
					int c=0;
					
					cout <<endl<< " CONFIRM PASSWORD : " << endl ;
					char co[10];
					for ( int i=0 ; i<10 ; i++)
					{
		
						chu=getch();
						if ( chu != 13)
						{
		
							co[i]=chu ;
							cout << "*" ;
						}
						else if ( chu == 13)
						{
							for ( int j=i ; j<10 ;j++)
							{
								co[j] = '\0';
							}
							break;
							
						}
					}
					//
					
					for ( int i=0 ; i <10 ; i++)
					{
						if ( chn[i] == co[i] )
						{
							c++ ;
						}
					}
					if ( c == 10 || c == 9 )
					{
						cout << "\t\t" << "PASSWORD MATCHED " << "\t\t" << "\n\n" ;
						getch();
						ofstream obj ;
						obj.open((name + "password" + ".bin").c_str());
						if ( obj == NULL )
						{
							cout << "ACCOUNT CANNOT BE CREATED " << endl ; main_menu();
						}
						obj << "NAME: " << name << endl ;
						obj <<  "PASSWORD:  " << chn << endl ;
						obj.close();
						return 5 ;
						break;
					}
					else 
					{
						cout << "\t\t" << "PASSWORD MISMATCH " << "\t\t" << "\n\n" ;
						cout << " :: SELECT :: 1-EXIT  2-RE-ENTER " << endl;
						char chu ;
						chu=getch();
						if (chu == 49){
							main_menu();
						}
						else if ( chu == 50)
						{
							
						}
						else{
						}
					} 
				}
			}
			else if ( c== 50)
			{
				system("cls");
				cout << "  ::  LOGIN   ::   " << "\n\n" ;
				cout <<"\n"<< "ENTER USERNAME : " ;
				cin >> name ;
				string ch,st ,n,no;
				int nn ;
				ch = name + "password" ;
				
				ifstream obj ;
				obj.open((ch + ".bin" ).c_str());
				obj >> n ;
				obj >> n ;
				 
				if ( obj != NULL &&  name == n )
				{
					cout << "\n" << " USER NAME  SUCCESSFULLY MATCHED " << endl ;
					while (1)
					{
					obj.seekg(0);
						
						string st ;
						while ( obj >> st )
						{
							if ( st == "PASSWORD:")
							{
								obj >> st ;
								nn = st.length();
							}
						}
					
						char chn[nn + 1] , chu ;
						char co[nn + 1] ;
						
						cout << "\n" << "ENTER PASSWORD : " << endl ;
						
						
							
							for ( int i=0 ; i<nn+1 ; i++)
							{
								fflush(stdin);
								chu=getch();
								if ( chu != 13)
								{
		
									chn[i]=chu ;
									cout << "*" ;
								}
								else 
								{
									break;
								}
							}
							int c=0;
							
							strcpy(co, st.c_str());
							for ( int i=0 ; i <nn+1 ; i++)
							{
								if ( chn[i] == co[i] )
								{
								 c++ ;
								}
							}
							
							if ( c == nn+1 || c == nn )
								{
									cout << "PASSWORD SUCCESSFULLY MATCHED " << endl ;
									return 5 ;
									break;
								}
							else 
								{
									cout << "PASSWORD MISMATCH ! " << endl ;
									cout << "RE-ENTER PASSWORD " << endl ;
									count++ ;
									if ( count ==  5){
										sleep(5);
										main_menu();
									}
								}
							
						
					}
				}
				
			}
			else if ( c== 51)
			{
				main_menu ();
			}
			else 
			{
				cout << "RE-ENTER " << endl ;
				patient_verification () ;
			}
		}
		
		
		
		
		void update_info ()
		{
			system("cls");
			cout << " :: UPDATE INFORMATION :: " << endl ;
			cout << "\n\n\n" ;
			cout << "ENTER ID : " << endl ;
			cin >> ID ;
			ostringstream strg;
			strg<< ID ;
			s1 = strg.str();	
			string ch ,x;
			ch = s1 + "details" ;
			ifstream obj ;
			obj.open((ch + ".txt").c_str());
			if ( obj == NULL ){
				cout << "ERROR IN FILE OPENING " << endl ;
			    patient_menu();
			}
			string n;	
			while ( obj>> n )
			{
				if (n=="NAME" )
				{
					obj >> name ;
					obj >> name ;
				}
				else if ( n == "FATHERS")
				{
					obj >> fatherName ;
					obj >> fatherName;
					obj >> fatherName ;
				}
				else if ( n== "MOTHERS" )
				{
					obj >> motherName ;
					obj >> motherName;
					obj >>  motherName ;
				}
				else if ( n== "BLOOD")
				{
					obj >> bloodType ;
					obj >> bloodType ;
					obj >> bloodType;
				}
				else if ( n == "PHONE")
				{
					obj >> phoneNumber;
					obj >> phoneNumber ;
					obj >> phoneNumber ;
				}
				else if (  n == "ADDRESS" ||  n == "Address")
				{
					obj >> address ;
					obj >> address ;
				}
				else if ( n == "EMAIL")
				{
					obj >> email ;
					obj >> email ;
				}
				else if ( n == "AGE" )
				{
					obj >> age ;
					obj >> age ;
				}
			
			}
			obj.close();
			
			remove((ch + ".txt").c_str());
			
			ofstream obj2 ;
			obj2.open((ch + ".txt").c_str());
			if ( obj2 == NULL )
			{
				cout << "no file to  exist" << endl ;			
			}
			
			while (1)
			{
			
				cout << "\n" << "SELECT ::  1- UPDATE  ::   2- GO BACK  ::" << endl ;
				char c ;
				c= getch();
				if ( c == 49 )
				{	
					system ("cls");
					cout << "SELECT WHAT DO YOU WANT TO UPDATE : " << endl ;	
					cout << "1- Name " << endl ;
					cout << "\n";
					cout << "2- Address" << endl ;
					cout << "\n";
					cout << "3- Fathers name " << endl ;
					cout << "\n";
					cout << "4- Mothers name " << endl ;
					cout << "\n";
					cout << "5- Blood type " << endl ;
					cout << "\n";
					cout << "6- Phone Number  " << endl ;
					cout << "\n";
					cout << "7- Email " << endl ;
					cout << "\n";
					cout << "8- Age " << endl ;
					cout << "\n";
					char c ;
					c=getch();
					if ( c== 49)
					{
						cout << "ENTER YOUR NAME TO UPDATE :  " << endl ;
						cin >> x;
						set_name(x) ;		
					}
					else if ( c == 50 )
					{
						cout << "ENTER YOUR ADDRESS TO UPDATE : " << endl ;
						cin >> x;
						set_add(x);
					}
					else if ( c== 51)
					{
						cout << "ENTER YOUR FATHERS NAME TO UPDDATE : " << endl ;
						cin >> x;
						set_fatherName(x) ;
					}
					else if ( c== 52)
					{
						cout << "ENTER YOUR MOTHERS NAME TO UPDATE : " << endl ;
						cin >> x;
						set_motherName(x) ;
					}
					else if ( c== 53)
					{
						cout << "ENTER YOUR BLOOD TYPE TO UPDATE : " << endl ;
						cin >> x;
						set_bloodType(x) ;
					}
					else if ( c== 54)
					{
						cout << "ENTER YOUR PHONE NUMBER TO UPDATE : " << endl ;
						cin >>  x;
						set_phoneNumber(x); 
					}
					else if ( c== 55)
					{
						cout << "ENTER YOUR EMAIL TO UPDATE : " << endl ;
						cin >>x;
						set_email(x) ;
					}
					else if ( c== 56)
					{
						cout << "ENTER YOUR AGE TO UPDATE : " << endl ;
						cin >> x ;
						set_age(x);
					}	
				}
				else if ( c== 50)
				{
//					patient_menu();
					break;
				}
				else {cout << "WRONG INPUT : ENTER AGAIN " << endl ; 
				}
			}
			
			obj2 << "-----------------" << endl ;
			obj2 << " PATIENT ID : "  << ID << endl ;
			obj2 << "-----------------" << endl ;
			obj2 << "\n" ;
			obj2 << "NAME : " << name << endl ;
			obj2 << "FATHERS NAME : " << fatherName << endl ;
			obj2 << "MOTHERS NAME : " << motherName << endl ;
			obj2 << "BLOOD TYPE : " << bloodType << endl ;
			obj2 << "PHONE NUMBER : " << phoneNumber << endl ;
			obj2 << "ADDRESS : " << address << endl ;
			obj2 << "EMAIL : " << email << endl ;
			obj2 << "AGE : " << age << endl ;
			obj2.close();
			
			cout << "PRESS ENTER TO GO BACK " << endl ;
			char chu;
			chu=getch();
			if ( chu == 13)
			{
				patient_menu();
			}
		}
		
		void patient_invoice()
		{
			system("cls") ;
			string x;
			cout << "\t"<<" :: PATIENT INVOICE :: " << "\t\t" << "\n\n\n" ;
			cout << " 1- ENTER ID " << endl ;
			cout << "\n\n" ;
			cout << " 2- GO BACK " << endl ;
			char chu ;
			chu=getch();
			if ( chu == 49)
			{
				cout << "enter : " ;
				cin >> ID ;
				ostringstream strg;
				strg<< ID ;
				s1 = strg.str();
				
				ifstream obj,obj2 ;
				obj.open((s1 + "details" + ".txt").c_str());
				if ( obj != NULL )
				{
					cout << "\t\t" << "id matched " << "\t\t" << "\n\n" <<endl ;
					obj.close();
					
					obj2.open(( s1 + "invoice" + ".txt").c_str());
					if ( obj2 != NULL)
					{
						while ( getline(obj2 , x))
						{
							cout << x << endl ;
						}
						obj2.close();
					}
				}
				else 
				{
					cout << "WRONG ID ENTERED " << endl ;
					patient_invoice();
				}
				
				cout << "PRESS ENTER TO GO BACK " << endl ;
				chu=getch();
				if ( chu == 13)
				{
					patient_menu();
				}
				else 
				{
					patient_invoice();
				}
				
			}
			else if ( chu == 50)
			{
				patient_menu();
			}
			else{
				 patient_invoice();
			}
		}
		void patient_appointment ()
		{
			system ("cls");
			cout << "1-BOOK AN APPOINTMENT " << endl ;
			cout << "\n\n\n";
			cout << "2-CHECK APPOINTMENT " << endl ;
			cout << "\n\n\n";
			cout << "3-CANCEL APPOINTMENT " << endl ;
			cout << "\n\n\n";
			cout << "4-GO BACK " ;
			cout << "\n\n";
			char ch ; ch = getch();
			if ( ch == 49)
			{
				patient_book_appointment ();	
			}
			else if ( ch == 50)
			{
				patient_check_appointment ();
			}
			else if ( ch == 51)
			{
				patient_delete_appointment ();
			}
			else if ( ch == 52)
			{
				patient_menu ();
			}
			else {
			}
		}
		
		void patient_check_appointment ()
		{
			system("cls");
			cout << "\n\n" << ":: CHECK APPOINTMENT ::" << endl ;
			cout << "\n\n";
			
			cout << " ENTER PATIENT ID :  " << endl ;
			cin >> ID ;
			ostringstream strg;
			strg<< ID ;
			s1 = strg.str();	
			string ch ;
			ch = s1 + "appointment" ;
			
			ifstream obj ; 
			obj.open((ch + ".txt").c_str()) ;
			if ( obj == NULL ){cout << "no file " << endl ;
			sleep(1);patient_appointment ();
			}
			string tr ;
			while (getline(obj,tr))
			{
				cout << tr << endl ;
			}
			obj.close();
			
			cout << "\n\n\n" << "1 -GO BACK " << "\n\n" ;
			char chu ;
			 chu =getch();
			if ( chu == 49 )
			{
				patient_appointment ();
			}
		}
		
		void patient_delete_appointment ()
		{
			system("cls");
			cout << "\n\n" << ":: CANCEL APPOINTMENT ::" << endl ;
			cout << "\n\n";
			
			cout << " ENTER PATIENT ID :  " << endl ;
			cin >> ID ;
			ostringstream strg;
			strg<< ID ;
			s1 = strg.str();	
			string ch ;
			ch = s1 + "appointment" ;
			
			if ( remove((ch + ".txt").c_str())==0)
			{
				cout << " APPOINTMENT SUCCESSFULLY CANCELED " << endl ;
//				ifstream obj ;
//				obj.
			}
			else 
			{
				cout << ":: TRY AGAIN :: THERE MIGHT HAVE BEEN A TYPO ! :: " << endl ;
			}
			
			cout << "\n\n\n" << "1 -GO BACK " << "\n\n" ;
			char chu ; chu =getch();
			if ( chu == 49 )
			{
				patient_appointment ();
			}
		}
		void patient_book_appointment()//recheck
		{
			system("cls");
			cout << "::   BOOK AN APPOINTMENT   ::" << endl ;
			cout << "\n\n\n" ;
			
			cout << ":: CHOOSE YOUR DEPARTMENT ::" << endl ;
			cout << "\n\n\n";
			cout << " 1. EYE,EAR,NOSE AND THROAT" << endl ;
			printf ("\n\n\n");
			cout << " 2. CHILDRENS HOSPITAL" <<endl;
			printf ("\n\n\n");			
			cout << " 3. KIDNEY AND BLADDER " << endl;
			printf ("\n\n\n");
			cout << " 4. ONCOLOGY" <<endl;
			printf ("\n\n\n");
			cout << " 5. DENTAL" << endl;
			printf ("\n\n\n");
			cout << " 6. CLINICAL IMAGING (RADIOLOGY) " << endl ;
			printf ("\n\n\n");	
			cout << " 7. CARDIOLOGY" <<endl;
			printf ("\n\n\n");
			cout << " 8. NEUROLOGY" <<endl ;
			printf ("\n\n\n");
			cout << " 9. DERMATOLOGY" <<endl ;
			printf ("\n\n\n");
			cout << "ENTER : " << endl  ;
			int l ;
			cin >> l ;
			if ( l==1 )
			{
				b_eye_ear_nose();	
			}
			else if ( l ==2)
			{
				b_childrens_hospital();
			}
			else if ( l == 3)
			{
				b_kidney_bladder();
			}
			else if ( l == 4)
			{
				b_oncology();
			}
			else if ( l ==5)
			{
				b_dental();
			}
			else if ( l ==6)
			{
			    b_clinical_imaging();
			}
			else if ( l ==7)
			{
				b_cardiology();
			}
			else if ( l ==8)
			{
				b_neurology();
			}
			else if ( l == 9)
			{
				b_dermatology();
			}
			
			
		}
		
		void  department_menu ()
		{	
			system ("cls");
		
			cout << ":: DEPARTMENTS ::" << endl ;
			cout << "\n\n\n";
			cout << " EYE,EAR,NOSE AND THROAT" << endl ;
			printf ("\n\n\n");
			cout << "  CHILDRENS HOSPITAL" <<endl;
			printf ("\n\n\n");			
			cout << "  KIDNEY AND BLADDER " << endl;
			printf ("\n\n\n");
			cout << "  ONCOLOGY" <<endl;
			printf ("\n\n\n");
			cout << "  DENTAL" << endl;
			printf ("\n\n\n");
			cout << "  CLINICAL IMAGING (RADIOLOGY) " << endl ;
			printf ("\n\n\n");	
			cout << "  OPERATING ROOMS AND PAIN CLINIC " <<endl;
			printf ("\n\n\n");
			cout << "  CARDIOLOGY" <<endl ;
			printf ("\n\n\n");
			cout << "  NEUROLOGY " <<endl ;
			printf ("\n\n\n");
			cout << "  DERMATOLOGY" << endl ; 
			cout << "\n\n\n" ;
			cout << " 1. GO BACK " << endl ;
			char sel;
			sel=getch() ;
			if ( sel == 49){
				patient_menu();
			}
		} 
		
		void b_eye_ear_nose ()
		{
			system ("cls");
			BOOK_APPOINTMENT  (eyeWord,MReye,MReye2);
			
		}
		void b_childrens_hospital ()
		{
			system ("cls");
			BOOK_APPOINTMENT  (childWord,MRchild,MRchild2);	
		}
		void b_kidney_bladder ()
		{
			system ("cls");
			BOOK_APPOINTMENT  (kidneyWord,MRkidney ,MRkidney2 );	
		}
		
		void b_dental ()
		{
			system ("cls");
			BOOK_APPOINTMENT (dWord,MRdental , MRdental2);
		}
		void b_clinical_imaging ()
		{
			system ("cls");
			BOOK_APPOINTMENT (imageWord , MRimage , MRimage2);
		}
		void b_cardiology ()
		{
			system ("cls");
			BOOK_APPOINTMENT (cardiologyWord,MRcardiology ,MRcardiology2);
		}
		void b_neurology () 
		{
			system ("cls");
			BOOK_APPOINTMENT (neuroWord , MRneuro ,MRneuro2 );
		}
		void b_oncology ()
		{
			system ("cls");
			BOOK_APPOINTMENT (oncologyWord , MRoncology , MRoncology2);
		}
		void b_dermatology ()
		{
			system ("cls");
			BOOK_APPOINTMENT (dermaWord,MRderm,MRderm);
		}
		void BOOK_APPOINTMENT  ( string x , string MR , string MR2) /// xstores - > oncology 
		{
			system ("cls");
			cout << "SELECT YOUR DOCTOR :  " << endl ;
			cout << "\n\n" ;
			ifstream obj,obj2 ;
			obj.open((x + ".txt").c_str());
			obj2.open((x+"2"+".txt").c_str());
			if ( obj == NULL || obj2 == NULL){
				cout << "FILE CANT BE OPENED ! " << endl ; exit (1);
			}
			string txt ,trt;
			getline(obj,txt) ;
			cout <<"1-" << txt << endl ;
			getline(obj2,trt) ;
			cout << "\n\n" ;
			cout << "2- " << trt << endl ;
			cout << "\n\n\n\n\n\n\n\n\n";
			cout << "3 - GO BACK " << endl ;
			char ch ,cho,l;
			int count =0 ;
			ch=getch();
			if ( ch == 49 )
			{
				system ("cls");
				cout << "DOCTOR SCHEDULE : " << endl ;
				cout << "\n\n" ;
				while (getline(obj,trt))
				{
					cout << trt ;
					cout << "\n";
				}
				 
				cout << "\n\n" ;
				cout << ":: ENTER DAY ::  "	<< endl ;
				string day ;
				cin >> day ;
				string chu ;
				if ( day == "Monday" || day == "monday" || day == "MONDAY")
				{
					count =0;
					cout << "\n" ;	
					cout << "Select timing : " << endl ;
					cout << " 1- FIRST SHIFT  :: 2-SECOND SHIFT ::" << endl ;
					cho = getch();
					if ( cho == 49)
					{
						fstream obji,los ; 
						obji.open((x+"1"+"seats"+"1"+".txt").c_str(),ios::in) ;  // to read a file
						los.open((x+"1"+"seats"+"1"+".txt").c_str(),ios::app);   // to write to a file !
						if ( los == NULL){cout << "NO FILE PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
								
							}
							else if ( l == '\0')
							{
								break ;
							}
							
						}
						
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 <<endl; 
						char chi;
						obji.close();los.close();
						chi=getch() ;
						if ( chi == 13 )
						{	string chu;		
							system("cls");
							string ch ;
							
							
							patientInvestigation ();//////////
							
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice 
							
//							obj.open()
							ofstream obj ; // file openened to be edited 
							
						
							ch= s1 + "appointment";
			
				
							obj.open((ch+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR << endl; 
							ofstream oc ;
							oc.open((MR + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR << endl ;
							oc << "APPOINTMENT DAY : MONDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 9-11 am " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT "<< ID << endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : MONDAY " << endl ;
							obj << "TIMINGS : " << " 9-11 am " << endl ;
							cout << "TIMINGS : 9-11 am" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
						}
						else 
						{
						patient_menu();
						}
					}
										
					else if ( cho == 50)
					{
						count =0;
						fstream obji,los ;
						obji.open((x+"1"+"seats"+"2"+".txt").c_str(),ios::in) ;
						los.open((x+"1"+"seats"+"2"+".txt").c_str(),ios::app);
						if (  los == NULL){cout << "NO FIL PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '\0')
							{
								break ;
							}
							
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 << endl  ; 
						char chi;
						
						chi=getch() ;
						obji.close();los.close();
						if ( chi == 13 )
						{
							system("cls");
							patientInvestigation ();
							
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice
							ofstream obj ; // file openened to be edited 
							
							
							chu= s1 + "appointment";
			
				
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR << endl; 
							ofstream oc ;
							oc.open((MR + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR << endl ;
							oc << "APPOINTMENT DAY : MONDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 1-3 pm " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT "<<ID << endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : MONDAY " << endl ;
							obj << "TIMINGS : " << " 1-3 pm " << endl ;
							cout << "TIMINGS : 1-3 pm" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
							
						}
						else {patient_menu();
						}
					}
				}
					
				else if ( day == "Tuesday" || day == "TUESDAY" || day == "tuesday")
				{
					count =0;
					cout << "\n" ;	
					cout << "Select timing : " << endl ;
					cout << " 1- FIRST SHIFT  :: 2-SECOND SHIFT ::" << endl ;
					cho = getch();
					if ( cho == 49)
					{
						fstream obji,los ;
						obji.open((x+"2"+"seats"+"1"+".txt").c_str(),ios::in) ;
						los.open((x+"2"+"seats"+"1"+".txt").c_str(),ios::app);
						if (  los == NULL){cout << "NO FILE PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '\0'){break;
							}	
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 <<endl; 
						char chi;
						obji.close();los.close();
						chi=getch() ;
						if ( chi == 13 )
						{			
							system("cls");
							patientInvestigation ();  // long int is converted iinto string 
							
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice
							ofstream obj ; // file openened to be edited 
							
						
							chu= s1 + "appointment";
			
				
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR << endl; 
							ofstream oc ;
							oc.open((MR + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR << endl ;
							oc << "APPOINTMENT DAY : TUESDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 9-11 am " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT "<<ID << endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : TUESDAY " << endl ;
							obj << "TIMINGS : " << " 9-11 am " << endl ;
							cout << "TIMINGS : 9-11 am" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
						}
						else {patient_menu();
						}
					}
										
					else if ( cho == 50)
					{
						count =0;
						fstream obji,los ;
						obji.open((x+"2"+"seats"+"2"+".txt").c_str(),ios::in) ;
						los.open((x+"2"+"seats"+"2"+".txt").c_str(),ios::app);
						if (los == NULL){cout << "NO FIL PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '/0')
							{
								break;
							}	
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 << endl  ; 
						char chi;
						
						chi=getch() ;
						obji.close();los.close();
						if ( chi == 13 )
						{
							system("cls");
							patientInvestigation ();
							
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $  " << bill << endl;
							eg.close(); // closing file for invoice
							ofstream obj ; // file openened to be edited 
							

							chu= s1 + "appointment";
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR << endl; 
							ofstream oc ;
							oc.open((MR + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR << endl ;
							oc << "APPOINTMENT DAY : TUESDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 1-3 pm " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT "<<ID << endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : TUESDAY " << endl ;
							obj << "TIMINGS : " << " 1-3 pm " << endl ;
							cout << "TIMINGS : 1-3 pm" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
							
						}
						else {patient_menu();
						}
					
					}
				}
				else if ( day == "WEDNESDAY" || day == "Wednesday" || day == "wednesday")
				{
					count =0 ;
					cout << "\n" ;	
					cout << "Select timing : " << endl ;
					cout << " 1- FIRST SHIFT  :: 2-SECOND SHIFT ::" << endl ;
					cho = getch();
					if ( cho == 49)
					{
						fstream obji,los ;
						obji.open((x+"3"+"seats"+"1"+".txt").c_str(),ios::in) ;
						los.open((x+"3"+"seats"+"1"+".txt").c_str(),ios::app);
						if ( los == NULL){cout << "NO FILE PRESENT !" << endl ;
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '/0')
							{
								break;
							}	
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 <<endl; 
						char chi;
						obji.close();los.close();
						chi=getch() ;
						if ( chi == 13 )
						{			
							system("cls");
							patientInvestigation ();
							
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << " APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice
							
							ofstream obj ;
							chu= s1 + "appointment";
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}						
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR << endl; 
							ofstream oc ;
							oc.open((MR + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR << endl ;
							oc << "APPOINTMENT DAY : WEDNESDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 9-11 am " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT " <<ID<< endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : WEDNESDAY " << endl ;
							obj << "TIMINGS : " << " 9-11 am " << endl ;
							cout << "TIMINGS : 9-11 am" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
						}
						else {patient_menu();
						}
					}
										
					else if ( cho == 50)
					{
						count =0;
						fstream obji,los ;
						obji.open((x+"3"+"seats"+"2"+".txt").c_str(),ios::in) ;
						los.open((x+"3"+"seats"+"2"+".txt").c_str(),ios::app);
						if (  los == NULL){cout << "NO FIL PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '/0'){break;
							}
							
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 << endl  ; 
						char chi;
						
						chi=getch() ;
						obji.close();los.close();
						if ( chi == 13 )
						{
							system("cls");
							patientInvestigation ();
							
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice
							
							ofstream obj ; // file openened to be edited 
							chu= s1 + "appointment";
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR << endl; 
							ofstream oc ;
							oc.open((MR + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR << endl ;
							oc << "APPOINTMENT DAY : WEDNESDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 1-3 pm " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT "<<ID << endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : WEDNESDAY " << endl ;
							obj << "TIMINGS : " << " 1-3 pm " << endl ;
							cout << "TIMINGS : 1-3 pm" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
							
						}
						else {patient_menu();
						}
					}
				}
				else if ( day == "THURSDAY" || day == "thursday" || day== "Thursday")
				{
					count=0;
					cout << "\n" ;	
					cout << "Select timing : " << endl ;
					cout << " 1- FIRST SHIFT  :: 2-SECOND SHIFT ::" << endl ;
					cho = getch();
					if ( cho == 49)
					{
						fstream obji,los ;
						obji.open((x+"4"+"seats"+"1"+".txt").c_str(),ios::in) ;
						los.open((x+"4"+"seats"+"1"+".txt").c_str(),ios::app);
						if ( los == NULL){cout << "NO FILE PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if (l=='/0'){break;
							}
							
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 <<endl; 
						char chi;
						obji.close();los.close();
						chi=getch() ;
						if ( chi == 13 )
						{			
							system("cls");
							patientInvestigation ();
							
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $  " << bill << endl;
							eg.close(); // closing file for invoice
							
							ofstream obj ; // file openened to be edited 
							chu= s1 + "appointment";
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR << endl; 
							ofstream oc ;
							oc.open((MR + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR << endl ;
							oc << "APPOINTMENT DAY : THURSDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 9-11 am " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT "<<ID << endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : THURSDAY " << endl ;
							obj << "TIMINGS : " << " 9-11 am " << endl ;
							cout << "TIMINGS : 9-11 am" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
						}
						else {patient_menu();
						}
					}
										
					else if ( cho == 50)
					{
						count =0;
						fstream obji,los ;
						obji.open((x+"4"+"seats"+"2"+".txt").c_str(),ios::in) ;
						los.open((x+"4"+"seats"+"2"+".txt").c_str(),ios::app);
						if (  los == NULL){cout << "NO FIL PRESENT !" << endl ;
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '/0'){break;
							}
							
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 << endl  ; 
						char chi;
						
						chi=getch() ;
						obji.close();los.close();
						if ( chi == 13 )
						{
							system("cls");
							patientInvestigation ();
					
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $  " << bill << endl;
							eg.close(); // closing file for invoice
							
							ofstream obj ; // file openened to be edited 
							chu= s1 + "appointment";
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR << endl; 
							ofstream oc ;
							oc.open((MR + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR << endl ;
							oc << "APPOINTMENT DAY : THURSDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 1-3 pm " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT "<<ID << endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : THURSDAY " << endl ;
							obj << "TIMINGS : " << " 1-3 pm " << endl ;
							cout << "TIMINGS : 1-3 pm" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
							
						}
						else {patient_menu();
						}
					}
				
				}
				else if ( day == "FRIDAY" || day == "Friday" ||  day == "friday")
				{
					cout << "\n" ;	
					cout << "Select timing : " << endl ;
					cout << " 1- FIRST SHIFT  :: 2-SECOND SHIFT ::" << endl ;
					cho = getch();
					if ( cho == 49)
					{
						fstream obji,los ;
						obji.open((x+"5"+"seats"+"1"+".txt").c_str(),ios::in) ;
						los.open((x+"5"+"seats"+"1"+".txt").c_str(),ios::app);
						if ( los == NULL){cout << "NO FILE PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '/0'){break;
							}
							
						}
						
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 <<endl; 
						char chi;
						obji.close();los.close();
						chi=getch() ;
						if ( chi == 13 )
						{			
							system("cls");
							patientInvestigation ();
							
								chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice
						
							ofstream obj ; // file openened to be edited 
							chu= s1 + "appointment";
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR << endl; 
							ofstream oc ;
							oc.open((MR + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR << endl ;
							oc << "APPOINTMENT DAY : FRIDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 9-11 am " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT " <<ID<< endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : FRIDAY " << endl ;
							obj << "TIMINGS : " << " 9-11 am " << endl ;
							cout << "TIMINGS : 9-11 am" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
						}
						else {patient_menu();
						}
					}
				
					else if ( cho == 50)
					{
						count =0;
						fstream obji,los ;
						obji.open((x+"5"+"seats"+"2"+".txt").c_str(),ios::in) ;
						los.open((x+"5"+"seats"+"2"+".txt").c_str(),ios::app);
						if (  los == NULL){cout << "NO FIL PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '/0'){break;
							}
							
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 << endl  ; 
						char chi;
						
						chi=getch() ;
						obji.close();los.close();
						if ( chi == 13 )
						{
							system("cls");
							patientInvestigation ();
						
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice
							
							ofstream obj ; // file openened to be edited 
							chu= s1 + "appointment";
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR << endl; 
							ofstream oc ;
							oc.open((MR + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR << endl ;
							oc << "APPOINTMENT DAY : FRIDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 1-3 pm " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT " <<ID <<  endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : FRIDAY " << endl ;
							obj << "TIMINGS : " << " 1-3 pm " << endl ;
							cout << "TIMINGS : 1-3 pm" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
							
						}
						else {patient_menu();
						}
					}
				}
				else {patient_menu();
					
				}
			}
			///////		
			else if ( ch == 50)
			{
				///obj2 and other changes x wala
				system ("cls");
				cout << "DOCTOR SCHEDULE : " << endl ;
				cout << "\n\n" ;
				while (getline(obj2,trt))
				{
					cout << trt ;
					cout << "\n";
				}
				 
				cout << "\n\n" ;
				cout << ":: ENTER DAY ::  "	<< endl ;
				string day ;
				cin >> day ;
				string chu ;
				if ( day == "Monday" || day == "monday" || day == "MONDAY")
				{
					count =0;
					cout << "\n" ;	
					cout << "Select timing : " << endl ;
					cout << " 1- FIRST SHIFT  :: 2-SECOND SHIFT ::" << endl ;
					cho = getch();
					if ( cho == 49)
					{
						fstream obji,los ;
						obji.open(("2"+x+"1"+"seats"+"1"+".txt").c_str(),ios::in) ;  // to read a file
						los.open(("2"+x+"1"+"seats"+"1"+".txt").c_str(),ios::app);   // to write to a file !
						if ( los == NULL){cout << "NO FILE PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
								
							}
							else if ( l == '\0')
							{
								break ;
							}
							
						}
						
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 <<endl; 
						char chi;
						obji.close();los.close();
						chi=getch() ;
						if ( chi == 13 )
						{	string chu;		
							system("cls");
							string ch ;
							
							
							patientInvestigation ();//////////
							
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice 
							
//							obj.open()
							ofstream obj ; // file openened to be edited 
							
						
							ch= s1 + "appointment";
			
				
							obj.open((ch+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR2 << endl; 
							ofstream oc ;
							oc.open((MR2 + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR2 << endl ;
							oc << "APPOINTMENT DAY : MONDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 11-1 pm " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT " <<ID <<  endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : MONDAY " << endl ;
							obj << "TIMINGS : " << " 11-1 pm " << endl ;
//							obj << "DAY : MONDAY " << endl ;
							cout << "TIMINGS : 11-1 pm " << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
						}
						else 
						{
							patient_menu();
						}
					}
										
					else if ( cho == 50)
					{
						count =0;
						fstream obji,los ;
						obji.open(("2"+x+"1"+"seats"+"2"+".txt").c_str(),ios::in) ;
						los.open(("2"+x+"1"+"seats"+"2"+".txt").c_str(),ios::app);
						if (  los == NULL){cout << "NO FIL PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '\0')
							{
								break ;
							}
							
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 << endl  ; 
						char chi;
						
						chi=getch() ;
						obji.close();los.close();
						if ( chi == 13 )
						{
							system("cls");
							patientInvestigation ();
							
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice
							ofstream obj ; // file openened to be edited 
							
							
							chu= s1 + "appointment";
			
				
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR2 << endl; 
							ofstream oc ;
							oc.open((MR2 + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR2 << endl ;
							oc << "APPOINTMENT DAY : MONDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 1-3 pm " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT " <<ID <<  endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : MONDAY " << endl ;
							obj << "TIMINGS : " << " 1-3 pm " << endl ;
//							obj << "DAY : MONDAY " << endl ;
							cout << "TIMINGS : 1-3 pm" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
							
						}
						else {patient_menu();
						}
					}
				}
					
				else if ( day == "Tuesday" || day == "TUESDAY" || day == "tuesday")
				{
					count =0;
					cout << "\n" ;	
					cout << "Select timing : " << endl ;
					cout << " 1- FIRST SHIFT  :: 2-SECOND SHIFT ::" << endl ;
					cho = getch();
					if ( cho == 49)
					{
						fstream obji,los ;
						obji.open(("2"+x+"2"+"seats"+"1"+".txt").c_str(),ios::in) ;
						los.open(("2"+x+"2"+"seats"+"1"+".txt").c_str(),ios::app);
						if (  los == NULL){cout << "NO FILE PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '\0'){break;
							}	
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 <<endl; 
						char chi;
						obji.close();los.close();
						chi=getch() ;
						if ( chi == 13 )
						{			
							system("cls");
							patientInvestigation ();  // long int is converted iinto string 
							
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice
							ofstream obj ; // file openened to be edited 
							
						
							chu= s1 + "appointment";
			
				
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR2 << endl; 
							ofstream oc ;
							oc.open((MR2 + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR2 << endl ;
							oc << "APPOINTMENT DAY : TUESDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 9-11 am " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT " <<ID <<  endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : TUESDAY " << endl ;
							obj << "TIMINGS : " << " 9-11 am " << endl ;
//							obj << "DAY : TUESDAY " << endl ;
							cout << "TIMINGS : 9-11 am" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
						}
						else {patient_menu();
						}
					}
										
					else if ( cho == 50)
					{
						count =0;
						fstream obji,los ;
						obji.open(("2"+x+"2"+"seats"+"2"+".txt").c_str(),ios::in) ;
						los.open(("2"+x+"2"+"seats"+"2"+".txt").c_str(),ios::app);
						if (los == NULL){cout << "NO FIL PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '/0')
							{
								break;
							}	
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 << endl  ; 
						char chi;
						
						chi=getch() ;
						obji.close();los.close();
						if ( chi == 13 )
						{
							system("cls");
							patientInvestigation ();
							
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice
							ofstream obj ; // file openened to be edited 
							

							chu= s1 + "appointment";
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR2 << endl; 
							ofstream oc ;
							oc.open((MR2 + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR2 << endl ;
							oc << "APPOINTMENT DAY : TUESDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 1-3 pm " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT " <<ID <<  endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : TUESDAY " << endl ;
							obj << "TIMINGS : " << " 1-3 pm " << endl ;
//							obj << "DAY : TUESDAY " << endl ;
							cout << "TIMINGS : 1-3 pm" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
							
						}
						else {patient_menu();
						}
					
					}
				}
				else if ( day == "WEDNESDAY" || day == "Wednesday" || day == "wednesday")
				{
					count =0 ;
					cout << "\n" ;	
					cout << "Select timing : " << endl ;
					cout << " 1- FIRST SHIFT  :: 2-SECOND SHIFT ::" << endl ;
					cho = getch();
					if ( cho == 49)
					{
						fstream obji,los ;
						obji.open(("2"+x+"3"+"seats"+"1"+".txt").c_str(),ios::in) ;
						los.open(("2"+x+"3"+"seats"+"1"+".txt").c_str(),ios::app);
						if ( los == NULL){cout << "NO FILE PRESENT !" << endl ;
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '/0')
							{
								break;
							}	
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 <<endl; 
						char chi;
						obji.close();los.close();
						chi=getch() ;
						if ( chi == 13 )
						{			
							system("cls");
							patientInvestigation ();
							
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice
							
							ofstream obj ;
							chu= s1 + "appointment";
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}						
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR2 << endl; 
							ofstream oc ;
							oc.open((MR2 + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR2 << endl ;
							oc << "APPOINTMENT DAY : WEDNESDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 9-11 am " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT " <<ID <<  endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : WEDNESDAY " << endl ;
							obj << "TIMINGS : " << " 9-11 am " << endl ;
//							obj << "DAY : WEDNESDAY " << endl ;
							cout << "TIMINGS : 9-11 am" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
						}
						else {patient_menu();
						}
					}
										
					else if ( cho == 50)
					{
						count =0;
						fstream obji,los ;
						obji.open(("2"+x+"3"+"seats"+"2"+".txt").c_str(),ios::in) ;
						los.open(("2"+x+"3"+"seats"+"2"+".txt").c_str(),ios::app);
						if (  los == NULL){cout << "NO FIL PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '/0'){break;
							}
							
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 << endl  ; 
						char chi;
						
						chi=getch() ;
						obji.close();los.close();
						if ( chi == 13 )
						{
							system("cls");
							patientInvestigation ();
							
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $" << bill << endl;
							eg.close(); // closing file for invoice
							
							ofstream obj ; // file openened to be edited 
							chu= s1 + "appointment";
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR2 << endl; 
							ofstream oc ;
							oc.open((MR2 + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR2 << endl ;
							oc << "APPOINTMENT DAY : WEDNESDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 1-3 pm " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT " <<ID <<  endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
							obj << "DAY : WEDNESDAY " << endl ;
							obj << "TIMINGS : " << " 1-3 pm " << endl ;
//							obj << "DAY : WEDNESDAY " << endl ;
							cout << "TIMINGS : 1-3 pm" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
							
						}
						else {exit(1);
						}
					}
				}
				else if ( day == "THURSDAY" || day == "thursday" || day== "Thursday")
				{
					count=0;
					cout << "\n" ;	
					cout << "Select timing : " << endl ;
					cout << " 1- FIRST SHIFT  :: 2-SECOND SHIFT ::" << endl ;
					cho = getch();
					if ( cho == 49)
					{
						fstream obji,los ;
						obji.open(("2"+x+"4"+"seats"+"1"+".txt").c_str(),ios::in) ;
						los.open(("2"+x+"4"+"seats"+"1"+".txt").c_str(),ios::app);
						if ( los == NULL){cout << "NO FILE PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if (l=='/0'){break;
							}
							
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 <<endl; 
						char chi;
						obji.close();los.close();
						chi=getch() ;
						if ( chi == 13 )
						{			
							system("cls");
							patientInvestigation ();
							
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice
							
							ofstream obj ; // file openened to be edited 
							chu= s1 + "appointment";
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR2 << endl; 
							ofstream oc ;
							oc.open((MR2 + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR2 << endl ;
							oc << "APPOINTMENT DAY : THURSDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 9-11 am " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT " <<ID <<  endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
//							obj << "DAY : THURSDAY " << endl ;
							obj << "TIMINGS : " << " 9-11 am " << endl ;
							obj << "DAY : THURSDAY " << endl ;
							cout << "TIMINGS : 9-11 am" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
						}
						else {patient_menu();
						}
					}
										
					else if ( cho == 50)
					{
						count =0;
						fstream obji,los ;
						obji.open(("2"+x+"4"+"seats"+"2"+".txt").c_str(),ios::in) ;
						los.open(("2"+x+"4"+"seats"+"2"+".txt").c_str(),ios::app);
						if (  los == NULL){cout << "NO FIL PRESENT !" << endl ;
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '/0'){break;
							}
							
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 << endl  ; 
						char chi;
						
						chi=getch() ;
						obji.close();los.close();
						if ( chi == 13 )
						{
							system("cls");
							patientInvestigation ();
					
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice
							
							ofstream obj ; // file openened to be edited 
							chu= s1 + "appointment";
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR2 << endl; 
							ofstream oc ;
							oc.open((MR2 + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR2 << endl ;
							oc << "APPOINTMENT DAY : THURSDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 1-3 pm " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT " <<ID <<  endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
//							obj << "DAY : FRIDAY " << endl ;
							obj << "TIMINGS : " << " 1-3 pm " << endl ;
							obj << "DAY : THURSDAY " << endl ;
							cout << "TIMINGS : 1-3 pm" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
							
						}
						else {patient_menu();
						}
					}
				
				}
				else if ( day == "FRIDAY" || day == "Friday" ||  day == "friday")
				{
					cout << "\n" ;	
					cout << "Select timing : " << endl ;
					cout << " 1- FIRST SHIFT  :: 2-SECOND SHIFT ::" << endl ;
					cho = getch();
					if ( cho == 49)
					{
						fstream obji,los ;
						obji.open(("2"+x+"5"+"seats"+"1"+".txt").c_str(),ios::in) ;
						los.open(("2"+x+"5"+"seats"+"1"+".txt").c_str(),ios::app);
						if ( los == NULL){cout << "NO FILE PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '/0'){break;
							}
							
						}
						
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 <<endl; 
						char chi;
						obji.close();los.close();
						chi=getch() ;
						if ( chi == 13 )
						{			
							system("cls");
							patientInvestigation ();
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice
						
							ofstream obj ; // file openened to be edited 
							chu= s1 + "appointment";
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR2 << endl; 
							ofstream oc ;
							oc.open((MR2 + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR2 << endl ;
							oc << "APPOINTMENT DAY : FRIDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 9-11 am " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT " <<ID <<  endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
//							obj << "DAY : FRIDAY " << endl ;
							obj << "TIMINGS : " << " 9-11 am " << endl ;
							obj << "DAY : FRIDAY  " << endl ;
							cout << "TIMINGS : 9-11 am" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
						}
						else {patient_menu();
						}
					}
				
					else if ( cho == 50)
					{
						count =0;
						fstream obji,los ;
						obji.open(("2"+x+"5"+"seats"+"2"+".txt").c_str(),ios::in) ;
						los.open(("2"+x+"5"+"seats"+"2"+".txt").c_str(),ios::app);
						if (  los == NULL){cout << "NO FIL PRESENT !" << endl ; 
						}
						
						while ( obji >> l )
						{
							if ( l == '1' )
							{
								count ++;
							}
							else if ( l == '/0'){break;
							}
							
						}
						cout << "NUMBER OF SEATS ALREADY BOOKED : " << count << endl ;
						cout << "NUMBER OF AVAILABLE SEATS : " << 10 - count << endl ;
						cout << " :: PRESS ENTER TO PROCEED :: " << endl ;
						los << 1 << endl  ; 
						char chi;
						
						chi=getch() ;
						obji.close();los.close();
						if ( chi == 13 )
						{
							system("cls");
							patientInvestigation ();
						
							chu = s1 + "invoice" ;
							cout << "APPOINTMENT SUUCESSFULLY BOOKED ! " << endl ;
							fstream eg ;
							eg.open((chu+".txt").c_str() , ios :: app);
							if ( eg == NULL){cout << "FILE NOT present" << endl ;exit(1);
							}
							bill = bill + 10 ;
							eg << "ID : " << ID << endl ;
							eg << "INVOICE : " << endl ;
							eg << "APPOINTMENT FOR DR : " << txt << endl ;
							eg << "APPOINTMENT: $ " << bill << endl;
							eg.close(); // closing file for invoice
							
							ofstream obj ; // file openened to be edited 
							chu= s1 + "appointment";
							obj.open((chu+".txt").c_str());
							if (obj== NULL)
							{
								cout << "NO FILE PRESENT " << endl ;exit(1);
							}
							obj << ID << endl ;
							obj << ":: APPOINTMENT BOOKED :: " << endl ;
							obj << "DOCTOR : " << txt << endl ;
							obj << "DOCTOR MR# " << MR2 << endl; 
							ofstream oc ;
							oc.open((MR2 + ".txt").c_str(), ios :: app ) ;
							if ( oc == NULL )
							{
								cout << "NO FILLE " ; exit(1);
							}
							oc << " MR# : " << MR2 << endl ;
							oc << "APPOINTMENT DAY : FRIDAY " << endl ;
							oc << " APPOINTMENT TIMINGS : 1-3 pm " << endl ;
							oc << "PATIENT ID FOR APPOINTMENT " <<ID <<  endl ;
							oc << "-------------------------------" << endl ;
							oc.close();
//							obj << "DAY : FRIDAY " << endl ;
							obj << "TIMINGS : " << " 1-3 pm " << endl ;
							obj << "DAY : FRIDAY " << endl ;
							cout << "TIMINGS : 1-3 pm" << endl;
							cout << "PATIENT ID : " << ID << endl ;
							obj.close();
							
						}
						else {patient_menu();
						}
					}
				}
				
					
			}
			else if ( ch == 51)
			{
				patient_book_appointment();
			}
			else 
			{
//				oncology();
			} 
		}// end of book an appointment 
		
		
		
		patientInvestigation ()
		{
			// make patient file->details  
			cout << "\n"<< " :: BASIC INFORMATION ::  "<< "\n\n" ;
			srand(time(NULL));
			ID= (rand() % 9000000) +1000000 ;
			ostringstream strg; // to cnvert long int -> string 
			strg<< ID ;
			s1 = strg.str();	
			string ch ;
			ch= s1 + "details";
			
			ofstream obj ;
			obj.open((ch+".txt").c_str());  //wouldnt work with c_str ?
			if ( obj == NULL )
			{
				cout << "FILE NOT FOUND " << endl ;
				exit(1); 
			}
			
			obj << "--------------" << endl ;
			obj << "PAIENT ID : " << ID << endl ;
			obj << "--------------" << endl << endl ;	
			cout << "Enter your name : " ;
			cin >> name ;
			obj << "NAME : " << get_name() << endl ;  // for file
			cout << endl<< "Enter your fathers name : "  ;
			cin >> fatherName ;
			fflush(stdin);
			obj << "FATHERS NAME : " << fatherName << endl ;
			fflush(stdin);
			cout<< endl  << "Enter your mothers name : " ;
			cin >> motherName ;
			obj <<"MOTHERS NAME : "<< motherName << endl;
			fflush(stdin);
			cout << endl<< "Enter your blood type : "  ;
			cin >>  bloodType ;
			obj << "BLOOD TYPE : " << bloodType << endl ;
			cout<<endl << "Enter your phone number :  " ;
			fflush(stdin);
			cin >> phoneNumber ;
			obj << "PHONE NUMBER : " << phoneNumber << endl ;
			cout <<endl << "Enter your address : "  ;
			fflush(stdin);
			getline (cin,address);
			obj << "ADDRESS : " << address << endl;
			fflush(stdin);
			cout <<endl<< "Enter your email : " ;
			cin >> email ;
			obj << "EMAIL : " << email << endl ;
			cout << endl << "Enter your age : "  ;
			fflush(stdin);
			cin >> age ;
			obj << "AGE : " << age << endl ; 
			system ("cls");
			cout << " :: MEDICAL INFORMATION :: " << endl ;
			obj << "\n" << " :: MEDICAL INFORMATION :: " << endl ;
			cout << "SELECT ANY MEDICATIONS IF YOU HAVE TAKEN : " << endl ;
			medication (ch);
			system ("cls");
			cout << "SELECT IF YOU HAVE ANY CURRENT DISEASES : " << endl;
			diseases (ch);
			obj.close();
			
    	
		}
		
		
		///////////
		void medication (string ch)
		{
			system ("cls");
			fstream obj ;
			obj.open((ch+".txt").c_str(), ios :: app );
			if ( obj == NULL){cout << "NO FILE ";exit(1);
			}
			obj <<endl<< "MEDICINES USED BEFORE :  " << endl ;
			char co;
			cout << " ENTER MEDICATION " << "\n\n" ;
			sleep(1);
			while (1)
			{
				char co;
				system("cls");
				cout << "1-BLOOD THINING MEDICINES " << endl ;
				cout << "2-MEDICINE USED FOR INFECTION" << endl;
				cout << "3-PAIN KILLERS / MORPHINE " << endl ;
				cout << "4-ANY MEDICINES USED FOR BLOOD PRESSURE / CHOLESTROL " << endl ;
				cout << "5-INSULIN " << endl ;
				cout << "6-BIRTH CONTROL PILLS " << endl ;
				cout << "7-NONE " << endl ;
				cout << "8-BACK " << endl ;
				cout << "SELECT : " << endl ;
				co = getch();
				if ( co == 49)
				{
					cout << "BLOOD THINING MEDICINES " << endl ;
					obj << "BLOOD THINING MEDICINES " << endl ;
				}
				else if ( co == 50)
				{
					cout << "MEDICINE USED FOR INFECTION" << endl;
					obj << "MEDICINE USED FOR INFECTION" << endl;
				}
				else if ( co ==51)
				{
					cout <<  "PAIN KILLERS / MORPHINE " << endl ;
					obj << "PAIN KILLERS / MORPHINE " << endl ;
				}
				else if ( co== 52)
				{
					cout << " MEDICINES USED FOR BLOOD PRESSURE / CHOLESTROL " << endl ;
					obj << " MEDICINES USED FOR BLOOD PRESSURE / CHOLESTROL " << endl ;
				}
				else if ( co == 53)
				{
					cout <<  "INSULIN " << endl ;
					obj << "INSULIN " << endl ;
				}
				else if ( co == 54)
				{
					cout << "BIRTH CONTROL PILLS " << endl ;
					obj << "BIRTH CONTROL PILLS " << endl ;
				}
				else if ( co == 55){
					cout << "NO MEDICATION " << endl ;
					obj << "NO MEDICATION " << endl ;
					break;
					
				}
				else if ( co == 56)
				{
					break ;
				}
				else {
				}
			}
			obj.close();
		}
		void diseases (string ch)
		{
			system ("cls");
			fstream obj ;
			obj.open((ch+".txt").c_str(), ios :: app );
			if ( obj == NULL){cout << "NO FILE ";exit(1);
			}
			cout << " ENTER FORMER DISEASES :  " << "\n\n" ;
			obj <<endl<< "DISEASES FROM BEFORE :  " << endl ;
			char co;
			sleep(1);
			while (1)
			{	system("cls");
				cout << "1-DIABETES " << endl ;
				cout << "2-CHOLESTROL /BLOOD PRESSURE " << endl ;
				cout << "3-HORMONAL DISEASE " << endl ;
				cout << "4-HEART DISEASE " << endl ;
				cout << "5-NEUROLOGICAL DISEASE " << endl ;
				cout << "6-LIVER RELATED DISEASE " << endl ;
				cout << "7-OTHER " << endl ;
				cout << "8-NONE " << endl ;
				cout << "9-BACK " << endl ;
				co =getch();
				if ( co== 49)
				{
					cout << "DIABETES " << endl ;
					obj << 	"DIABETES " << endl ;
				} 
				else if ( co == 50 )
				{
					cout << "CHOLESTROL /BLOOD PRESSURE " << endl ;
					obj << "CHOLESTROL /BLOOD PRESSURE " << endl ;
				}
				else if ( co == 51)
				{
					cout << "HARMONAL DIEASE " << endl ;
					obj << "HARMONAL DIEASE " << endl ;
				}
				else if ( co == 52)
				{
					cout << "HEART DISEASE " << endl ;
					obj << "HEART DISEASE " << endl ;
				}
				else if ( co == 53)
				{
					cout << "NEUROLOGICAL DISEASE " << endl ;
					obj << "NEUROLOGICAL DISEASE " << endl ;
				}
				else if ( co == 54)
				{
					cout << "LIVER RELATED DISEASE " << endl ;
					obj << "LIVER RELATED DISEASE " << endl ;
				}
				else if ( co == 55)
				{
					string l;
					cout << "ENTER ANY OTHER DISEASE : " << endl ;
					cin >> l ;
					obj << l << endl ;
					break;
				}
				else if ( co == 56)
				{
					cout << "NO DISEASE " << endl ;
					obj << "NO DISEASE " << endl ;
					break;
				}
				else if ( co == 57)
				{
					break;
				}
				else {
				}
			}
			obj.close();
		}
		
				
};





class hospital 
{   
	protected : 
		long int telephone1 ;      
		long int telephone2  ;
		string name  ;
		string location  ;
		
	public : 
		hospital ()
		{ //hardcoded	
			telephone1 = 892211 ;
			telephone2 = 555565 ;
			name = " ALASKA Public Hospital " ;
			location = " BUILDING #4 , LANE # 31 " ;
		}
		
		void hospital_info()
		{
			system("cls");
			printf ("\n\n\n");
			cout <<":::::::    " << get_hosp_name() <<"    :::::::"<< endl ;
			printf ("\n\n\n");
			cout <<"TEL : " << get_hosp_number() << endl ;
			cout <<"TEL : " << telephone2 << endl ;
			printf ("\n\n\n");
			cout <<"LOCATION :" << get_hosp_loc() << endl ;
			printf ("\n\n\n");
			
			cout << " 1.PLACES TO EAT " << endl ;
			printf ("\n\n\n");
			cout << " 2.PLACES TO BUY " << endl;
			printf ("\n\n\n");
			cout << " 3.PLACES TO PRAY " << endl ;
			printf ("\n\n\n");
			cout << " 4.GO BACk " << endl ;
			char ch ;
			ch=getch();
			while (1)
			{
				if ( ch == 49)
				{
					system("cls");
					cout << "For Patients and Visitors "<< endl <<"Main Dining Hall || Location: Main Hospital Building, First Floor" <<endl ;
					cout << "Timings:  " << endl << "Breakfast    6:30 a.m. - 11:30 a.m.     (Mon – Sun)" << endl << "Lunch          1:30 a.m. -  2:45 p.m.     (Mon – Sun)"
					<<endl << "Snacks        3:15 p.m. -  6:00 p.m.     (Mon – Sun) " <<endl << "Dinner         6:00 p.m. - 10:00 p.m.    (Mon – Sun)" << endl
					<< "Call: +92 21 3486 1105  Ext. 1105" <<endl ;
					printf ("\n\n");
					cout << " PRESS ENTER " << endl ;
					printf ("\n\n");
					getch();
					
					hospital_info();
				}
				else if (  ch == 50)
				{
					system ("cls");
					cout << " Flower Shop :: Location : Hospital Courtyard "<<endl <<
                    "Timings:  9:00 a.m. to 7:45 p.m.     (Mon – Sat)" << endl <<"Call: +92 21 3486 2944  Ext.  2944" << endl <<
                    "Gift and Snack Shop ::  Location : Hospital Courtyard" << endl <<" Timings:  9:00 a.m. to 7:00 p.m.     (Mon – Sat" << endl <<
					" liberty books :: Location: Hospital Courtyard " << endl
					<< "Timings:  8:00 a.m. to 8:00 p.m.     (Mon – Sat)" << endl ;
					printf ("\n\n");
					cout << "PRESS ENTER " << endl ;
					printf ("\n\n");
					getch();
					hospital_info();
				}
				else if ( ch == 51)
				{
					system ("cls");
					cout << "A segregated prayer area for men and women is located behind the Main Laboratory. Praying "<<endl
					<<"Praying areas for females are located in the Private Wing (First Floor) and in the Neonatal (New Born) Intensive Care Unit (NICU)" <<endl;
					printf ("\n\n");
					cout << " PRESS ENTER " << endl ;
					printf ("\n\n");
					getch();
					hospital_info();
				}
				else if ( ch == 52 )
				{
					main_menu();
				}
				else{
				}
				
			}
		}
		
	
		
		
		
		
		/////////normal menu til now ////////////////
		/////////major subdivided menu down ///////////
		
		
		/// stters and getters 
		void set_hospital_name (const string x)
		{
			this->name = x ;
		}
		void set_hospital_location (const string x)
		{
			this->location = x ;
		}
		void set_tele (const long int x ,const long int y )
		{
			this->telephone1=x;
			this->telephone2=y;
		}
		string get_hosp_name () const
		{
			return name ;
		}
		string get_hosp_loc () const
		{
			return location ;
		}
		long int get_hosp_number() const
		{
			return telephone1 ;
		}
};


class labortary : protected hospital 
{
	private :
		
	public : 
	
		labortary (){
			
		}
		void lab_menu () //to be continued !
		{	
			system("cls");
			cout << " :: LABORTARY  ::   " << "\n\n\n";
			cout << " 1- CHECK PATIENT REQUESTS FOR BLOOD TESTS " << endl ;
			cout << "\n\n" ;
			cout << " 2- CHECK APPROVED BLOOD REQUESTS " << endl ;
			cout << "\n\n" ;
			cout << " 3- END " << endl ;
			char chu ;
			chu=getch() ;
			if ( chu == 49)
			{
				chech_bloodTest ();
			}
			else if ( chu == 50)
			{
//				main_menu() ;
				approved_requests();
			}
			else if ( chu == 51)
			{
				main_menu();
			}	 	
			else
			{
				lab_menu();
			}
		}
		int lab_verification ()
		{
			int s=0;
			string str,str2,c ;
			system("cls");
			cout << "\t" << " :: LABORTARY VERIFICATION  :: " << "\t" << "\n\n\n" ;
			cout << " 1 - VERIFY " << endl ;
			cout << "\n\n" ;
			cout << " 2 - GO BACk " <<endl ;
			char chu;
			chu=getch();
			if ( chu ==49)
			{
				
			
			cout << "ENTER FIRST NAME IN UPPER CASE : "  ;
			cin >>str ;
			
			ifstream obj ;
			obj.open("LABnames.bin");
			if ( obj== NULL){cout << "no filee" ;
			}
			
			while ( obj >> c)
			{
				if ( str == c )
				{
					cout << "\t\t" << "first name matched " << "\t\t" << "\n" ;
					obj >> c ;
					cout<< endl << "ENTER LAST NAME : "   ;
					cin >> str2 ;
					if ( str2 == c)
					{
						cout << "\t\t" << "last name matched " << "\t\t" << "\n" ;
						s=67 ;
					}
				}
			}
			obj.close();
			if (s=67)
			{
				ifstream obj2 ;
				obj2.open("LABpassword.bin");
				obj2>> c ;
				int n = c.length();
 				char chu;
    			// declaring character array
    			char co[n + 1];
 				char ch[n +1] ;
   				// copying the contents of the
   				// string to char array
    			strcpy(co, c.c_str());
				cout << endl << "ENTER PASSWORD : " ;
				for ( int i=0 ; i<n+1 ; i++)
				{
		
					chu=getch();
					if ( chu != 13)
					{
		
						ch[i]=chu ;

						cout << "*" ;
					}
					else 
					{
						break;
					}
				}
				int cp=0;
				for ( int i=0 ; i < n+1 ; i++)
				{
					if ( ch[i] == co[i] )
					{
						cp++ ;
					}
				}
				
				
				if ( cp == n +1)
				{
					cout << "\t\t" << "password matched" << "\t\t" << "\n\n" ;
					return 77 ;
				}
				obj2.close();
			}
			
			}
			else if ( chu == 50)
			{
				main_menu();
			}
			else 
			{
				lab_verification();
			}
		}
		
		void approved_requests()
		{
			system("cls");
			string l , temp ,o;
			cout << "\t\t" << " :: APPROVED BLOOD TEST REQUESTS :: " << "\t" << "\n\n\n" <<endl ;
			cout << "PRESS ENTER TO CHECK " << endl ;
			char chu ;
			chu=getch() ;
			if ( chu == 13)
			{
				ifstream obj,obj2 ;
				
				obj.open("BLOODREQUESTS.txt");
				if ( obj != NULL)
				{
					while ( obj >> l )
					{
						obj2.open((l + "lab" + ".txt").c_str());
						if ( obj2 != NULL)
						{
							while ( obj2 >> temp )
							{
								if ( temp == "APPROVED")
								{
									obj2.seekg(0);
									while ( getline (obj2 , o))
									{
										cout << o << endl ;
									}
									obj2.close();
								}
							
							}
						}
						else 
						{
							approved_requests();
						}
					}
				}
				else 
				{
					approved_requests();
				}
				obj.close();
			}
		}
		void chech_bloodTest () 
		{	system("cls");
			cout << "\t\t"	 << " :: PATIENT BlOOD TEST REQUESTS :: " << "\t\t" << "\n\n\n\n" ;
			cout << "PRESS ENTER TO PROCEED " << "\n\n";
			char chu ;
			int sel ;
			string ch,s1,cr ,temp;
			chu=getch();
//			long int i= 1008702;
			if ( chu == 13)
			{
				cout << " PENDING BLOOD TEST REQUESTS : " << endl ;
				
				fstream obj;
				ifstream obj2,obj3;
				obj3.open("BLOODREQUESTS.txt");
				
				if ( obj3 != NULL)
				{
					while (obj3 >> ch ) 
					{
						
					obj2.open((ch +"lab"+ ".txt").c_str());				
					if ( obj2 != NULL)
					{
						while ( getline (obj2,temp))
						{
							cout << temp<< endl ;
							sel = 6;
						}
						getch();
						cout << "\n\n" << "DO YOU WANT TO APPROVE " << endl ;
						cout << " 1 - YES  " <<endl ;
						cout << " 2 - NO " << endl ;
						cout << " 3 - PROCEED " << endl ;
						chu = getch();
						if ( chu == 49 && sel == 6)
						{
							obj.open(( ch +"lab" + ".txt").c_str(), ios::app);
							obj << "-------------------------------" << endl ;
							obj << "-------------------------------" << endl ;
							obj << "         APPROVED              " << endl ;
							obj << "-------------------------------" << endl ;
							obj << "-------------------------------" << endl ;
							obj.close() ;obj2.close();
							
							cout << "PRESS ENTER TO GO BACK" ;
							chu = getch();
							if ( chu == 13)
							{
								lab_menu() ;
							}
							else {
								lab_menu();
							}
						}
						else if ( chu == 50 )
						{
							obj2.close();
							remove ((ch + ".txt").c_str());
							remove ("BLOODREQUESTS.txt");
							
							ofstream obj8 ;
							obj8.open("BLOODREQUESTS.txt");
							while (obj3 >> ch)
							{
								obj8<< ch << endl ;
								
							}
							obj8.close();
//							
							cout << "PRESS ENTER TO GO BACK" ;
							chu = getch();
							if ( chu == 13)
							{
								lab_menu() ;
							}
							else {
								lab_menu();
							}
						}
						else if ( chu == 51)
						{
							
						}
						else 
						{
							chech_bloodTest ();
						}
						
					}
					else 
					{
						
						chech_bloodTest ();
					}
					
					}//end of while lop
					obj3.close();
				}
			}
			
		}	
};

class pharmacy : protected hospital
{
	private :
		string firstName;
		string lastName ;
		string userName;
		string Pass ;
		int prodQty;
		float bill ;
		double amt ; // amt acquired by file !
		long int patientID ;
		string MRnumber ;
		string docDept ;
	public :
		pharmacy ()
		{
			MRnumber="";
			docDept="";
			name = "";
			prodQty =0 ;
			bill =0.0  ;
			Pass ="";
			patientID =0;
			amt=0.0 ;
			lastName ="";
			firstName ="";userName="";
		} 	
		
		int pharmacy_verification ()  
		{
			system ("cls");
			cout << " :: VERIFICATION :: " << "\n\n" ;
			cout << " CHOOSE YOUR DESIGNATION : " << endl ;
			char chu ;
			cout << "\n\n";
			cout << " 1 - PATIENT " << endl ;
			cout << "\n\n" ;
			cout << " 2 -  DOCTOR " << endl ;
			cout << "\n\n" ;
			cout << " 3 - GO BACK " << endl ;
			chu=getch();
			int sel=0 , nl=0,c=0;
			string str,strt;
			if ( chu == 49)
			{
				system("cls");
				cout <<"\t\t"<< " :: PATIENT VERIFICATION :: " <<"\t\t"<< "\n\n\n\n" ;
				ifstream obj2,obj ;
				cout << "ENTER USER NAME  : " ;
				fflush(stdin);
				getline(cin , userName ) ;
				obj2.open((userName + "password" +".bin").c_str());
				
				while ( obj2 >> str)
				{
						if ( str == "NAME:")
						{
							getline(obj2 ,str );
							if ( str == " " + userName )
							{
								cout << "\t\t" << "user name matched " <<"\n"<< endl ;
			  					sel =344 ;
							  	
							}
						}
						fflush(stdin);
					    if ( str == "PASSWORD:"  && sel == 344)
						{
							obj2 >> str ;
							nl = str.length();
							cout << " ENTER PASSWORD : " << endl;
							char ch[nl+1] ;
							fflush(stdin);
			  				for ( int i=0 ; i<nl+1 ; i++) 
							{
								chu=getch();
								if ( chu != 13)
								{
		
									ch[i] = chu ;
									cout << "*" ;
								}
								else if ( chu == 13)
								{
									break;
								}
							}
							char co[nl + 1];
    						// copying the contents of the
    						// string to char array
   							strcpy(co, str.c_str());	
   							for ( int i=0 ; i <nl+1 ; i++)
							{
								if ( ch[i] == co[i] )
								{
								 c++ ;
								}
							}
							if ( c == nl+1 || c == nl)
							{
								cout << "\t\t" << "password matched " << endl ;
								getch();
								return 5 ;
								break;
							}
						}
					
				}
				obj2.close();
						
			}
			
			else if ( chu == 50)
			{
				system("cls") ;
				cout << "\t\t"<<" :: DOCTOR'S VERIFICATION :: " << "\t\t" << "\n\n\n\n";
							string  n,n2 ;
			int c=0 , nl;
			char chu;
			ifstream obj ;
			ifstream obj2 ;
			obj2.open("DOCTORSpassword.bin");
			obj.open("DOCTORSname.txt");
			if (obj == NULL || obj2 == NULL )
			{
				cout << "no file "; main_menu();
			}
			cout << "(in upper case)" << endl ;
			cout << "ENTER FIRST NAME : " << endl ;
			cin >> firstName ;
			
			while ( obj >> n )
			{
				if ( n == firstName )
				{
					cout << "\t\t"<< "FIRST NAME MATCHED " << "\t" << endl ;
					c++ ;//inc
					cout << "ENTER LAST NAME : " << endl ;;
					cin >> lastName ;
					obj >> n ;
					if ( n == lastName )
					{
						cout << "\t\t"<< "LAST NAME MATCHED " << "\t" << endl ;
						c++ ;//inc-> 2
						if ( c == 2)
						{
						
							cout <<"\n\n " << " ENTER PASSWORD : " << endl ;
							
							while ( obj2 >> n2)
							{
								nl = n2.length();
								obj2.seekg(0);
								break;
							}
							char ch[nl + 1];
							for ( int i=0 ; i<nl+1 ; i++) //8 chaaracters long password
							{
		
								chu=getch();
								if ( chu != 13)
								{
		
									ch[i] = chu ;
									cout << "*" ;
								}
								else if ( chu == 13)
								{
									break;
								}
							}
							int c=0;
							char co[nl + 1];
 
    							// copying the contents of the
    							// string to char array
   							strcpy(co, n2.c_str());
						
							while ( obj2 >> n2)
							{
								for ( int i=0 ; i <nl+1 ; i++)
								{
									if ( ch[i] == co[i] )
									{
									 c++ ;
									}
								}
								
								if ( c==7 || c == 8 )
								{
									cout << "\t\t"<< "PASSWORD MATCHED " << "\t" << endl ;
									getch();
									return 6 ;
									obj2.close();
									break ;
								}
								else{
									cout << "incorrect password !" << endl ;
									sleep(1);
									
								}
							}
						}
					}				
					
				}
			
				
			}
			
			obj.close();
//			obj2.close();
				
			}
			else if (chu == 51)
			{
				main_menu();
				
			}
			else
			{
				pharmacy_verification () ;
			}
			
		}
		
	void pharmacy_open_patient  ()
		{
			system ("cls");
				
				system("cls");
				cout << "ENTER PATIENT ID : " << endl ;
				cin >> patientID;
				cout << "\n\n\n" ;
				cout << "Press enter to select pharmacy items : " << endl ;
				cout << "\n\n";
				char sel ;
				sel =getch();
				if ( sel == 13)
				{
					ifstream obj ;
					obj.open("Pharmacy.txt") ;
					if ( obj == NULL )
					{
						cout << "NO file persent " << endl ;
						exit (1);
					}
					string cr;
					while ( getline(obj,cr))
					{
						cout << cr << endl;
					}
				
					obj.close();
					int n,count =0 ;
					char next ;
					cout << "ENTER NUMBER OF MEDICINES YOU WANT : " << endl ;
					cin >> sel ;
					for (int i=0 ; i<sel ; i++)
					{
						
					cout << "\n\n"<<"ENTER ITEM NUMBER  : " << endl ;
					cin >> n ;
					fflush(stdin);
					obj.open("Pharmacy.txt");
					if ( obj == NULL){cout << "NO FILE " << endl ;exit(1);
					}
					bill=0.0;
					while (obj.get(next))
					{
						if ( next == '\n')
						{
							count++;
						}
						if ( count == n-1+2)
						{
							string ch ,s1;
							obj >> amt ;
							
							ifstream obj2 ;
							ostringstream strg; // to cnvert long int -> string 
							strg<< patientID ;
							s1 = strg.str();	
							ch= s1 + "details";
							
							obj2.open(( ch + ".txt").c_str());
							if (obj2 != NULL )
							{
								obj2.close();
								cout << " ENTER ITEM QUANTITY : " ;
								cin >> prodQty ;
								bill = bill + prodQty*amt ;
								
								fstream obj3 ;
								obj3.open(( s1  + "invoice" + ".txt").c_str(),ios :: app);
								if (obj3== NULL){cout << "NO FILE " << endl ;
								}
								obj3 << "MEDICINE: $ " << bill << endl ;
								obj3.close();
								cout << "\n\n";
								cout << "1 - ENTER ANY OHER MEDICINE " << endl ;
								cout << " 2 - GO BACK " << endl ;
								char chu ;
								chu=getch();
								if ( chu == 49)
								{
									
								}
								else if ( chu == 50)
								{
									obj3.close();
									pharmacy_verification();
								}
							}
							break;
						}
					}
					
					}
				}	
//					obj.close();
				
		}
			
		void pharmacy_open_doctor  ()
		{
				
			system("cls");
			string dr,str,str2,cr ;
			int s=0 ,n;
			cout << "CHOOSE DOCTOR's DEPARTMENT : " <<endl ;
			cout << "\n\n\n";
			cout << " 1 - EYE,EAR,NOSE AND THROAT" << endl ;
			cout << " 2 - CHILDRENS HOSPITAL" <<endl;			
			cout << " 3 - KIDNEY AND BLADDER " << endl;
			cout << " 4 - ONCOLOGY" <<endl;
			cout << " 5 - DENTAL" << endl;
			cout << " 6 - CLINICAL IMAGING (RADIOLOGY) " << endl ;
			cout << " 7 - CARDIOLOGY" <<endl ;
			cout << " 8 - NEUROLOGY " <<endl ;
			cout << " 9 - DERMATOLOGY" << endl ; 
			cout << " 10. GO BACK " << endl ;
			int sel;
			cin >> sel ;
			if ( sel == 1){
					docDept = "eye, ear, nose and throat" ;
				}
			else if ( sel == 2)
			{
				docDept = "childrens hospital" ;
			}		
			else if ( sel == 3)
			{
				docDept = "kidney, bladder" ;
			}	
			else if ( sel == 4)
			{
				docDept="oncology";
			}	
			else if ( sel == 5)
			{
				docDept= "dental" ;
			}
			else if ( sel == 6)
			{
				docDept="clinical imaging" ;
			}
			else if ( sel == 7)
			{
				docDept = "cardiology";
			}
			else if ( sel == 8)
			{
				docDept="neurology";
			}
			else if ( sel == 9)
			{
				docDept="dermatology";
			}
			else if ( sel == 10)
			{
				main_menu();
			}
		
					
			cout <<endl << "ENTER DOCTOR's MR# NUMBER :  " ;
			cin >> MRnumber ;
			ifstream obj,obj2;
			obj.open((docDept + ".txt").c_str());
			obj2.open((docDept + "2" +".txt").c_str());
			if ( obj!=NULL)
			{
				while ( obj >> str)
				{
					if ( str == MRnumber )
					{
						cout << "\t\t" << "mr# matched " << "\n\n";
						obj.seekg(0);
						getline(obj,dr);
						cout << "WELCOME DR." << dr << endl ;
						getch();
						obj.close();
						s=454 ;
						break;
					}
				}
			}
				
			if ( obj2!=NULL)
				{
				
					while ( obj2 >> str2)
					{
						if ( str2 == MRnumber )
						{
							cout << "\t\t" << "mr# matched " << "\n\n";
							obj2.seekg(0);
							getline(obj2,dr);
							cout << "WELCOME DR." << dr << endl ;
							s=454 ;
							getch();
							obj2.close();
							break;
						}
//						else 
//						{
//							cout << "incorrect MR" ;
//							getch();
//							pharmacy_verification ();
//						}	
					}
				}
				
				if ( s == 454)
				{
					ifstream obj3 ;
					obj3.open("Pharmacy.txt") ;
					if ( obj3 == NULL )
					{
						cout << "NO file persent " << endl ;
						exit (1);
					}
					string cr;
					while ( getline(obj3,cr))
					{
						cout << cr << endl;
					}
				
					obj3.close();
					int n,count =0,sel ;
					char next ;
					cout << "ENTER NUMBER OF MEDICINES YOU WANT : " << endl ;
					cin >> sel ;
					for (int i=0 ; i<sel ; i++)
					{
					
					cout << "\n\n"<<"ENTER ITEM NUMBER  : " << endl ;
					cin >> n ;
					obj3.open("Pharmacy.txt");
//					if ( obj == NULL){cout << "NO FILE " << endl ;exit(1);
//					}
					bill=0.0;
					obj3.seekg(0);
					while (obj3.get(next))
					{
						if ( next == '\n')
						{
							count++;
						}
						if ( count == n-1+2)
						{
							string ch ,s1;
							obj3 >> amt ;
							
							ofstream obj4 ;
							
							obj4.open(( MRnumber +"med"+ ".txt").c_str());
							if (obj4 != NULL )
							{
								obj4.close();
								cout << " ENTER ITEM QUANTITY : " ;
								cin >> prodQty ;
								bill = bill + prodQty*amt ;
								
								fstream obj5 ;
								obj5.open(( MRnumber+ "med" + ".txt").c_str(),ios :: app);
								if (obj5== NULL){cout << "NO FILE " << endl ;
								}
								obj5 << "MEDICINE: $ " << bill << endl ;
								obj5.close();
								cout << "\n\n";
								cout << "1 - ENTER ANY OHER MEDICINE " << endl ;
								cout << " 2 - GO BACK " << endl ;
								char chu ;
								chu=getch();
								if ( chu == 49)
								{
									
								}
								else if ( chu == 50)
								{
									pharmacy_verification();
								}
							}
							break;
						}
					}
	
					obj3.close();
					}//end of for loop
				}
			
		}
		
	};
		


class admin : protected hospital
{
	private : 
	
		long int patientID ;
		int percentageAid ;
	public : 
	
	admin ()
	{
		patientID =0;
		percentageAid=0;
	}
	int admin_verification ()
	{
		int s,nl,ce=0;
		string str,str2,c ;
		char chu ;
		system("cls");
		cout << "\t" << " :: ADMIN VERIFICATION  :: " << "\t" << "\n\n\n" ;
		cout << "ENTER FIRST NAME IN UPPER CASE : "  ;
		cin >>str ;
		
		ifstream obj ;
		obj.open("ADMINnames.bin");
		if ( obj== NULL){cout << "no filee" ;
		}
		
		while ( obj >> c)
		{
			if ( str == c )
			{
				cout << "\t\t" << "first name matched " << "\t\t" << "\n" ;
				obj >> c ;
				cout<< endl << "ENTER LAST NAME : "   ;
				cin >> str2 ;
				if ( str2 == c)
				{
					cout << "\t\t" << "last name matched " << "\t\t" << "\n" ;
					s=67 ;
				}
				else
				{
					cout << "\t\t"<< "last name not matched " << "\t\t" << endl ;
					sleep(1);
					admin_verification ();
				}	
			}
		}
		obj.close();
		if (s=67)
		{
			ifstream obj2 ;
			obj2.open("ADMINpassword.bin");
			obj2>> c ; // c->string
			
			nl = c.length(); // c-> length
			char ch[nl + 1]; 
			char co[nl + 1];
			strcpy(co, c.c_str()); //c-> char array
			
			cout << endl << "ENTER PASSWORD : " ;
			for ( int i=0 ; i<nl+1 ; i++) //8 chaaracters long password
			{

				chu=getch();
				if ( chu != 13)
				{
					ch[i] = chu ;
					cout << "*" ;
				}
				else if ( chu == 13)
				{
					break;
				}
			}
			
			// fr comapirng 
			for ( int i=0 ; i <nl+1 ; i++)
			{
				if ( ch[i] == co[i] )
				{
					ce++ ;
				}
			}
			
			if ( ce == nl+1 )
			{
				cout << "\t\t" << "password matched" << "\t\t" << "\n\n" ;
				return 77 ;
			}
			obj2.close();
		}
	}
	
	void admin_menu() 
	{
		system("cls");
		cout << "\t\t" << " :: ADMIN MENU :: " << "\t\t" << "\n\n\n\n" ;
		cout << " 1 - APPROVE / DISAPPROVE FINANCIAL AID REQUESTS " << endl ;
		cout << "\n\n" ;
		cout << " 2 - GO BACK " << endl;
		char chu ;
		chu =getch();
		if ( chu == 49)
		{
			app_rej_req();
		}
		else if ( chu == 50 )
		{
			main_menu();
		}
		else  
		{
			admin_menu() ;
		}
	}
	
	void app_rej_req()
	{
		system("cls");
		cout << " 1 - VIEW APPROVE REQUESTS " << endl ;
		cout << "\n\n" ;
		cout << " 2 - GO BACK " << endl ;
		char chu ;
		string ch,temp ;
		int sel =0;
		chu =getch();
		if ( chu == 49)
		{
			system("cls");
			
			ifstream obj2,obj3;
			obj3.open("AIDrequests.bin");
			if ( obj3 != NULL)
			{
				while (obj3 >> ch ) 
				{	
					obj2.open((ch +"aid"+ ".txt").c_str());				
					if ( obj2 != NULL)
					{
						while ( getline (obj2,temp))
						{
							cout << temp<< endl ;
							sel = 6;
						}
						getch();
						cout << "\n\n" << "DO YOU WANT TO APPROVE " << endl ;
						cout << " 1 - YES  " <<endl ;
						cout << " 2 - NO " << endl ;
						chu = getch();
						if ( chu == 49 && sel == 6)
						{
							fstream obj ;
							obj.open(( ch +"aid" + ".txt").c_str(), ios::app);
							obj << "\n\n" << "::APPROVED::" << "\n" ;
							cout << "APPROVED " << endl ;
							cout << " ENTER PERCENTAGE TO BE GIVEN ON TOTAL BILL FOR PATIENT AID : " << endl ;
							cin >> percentageAid ;
							obj <<"\n" <<"FINANCIAL AID GIVEN(in %): " << percentageAid << endl ;
							
							
							obj.close() ;obj2.close();
							cout << "PRESS ENTER TO GO BACK" ;
							chu = getch();
							if ( chu == 13)
							{
								admin_menu() ;
							}
							else {
								admin_menu();
							}
						}
						else if ( chu == 50 )
						{
							obj2.close();
							
							fstream obj ;
							obj.open(( ch +"aid" + ".txt").c_str(), ios::app);
							obj << "\n\n" << "::REJECTED::" << "\n" ;
							obj.close() ;obj2.close();
							cout << " REQUEST REJECTED " << endl ;
							
							cout << "PRESS ENTER TO GO BACK" ;
							chu = getch();
							if ( chu == 13)
							{
								app_rej_req() ;
							}
							else {
								app_rej_req();
							}
						}
						else 
						{
							app_rej_req();
						}
						
					}
					else 
					{
						
						app_rej_req()
					;}
					
					}//end of while lop
					obj3.close();
			}
		}
		
		
		
		else if ( chu == 50)
		{
			admin_menu();
		}
		else {app_rej_req();
		}
	}
};


void main_menu()
	{	
		us();
		getch();
		system("cls");
		cout << "\t" <<  " :: MAIN MENU :: " << "\t" ;
		cout << "\n\n" ;
		cout <<" 1. PATIENT "  << endl ;
		cout << "\n\n" ;
		cout <<" 2. DOCTOR " <<endl ;
		cout << "\n\n" ;
		cout << " 3. LABORTARY" << endl ;
		cout << "\n\n" ;
		cout << " 4. PHARMACY " << endl;
		cout << "\n\n" ;
		cout << " 5. ADMINISTRATION " << endl ;
		cout << "\n\n" ;
		cout << " 6. HOSPITAL INFORMAION" << endl ;
		cout << "\n\n";
		cout << " 7. EXIT  " ;
		char ch;
		while (1)
		{
			
		ch= getch();
		if ( ch == 49) 
		{
			patient p ;
			if ( p.patient_verification () == 5 )
			{
				p.patient_menu();	
			}
			
			break;
		}
		else if ( ch == 50)
		{
			doctor dr ;
			if ( dr.doctor_verification() == 6)
			{
				dr.docMenu();
			}
			break;
		}
		else if ( ch == 51)
		{
			labortary l1 ;
			if ( l1.lab_verification()  == 77 )
			{
				l1.lab_menu();
			}
			
			break ;
		}
		else if ( ch == 52)
		{
			pharmacy p1;
			int l ;
			l=p1.pharmacy_verification() ;
			if ( l == 5 )
			{
				p1.pharmacy_open_patient();
			}
			else if ( l == 6)
			{
				p1.pharmacy_open_doctor();
			}
			
		}
		else if ( ch == 53)
		{
			admin a1 ;
			if ( a1.admin_verification() == 77)
			{
				a1.admin_menu();
			}
			
		}
		else if(ch == 54)
		{
			hospital h;
			h.hospital_info();
		}
		else if ( ch == 55)
		{
			exit(1);
		}
			
		} 
			
	}



int main ()
{
	system("Color 3B");
	main_menu();
	
	
}
