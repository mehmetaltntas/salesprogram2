#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>


using namespace std;

class Pharmacy{

private:
    int pharmacy_ID;
    string pharmacy_name;
    string pharmacy_address;

public:

    fstream PharmacyList,File,File2,File3,File4;

    Pharmacy(){
        //  cout << "default ctor called\n" ;
        pharmacy_ID = 0;
        pharmacy_name = "No name";
        pharmacy_address = "No name";
    }
    Pharmacy(int ph_ID,char* ph_name,char* ph_address){

        // cout << "ctor with argument called\n" ;
        pharmacy_ID = ph_ID;
        pharmacy_name = ph_name;
        pharmacy_address = ph_address;

    }
    Pharmacy(const Pharmacy& other){

        //  cout << "copy ctor called\n" ;
        pharmacy_ID = other.pharmacy_ID;
        pharmacy_name = other.pharmacy_name;
        pharmacy_address = other.pharmacy_address;
    }
    Pharmacy& operator=(const Pharmacy& other){

        //   cout << "assignment operator called\n" ;
        pharmacy_ID = other.pharmacy_ID;
        pharmacy_name = other.pharmacy_name;
        pharmacy_address = other.pharmacy_address;
        return *this;
    }
    void setPharmacyID(int ph_ID){

        pharmacy_ID = ph_ID;
    }
    void setPharmacyName(string ph_name){

        pharmacy_name = ph_name;
    }
    void setPharmacyAddress(string ph_address){
        pharmacy_address = ph_address;
    }
    int getPharmacyID() const{
        return pharmacy_ID;
    }
    string getPharmacyName(){
        return pharmacy_name;
    }
    string  getPharmacyAddress(){
        return pharmacy_address;
    }
    void InputPharmacy(){

        Pharmacy Pharmacy_1,Pharmacy_2,Pharmacy_3,Pharmacy_4;
							
        int ID_1 = 1 ,ID_2 = 2 ,ID_3 = 3 ,ID_4 = 4;
        string name_1 = "AKIN",name_2 = "ISIK" , name_3 = "MUTLU" , name_4 = "IRMAK";
        string address_1 = "Pasa Mahallesi" , address_2 = "Haci Yusuf Mahallesi" , address_3 = "Tatli Su Mahallesi" , address_4 = "Aydincik Mahallesi";
        Pharmacy_1.setPharmacyID(ID_1)  ,   Pharmacy_1.setPharmacyName(name_1) , Pharmacy_1.setPharmacyAddress(address_1);
        Pharmacy_2.setPharmacyID(ID_2)  ,   Pharmacy_2.setPharmacyName(name_2) , Pharmacy_2.setPharmacyAddress(address_2);
        Pharmacy_3.setPharmacyID(ID_3)  ,   Pharmacy_3.setPharmacyName(name_3) , Pharmacy_3.setPharmacyAddress(address_3);
        Pharmacy_4.setPharmacyID(ID_4)  ,   Pharmacy_4.setPharmacyName(name_4) , Pharmacy_4.setPharmacyAddress(address_4);



        PharmacyList.open("Pharmacy_List.dat",ios::out|ios::in|ios::app);
        File.open("AKIN_Medicine.dat",ios::out|ios::in|ios::app);
        File2.open("ISIK_Medicine.dat",ios::out|ios::in|ios::app);
        File3.open("MUTLU_Medicine.dat",ios::out|ios::in|ios::app);
        File4.open("IRMAK_Medicine.dat",ios::out|ios::in|ios::app);

        if (!PharmacyList || !File || !File2 || !File3 || !File4){
            cout << "Error opening File"<<endl;
            exit(1);
        }

        else{

            PharmacyList.setf(ios::left);
        //  PharmacyList<<setw(5)<<"ID"<<setw(10)<<"NAME"<<setw(10)<<"Address"<<endl<<endl;
            PharmacyList<<setw(5)<<Pharmacy_1.pharmacy_ID<<setw(10)<<Pharmacy_1.pharmacy_name<<setw(10)<<Pharmacy_1.pharmacy_address<<endl;
            PharmacyList<<setw(5)<<Pharmacy_2.pharmacy_ID<<setw(10)<<Pharmacy_2.pharmacy_name<<setw(10)<<Pharmacy_2.pharmacy_address<<endl;
            PharmacyList<<setw(5)<<Pharmacy_3.pharmacy_ID<<setw(10)<<Pharmacy_3.pharmacy_name<<setw(10)<<Pharmacy_3.pharmacy_address<<endl;
            PharmacyList<<setw(5)<<Pharmacy_4.pharmacy_ID<<setw(10)<<Pharmacy_4.pharmacy_name<<setw(10)<<Pharmacy_4.pharmacy_address<<endl;
        }
         cout << "\n\n\t\tPHARMACIES CREATED AUTOMATICALLY"<<endl;
         
         File.close();
         File2.close();
         File3.close();
         File4.close();
         
      	       
    }
    void CreateNewPharmacy(int i){

        Pharmacy newPharmacy;

        int new_ID;
        string NewPhName;
        string NewPhAddress;

        new_ID = i;
        cout<<"Enter the name of the pharmacy you want to create -> ";
        cin>>NewPhName;
        cout<<"Enter the address of the pharmacy you want to create -> ";
        cin>>NewPhAddress;

        newPharmacy.setPharmacyID(new_ID);
        newPharmacy.setPharmacyName(NewPhName);
        newPharmacy.setPharmacyAddress(NewPhAddress);

        

        fstream Filee;

        NewPhName.append("_Medicine.dat");
        Filee.open(NewPhName.c_str(), ios::out|ios::in|ios::app);
        PharmacyList.open("PharmayList.dat",ios::out|ios::in|ios::app);
        if(!Filee){
        	cout<<"ERROR OPENING FILE";
        	exit(1);
		}

         PharmacyList.setf(ios::left);
        PharmacyList<< setw(5) << newPharmacy.pharmacy_ID << setw(10) <<newPharmacy.pharmacy_name << setw(10)
                    << newPharmacy.pharmacy_address << endl;
         Filee.close();
         PharmacyList.close();
         getch();

    }
    void ShowPharmacyInfo(){

        fstream myFile;
        string myLine;
		system("cls");
        myFile.open("Pharmacy_List.dat", ios::in | ios::out | ios::app);

        if(!myFile)
        {
            cout << "Error opening the file!";
            exit(1);
        }

        myFile.seekg(ios::beg);
        if(myFile.is_open())
        {
            while( getline(myFile, myLine))
            {
                cout <<"\n\n\t\t" <<myLine << endl;
            }

            myFile.close();
        }
        else
        {
            cout << "Unable to open the file!";
        }
        myFile.close();
        getch();
    }

void ShowAnyPharmacy(){

    Pharmacy p;
    string name;
    fstream File5;

    cout<<"Enter your pharmacy name ->";
    cin>>name;

    File5.open("Pharmacy_List.dat", ios::in | ios::out | ios::app);

    if(!File5)
    {
        cout << "Error opening the file!";
        exit(1);
    }


    while(!File5.eof()){
        File5>>p.pharmacy_ID;
        File5>>p.pharmacy_name;
        File5>>p.pharmacy_address;

        if(p.pharmacy_name == name){

            cout<<p.pharmacy_ID<<"\t"<<p.pharmacy_name<<"\t"<<p.pharmacy_address<<endl;
        }

        else{
            cout<<"The pharmacy is not found !";
            break;
        }
    }
    File5.close();
    getch();

}

void MedicationListForAnyPharmacy(){


        fstream file;
        string line;
		string filename;
		
		cout<<"\n\nEnter the pharmacy name ->";
		cin>>filename;
		
        filename.append("_Medicine.dat");
        file.open(filename.c_str(),ios::out|ios::in|ios::app);

        if (!file){
            cout << "Error opening File"<<endl;
            exit(1);
        }
		system("cls");
        file.seekg(ios::beg);
        
        if(file.is_open())
        {
        	cout<<"\n\n"<<endl;
            while( getline(file, line))
            {
                cout <<"\t"<<line << endl;
            }

            file.close();
        }
        else
        {
            cout << "Unable to open the file!";
        }
        
        file.close();
        getch();
    }

	
};


