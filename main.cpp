 #include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct daylightInfo{
string month;
int day;
int year;
int AMhour;
int AMmin;
int PMhour;
int PMmin;
};

//////////////prototyped functions ////////////
int hours(daylightInfo data[], int N, int index);
int minutes(daylightInfo data[], int N, int index);

int main() {
  char throwaway;
  int N;
  cin >> N;
  daylightInfo data[N];

  for (int i = 0; i < N; i++){
    cin >> data[i].month >> data[i].day >> data[i].year >> data[i].AMhour >> throwaway >> data[i].AMmin >> data[i].PMhour >> throwaway >> data[i].PMmin;
  }

  for (int j = 0; j < N; j++)
    {
      cout << data[j].month << " " << data[j].day << " " << data[j].year << " " << hours(data, N, j) << " hours " << minutes(data, N, j) << " minutes" << endl;
      
    }
  
}

int hours(daylightInfo data[], int N, int index)
{
  int hours;
  
    if (data[index].PMmin < data[index].AMmin)
    {
      hours = data[index].PMhour - data[index].AMhour - 1;
    }
    else
      hours = data[index].PMhour - data[index].AMhour;

  return hours;
}



int minutes(daylightInfo data[], int N, int index)
{

  int minutes;
  
  if (data[index].PMmin < data[index].AMmin)
    {
      minutes = data[index].PMmin - data[index].AMmin + 60;
    }
    else
      minutes = data[index].PMmin - data[index].AMmin;

return minutes;  
}