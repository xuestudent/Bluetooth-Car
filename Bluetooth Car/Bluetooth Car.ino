

    char serial_val;//存储串口的数据
    int left = 5 ;//设定引脚号左前轮对应3.4号引脚
    int left2 = 4 ;
    int right = 3 ;//设定引脚号右前轮对应2.3号引脚
    int right2 = 2 ;
   




    void setup()
    {
    //设定引脚的模式
    pinMode(right,OUTPUT);
    pinMode(left,OUTPUT);
    pinMode(right2,OUTPUT);
    pinMode(left2,OUTPUT);



    Serial.begin(9600);//配置蓝牙串口波特率
    }





    void loop()
    {
      
          if (Serial.available()>0)//检查串口有无数据
        {   
          serial_val=Serial.read( );
         if (serial_val == 'w')//发送w时前进
        {
        advance( );
        Serial.println("The car is ardvancing ");
          
        }
         else if (serial_val == 'a')//发送a时左转
          {
        turn_left( );
        Serial.println("The car is turning left");
        }
        else if (serial_val == 'd')//发送d时右转
         {
        turn_right( );
        Serial.println("The car is turning right");     
        }
        else  if (serial_val == 'r') //发送r时后退
         {
        retreat( );
        Serial.println("The car is retreating");
        }
        else  if (serial_val == 's')//发送s时停止
         {
         stop( );
        Serial.println("The car is stopping");
        }

    }
  }
    void advance( )//前进函数
    {
      digitalWrite( left, LOW);
      digitalWrite( left2, HIGH);
      digitalWrite( right, LOW);
      digitalWrite( right2, HIGH);

    }
    void turn_left( )//左转函数
    {
      digitalWrite(left,LOW);
      digitalWrite(left2,LOW);
      digitalWrite(right,LOW);
      digitalWrite(right2,HIGH);
      

    }
    void turn_right( )//右转函数
    {
      digitalWrite(left,LOW);
      digitalWrite(left2,HIGH);
      digitalWrite(right,LOW);
      digitalWrite(right2,LOW);
           
    }
    void retreat( )//后退函数
    {
      digitalWrite(left,HIGH);
      digitalWrite(left2,LOW);
      digitalWrite(right,HIGH);
      digitalWrite(right2,LOW);
    }
    void stop( )//停止函数
    {
      digitalWrite(left,LOW);
      digitalWrite(left2,LOW);
      digitalWrite(right,LOW);
      digitalWrite(right2,LOW);
    }
