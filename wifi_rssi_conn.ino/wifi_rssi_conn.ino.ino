/*
 *  This sketch demonstrates how to scan WiFi networks. 
 *  The API is almost the same as with the WiFi Shield library, 
 *  the most obvious difference being the different file you need to include:
 */
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
//  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("Setup done");
}

void loop() {
  Serial.println("scan start");
    // WiFi.scanNetworks will return the number of networks found
  
  int a[5][3]={(1,-1000),(2,-1000),(3,-1000),(4,-1000),(5,-1000),(1,-1000),(2,-1000),(3,-1000),(4,-1000),(5,-1000),(1,-1000),(2,-1000),(3,-1000),(4,-1000),(5,-1000)};     //array for RSSI 
  
  for(int j=0;j<=3;j++)
  {
  
  int n = WiFi.scanNetworks();
 Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else
  { 
    if(j==0)
  {
      Serial.print(n);
      Serial.println(" networks found");
          for (int i = 0; i < n; i++)
          {
//                 Print SSID and RSSI for each network found
              
                
                Serial.print(i + 1);
                Serial.print(": ");
                Serial.print(WiFi.SSID(i));
                Serial.print(" ");
                a[i][j]=WiFi.RSSI(i);
                Serial.print(WiFi.RSSI(i));
                Serial.print("");
                Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?"$ ":"*");  
                delay(10);
                Serial.print("(RSSI value in array)::");
                Serial.println(a[i][1]);
                
          }    
  }
  else
    if(j>=1)
  {
      Serial.print(n);
      Serial.println(" networks found");
          for (int i = 0; i < 5; i++)
          {
//                 Print SSID and RSSI for each network found
              
                
                Serial.print(i + 1);
                Serial.print(": ");
                Serial.print(WiFi.SSID(i));
                Serial.print(" ");
                a[i][j]=a[i][j]+WiFi.RSSI(i);
                Serial.print(WiFi.RSSI(i));
                Serial.print("");
                Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?"$ ":"*");  
                delay(10);
                Serial.print("(RSSI value in array)::");
                Serial.println(a[i][1]);
                
          }    
  }
  

              
              Serial.print(j+1);Serial.println("  baar ");

  }   
//    }
//    else if(m=3)
//      {
//       for (i = 0; i < n; ++i)
//        { 
//          for (j = 0; j< n; ++j)
//            { 
//              c[i]=c[i]+a[i][j];   
//              Serial.println(c[i]);
//            }
//        }
//              for (i = 0; i < n; ++i)
//              {
//                high=c[0];
//                if(c[i+1]>c[i])
//                high=c[i+1];
//              }
//      }
//     }
//  }
//  
  }
  Serial.println("");

  // Wait a bit before scanning again
  delay(5000);
}
