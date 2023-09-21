#include <iostream>
#include <iomanip>
   using namespace std;

   int main()
   {
   //variables
   char restart = ' ';
   char yon = ' ';
   int typeOfPlane = 0;
   int airportOne = 0;
   int airportTwo = 0;
   char license = ' ';
   int visibility = 0;
   const int S = 10;
   const int M = 60;
   const int L = 750;
   char voi = ' ';
   int altitude = 0;
   int fuel = 0;
   const int PHLTOPIT = 268;
   double PHLTOPITTIME = 0.0;
   const int KMDTTOPHL = 87;
   double KMDTTOPHLTIME = 0.0;
   const int KMDTTOPIT = 165;
   double KMDTTOPITTIME = 0.0;
   int speed = 0;
   int distance = 0;
   int time = 0;
   double fuelConsumpt = 0.0;
   int vfrOrIfr = 0;
   //while and inputs
   cout << "Would you like to craft a flight plan? Y or N: " << endl;
   cin >> yon;
   if (toupper(yon) == 'N')
   // do while loop for asking if you would like to create a plan
       do {
         cout << "okay! How about now? ";
         cin >> yon;

      } while (toupper(yon) == 'N');
      //endif
   cout << "Do you have a pilots liscence? (Y or N): ";
   cin >> license;
   //specifics
   if (toupper(license) == 'Y')
      {
      //do while loop for restarting
      do{
      //get all inputs
      cout << "Great, first lets start with the airport you would like to take off from and land at, type the starting airport first." << endl << "The choices are (1. kphl 2. kpit 3. kmdt) use (1, 2, or 3) as inputs: " << endl;
      cin >> airportOne >> airportTwo;
      cout << "Sounds good!" << endl;
      do{
      cout << "What size plane are you going to be flying in? Small 3 Medium 2 Large 1, If your entry is not one of the options the question will be asked again: ";
      cin >> typeOfPlane;
      }while (typeOfPlane != 1 && typeOfPlane != 2 && typeOfPlane != 3);
      typeOfPlane = toupper(typeOfPlane);
      do{
      cout << "What is the average speed that you will be traveling during your flight. If your speed is too high or too the question will be asked again: ";
      cin >> speed;
      speed = toupper(speed);
      }while((typeOfPlane == 1 && (speed >= 3000 || speed < 100)) || (typeOfPlane == 2 && (speed >= 3000 || speed < 100)) || (typeOfPlane == 3 && (speed > 400 || speed < 60)));
      cout << "And how much fuel will you be carrying?: ";
      cin >> fuel;
      fuel = toupper(fuel);
      cout << "What altitude will you be flying at?: ";
      cin >> altitude;
      do{
      cout << "Will you be flying Visual Flight Rules, or Intrument Flight Rules? VFR: 1 IFR: 2 , If your entry is not one of the options the question will be asked again ";
      cin >> vfrOrIfr;
      }while(vfrOrIfr != 1 && vfrOrIfr != 2);
      cout << "What is your visibility in statute miles?" << endl;
      cin >> visibility;
      if (visibility < 3 && vfrOrIfr == 1)
      {
        cout << "In this visibility you can not fly Visual Flight Rules";
        exit(0);
      }
      //if statements for calculations based on altitude, distance, speed etc.
      if((airportOne == 1 || airportOne == 2) && (airportTwo == 1 || airportTwo == 2))
      {
        distance = PHLTOPIT;
        if (typeOfPlane == 1)
        {
          if (altitude >= 33000 && altitude <= 42000)
          {
          cout << "Your cruising altitude is good for your aircraft." << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(L);
          }
          else 
          {
          cout << "Your cruising altitude should be between 33,000 and 42,000 feet." << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(L);
          //endif
          }
          if (fuel < fuelConsumpt)
            cout << "The amount of fuel you will need should be around " << fuelConsumpt << " gallons for your speed,but double check for the specific plane you are using" << endl;
          else
            cout << "The amount of fuel you're carrying should be enough for your flight based of your speed" << endl;
          //endif
        }
        else if (typeOfPlane == 2)
        {
          if (altitude >= 33000 && altitude <= 42000)
          {
          cout << "Your cruising altitude is good for your aircraft." << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(M);  
          }
          else
          {
          cout << "Your cruising altitude should be between 33,000 and 42,000 feet" << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(M);
          //endif
          }
          if (fuel < fuelConsumpt)
            cout << "The amount of fuel you will need should be around " << fuelConsumpt << " gallons for your speed,but double check for the specific plane you are using" << endl;
          else
            cout << "The amount of fuel you're carrying should be enough for your flight based of your speed" << endl;
          //endif
        }
        else if(typeOfPlane == 3)
        {
          if (altitude >= 5000 && altitude <= 12000)
          {
          cout << "Your cruising altitude is good for your aircraft." << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(S);  
          }
          else
          {
          cout << "Your cruising galtitude should be between 5,000 and 12,000 feet" << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(S);
          //endif
          }
          if (fuel < fuelConsumpt)
            cout << "The amount of fuel you will need should be around " << fuelConsumpt << " gallons for your speed,but double check for the specific plane you are using" << endl;
          else
            cout << "The amount of fuel you're carrying should be enough for your flight based of your speed" << endl;
          //endif
        //endif
        }
      }
      else if ((airportOne || airportTwo == 1) && (airportOne || airportTwo == 3))
         {
         distance = KMDTTOPHL;
         if (typeOfPlane == 1)
        {
          if (altitude >= 33000 && altitude <= 42000)
          {
          cout << "Your cruising altitude is good for your aircraft." << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(L);
          }
          else 
          {
          cout << "Your cruising altitude should be between 33,000 and 42,000 feet." << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(L);
          //endif
          }
          if (fuel < fuelConsumpt)
            cout << "The amount of fuel you will need should be around " << fuelConsumpt << " gallons for your speed,but double check for the specific plane you are using" << endl;
          else
            cout << "The amount of fuel you're carrying should be enough for your flight based of your speed" << endl;
          //endif
        }
        else if (typeOfPlane == 2)
        {
          if (altitude >= 33000 && altitude <= 42000)
          {
          cout << "Your cruising altitude is good for your aircraft." << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(M);  
          }
          else
          {
          cout << "Your cruising altitude should be between 33,000 and 42,000 feet" << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(M);
          //endif
          }
          if (fuel < fuelConsumpt)
            cout << "The amount of fuel you will need should be around " << fuelConsumpt << " gallons for your speed,but double check for the specific plane you are using" << endl;
          else
            cout << "The amount of fuel you're carrying should be enough for your flight based of your speed" << endl;
          //endif
        }
        else if(typeOfPlane == 3)
        {
          if (altitude >= 5000 && altitude <= 12000)
          {
          cout << "Your cruising altitude is good for your aircraft." << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(S);  
          }
          else
          {
          cout << "Your cruising galtitude should be between 5,000 and 12,000 feet" << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(S);
          //endif
          }
          if (fuel < fuelConsumpt)
            cout << "The amount of fuel you will need should be around " << fuelConsumpt << " gallons for your speed,but double check for the specific plane you are using" << endl;
          else
            cout << "The amount of fuel you're carrying should be enough for your flight based of your speed" << endl;
          //endif
        //endif
        }
         }
      else if((airportOne || airportTwo == 2) && (airportOne || airportTwo == 3))
         {
         distance = KMDTTOPIT;
         if (typeOfPlane == 1)
        {
          if (altitude >= 33000 && altitude <= 42000)
          {
          cout << "Your cruising altitude is good for your aircraft." << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(L);
          }
          else 
          {
          cout << "Your cruising altitude should be between 33,000 and 42,000 feet." << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(L);
          //endif
          }
          if (fuel < fuelConsumpt)
            cout << "The amount of fuel you will need should be around " << fuelConsumpt << " gallons for your speed,but double check for the specific plane you are using" << endl;
          else
            cout << "The amount of fuel you're carrying should be enough for your flight based of your speed" << endl;
          //endif
        }
        else if (typeOfPlane == 2)
        {
          if (altitude >= 33000 && altitude <= 42000)
          {
          cout << "Your cruising altitude is good for your aircraft." << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(M);  
          }
          else
          {
          cout << "Your cruising altitude should be between 33,000 and 42,000 feet" << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(M);
          //endif
          }
          if (fuel < fuelConsumpt)
            cout << "The amount of fuel you will need should be around " << fuelConsumpt << " gallons for your speed,but double check for the specific plane you are using" << endl;
          else
            cout << "The amount of fuel you're carrying should be enough for your flight based of your speed" << endl;
          //endif
        }
        else if(typeOfPlane == 3)
        {
          if (altitude >= 5000 && altitude <= 12000)
          {
          cout << "Your cruising altitude is good for your aircraft." << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(S);  
          }
          else
          {
          cout << "Your cruising galtitude should be between 5,000 and 12,000 feet" << endl;
          PHLTOPITTIME = PHLTOPIT / static_cast<double>(speed);
          fuelConsumpt = (PHLTOPITTIME) * static_cast<double>(S);
          //endif
          }
          if (fuel < fuelConsumpt)
            cout << "The amount of fuel you will need should be around " << fuelConsumpt << " gallons for your speed,but double check for the specific plane you are using" << endl;
          else
            cout << "The amount of fuel you're carrying should be enough for your flight based of your speed" << endl;
          //endif
        //endif            
         } 
       
      }
      //output
      if (fuel >= fuelConsumpt)
      {
      cout << fixed << setprecision(2);
      cout << "The distance between airports is " << distance << " miles." << " Your fuel consumption on this flight will be around " << fuelConsumpt << " gallons." << " This can change with tail winds or headwinds so make sure to check on the day of your flight." << endl;
      }
      else
      {
        cout << "The distance between airports is " << distance << " miles." << "Your fuel consumption can change with tail winds or headwinds so make sure to check on the day of your flight." << endl;
      }
      cout << "Would you like to create another flight plan? Y or N" ;
      cin >> restart;
      restart = toupper(restart);
      } while (restart == 'Y');  
      }
   else
   {
      cout << "You're gonna need that";
   }

   return 0;
}