class Medicine{

private:
    int medicine_ID;
    int medicine_amount;
    double medicine_price;
    string medicine_name;
    Pharmacy pPharmacy;

public:
        Medicine(){
          //  cout << "default ctor called\n" ;
            medicine_ID = 0;
            medicine_amount = 0;
            medicine_price = 0.0;
            medicine_name = "No name";


        }
        Medicine(int med_ID,int med_amount,double med_price,char* med_name){

          //  cout << "ctor with argument called\n" ;
            medicine_ID = med_ID;
            medicine_amount = med_amount;
            medicine_price = med_price;
            medicine_name = med_name;

        }
        Medicine(const Medicine& other){

            cout << "copy ctor called\n" ;
            medicine_ID = other.medicine_ID;
            medicine_amount = other.medicine_amount;
            medicine_price = other.medicine_price;
            medicine_name = other.medicine_name;
        }
        Medicine& operator=(const Medicine& other){

           //  cout << "assignment operator called\n" ;
             medicine_ID = other.medicine_ID;
             medicine_amount = other.medicine_amount;
             medicine_price = other.medicine_price;
            medicine_name = other.medicine_name;

            return *this;
        }
        void setMedicineID(int med_ID){
            medicine_ID = med_ID;
        }
        void setMedicineAmount(int med_amount){
                medicine_amount = med_amount;
        }
        void setMedicinePrice(double med_price){
            medicine_price = med_price;
        }
        void setMedicineName(string med_name){
            medicine_name =med_name;
        }
        int getMedicineID(){

            return medicine_ID;
        }
        int  getMedicineAmount(){
            return medicine_amount;
        }
        double getMedicinePrice(){
            return medicine_price;
        }
        string getMedicineName(){
            return medicine_name;
        }

void InputMedicine(){

            Medicine Medicine_1 ,Medicine_2 ,Medicine_3  ,Medicine_4 ,Medicine_5 ,Medicine_6 ,Medicine_7 ,Medicine_8 ,Medicine_9 ,Medicine_10;

            Medicine_1.medicine_ID = 1;         Medicine_1.medicine_name = "PAROL";     Medicine_1.medicine_price = 1.12;	Medicine_1.medicine_amount = 10;
            Medicine_2.medicine_ID = 2;         Medicine_2.medicine_name = "NOVALGIN";  Medicine_2.medicine_price = 2.24;	Medicine_2.medicine_amount = 20;
            Medicine_3.medicine_ID = 3;         Medicine_3.medicine_name = "ALVARES";   Medicine_3.medicine_price = 3.36;	Medicine_3.medicine_amount = 30;
            Medicine_4.medicine_ID = 4;         Medicine_4.medicine_name = "GRIPIN";    Medicine_4.medicine_price = 4.48;	Medicine_4.medicine_amount = 40;
            Medicine_5.medicine_ID = 5;         Medicine_5.medicine_name = "MINOSET";   Medicine_5.medicine_price = 6.00;	Medicine_5.medicine_amount = 50;
            Medicine_6.medicine_ID = 6;         Medicine_6.medicine_name = "VERMIDON";  Medicine_6.medicine_price = 7.20;	Medicine_6.medicine_amount = 60;
            Medicine_7.medicine_ID = 7;         Medicine_7.medicine_name = "TEMPRA";    Medicine_7.medicine_price = 8.40;	Medicine_7.medicine_amount = 70;
            Medicine_8.medicine_ID = 8;         Medicine_8.medicine_name = "ZOLBEN";    Medicine_8.medicine_price = 9.60;	Medicine_8.medicine_amount = 80;
            Medicine_9.medicine_ID = 9;         Medicine_9.medicine_name = "REVANIN";   Medicine_9.medicine_price = 10.80;	Medicine_9.medicine_amount = 90;
            Medicine_10.medicine_ID = 10;       Medicine_10.medicine_name = "SARA";     Medicine_10.medicine_price = 12.00;	Medicine_10.medicine_amount = 100;
            
            fstream file_1,file_2,file_3,file_4;
            
            file_1.open("AKIN_Medicine.dat") , file_2.open("ISIK_Medicine.dat") , file_3.open("MUTLU_Medicine.dat") , file_4.open("IRMAK_Medicine.dat");
            
            if(!file_1 || !file_2 || !file_3 || !file_4){
            	cout<<"ERROR OPENING FILE";
            	exit(1);
			}
			
			file_1.setf(ios::left);
            //	file_1<<setw(5)<<"ID"<<setw(10)<<"NAME"<<setw(10)<<"PRICE"<<setw(10)<<"AMOUNT"<<endl<<endl;
            	file_1<<setw(5)<<Medicine_1.medicine_ID<<setw(10)<<Medicine_1.medicine_name<<setw(10)<<Medicine_1.medicine_price*5.9<<Medicine_1.medicine_amount*10<<endl;
            	file_1<<setw(5)<<Medicine_2.medicine_ID<<setw(10)<<Medicine_2.medicine_name<<setw(10)<<Medicine_2.medicine_price*4.8<<Medicine_2.medicine_amount*9<<endl;
            	file_1<<setw(5)<<Medicine_3.medicine_ID<<setw(10)<<Medicine_3.medicine_name<<setw(10)<<Medicine_3.medicine_price*3.7<<Medicine_3.medicine_amount*8<<endl;
            	file_1<<setw(5)<<Medicine_4.medicine_ID<<setw(10)<<Medicine_4.medicine_name<<setw(10)<<Medicine_4.medicine_price*2.6<<Medicine_4.medicine_amount*7<<endl;
            	file_1<<setw(5)<<Medicine_5.medicine_ID<<setw(10)<<Medicine_5.medicine_name<<setw(10)<<Medicine_5.medicine_price*1.5<<Medicine_5.medicine_amount*6<<endl;
            	file_1<<setw(5)<<Medicine_6.medicine_ID<<setw(10)<<Medicine_6.medicine_name<<setw(10)<<Medicine_6.medicine_price*0.9<<Medicine_6.medicine_amount*5<<endl;
            	file_1<<setw(5)<<Medicine_7.medicine_ID<<setw(10)<<Medicine_7.medicine_name<<setw(10)<<Medicine_7.medicine_price*0.8<<Medicine_7.medicine_amount*4<<endl;
            	file_1<<setw(5)<<Medicine_8.medicine_ID<<setw(10)<<Medicine_8.medicine_name<<setw(10)<<Medicine_8.medicine_price*0.7<<Medicine_8.medicine_amount*3<<endl;
            	file_1<<setw(5)<<Medicine_9.medicine_ID<<setw(10)<<Medicine_9.medicine_name<<setw(10)<<Medicine_9.medicine_price*0.6<<Medicine_9.medicine_amount*2<<endl;
            	file_1<<setw(5)<<Medicine_10.medicine_ID<<setw(10)<<Medicine_10.medicine_name<<setw(10)<<Medicine_10.medicine_price*0.5<<Medicine_10.medicine_amount*1<<endl;
            	
			file_2.setf(ios::left);
            //	file_2<<setw(5)<<"ID"<<setw(10)<<"NAME"<<setw(10)<<"PRICE"<<setw(10)<<"AMOUNT"<<endl<<endl;
				file_2<<setw(5)<<"ID"<<setw(10)<<"NAME"<<setw(10)<<"PRICE"<<setw(10)<<"AMOUNT"<<endl<<endl;
            	file_2<<setw(5)<<Medicine_1.medicine_ID<<setw(10)<<Medicine_1.medicine_name<<setw(10)<<Medicine_1.medicine_price*8.0<<Medicine_1.medicine_amount*5<<endl;
            	file_2<<setw(5)<<Medicine_2.medicine_ID<<setw(10)<<Medicine_2.medicine_name<<setw(10)<<Medicine_2.medicine_price*7.5<<Medicine_2.medicine_amount*4<<endl;
            	file_2<<setw(5)<<Medicine_3.medicine_ID<<setw(10)<<Medicine_3.medicine_name<<setw(10)<<Medicine_3.medicine_price*7.0<<Medicine_3.medicine_amount*3<<endl;
            	file_2<<setw(5)<<Medicine_4.medicine_ID<<setw(10)<<Medicine_4.medicine_name<<setw(10)<<Medicine_4.medicine_price*7.0<<Medicine_4.medicine_amount*2<<endl;
            	file_2<<setw(5)<<Medicine_5.medicine_ID<<setw(10)<<Medicine_5.medicine_name<<setw(10)<<Medicine_5.medicine_price*6.5<<Medicine_5.medicine_amount*1<<endl;
            	file_2<<setw(5)<<Medicine_6.medicine_ID<<setw(10)<<Medicine_6.medicine_name<<setw(10)<<Medicine_6.medicine_price*5.5<<Medicine_6.medicine_amount*1<<endl;
            	file_2<<setw(5)<<Medicine_7.medicine_ID<<setw(10)<<Medicine_7.medicine_name<<setw(10)<<Medicine_7.medicine_price*5.0<<Medicine_7.medicine_amount*2<<endl;
            	file_2<<setw(5)<<Medicine_8.medicine_ID<<setw(10)<<Medicine_8.medicine_name<<setw(10)<<Medicine_8.medicine_price*4.5<<Medicine_8.medicine_amount*3<<endl;
            	file_2<<setw(5)<<Medicine_9.medicine_ID<<setw(10)<<Medicine_9.medicine_name<<setw(10)<<Medicine_9.medicine_price*4.0<<Medicine_9.medicine_amount*4<<endl;
            	file_2<<setw(5)<<Medicine_10.medicine_ID<<setw(10)<<Medicine_10.medicine_name<<setw(10)<<Medicine_10.medicine_price*3.5<<Medicine_10.medicine_amount*5<<endl;
			
			file_3.setf(ios::left);
            //	file_3<<setw(5)<<"ID"<<setw(10)<<"NAME"<<setw(10)<<"PRICE"<<setw(10)<<"AMOUNT"<<endl<<endl;
            	file_3<<setw(5)<<Medicine_1.medicine_ID<<setw(10)<<Medicine_1.medicine_name<<setw(10)<<Medicine_1.medicine_price*9.3<<Medicine_1.medicine_amount*8<<endl;
            	file_3<<setw(5)<<Medicine_2.medicine_ID<<setw(10)<<Medicine_2.medicine_name<<setw(10)<<Medicine_2.medicine_price*8.3<<Medicine_2.medicine_amount*6<<endl;
            	file_3<<setw(5)<<Medicine_3.medicine_ID<<setw(10)<<Medicine_3.medicine_name<<setw(10)<<Medicine_3.medicine_price*7.3<<Medicine_3.medicine_amount*4<<endl;
            	file_3<<setw(5)<<Medicine_4.medicine_ID<<setw(10)<<Medicine_4.medicine_name<<setw(10)<<Medicine_4.medicine_price*6.3<<Medicine_4.medicine_amount*2<<endl;
            	file_3<<setw(5)<<Medicine_5.medicine_ID<<setw(10)<<Medicine_5.medicine_name<<setw(10)<<Medicine_5.medicine_price*5.3<<Medicine_5.medicine_amount*1<<endl;
            	file_3<<setw(5)<<Medicine_6.medicine_ID<<setw(10)<<Medicine_6.medicine_name<<setw(10)<<Medicine_6.medicine_price*4.3<<Medicine_6.medicine_amount*3<<endl;
            	file_3<<setw(5)<<Medicine_7.medicine_ID<<setw(10)<<Medicine_7.medicine_name<<setw(10)<<Medicine_7.medicine_price*3.3<<Medicine_7.medicine_amount*5<<endl;
            	file_3<<setw(5)<<Medicine_8.medicine_ID<<setw(10)<<Medicine_8.medicine_name<<setw(10)<<Medicine_8.medicine_price*2.3<<Medicine_8.medicine_amount*7<<endl;
            	file_3<<setw(5)<<Medicine_9.medicine_ID<<setw(10)<<Medicine_9.medicine_name<<setw(10)<<Medicine_9.medicine_price*1.3<<Medicine_9.medicine_amount*9<<endl;
            	file_3<<setw(5)<<Medicine_10.medicine_ID<<setw(10)<<Medicine_10.medicine_name<<setw(10)<<Medicine_10.medicine_price*1.0<<Medicine_10.medicine_amount*1<<endl;
				
			file_4.setf(ios::left);
            //	file_4<<setw(5)<<"ID"<<setw(10)<<"NAME"<<setw(10)<<"PRICE"<<setw(10)<<"AMOUNT"<<endl<<endl;			
            	file_4<<setw(5)<<Medicine_1.medicine_ID<<setw(10)<<Medicine_1.medicine_name<<setw(10)<<Medicine_1.medicine_price*9.6<<Medicine_1.medicine_amount*4<<endl;
            	file_4<<setw(5)<<Medicine_2.medicine_ID<<setw(10)<<Medicine_2.medicine_name<<setw(10)<<Medicine_2.medicine_price*8.4<<Medicine_2.medicine_amount*1<<endl;
            	file_4<<setw(5)<<Medicine_3.medicine_ID<<setw(10)<<Medicine_3.medicine_name<<setw(10)<<Medicine_3.medicine_price*7.2<<Medicine_3.medicine_amount*7<<endl;
            	file_4<<setw(5)<<Medicine_4.medicine_ID<<setw(10)<<Medicine_4.medicine_name<<setw(10)<<Medicine_4.medicine_price*6.0<<Medicine_4.medicine_amount*3<<endl;
            	file_4<<setw(5)<<Medicine_5.medicine_ID<<setw(10)<<Medicine_5.medicine_name<<setw(10)<<Medicine_5.medicine_price*5.8<<Medicine_5.medicine_amount*9<<endl;
            	file_4<<setw(5)<<Medicine_6.medicine_ID<<setw(10)<<Medicine_6.medicine_name<<setw(10)<<Medicine_6.medicine_price*4.6<<Medicine_6.medicine_amount*5<<endl;
            	file_4<<setw(5)<<Medicine_7.medicine_ID<<setw(10)<<Medicine_7.medicine_name<<setw(10)<<Medicine_7.medicine_price*3.4<<Medicine_7.medicine_amount*2<<endl;
            	file_4<<setw(5)<<Medicine_8.medicine_ID<<setw(10)<<Medicine_8.medicine_name<<setw(10)<<Medicine_8.medicine_price*2.2<<Medicine_8.medicine_amount*8<<endl;
            	file_4<<setw(5)<<Medicine_9.medicine_ID<<setw(10)<<Medicine_9.medicine_name<<setw(10)<<Medicine_9.medicine_price*1.0<<Medicine_9.medicine_amount*10<<endl;
            	file_4<<setw(5)<<Medicine_10.medicine_ID<<setw(10)<<Medicine_10.medicine_name<<setw(10)<<Medicine_10.medicine_price*0.8<<Medicine_10.medicine_amount*6<<endl;

			file_1.close();
			file_2.close();
			file_3.close();
			file_4.close();
			
			 cout << "\n\n\t\tMEDICINES CREATED AUTOMATICALLY"<<endl;
			
			getch();

        }
    void CreateMedicine(int i)
    {

        int new_ID, new_amount;
        double new_price;
        string new_name, filename;
        Medicine newMedicine;
        fstream addMedicine;

        new_ID = i;
        cout << "\n\nEnter the name of the medicine you want to create -> ";
        cin >> new_name;
        cout << "\n\nEnter the amount of the medicine -> ";
        cin >> new_amount;
        cout << "\n\nEnter the price of the medicine -> ";
        cin >> new_price;

        newMedicine.setMedicineID(new_ID);
        newMedicine.setMedicineName(new_name);
        newMedicine.setMedicineAmount(new_amount);
        newMedicine.setMedicinePrice(new_price);

        cout << "\n\nEnter the pharmacy you want to add the medicine to ->";
        cin >> filename;

        filename.append("_Medicine.dat");
        addMedicine.open(filename.c_str(), ios::out | ios::in | ios::app);

        if (!addMedicine)
        {
            cout << "Error opening File" << endl;
            exit(1);
        }

        addMedicine.setf(ios::left);
        addMedicine << setw(5) << newMedicine.medicine_ID << setw(10) << newMedicine.medicine_name << setw(10)
                    << newMedicine.medicine_amount << setw(10) << newMedicine.medicine_price << endl;

        addMedicine.close();
    }

