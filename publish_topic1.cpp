/* publish topic　の作成*/


#include "ros/ros.h" 
#include "std_msgs/Float64.h"
#include <sstream>
#include "ros/time.h"
#include <motor/control.h>
#include <serial/serial.h>
// #include <text_con/text_comand.h>　//おそらく不要


// シリアル通信の設定
std::string port0 = "/dev/ttyUSBwheel1";
uint32_t baud = 115200; //setup baud
serial::Serial motor_serial0(port0, baud, serial::Timeout::simpleTimeout(1000));


int main(int argc, char **argv)
{
	//このノードは"motor_pub"という名前であるという意味
 ros::init(argc, argv, "motor_pub");
   //ノードハンドラの宣言
 ros::NodeHandle nh;
   //Publisherとしての定義
 　//std_msgs::Float64型のメッセージを"motor"というトピックへ配信する
 　//"10"はトピックキューの最大値
 ros::Publisher motor_pub = n.advertise<motor::control>("motor", 10);
 　
 　//1秒間に30のメッセージをPublishする
 ros::Rate loop_rate(30);
   
   //std_msgs::Float64型のオブジェクトを定義
 　//Float64で定義した変数はメンバ変数としてアクセスできる
 motor::control motor_con_msg;

 int speed;
 int t;
 int renew = 0;
 while (ros::ok())
 {
  while(ros::ok() && renew==0)
 {  
	  std::stringstream ss;
	ss<< "単輪の速度を入力（0≦X≦75）X(cm/s)" ;
	ss >> speed;
    
	ROS_INFO_STREAM("speed1 " << speed);
	
	ss << "秒を入力T(秒)" ;
	ss >> t;	
	loop_rate.sleep();
 }
  
  //ROS timeで現在時刻を取得する関数
  motor_con_msg.header.stamp = ros::Time::now();
  motor_pub.publish(speed);
  motor_serial0.write(data);  // データを送信する
  ROS_INFO("%s", data);  // デバッグ用
  renew = 0;
  
  ros::spinOnce();
  loop_rate.sleep();
 }
 return 0;
}