    void SearchMedicine()
    {
    }
    void FixMedicine()
    {
    }
};
void menu()
{
    cout << "\n"
         << endl;
    cout << "			|					|" << endl;
    cout << "			|					|" << endl;
    cout << "			|	1.	PHARMACY		|" << endl;
    cout << "			|	2.	CUSTOMER		|" << endl;
    cout << "			|					|" << endl;
    cout << "			|					|" << endl;
}
void menu_1()
{
    cout << "\n"
         << endl;
    cout << "			|				        |" << endl;
    cout << "			|	1.CREATE PHARMACY LIST		|" << endl;
    cout << "			|	2.ADD PHARMACY	        	|" << endl;
    cout << "			|	3.ADD MEDICINE	       		|" << endl;
    cout << "			|	4.FIX MEDICINE			|" << endl;
    cout << "			|				        |" << endl;
}
void menu_2()
{
    cout << "\n"
         << endl;
    cout << "			|				             |" << endl;
    cout << "			|	1.SEARCH MEDICINE	             |" << endl;
    cout << "			|	2.LIST PHARMACY	       	    	     |" << endl;
    cout << "			|	3.SHOW ANY PHARMACY		     |" << endl;
    cout << "			|	4.MEDICATION LIST FOR ANY PHARMACY   |" << endl;
    cout << "			|				             |" << endl;
}
int main()
{

    Pharmacy Pharmacy;
    Medicine Medicine;
    int choose = -1, choose_2 = -1, choose_3 = -1, k = 5, j = 11, p = 0;
    int password, pw;
    pw = 0000;
    while (choose != 0)
    {

        system("cls");
        menu();
        cout << "\n\t\t\t-> ";

        cin >> choose;
        if (choose == 1)
        {
            cout << "\n\n\t       Password -> ";
            cin >> password;

            if (password == pw)
            {
                while (choose_2 != 0)
                {

                    system("cls");
                    menu_1();

                    cout << "\n\t\t\t>";
                    cin >> choose_2;

                    switch (choose_2)
                    {

                    case 1:
                        if (p == 0)
                        {

                            Pharmacy.InputPharmacy();
                            Medicine.InputMedicine();
                            p++;
                        }

                        break;
                    case 2:

                        Pharmacy.CreateNewPharmacy(k);
                        k++;
                        break;
                    case 3:
                        Medicine.CreateMedicine(j);
                        j++;
                        break;
                    case 4:
                        Medicine.FixMedicine();
                        break;
                    }
                }
                choose_2 = -1;
            }
        }
        if (choose == 2)
        {
            while (choose_3 != 0)
            {
                system("cls");
                menu_2();

                cout << "\n\t\t\t>";
                cin >> choose_3;

                switch (choose_3)
                {

                case 1:
                    Medicine.SearchMedicine();
                    break;
                case 2:
                    Pharmacy.ShowPharmacyInfo();
                    break;
                case 3:
                    Pharmacy.ShowAnyPharmacy();
                    break;
                case 4:
                    Pharmacy.MedicationListForAnyPharmacy();
                    break;
                }
            }
            choose_3 = -1;
        }
    }

    return 0;
}







